def printer()#コンソールに文字列の状態を表示させる関数
  $list.each do |index_structure|#リストのインデックスを取り出しindex_charに代入するループ処理
    print(index_structure)#現在の位置の文字を表示
  end#ループ処理の終了宣言
  print("\n")#文字列を出力し終えたら改行する。
end#関数printerの終了宣言。

def production_memory()#ルールマッチと推論を行う関数
  $pattern =0#ルールを保持する変数を初期化
  $list.each_with_index do |index_char ,index_num|#リストのインデックスと要素を取り出しインデックスをindex_num,要素をindex_structureに代入するループ処理
    if $list.last == "ß"#制御文字ßが末尾に含まれている場合、ルール10を適用。
      $pattern = 10#適用するルールを保持する変数に１０を格納する。
      break#適用するルールが決定されたのでルールの選定を終了する。
    end#ルール１０の判定文の終了宣言。
    if index_char == "ß"#制御文字ßのある箇所を探す。
      if $list[index_num+2] ="$"#ßの二つ後ろがßの場合、ルール９を適用する。
        $location = index_num#グローバル変数locationにßの位置を格納する。
        $pattern = 9#適用するルールを保持する変数に１０を格納する。
        break#適用するルールが決定されたのでルールの選定を終了する。
      end#ルール９の判定文の終了宣言。
    end#ßが存在する場合の処理を終了。
    if index_char == "$"#制御文字＄のある箇所を探す。
      if $list.size - 2 > index_num#＄の文字の後ろに二文字存在することを確認する。
        if $list[index_num + 2] =="$"#文字が＄で挟まれている場合、ルール７を適用する。
          $location = index_num#グローバル変数locationに＄の位置を格納する。
          $pattern = 7#適用するルールを保持する変数に７を代入する。
          break#適用するルールが決定されたのでルールの選定を終了する。
        end#ルール７の処理の終了宣言。
        if $list[index_num + 1] == "$"#＄の後ろに＄が存在する場合、ルール８を適用する。
          $location = index_num#グローバル変数locationに＄の位置を格納する。
          $pattern = 8#適用するルールを保持する変数に８を代入する。
          break#適用するルールが決定されたのでルールの選定を終了する。
        end
        if 96 > $list[index_num + 1].ord and 96 < $list[index_num + 2].ord#＄の後ろが記号文字の順番の場合、ルール５を適用する
          $location = index_num#グローバル変数locationに＄の位置を格納する。
          $pattern = 5#適用するルールを保持する変数に５を代入する。
          break#適用するルールが決定されたのでルールの選定を終了する。
        end#ルール５の処理文の終了宣言

        if 96 < $list[index_num + 1].ord and 96 > $list[index_num + 2].ord#＄の後ろが文字記号の順番の場合、ルール６を適用する
          $location = index_num#グローバル変数locationに＄の位置を格納する。
          $pattern = 6#適用するルールを保持する変数に６を代入する。
          break#適用するルールが決定されたのでルールの選定を終了する。
        end#ルール６の処理文の終了宣言
        if 96 < $list[index_num + 1].ord and  96 < $list[index_num + 2].ord  #＄の後ろ二文字が文字の場合の処理文

          if $list[index_num + 1].ord < $list[index_num + 2].ord#二文字目が一文字目よりASCII codeの値が大きい場合はルール１を適用する。
            $location = index_num#グローバル変数locationに＄の位置を格納する。
            $pattern = 1#適用するルールを保持する変数に１を代入する。
            break#適用するルールが決定されたのでルールの選定を終了する。
          end
          if $list[index_num + 1].ord > $list[index_num + 2].ord#二文字目が一文字目よりASCII codeの値が小さい場合はルール２を適用する。
            $location = index_num#グローバル変数locationに＄の位置を格納する。
            $pattern = 2#適用するルールを保持する変数に２を代入する。
            break#適用するルールが決定されたのでルールの選定を終了する。
          end
        end
        if 96 > $list[index_num + 1].ord and 96 > $list[index_num + 2].ord#記号が二つ並んでる場合の処理文
          if $list[index_num + 1].ord == 42#一文字目が＊の場合を選定する。
            if 46 > $list[index_num + 2].ord#一文字目が＊で二文字目が＋またはーの場合、ルール３を適用する。
              $location = index_num#グローバル変数locationに＄の位置を格納する。
              $pattern = 3#適用するルールを保持する変数に３を代入する。
              break#適用するルールが決定されたのでルールの選定を終了する。
            end#ルール３の処理の終了宣言
            if 46 < $list[index_num + 2].ord#一文字目が＊で二文字目が／の場合、ルール４を適用する。
              $location = index_num#グローバル変数locationに＄の位置を格納する。
              $pattern = 4#適用するルールを保持する変数に４を代入する。
              break#適用するルールが決定されたのでルールの選定を終了する。
            end#ルール４の処理の終了宣言
          end#一文字目が＊の場合の処理文の処理宣言
          if $list[index_num + 2].ord == 42#二文字目が＊の場合を選定する。
            if $list[index_num + 1].ord > 46#二文字目が＊で一文字目が／の場合、ルール３を適用する。
              $location = index_num#グローバル変数locationに＄の位置を格納する。
              $pattern = 3#適用するルールを保持する変数に３を代入する。
              break#適用するルールが決定されたのでルールの選定を終了する。
            end#ルール３の処理の終了宣言
            if $list[index_num + 1].ord < 46#二文字目が＊で一文字目が＋またはーの場合、ルール４を適用する。
              $location = index_num#グローバル変数locationに＄の位置を格納する。
              $pattern = 4#適用するルールを保持する変数に４を代入する。
              break#適用するルールが決定されたのでルールの選定を終了する。
            end#ルール４の処理の終了宣言
          end#二文字目が＊の場合の処理文の処理宣言
          if $list[index_num + 1].ord > $list[index_num + 2].ord#＊が含まれていなく一文字目が二文字目よりASCII codeの値が大きい場合、ルール３を適用する。
            $location = index_num#グローバル変数locationに＄の位置を格納する。
            $pattern = 3#適用するルールを保持する変数に３を代入する。
            break#適用するルールが決定されたのでルールの選定を終了する。
          end#ルール３の処理文の終了宣言

          if $list[index_num + 1].ord < $list[index_num + 2].ord#＊が含まれていなく一文字目が二文字目よりASCII codeの値が小さい場合、ルール４を適用する。
            $location = index_num#グローバル変数locationに＄の位置を格納する。
            $pattern = 4#適用するルールを保持する変数に４を代入する。
            break#適用するルールが決定されたのでルールの選定を終了する。
          end #ルール４の処理文の終了宣言
        end#記号が二つ並んでる場合の処理文の終了。
      end#＄の後ろに二文字ある場合の処理文の終了。
    end#＄が存在する場合の処理の終了宣言。
  end#文字列を調査するループ文の終了宣言。
  if $pattern == 0#該当するルールが存在しない場合、ルール７を適用する。
    $pattern =7#何にも当てはまらない場合はルール７を適用する。
  end#ルール７の処理文の終了宣言。
