#include<stdio.h>
#include<string.h>

#pragma warning(disable : 4996)

class creature{
public:
	int attribute(char *data_q){
		char data[] = "呼吸する";
		if (data_q == NULL){
			printf("answer:%s\n", data);
		}
		else{
			printf("第三階層：");
			if (*data_q == *data){
				
				printf("YES\n");
				return 0;
			}
			else{
				printf("不明\n");
				return 1;
			}
		}
	}
};

class bird :public creature{
public:
	int Attribute(char *data_q){
		char data[] = "翼がある";
		if (data_q == NULL){
			printf("answer:%s\n", data);
		}
		else{
			printf("第二階層：");
			if (*data_q == *data){
				printf("YES\n");
				return 0;
			}
			else{
				printf("不明\n");
				return 1;
			}
		}
	}
};

class parrot :public bird{
public:
	int skill(char *data_q){
		char data[] = "モノマネ";
		if (data_q == NULL){
			printf("answer:%s\n", data);
		}
		else{
			printf("第一階層：");
			if (*data_q == *data){
				printf("YES\n");
				return 0;
			}
			else{
				printf("不明\n");
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

	printf("質問を入力してください\n");
	scanf("%s", question);

	NM1 = strstr(question, "オーム");
	NM2 = strstr(question, "鳥");
	NM3 = strstr(question, "生物");

	if (NM1 == NULL){
		if (NM2 == NULL){
			if (NM3 == NULL){
				printf("わかりません\n");
			}
		}
	}

	if (NM1 != NULL){
		parrot parrot;
		NM1 = strstr(NM1, "特技");
		if (NM1 != NULL){
			NM1 = strstr(NM1, "何");
			if (NM1 != NULL){
				parrot.skill(data_q);
			}
		}
		
		NM1 = strstr(question, "呼吸");
		if (NM1 != NULL){
			data_q = "呼吸する";
			NM1 = strstr(NM1, "か");
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