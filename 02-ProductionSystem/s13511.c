#include<stdio.h>
#include<ctype.h>

int prodaction_R1();
int prodaction_R2();
int prodaction_R3();
int prodaction_R4();

char string[] = { 'a', '*', 'b', '-', 'c', 'd', '/', 'e', '+', 'f', 'g', '0' };

int i, j=0;
int ireko;

int ascii_l = 0;
int ascii_r = 0;

//========================================================================

main(){
	printf("R1�K�p\n");
		prodaction_R1();
	printf("R2�K�p\n");
		prodaction_R2();
	printf("R3�K�p\n");
		prodaction_R3();
	printf("R4�K�p\n");
		prodaction_R4();
}

prodaction_R1(){

	int flug_R1;

	do{ //R1�F�������E�ɂ���@�ȁ@�L�������ɂ���@���@���������Ɉړ�����

		flug_R1 = 0; //�t���O������

		for (i = 0; i < 12; i++){

			if (ispunct(string[i]) && isalpha(string[i + 1])){ //ispunct�͋L���Cisalpha�̓A���t�@�x�b�g�ł��邩���肷��֐�

				ireko = string[i];
				string[i] = string[i + 1]; //R1�K�p�@
				string[i + 1] = ireko;

				flug_R1 = flug_R1 + 1; //�t���O�ɉ��Z����
			}

			for (j = 0; j < 11; j++){
				printf("%c ", string[j]);
			}
			printf("\n");
		}

	} while (flug_R1 != 0); //�������Ȃ������Ƃ��I��

	return 0;
}

prodaction_R2(){

	int flug_R2;

	do{ //R2�F�������������E�ɂ���@�ȁ@���������オ���ɂ���@���@���������������Ɉړ�����

		flug_R2 = 0; //�t���O������

		for (i = 0; i < 12; i++){

			if (isalpha(string[i]) && isalpha(string[i+1])){
				ascii_l = string[i];
				ascii_r = string[i+1];
			if (ascii_l < ascii_r){ //�A�X�L�[�R�[�h���Ŕ���

				ireko = string[i];
				string[i] = string[i + 1]; //R1�K�p�@
				string[i + 1] = ireko;

				flug_R2 = flug_R2 + 1; //�t���O�ɉ��Z����
			}}

			for (j = 0; j < 11; j++){
				printf("%c ", string[j]);
			}
			printf("\n");

		}
	} while (flug_R2 != 0); //�������Ȃ������Ƃ��I��

	return 0;
}

prodaction_R3(){

	int flug_R3;

	do{ //R3�F�L�������オ�E�ɂ���@�ȁ@�L�������������ɂ���@���@�L������������Ɉړ�����

		flug_R3 = 0; //�t���O������

		for (i = 0; i < 12; i++){

			if (ispunct(string[i]) && ispunct(string[i + 1])){ //ispunct�͋L���ł��邩���肷��֐�
				ascii_l = string[i];
				ascii_r = string[i + 1];
			if (ascii_l > ascii_r){ //�A�X�L�[�R�[�h���Ŕ���

				ireko = string[i];
				string[i] = string[i + 1]; //R1�K�p�@
				string[i + 1] = ireko;

				flug_R3 = flug_R3 + 1; //�t���O�ɉ��Z����
			}}

			for (j = 0; j < 11; j++){
				printf("%c ", string[j]);
			}
			    printf("\n");
			}

	} while (flug_R3 != 0); //�������Ȃ������Ƃ��I��

	return 0;
}

prodaction_R4(){

	int flug_R4;

	do{ //R4�F�u*�v���u/�v�̍��ȊO�ɂ���@�ȁ@�u/�v���u*�v�̉E�ȊO�ɂ���@���@�u*�v���E�Ɉړ�����

		flug_R4 = 0; //�t���O������

		for (i = 0; i < 12; i++){

			if (string[i] == '*' && string[i+1] != '/'){
				ireko = string[i+1];
				string[i+1] = string[i]; //R1�K�p�@
				string[i] = ireko;

				flug_R4 = flug_R4 + 1; //�t���O�ɉ��Z����
			}}

			for (j = 0; j < 11; j++){
				printf("%c ", string[j]);
			}
			printf("\n");
		
	}while (flug_R4 != 0); //�������Ȃ������Ƃ��I��

	return 0;
}