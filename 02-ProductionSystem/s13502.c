#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Hyouji(char array[]);	// ��ԕ\���p�֐�
void rule1(char array[]);	// ���[��1
void rule2(char array[]);	// ���[��2
void rule3(char array[]);	// ���[��3
void rule4(char array[]);	// ���[��4

main() {
	int	pattern = 0;

	char start[12] = "a*b-cd/e+fg";	// �������
	char goal[12] = "gfedcba+-*/";

	Hyouji(start); // �z��S���\��

		rule1(start);  // �L�����E�ɗ���@���[���K��

		rule2(start);  // �����������ƕ��ׂ�@���[���K��

		rule3(start);	// �L�������������ɓ���ւ���@���[���K��

		rule4(start);	// �u*�v�𐳂����ꏊ�ɓ���ւ���@���[���K��
}



//�֐� 

//------------------------------------

void Hyouji(char array[]){
	int i;

	for (i = 0; i < 11; i++){
		printf("%c", array[i]);
	}
	printf("\n");
}

void rule1(char array[]) {
	int k, m, i;
	int stay;

	printf("\n");
	printf("���[��1 �L�����E�Ɋ񂹂�\n");
	// �L�����E�Ɋ񂹂�
	for (k = 0; k < 11; k++) {
		for (m = 0; m < 10; m++) {
			if (ispunct(array[m]) != 0) {	// m���L���Ȃ�
				stay = array[m + 1];		// ��ׂƌ���
				array[m + 1] = array[m];
				array[m] = stay;
				Hyouji(array);
			}
		}

	}

}

void rule2(char array[]) {
	int i, m;
	int stay;

	printf("\n");
	printf("���[��2 �A���t�@�x�b�g�����ւ���(����)\n");
	// �A���t�@�x�b�g�����ւ���
	for (m = 0; m < 11; m++) {
		for (i = 0; i < 11; i++) {
			if (ispunct(array[i]) == 0) {		// �A���t�@�x�b�g�Ȃ�
				if (array[i] < array[i + 1]) {	// �Ȃ����E�̂ق����f�J��
					stay = array[i + 1];
					array[i + 1] = array[i];
					array[i] = stay;
					Hyouji(array);
				}
			}
			
		}
	}

}

void rule3(char array[]) {
	int i, m;
	int stay;

	printf("\n");
	printf("���[��3 �L�������������ɕ��ׂ�\n");

	for (m = 0; m < 11; m++) {
		for (i = 0; i < 10; i++) {
			if (ispunct(array[i]) != 0) {		// �L���Ȃ�
				if (array[i + 1] < array[i]) {	// �ׂ��������Ȃ�
					stay = array[i + 1];
					array[i + 1] = array[i];
					array[i] = stay;
					Hyouji(array);
				}
			}
			
		}
	}
}

void rule4(char array[]) {
	int i, m;
	int stay;

	printf("\n");
	printf("���[��4 �u*�v�𐳂����ʒu�ɂ����Ă�\n");

	for (m = 7; m < 8; m++) {
		for (i = m; i < 9; i++) {
		  if (ispunct(array[i]) != 0) {		// �L���Ȃ�
			if (array[i] < array[i + 1]) {	// �ׂ��ł����Ȃ�
			
					stay = array[i];
					array[i] = array[i + 1];
					array[i+1] = stay;
					Hyouji(array);
				} 
			 }
			
		    }
		}


}
