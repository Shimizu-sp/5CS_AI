#include<stdio.h>
#include<stdlib.h>


main(void) {
	char s[11] = "a*b-cd/e+fg";
	char g[11] = "gfedcba+-*/";
	int e = 0;
	int i = 0;
	int j = 0;

	/*printf("a�̕����R�[�h��%d \n", 'a');
	printf("b�̕����R�[�h��%d \n", 'b');
	printf("c�̕����R�[�h��%d \n", 'c');
	printf("d�̕����R�[�h��%d \n", 'd');
	printf("e�̕����R�[�h��%d \n", 'e');
	printf("f�̕����R�[�h��%d \n", 'f');
	printf("g�̕����R�[�h��%d \n", 'g');

	printf("\n+�̕����R�[�h��%d \n", '+');
	printf("-�̕����R�[�h��%d \n", '-');
	printf("*�̕����R�[�h��%d \n", '*');
	printf("/�̕����R�[�h��%d \n", '/');
	*/

	//R1.�L���𐔎��ɒu��������
	for (j = 0; j < 11; j++) {
		if (s[j] == 'g') {
			s[j] = 1;
			printf("g -> %d\n", s[j]);
		}
		if (s[j] == 'f') {
			s[j] = 2;
			printf("f -> %d\n", s[j]);
		}
		if (s[j] == 'e') {
			s[j] = 3;
			printf("e -> %d\n", s[j]);
		}
		if (s[j] == 'd') {
			s[j] = 4;
			printf("d -> %d\n", s[j]);
		}
		if (s[j] == 'c') {
			s[j] = 5;
			printf("c -> %d\n", s[j]);
		}
		if (s[j] == 'b') {
			s[j] = 6;
			printf("b -> %d\n", s[j]);
		}
		if (s[j] == 'a') {
			s[j] = 7;
			printf("a -> %d\n", s[j]);
		}
		if (s[j] == '+') {
			s[j] = 8;
			printf("+ -> %d\n", s[j]);
		}
		if (s[j] == '-') {
			s[j] = 9;
			printf("- -> %d\n", s[j]);
		}
		if (s[j] == '*') {
			s[j] = 10;
			printf("* -> %d\n", s[j]);
		}
		if (s[j] == '/') {
			s[j] = 11;
			printf("/ -> %d\n", s[j]);
		}
	}

	//�S�̂���for��
	for (i = 0; i < 11; i++) {
		for (j = 0; j < 10; j++) {
			//R2.�o�u���\�[�g�ŏ��������ɕ��ׂ�
			if (s[j] > s[j + 1]) {
				e = s[j];
				s[j] = s[j + 1];
				s[j + 1] = e;

			}
		}
	}
	for (j = 0; j < 11; j++) {
		if (s[j] == 1) {
			s[j] = 'g';
			printf("%c ", s[j]);
		}
		if (s[j] == 2) {
			s[j] = 'f';
			printf("%c ", s[j]);
		}
		if (s[j] == 3) {
			s[j] = 'e';
			printf("%c ", s[j]);
		}
		if (s[j] == 4) {
			s[j] = 'd';
			printf("%c ", s[j]);
		}
		if (s[j] == 5) {
			s[j] = 'c';
			printf("%c ", s[j]);
		}
		if (s[j] == 6) {
			s[j] = 'b';
			printf("%c ", s[j]);
		}
		if (s[j] == 7) {
			s[j] = 'a';
			printf("%c ", s[j]);
		}
		if (s[j] == 8) {
			s[j] = '+';
			printf("%c ", s[j]);
		}
		if (s[j] == 9) {
			s[j] = '-';
			printf("%c ", s[j]);
		}
		if (s[j] == 10) {
			s[j] = '*';
			printf("%c ", s[j]);
		}
		if (s[j] == 11) {
			s[j] = '/';
			printf("%c \n", s[j]);
		}
	}
}