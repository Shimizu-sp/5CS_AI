#include<stdio.h>
#include<string.h>

void is();
void r1();
void r2();
void r3();
void r4();
void fs();

char WM[][11] = { "a", "*", "b", "-", "c", "d", "/", "e", "+", "f", "g" };
char goal[][11] = { "g", "f", "e", "d", "c", "b", "a", "+", "-", "*", "/" };
int checker = 0;//���ᐔ
int i, j, n;//�J�E���^
char change;//����ւ����ꎞ�ێ��p�ϐ�
int ck;//���[�v�����p�`�F�b�J�[�ϐ�

int cc_1, cc_2;

int main(){
	is();//������ԕ\��
	r1();//���[��1�F�L���͉E�ց@�K�p
	r2();//���[��2:WM[0][0]�`WM[6][0]�܂ł́C�����R�[�h�̒l���傫�����ɂ���@�K�p
	r3();//���[��3:WM[7][0]�`[8][0]�܂ł𕶎��R�[�h�̏��������ɂ���@�K�p
	r4();//���[��4:*��WM[9][0]�ɓ���܂ŉE�ׂƌ������Ȃ���΂Ȃ�Ȃ��@�K�p
	fs();//�ŏI��ԕ\��
}

void is(){
	printf("---�������------------------------------------------\n");

	//WM�ƃS�[����Ԃ̔�r
	for (i = 0; i < 11; i++){
		if (WM[i][0] != goal[i][0]){
			printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
			checker++;
		}
	}
	printf("\n���ᐔ�F%d\n\n", checker);
}

void r1(){
	//���[��1:�L���͉E��
	checker = 0;
	i = 0;
	ck = 0;
	printf("---���[��1�K�p----------------------------------------\n");
	while (ck != 5){
		if ('+' == WM[i][0] || '-' == WM[i][0] || '*' == WM[i][0] || '/' == WM[i][0]){
			if ('a' == WM[i + 1][0] || 'b' == WM[i + 1][0] || 'c' == WM[i + 1][0] || 'd' == WM[i + 1][0] || 'e' == WM[i + 1][0] || 'f' == WM[i + 1][0] || 'g' == WM[i + 1][0]){
				change = WM[i][0];
				WM[i][0] = WM[i + 1][0];
				WM[i + 1][0] = change;
			}
		}
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);

		if ('+' == WM[7][0] || '-' == WM[7][0] || '*' == WM[7][0] || '/' == WM[7][0]){
			if ('+' == WM[8][0] || '-' == WM[8][0] || '*' == WM[8][0] || '/' == WM[8][0]){
				if ('+' == WM[9][0] || '-' == WM[9][0] || '*' == WM[9][0] || '/' == WM[9][0]){
					if ('+' == WM[10][0] || '-' == WM[10][0] || '*' == WM[10][0] || '/' == WM[10][0]){
						ck++;
					}
				}
			}
		}
		i++;
		if (i == 11){
			i = 0;
			if (ck != 5){
				printf("---���[��1�K�p----------------------------------------\n");
			}
		}
	}

	printf("---���[��1�I��----------------------------------------\n");

	for (i = 0; i < 11; i++){
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
		if (WM[i][0] != goal[i][0]){
			checker++;
		}
	}
	printf("\n���ᐔ�F%d\n", checker);
}

void r2(){
	//���[��2:WM[0][0]�`WM[6][0]�܂ł́C�����R�[�h�̒l���傫�����ɂ���
	i = 0;
	checker = 0;
	printf("---���[��2�K�p----------------------------------------\n");
	while (1){
		cc_1 = WM[i][0];
		cc_2 = WM[i + 1][0];
		if (cc_1 < cc_2){
			change = WM[i][0];
			WM[i][0] = WM[i + 1][0];
			WM[i + 1][0] = change;
		}
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);

		i++;
		if (i == 11){
			checker = 0;
			for (j = 0; j < 11; j++){
				if (WM[j][0] != goal[j][0]){
					checker++;
				}
			}
			if (checker <= 4){
				break;
			}
			i = 0;
			printf("---���[��2�K�p----------------------------------------\n");
		}
	}

	printf("---���[��2�I��----------------------------------------\n");
	checker = 0;

	for (i = 0; i < 11; i++){
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
		if (WM[i][0] != goal[i][0]){
			checker++;
		}
	}
	printf("\n���ᐔ%d\n", checker);
}

void r3(){
	//���[��3:WM[7][0]�`[8][0]�܂ł𕶎��R�[�h�̏��������ɂ���
	i = 7;
	checker = -1;
	printf("---���[��3�K�p----------------------------------------\n");
	while (1){
		if (i == 7){
			for (j = 0; j<7; j++){
				printf("WM:%c goal:%c\n", WM[j][0], goal[j][0]);
			}
		}

		cc_1 = WM[i][0];
		cc_2 = WM[i + 1][0];
		if (cc_1 > cc_2){
			if (i != 10){
				change = WM[i][0];
				WM[i][0] = WM[i + 1][0];
				WM[i + 1][0] = change;
			}
		}
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);

		i++;
		if (i == 11){
			checker = 0;
			for (j = 0; j < 11; j++){
				if (WM[j][0] != goal[j][0]){
					checker++;
				}
			}
			if ('*' == WM[7][0] && '+' == WM[8][0] && '-' == WM[9][0] && '/' == WM[10][0]){
				break;
			}
			i = 7;
			printf("---���[��3�K�p----------------------------------------\n");
		}
	}

	printf("---���[��3�I��----------------------------------------\n");
	checker = 0;

	for (i = 0; i < 11; i++){
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
		if (WM[i][0] != goal[i][0]){
			checker++;
		}
	}
	printf("\n���ᐔ�F%d\n", checker);
}

void r4(){
	//���[��4:*��WM[9][0]�ɓ���܂ŉE�ׂƌ������Ȃ���΂Ȃ�Ȃ�
	checker = 0;
	i = 0;
	printf("---���[��4�K�p----------------------------------------\n");
	while (1){
		if ('*' == WM[i][0]){
			break;
		}
		i++;
	}

	n = i;

	while (1){
		if (i <= n){
			for (j = 0; j<7; j++){
				printf("WM:%c goal:%c\n", WM[j][0], goal[j][0]);
			}
		}
		change = WM[i][0];
		WM[i][0] = WM[i + 1][0];
		WM[i + 1][0] = change;

		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);

		if ('*' == WM[9][0]){
			for (i = 9; i < 11; i++){
				printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
			}
			break;
		}
		if (i == 11){
			i = n;
		}
		i++;
	}

	printf("---���[��4�I��----------------------------------------\n");
	checker = 0;

	for (i = 0; i < 11; i++){
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
		if (WM[i][0] != goal[i][0]){
			checker++;
		}
	}
	printf("\n���ᐔ�F%d\n", checker);
}

void fs(){
	printf("---�ŏI����------------------------------------------\n");
	for (i = 0; i < 11; i++){
		printf("WM:%c goal:%c\n", WM[i][0], goal[i][0]);
		if (WM[i][0] != goal[i][0]){
			checker++;
		}
	}
	printf("\n���ᐔ�F%d\n", checker);
}