#include<stdio.h>
#include <stdlib.h>

main(){
	int i, j,x,y,flag,kinb,kinb2,kinb3,kinb4,ans1,ans2,ans3,ans4,ex,ex2,ex3,ex4;

	int start[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } };
	int  goal[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };


	//空白のマスの座標を探す
	printf("開始状態\n");
	for (j = 0; j < 3; j++){
		for (i = 0; i < 3; i++){
			printf(" %d", start[i][j]);

		}
		printf("\n");
	}

	printf("\n");

	for (j = 0; j < 3; j++){
		for (i = 0; i < 3; i++){
			if (start[i][j] == 0){
				x = i;
				y = j;
				flag = 1;
				break;
			}
			if (flag == 1){
				break;
			}


		}
		
	}printf("空白マスの座標は[%d,%d]\n",x, y);

	//空白のマスの４近傍の座標ををansに代入
	kinb = x - 1;
	kinb2 = x + 1;
	kinb3 = y - 1;
	kinb4 = y + 1;

	ans1 = start[kinb][y];
	ans2 = start[kinb2][y];
	ans3 = start[x][kinb3];
	ans4 = start[x][kinb4];


	printf("\n空白のマスの近傍は\n上が%d\n下が%d\n左が%d\n右が%d\n", ans1, ans2, ans3, ans4);

	//空白のマスと近傍を入れ替える
	int ato_x = kinb;
	int ato_y = y;
	int hozon = 0;

	hozon = start[x][y];
	start[x][y] = start[ato_x][ato_y];
	start[ato_x][ato_y] = hozon;




	}