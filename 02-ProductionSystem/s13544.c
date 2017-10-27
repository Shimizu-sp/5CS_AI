#include<stdio.h>
#include<string.h>

void is();
void r1();
void r2();
void r3();
void r4();
void fs();

char WM[][11] = { "a", "*", "b", "-", "c", "d", "/", "e", "+", "f", "g" };
char goal[][11] = { "g", "f", "e", "d", "c", "b", "a", "+", "-", "*", "/" };
int checker = 0;//相違数
int i, j, n;//カウンタ
char change;//入れ替え時一時保持用変数
int ck;//ループ条件用チェッカー変数

int cc_1, cc_2;

int main(){
	is();//初期状態表示
	r1();//ルール1：記号は右へ　適用
	r2();//ルール2:WM[0][0]～WM[6][0]までは，文字コードの値が大きい順にする　適用
	r3();//ルール3:WM[7][0]～[8][0]までを文字コードの小さい順にする　適用
	r4();//ルール4:*はWM[9][0]に入るまで右隣と交換しなければならない　適用
	fs();//最終状態表示
}

void is(){
	printf("---初期状態------------------------------------------\n");

	//WMとゴール状態の比較
	for (i = 0; i < 11; i++){
		if (WM[i][0] != goal[i][0]){
			printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
			checker++;
		}
	}
	printf("\n相違数：%d\n\n", checker);
}

void r1(){
	//ルール1:記号は右へ
	checker = 0;
	i = 0;
	ck = 0;
	printf("---ルール1適用----------------------------------------\n");
	while (ck != 5){
		if ('+' == WM[i][0] || '-' == WM[i][0] || '*' == WM[i][0] || '/' == WM[i][0]){
			if ('a' == WM[i + 1][0] || 'b' == WM[i + 1][0] || 'c' == WM[i + 1][0] || 'd' == WM[i + 1][0] || 'e' == WM[i + 1][0] || 'f' == WM[i + 1][0] || 'g' == WM[i + 1][0]){
				change = WM[i][0];
				WM[i][0] = WM[i + 1][0];
				WM[i + 1][0] = change;
			}
		}
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);

		if ('+' == WM[7][0] || '-' == WM[7][0] || '*' == WM[7][0] || '/' == WM[7][0]){
			if ('+' == WM[8][0] || '-' == WM[8][0] || '*' == WM[8][0] || '/' == WM[8][0]){
				if ('+' == WM[9][0] || '-' == WM[9][0] || '*' == WM[9][0] || '/' == WM[9][0]){
					if ('+' == WM[10][0] || '-' == WM[10][0] || '*' == WM[10][0] || '/' == WM[10][0]){
						ck++;
					}
				}
			}
		}
		i++;
		if (i == 11){
			i = 0;
			if (ck != 5){
				printf("---ルール1適用----------------------------------------\n");
			}
		}
	}

	printf("---ルール1終了----------------------------------------\n");

	for (i = 0; i < 11; i++){
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
		if (WM[i][0] != goal[i][0]){
			checker++;
		}
	}
	printf("\n相違数：%d\n", checker);
}

void r2(){
	//ルール2:WM[0][0]～WM[6][0]までは，文字コードの値が大きい順にする
	i = 0;
	checker = 0;
	printf("---ルール2適用----------------------------------------\n");
	while (1){
		cc_1 = WM[i][0];
		cc_2 = WM[i + 1][0];
		if (cc_1 < cc_2){
			change = WM[i][0];
			WM[i][0] = WM[i + 1][0];
			WM[i + 1][0] = change;
		}
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);

		i++;
		if (i == 11){
			checker = 0;
			for (j = 0; j < 11; j++){
				if (WM[j][0] != goal[j][0]){
					checker++;
				}
			}
			if (checker <= 4){
				break;
			}
			i = 0;
			printf("---ルール2適用----------------------------------------\n");
		}
	}

	printf("---ルール2終了----------------------------------------\n");
	checker = 0;

	for (i = 0; i < 11; i++){
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
		if (WM[i][0] != goal[i][0]){
			checker++;
		}
	}
	printf("\n相違数%d\n", checker);
}

void r3(){
	//ルール3:WM[7][0]～[8][0]までを文字コードの小さい順にする
	i = 7;
	checker = -1;
	printf("---ルール3適用----------------------------------------\n");
	while (1){
		if (i == 7){
			for (j = 0; j<7; j++){
				printf("WM:%c goal:%c\n", WM[j][0], goal[j][0]);
			}
		}

		cc_1 = WM[i][0];
		cc_2 = WM[i + 1][0];
		if (cc_1 > cc_2){
			if (i != 10){
				change = WM[i][0];
				WM[i][0] = WM[i + 1][0];
				WM[i + 1][0] = change;
			}
		}
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);

		i++;
		if (i == 11){
			checker = 0;
			for (j = 0; j < 11; j++){
				if (WM[j][0] != goal[j][0]){
					checker++;
				}
			}
			if ('*' == WM[7][0] && '+' == WM[8][0] && '-' == WM[9][0] && '/' == WM[10][0]){
				break;
			}
			i = 7;
			printf("---ルール3適用----------------------------------------\n");
		}
	}

	printf("---ルール3終了----------------------------------------\n");
	checker = 0;

	for (i = 0; i < 11; i++){
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
		if (WM[i][0] != goal[i][0]){
			checker++;
		}
	}
	printf("\n相違数：%d\n", checker);
}

void r4(){
	//ルール4:*はWM[9][0]に入るまで右隣と交換しなければならない
	checker = 0;
	i = 0;
	printf("---ルール4適用----------------------------------------\n");
	while (1){
		if ('*' == WM[i][0]){
			break;
		}
		i++;
	}

	n = i;

	while (1){
		if (i <= n){
			for (j = 0; j<7; j++){
				printf("WM:%c goal:%c\n", WM[j][0], goal[j][0]);
			}
		}
		change = WM[i][0];
		WM[i][0] = WM[i + 1][0];
		WM[i + 1][0] = change;

		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);

		if ('*' == WM[9][0]){
			for (i = 9; i < 11; i++){
				printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
			}
			break;
		}
		if (i == 11){
			i = n;
		}
		i++;
	}

	printf("---ルール4終了----------------------------------------\n");
	checker = 0;

	for (i = 0; i < 11; i++){
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
		if (WM[i][0] != goal[i][0]){
			checker++;
		}
	}
	printf("\n相違数：%d\n", checker);
}

void fs(){
	printf("---最終結果------------------------------------------\n");
	for (i = 0; i < 11; i++){
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
		if (WM[i][0] != goal[i][0]){
			checker++;
		}
	}
	printf("\n相違数：%d\n", checker);
}