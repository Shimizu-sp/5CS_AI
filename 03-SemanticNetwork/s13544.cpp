#include<stdio.h>
#include<string.h>

#pragma warning(disable : 4996)

class creature{
public:
	int attribute(char *data_q){
		char data[] = "�ċz����";
		if (data_q == NULL){
			printf("answer:%s\n", data);
		}
		else{
			printf("��O�K�w�F");
			if (*data_q == *data){
				
				printf("YES\n");
				return 0;
			}
			else{
				printf("�s��\n");
				return 1;
			}
		}
	}
};

class bird :public creature{
public:
	int Attribute(char *data_q){
		char data[] = "��������";
		if (data_q == NULL){
			printf("answer:%s\n", data);
		}
		else{
			printf("���K�w�F");
			if (*data_q == *data){
				printf("YES\n");
				return 0;
			}
			else{
				printf("�s��\n");
				return 1;
			}
		}
	}
};

class parrot :public bird{
public:
	int skill(char *data_q){
		char data[] = "���m�}�l";
		if (data_q == NULL){
			printf("answer:%s\n", data);
		}
		else{
			printf("���K�w�F");
			if (*data_q == *data){
				printf("YES\n");
				return 0;
			}
			else{
				printf("�s��\n");
				return 1;
			}
		}
	}
};

int main(){
	char question[100];
	char *NM1;
	char *NM2;
	char *NM3;
	char *data_q = NULL;
	int ck;

	printf("�������͂��Ă�������\n");
	scanf("%s", question);

	NM1 = strstr(question, "�I�[��");
	NM2 = strstr(question, "��");
	NM3 = strstr(question, "����");

	if (NM1 == NULL){
		if (NM2 == NULL){
			if (NM3 == NULL){
				printf("�킩��܂���\n");
			}
		}
	}

	if (NM1 != NULL){
		parrot parrot;
		NM1 = strstr(NM1, "���Z");
		if (NM1 != NULL){
			NM1 = strstr(NM1, "��");
			if (NM1 != NULL){
				parrot.skill(data_q);
			}
		}
		
		NM1 = strstr(question, "�ċz");
		if (NM1 != NULL){
			data_q = "�ċz����";
			NM1 = strstr(NM1, "��");
			if (NM1 != NULL){
				ck = parrot.skill(data_q);
				if (ck == 1){
					ck = parrot.Attribute(data_q);
					if (ck == 1){
						ck = parrot.attribute(data_q);
					}
				}
			}
		}
		
	}
	if (NM2 != NULL){
		bird bird;
	}
	if (NM3 != NULL){
		creature creature;
	}
}