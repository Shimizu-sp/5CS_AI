#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

main() {

	int a;
	int i;
	char str1[256];		//格納
	char str2[] = "オウム";
	char str3[] = "特技";
	char str4[] = "呼吸する";
	char str5[] = "鳥";
	char str6[] = "生物";

	printf("文字の入力 => ");
	gets(str1);		//文字列の入力

	printf("isa関係は1、hasa関係は2 => ");
	scanf("%d", &i);	//判定


	if (strstr(str1, str2) != NULL) {	//オウムが入力されていればaに1を代入
		a = 1;
	}if (strstr(str1, str5) != NULL) {	//鳥が入力されていればaに2を代入
		a = 2;
	}if (strstr(str1, str6) != NULL) {	//生物が入力されていればaに3を代入
		a = 3;
	
	}

	if (i == 2) {
		if (strstr(str1, str2) != NULL) {

			if (strstr(str1, str3) != NULL) {
				printf("モノマネ\n");
			}
		}
	}
	if(i == 1){
		if (strstr(str1, str2) != NULL && (str1, str4) != NULL) {
			printf("YES\n");
		}
		switch (a){
			break;
		case 1:
			printf("isa関係は\n%s\n↓\n%s\n↓\n%s\n", str6, str5, str2);
			break;
		case 2:
			printf("isa関係は\n%s\n↓\n%s\n", str6, str5);
			break;
		case 3:
			printf("isa関係は\n%s\n", str6);
			break;
		default:
			printf("ERROR\n");
			break;
		}
	}

	return 0;
}
