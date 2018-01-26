# -*- coding:utf-8 -*-
from pyevolve import G1DList, GSimpleGA, Selectors
from pyevolve import Initializators, Mutators, Consts
import math

# 関数
def function(genome):
   X = genome[0]
   t1 = math.sin((X*math.pi)/7);
   t2 = (4*math.log(X+15))/(X+15);
   t3 = 0.35*math.sqrt(X+8.5);
   score = (t1*t2)+t3;
   return score

# Genome instance
genome = G1DList.G1DList(10)# xの遺伝子サイズをあらわす
# rangemax,rangemin … xとyの範囲
genome.setParams(rangemin=-10, rangemax=15, bestRawScore=0.00, roundDecimal=2)
# G1DListをrangemin,rangemaxの間で初期化
genome.initializator.set(Initializators.G1DListInitializatorReal)
# rangemin,rangemaxの値の間で突然変異する
genome.mutator.set(Mutators.G1DListMutatorRealGaussian)

# 評価関数
genome.evaluator.set(function)


ga = GSimpleGA.GSimpleGA(genome)
 # 選択方法はルーレット方式
ga.selector.set(Selectors.GRouletteWheel)

ga.minimax = Consts.minimaxType["maximize"]
ga.setGenerations(500)# 500世代まで計算
ga.setMutationRate(0.05)# 突然変異率 0.05
ga.setPopulationSize(20)  # 集団の数は20
ga.terminationCriteria.set(GSimpleGA.RawScoreCriteria)# 個体から得られるbestrawscoreによって進化を打ち切る

# 評価開始,100世代ごとに途中経過を表示
ga.evolve(freq_stats=100)

# 最も良いものを表示
best = ga.bestIndividual()
print best
print "best score: %.2f" % best.getRawScore()
