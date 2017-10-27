# 特定文字列に対する処理を行うプロダクションシステム
module ProductionSystem
  # データ推論の途中結果を格納しておくクラス
  class WMemory
    # memory   : 推論途中の結果文字列
    # operated : 結果文字列に対して適応されたルール
    #            - memoryと同じインデックスの結果文字列に対応
    attr_accessor :memory, :operated

    # インスタンスの生成
    def initialize
      @memory   = []
      @operated = []
    end

    # 初期状態を格納させる
    #
    # 同時に初期化されたというフラグも格納させる
    def init_memory(str)
      @memory << str
      @operated << 'Init'
    end

    # 結果文字列と適応されたルールを各々の`メモリ`へ保持させる
    #
    # str [String] : 結果文字列
    # opr [String] : 適応されたルール
    def save(str, opr)
      memory << str
      operated << opr
    end

    # 処理途中文字列メモリ内の最新のものを返す
    def load
      memory[-1]
    end
  end

  # 問題解決のためのルール(知識)を保持しておくクラス
  #
  # このクラスは処理群をまとめることを目的としているためインスタンス化しない
  #
  # Rules Document #
  # R1 : "(記号)(文字)" の場合、"(文字)(記号)" と置換する
  # - この時の(記号)は1文字以上のもの
  # R2 : "abcdefg" の順で並んでいた場合、"gfedcba" と置換する (reverse)
  # R3 : "*-/+" の順で並んでいた場合、"+-*/" と置換する
  class PMemory
    # 適応したいルールにマッチする部分を探すモジュール
    #
    # 対応する処理は Processing にて行う
    module Matcher
      # 与えられた文字列がどのルールにマッチするかを判定する
      def self.operate(str)
        if (md = str.match(/\W+[a-z]/))    # Rule 1
          Processing.swap_sym_char(str, md)
        elsif (md = str.match(/abcdefg/))  # Rule 2
          Processing.reverse_letters(str, md)
        elsif (md = str.match(%r{\*-/\+})) # Rule 3
          Processing.adjust_syms(str, md)
        end
      end
    end

    # 適応したいルールに対応した処理を行うモジュール
    #
    # Matcherにて指定された処理を実行し結果を返す
    #
    # 各処理では以下のものを返り値とする
    # - 処理後の文字列 ress (result string)
    # - 適応したルール oprr (operated rule, 返り値の2つ目の要素)
    module Processing
      # 記号と文字を入れ替える(R1)
      def self.swap_sym_char(str, md)
        ress = str.dup
        ress[md.begin(0)...md.end(0)] = (md[0][-1] + md[0]).chop
        [ress, "R1"]
      end

      # アルファベットを反転して置換する(R2)
      def self.reverse_letters(str, md)
        ress = str.dup
        ress[md.begin(0)...md.end(0)] = md[0].reverse
        [ress, "R2"]
      end

      # 記号の順序を整えて置換する(R3)
      def self.adjust_syms(str, md)
        ress = str.dup
        ress[md.begin(0)...md.end(0)] = '+-*/'
        [ress, "R3"]
      end
    end
  end

  # ワーキングメモリ・プロダクションメモリを用いて推論を行うクラス
  class InterPreter
    # wm : ワーキングメモリ
    attr_accessor :wm

    # インスタンスの生成
    #
    # ワーキングメモリへ初期状態をブチ込む
    def initialize(str)
      @wm = WMemory.new

      wm.init_memory(str)
    end

    # 与えられたゴール状態へなるように推論を行う
    def operate(goal = 'gfedcba+-*/')
      puts "WM(Init state) : #{wm.load}"
      until (current = wm.load) == goal
        ress, oprr = PMemory::Matcher.operate(current)
        wm.save(ress, oprr)
        puts "WM(working) : #{ress}, Operated : #{oprr}"
      end
    end
  end

  # 実行
  def self.run
    ProductionSystem::InterPreter.new('a*b-cd/e+fg').operate
  end
end

########## main ##########

ProductionSystem.run
