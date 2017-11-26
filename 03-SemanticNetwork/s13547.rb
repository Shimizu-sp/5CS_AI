# 意味ネットワーク
module Meanetwork
  # 生物
  class Lives
    # 生物は呼吸する #=> breath: yes
    KNOWLEDGE = { 'breathed' => 'yes' }.freeze

    # 知識(KNOWLEDGE)に要素があるか探索する
    #
    # 存在しない場合はその旨を返す
    def self.search(attr_)
      return "No knowledge founds in #{self}." unless KNOWLEDGE.key?(attr_)
      KNOWLEDGE[attr_]
    end
  end

  # 鳥
  class Bird < Lives
    # 鳥は生物である #=> is_a: lives
    # 鳥には翼がある #=> has_wing: yes
    KNOWLEDGE = {
      'is_a' => superclass,
      'has_wing' => 'yes'
    }.freeze

    # 継承元(Lives)と同様
    #
    # 存在しない場合は親クラスの参照処理を行う(Lives.search)
    def self.search(attr_)
      unless KNOWLEDGE.key?(attr_)
        puts "  info:No knowledge founds in #{self}. Search #{superclass}..."
        return KNOWLEDGE['is_a'].search(attr_)
      end
      KNOWLEDGE[attr_]
    end
  end

  # オウム
  class Parrot < Bird
    # オウムは鳥である #=> is_a: bird
    # オウムの特技はモノマネである #=> speciality: mimicry
    KNOWLEDGE = {
      'is_a' => superclass,
      'speciality' => 'mimicry'
    }.freeze

    # 継承元(Bird)と同様
    #
    # 存在しない場合は親クラスの参照処理を行う(Bird.search)
    def self.search(attr_)
      unless KNOWLEDGE.key?(attr_)
        puts "  info:No knowledge founds in #{self}. Search #{superclass}..."
        return KNOWLEDGE['is_a'].search(attr_)
      end
      KNOWLEDGE[attr_]
    end
  end

  # オウムの特技は何ですか?
  def self.what_is_the_parrots_speciality?
    puts "Question: What is the parrot's speciality?"
    puts "Answer: #{Parrot.search('speciality')}"
    puts '-' * 10
  end

  # オウムは呼吸をしますか?
  def self.parrot_breathed?
    puts 'Question: Is parrot breathed?'
    puts "Answer: #{Parrot.search('breathed')}"
    puts '-' * 10
  end
end

Meanetwork.what_is_the_parrots_speciality?
Meanetwork.parrot_breathed?
