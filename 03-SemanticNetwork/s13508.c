#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void) {
	char test[100];
	char *a,*b;

	scanf("%s", test);	//質問入力
	
	a = _mbsstr(test, "オーム");	//オームという単語があるか文字列を検索し、無ければNULLを返す
	if (a != NULL) {

		b = _mbsstr(test, "特技");	//特技という単語があるか文字列を検索し、無ければNULLを返す
		
		if (b != NULL) {	//NULLがこなければモノマネと答える
			printf("モノマネ\n");
		}
		else {	//NULLであれば上位概念へ

			a = _mbsstr(test, "翼がある");	//翼があるという単語があるか文字列を検索し、無ければNULLを返す

			if (a != NULL) {	//NULLがこなければYesと答え、プロセスを出力する
				printf("\n鳥→翼がある\n↑\nオーム\n");
				printf("\nYes\n");
			}
			else {	//NULLであれば上位概念へ

				a = _mbsstr(test, "呼吸");	//呼吸という単語があるか文字列を検索し、無ければNULLを返す

				if (a != NULL) {	//NULLがこなければYesと答え、プロセスを出力する
					printf("\n生物→呼吸をする\n↑\n鳥\n↑\nオーム\n");
					printf("\nYes\n");
				}

			}
		}
	}
}