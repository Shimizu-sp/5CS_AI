#!/usr/bin/env python
#-*- coding: utf-8 -*-

class Creature(object): #生物クラス
    def __init__(self):
        self.attr = '呼吸する'

    def printAttr(self):
        print('生物は{0}'.format(self.attr))


class Bird(Creature):   #鳥クラス
    def __init__(self):
        super().__init__()
        self.have = '翼がある'

    def printHave(self):
        print('鳥には{0}'.format(self.have))

class Parrot(Bird): #オウムクラス
    def __init__(self):
        super().__init__()
        self.abil = 'モノマネ'

    def printAbil(self):
        print('オウムの特技は{0}'.format(self.abil))


def main():
    oum = Parrot() #oumにオウムクラスを継承
    print('オウムの特技は何ですか => ',end="")
    oum.printAbil() #返答としてオウムクラスのprintAbilを返す．

    print('オウムは呼吸するか？ => ',end="")
    if oum.attr == '呼吸する':  #呼吸する場合は，Yes
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()
