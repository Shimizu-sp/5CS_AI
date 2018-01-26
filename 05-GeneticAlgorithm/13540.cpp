#define _USE_MATH_DEFINES
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

double Compatible(double x) { //適合度計算用　戻り値:適合度
	if (x > 15 || x < -10) {
		return -1000; //指定範囲外の数値
	}

	double fx;
	fx = sin((M_PI*x) / 7)*((4 * log(x + 15)) / x + 15) + (0.35*sqrt(x + 8.5)); //関数部分
	if (isnan(fx)) {
		fx = -1000; //nan判定の数値
	}

	return fx;
}

int main(void){
	char DNA[20][10];//0or1で構成される10桁の配列が20個
	double Points[20]; //各遺伝子ごとの適合度を格納
	
	int r1, r2; //ランダムな変数を入れる

	double maxPoint = -1000; //関数の最大値
	char maxDNA[20]; //関数の値が最大となる遺伝子

	int i, j, k;

	double x; //遺伝子を変換した値を格納


	//初期の遺伝子を作成
	for (i = 0; i < 20; i++){
		for (j = 0; j < 10; j++){
			DNA[i][j] = rand() % 2+48;
			//printf("%c", DNA[i][j]);
		}
		//printf("\n");
	}
	//printf("\n");

	//ここから500世代分のループ
	for (int i = 0; i < 500; i++){

	//1点交叉
	for (j = 0; j < 10; j++){
		for (k = 0; k < 5; k++){
			swap(DNA[2*j][k],DNA[2*j+1][k]);
		}
	}

	//適合度計算
	for (j = 0; j < 20; j++){
		x = 0;
		for (k = 1; k < 10; k++){
			x += (DNA[j][k]-48)* pow(2, -k + 4); //遺伝子(0 or 1)*2^(-k+4)
		}
		if (DNA[j][0] == 49)x *= -1;

		Points[j] = Compatible(x); //適合度計算

		if (Points[j] > maxPoint) { //最大値と比べる
			maxPoint = Points[j];
			for (k = 0;k < 20;k++) {
				maxDNA[k] = DNA[j][k];
			}
		}
	}

	//適合度が高い順に並べ替え
	for (j = 0; j<20; ++j) {
		for (k = j + 1; k<20; ++k) {
			if (Points[j] < Points[k]) {
				swap(Points[j], Points[k]);
				swap(DNA[j], DNA[k]);
			}
		}
	}

	//ルーレット部分未完成

	/*　突然変異
	rand()%20に対応する遺伝子の
	rand()%10に対応する部分の値を入れ替え
	*/
	if (i < 499) {
		r1 = rand() % 20;
		r2 = rand() % 10;

		if (DNA[r1][r2] == 49)DNA[r1][r2] = 48;
		else if (DNA[r1][r2] == 48)DNA[r1][r2] = 49;
		}

	}//遺伝的アルゴリズムここまで
	
	printf("500世代目\n");
	x = 0;
	for (j = 1; j < 10; j++) {
		x += (DNA[0][j] - 48)* pow(2, -j + 4);
	}
	if (DNA[0][0] == 49)x *= -1;
	printf("最大の遺伝子 %f\n", x);
	printf("最大値 %f\n\n", Compatible(x));


	printf("アルゴリズム全体\n");
	x = 0;
	for (j = 1; j < 10; j++) {
		x += (maxDNA[j] - 48)* pow(2, -j + 4);
	}
	if (maxDNA[0] == 49)x *= -1;
	printf("最大の遺伝子 %f\n",x);
	printf("最大値 %f\n", maxPoint);
}