end#プロダクトメモリの処理文の終了宣言。

def working_memory()#ルールを元に動作を実行するワーキングメモリの関数。
  if $pattern == 1#ルール１に適応した場合に行う動作。＄と＄以降２つの文字を取り出して最後尾を先頭へ運び残り２つを後ろへシフトする。
    instant_box = $list[$location+1]#＄の直後の文字をinstant_boxに保存する。
    $list[$location] = $list[$location + 2 ]#＄が格納されている場所に最後尾の文字を格納
    $list[$location + 1] = "$"#＄の直後の文字が格納されていた場所に＄を格納する。
    $list[$location + 2] = instant_box#最後尾の文字が格納されていた場所に保存しておいた＄の直後の文字を格納する。
  end#ルール１の処理文の終了宣言

  if $pattern == 2#ルール２に適応した場合に行う動作。＄以降２つを取り出して＄とその後ろの文字を入れ替える。
    $list[$location] =$list[$location + 1]#＄の後ろの文字を取り出して＄があった場所に格納する。
    $list[$location + 1] ="$"#文字があった場所に＄を格納する。
  end#ルール２の処理文の終了宣言

  if $pattern == 3#ルール３に適応した場合に行う動作。＄以降２つを取り出して最後尾を先頭へ運び残り２つを後ろへシフトする。
    instant_box = $list[$location+1]#＄の直後の文字をinstant_boxに保存する。
    $list[$location] = $list[$location + 2 ]#＄が格納されている場所に最後尾の文字を格納
    $list[$location + 1] = "$"#＄の直後の文字が格納されていた場所に＄を格納する。
    $list[$location + 2] = instant_box#最後尾の文字が格納されていた場所に保存しておいた＄の直後の文字を格納する。
  end#ルール３の処理文の終了宣言

  if $pattern == 4#ルール４に適応した場合に行う動作。＄以降２つを取り出して＄とその後ろの記号を入れ替える。
    $list[$location] =$list[$location + 1]#＄の後ろの文字を取り出して＄があった場所に格納する。
    $list[$location + 1] ="$"#文字があった場所に＄を格納する。
  end#ルール４の処理文の終了宣言

  if $pattern == 5#ルール５に適応した場合に行う動作。＄以降２つを取り出して最後尾を先頭へ運び残り２つを後ろへシフトする。
    instant_box = $list[$location+1]#＄の直後の文字をinstant_boxに保存する。
    $list[$location] = $list[$location + 2 ]#＄が格納されている場所に最後尾の文字を格納
    $list[$location + 1] = "$"#＄の直後の文字が格納されていた場所に＄を格納する。
    $list[$location + 2] = instant_box#最後尾の文字が格納されていた場所に保存しておいた＄の直後の文字を格納する。
  end#ルール５の処理文の終了宣言

  if $pattern == 6#ルール６に適応した場合に行う動作。＄以降２つを取り出して＄とその後ろの記号を入れ替える。
    $list[$location] =$list[$location + 1]#＄の後ろの文字を取り出して＄があった場所に格納する。
    $list[$location + 1] ="$"#文字があった場所に＄を格納する。
  end#ルール６の処理文の終了宣言

  if $pattern ==7#ルール７に適応した場合に行う動作。制御文字＄を文字列の先頭に追加する。
    $list.unshift "$"#制御文字＄を文字列の先頭に追加する。
  end#ルール７の処理文の終了宣言

  if $pattern == 8#ルール８に適応した場合に行う動作。二つ重なっている＄の内の一つを制御文字ßに変更し、もう一つを文字列から削除する。
    $list.delete_at($location + 1)#＄の後ろにある＄を削除する。
    $list[$location] ="ß"#＄があった場所にßを格納する。
  end#ルール８の処理文の終了宣言

  if $pattern == 9#ルール９に適応した場合に行う動作。ßの二つ後ろに＄がある場合に、ßを＄の位置に移動し＄を削除する。
    $list[$location + 2] = "ß"#＄がある場合にßを格納する。
    $list.delete_at($location)#元々ßがあった場所にあるßを削除する。
  end#ルール９の処理文の終了宣言

  if $pattern == 10#ルール１０に適応した場合に行う動作。末尾にßが存在する場合にßを削除し終了する。
    $list.pop#末尾にある文字を削除する。
    $finish_checker = "TRUE"#終了条件にTRUEを入れる
  end#ルール１０の処理文の終了宣言
end#ワーキングメモリの処理文の終了宣言

$list= ["a","*","b","-","c","d","/","e","+","f","g"]# 文字を格納したリスト。
$pattern = 0#適用するルールを保持しておくグローバル変数。
$finish_checker = "FALSE"#終了を確認するブール型の変数。
printer()#初期状態を出力する。
loop do#処理を行うループ文の開始
  if $finish_checker =="TRUE"#終了条件を満たした場合に行う終了処理
    print ("finished\n")#終了する際にfinishedと表示させる。
    break#処理から抜け出して終了する。
  end#終了処理の終了宣言
  production_memory()#ルールマッチと推論を行う関数を呼び出す
  working_memory()#動作を実行する関数を呼び出す
  printer()#コンソールに現在の状況を表示させる関数
end#処理文の終了宣言
