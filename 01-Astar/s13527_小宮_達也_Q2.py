# -*- coding: utf-8 -*-
import numpy as np
from collections import deque

def main():
	output = open('output.txt','w')
	graph = open('graph.txt','w')
	first = np.array([[8, 1, 5] , [2, 0, 4] , [6, 3, 7]]) #初期状態
	now = np.array([ [8, 1, 5] , [2, 0, 4] , [6, 3, 7] ])  #現在状態
	end = np.array([ [1, 2, 3], [4, 5, 6], [7, 8, 0] ]) #終了状態
	hozon = np.array([]) #次の状態候補を保存する
	hozon_list = [] #次の状態候補たちを保存する
	kinbou = [] #空白位置の近傍座標を保存するリスト
	h_cost_list = [] #h関数の値を保存する
	g_cost_list = [] #g関数の値を保存する
	f_cost_list = [] #発見的関数の値を保存する
	used_list = [] #探索済みリスト
	flag = 0
	stack_d = deque()
	count = 1
	print(now)	

    #現在状態が終了状態になるまで繰り返す
	while (np.allclose(now,end) == False):
		used_list.append(now)
    	#空白位置を調べる
		now_x,now_y = blank(now)

		#空白位置の近傍を調べる
		kinbou = blank_kinbou(now_x,now_y)

		#近傍の発見的関数の値を調べる
		for i in kinbou:
			h_cost,hozon = h(i[0],i[1],now_x,now_y,now,end)
			g_cost = g(i[0],i[1],now_x,now_y,first,hozon)
			#探索済みのやつがあるか調べる
			for j in used_list:
				if (np.allclose(j,hozon) == True):
					#あったらフラグを立てて弾く
					flag=1
					break
			if (flag==0):
				h_cost_list.append(h_cost)
				g_cost_list.append(g_cost)
				hozon_list.append(hozon)
			flag=0

		for (hcost,gcost) in zip(h_cost_list,g_cost_list):
			f_cost_list.append(hcost+gcost)

		#スタックを作成する
		for i in range(0,len(f_cost_list)):
			stack_d.appendleft([hozon_list[f_cost_list.index(max(f_cost_list))],max(f_cost_list)])
			f_cost_list[f_cost_list.index(max(f_cost_list))] = -1


		#交換する
		stack = stack_d.popleft()
		now = stack[0]
		output.write(str(stack[0]))
		output.write('\n')
		output.write('発見的関数値:%d' % int(stack[1]))
		output.write('\n')
		graph.write('%d ' % count)
		graph.write('%d\n' % int(stack[1]))
		print(now)
		h_cost_list = []
		g_cost_list = []
		hozon_list = []
		f_cost_list = []
		count+=1

	print("終わり\n")
	output.close()
	graph.close()

#初期状態から現在状態までの経路コスト(OK)
def g(piece_x,piece_y,blank_x,blank_y,first=[],now=[]):
      p=0
      changes=np.array(now)
      hozon=changes[piece_x][piece_y]
      changes[piece_x][piece_y]=changes[blank_x][blank_y]
      changes[blank_x][blank_y]=hozon
      for i in range(1,9):
            p+=manhattan(i,first,changes)
      return p

#現在の状態からゴール状態までの最適コストの推定値を求める関数(OK)
def h(piece_x,piece_y,blank_x,blank_y,now=[],end=[]):
	p=0
	changes=np.array(now)
	hozon=changes[piece_x][piece_y]
	changes[piece_x][piece_y]=changes[blank_x][blank_y]
	changes[blank_x][blank_y]=hozon
	for i in range(1,9):
		p+=manhattan(i,changes,end)
	return p,changes

#マンハッタン距離を求める関数(OK)
def manhattan(i,start=[],end=[]):
	#現在状態のiのインデックスを取り出す
	index_i = np.where(start==i)
	i_x = index_i[0][0]
	i_y = index_i[1][0]
	#終了状態のiのインデックスを取り出す
	index_end = np.where(end==i)
	end_x = index_end[0][0]
	end_y = index_end[1][0]
	#マンハッタン距離を求める
	m = abs(i_x - end_x) + abs(i_y - end_y)
	#マンハッタン距離を返す
	return m

