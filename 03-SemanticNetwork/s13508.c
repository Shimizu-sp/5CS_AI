#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void) {
	char test[100];
	char *a,*b;

	scanf("%s", test);	//�������
	
	a = _mbsstr(test, "�I�[��");	//�I�[���Ƃ����P�ꂪ���邩��������������A�������NULL��Ԃ�
	if (a != NULL) {

		b = _mbsstr(test, "���Z");	//���Z�Ƃ����P�ꂪ���邩��������������A�������NULL��Ԃ�
		
		if (b != NULL) {	//NULL�����Ȃ���΃��m�}�l�Ɠ�����
			printf("���m�}�l\n");
		}
		else {	//NULL�ł���Ώ�ʊT�O��

			a = _mbsstr(test, "��������");	//��������Ƃ����P�ꂪ���邩��������������A�������NULL��Ԃ�

			if (a != NULL) {	//NULL�����Ȃ����Yes�Ɠ����A�v���Z�X���o�͂���
				printf("\n������������\n��\n�I�[��\n");
				printf("\nYes\n");
			}
			else {	//NULL�ł���Ώ�ʊT�O��

				a = _mbsstr(test, "�ċz");	//�ċz�Ƃ����P�ꂪ���邩��������������A�������NULL��Ԃ�

				if (a != NULL) {	//NULL�����Ȃ����Yes�Ɠ����A�v���Z�X���o�͂���
					printf("\n�������ċz������\n��\n��\n��\n�I�[��\n");
					printf("\nYes\n");
				}

			}
		}
	}
}