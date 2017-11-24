#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

int main(void){
	char main[3][2][500] = { { "生物", "呼吸する", },
							{"鳥", "翼がある"},
							{"オーム", "モノマネ"} };
	char name[2][500] = { "属性", "特技" };

	char a[500];
	int j,main_nomber=0,chara_nomber=0,answer=0;

	printf("質問を入力せよ\n");
	scanf("%s",a);

	//****************************************************************//
	//概念の摘出
	for (j = 0; j <= 2;j++){
		if (strstr(a, main[j][0]) != NULL){
			main_nomber = j;
			printf("「%s」確認\n", main[j][0]);
			break;
		}
	}
	//****************************************************************//
	//質問内容の摘出
	for (j = 0; j <= 2; j++){
		if (strstr(a, main[j][1]) != NULL){
			chara_nomber = j + 1;
			printf("「%s」確認\n", main[j][1]);
			break;
		}
	}
	for (j = 0; j <= 1; j++){
		if (strstr(a, name[j]) != NULL){
			chara_nomber = j + 11;
			printf("「%s」確認\n", name[j]);
			break;
		}
	}
	//****************************************************************//
	//推論
	j = main_nomber;
	//「概念」と「質問」が両方そろっているか確認
	if (main_nomber != 0 && chara_nomber != 0) {
		//「属性」か「特技」であれば属性を表示する
		if (chara_nomber >=10) {
			printf("%sの属性は「%s」\n",main[main_nomber][0],main[main_nomber][1]);		
		}
		//「呼吸」「翼」「モノマネ」であればis-aを行う
		else if (chara_nomber < 10) {
			while (j!=-1) {
				if (strstr(a, main[j][1]) != NULL) {
					printf("[%s] - [%s] 一致\n",main[j][0],main[j][1]);
					answer = 1;
					break;
				}
				printf("[%s] - [%s] 不一致\n", main[j][0], main[j][1]);
				j--;
			}
			//質問の結果
			if (answer==1) {
				printf("質問の回答　「Yes」\n");
			}
			else {
				printf("質問の回答　「No」\n");
			}
		}
	}
}
