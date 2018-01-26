# -*- coding: utf-8 -*-

from pyevolve import G1DList, GSimpleGA, Selectors
from pyevolve import Initializators, Mutators, Consts,Crossovers
import math
import numpy as np

# 評価関数
def eval_func(x):
    x= int(''.join(map(str, x)), base=2)
    pi=math.pi/7
    log=np.log(x+15)
    sqrt=np.sqrt(x+8.5)
    sin=np.sin(x*pi)
    score=sin*4*log/x+15+0.35*sqrt
    return score

# Genome Instance
genome = G1DList.G1DList(10)#遺伝子のサイズ
genome.setParams(rangemin=0, rangemax=1)#最小値、最大値
# 評価関数をセット
genome.evaluator.set(eval_func)
# 評価をするGAEngine を作成
ga = GSimpleGA.GSimpleGA(genome)
Consts.CDefTournamentPoolSize = 10 #エリート選択の選択する数
ga.selector.set(Selectors.GTournamentSelector)#エリート選択
ga.selector.set(Selectors.GRouletteWheel)#ルーレット選択
genome.crossover.set(Crossovers.G1DBinaryStringXSinglePoint)#一点交叉
ga.setGenerations(500)#世代数
ga.setPopulationSize(20)#遺伝子数
ga.setCrossoverRate(0.5)# 交叉確率
ga.setMutationRate(0.05)# 突然変異の発生確率
# 評価開始
ga.evolve(freq_stats=10) #10世代おきに途中経過を表示
result=ga.bestIndividual()#結果表示
print(result)