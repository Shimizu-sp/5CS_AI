import sys
import numpy as np
import math
import copy

def cul(x):
    x = x + 3
    print(x)

lists = []
n_list = []
r_list = []

high_list = []
low_list = []
one_list = []

elite_list = []

up_list = []
down_list = []

mae_list = []
usiro_list = []

child_list = []

gen = 0

b = ""

#10桁2進乱数生成
for i in range(20):
    for ii in range(10):
        a = np.random.randint(2)
        b = str(b) + str(a)
    lists.append(b)
    ii = 1
    b = ""
#print(lists)

# 0000000000 ～　1111111111 まで1023刻み
# 25 / 1024 ≒ 0.024

#遺伝子を10進数に変換
while gen < 501:
    print("Generation : %d" % gen)

    #print(lists)
    for i in range(20):
        #print(lists[i])
        lists[i] = int(lists[i],2) #2進数を10進数に変換
        #print(lists[i])
        n_list.append(-10 + 0.024 * lists[i]) #-10～15の1024段階で表現
        if n_list[i] == 14.552: #111111111の補完
            n_list[i] = 15
        n_list[i] = '{0:8.6g}'.format(n_list[i])
        n_list[i] = float(n_list[i])
        #print(n_list[i]) # -10～15で表現

    #print(n_list)

    #関数に代入
    for i in range(20):
        x = n_list[i]
        if n_list[i] > -8.5: #複素数を除く処理
            a = math.sin(x*math.pi)/7 * (4*math.log(x+15))/(x + 15) + 0.35*math.sqrt(x+8.5)
        else:
            a = 0
        r_list.append(a)

    iii = 99

    #重複分保存
    s = set()
    w_list = [x for x in n_list if x in s or s.add(x)]
    #print(w_list)

    #print(w_list)

    #print(r_list)
    x = zip(n_list, r_list) #タプルでラベル付け
    #print(x)
    nr_list = dict(x) #タプルを辞書化
    #print(nr_list)

    i = 0

    #（関数の解≒適合度）降順にソート
    for k, v in sorted(nr_list.items(), key=lambda x: -x[1]): #適合度キーで降順ソート
        if i < 10:
            #print(float(k))
            high_list.append(float(k))
        one_list.append(float(k))
        i += 1

        print("x = %.3f : f(x) = %.17f " % (float(k),float(v)))
    #print(high_list)
    #print(low_list)
    #print(one_list)

    count = 0

    while len(one_list) < 20:
        if len(one_list) < 20:
            one_list.append(w_list[count])
            count += 1
    #print(len(one_list))

    #エリート選択
    for i in range(len(high_list)):
        elite_list.append(high_list[0])
        elite_list.append(high_list[i])
    #print(elite_list)

    #print(one_list)
    #ルーレット選択
    while len(low_list) < 10:
        a = np.random.randint(401)
        if (0 < a <= 1):
            low_list.append(one_list[0])
        elif (1 < a < 4):
            low_list.append(one_list[1])
        elif (4 < a <= 9):
            low_list.append(one_list[2])
        elif (9 < a <= 16):
            low_list.append(one_list[3])
        elif (16 < a <= 25):
            low_list.append(one_list[4])
        elif (25 < a <= 36):
            low_list.append(one_list[5])
        elif (36 < a <= 49):
            low_list.append(one_list[6])
        elif (49 < a <= 64):
            low_list.append(one_list[7])
        elif (64 < a <= 81):
            low_list.append(one_list[8])
        elif (81 < a <= 100):
            low_list.append(one_list[9])
        elif (100 < a <= 121):
            low_list.append(one_list[10])
        elif (121 < a <= 144):
            low_list.append(one_list[11])
        elif (144 < a <= 169):
            low_list.append(one_list[12])
        elif (169 < a <= 196):
            low_list.append(one_list[13])
        elif (196 < a <= 225):
            low_list.append(one_list[14])
        elif (225 < a <= 256):
            low_list.append(one_list[15])
        elif (256 < a <= 289):
            low_list.append(one_list[16])
        elif (289 < a <= 324):
            low_list.append(one_list[17])
        elif (324 < a <= 361):
            low_list.append(one_list[18])
        elif (361 < a <= 400):
            low_list.append(one_list[19])
    #print(low_list)
    #print(len(low_list))

    ii = 0
    #print(elite_list)
    #print(low_list)
    #10進数を遺伝子に変換
    for i in range(20):
        if i < 10:
            #10進数を遺伝子に変換
            a = int((elite_list[i] + 10)/0.024)
            a = '{0:8.8g}'.format(a)
            #print(a)
            a = int(a) #左詰め
            #print(a)
            a = bin(a)[2:].zfill(10)
            #print(a)
            up_list.append(a)
        else:
            #print(low_list[ii])
            #10進数を遺伝子に変換
            a = int((low_list[ii] + 10)/0.024)
            a = '{0:8.20g}'.format(a)
            #print(a)
            a = int(a) #左詰め
            #print(a)
            a = bin(a)[2:].zfill(10)
            #print(a)
            down_list.append(a)
            ii += 1

    #print(up_list)
    #print(down_list)

    def split_str(s, n):
        length = len(s)
        return [s[i:i+n] for i in range(0, length, n)]


    for i in range(5):
        mae_list = split_str(up_list[2*i - 1], 5)
        usiro_list = split_str(up_list[2*i], 5)
        #print(mae_list)
        #print(usiro_list)
        a = mae_list[0] + usiro_list[1]
        b = mae_list[1] + usiro_list[0]
        child_list.append(a)
        child_list.append(b)
    for i in range(5):
        mae_list = split_str(down_list[2*i - 1], 5)
        usiro_list = split_str(down_list[2*i], 5)
        #print(mae_list)
        #print(usiro_list)
        a = mae_list[0] + usiro_list[1]
        b = mae_list[1] + usiro_list[0]
        child_list.append(a)
        child_list.append(b)

    del lists[:]

    lists = copy.deepcopy(child_list)

    del n_list[:]
    del r_list[:]
    del high_list[:]
    del low_list[:]
    del one_list[:]
    del elite_list[:]
    del up_list[:]
    del down_list[:]
    del mae_list[:]
    del usiro_list[:]
    del child_list[:]
    #print(lists)

    gen += 1

    #key = input("continue...")



#print(child_list)
