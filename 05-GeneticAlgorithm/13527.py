# -*- coding: utf-8 -*-
import sys
from math import *
import numpy as np
import numpy.random as random

#整数部5桁 小数部5桁

def main():
	population=20 #個体数
	gen_size=10 #遺伝子の数
	generation=500 #世代数
	mutate_para = 0.05
	ind=np.zeros((population,gen_size),dtype=np.int32) #親の個体[個体数,遺伝子]
	child1=np.zeros((10,gen_size),dtype=np.int32) #子の上位個体[個体数,遺伝子]
	child2=np.zeros((10,gen_size),dtype=np.int32) #子の下位個体[個体数,遺伝子]
	offspring=np.zeros((population,gen_size),dtype=np.int32) #子の個体
	fitness = np.zeros(population,dtype=np.float) #適応度

	#初期集団の生成
	for i in range(0,population):
		ind[i]=random.randint(0,2,size=10)
	for i in range(0,population):
		fitness[i]=eval(ind[i])
	max_fit = max(fitness)
	print("初期集団の適応度の最大値:%s" % max_fit)
	print("それのxの値:%s" % round(encode(ind[np.argmax(fitness)]),2))
	#進化開始
	for i in range(1,generation):
		#選択
		child1,child2=selection(ind,fitness)
		#交叉
		child1,child2=crossover(child1,child2)
		#child1とchild2を合体する
		offspring= np.r_[child1, child2]
		#突然変異
		for j in range(0,population):
			if random.random() < mutate_para:
				offspring[j]=mutate(offspring[j])
		ind=offspring
		#計算
		for j in range(0,population):
			fitness[j]=eval(ind[j])
		max_fit = max(fitness)
		print("第"+str(i)+"世代の最大値:%s" % max_fit)
		print("それのxの値:%s" % round(encode(ind[np.argmax(fitness)]),2))


#選択
def selection(ind,fit):
	population=20 #個体数
	gen_size=10 #染色体の数
	child1=np.zeros((10,gen_size),dtype=np.int32) #子の上位個体[個体数,遺伝子]
	child2=np.zeros((10,gen_size),dtype=np.int32) #子の下位個体[個体数,遺伝子]
	select_fit = np.zeros(population,) #適応度の保存
	select_fit=fit
	sumfit=sum(fit)
	#ルーレット選択
	for i in range(0,10):
		hozon_fit=0
		point = round(random.uniform(0, sumfit),2)
		for j in range(0,population):
			if(point>=hozon_fit and point<(hozon_fit+fit[j])):
				child2[i]=ind[j]
				break
			hozon_fit+=fit[j]
	#エリート選択
	for i in range(0,10):
		child1[i]=ind[np.argmax(select_fit)]
		select_fit[np.argmax(select_fit)] = -100000
	return child1,child2

#交叉
def crossover(ind1,ind2):
	ind1[0:5]=ind2[5:10]
	ind2[0:5]=ind1[5:10]

	return ind1,ind2

#突然変異
def mutate(ind):
	size = len(ind)
	point = random.randint(0, size)
	if(ind[point]==0):
		ind[point]=1
	else:
		ind[point]=0
	return ind

#評価関数
def eval(ind):
  ten_shin = encode(ind)
  #8.51以上だと虚数が出てくるので弾く
  if(ten_shin < -8.500):
  	return 0
  else:
  	return round(sin((ten_shin*pi)/7)*((4*log(ten_shin+15))/(ten_shin+15))+0.35*sqrt(ten_shin+8.5),2)

#2進数を10進数にする
def encode(ind):
	#indが正の数の場合
	if(ind[0]==0):
		#個体を整数部と小数部に分割
		in_val = ind[0:5]
		sho_val = ind[5:10]
		#整数部を変換
		two_shin = ''#2進数の値を保存する
		for x in in_val:
			two_shin += str(x)
		values=int(two_shin,2)
		in_hozon =  -(values & 0b10000) | (values & 0b01111) #整数部保存
		sho_hozon=sho_val[0]*0.5+sho_val[1]*0.25+sho_val[2]*0.125+sho_val[3]*0.0625+sho_val[4]*0.03125
		return (in_hozon+sho_hozon)

	#indが負の数の場合
	else:
		#マイナスなのでビット反転する
		for i in range(0,len(ind)):
			if(ind[i]==0):
				ind[i]=1
			else:
				ind[i]=0
		#1を足す
		if(ind[9]==0):
			ind[9]=1
		elif(ind[9]==1 and ind[8]==0):
			ind[9]=0
			ind[8]=1
		elif(ind[9]==1 and ind[8]==1 and ind[7]==0):
			ind[9]=0
			ind[8]=0
			ind[7]=1
		elif(ind[9]==1 and ind[8]==1 and ind[7]==1 and ind[6]==0):
			ind[9]=0
			ind[8]=0
			ind[7]=0
			ind[6]=1
		elif(ind[9]==1 and ind[8]==1 and ind[7]==1 and ind[6]==1 and ind[5]==0):
			ind[9]=0
			ind[8]=0
			ind[7]=0
			ind[6]=0
			ind[5]=1
		elif(ind[9]==1 and ind[8]==1 and ind[7]==1 and ind[6]==1 and ind[5]==1 and ind[4]==0):
			ind[9]=0
			ind[8]=0
			ind[7]=0
			ind[6]=0
			ind[5]=0
			ind[4]=1
		elif(ind[9]==1 and ind[8]==1 and ind[7]==1 and ind[6]==1 and ind[5]==1 and ind[4]==1 and ind[3]==0):
			ind[9]=0
			ind[8]=0
			ind[7]=0
			ind[6]=0
			ind[5]=0
			ind[4]=0
			ind[3]=1
		elif(ind[9]==1 and ind[8]==1 and ind[7]==1 and ind[6]==1 and ind[5]==1 and ind[4]==1 and ind[3]==1 and ind[2]==0):
			ind[9]=0
			ind[8]=0
			ind[7]=0
			ind[6]=0
			ind[5]=0
			ind[4]=0
			ind[3]=0
			ind[2]=1
		elif(ind[9]==1 and ind[8]==1 and ind[7]==1 and ind[6]==1 and ind[5]==1 and ind[4]==1 and ind[3]==1 and ind[2]==1 and ind[1]==0):
			ind[9]=0
			ind[8]=0
			ind[7]=0
			ind[6]=0
			ind[5]=0
			ind[4]=0
			ind[3]=0
			ind[2]=0
			ind[1]=1
		elif(ind[9]==1 and ind[8]==1 and ind[7]==1 and ind[6]==1 and ind[5]==1 and ind[4]==1 and ind[3]==1 and ind[2]==1 and ind[1]==1 and ind[0]==0):
			ind[9]=0
			ind[8]=0
			ind[7]=0
			ind[6]=0
			ind[5]=0
			ind[4]=0
			ind[3]=0
			ind[2]=0
			ind[1]=0
			ind[0]=1
		#個体を整数部と小数部に分割
		in_val = ind[0:5]
		sho_val = ind[5:10]
		#整数部を変換
		two_shin = ''#2進数の値を保存する
		for x in in_val:
			two_shin += str(x)
		values=int(two_shin,2)
		in_hozon =  -(values & 0b10000) | (values & 0b01111) #整数部保存
		sho_hozon=sho_val[0]*0.5+sho_val[1]*0.25+sho_val[2]*0.125+sho_val[3]*0.0625+sho_val[4]*0.03125
		return (in_hozon+sho_hozon)

if __name__ == "__main__":
    main()