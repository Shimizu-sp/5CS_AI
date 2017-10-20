
def printer():#txtに出力
    tx.write('version' + str(version_c)+ '\n')
    for printer_c1 in  range(3):
        for printer_c2 in range(3):
            if printer_c2 != 0:
                tx.write(',')
            if stack[-1][printer_c1][printer_c2] == 0:
                tx.write('B') #change 0 to Brank(B)
            else:
                tx.write(str(stack[-1][printer_c1][printer_c2]))#
        tx.write('\n')


def result_check():
    global stack
    global version
    global result
    global result_border
    global version_c
    global version_stack
    global back_c
    global jeneration
    global before_move_top
    global before_move_left
    global before_move_right
    global before_move_under
    but_c = 0
    jeneration= jeneration_stack.pop()
    result_border = 18
    for result_c in range(4):
        result[result_c] = result_man[result_c] + jeneration
        if result_border > result_man[result_c]:
            if result_c == 0 :
                if before_move_under == False:#前回下に移動してるパターンを除く
                    result_border = result_man[result_c]
            if result_c == 1:
                if  before_move_right == False:#前回右に移動してるパターンを除く
                    result_border = result_man[result_c]
            if result_c == 2:
                if  before_move_top ==False:#前回上に移動してるパターンを除く
                    result_border = result_man[result_c]
            if result_c == 3:
                if before_move_left == False:#前回左に移動してるパターンを除く
                    result_border = result_man[result_c]
    jeneration += 1
    for result_c in range(4):
        if result_man[result_c] == result_border:
            if result_c == 0:
                if before_move_under == False:
                    stack.append([[8,1,5],[2,0,4],[6,3,7]])#スタックに配列を追加
                    jeneration_stack.append(jeneration)
                    for add_c1 in range(3):
                        for add_c2 in range(3):
                            stack[-1][add_c1][add_c2] = pazzle_stack1[add_c1][add_c2]#追加した配列を置き換える

            if result_c == 1:
                if before_move_right == False:
                    stack.append([[8,1,5],[2,0,4],[6,3,7]])#スタックに配列を追加
                    jeneration_stack.append(jeneration)
                    for add_c1 in range(3):
                        for add_c2 in range(3):
                            stack[-1][add_c1][add_c2] = pazzle_stack2[add_c1][add_c2]#追加した配列を置き換える

            if result_c == 2:
                if before_move_top == False:
                    stack.append([[8,1,5],[2,0,4],[6,3,7]])#スタックに配列を追加
                    jeneration_stack.append(jeneration)
                    for add_c1 in range(3):
                        for add_c2 in range(3):
                            stack[-1][add_c1][add_c2] = pazzle_stack3[add_c1][add_c2]#追加した配列を置き換える

            if result_c == 3:
                if before_move_left  == False:
                    stack.append([[8,1,5],[2,0,4],[6,3,7]])#スタックに配列を追加
                    jeneration_stack.append(jeneration)
                    for add_c1 in range(3):
                        for add_c2 in range(3):
                            stack[-1][add_c1][add_c2] = pazzle_stack4[add_c1][add_c2]#追加した配列を置き換える

    before_move_top = False
    before_move_under = False
    before_move_left = False
    before_move_right = False
    for result_c in range(4):#移動した場所を記憶しておく
        if result_man[result_c] ==result_border:#移動する場合の条件
            if result_c == 0:
                before_move_top = True#上に移動したのでここがTrue
                before_move_under = False
                before_move_left = False
                before_move_right = False
                tx.write('発見的関数:'+ str(result[0])+'\n')
            if result_c == 1:
                before_move_top = False
                before_move_under = False
                before_move_left = True#左に移動したのでここがTrue
                before_move_right = False
                tx.write('発見的関数:'+ str(result[1])+'\n')
            if result_c == 2:
                before_move_top = False
                before_move_under = True#下に移動したのでここがTrue
                before_move_left = False
                before_move_right = False
                tx.write('発見的関数:'+ str(result[2])+'\n')
            if result_c == 3:
                before_move_top = False
                before_move_under = False
                before_move_left = False
                before_move_right = True#右に移動したのでここがTrue
                tx.write('発見的関数:'+ str(result[3])+'\n')


