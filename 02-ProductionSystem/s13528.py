
#!/usr/bin/env python
#-*- coding: utf-8 -*-

f = open('result.txt', 'w')

def rule1(moji):    #文字列の中で隣り合わせの文字が左が記号，右がアルファベットの場合，左右交換
    symbol = ['+', '-', '*', '/']
    alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
    temp = ''
    for i in range(10):
        if moji[i] in symbol and moji[i+1] in alphabet:
            temp = moji[i]
            moji[i] = moji[i+1]
            moji[i+1] = temp
            f.writelines("R1を適用→ " + str(moji[i+1]) + " と " + str(moji[i]) + " を交換： " + str(','.join(moji)) + "\n")
            print("R1を適用：" + str(moji))
            break
    return moji,temp

def rule2(moji):    #左から7文字目までの文字列の中で，隣り合わせの文字の左のユニコードポイントより右のユニコードポイントが大きい場合，左右交換
    temp = ''
    for i in range(7):
        if ord(moji[i]) < ord(moji[i+1]):
            temp = moji[i]
            moji[i] = moji[i+1]
            moji[i+1] = temp
            f.writelines("R2を適用→ " + str(moji[i+1]) + " と " + str(moji[i]) + " を交換： " + str(','.join(moji)) + "\n")
            print("R2を適用：" + str(moji))
            break
    return moji,temp

def rule3(moji):    #8~11文字目の文字列の中で「+」がある場合，その左の文字と+を交換
    temp = ''
    for i in range(8,11):
        if moji[i] == '+':
            temp = moji[i]
            moji[i] = moji[i-1]
            moji[i-1] = temp
            f.writelines("R3を適用→ " + str(moji[i]) + " と + を交換： " + str(','.join(moji)) + "\n")
            print("R3を適用：" + str(moji))
            break
    return moji,temp

def rule4(moji):    #9~11文字目の文字列の中で「-」がある場合，その左の文字と-を交換
    temp = ''
    for i in range(9,11):
        if moji[i] == '-':
            temp = moji[i]
            moji[i] = moji[i-1]
            moji[i-1] = temp
            f.writelines("R4を適用→ " + str(moji[i]) + " と - を交換： " + str(','.join(moji)) + "\n")
            print("R4を適用：" + str(moji))
            break
    return moji,temp

def rule5(moji):    #11文字目が「/」でない場合，10文字目と11文字目を交換
    temp = ''
    if moji[10] != '/':
        temp = moji[10]
        moji[10] = moji[10-1]
        moji[10-1] = temp
        f.writelines("R5を適用→ " + str(moji[i])+ " / と を交換： " + str(','.join(moji)) + "\n")
        print("R5を適用：" + str(moji))
    return moji,temp

def main(moji):     #rule１から適用しスワップを行なったらまたrule１から適用を行うループ
    while True:
        moji,flg = rule1(moji)
        if flg == '':
            moji,flg = rule2(moji)
            if flg == '':
                moji,flg = rule3(moji)
                if flg == '':
                    moji,flg = rule4(moji)
                    if flg == '':
                        moji,flg = rule5(moji)
                        if flg == '':   #全てのルールが適用できない場合に終了
                            break
    f.close()
    print("Finish!")

if __name__ == '__main__':
    start ='*gfedcba+-*/'
    main(list(start))
