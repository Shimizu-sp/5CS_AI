# 3x3の8パズル問題を解くためのモジュール
module EightPuzzle
  # 各状態を保持するためのノードとなるクラス
  #
  # 各ノードは単一の親ノードの情報を持ち、子ノードの情報は持たない
  class Node
    attr_accessor :board, :parent, :visited

    # ノードの生成
    def initialize(board)
      @board    = Board.new(board)
      @parent   = nil
      @visited  = false
    end

    # 親とするノードの設定
    def add_parent(parent)
      self.parent = parent
    end

    # 現在のノードの位置からルートノードまでの距離(深さ)を求める
    def depth
      return 1 if root?
      1 + parent.depth
    end

    # ルートノードかどうか
    def root?
      parent.nil?
    end

    # ノードを探索したことのフラグ付けを行う
    def visit
      self.visited = true
    end

    # ファイル出力用表示の定義
    def outs
      <<~OUTS
      Current : #{board.state[0]}
                #{board.state[1]}
                #{board.state[2]}
      Evaluated value : #{board.dist + depth}
      =========================
      OUTS
    end

    # デバッグ向け簡易表示
    def to_s
      "Board : #{board.state}, Dist : #{board.dist}, Depth : #{depth}"
    end
  end

  # パズルの状態を保持するためのクラス
  class Board
    attr_accessor :state, :dist

    # パズル盤の生成
    def initialize(state)
      @state = state
      @dist  = 0

      manhattan
    end

    # 空欄となっている場所のインデックスを(x, y)で返す
    def index_blank
      state.each_with_index do |row, y|
        row.each_with_index do |fig, x|
          return [x, y] if fig == -1
        end
      end
    end

    # 現状態とゴール状態との間のマンハッタン距離を求める
    #
    # ゴール状態をあらかじめ設定してあるため、一般解としては運用できない
    def manhattan
      self.dist = 0
      state.each_with_index do |row, y|
        row.each_with_index do |fig, x|
          case fig
          when 1 then self.dist += (y + x)
          when 2 then self.dist += (y + (x - 1).abs)
          when 3 then self.dist += (y + (x - 2).abs)
          when 4 then self.dist += ((y - 1).abs + x)
          when 5 then self.dist += ((y - 1).abs + (x - 1).abs)
          when 6 then self.dist += ((y - 1).abs + (x - 2).abs)
          when 7 then self.dist += ((y - 2).abs + x)
          when 8 then self.dist += ((y - 2).abs + (x - 1).abs)
          when -1 then next
          end
        end
      end
    end

    # 状態の複製をする
    #
    # 参照渡しである配列を2次元で表現しているためコピーに工夫が必要
    def duplicate
      dup_state = []
      state.each do |row|
        dup_state << row.dup
      end
      dup_state
    end

    # 指定したインデックスの要素を空白と入れ替えた状態を返す
    def move(x, y)
      new_state = duplicate
      blank_x, blank_y = index_blank
      new_state[y][x], new_state[blank_y][blank_x] = new_state[blank_y][blank_x], new_state[y][x]
      new_state
    end

    # ゴール状態となっているか
    #
    # マンハッタン距離が0であればパズルが解けている
    def goal?
      dist.zero?
    end
  end

  # パズルを解くためのソルバ
  #
  # 処理をまとめたもの
  module Solver
    # 次状態候補を生成する
    #
    # 現状態のノードに探索したことのフラグ付けも行う
    def self.make_next_states(node)
      node.visit
      next_states = []
      b_x, b_y = node.board.index_blank
      next_states << Node.new(node.board.move(b_x, b_y - 1)) unless (b_y - 1) < 0
      next_states << Node.new(node.board.move(b_x - 1, b_y)) unless (b_x - 1) < 0
      next_states << Node.new(node.board.move(b_x + 1, b_y)) unless (b_x + 1) > 2
      next_states << Node.new(node.board.move(b_x, b_y + 1)) unless (b_y + 1) > 2
      next_states
    end

    # 次状態候補をマンハッタン距離の降順となるようにソートして返す
    def self.next_states_ordered_desc(node)
      next_states = make_next_states(node)
      next_states.sort_by { |n| n.board.dist }.reverse
    end

    # 次状態候補に親ノードの設定を含めたものを返す
    def self.next_states_parent_as(parent)
      next_states = next_states_ordered_desc(parent)
      next_states.each { |n| n.add_parent(parent) }
      next_states
    end

    # 探索点を移動する前に、選択候補の状態が重複した動きになっていないか確認する
    #
    # スタックの中に同じ盤面のものが含まれていれば探索済みとする
    def self.next_states_check_moving(next_states, stack)
      next_states.each do |ns|
        ns.visit if stack.any? { |st| st.board.state == ns.board.state }
      end
    end

    # 次状態候補をスタックへ入れる
    def self.push_next_states(next_states, stack)
      next_states.each { |n| stack.push(n) }
    end

    # 深さ優先探索をスタックを用いて行う
    #
    # 実行した時間をファイル名とした結果ファイルの出力も行う
    def self.operate_stack(root, lim_depth)
      stack = []
      stack.push(root)
      timestamp = Time.now.to_i.to_s
      until stack.empty?
        current = stack.pop
        outs_current_to(timestamp, current)
        if current.board.goal?
          stack.push(current)
          break
        end
        next if current.depth >= lim_depth
        next if current.visited
        next_states = next_states_parent_as(current)
        next_states_check_moving(next_states, stack)
        stack.push(current)
        push_next_states(next_states, stack)
      end
      stack.last
    end

    # 得た解手順の表示
    def self.puts_trace(node_solved)
      if node_solved.nil?
        puts 'Unsolved'
        return
      end
      puts_trace(node_solved.parent) unless node_solved.root?
      puts node_solved.outs
    end

    # 探索内容をファイルへ出力させる
    def self.outs_current_to(filename, current)
      `echo "#{current.outs}" >> #{filename + '.result.txt'}`
    end

    # 以下デバッグ用表示処理 #

    # スタックの中身の表示
    def self.puts_stack(stack)
      print "Stack : \n"
      stack.each { |n| print "    #{n}\n" }
    end

    # 現在の状態から選択されうる次状態の表示
    def self.puts_next_states(next_states)
      print "Nexts : \n"
      next_states.each { |n| print "    #{n}\n" }
    end

    # デバッグ用表示処理終わり #
  end

  # 8パズルを解く
  #
  # 全体の処理をmainから1行で呼ぶためのエイリアス
  # 探索木の深さをlim_depthとする
  def self.from_init_to_solve(puzzle, lim_depth)
    root = Node.new(puzzle)
    last = Solver.operate_stack(root, lim_depth)
    Solver.puts_trace(last)
  end
end

########## main ##########
EightPuzzle.from_init_to_solve([[8, 1, 5], [2, -1, 4], [6, 3, 7]], 100)
