//出来たこと　初期生成
//            2進変換

#include<stdio.h>
#include <stdlib.h> 
#include<time.h>

#define MIN -10.0
#define MAX 

int Fitness_GA();  //適応度評価関数
int Choice_GA();   //選択関数
int Crossing_GA(); //交叉関数
int Mutation_GA(); //突然変異関数

int parent1[20], parent2[20], parent3[20], parent4[20], parent5[20], parent6[20], parent7[20], parent8[20], parent9[20], parent10[20];
int parent11[20], parent12[20], parent13[20], parent14[20], parent15[20], parent16[20], parent17[20], parent18[20], parent19[20], parent20[20];

main(){

	int i, j, kiroku;
	double binary[100]; //2進数用
	int random1; //整数保存用
	double random2; //小数点以下保存用

	//初期生成
	srand(time(NULL)); // 現在時刻を乱数の種の設定

	for (i = 0; i < 10; i++){

		random1 = -10 + rand() % (15 - -10); // -10〜15の範囲の乱数を生成
		random2 = (double)rand() / RAND_MAX; //小数点以下の数値を加算

		printf("%f\n", random1 + random2);

	}

	//============2進数に変換(整数部)==========================
	int test = 10; //テスト用
	int onetime_keep[10];
	int nisin[10]; //テスト用

	i = 0; //初期化
	while (test != 0){ //割りきれるまで
		onetime_keep[i] = test % 2; //2で割ったときの余りを保存
		test = test / 2; //2で割る
		i++;
	}

	kiroku = 0;
	for (j = i-1; j >= 0;j--){
		nisin[kiroku] = onetime_keep[j];
		kiroku++;
	}
	//==========================================================


	//============2進数に変換(小数部)==========================
	double testtest = 0.125;
	int ninsinnisin[10];
	
	i = 0;
	while (testtest != 1.0){
		ninsinnisin[i] = testtest * 2;
		testtest = testtest * 2;
		i++;
	}
	//==========================================================


	//============2の補数変換===================================
	int testtesttest = -18;
	int nisinnisinnisin[10];

	if (testtesttest < 0){ //負の値であるとき

		testtesttest = abs(testtesttest); //絶対値に直す

		i = 0; //初期化
		while (testtesttest != 0){ //割りきれるまで
		    onetime_keep[i] = testtesttest % 2; //2で割ったときの余りを保存
			testtesttest = testtesttest / 2; //2で割る
			i++;
		}

		kiroku = 0;
		for (i = 0; j >= 0; j--){ //2の補数（反転）

			if (onetime_keep[j] == 0){
				nisinnisinnisin[kiroku] = 1;

			}else if (onetime_keep[j] == 1){
				nisinnisinnisin[kiroku] = 0;
			}
			kiroku++;
		}

		for (j = i - 1; j >= 0;j--){

			if (nisinnisinnisin[j] == 1){
				nisinnisinnisin[j] = 0;
			
			}else if (nisinnisinnisin[j] == 0){
				nisinnisinnisin[j] = 1;
				j = -1;
			}
			j--;
		}
	}

	for (i = 0; i < 5; i++){
		printf(" %d \n", nisinnisinnisin[i]);
	}

	//==========================================================
	

}



Fitness_GA(){


}

Choice_GA(){


}

Crossing_GA(){


}

Mutation_GA(){


}
