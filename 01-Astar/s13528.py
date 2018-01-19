#!/usr/bin/env python
#-*- coding: utf-8 -*-

import matplotlib.pyplot as plt
from heapq import heappush, heappop

class Board():
    def __init__(self, board_list, distance, parent):
        self._array = board_list
        self.parent = parent
        self.distance = distance
        self.heuristic = calc_heuristic(self._array)
        self.cost = self.distance + self.heuristic
        self.hashvalue = hash(tuple(self._array))

    def getBoard(self):
        return self._array
    def __hash__(self):
        return self.hashvalue
    def __eq__(self,other):
        return self._array == other._array
    def __lt__(self, other):
        return self._array < other._array


def astar():
    No = 0
    queue = []       #待ち行列
    visited = {}     #過去の盤面
    moved = {}       #手数
    #インスタンス化とコスト記録
    start = Board(start_board, 0, None)
    end = Board(goal_board, 99, None)
    #queueにコストとインスタンスを登録
    heappush(queue, (start.cost, start))
    fp = [] #f(p)の記録用リスト

    #探索開始
    while len(queue) > 0:
        No += 1
        #print(No)
        #コスト最小のノードを取り出す
        now_list = heappop(queue)
        now_board = now_list[1]
        if now_board._array == goal_board:
            end = now_board
            f.write('f(p)の値:'+ '\n' +str(fp) + '\n' + '\n')
            break #ゴールで終了

        #スライド可能なピースのインデックス
        index = now_board._array.index(0)
        x, y = XY_piece(index)
        slidable = slidable_piece(x, y)
        #次のノードの探索
        for piece in slidable:
            next_board = now_board._array[:]
            next_index = piece[0] * Squares + piece[1]
            next_board[index],next_board[next_index] = next_board[next_index],next_board[index]
            #インスタンス化
            new_Board = Board(next_board, now_board.distance+1, now_board)
            new_distance = new_Board.cost
            #visitedの今回のコストのほうが小さいか、未訪問ならコストを追加
            if tuple(new_Board._array) not in visited or new_distance < moved[new_Board]:
                moved[new_Board] = new_distance
                visited[tuple(new_Board._array)] = new_Board    #visitedに追加
                new_Board.parent = now_board                    #親ノードを追加
                heappush(queue, (new_Board.cost, new_Board))    #待ち行列へ
        fp.append([No,new_distance])
    var = end
    ans = []
    while var != start:
        ans = ans + [var.getBoard()]
        var = var.parent
    ans = ans + [var.getBoard()]
    ans.reverse()
    return ans, No

def calc_heuristic(array):      #コスト予測値
    board_list = array
    heuristic = 0
    same = 0
    for var in board_list:      #ピースの不一致数
        x, y = XY_piece(var)
        if goal_board.index(var) != board_list.index(var):
            same += 1
        # ゴール盤面へ移動するときのマンハッタン距離
        pos = goal_board.index(var)
        goal_board_x, goal_board_y = XY_piece(pos)
        x, y = XY_piece(board_list.index(var))
        heuristic += abs(x-goal_board_x) + abs(y-goal_board_y)
    return heuristic

def slidable_piece(x, y):   #スライド可能なピースのリストを返す。
    slidable = [[x, y]]

    if(y+1 < Squares):
        slidable.append([x, y+1])   #U

    if(y-1 >= 0):
        slidable.append([x, y-1])   #D

    if(x+1 < Squares):
        slidable.append([x+1, y])   #R

    if(x-1 >= 0):
        slidable.append([x-1, y])   #L
    return slidable

def XY_piece(index):        #インデックスからXYを返す
    x = index // Squares
    y = index % Squares
    return x, y

def main():
    global start_board, goal_board, Squares# ,No
    Squares = 3 #マス目
    start_board = [8, 1, 5, 2, 0, 4, 6, 3, 7]
    goal_board = [1, 2, 3, 4, 5, 6, 7, 8, 0]
    ans, visit = astar()
    return ans, visit

if __name__ == '__main__':
    f = open('result.txt', 'w')
    ans, visit = main()
    f.write('パズルの盤面:\n')
    for i in range(len(ans)):
        for j in range(Squares):
            f.write(str(ans[i][Squares*j :Squares*j + Squares]) + '\n')
        f.write('\n')
    f.close()
    print(str(len(ans))+'手')
    print('Finished!')
