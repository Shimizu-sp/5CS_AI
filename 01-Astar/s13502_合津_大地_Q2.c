#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Hyouji(int array[3][3]);
void Manhattan(int array_start[3][3], int array_goal[3][3]);
void Whereishole(int array[3][3]);

main() {
	int start[3][3] = { {8, 1, 5},	//初期状態
						{2, 0, 4},
						{6, 3, 7} };


	int goal[3][3] = { {1, 2, 3},	//ゴール状態
						{4, 5, 6},
						{7, 8, 0} };

	Hyouji(start);
	printf("\n");
	Hyouji(goal);

	Manhattan(start, goal);

	Whereishole(start);

}





void Hyouji(int array[3][3]){	//パズル表示用関数

	int hyouji_x = 0 , hyouji_y=0 ;

	for (hyouji_x = 0; hyouji_x < 3; hyouji_x++){
		for (hyouji_y = 0; hyouji_y < 3; hyouji_y++){
			printf("%d ,", array[hyouji_x][hyouji_y]);

		}
		printf("\n");

	}
	printf("\n");
}

void Whereishole(int array[3][3]) {	//穴あき位置を確認
	int i, e;

	for (i = 0; i < 3; i++) {
		for (e = 0; e < 3; e++) {
			if (array[i][e] == 0) {

				printf(" 穴あきの位置は start[%d][%d] です\n", i, e);

			}
		}
	}
	
}

void Manhattan(int array_start[3][3], int array_goal[3][3]) {
	int i, e;	//for用
	int n;		//現在検索中の値
	int manhattan_souwa=0;	//マンハッタン距離の総和
	int manhattan_start_x, manhattan_start_y, manhattan_goal_x, manhattan_goal_y;	//初期状態の位置（x,y）, ゴール状態の位置（x,y）

	
	for (n = 1; n < 9; n++) {	//1〜8までのマンハッタン距離の総和を求める

		for (i = 0; i < 3; i++) {		//初期状態の数値 n の位置を検索
			for (e = 0; e < 3; e++) {
				if (array_start[i][e] == n) {
					manhattan_start_x = i;	//初期状態のnの位置(x)
					manhattan_start_y = e;	//初期状態のnの位置(y)

				}
			}
		}
		//printf("%d %d\n", manhattan_start_x, manhattan_start_y);


		
		for (i = 0; i < 3; i++) {		//ゴール状態の数値 n の位置を検索
			for (e = 0; e < 3; e++) {
				if (array_goal[i][e] == n) {
					manhattan_goal_x = i;	//ゴール状態のnの位置(x)
					manhattan_goal_y = e;	//ゴール状態のnの位置(y)

				}
			}
		}
		//printf("%d %d\n", manhattan_goal_x, manhattan_goal_y);

		//マンハッタン距離＝|x1 - x2| + |y1 - y2|
		manhattan_souwa += abs(manhattan_goal_x - manhattan_start_x) + abs(manhattan_goal_y - manhattan_start_y);

	}

	printf("マンハッタン距離の総和 = %d\n", manhattan_souwa); //
}