def cariculate():
    change_box = 0
    global pazzle
    global pazzle_stack1
    global pazzle_stack2
    global pazzle_stack3
    global pazzle_stack4
    global pazzle_changing
    global pazzle_manhattan
    global result_man#メイン文で定義した変数と配列をグローバルとして宣言する
    for copy_c1 in range(3):
        for copy_c2 in range(3):
            pazzle_changing[copy_c1][copy_c2] = pazzle[copy_c1][copy_c2]#パズルをパターン毎に調べるためのリストにpazzleの中身をコピーする
    for c1 in range(3):
        for c2 in range(3):
            if pazzle_changing[c1][c2] == 0:#空白を検出

                #上に移動するパターンを考える
                if c1 - 1 > -1:#インデックスが０以下にならないように条件をつける
                    change_box = pazzle_changing[c1 - 1][c2]
                    pazzle_changing[c1 - 1][c2] = 0
                    pazzle_changing[c1][c2] = change_box
                    for copy_c1 in range(3):
                        for copy_c2 in range(3):
                            pazzle_stack1[copy_c1][copy_c2] = pazzle_changing[copy_c1][copy_c2]
                            pazzle_manhattan[copy_c1][copy_c2] = pazzle_stack1[copy_c1][copy_c2]
                            pazzle_changing[copy_c1][copy_c2] = pazzle[copy_c1][copy_c2]
                    result_man[0] = cariculate_manhattan()#このパターンのマンハッタン距離を調べる
                else:
                    result_man[0]=25#移動できない場合のマンハッタン距離は25とする

                #左に移動するパターンを考える
                if c2 - 1 > -1:#インデックスが０以下にならないように条件をつける
                    change_box = pazzle_changing[c1][c2 - 1]#移動先の数値を確保
                    pazzle_changing[c1][c2] = change_box#置き換え
                    pazzle_changing[c1][c2 - 1] = 0#置き換え
                    for copy_c1 in range(3):
                        for copy_c2 in range(3):
                            pazzle_stack2[copy_c1][copy_c2] = pazzle_changing[copy_c1][copy_c2]
                            pazzle_manhattan[copy_c1][copy_c2] = pazzle_stack2[copy_c1][copy_c2]
                            pazzle_changing[copy_c1][copy_c2] = pazzle[copy_c1][copy_c2]
                    result_man[1] = cariculate_manhattan()#このパターンのマンハッタン距離を調べる
                else:
                    result_man[1]=25#移動できない場合のマンハッタン距離は25とする

                #下に移動するパターンを考える
                if c1 + 1 < 3:#インデックスが３以上にならないように条件をつける
                    change_box = pazzle_changing[c1 +1][c2]#移動先の数値を確保
                    pazzle_changing[c1][c2] = change_box#置き換え
                    pazzle_changing[c1 +1][c2] = 0#置き換え
                    for copy_c1 in range(3):
                        for copy_c2 in range(3):
                            pazzle_stack3[copy_c1][copy_c2] = pazzle_changing[copy_c1][copy_c2]
                            pazzle_manhattan[copy_c1][copy_c2] = pazzle_stack3[copy_c1][copy_c2]
                            pazzle_changing[copy_c1][copy_c2] = pazzle[copy_c1][copy_c2]
                    result_man[2] = cariculate_manhattan()#このパターンのマンハッタン距離を調べる
                else:
                    result_man[2]=25#移動できない場合のマンハッタン距離は25とする

                #右に移動するパターンを考える
                if c2 + 1 < 3:#インデックスが３以上にならないように条件をつける
                    change_box = pazzle_changing[c1][c2 + 1]#移動先の数値を確保
                    pazzle_changing[c1][c2] = change_box#置き換え
                    pazzle_changing[c1][c2 + 1] = 0#置き換え
                    for copy_c1 in range(3):
                        for copy_c2 in range(3):
                            pazzle_stack4[copy_c1][copy_c2] = pazzle_changing[copy_c1][copy_c2]
                            pazzle_manhattan[copy_c1][copy_c2] = pazzle_stack4[copy_c1][copy_c2]
                            pazzle_changing[copy_c1][copy_c2] = pazzle[copy_c1][copy_c2]
                    result_man[3] = cariculate_manhattan()#このパターンのマンハッタン距離を調べる
                else:
                    result_man[3]=25#移動できない場合のマンハッタン距離は25とする

    #ßtx.write(str(result_border))
