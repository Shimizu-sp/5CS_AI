import copy

# 失敗作

puzzle = [ 8, 1, 5, 2, 9, 4, 6, 3, 7 ]
comp   = [ 1, 2, 3, 4, 5, 6, 7, 8, 9 ]
direct_list = []
pre_puzzle = []

tmp_num = 10
tmp_num2 = 10
cost_num = 1
all_puzzle = [ [ 8, 1, 5, 2, 9, 4, 6, 3, 7 ] ]
cnt = 0

# マンハッタン距離を求める
def ManhattanFunc( data ):
	sum_cnt = 0
	for i in range( len( data ) ):
		if data[i] == 9:
			continue
		num = abs( i + 1 - data[i] )
		if num <= 2:
			sum_cnt += num
		else:
			if num % 3 == 0:
				sum_cnt += num / 3
			else:
				sum_cnt += num % 3 + (num - num % 3 ) / 3
	return sum_cnt 

def cost( data ):
	return ManhattanFunc( data )

# パズルの動かし方
def AbleMovePuzzle( data ):
	able_move = []	
	free = data.index( 9 ) + 1

	if free % 3 != 0:
		able_move.append( free + 1 )
		if free % 3 != 1:
			able_move.append( free - 1 )
	else:
		able_move.append( free - 1 )
	if free < 7:
		able_move.append( free + 3 )
		if free > 3:
			able_move.append( free - 3 )
	else:
		able_move.append( free - 3 )
	return free,able_move
	
# パズルの交換
def ChangePuzzle( data ): 
	global tmp_num, cost_num, direct_list, puzzle,cnt
	chose = 0

	# 動かせるパネルの方向を確認
	free,able_move = AbleMovePuzzle( data )

	min = ( 0, 81 )
	di_list = []

	# パズルを保存
	all_puzzle.append( copy.deepcopy( puzzle ) )
	
	for i in able_move:
		if i == tmp_num:
			continue
		tmp_puzzle = copy.deepcopy( puzzle )
		tmp_puzzle[ free - 1 ] , tmp_puzzle[ i - 1 ] = tmp_puzzle[ i - 1 ],  tmp_puzzle[ free - 1 ]

		# 今までにあったか検索
		num, exist = Search( tmp_puzzle )
		if exist:
			continue
		chose = 1
		di_list.append( i )
		direct_list.append( di_list )
		
		print( "値:{0} 範囲:{1} コスト:{2} パズル:{3}".format( i,able_move,cost(tmp_puzzle), tmp_puzzle ) )
		if min[1] > cost( tmp_puzzle ):
			min = i, cost( tmp_puzzle )

	if chose == 0:
		puzzle = all_puzzle[-2]
		tmp_num = free
	else:
		puzzle[ free - 1 ], puzzle[ min[0] - 1 ] = puzzle[ min[0] - 1 ], puzzle[ free - 1 ]
		cost_num += 1
		tmp_num = free	# 動かした方向を保存
	
# 今までに存在したか
def Search( data ):
	for i in range( len( all_puzzle ) ):
		if all_puzzle[i] == data:
			return i, True
	return 0, False

if __name__ == '__main__':
	global cnt
	while cnt != 2000:
		ChangePuzzle( puzzle )
		print( puzzle[0:3] )
		print( puzzle[3:6] )
		print( puzzle[6:9] )
		cnt = cnt + 1
	
