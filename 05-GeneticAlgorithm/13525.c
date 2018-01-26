#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
main() {

	int DNA_f[20][11] = { 0 };//配列10桁＊20個+1の数
	int DNA_ER[20][11] = { 0 };//値保管用配列

	int DNA_data[11] = { 0 };//一時保存

	int i = 0, j = 0, C = 0;//カウント

	int min = 0;//最少値
	int max = 0;//最大値
	int ru = 0;//ルーレット用


	srand(time(NULL));//初期の遺伝子の乱数生成
	for (i = 0; i < 20; i++) {
		for (j = 0; j < N; j++) {

			DNA_f[i][j] = rand() % 2;
			printf("%d,", DNA_f[i][j]);//確認用
		}
		printf("\n");
	}
	printf("\n");
	//back:
	//適応度評価(1はいくつあるか)1が10こあれば終了
	for (i = 0; i < 20; i++) {
		for (j = 0; j < N; j++) {
			if (DNA_f[i][j] == 1) {
				DNA_f[i][N] = DNA_f[i][N] + 1;//1の数を配列の一番最後に格納
			}
		}
		printf("1の数[%d]=%d\n", i + 1, DNA_f[i][10]);//確認用
	}
	//選択(エリート),1の数が多い順に20こから10こ選択
	//降順ソート
	for (i = 0; i < 20; i++) {
		if (DNA_f[i][N] <= DNA_f[i + 1][N] && i + 1 != 20) {//1の数がiよりi+1の方が多かったら
			for (j = 0; j < N; j++) {
				//　1.DNA_f[i+1][0]〜DNA_f[i+1][9]のなかみをDNA_data[0]〜DNA_data[9]に移す
				DNA_data[j] = DNA_f[i + 1][j];
				//　2.DNA_f[i+1][0]〜DNA_f[i+1][9]をDNA_f[i][0]〜DNA_f[i][9]に置き換える
				DNA_f[i + 1][j] = DNA_f[i][j];
				//　3.DNA_f[i][0]〜DNA_f[i][9]をDNA_data[0]〜DNA_data[9]に置き換える
				DNA_f[i][j] = DNA_data[j];
			}
		}
	}
	//上位10こを別配列に移す
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			DNA_ER[i][j] = DNA_f[i][j];
		}
	}

	//選択ルーレット,1の数を重みとして乱数選択する
	min = N;
	//1の数が一番多い値と小さい値を調べ範囲を決める
	for (i = 10; i < 20; i++) {
		if (DNA_f[i][N] >= max) {
			max = DNA_f[i][N];
		}
		if (DNA_f[i][N] <= min) {
			min = DNA_f[i][N];
		}
	}
	while (C != 10) {
		rand() % max + 1;//ルーレット
		for (i = 0; i < 20; i++) {
			if (DNA_f[i][N] == ru) {
				DNA_data[j] = DNA_f[i][N];
				C++;
			}
		}
	}
	//以下未完成
	//10こを別配列に移す
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			DNA_ER[i][j] = DNA_f[i][j];
		}
	}


	//



	//交叉


	//突然変異


	//backして評価を受ける
	//goto back;


}