def cariculate_manhattan():#マンハッタン距離を計算する関数
    global pazzle_manhattan#マンハッタン距離を計算する配列を初期化
    manhattan_total = 0#マンハッタン距離を入れる変数を初期化
    for manhattan_c1 in range(3):
        for manhattan_c2 in range(3):
            for manhattan_c3 in range(3):
                for manhattan_c4 in range(3):
                    if pazzle_manhattan[manhattan_c1][manhattan_c2] is origin[manhattan_c3][manhattan_c4]:#パズルと完成形を比較
                        if pazzle_manhattan[manhattan_c1][manhattan_c2] != 0:
                            math_box1 =manhattan_c1 - manhattan_c3#Y座標のマンハッタン距離を計算
                            math_box2 = manhattan_c2 - manhattan_c4#X座標のマンハッタン距離を計算
                            manhattan = abs(math_box1)+ abs(math_box2)#それぞれのマンハッタン距離の輪を取る
                            manhattan_total = manhattan_total + manhattan
    return manhattan_total#マンハッタン距離を戻り値にする
def change_main_pazzle():#スタックから
    global pazzle
    global stack
    for copy_c1 in range(3):
        for copy_c2 in range(3):
            pazzle[copy_c1][copy_c2] = stack[-1][copy_c1][copy_c2]#検査するパターンをpazzleに写す
    stack.pop()#スタックから検査する物をポップさせる

if __name__ == '__main__':
    import copy
    stack =[]#ノードのスタック
    jeneration_stack = [0]#深さのスタック
    result =[1,2,3,4]#各パターンの発見的関数を保持する
    result_man = [25,25,25,25]#各パターンのマンハッタン距離を保持する
    pazzle =[[8,1,5],#初期状態を定義
             [2,0,4],#空白は０と置く
             [6,3,7]]
    origin = [[1,2,3],#完成形を定義
              [4,5,6],
              [7,8,0]]#空白は０と置く
    before_move_top = False#前回上に移動したかの有無を保持する変数
    before_move_under = False#前回下に移動したかの有無を保持する変数
    before_move_left = False#前回左に移動したかの有無を保持する変数
    before_move_right = False#前回右に移動したかの有無を保持する変数

    pazzle_changing = [[0 for i2 in range(3)] for i1 in range(3)]#３X３の配列を定義
    pazzle_stack1 = [[0 for i2 in range(3)] for i1 in range(3)]#３X３の配列を定義
    pazzle_stack2 = [[0 for i2 in range(3)] for i1 in range(3)]#３X３の配列を定義
    pazzle_stack3 = [[0 for i2 in range(3)] for i1 in range(3)]#３X３の配列を定義
    pazzle_stack4 = [[0 for i2 in range(3)] for i1 in range(3)]#３X３の配列を定義
    pazzle_manhattan = [[0 for i2 in range(3)] for i1 in range(3)]#３X３の配列を定義
    for c1 in range(3):
        for c2 in range(3):
            pazzle_manhattan[c1][c2] = pazzle[c1][c2]#初期化
            pazzle_changing[c1][c2] = pazzle[c1][c2]#初期化
            pazzle_stack1[c1][c2] = pazzle[c1][c2]#初期化
            pazzle_stack2[c1][c2] = pazzle[c1][c2]#初期化
            pazzle_stack3[c1][c2] = pazzle[c1][c2]#初期化
            pazzle_stack4[c1][c2] = pazzle[c1][c2]#初期化
    tx = open("output.txt",'w')#make text file
    version_c = 1
    stack.append(pazzle)#スタックに初期状態をプッシュする
    jeneration = 0#深さを初期化
    while True:#無限ループ
        if len(jeneration_stack) == 0:#スタックが空になったら終了する
            break
        if jeneration_stack[-1] <35:#深さ35以降を切る
            tx.write('\n')
            change_main_pazzle()#スタックからポップさせる関数
            if pazzle == origin:#完成形と一致したら終了
                print('finished')#コンソールにfinishedと表示
                break
            cariculate()#４パターンを考える
            result_check()#マンハッタン距離を出力
            version_c +=1#深さに１加える
            printer()
        else:
            stack.pop()
            jeneration_stack.pop()
            before_move_top = False
            before_move_under = False
            before_move_left = False
            before_move_right = False
