import random
import math

def check_degree():
    global dna_list
    global jav
    global rulet
    global mother
    global sort
    global bigest
    global bigest_location 
    sum_value = 0.0
    counter = 0
    for counter in range(20):
        harf = 0.1
        four =dna_list[counter][1]*8#2の3乗の個所を計算
        three = dna_list[counter][2]*4#2の2乗の個所を計算
        two = dna_list[counter][3]*2#2の1乗の個所を計算
        one = dna_list[counter][4]
        real_number_part = four+ three +two +one#整数を計算
        harf = dna_list[counter][5]*0.5#少数桁の考慮
        quorter = dna_list[counter][6]*0.25#少数桁の考慮
        harf1 = dna_list[counter][7]*0.125#少数桁の考慮
        harf2 = dna_list[counter][8]*0.0625#少数桁の考慮
        harf3 = dna_list[counter][9]*0.03125#少数桁の考慮
        syousu = harf+quorter+harf1+harf2+harf3#少数の和をとる
        degree = syousu + real_number_part#全体を足し合わせる
        degree = round(degree,2)
        locat = degree
        if dna_list[counter][0] == 1 :
            degree=degree*(-1)#符号ビットの考慮
        if -10<degree <15:#範囲内のみ計算
            degree =math.sin(degree*math.pi/7)*(4*math.log(degree + 15))/(degree+15)+0.35*math.sqrt(math.fabs(degree) + 8.5)#計算
        else:
            degree = -179#logが0以下に触れた場合は範囲外に飛ばす
        degree = round(degree,2)
        sum_value+=degree#ルーレット設定用の全体和を計算
        jav[counter] = degree
    for counter1 in range(20):#エリート選択のためにバブルソートを行う
        for counter2 in range(20):
            if counter2 <19:
                if jav[counter2] < jav[counter2 +1]:
                    place = jav[counter2]
                    jav[counter2 ] = jav[counter2 +1]
                    jav[counter2 +1]=place
                    place2 = sort[counter2]#ソート順位を保持
                    sort[counter2 ] = sort[counter2 +1]
                    sort[counter2+1]=place2
    if jav[0] > bigest:
        bigest = jav[0]
        bigest_location = locat
    place = 0#初期化
    for counter in range(20):#ルーレット
        rulet[counter] =round(( (jav[counter] /sum_value + place)*100),0)#ルーレットを作成し0〜100までの範囲に補正
        place =jav[counter] /sum_value#現状のルーレットが埋まってる範囲

    darts1 = random.randint(0,100)#ルーレット1
    darts2 = random.randint(0,100)#ルーレット2
    darts3 = random.randint(0,100)#ルーレット3
    darts4 = random.randint(0,100)#ルーレット4
    darts5 = random.randint(0,100)#ルーレット5
    darts6 = random.randint(0,100)#ルーレット6
    darts7 = random.randint(0,100)#ルーレット7
    darts8 = random.randint(0,100)#ルーレット8
    darts9 = random.randint(0,100)#ルーレット9
    darts0 = random.randint(0,100)#ルーレット10
    for counter in range(10):
        if darts0 < rulet[counter]:
            rulet_r[counter]=counter
            darts0 = 102#ルーレットで当たったので範囲外へ
        if darts1 < rulet[counter]:
            rulet_r[counter]=counter
            darts1 = 102#ルーレットで当たったので範囲外へ
        if darts2 < rulet[counter]:
            rulet_r[counter]=counter
            darts2 = 102#ルーレットで当たったので範囲外へ
        if darts3 < rulet[counter]:
            rulet_r[counter]=counter
            darts3 = 102#ルーレットで当たったので範囲外へ
        if darts4 < rulet[counter]:
            rulet_r[counter]=counter
            darts4 = 102#ルーレットで当たったので範囲外へ
        if darts5 < rulet[counter]:
            rulet_r[counter]=counter
            darts5 = 102#ルーレットで当たったので範囲外へ
        if darts6 < rulet[counter]:
            rulet_r[counter]=counter
            darts6 = 102#ルーレットで当たったので範囲外へ
        if darts7 < rulet[counter]:
            rulet_r[counter]=counter
            darts7 = 102#ルーレットで当たったので範囲外へ
        if darts8 < rulet[counter]:
            rulet_r[counter]=counter
            darts8 = 102#ルーレットで当たったので範囲外へ
        if darts9 < rulet[counter]:
            rulet_r[counter]=counter
            darts9 = 102#ルーレットで当たったので範囲外へ
    for counter in range(10):#ルーレットで選択された遺伝子を保持
        mother[11][counter] = dna_list[rulet_r[1]][counter]
        mother[12][counter] = dna_list[rulet_r[2]][counter]
        mother[13][counter] = dna_list[rulet_r[3]][counter]
        mother[14][counter] = dna_list[rulet_r[4]][counter]
        mother[15][counter] = dna_list[rulet_r[5]][counter]
        mother[16][counter] = dna_list[rulet_r[6]][counter]
        mother[17][counter] = dna_list[rulet_r[7]][counter]
        mother[18][counter] = dna_list[rulet_r[8]][counter]
        mother[19][counter] = dna_list[rulet_r[9]][counter]
        mother[10][counter] = dna_list[rulet_r[0]][counter]



