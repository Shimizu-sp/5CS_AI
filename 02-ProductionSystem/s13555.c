#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>

main(){
	// a*b-cd/e+fg     gfedcba+-*/
	int i, j;
    char moji[] = "a*b-cd/e+fg";

	char change;


	printf("初期状態は:");
	for (i = 0; i < 11; i++){
		printf(" %c", moji[i]);
	}
	printf("\n\n");

	printf("ルール1 : 記号の右隣に文字は来ない。\n");
	for (j = 0; j < 10; j++){                     //ルール1 : 記号の右隣に文字は来ない。
		for (i = 0; i < 10; i++){
			if (ispunct(moji[i]) != 0) {
				if (isalnum(moji[i + 1])){
					change = moji[i];
					moji[i] = moji[i + 1];
					moji[i + 1] = change;
				}
			}
		  
		}
		for (i = 0; i < 11; i++){
			printf("%c", moji[i]);
		}
	  printf("\n");
	}
	printf("\n");
	change = "";


	printf("ルール2 :aの右隣は記号である。\n");
	for (j = 0; j < 10; j++){                     //ルール2 :aの右隣は記号である。
		for (i = 0; i < 10; i++){
			if (moji[i] == 97){
				if (isalnum(moji[i + 1]) == 2){
					change = moji[i];
					moji[i] = moji[i + 1];
					moji[i + 1] = change;
				}
			}
		}
		for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
		}
		printf("\n");
	}
	printf("\n");


	printf("ルール3 :bの右隣はaである。\n");
		for (j = 0; j < 10; j++){                     //ルール3 :bの右隣はaである。
			for (i = 0; i < 10; i++){
				if (moji[i] == 98){
					if (moji[i + 1] != 97){
						change = moji[i];
						moji[i] = moji[i + 1];
						moji[i + 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
			printf("%c", moji[i]);
		}
			printf("\n");
		}
		printf("\n");


		printf("ルール4 :cの右隣はbである。\n");
		for (j = 0; j < 10; j++){                     //ルール4 :cの右隣はbである。
			for (i = 0; i < 10; i++){
				if (moji[i] == 99){
					if (moji[i + 1] != 98){
						change = moji[i];
						moji[i] = moji[i + 1];
						moji[i + 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");


		printf("ルール5 :dの右隣はcである。\n");
		for (j = 0; j < 10; j++){                     //ルール5 :dの右隣はcである。
			for (i = 0; i < 10; i++){
				if (moji[i] == 100){
					if (moji[i + 1] != 99){
						change = moji[i];
						moji[i] = moji[i + 1];
						moji[i + 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");


		printf("ルール6 :eの右隣はdである。\n");
		for (j = 0; j < 10; j++){                     //ルール6 :eの右隣はdである。
			for (i = 0; i < 10; i++){
				if (moji[i] == 101){
					if (moji[i + 1] != 100){
						change = moji[i];
						moji[i] = moji[i + 1];
						moji[i + 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");


		printf("ルール7 :fの右隣はeである。\n");
		for (j = 0; j < 10; j++){                     //ルール7 :fの右隣はeである。
			for (i = 0; i < 10; i++){
				if (moji[i] == 102){
					if (moji[i + 1] != 101){
						change = moji[i];
						moji[i] = moji[i + 1];
						moji[i + 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");


		printf("ルール8 : + の左隣は a である。\n");
		for (j = 0; j < 11; j++){                     //ルール8 : + の左隣は a である。
			for (i = 0; i < 11; i++){
				if (moji[i] == 43){
					if (moji[i - 1] != 97){
						change = moji[i];
						moji[i] = moji[i - 1];
						moji[i - 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");


		printf("ルール9 : - の左隣は + である。\n");
		for (j = 0; j < 11; j++){                     //ルール9 : - の左隣は + である。
			for (i = 0; i < 11; i++){
				if (moji[i] == 45){
					if (moji[i - 1] != 43){
						change = moji[i];
						moji[i] = moji[i - 1];
						moji[i - 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");




		printf("\n");
	}
