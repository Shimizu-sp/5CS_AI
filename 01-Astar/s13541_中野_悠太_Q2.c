#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int defalut[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } }; //�������
int end[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } }; //�S�[�����

int trade(int x_axis, int y_axis);
int manhattan(int x_axis, int y_axis);

int main(){

	int n, i, man = 0, flag = 0;




	while (1 == 1){
		for (i = 0; i < 3; i++){

			for (n = 0; n < 3; n++){
				printf("%d ", defalut[i][n]);; //���݂̏�Ԃ�\��

				if (defalut[i][n] == -1){ //�s�[�X�̓���ւ�
					trade(i, n);
				}

				man = man + manhattan(i, n); //���݂̃}���n�b�^���������v�Z

			}
			printf("\n");

			if (defalut[i][n] == end[i][n]){
				flag = flag + 1;
			}
			if (flag == 9){ //�I������
				break;
			}


		}
		printf("�}���n�b�^�������@= %d\n", man); //�}���n�b�^��������\��
		getchar();
		flag = 0;
		man = 0;
	}



	for (i = 0; i < 3; i++){

		for (n = 0; n < 3; n++){
			printf("%d ", defalut[i][n]);; //���݂̏�Ԃ�\��
		}
		printf("\n");
	}


}

int manhattan(int x_axis, int y_axis){ //�}���n�b�^���������v�Z����֐�
	int i, n;
	int m = 0;

	for (i = 0; i < 3; i++){
		for (n = 0; n < 3; n++){
			if (defalut[x_axis][y_axis] == end[i][n]){

				m = abs(x_axis - i) + abs(y_axis - n);
				break;
			}
		}

	}

	return m;
}

int trade(int x_axis, int y_axis){ //�s�[�X�̓���ւ�

	return 0;
}