#空白位置を調べる(OK)
def blank(hoge=[]):
	for i in range(0,3):
		for j in range(0,3):
			if(hoge[i][j]==0):
				x=i
				y=j
	return x,y

#空白位置の近傍を調べる(OK)
def blank_kinbou(x,y):
	kinbou = []
	#近傍箇所が2箇所か調べる
	if (x==0 and y==0):
		kinbou1_x = x+1
		kinbou1_y = y
		kinbou2_x = x
		kinbou2_y = y+1
		kinbou.append([kinbou1_x,kinbou1_y])
		kinbou.append([kinbou2_x,kinbou2_y])
	if (x==0 and y==2):
		kinbou1_x = x+1
		kinbou1_y = y
		kinbou2_x = x
		kinbou2_y = y-1
		kinbou.append([kinbou1_x,kinbou1_y])
		kinbou.append([kinbou2_x,kinbou2_y])
	if (x==2 and y==0):
		kinbou1_x = x
		kinbou1_y = y+1
		kinbou2_x = x-1
		kinbou2_y = y
		kinbou.append([kinbou1_x,kinbou1_y])
		kinbou.append([kinbou2_x,kinbou2_y])
	if (x==2 and y==2):
		kinbou1_x = x-1
		kinbou1_y = y
		kinbou2_x = x
		kinbou2_y = y-1
		kinbou.append([kinbou1_x,kinbou1_y])
		kinbou.append([kinbou2_x,kinbou2_y])
	#近傍箇所が3近傍か調べる
	if (x==1 and y==0):
		kinbou1_x = x+1
		kinbou1_y = y
		kinbou2_x = x-1
		kinbou2_y = y
		kinbou3_x = x
		kinbou3_y = y+1
		kinbou.append([kinbou1_x,kinbou1_y])
		kinbou.append([kinbou2_x,kinbou2_y])
		kinbou.append([kinbou3_x,kinbou3_y])
	if (x==0 and y==1):
		kinbou1_x = x+1
		kinbou1_y = y
		kinbou2_x = x
		kinbou2_y = y-1
		kinbou3_x = x
		kinbou3_y = y+1
		kinbou.append([kinbou1_x,kinbou1_y])
		kinbou.append([kinbou2_x,kinbou2_y])
		kinbou.append([kinbou3_x,kinbou3_y])
	if (x==2 and y==1):
		kinbou1_x = x
		kinbou1_y = y+1
		kinbou2_x = x
		kinbou2_y = y-1
		kinbou3_x = x-1
		kinbou3_y = y
		kinbou.append([kinbou1_x,kinbou1_y])
		kinbou.append([kinbou2_x,kinbou2_y])
		kinbou.append([kinbou3_x,kinbou3_y])
	if (x==1 and y==2):
		kinbou1_x = x+1
		kinbou1_y = y
		kinbou2_x = x-1
		kinbou2_y = y
		kinbou3_x = x
		kinbou3_y = y-1
		kinbou.append([kinbou1_x,kinbou1_y])
		kinbou.append([kinbou2_x,kinbou2_y])
		kinbou.append([kinbou3_x,kinbou3_y])
	#近傍箇所が4箇所か調べる
	if (x==1 and y==1):
		kinbou1_x = x+1
		kinbou1_y = y
		kinbou2_x = x-1
		kinbou2_y = y
		kinbou3_x = x
		kinbou3_y = y+1
		kinbou4_x = x
		kinbou4_y = y-1
		kinbou.append([kinbou1_x,kinbou1_y])
		kinbou.append([kinbou2_x,kinbou2_y])
		kinbou.append([kinbou3_x,kinbou3_y])
		kinbou.append([kinbou4_x,kinbou4_y])

	return kinbou

if __name__ == '__main__':
    main()
