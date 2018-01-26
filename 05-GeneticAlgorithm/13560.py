import random
import math
from operator import itemgetter

count = 20


def func1():
    gene = []
    for i in range(count):
        fg = (format(random.randint(0,1023),'010b'))
        x = int(fg,2) * 25 / 1024 - 10
        if x <= -8.5:
            fx = round(math.cos(math.pi * x / 7) * 4 * math.log(x + 15) / (x + 15),2)
        else:
            fx = round(math.cos(math.pi * x / 7) * 4 * math.log(x + 15) / (x + 15) + (0.35 * math.sqrt(x + 8.5)), 2)
        gene.append([fg,fx])
    return gene

if __name__ == '__main__':
    gene = func1()

    print('\n初期遺伝子生成')
    print(gene)
