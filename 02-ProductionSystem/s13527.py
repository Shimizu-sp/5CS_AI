# -*- coding: utf-8 -*-

def main():
	#現在状態
	start = ['a','*','b','-','c','d','/','e','+','f','g']
	#ゴール状態
	end = ['g','f','e','d','c','b','a','+','-','*','/']

	#状態が一致するまでループする
	while start != end:
		for i in range(0,len(start)-1):
			#R1
			if (start[i]=="a") and (start[i+1]=="b"):
				#交換する
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("aとbを交換する")
			#R2
			elif (start[i]=="a") and (start[i+1]=="c"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("aとcを交換する")
			#R3
			elif (start[i]=="a") and (start[i+1]=="d"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("aとdを交換する")
			#R4
			elif (start[i]=="a") and (start[i+1]=="e"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("aとeを交換する")
			#R5
			elif (start[i]=="a") and (start[i+1]=="f"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("aとfを交換する")
			#R6
			elif (start[i]=="a") and (start[i+1]=="g"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("aとgを交換する")
			#R7
			elif (start[i]=="b") and (start[i+1]=="c"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("bとcを交換する")
			#R8
			elif (start[i]=="b") and (start[i+1]=="d"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("bとdを交換する")
			#R9
			elif (start[i]=="b") and (start[i+1]=="e"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("bとeを交換する")
			#R10
			elif (start[i]=="b") and (start[i+1]=="f"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("bとfを交換する")
			#R11
			elif (start[i]=="b") and (start[i+1]=="g"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("bとgを交換する")
			#R12
			elif (start[i]=="c") and (start[i+1]=="d"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("cとdを交換する")
			#R13
			elif (start[i]=="c") and (start[i+1]=="e"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("cとeを交換する")
			#R14
			elif (start[i]=="c") and (start[i+1]=="f"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("cとfを交換する")
			#R15
			elif (start[i]=="c") and (start[i+1]=="g"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("cとgを交換する")
			#R16
			elif (start[i]=="d") and (start[i+1]=="e"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("dとeを交換する")
			#R17
			elif (start[i]=="d") and (start[i+1]=="f"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("dとfを交換する")
			#R18
			elif (start[i]=="d") and (start[i+1]=="g"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("dとgを交換する")
			#R19
			elif (start[i]=="e") and (start[i+1]=="f"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("eとfを交換する")
			#R20
			elif (start[i]=="e") and (start[i+1]=="g"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("eとgを交換する")
			#R21
			elif (start[i]=="f") and (start[i+1]=="g"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("fとgを交換する")
			#R22
			elif (start[i]=="+") and (start[i+1]=="a"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("+とaを交換する")
			#R23
			elif (start[i]=="+") and (start[i+1]=="b"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("+とbを交換する")
			#R24
			elif (start[i]=="+") and (start[i+1]=="c"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("+とcを交換する")
			#R25
			elif (start[i]=="+") and (start[i+1]=="d"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("+とdを交換する")
			#R26
			elif (start[i]=="+") and (start[i+1]=="e"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("+とeを交換する")
			#R27
			elif (start[i]=="+") and (start[i+1]=="f"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("+とfを交換する")
			#R28
			elif (start[i]=="+") and (start[i+1]=="g"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("+とgを交換する")
			#R29
			elif (start[i]=="-") and (start[i+1]=="a"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("-とaを交換する")
			#R30
			elif (start[i]=="-") and (start[i+1]=="b"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("-とbを交換する")
			#R31
			elif (start[i]=="-") and (start[i+1]=="c"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("-とcを交換する")
			#R32
			elif (start[i]=="-") and (start[i+1]=="d"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("-とdを交換する")
			#R33
			elif (start[i]=="-") and (start[i+1]=="e"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("-とeを交換する")
			#R34
			elif (start[i]=="-") and (start[i+1]=="f"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("-とfを交換する")
			#R35
			elif (start[i]=="-") and (start[i+1]=="g"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("-とgを交換する")
			#R36
			elif (start[i]=="-") and (start[i+1]=="+"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("-と+を交換する")
			#R37
			elif (start[i]=="*") and (start[i+1]=="a"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("*とaを交換する")
			#R38
			elif (start[i]=="*") and (start[i+1]=="b"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("*とbを交換する")
			#R39
			elif (start[i]=="*") and (start[i+1]=="c"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("*とcを交換する")
			#R40
			elif (start[i]=="*") and (start[i+1]=="d"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("*とdを交換する")
			#R41
			elif (start[i]=="*") and (start[i+1]=="e"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("*とeを交換する")
			#R42
			elif (start[i]=="*") and (start[i+1]=="f"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("*とfを交換する")
			#R43
			elif (start[i]=="*") and (start[i+1]=="g"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("*とgを交換する")
			#R44
			elif (start[i]=="*") and (start[i+1]=="+"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("*と+を交換する")
			#R45
			elif (start[i]=="*") and (start[i+1]=="-"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("*と-を交換する")
			#R46
			elif (start[i]=="/") and (start[i+1]=="a"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("/とaを交換する")
			#R47
			elif (start[i]=="/") and (start[i+1]=="b"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("/とbを交換する")
			#R48
			elif (start[i]=="/") and (start[i+1]=="c"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("/とcを交換する")
			#R49
			elif (start[i]=="/") and (start[i+1]=="d"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("/とdを交換する")
			#R50
			elif (start[i]=="/") and (start[i+1]=="e"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("/とeを交換する")
			#R51
			elif (start[i]=="/") and (start[i+1]=="f"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("/とfを交換する")
			#R52
			elif (start[i]=="/") and (start[i+1]=="g"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("/とgを交換する")
			#R53
			elif (start[i]=="/") and (start[i+1]=="+"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("/と+を交換する")
			#R54
			elif (start[i]=="/") and (start[i+1]=="-"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("/と-を交換する")
			#R55
			elif (start[i]=="/") and (start[i+1]=="*"):
				hozon=start[i]
				start[i]=start[i+1]
				start[i+1]=hozon
				print("/と*を交換する")


if __name__ == '__main__':
    main()