dna_list =[[random.randint(0,1)for i in range(10)]for j in range(20)]#遺伝子を保持するリスト
jav = [0 for i in range(20)]#値を保持するリスト
sort = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19]
mother = [[0 for i in range(10)]for j in range(20)]#親遺伝子を保持する場所
rulet =[0 for i in range(20)]
rulet_r =[0 for i in range(20)]
bigest =0.0
bigest_location =0.0
for jeneration_counter in range(500):#500世代の計算
    print("jeneration:",end="")
    print(jeneration_counter)
    check_degree()
    for counter in range(10):#エリート部分の保持
        mother[0][counter] = dna_list[sort[0]][counter]
        mother[1][counter] = dna_list[sort[1]][counter]
        mother[2][counter] = dna_list[sort[2]][counter]
        mother[3][counter] = dna_list[sort[3]][counter]
        mother[4][counter] = dna_list[sort[4]][counter]
        mother[5][counter] = dna_list[sort[5]][counter]
        mother[6][counter] = dna_list[sort[6]][counter]
        mother[7][counter] = dna_list[sort[7]][counter]
        mother[8][counter] = dna_list[sort[8]][counter]
        mother[9][counter] = dna_list[sort[9]][counter]
    change=random.randint(0,19)#突然変異させる親の番号を計算
    change_place = random.randint(0,9)#突然変異させる場所
    for counter in range(10):

        if counter < 5:#上5bitはそのまま
            dna_list[0][counter]=mother[0][counter]
            dna_list[1][counter]=mother[1][counter]
            dna_list[2][counter]=mother[2][counter]
            dna_list[3][counter]=mother[3][counter]
            dna_list[4][counter]=mother[4][counter]
            dna_list[5][counter]=mother[5][counter]
            dna_list[6][counter]=mother[6][counter]
            dna_list[7][counter]=mother[7][counter]
            dna_list[8][counter]=mother[8][counter]
            dna_list[9][counter]=mother[9][counter]
            dna_list[10][counter]=mother[10][counter]
            dna_list[11][counter]=mother[11][counter]
            dna_list[12][counter]=mother[12][counter]
            dna_list[13][counter]=mother[13][counter]
            dna_list[14][counter]=mother[14][counter]
            dna_list[15][counter]=mother[15][counter]
            dna_list[16][counter]=mother[16][counter]
            dna_list[17][counter]=mother[17][counter]
            dna_list[18][counter]=mother[18][counter]
            dna_list[19][counter]=mother[19][counter]
        else:#下はペアのものを保持
            dna_list[0][counter]=mother[1][counter]
            dna_list[1][counter]=mother[0][counter]
            dna_list[2][counter]=mother[3][counter]
            dna_list[3][counter]=mother[2][counter]
            dna_list[4][counter]=mother[5][counter]
            dna_list[5][counter]=mother[4][counter]
            dna_list[6][counter]=mother[7][counter]
            dna_list[7][counter]=mother[6][counter]
            dna_list[8][counter]=mother[9][counter]
            dna_list[9][counter]=mother[8][counter]
            dna_list[10][counter]=mother[11][counter]
            dna_list[11][counter]=mother[10][counter]
            dna_list[12][counter]=mother[13][counter]
            dna_list[13][counter]=mother[12][counter]
            dna_list[14][counter]=mother[15][counter]
            dna_list[15][counter]=mother[14][counter]
            dna_list[16][counter]=mother[17][counter]
            dna_list[17][counter]=mother[16][counter]
            dna_list[18][counter]=mother[19][counter]
            dna_list[19][counter]=mother[18][counter]
    if dna_list[change][change_place] ==1 :#突然変異箇所をビット反転
            dna_list[change][change_place] =0
    else:
            dna_list[change][change_place] =1
    print("\n")

print("500世代計算後の最大値：",end="")
print(jav[0])
four =dna_list[0][1]*8#2の3乗の個所を計算
three = dna_list[0][2]*4#2の2乗の個所を計算
two = dna_list[0][3]*2#2の1乗の個所を計算
one = dna_list[0][4]
real_number_part = four+ three +two +one#整数を計算
harf = dna_list[0][5]*0.5#少数桁の考慮
quorter = dna_list[0][6]*0.25#少数桁の考慮
harf1 = dna_list[0][7]*0.125#少数桁の考慮
harf2 = dna_list[0][8]*0.0625#少数桁の考慮
harf3 = dna_list[0][9]*0.03125#少数桁の考慮
syousu = harf+quorter+harf1+harf2+harf3#少数の和をとる
degree = syousu + real_number_part#全体を足し合わせる
degree = round(degree,2)
print("xの値：",end="")
print(degree)
print("\n")
print("計算中の最大値：",end="")
print(bigest)
print("xの値：",end="")
print(bigest_location)
