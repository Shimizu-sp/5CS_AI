#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int defalut[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } }; //初期状態
int end[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } }; //ゴール状態

int trade(int x_axis, int y_axis);
int manhattan(int x_axis, int y_axis);

int main(){

	int n, i, man = 0, flag = 0;




	while (1 == 1){
		for (i = 0; i < 3; i++){

			for (n = 0; n < 3; n++){
				printf("%d ", defalut[i][n]);; //現在の状態を表示

				if (defalut[i][n] == -1){ //ピースの入れ替え
					trade(i, n);
				}

				man = man + manhattan(i, n); //現在のマンハッタン距離を計算

			}
			printf("\n");

			if (defalut[i][n] == end[i][n]){
				flag = flag + 1;
			}
			if (flag == 9){ //終了条件
				break;
			}


		}
		printf("マンハッタン距離　= %d\n", man); //マンハッタン距離を表示
		getchar();
		flag = 0;
		man = 0;
	}



	for (i = 0; i < 3; i++){

		for (n = 0; n < 3; n++){
			printf("%d ", defalut[i][n]);; //現在の状態を表示
		}
		printf("\n");
	}


}

int manhattan(int x_axis, int y_axis){ //マンハッタン距離を計算する関数
	int i, n;
	int m = 0;

	for (i = 0; i < 3; i++){
		for (n = 0; n < 3; n++){
			if (defalut[x_axis][y_axis] == end[i][n]){

				m = abs(x_axis - i) + abs(y_axis - n);
				break;
			}
		}

	}

	return m;
}

int trade(int x_axis, int y_axis){ //ピースの入れ替え

	return 0;
}