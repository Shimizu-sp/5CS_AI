#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

main() {

	int a;
	int i;
	char str1[256];		//�i�[
	char str2[] = "�I�E��";
	char str3[] = "���Z";
	char str4[] = "�ċz����";
	char str5[] = "��";
	char str6[] = "����";

	printf("�����̓��� => ");
	gets(str1);		//������̓���

	printf("isa�֌W��1�Ahasa�֌W��2 => ");
	scanf("%d", &i);	//����


	if (strstr(str1, str2) != NULL) {	//�I�E�������͂���Ă����a��1����
		a = 1;
	}if (strstr(str1, str5) != NULL) {	//�������͂���Ă����a��2����
		a = 2;
	}if (strstr(str1, str6) != NULL) {	//���������͂���Ă����a��3����
		a = 3;
	
	}

	if (i == 2) {
		if (strstr(str1, str2) != NULL) {

			if (strstr(str1, str3) != NULL) {
				printf("���m�}�l\n");
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
			printf("isa�֌W��\n%s\n��\n%s\n��\n%s\n", str6, str5, str2);
			break;
		case 2:
			printf("isa�֌W��\n%s\n��\n%s\n", str6, str5);
			break;
		case 3:
			printf("isa�֌W��\n%s\n", str6);
			break;
		default:
			printf("ERROR\n");
			break;
		}
	}

	return 0;
}
