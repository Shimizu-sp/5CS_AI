#include<stdio.h>
main(){

	char First[11] = { 'a', '*', 'b', '-', 'c', 'd', '/', 'e', '+', 'f', 'g' };//11��ނ̕�����
	int i = 0, j = 0;//�J�E���g�p
	int where = 0;//�����̈ʒu�L��
	char n = '1';//������̕ۑ��p

	for (i = 0; i < 11; i++){
		printf("%c", First[i]);//������Ԃ��ŏ��ɕ\��
	}
	printf("\n");
	printf("���ёւ����J�n���܂�\n");

	while (First[0] != 'g'){//R1_������g��1�ԖڂłȂ���ΑO�ƌ�������
		for (j = 0; j < 11; j++){
			if (First[j] == 'g'){
				where = j;//g�̏ꏊ�擾
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//����
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//�ړ��ߒ�(WM�̏�ԕω�)
		}
		printf("\n");
	}
	printf("g���������ʒu�Ɉړ����܂����B\n");

	while (First[1] != 'f'){//R2_������f��2�ԖڂłȂ���ΑO�ƌ�������
		for (j = 0; j < 11; j++){
			if (First[j] == 'f'){
				where = j;//f�̏ꏊ�擾
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//����
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//�ړ��ߒ�(WM�̏�ԕω�)
		}
		printf("\n");
	}
	printf("f���������ʒu�Ɉړ����܂����B\n");

	while (First[2] != 'e'){//R3_������e��3�ԖڂłȂ���ΑO�ƌ�������
		for (j = 0; j < 11; j++){
			if (First[j] == 'e'){
				where = j;//e�̏ꏊ�擾
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//����
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//�ړ��ߒ�(WM�̏�ԕω�)
		}
		printf("\n");
	}
	printf("e���������ʒu�Ɉړ����܂����B\n");

	while (First[3] != 'd'){//R4_������d��4�ԖڂłȂ���ΑO�ƌ�������
		for (j = 0; j < 11; j++){
			if (First[j] == 'd'){
				where = j;//d�̏ꏊ�擾
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//����
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//�ړ��ߒ�(WM�̏�ԕω�)
		}
		printf("\n");
	}
	printf("d���������ʒu�Ɉړ����܂����B\n");

	while (First[4] != 'c'){//R5_������c��5�ԖڂłȂ���ΑO�ƌ�������
		for (j = 0; j < 11; j++){
			if (First[j] == 'c'){
				where = j;//c�̏ꏊ�擾
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//����
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//�ړ��ߒ�(WM�̏�ԕω�)
		}
		printf("\n");
	}
	printf("c���������ʒu�Ɉړ����܂����B\n");
	while (First[5] != 'b'){//R6_������b��6�ԖڂłȂ���ΑO�ƌ�������
		for (j = 0; j < 11; j++){
			if (First[j] == 'b'){
				where = j;//b�̏ꏊ�擾
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//����
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//�ړ��ߒ�(WM�̏�ԕω�)
		}
		printf("\n");
	}
	printf("b���������ʒu�Ɉړ����܂����B\n");

	while (First[6] != 'a'){//R7_������a��7�ԖڂłȂ���ΑO�ƌ�������
		for (j = 0; j < 11; j++){
			if (First[j] == 'a'){
				where = j;//a�̏ꏊ�擾
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//����
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//�ړ��ߒ�(WM�̏�ԕω�)
		}
		printf("\n");
	}
	printf("a���������ʒu�Ɉړ����܂����B\n");

		while (First[7] != '+'){//R8_������+��8�ԖڂłȂ���ΑO�ƌ�������
		for (j = 0; j < 11; j++){
			if (First[j] == '+'){
				where = j;//+�̏ꏊ�擾
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//����
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//�ړ��ߒ�(WM�̏�ԕω�)
		}
		printf("\n");
	}
	printf("+���������ʒu�Ɉړ����܂����B\n");

	while (First[8] != '-'){//R9_������-��9�ԖڂłȂ���ΑO�ƌ�������
		for (j = 0; j < 11; j++){
			if (First[j] == '-'){
				where = j;//-�̏ꏊ�擾
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//����
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//�ړ��ߒ�(WM�̏�ԕω�)
		}
		printf("\n");
	}
	printf("-���������ʒu�Ɉړ����܂����B\n");

	while (First[9] != '*'){//R10_������*��10�ԖڂłȂ���ΑO�ƌ�������
		for (j = 0; j < 11; j++){
			if (First[j] == '*'){
				where = j;//*�̏ꏊ�擾
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//����
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//�ړ��ߒ�(WM�̏�ԕω�)
		}
		printf("\n");
	}
	printf("*���������ʒu�Ɉړ����܂����B\n");

	while (First[10] != '/'){//R11_������/��11�ԖڂłȂ���ΑO�ƌ�������
		for (j = 0; j < 11; j++){
			if (First[j] == '/'){
				where = j;// /�̏ꏊ�擾
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//����
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//�ړ��ߒ�(WM�̏�ԕω�)
		}
		printf("\n");
	}
	printf("/���������ʒu�Ɉړ����܂����B\n");
	printf("\n");
	for (i = 0; i < 11; i++){
		printf("%c", First[i]);//�S�[����Ԃ�\��
	}
	printf("\n");
	printf("���ёւ����I�����܂����B\n");

}