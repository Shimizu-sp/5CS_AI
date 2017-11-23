#include<stdio.h>
#include<stdlib.h>


void byoga(int num[12]){
	int i;
	//WMの状態を描画
	for (i = 0; i < 12; i++){

		if (num[i] == 1){
			printf("g");
		}
		else if (num[i] == 2){
			printf("f");
		}
		else if (num[i] == 3){
			printf("e");
		}
		else if (num[i] == 4){
			printf("d");
		}
		else if (num[i] == 5){
			printf("c");
		}
		else if (num[i] == 6){
			printf("b");
		}
		else if (num[i] == 7){
			printf("a");
		}
		else if (num[i] == 8){
			printf("+");
		}
		else if (num[i] == 9){
			printf("-");
		}
		else if (num[i] == 10){
			printf("*");
		}
		else if (num[i] == 11){
			printf("/");
		}
		else{
			printf("\n");
		}
	}
}

void babble(int num[12] ,int n){
	int i,j,save;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (num[j - 1] > num[j]) { //バブルソート
				save = num[j];        
				num[j] = num[j - 1];
				num[j - 1] = save;
				byoga(num);
			}
			
		}
	}
}
int main(void){
	//	{ "a*b-cd/e+fg"}
	//	{ "gfedcba+-*/" }

	int num[12] = { 7, 10, 6, 9, 5, 4, 11, 3, 8, 2, 1 };//初期状態
	int goal[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };//ゴール状態

	int i = 0, j = 0, n = 0;;
	int point = 0;

	//int num[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	byoga(num);
	while (1){

		babble(num, 11);
		for (i = 0; i < 12; i++){//ゴール状態と同じかどうかを判定
			if (num[i] == goal[i]){
				point++;
			}
		}
		if (point == 12){
			break;
		}
		else{
			point = 0;
		}
	}
	getchar();
}

//ルール1　gが配列の1番目でないならば左の要素と交換をする
//ルール2　fが配列の2番目でないならば左の要素と交換をする
//ルール3　dが配列の3番目でないならば左の要素と交換をする
//ルール4　cが配列の4番目でないならば左の要素と交換をする
//ルール5　bが配列の5番目でないならば左の要素と交換をする
//ルール6　aが配列の6番目でないならば左の要素と交換をする
//ルール7　+が配列の7番目でないならば左の要素と交換をする
//ルール8　-が配列の8番目でないならば左の要素と交換をする
//ルール9　*が配列の9番目でないならば左の要素と交換をする