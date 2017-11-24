#include<stdio.h>
#include<string.h>

#pragma warning(disable : 4996)

class creature{
public:
	int attribute(char *data_q){
		char data[] = "ŒÄ‹z‚·‚é";
		if (data_q == NULL){
			printf("answer:%s\n", data);
		}
		else{
			printf("‘æOŠK‘wF");
			if (*data_q == *data){
				
				printf("YES\n");
				return 0;
			}
			else{
				printf("•s–¾\n");
				return 1;
			}
		}
	}
};

class bird :public creature{
public:
	int Attribute(char *data_q){
		char data[] = "—ƒ‚ª‚ ‚é";
		if (data_q == NULL){
			printf("answer:%s\n", data);
		}
		else{
			printf("‘æ“ñŠK‘wF");
			if (*data_q == *data){
				printf("YES\n");
				return 0;
			}
			else{
				printf("•s–¾\n");
				return 1;
			}
		}
	}
};

class parrot :public bird{
public:
	int skill(char *data_q){
		char data[] = "ƒ‚ƒmƒ}ƒl";
		if (data_q == NULL){
			printf("answer:%s\n", data);
		}
		else{
			printf("‘æˆêŠK‘wF");
			if (*data_q == *data){
				printf("YES\n");
				return 0;
			}
			else{
				printf("•s–¾\n");
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

	printf("¿–â‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
	scanf("%s", question);

	NM1 = strstr(question, "ƒI[ƒ€");
	NM2 = strstr(question, "’¹");
	NM3 = strstr(question, "¶•¨");

	if (NM1 == NULL){
		if (NM2 == NULL){
			if (NM3 == NULL){
				printf("‚í‚©‚è‚Ü‚¹‚ñ\n");
			}
		}
	}

	if (NM1 != NULL){
		parrot parrot;
		NM1 = strstr(NM1, "“Á‹Z");
		if (NM1 != NULL){
			NM1 = strstr(NM1, "‰½");
			if (NM1 != NULL){
				parrot.skill(data_q);
			}
		}
		
		NM1 = strstr(question, "ŒÄ‹z");
		if (NM1 != NULL){
			data_q = "ŒÄ‹z‚·‚é";
			NM1 = strstr(NM1, "‚©");
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