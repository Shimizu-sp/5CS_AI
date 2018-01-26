#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void main() {
	int i, j, m;						//計算用のカウンター変数
	int counter;						//世代を表す変数
	int GetRandom(int min, int max);	//ランダムな値の範囲指定
	int sh[10];							//初期集団用の配列
	int rh[10];							//ランク選択で選択された配列を保存しておく配列
	int point;							//交叉の切断面を表す変数
	int irekae;							//交叉の入れ替え用変数
	double kt;							//交叉と突然変異で用いる変数
	int eh[10];							//エリート選択で選択された配列を保存しておく配列
	int en;								//エリート個体が個体群の中の何番目かを表す変数
	double elite;						//エリートを探すための変数
	
	//乱数生成//

	for (i = 0; i < 9; i++) {
		sh[i] = rand() % 26 - 10;		//乱数生成
	}

}