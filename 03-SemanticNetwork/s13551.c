#include<stdio.h>
#include<string.h>
int main(void) {
	int s = 0, t = 0, o = 0, k = 0, tu = 0, tk = 0, y = 0, n = 0, b = 0, d = 0, a = 0, lp = 0;//�ϐ��̒�`
	char str1[] = "����";//���O�ݒ�̒P��̐ݒ�
	char str2[] = "��";//���O�ݒ�̒P��̐ݒ�
	char str3[] = "�I�[��";//���O�ݒ�̒P��̐ݒ�
	char str4[] = "�ċz";//���O�ݒ�̒P��̐ݒ�
	char str5[] = "��";//���O�ݒ�̒P��̐ݒ�
	char str6[] = "���Z";//���O�ݒ�̒P��̐ݒ�
	char str7[] = "����";//���O�ݒ�̒P��̐ݒ�
	char str8[] = "�Ȃ�";//���O�ݒ�̒P��̐ݒ�
	char str9[] = "����";//���O�ݒ�̒P��̐ݒ�
	char str10[] = "���Ȃ�";//���O�ݒ�̒P��̐ݒ�
	char str11[50];//���͂��镶���̒�`
	while (b = !0) {
		printf("���������͂��Ă�������\n");
		scanf_s("%s", str11,50);//�����̓���
		if (strstr(str11, str1) != NULL) {//�����ɐ��������邩�m�F
			s = 1;
			d = 1;
		}
		if (strstr(str11, str2) != NULL) {//�����ɒ������邩�m�F
			t = 1;
			d = 1;
		}
		if (strstr(str11, str3) != NULL) {//�����ɃI�[�������邩�m�F
			o = 1;
			d = 1;
		}
		if (strstr(str11, str4) != NULL) {//�����Ɍċz�����邩�m�F
			k = 1;
			lp = 1;
		}
		if (strstr(str11, str5) != NULL) {//�����ɗ������邩�m�F
			tu = 1;
			lp = 1;
		}
		if (strstr(str11, str6) != NULL) {//�����ɓ��Z�����邩�m�F
			tk = 1;
			lp = 1;
		}
		if (strstr(str11, str7) != NULL) {//�����ɂ��邪���邩�m�F
			y = 1;
		}
		if (strstr(str11, str8) != NULL) {//�����ɂȂ������邩�m�F
			n = 1;
		}
		if (strstr(str11, str9) != NULL) {//�����ɂ��邪���邩�m�F
			y = 1;
		}
		if (strstr(str11, str10) != NULL) {//�����ɂ��Ȃ������邩�m�F
			n = 1;
		}if (d == 1) {//while�𔲂���
			break;
		}if (d = !1) {//�Ⴄ���������͂��ꂽ�ꍇ
			printf("������x���肢���܂�");
		}
	}
	while (b = !0) {
		if (o == 1) {//�����ɃI�[��������ꍇ
			if (tk == 1) {//�����ɓ��Z������ꍇ
				a = 1;
				printf("�I�[���̓��Z�̓��m�}�l�ł���\n");
				break;
			}
			else {//�����ɓ��Z���Ȃ��ꍇ
				t++;
				o++;
				printf("�I�[���͒��ł���\n");
			}
		}
		if (t >= 1) {//�����ɒ�������ꍇ����ʂƂ��ČĂ΂ꂽ�ꍇ
			if (tu == 1) {//�����ɗ�������ꍇ
				a = 2;
				printf("���ɂ͗�������\n");
				break;
			}
			else {//�����ɗ����Ȃ��ꍇ
				s++;
				printf("���͐����ł���\n");
			}
		}
		if (s >= 1) {//�����ɐ���������ꍇ����ʂƂ��ČĂ΂ꂽ�ꍇ
			if (k == 1) {//�����Ɍċz������ꍇ
				a = 3;
				printf("�����͌ċz������\n");
				break;
			}
			else {//�����Ɍċz���Ȃ��ꍇ
				a = 4;
				break;
			}
		}
	}
	if (a == 1) {
		printf("���m�}�l\n");
	}
	if (a == 2) {
		if (y == 1) {
			printf("Yes\n");
		}
		if (n == 1) {
			printf("No\n");
		}
	}if (a == 3) {
		if (y == 1) {
			printf("Yes\n");
		}
		if (n == 1) {
			printf("No\n");
		}
	}
	return 0;
}