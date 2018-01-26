#!/usr/bin/env python
#-*- coding: utf-8 -*-
import random
import math
from operator import itemgetter

gene_num = 20
def first_generation():
    gene = []
    for i in range(gene_num):
        r = format(random.randint(0,1023),'010b')
        gene.append([r, 0])
    return gene

def toDecimal(num): #二進数から10進数に変換
    num = int(num,2) * 25/1023 -10
    return round(num, 2)

def eval_func(x):
    x = toDecimal(x)
    if x <= -8.5: #虚数が出る場合は(0.35*math.sqrt(x+8.5)を０とする
        return round(math.cos(math.pi * x /7) * 4*math.log(x + 15)/(x+15), 2)
    fx = round(math.cos(math.pi * x /7) * 4*math.log(x + 15)/(x+15) + (0.35*math.sqrt(x+8.5)), 2)
    return fx

def check_fit(gene): #適応度を計算してソートして返す
    for i in range(gene_num):
        gene[i][1] = eval_func(gene[i][0])
    gene = sorted(gene, key=itemgetter(1), reverse=True)
    return gene

def elite(gene):
    """エリート選択．上位から2組ずつ1点交叉(5:5)"""
    new_gene = []
    for i in range(gene_num//4):
        a, b = gene[i*2][0],gene[i*2+1][0]
        new_gene.append([a[:5] + b[5:], 0])
        new_gene.append([b[:5] + a[5:], 0])
    return new_gene

def roulette(gene):
    """ルーレット交叉．下位10の適応度の総和との割合を比重に選択．1点交叉(5:5)"""
    gene_sum =0
    new_gene = []
    for i in range(gene_num//2):
        gene_sum += gene[10+i][1] + 10

    for i in range(gene_num//2):
        ref = 0
        while(gene_sum > ref):
            r = random.randint(9,19)
            ref += gene[r][1] + 10
            if gene_sum > ref:
                a = gene[r][0]
        ref = 0
        while(gene_sum > ref):
            r = random.randint(9,19)
            ref += gene[r][1] + 10
            if gene_sum > ref:
                b = gene[r][0]
        new_gene.append([a[:5] + b[5:], 0])
        new_gene.append([b[:5] + a[5:], 0])
    return new_gene

def crossover(gene): #選択と交叉
    next_gene = []
    next_gene.extend(elite(gene))
    next_gene.extend(roulette(gene))
    return next_gene

def mutation(gene): #突然変異
    r1 = random.randint(0,19)
    temp = list(gene[r1][0])
    r2 = random.randint(0,9)
    if temp[r2] == "1":
        temp[r2] = "0"
    elif temp[r2] == "0":
        temp[r2] = "1"
    gene[r1][0] = "".join(temp)
    return gene


if __name__ == '__main__':
    generations = 500
    total_max = -10
    gene = first_generation()
    for i in range(generations):
        gene = check_fit(gene)
        print("世代数:" + str(i+1) + "  最大値:"+ str(toDecimal(gene[0][0])) )
        if total_max < toDecimal(gene[1][0]):
            total_max = toDecimal(gene[1][0])
        gene = crossover(gene)
        gene = mutation(gene)
    print("500世代を通しての最大値:" + str(total_max))
