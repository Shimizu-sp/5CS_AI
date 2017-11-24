#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	char s[100];
	int flug = 0;

	while (flug != 1){

		//
		char seibutu[100] = {"生物"};
		char tori[100] = { "鳥" };
		char oumu[100] = { "オーム" };
		char kokyuu[100] = {"呼吸"};
		char tubasa[100] = { "翼" };
		char monomane[100] = { "モノマネ" };
		char nai[100] = { "ない" };
		char oumutokugi[100] = { "オームの特技は何ですか" };
		//
		
		//1は生物,2は鳥,3はオーム
		memset(s, 0, sizeof(s));
		scanf("%99s", s);
		if (strcmp(s, oumutokugi)==0){
			printf("A.モノマネ\n");
			flug = 0;
			getchar();
		}
		else if (strstr(s, nai)){
			printf("A.無効\n");
		}
		else if (strstr(s, oumu)){
			if (strstr(s, monomane)){
				printf("オームの特徴に存在する\n");
				printf("A.Yes\n");
			}
			else if (strstr(s, tubasa)){
				printf("オームの特徴に存在しない\n");
				printf("鳥の特徴に存在する\n");
				printf("A.Yes\n");
			}
			else if (strstr(s, kokyuu)){
				printf("オームの特徴に存在しない\n");
				printf("鳥の特徴に存在しない\n");
				printf("生物の特徴に存在する\n");
				printf("A.Yes\n");
			}
			else{
				printf("A.無効\n");
			}
		}
		else if (strstr(s, tori)){
			if (strstr(s, tubasa)){
				printf("鳥の特徴に存在する\n");
				printf("A.Yes\n");
			}
			else if (strstr(s, kokyuu)){
				printf("鳥の特徴に存在しない\n");
				printf("生物の特徴に存在する\n");
				printf("A.Yes\n");
			}
			else{
				printf("A.無効\n");
			}
		}
		else if (strstr(s,seibutu)){
			if (strstr(s, kokyuu)){
				printf("生物の特徴に存在する\n");
				printf("A.Yes\n");
			}
			else{
				printf("A.無効\n");
			}
		}
		else{
			printf("A.無効\n");
		}
		getchar();
	}
}