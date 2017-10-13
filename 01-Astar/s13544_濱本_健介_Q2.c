#include<stdio.h>

int main(){
	
	int box[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } };//初期状態（空白は0とする）および移動後の盤面
	int box_up[3][3] = { 0 };
	int box_left[3][3] = { 0 };
	int box_right[3][3] = { 0 };
	int box_doun[3][3] = { 0 };
	int i,j,n,m;//ループカウンター
	int x_0, y_0;//0の入っている座標
	int x, y;
	int x_g, y_g;//ゴールの座標
	int m1=0, m2=0, m3=0, m4=0,M=100;//マンハッタン距離
	int g=0;//経路コスト
	int f1=0,f2=0,f3=0,f4=0;//発見的関数の値
	int ck=0;//大小関係を調べるチェッカー

	g++;

	//while (M != 0){

		//初期状態表示
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				printf("%d ", box[i][j]);
			}
			printf("\n");
		}

		//0の位置を求める
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (box[i][j] == 0){
					break;
				}
			}
			if (box[i][j] == 0){
				break;
			}
		}
		printf("\n0:box[%d][%d]\n\n", i, j);

		//上の数字を0の位置に入れた場合のマンハッタン距離を求める
		printf("---UP---\n\n");
		//0とその上の数字の入れ替え
		x_0 = i;
		y_0 = j;
		box[x_0][y_0] = box[x_0 - 1][y_0];
		box[x_0 - 1][y_0] = 0;

		//マンハッタン距離の総和を求める
		for (n = 0; n < 3; n++){
			for (m = 0; m < 3; m++){
				x = n;
				y = m;
				switch (box[x][y]){
				case 1:
					x_g = 0;
					y_g = 0;
					break;
				case 2:
					x_g = 0;
					y_g = 1;
					break;
				case 3:
					x_g = 0;
					y_g = 2;
					break;
				case 4:
					x_g = 1;
					y_g = 0;
					break;
				case 5:
					x_g = 1;
					y_g = 1;
					break;
				case 6:
					x_g = 1;
					y_g = 2;
					break;
				case 7:
					x_g = 2;
					y_g = 0;
					break;
				case 8:
					x_g = 2;
					y_g = 1;
					break;
				case 0:
					x_g = x;
					y_g = y;
					break;
				}
				while (x != x_g){
					if (x > x_g){
						x = x - 1;
						m1++;
					}
					else if (x < x_g){
						x = x + 1;
						m1++;
					}
				}
				while (y != y_g){
					if (y>y_g){
						y = y - 1;
						m1++;
					}
					else if (y < y_g){
						y = y + 1;
						m1++;
					}
				}
			}
		}
		printf("M1=%d\n\n", m1);

		//盤面の保持
		for (m = 0; m < 3; m++){
			for (n = 0; n < 3; n++){
				box_up[m][n] = box[m][n];
				printf("%d ", box[m][n]);
			}
			printf("\n");
		}
		printf("\n");

		//パズルを入れ替える前の状態に戻す
		box[x_0 - 1][y_0] = box[x_0][y_0];
		box[x_0][y_0] = 0;


		//左の数字を0の位置に入れた場合のマンハッタン距離を求める
		printf("---LEFT---\n\n");
		//0とその左の数字の入れ替え
		x_0 = i;
		y_0 = j;
		box[x_0][y_0] = box[x_0][y_0 - 1];
		box[x_0][y_0 - 1] = 0;

		//マンハッタン距離の総和を求める
		for (n = 0; n < 3; n++){
			for (m = 0; m < 3; m++){
				x = n;
				y = m;
				switch (box[x][y]){
				case 1:
					x_g = 0;
					y_g = 0;
					break;
				case 2:
					x_g = 0;
					y_g = 1;
					break;
				case 3:
					x_g = 0;
					y_g = 2;
					break;
				case 4:
					x_g = 1;
					y_g = 0;
					break;
				case 5:
					x_g = 1;
					y_g = 1;
					break;
				case 6:
					x_g = 1;
					y_g = 2;
					break;
				case 7:
					x_g = 2;
					y_g = 0;
					break;
				case 8:
					x_g = 2;
					y_g = 1;
					break;
				case 0:
					x_g = x;
					y_g = y;
					break;
				}
				while (x != x_g){
					if (x > x_g){
						x = x - 1;
						m2++;
					}
					else if (x < x_g){
						x = x + 1;
						m2++;
					}
				}
				while (y != y_g){
					if (y>y_g){
						y = y - 1;
						m2++;
					}
					else if (y < y_g){
						y = y + 1;
						m2++;
					}
				}
			}
		}
		printf("M2=%d\n\n", m2);

		//盤面の保持
		for (m = 0; m < 3; m++){
			for (n = 0; n < 3; n++){
				box_up[m][n] = box[m][n];
				printf("%d ", box[m][n]);
			}
			printf("\n");
		}
		printf("\n");

		//パズルを入れ替える前の状態に戻す
		box[x_0][y_0 - 1] = box[x_0][y_0];
		box[x_0][y_0] = 0;


		//右の数字を0の位置に入れた場合のマンハッタン距離を求める
		printf("---RIGHT---\n\n");
		//0とその右の数字の入れ替え
		x_0 = i;
		y_0 = j;
		box[x_0][y_0] = box[x_0][y_0 + 1];
		box[x_0][y_0 + 1] = 0;

		//マンハッタン距離の総和を求める
		for (n = 0; n < 3; n++){
			for (m = 0; m < 3; m++){
				x = n;
				y = m;
				switch (box[x][y]){
				case 1:
					x_g = 0;
					y_g = 0;
					break;
				case 2:
					x_g = 0;
					y_g = 1;
					break;
				case 3:
					x_g = 0;
					y_g = 2;
					break;
				case 4:
					x_g = 1;
					y_g = 0;
					break;
				case 5:
					x_g = 1;
					y_g = 1;
					break;
				case 6:
					x_g = 1;
					y_g = 2;
					break;
				case 7:
					x_g = 2;
					y_g = 0;
					break;
				case 8:
					x_g = 2;
					y_g = 1;
					break;
				case 0:
					x_g = x;
					y_g = y;
					break;
				}
				while (x != x_g){
					if (x > x_g){
						x = x - 1;
						m3++;
					}
					else if (x < x_g){
						x = x + 1;
						m3++;
					}
				}
				while (y != y_g){
					if (y>y_g){
						y = y - 1;
						m3++;
					}
					else if (y < y_g){
						y = y + 1;
						m3++;
					}
				}
			}
		}
		printf("M3=%d\n\n", m3);

		//盤面の保持
		for (m = 0; m < 3; m++){
			for (n = 0; n < 3; n++){
				box_up[m][n] = box[m][n];
				printf("%d ", box[m][n]);
			}
			printf("\n");
		}
		printf("\n");

		//パズルを入れ替える前の状態に戻す
		box[x_0][y_0 + 1] = box[x_0][y_0];
		box[x_0][y_0] = 0;


		//下の数字を0の位置に入れた場合のマンハッタン距離を求める
		printf("---DOWN---\n\n");
		//0とその下の数字の入れ替え
		x_0 = i;
		y_0 = j;
		box[x_0][y_0] = box[x_0 + 1][y_0];
		box[x_0 + 1][y_0] = 0;

		//マンハッタン距離の総和を求める
		for (n = 0; n < 3; n++){
			for (m = 0; m < 3; m++){
				x = n;
				y = m;
				switch (box[x][y]){
				case 1:
					x_g = 0;
					y_g = 0;
					break;
				case 2:
					x_g = 0;
					y_g = 1;
					break;
				case 3:
					x_g = 0;
					y_g = 2;
					break;
				case 4:
					x_g = 1;
					y_g = 0;
					break;
				case 5:
					x_g = 1;
					y_g = 1;
					break;
				case 6:
					x_g = 1;
					y_g = 2;
					break;
				case 7:
					x_g = 2;
					y_g = 0;
					break;
				case 8:
					x_g = 2;
					y_g = 1;
					break;
				case 0:
					x_g = x;
					y_g = y;
					break;
				}
				while (x != x_g){
					if (x > x_g){
						x = x - 1;
						m4++;
					}
					else if (x < x_g){
						x = x + 1;
						m4++;
					}
				}
				while (y != y_g){
					if (y>y_g){
						y = y - 1;
						m4++;
					}
					else if (y < y_g){
						y = y + 1;
						m4++;
					}
				}
			}
		}
		printf("M4=%d\n\n", m4);

		//盤面の保持
		for (m = 0; m < 3; m++){
			for (n = 0; n < 3; n++){
				box_up[m][n] = box[m][n];
				printf("%d ", box[m][n]);
			}
			printf("\n");
		}
		printf("\n");

		//パズルを入れ替える前の状態に戻す
		box[x_0 + 1][y_0] = box[x_0][y_0];
		box[x_0][y_0] = 0;

		printf("\n");

		//各マンハッタン距離の総和に経路コストを足す
		printf("---COST---\n\n");
		f1 = g + m1;
		f2 = g + m2;
		f3 = g + m3;
		f4 = g + m4;

		printf("f1=%d\nf2=%d\nf3=%d\nf4=%d\n", f1, f2, f3, f4);

		printf("\n");

		if (f1 < f2 && f1 < f3 && f1 < f4){
			for (m = 0; m < 3; m++){
				for (n = 0; n < 3; n++){
					box[m][n] = box_up[m][n];
					printf("%d ", box[m][n]);
				}
				printf("\n");
			}
		}
		


	//}
}