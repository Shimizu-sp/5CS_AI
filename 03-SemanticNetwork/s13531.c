#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

int main(void){
	char main[3][2][500] = { { "����", "�ċz����", },
							{"��", "��������"},
							{"�I�[��", "���m�}�l"} };
	char name[2][500] = { "����", "���Z" };

	char a[500];
	int j,main_nomber=0,chara_nomber=0,answer=0;

	printf("�������͂���\n");
	scanf("%s",a);

	//****************************************************************//
	//�T�O�̓E�o
	for (j = 0; j <= 2;j++){
		if (strstr(a, main[j][0]) != NULL){
			main_nomber = j;
			printf("�u%s�v�m�F\n", main[j][0]);
			break;
		}
	}
	//****************************************************************//
	//������e�̓E�o
	for (j = 0; j <= 2; j++){
		if (strstr(a, main[j][1]) != NULL){
			chara_nomber = j + 1;
			printf("�u%s�v�m�F\n", main[j][1]);
			break;
		}
	}
	for (j = 0; j <= 1; j++){
		if (strstr(a, name[j]) != NULL){
			chara_nomber = j + 11;
			printf("�u%s�v�m�F\n", name[j]);
			break;
		}
	}
	//****************************************************************//
	//���_
	j = main_nomber;
	//�u�T�O�v�Ɓu����v������������Ă��邩�m�F
	if (main_nomber != 0 && chara_nomber != 0) {
		//�u�����v���u���Z�v�ł���Α�����\������
		if (chara_nomber >=10) {
			printf("%s�̑����́u%s�v\n",main[main_nomber][0],main[main_nomber][1]);		
		}
		//�u�ċz�v�u���v�u���m�}�l�v�ł����is-a���s��
		else if (chara_nomber < 10) {
			while (j!=-1) {
				if (strstr(a, main[j][1]) != NULL) {
					printf("[%s] - [%s] ��v\n",main[j][0],main[j][1]);
					answer = 1;
					break;
				}
				printf("[%s] - [%s] �s��v\n", main[j][0], main[j][1]);
				j--;
			}
			//����̌���
			if (answer==1) {
				printf("����̉񓚁@�uYes�v\n");
			}
			else {
				printf("����̉񓚁@�uNo�v\n");
			}
		}
	}
}
