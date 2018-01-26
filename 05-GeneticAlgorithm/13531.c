#include<stdio.h>
#include<string.h>

void main(){
	srand((unsigned int)time(NULL));

	int g[20][10];//[x][y] x=遺伝子コード番号 ,y=二進数
	int tekiou[20];//[x] 適応度記録　x=順位
	int loop,i,j,k,l,random,change,tt1,tt2;
	//乱数による初期遺伝子生成　10桁の数値を20個生成
	for (i = 0; i < 20; i++){
		for (j = 0; j < 10; j++){
			g[i][j] = rand() % 2;
		}
	}

	//以下500世代分ループ
	for (loop = 0; loop < 500; loop++) {
	/*******************************************************/
		//適応度計算	
		for (i = 0; i < 20; i++) {
			for (j = 0; j < 20; j++) {

				/**********未実装**********/

			}
		}

		//適応度を基準に順位付け//選択（上位10個　エリート選択）
		for (i = 0; i < 20; i++) {
			tt1 = 0;
			tt2 = -1;
			for (j = i; j < 20; j++) {
				if (tekiou[j] >tt1) {
					tt1 = tekiou[j];
					tt2 = j;
				}
			}
			//順位による遺伝子・適応度の場所変更
			for (k = 0; k < 10; k++) {
				change = g[i][k];
				g[i][k] = g[tt2][k];
				g[tt2][k] = change;
			}
			change = tekiou[i];
			tekiou[i] = tekiou[tt2];
			tekiou[tt2] = change;
		}

		//選択（下位10個　ルーレット選択）
		for (i = 10; i < 20; i++) {

			/**********未実装**********/

		}
		//交叉（１点交叉　中央 エリート5ペア分　ルーレット5ペア分）
		for (i = 0; i < 20; i+2) {
			for (j = 5; j < 10; j++) {
				change = g[i][j];
				g[i][j] = g[i+1][j+1];
				g[i+1][j+1] = change;
			}
		}
		//突然変異（5％、10桁の内の1桁だけ変異）
		for (i = 0; i < 20; i++) {
			if (rand() % 100 < 5) {
				random = rand() % 10;
				g[i][random] = 1 - g[i][random];
			}
		}
	/*******************************************************/
	}
	//遺伝子コード　表示
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}
