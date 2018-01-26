require 'bigdecimal'

# 遺伝的アルゴリズムで関数の最大値を求める
module GeneticAlgorithm
  # 個体を扱うクラス
  class Individual
    attr_accessor :genotype, :phenotype, :fitness

    def initialize(genotype)
      @genotype  = genotype
      @phenotype = decode(genotype)
      @fitness   = nil
    end

    private

    # 遺伝子型から表現型へ書き直す
    #
    # [-10, 15]を1024分割する
    # 公差は0.024とし、'1111111111'の時には'15'として返す
    def decode(genotype)
      dig = genotype.to_i(2)
      return 15.0 if dig == 1023
      (dig * BigDecimal('0.024') - 10).to_f
    end
  end

  # Operatorのヘルパー
  module OperateHelper
    # 集団に対して適応度計算を行う
    def calculate_fitnesses
      population.each do |individual|
        individual.fitness = f(individual.phenotype)
      end
    end

    # 集団を適応度降順に並び替える
    def order_population
      population.sort_by!(&:fitness).reverse!
    end

    # 選択を行い、次世代として扱う集合を返す
    #
    # 上位10個体は適応度順のためそのまま(エリート選択)、下位10個体はルーレット選択を用いる
    def selection
      next_genotypes = []
      selection_elite!(next_genotypes)
      selection_roulette!(next_genotypes)
      next_genotypes
    end

    # 交叉を行う
    #
    # next_genotypes : Array<String> 次世代とする遺伝子の集合
    # - `selection`により得られた個体群を用いる
    #
    # 2個体ずつ交叉処理を行う
    # - 上位2個体には適用しない(エリート保存による)
    def crossover!(next_genotypes)
      next_genotypes[-18..-1].each_slice(2) do |g1, g2|
        g1[5..9], g2[5..9] = g2[5..9], g1[5..9]
      end
    end

    # 突然変異を行う
    #
    # *引数については`crossover`を参照*
    #
    # 1. 20ある遺伝子群の各個体に対して5%の確率で*突然変異を行うか*を判定する
    # 2. 選択された個体に対して、乱数にて変位させる遺伝子座を求める
    # 3. 指定された遺伝子座の遺伝子を反転させる
    #
    # - `crossover` と同様に上位2個体には適用しない
    def mutation!(next_genotypes)
      next_genotypes[-18..-1].each do |g|
        if rand <= 0.05
          mutate_index = rand(0..9)
          g[mutate_index] = g[mutate_index].to_i.zero? ? '1' : '0'
        end
      end
    end

    # 世代交代を行う
    #
    # 選択 → 交叉 → 突然変異 → 次世代集団生成
    # - これらの処理を包括して行う
    def migrate
      next_genotypes = selection
      crossover!(next_genotypes)
      mutation!(next_genotypes)
      make_next_population(next_genotypes)
    end

    # 上位10個体からエリート選択を行う
    def selection_elite!(next_genotypes)
      10.times { |i| next_genotypes << population[i].genotype }
    end

    # 下位10個体にはルーレット選択を適用する
    #
    # p_i = (f(s_i) + 1) / \sigma{j=1}{N} (f(s_j) + 1)
    # - i番目の個体の適応度f(s_i)を、同世代全ての個体の評価値の和で割り、それを確率として適用する
    # - 評価関数は負の値を取りうるので、各評価値は+1(スケーリング)して計算する
    def selection_roulette!(next_genotypes)
      # 下位10個体の取り出し
      lower_population = population[-10..-1]
      sum_fitness      = sum_fitness_scaled(lower_population)
      probabilitys     = roulette_probabilitys(lower_population, sum_fitness)

      10.times do
        # 選択確率最小から最大の間で乱数を発生させる
        p = rand(probabilitys[-1]..probabilitys[0])

        # 確率も降順で並んでいるため、頭から大なり比較をすれば良い
        # 同じ個体を取る可能性があるので、遺伝子(文字列)は複製する
        probabilitys.each_with_index do |prob_of_indi, i|
          if p >= prob_of_indi
            next_genotypes << lower_population[i].genotype.dup
            break
          end
        end
      end

      next_genotypes
    end

    # 同世代の評価値の和を求める
    #
    # 全ての評価値は+1のスケーリングが施される
    def sum_fitness_scaled(specific_population)
      specific_population.reduce(0.0) do |sum, individual|
        sum + (individual.fitness + 1)
      end
    end

    # 各個体の選択確率を求める
    #
    # 評価値に+1のスケーリングを行い求める
    def roulette_probabilitys(specific_population, sum_fitness)
      probabilitys = []
      specific_population.each do |individual|
        probabilitys << (individual.fitness + 1) / sum_fitness
      end
      probabilitys
    end
  end

  # GAの実行系
  class Operator
    include OperateHelper
    attr_accessor :population, :generation

    def initialize
      @population = []
      @generation = 1
      init_population
    end

    # 実行
    def execute
      # 初期世代実行
      calculate_fitnesses
      order_population
      puts_progress
      until generation >= 500
        migrate
        calculate_fitnesses
        order_population
        puts_progress
      end

      puts_result
    end

    private

    # 0,1からなる10桁の文字列を返す
    def make_genotype
      genotype = ''
      genotype.tap { |geno| 10.times { geno << [0, 1].sample.to_s } }
    end

    # 初期集団として20個体生成する
    def init_population
      20.times { population << Individual.new(make_genotype) }
    end

    # 次世代の集団を作成する
    #
    # 世代数も加算する
    def make_next_population(next_genotypes)
      population.clear
      next_genotypes.each do |g|
        population << Individual.new(g)
      end
      self.generation += 1
    end

    # 途中結果の表示
    def puts_progress
      puts "Generation : #{generation.to_s.rjust(3)}, Max f(x) : #{population[0].fitness}"
    end

    # 最終結果の表示
    def puts_result
      puts '-' * 50
      puts '*Result*'
      puts "Value of f(x) : #{population[0].fitness}"
      puts "Value of x    : #{population[0].phenotype}"
      puts "Genotype      : #{population[0].genotype}"
    end

    # 評価関数の定義
    # 平方根(Math.sqrt)のみ探索範囲的に虚数となるため実部を用いる(x < -8.5の時)
    def f(x)
      Math.sin((Math::PI * x) / 7) * 4 * (Math.log(x + 15) / (x + 15)) + 0.35 * Math.sqrt((x + 8.5).to_c).real
    end
  end
end

GeneticAlgorithm::Operator.new.execute
