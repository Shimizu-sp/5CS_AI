#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define _USE_MATH_DEFINES
#include<math.h>
#define N 20//個体数
#define L 10//遺伝子の長さ

main(){
	
	int juni[N+1] = { 0 };//適応度の順位番号を入れる関数
	int kari_juni = 0;//適応度順位番号入れ替え時に一時的に使用する関数
	int i, i2,i3,flag,go;//for文用
	int ransu=0;//乱数を仮入れ
	int ans[L] = { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0 };//Xの理論値（10桁2進数とした）
	float tekioudo[N] = { 0 };//適応度を入れる関数
	float test_tekioudo = 0;//適応度の仮入れ関数
	int heni1 = 0, heni2 = 0;//突然変異の位置を入れる関数
	double x = 0;//Xの値
	double X_ans = 0;//求まった最大値を入れる関数
	double x_all = 0;//500世代通しての最大値をもたらすxの値を入れる関数
	double X_all = 0;//500世代通しての最大値を入れる関数

	
	//遺伝子配列作成
	int idenshi[N][L] = {0};//遺伝子を入れる関数
	int kousa[L-5] = {0};//交叉を行う際に，遺伝子を仮入れする関数


	//500ループ開始
	for (go = 0; go < 500;go++) {

		//初期の遺伝子生成
		srand((unsigned)time(NULL));//乱数の設定

		for (i = 0; i < N; i++) {
			for (i2 = 0; i2 < L; i2++) {
				ransu = rand() % 10;
				if (ransu % 2 == 0) {
					idenshi[i][i2] = 0;
				}
				else {
					idenshi[i][i2] = 1;
				}
			}
		}

		//適応度評価
		//Xの理論値を40として行う
		//X=40→0000101000(10桁)
		test_tekioudo = 0;
		for (i = 0; i < N; i++) {
			for (i2 = 0; i2 < L; i2++) {
				if (ans[i2] == idenshi[i][i2]) { test_tekioudo++; }
				if (i2 == L - 1) {
					tekioudo[i] = test_tekioudo / 10;
				}
			}
			test_tekioudo = 0;
		}

		//順位決め
		for (i = 0; i < N; i++) {//順位の初期化
			juni[i] = -1;
		}

		for (i = 0; i < N; i++) {
			flag = 0;
			for (i2 = 0; i2 < N; i2++) {
				if (tekioudo[i] > tekioudo[juni[i2]] && flag == 0) {
					for (i3 = N; i3 > i2; i3--) {
						juni[i3] = juni[i3 - 1];
					}
					juni[i2] = i;
					flag = 1;
				}
				else if (tekioudo[i] < tekioudo[juni[i2]] && juni[i2] == -1 && flag == 0) {
					for (i3 = N; i3 > i2 + 2; i3--) {
						juni[i3] = juni[i3 - 1];
					}
					juni[i2] = i;
					flag = 1;
				}


			}
		}

		//エリート選択(今回は10位まで1位,2位、3位,4位、5位,6位、7位,8位、9位,10位というペアで選択し，交叉と行う)+交叉

		for (i = 0; i < L - 5; i++) {//1位,2位交叉
			idenshi[juni[0]][i] = kousa[i];
			idenshi[juni[0]][i] = idenshi[juni[1]][i];
			idenshi[juni[1]][i] = kousa[i];
		}

		for (i = 0; i < L - 5; i++) {//3位,4位交叉
			idenshi[juni[2]][i] = kousa[i];
			idenshi[juni[2]][i] = idenshi[juni[3]][i];
			idenshi[juni[3]][i] = kousa[i];
		}

		for (i = 0; i < L - 5; i++) {//5位,6位交叉
			idenshi[juni[4]][i] = kousa[i];
			idenshi[juni[4]][i] = idenshi[juni[6]][i];
			idenshi[juni[5]][i] = kousa[i];
		}

		for (i = 0; i < L - 5; i++) {//7位,8位交叉
			idenshi[juni[6]][i] = kousa[i];
			idenshi[juni[6]][i] = idenshi[juni[7]][i];
			idenshi[juni[7]][i] = kousa[i];
		}

		for (i = 0; i < L - 5; i++) {//9位,10位交叉
			idenshi[juni[8]][i] = kousa[i];
			idenshi[juni[8]][i] = idenshi[juni[9]][i];
			idenshi[juni[9]][i] = kousa[i];
		}
		//ルーレット選択+交叉




		//突然変異
		heni1 = rand() % 20;//どの遺伝子にするか
		heni2 = rand() % 10;//何桁目にするか

		//1桁分の数値を変更する
		if (idenshi[heni1][heni2] == 0) {
			idenshi[heni1][heni2] = 1;
		}
		else if (idenshi[heni1][heni2] == 1) {
			idenshi[heni1][heni2] = 0;
		}

		//突然変異後適応度評価
		//Xの理論値を40として行う
		//X=40→0000101000(10桁)
		test_tekioudo = 0;
		for (i = 0; i < N; i++) {
			for (i2 = 0; i2 < L; i2++) {
				if (ans[i2] == idenshi[i][i2]) { test_tekioudo++; }
				if (i2 == L - 1) {
					tekioudo[i] = test_tekioudo / 10;
				}
			}
			test_tekioudo = 0;
		}
		//順位決め
		for (i = 0; i < N; i++) {//順位の初期化
			juni[i] = -1;
		}

		for (i = 0; i < N; i++) {
			flag = 0;
			for (i2 = 0; i2 < N; i2++) {
				if (tekioudo[i] > tekioudo[juni[i2]] && flag == 0) {
					for (i3 = N; i3 > i2; i3--) {
						juni[i3] = juni[i3 - 1];
					}
					juni[i2] = i;
					flag = 1;
				}
				else if (tekioudo[i] < tekioudo[juni[i2]] && juni[i2] == -1 && flag == 0) {
					for (i3 = N; i3 > i2 + 2; i3--) {
						juni[i3] = juni[i3 - 1];
					}
					juni[i2] = i;
					flag = 1;
				}


			}
		}
		x = 0;
		//10進数に直す
		for (i = 0; i < L; i++) {
			x = x + idenshi[0][i] * pow(2, i);
		}
		x = x / 39.3461538462;
		x = ceil(x);//繰り上げ
		x = x - 10;//ｘの値とする
		X_ans = sin(x * M_PI / 2) * 4 * log(x + 15) / x + 15 + 0.35*sqrt(x + 8.5);//最大値の計算
		if ((X_ans-27.17)<=(X_all-27.17)||go==0){
			X_all = X_ans;
			x_all = x;
		}

	}


	x = 0;
	X_ans = 0;
	//10進数に直す
	for (i = 0; i < L;i++){
	x = x + idenshi[0][i] * pow(2,i);
	}
	x = x / 39.3461538462;
	x = ceil(x);//繰り上げ
	x = x - 10;//ｘの値とする
	X_ans = sin(x * M_PI / 2) * 4 * log(x + 15) / x + 15 + 0.35*sqrt(x + 8.5);//最大値の計算
	//結果表示
	printf("500世代実施後の最大値をもたらすxの値と最大値は以下の通りとなった\n");
	printf("xは%.0f xの最大値は%.2f\n",x,X_ans);
	printf("500世代全体を通しての最大値をもたらすxの値と最大値は以下の通りとなった\n");
	printf("xは%.0f xの最大値は%.2f\n", x_all, X_all);
	
		
}