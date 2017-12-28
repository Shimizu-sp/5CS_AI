#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>

class SEIBUTU{//生物に関する概念
public:
	int zokusei(int num1){
		
		int number = 1;//概念ごとに番号を設定しておく
		if (number == num1){
			printf("YES%d \n",num1);//生物は呼吸する
		}
		else{
			return 1;//解がない場合は1を返す
		}
	};
};

class TORI : public SEIBUTU{//生物の概念を引き継いでいる鳥に関する概念
public:
	int Zokusei(int num2){//生物の属性に関する関数
		int torinum = 0;
		int number = 2;

		if (torinum == num2){
			printf("羽がある\n");//鳥には羽があると
		}
		if (number == num2){
			printf("YES\n");
		}
		else{
			return 2;//解がない場合は2を返す
		}

	}
};

class OUMU : public TORI{//鳥の概念を引き継いでいるオームに関する概念
public:
	int tokugi(int num3){//オウムの特技に関する関数
		int oumunum = 0;
		int number = 3;
		if (oumunum == num3){
			printf("モノマネ \n");//オウムの特技はモノマネ
		}
		
		if (number == num3){
			printf("YES\n");
		}
		else{
			return 3; //解がない場合は3を返す
		}
	}
};


int main(){
	char query[30];
	int sp;
	int i;
	char *h, *j, *k, *l = 0;
	SEIBUTU seibutu;//継承関係を呼び出しておく
	TORI tori;
	OUMU oumu;
	//文字入力
	printf("文字を入力\n");
	scanf("%s", query);

	//質問の内部にオームが入っているか調べる
	j = strstr(query, "オーム");
	
	//入っている場合以下の処理を行う
	if (j != NULL){
		k = strstr(query, "特技");//質問内に特技が入っているか検索する
		l = strstr(query, "呼吸");//質問内に呼吸が入っているか検索する

		if (k != NULL){//特技が入っている場合、オウムの特技に関する意味ネットワークを参照する
			oumu.tokugi(0);
		}

		if (l != NULL){//呼吸が入っている場合、
			sp = 1;
			i=oumu.tokugi(sp);//オームの意味ネットワーク内を検索する
			if (i == 3){//解がない場合、上位概念(鳥)を検索する
				i = 0;
				printf("オウムの中には解がありません %d\n", i);
				i = tori.Zokusei(sp);

				if (i == 2){//鳥の中に解がない場合、上位概念（生物）を検索する
					i = 0;
					printf("鳥の中には解がありません %d\n", sp);
					i = seibutu.zokusei(sp);
					
					if (i == 1){//なかった場合は解なしとなる
						printf("解なし\n");
					}
				}
			}
		}
	}
}



