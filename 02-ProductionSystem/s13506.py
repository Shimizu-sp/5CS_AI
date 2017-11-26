# ルール1: 全ての降られた整数値が順番通りなら終了
def Rule1( str ):	
	for i in range( len(str) - 1 ):
		if str[i][1] != i:
			return False
	return True

# ルール2: 次の要素の割り振られた整数値と比較し 大きければ交換
def Rule2( str ):
	for i in range( len(str) - 1 ):
		if str[i][1] > str[i+1][1]:
			str[i],str[i+1] = str[i+1],str[i]
			Show( str )

# 表示		
def Show( str ):
	for i in range( len(str) ):
		print( str[i][0],end='' )
	print()

if __name__ == "__main__":
	str = [ ('a',6), ("*",9), ("b",5) , ("-",8 ) , ("c",4 ), ("d",3), ("/",10 ), ("e",2 ), ("+",7 ), ("f",1 ), ("g",0 ) ]

	# 表示
	print("変更前")
	Show( str )

	print("ルール適用")
	while 1:
		# ルール1を適用　正しければ終了
		if Rule1( str ):
			break

		# ルール2を適用
		Rule2( str )
	
	# 表示
	print("変更後")
	Show( str )
