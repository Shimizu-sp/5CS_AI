import numpy as np
import math
import copy
from numpy.random import *
#from matplotlib import pyplot

MAX_INDIVIDUAL = 20             # 初期個体数 #
MAX = 15                        # 実数の最大値 #
MIN = -10                       # 実数の最小値 #
GTYPE_LENGTH = 10               # 遺伝子長 #
INTERSECTION_POINT = 5          # 交叉点 遺伝子長の中央値 #
MUTATION_RATE = 0.05            # 突然変異率 #
MUTATION_POINT = 0              # 突然変異の座標 #
GENERATION_LIMIT = 500            # 世代数 #
PI = 3.14

class GA:
    def __init__(self):
        self.gtype = [[0 for i in range(GTYPE_LENGTH)] for j in range(MAX_INDIVIDUAL)]  # 遺伝子 #
        self.decimal = [0 for i in range(MAX_INDIVIDUAL)]                               # 10進数 #
        self.ptype = [0 for i in range(MAX_INDIVIDUAL)]                                 # 発現型 #
        self.fitness = [0 for i in range(MAX_INDIVIDUAL)]                               # 適応度 #
        self.total_mutation_count = 0                                                 # 突然変異回数 #
        self.max = 0                                                                  # 最良解 #
        self.max_fitness = 0                                                          # 最良解の適応度 #
        # 初期個体生成 #
        for i in range(GTYPE_LENGTH):
            for j in range(MAX_INDIVIDUAL):
                self.gtype[j][i] = random_integers( 0, 1)
    def radtrans(self):         # 基数変換　2進数 → 10進数 #
        for i in range(GTYPE_LENGTH):
            for j in range(MAX_INDIVIDUAL):
                self.decimal[j] += self.gtype[j][i] * pow(2,i)
    def calcptype(self):        # ptype計算 #
        for i in range(MAX_INDIVIDUAL):
                self.ptype[i] = MIN + ( ( (MAX - MIN) / pow(2,10) ) * self.decimal[i] )
                self.ptype[i] = round(self.ptype[i], 2)
    def fx(self, x):            # 関数 #
        a = np.sin( (x * PI) / 7 )
        b = (4 * np.log(x+ 15)) / (x + 15)
        c = 0.35 * np.sqrt(x + 8.5)
        ans = a * b + c
        ans = round(ans, 2) # 少数第2位へ丸める #
        return ans
    def calcfitness(self):      # 適応度計算 #
        for i in range(MAX_INDIVIDUAL):
                #self.fitness[i] = 1 /(1+ abs(self.fx(self.ptype[i])) )
                self.fitness[i] =  self.fx(self.ptype[i])
                self.fitness[i] = round(self.fitness[i], 2) # 少数第2位へ丸める #
    def crossover(self): # 遺伝子の交叉 #
        # 次世代の遺伝子 #
        next_gtype = [[0 for i in range(GTYPE_LENGTH)] for j in range(MAX_INDIVIDUAL)]
        max_num = 0             # 最大値保存 #
        min_num = 1             # 最小値保存 #
        max_index = 0           # 最大値のインデックス保存 #
        min_index = 0           # 最小値のインデックス保存 #
        max_gtype = [[] for x in range(GTYPE_LENGTH)]
        min_gtype = [[] for x in range(GTYPE_LENGTH)]
        temp_g1 = [[] for x in range(int(GTYPE_LENGTH/2))]
        temp_g2 = [[] for x in range(int(GTYPE_LENGTH/2))]

        # エリート選択 #
        for i in range(MAX_INDIVIDUAL): #最大値取得#
            if(max_num < self.fitness[i]):
                max_num = self.fitness[i]
                max_index = i
                max_gtype = copy.deepcopy(self.gtype[i])
        for i in range(MAX_INDIVIDUAL): #最小値取得#
            if(min_num > self.fitness[i]):
                min_num = self.fitness[i]
                min_index = i
                min_gtype = copy.deepcopy(self.gtype[i])
        for i in range(int(MAX_INDIVIDUAL/2)): #次のgtypeへコピー#
            if(i%2 == 0):
                next_gtype[i] = copy.deepcopy(max_gtype)
            else:
                next_gtype[i] = copy.deepcopy(min_gtype)
        # ルーレット選択 #
        for i in range(int(MAX_INDIVIDUAL/2),MAX_INDIVIDUAL):
            j = random_integers( 0, MAX_INDIVIDUAL-1)
            next_gtype[i] = copy.deepcopy(self.gtype[j])
        # 交叉 #
        for i in range(GTYPE_LENGTH):   # 1点交叉 #
            for j in range(MAX_INDIVIDUAL-1):
                temp_g1 = next_gtype[j][0:5]
                temp_g2 = next_gtype[j+1][0:5]
                next_gtype[j][:5] = temp_g2
                next_gtype[j+1][:5] = temp_g1
        self.gtype = copy.deepcopy(next_gtype)
    def mutation(self):     #突然変異#
        # 突然変異確率計算 #
        r1 = random_integers( 0, 99)
        if(r1 <= int(MUTATION_RATE*100)):  # 突然変異 #
            r2 = random_integers( 0, 19)   # 突然変異する遺伝子選定 #
            r3 = random_integers( 0, 9)    # 対象となる遺伝子のインデックス取得 #
            if(self.gtype[r2][r3] == 0):
                self.gtype[r2][r3] = 1
            else:
                self.gtype[r2][r3] = 0
            self.total_mutation_count += 1
    def summary(self):  # 世代の最大値などを取得 #
        self.max_fitness = -10
        for i in range(MAX_INDIVIDUAL): #最大値取得#
            if(self.max_fitness < self.fitness[i]):
                self.max = self.ptype[i]
                self.max_fitness = self.fitness[i]
    def disp(self):        # 遺伝子情報の表示 #
        # debug #
        '''
        print('num            gtype              ptype  fitness')
        for i in range(MAX_INDIVIDUAL):
            if(i <= 9):
                print(' {} {} {}    {}'.format( i, self.gtype[i], self.ptype[i], self.fitness[i]) )
            else:
                print('{} {} {}    {}'.format( i, self.gtype[i], self.ptype[i], self.fitness[i]) )
        '''
        #print('total_mutation = {}'.format(self.total_mutation_count))
        print('      x        = {}'.format(self.max))
        print('max_fitness    = {}'.format(self.max_fitness))
        print('-------------------------------------------------')
    def run(self): # GAの実行 #
        for i in range(GENERATION_LIMIT): # 500世代実施 #
            print('-----------------{} GENERATION------------------'.format(i+1))
            self.radtrans()     # 基数変換　2進数 → 10進数 #
            self.calcptype()    # ptype計算 #
            self.calcfitness()  # 適応度計算 #
            self.crossover()    # 遺伝子の交叉 #
            self.mutation()     # 突然変異 #
            self.summary()      # 世代の最大値などを取得 #
            self.disp()         # 遺伝子情報の表示 #
            self.decimal = [0 for i in range(MAX_INDIVIDUAL)] # 初期化 #
            ansx = self.max

if __name__ == '__main__':
    ga = GA()
    ga.run()
    # plot graph #
    '''
    pi = math.pi   #mathモジュールのπを利用
    x = np.linspace(-10, 15, 1024)  #0から2πまでの範囲を100分割したnumpy配列
    y  = np.sin( (x * PI) / 7 ) * ((4 * np.log(x+ 15)) / (x + 15)) + (0.35 * np.sqrt(x + 15))
    pyplot.plot(x, y)
    pyplot.show()
    '''
