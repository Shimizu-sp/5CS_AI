#include <stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include <random>
using namespace std;

double c[20] = {}, eli[10] = {}, roul[10] = {};
int iden[20] = {}, binary_eli[10] = {}, binary_roul[10] = {};
int r1 = 0, r2 = 0;
int ransu_kekka;

int ransu(int r2);
double fx(double x);

int main() {

	int idenshi_i;
	int s;
	double tekigou, idenshi_d;
	double save;

	/*20個体生成*/
	for (int i = 0; i < 20; i++) { 
		idenshi_i = ransu(r1); /*ransu関数に飛ぶ*/
		idenshi_d = idenshi_i; /*int型とdouble型に分ける*/
		/*遺伝子(10進数)それぞれ20個を保存*/
		iden[i] = idenshi_i;

		tekigou = fx(idenshi_d); /*func関数に飛ぶ*/

		/*小数点第2位まで求める*/
		for (s = 0; s < 3 - 1; s++) { /*小数点を右に動かす*/
			tekigou *= 10; /*2回10倍する*/
		}
		tekigou += 0.5; /*0.5を足す*/
		tekigou = (int)tekigou; /*小数点以下切り捨て*/
		for (s = 0; s < 3 - 1; s++) {/*少数点を左に動かす*/
			tekigou /= 10;/*2回10で割る*/
			
		}

		c[i] = tekigou; /*配列cのi番目に適合値を代入*/

		printf("乱数値：%d    適合値：%f\n", iden[i], c[i]);
	}

}

int ransu(int r2) {/*乱数を作る関数*/

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dice(-10, 15);

	ransu_kekka = dice(mt); /*乱数の結果を代入*/

	return ransu_kekka;/*mainに戻る*/

}

double fx(double x) {/*f(x)の計算をする関数*/

	double ans2 = 0.0, ans3 = 0.0;
	double s = (M_PI * x) / 7.0;
	double l = x + 15.0;
	double sq = x + 8.5;

	//printf("　x：%f\n", x);
	ans2 = sin(s) * ((4.0 * log(l)) / (x + 15.0)) + (0.35 * sqrt(sq)); /*f(x)の計算をする式*/
	ans3 = fabs(ans2); /*ans2の値の絶対値*/
	//printf("　適合度：%f\n\n", ans3);

	return ans3;

}
