#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	char s[100];
	int flug = 0;

	while (flug != 1){

		//
		char seibutu[100] = {"����"};
		char tori[100] = { "��" };
		char oumu[100] = { "�I�[��" };
		char kokyuu[100] = {"�ċz"};
		char tubasa[100] = { "��" };
		char monomane[100] = { "���m�}�l" };
		char nai[100] = { "�Ȃ�" };
		char oumutokugi[100] = { "�I�[���̓��Z�͉��ł���" };
		//
		
		//1�͐���,2�͒�,3�̓I�[��
		memset(s, 0, sizeof(s));
		scanf("%99s", s);
		if (strcmp(s, oumutokugi)==0){
			printf("A.���m�}�l\n");
			flug = 0;
			getchar();
		}
		else if (strstr(s, nai)){
			printf("A.����\n");
		}
		else if (strstr(s, oumu)){
			if (strstr(s, monomane)){
				printf("�I�[���̓����ɑ��݂���\n");
				printf("A.Yes\n");
			}
			else if (strstr(s, tubasa)){
				printf("�I�[���̓����ɑ��݂��Ȃ�\n");
				printf("���̓����ɑ��݂���\n");
				printf("A.Yes\n");
			}
			else if (strstr(s, kokyuu)){
				printf("�I�[���̓����ɑ��݂��Ȃ�\n");
				printf("���̓����ɑ��݂��Ȃ�\n");
				printf("�����̓����ɑ��݂���\n");
				printf("A.Yes\n");
			}
			else{
				printf("A.����\n");
			}
		}
		else if (strstr(s, tori)){
			if (strstr(s, tubasa)){
				printf("���̓����ɑ��݂���\n");
				printf("A.Yes\n");
			}
			else if (strstr(s, kokyuu)){
				printf("���̓����ɑ��݂��Ȃ�\n");
				printf("�����̓����ɑ��݂���\n");
				printf("A.Yes\n");
			}
			else{
				printf("A.����\n");
			}
		}
		else if (strstr(s,seibutu)){
			if (strstr(s, kokyuu)){
				printf("�����̓����ɑ��݂���\n");
				printf("A.Yes\n");
			}
			else{
				printf("A.����\n");
			}
		}
		else{
			printf("A.����\n");
		}
		getchar();
	}
}