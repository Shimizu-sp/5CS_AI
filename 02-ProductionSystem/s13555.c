#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>

main(){
	// a*b-cd/e+fg     gfedcba+-*/
	int i, j;
    char moji[] = "a*b-cd/e+fg";

	char change;


	printf("������Ԃ�:");
	for (i = 0; i < 11; i++){
		printf(" %c", moji[i]);
	}
	printf("\n\n");

	printf("���[��1 : �L���̉E�ׂɕ����͗��Ȃ��B\n");
	for (j = 0; j < 10; j++){                     //���[��1 : �L���̉E�ׂɕ����͗��Ȃ��B
		for (i = 0; i < 10; i++){
			if (ispunct(moji[i]) != 0) {
				if (isalnum(moji[i + 1])){
					change = moji[i];
					moji[i] = moji[i + 1];
					moji[i + 1] = change;
				}
			}
		  
		}
		for (i = 0; i < 11; i++){
			printf("%c", moji[i]);
		}
	  printf("\n");
	}
	printf("\n");
	change = "";


	printf("���[��2 :a�̉E�ׂ͋L���ł���B\n");
	for (j = 0; j < 10; j++){                     //���[��2 :a�̉E�ׂ͋L���ł���B
		for (i = 0; i < 10; i++){
			if (moji[i] == 97){
				if (isalnum(moji[i + 1]) == 2){
					change = moji[i];
					moji[i] = moji[i + 1];
					moji[i + 1] = change;
				}
			}
		}
		for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
		}
		printf("\n");
	}
	printf("\n");


	printf("���[��3 :b�̉E�ׂ�a�ł���B\n");
		for (j = 0; j < 10; j++){                     //���[��3 :b�̉E�ׂ�a�ł���B
			for (i = 0; i < 10; i++){
				if (moji[i] == 98){
					if (moji[i + 1] != 97){
						change = moji[i];
						moji[i] = moji[i + 1];
						moji[i + 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
			printf("%c", moji[i]);
		}
			printf("\n");
		}
		printf("\n");


		printf("���[��4 :c�̉E�ׂ�b�ł���B\n");
		for (j = 0; j < 10; j++){                     //���[��4 :c�̉E�ׂ�b�ł���B
			for (i = 0; i < 10; i++){
				if (moji[i] == 99){
					if (moji[i + 1] != 98){
						change = moji[i];
						moji[i] = moji[i + 1];
						moji[i + 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");


		printf("���[��5 :d�̉E�ׂ�c�ł���B\n");
		for (j = 0; j < 10; j++){                     //���[��5 :d�̉E�ׂ�c�ł���B
			for (i = 0; i < 10; i++){
				if (moji[i] == 100){
					if (moji[i + 1] != 99){
						change = moji[i];
						moji[i] = moji[i + 1];
						moji[i + 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");


		printf("���[��6 :e�̉E�ׂ�d�ł���B\n");
		for (j = 0; j < 10; j++){                     //���[��6 :e�̉E�ׂ�d�ł���B
			for (i = 0; i < 10; i++){
				if (moji[i] == 101){
					if (moji[i + 1] != 100){
						change = moji[i];
						moji[i] = moji[i + 1];
						moji[i + 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");


		printf("���[��7 :f�̉E�ׂ�e�ł���B\n");
		for (j = 0; j < 10; j++){                     //���[��7 :f�̉E�ׂ�e�ł���B
			for (i = 0; i < 10; i++){
				if (moji[i] == 102){
					if (moji[i + 1] != 101){
						change = moji[i];
						moji[i] = moji[i + 1];
						moji[i + 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");


		printf("���[��8 : + �̍��ׂ� a �ł���B\n");
		for (j = 0; j < 11; j++){                     //���[��8 : + �̍��ׂ� a �ł���B
			for (i = 0; i < 11; i++){
				if (moji[i] == 43){
					if (moji[i - 1] != 97){
						change = moji[i];
						moji[i] = moji[i - 1];
						moji[i - 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");


		printf("���[��9 : - �̍��ׂ� + �ł���B\n");
		for (j = 0; j < 11; j++){                     //���[��9 : - �̍��ׂ� + �ł���B
			for (i = 0; i < 11; i++){
				if (moji[i] == 45){
					if (moji[i - 1] != 43){
						change = moji[i];
						moji[i] = moji[i - 1];
						moji[i - 1] = change;
					}
				}
			}
			for (i = 0; i < 11; i++){
				printf("%c", moji[i]);
			}
			printf("\n");
		}
		printf("\n");




		printf("\n");
	}
