#include<stdio.h>
#include <time.h>
#include <stdlib.h>

main(){
	//※※※※※配列の0と1から整数への変換方法がわからないので、今回は目標を関数の最大値の評価ではなく配列とする※※※※

	//for用
	int i,j;
	//遺伝子となる10ケタの配列を20個用意する
	int Ko[20][10];
	//目標の配列
	int Oya[10];
	//選択時の配列と＋＋用
	int sentaku[20][10] = { 0 };
	int p = 0;
	//ごみ
	//500ループ用
	int w = 0;
	//適応度評価用
	int sa[20] = { 0 };
	//エリート選択一時格納用
	int eri[10][10] = { 0 };
	srand((unsigned)time(NULL));
	//for (i = 0; i<100; i++){ printf("%d\n", rand()); }
	printf("今回、OyaとKoの配列の値を遺伝的アルゴリズムで評価します。\nOyaの値は");

	//最初のみ配列に乱数で1と0をいれる
	for (i = 0; i < 10; i++){Ko[0][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[1][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[2][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[3][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[4][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[5][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[6][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[7][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[8][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[9][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[10][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[11][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[12][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[13][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[14][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[15][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[16][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[17][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[18][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Ko[19][i] = rand() % 2;}
	for (i = 0; i < 10; i++){Oya[i] = rand() % 2;}

	for (i = 0; i < 10; i++){ printf("[%d]", Oya[i]); }
	printf("です\n");
	//500世代なので500ループ
	while (w < 1){
		w++;
		//適応度評価
		//OyaとKoの、iのときの配列の値があっていればsaを加算。10のときに終了
		for (j = 0; j < 20; j++){
			for (i = 0; i < 10; i++){ 
				if (Ko[j][i] == Oya[i]){
					sa[j]++; 
				}
			}
			if (sa[j] == 10){
				printf("Ko%dがOyaと完全に一致しました\n",j);
				for (i = 0; i < 10; i++){ printf("[%d]", Ko[j][i]); }
				break;
			}
		}
		//Koのsaが高い順に、sentaku配列のNoが高いところにいれる
		for (j = 0; j < 20; j++){if(sa[j] == 9){for (i = 0; i < 10; i++){sentaku[p][i] = Ko[j][i];}printf("9だよ\n");p++;}}
		for (j = 0; j < 20; j++){if(sa[j] == 8){for (i = 0; i < 10; i++){sentaku[p][i] = Ko[j][i];}p++;printf("8だよ\n");}}
		for (j = 0; j < 20; j++){if(sa[j] == 7){for (i = 0; i < 10; i++){sentaku[p][i] = Ko[j][i];}p++;printf("7だよ\n");}}
		for (j = 0; j < 20; j++){if(sa[j] == 6){for (i = 0; i < 10; i++){sentaku[p][i] = Ko[j][i];}p++;printf("6だよ\n");}}
		for (j = 0; j < 20; j++){if(sa[j] == 5){for (i = 0; i < 10; i++){sentaku[p][i] = Ko[j][i];}p++;printf("5だよ\n");}}
		for (j = 0; j < 20; j++){if(sa[j] == 4){for (i = 0; i < 10; i++){sentaku[p][i] = Ko[j][i];}p++;printf("4だよ\n");}}
		for (j = 0; j < 20; j++){if(sa[j] == 3){for (i = 0; i < 10; i++){sentaku[p][i] = Ko[j][i];}p++;printf("3だよ\n");}}
		for (j = 0; j < 20; j++){if(sa[j] == 2){for (i = 0; i < 10; i++){sentaku[p][i] = Ko[j][i];}p++;printf("2だよ\n");}}
		for (j = 0; j < 20; j++){if(sa[j] == 1){for (i = 0; i < 10; i++){sentaku[p][i] = Ko[j][i];}p++;printf("1だよ\n");}}
		for (j = 0; j < 20; j++){if(sa[j] == 0){for (i = 0; i < 10; i++){sentaku[p][i] = Ko[j][i];}p++;printf("0だよ\n");}}
		//適用度評価終了

		//sentaku0~9までエリート選択と一点交差
		for (i = 5; i < 10; i++){
			sentaku[0][i] = eri[0][i];
			sentaku[0][i] = sentaku[1][i];
			sentaku[1][i] = eri[0][i];

			sentaku[2][i] = eri[1][i];
			sentaku[2][i] = sentaku[3][i];
			sentaku[3][i] = eri[1][i];

			sentaku[4][i] = eri[2][i];
			sentaku[4][i] = sentaku[5][i];
			sentaku[5][i] = eri[2][i];

			sentaku[6][i] = eri[3][i];
			sentaku[6][i] = sentaku[7][i];
			sentaku[7][i] = eri[3][i];

			sentaku[8][i] = eri[4][i];
			sentaku[8][i] = sentaku[9][i];
			sentaku[9][i] = eri[4][i];
			

		}
		

		//sentaku10~19までルーレット選択

		//突然変異(乱数でその乱数の番号の配列の1桁を入れ替え)

		for (j = 0; j < 20; j++){
			sa[j] = 0;
		}
	}

	
}