#include<stdio.h>

int main(){
	
	int box[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } };//������ԁi�󔒂�0�Ƃ���j����шړ���̔Ֆ�
	int box_up[3][3] = { 0 };
	int box_left[3][3] = { 0 };
	int box_right[3][3] = { 0 };
	int box_doun[3][3] = { 0 };
	int i,j,n,m;//���[�v�J�E���^�[
	int x_0, y_0;//0�̓����Ă�����W
	int x, y;
	int x_g, y_g;//�S�[���̍��W
	int m1=0, m2=0, m3=0, m4=0,M=100;//�}���n�b�^������
	int g=0;//�o�H�R�X�g
	int f1=0,f2=0,f3=0,f4=0;//�����I�֐��̒l
	int ck=0;//�召�֌W�𒲂ׂ�`�F�b�J�[

	g++;

	//while (M != 0){

		//������ԕ\��
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				printf("%d ", box[i][j]);
			}
			printf("\n");
		}

		//0�̈ʒu�����߂�
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (box[i][j] == 0){
					break;
				}
			}
			if (box[i][j] == 0){
				break;
			}
		}
		printf("\n0:box[%d][%d]\n\n", i, j);

		//��̐�����0�̈ʒu�ɓ��ꂽ�ꍇ�̃}���n�b�^�����������߂�
		printf("---UP---\n\n");
		//0�Ƃ��̏�̐����̓���ւ�
		x_0 = i;
		y_0 = j;
		box[x_0][y_0] = box[x_0 - 1][y_0];
		box[x_0 - 1][y_0] = 0;

		//�}���n�b�^�������̑��a�����߂�
		for (n = 0; n < 3; n++){
			for (m = 0; m < 3; m++){
				x = n;
				y = m;
				switch (box[x][y]){
				case 1:
					x_g = 0;
					y_g = 0;
					break;
				case 2:
					x_g = 0;
					y_g = 1;
					break;
				case 3:
					x_g = 0;
					y_g = 2;
					break;
				case 4:
					x_g = 1;
					y_g = 0;
					break;
				case 5:
					x_g = 1;
					y_g = 1;
					break;
				case 6:
					x_g = 1;
					y_g = 2;
					break;
				case 7:
					x_g = 2;
					y_g = 0;
					break;
				case 8:
					x_g = 2;
					y_g = 1;
					break;
				case 0:
					x_g = x;
					y_g = y;
					break;
				}
				while (x != x_g){
					if (x > x_g){
						x = x - 1;
						m1++;
					}
					else if (x < x_g){
						x = x + 1;
						m1++;
					}
				}
				while (y != y_g){
					if (y>y_g){
						y = y - 1;
						m1++;
					}
					else if (y < y_g){
						y = y + 1;
						m1++;
					}
				}
			}
		}
		printf("M1=%d\n\n", m1);

		//�Ֆʂ̕ێ�
		for (m = 0; m < 3; m++){
			for (n = 0; n < 3; n++){
				box_up[m][n] = box[m][n];
				printf("%d ", box[m][n]);
			}
			printf("\n");
		}
		printf("\n");

		//�p�Y�������ւ���O�̏�Ԃɖ߂�
		box[x_0 - 1][y_0] = box[x_0][y_0];
		box[x_0][y_0] = 0;


		//���̐�����0�̈ʒu�ɓ��ꂽ�ꍇ�̃}���n�b�^�����������߂�
		printf("---LEFT---\n\n");
		//0�Ƃ��̍��̐����̓���ւ�
		x_0 = i;
		y_0 = j;
		box[x_0][y_0] = box[x_0][y_0 - 1];
		box[x_0][y_0 - 1] = 0;

		//�}���n�b�^�������̑��a�����߂�
		for (n = 0; n < 3; n++){
			for (m = 0; m < 3; m++){
				x = n;
				y = m;
				switch (box[x][y]){
				case 1:
					x_g = 0;
					y_g = 0;
					break;
				case 2:
					x_g = 0;
					y_g = 1;
					break;
				case 3:
					x_g = 0;
					y_g = 2;
					break;
				case 4:
					x_g = 1;
					y_g = 0;
					break;
				case 5:
					x_g = 1;
					y_g = 1;
					break;
				case 6:
					x_g = 1;
					y_g = 2;
					break;
				case 7:
					x_g = 2;
					y_g = 0;
					break;
				case 8:
					x_g = 2;
					y_g = 1;
					break;
				case 0:
					x_g = x;
					y_g = y;
					break;
				}
				while (x != x_g){
					if (x > x_g){
						x = x - 1;
						m2++;
					}
					else if (x < x_g){
						x = x + 1;
						m2++;
					}
				}
				while (y != y_g){
					if (y>y_g){
						y = y - 1;
						m2++;
					}
					else if (y < y_g){
						y = y + 1;
						m2++;
					}
				}
			}
		}
		printf("M2=%d\n\n", m2);

		//�Ֆʂ̕ێ�
		for (m = 0; m < 3; m++){
			for (n = 0; n < 3; n++){
				box_up[m][n] = box[m][n];
				printf("%d ", box[m][n]);
			}
			printf("\n");
		}
		printf("\n");

		//�p�Y�������ւ���O�̏�Ԃɖ߂�
		box[x_0][y_0 - 1] = box[x_0][y_0];
		box[x_0][y_0] = 0;


		//�E�̐�����0�̈ʒu�ɓ��ꂽ�ꍇ�̃}���n�b�^�����������߂�
		printf("---RIGHT---\n\n");
		//0�Ƃ��̉E�̐����̓���ւ�
		x_0 = i;
		y_0 = j;
		box[x_0][y_0] = box[x_0][y_0 + 1];
		box[x_0][y_0 + 1] = 0;

		//�}���n�b�^�������̑��a�����߂�
		for (n = 0; n < 3; n++){
			for (m = 0; m < 3; m++){
				x = n;
				y = m;
				switch (box[x][y]){
				case 1:
					x_g = 0;
					y_g = 0;
					break;
				case 2:
					x_g = 0;
					y_g = 1;
					break;
				case 3:
					x_g = 0;
					y_g = 2;
					break;
				case 4:
					x_g = 1;
					y_g = 0;
					break;
				case 5:
					x_g = 1;
					y_g = 1;
					break;
				case 6:
					x_g = 1;
					y_g = 2;
					break;
				case 7:
					x_g = 2;
					y_g = 0;
					break;
				case 8:
					x_g = 2;
					y_g = 1;
					break;
				case 0:
					x_g = x;
					y_g = y;
					break;
				}
				while (x != x_g){
					if (x > x_g){
						x = x - 1;
						m3++;
					}
					else if (x < x_g){
						x = x + 1;
						m3++;
					}
				}
				while (y != y_g){
					if (y>y_g){
						y = y - 1;
						m3++;
					}
					else if (y < y_g){
						y = y + 1;
						m3++;
					}
				}
			}
		}
		printf("M3=%d\n\n", m3);

		//�Ֆʂ̕ێ�
		for (m = 0; m < 3; m++){
			for (n = 0; n < 3; n++){
				box_up[m][n] = box[m][n];
				printf("%d ", box[m][n]);
			}
			printf("\n");
		}
		printf("\n");

		//�p�Y�������ւ���O�̏�Ԃɖ߂�
		box[x_0][y_0 + 1] = box[x_0][y_0];
		box[x_0][y_0] = 0;


		//���̐�����0�̈ʒu�ɓ��ꂽ�ꍇ�̃}���n�b�^�����������߂�
		printf("---DOWN---\n\n");
		//0�Ƃ��̉��̐����̓���ւ�
		x_0 = i;
		y_0 = j;
		box[x_0][y_0] = box[x_0 + 1][y_0];
		box[x_0 + 1][y_0] = 0;

		//�}���n�b�^�������̑��a�����߂�
		for (n = 0; n < 3; n++){
			for (m = 0; m < 3; m++){
				x = n;
				y = m;
				switch (box[x][y]){
				case 1:
					x_g = 0;
					y_g = 0;
					break;
				case 2:
					x_g = 0;
					y_g = 1;
					break;
				case 3:
					x_g = 0;
					y_g = 2;
					break;
				case 4:
					x_g = 1;
					y_g = 0;
					break;
				case 5:
					x_g = 1;
					y_g = 1;
					break;
				case 6:
					x_g = 1;
					y_g = 2;
					break;
				case 7:
					x_g = 2;
					y_g = 0;
					break;
				case 8:
					x_g = 2;
					y_g = 1;
					break;
				case 0:
					x_g = x;
					y_g = y;
					break;
				}
				while (x != x_g){
					if (x > x_g){
						x = x - 1;
						m4++;
					}
					else if (x < x_g){
						x = x + 1;
						m4++;
					}
				}
				while (y != y_g){
					if (y>y_g){
						y = y - 1;
						m4++;
					}
					else if (y < y_g){
						y = y + 1;
						m4++;
					}
				}
			}
		}
		printf("M4=%d\n\n", m4);

		//�Ֆʂ̕ێ�
		for (m = 0; m < 3; m++){
			for (n = 0; n < 3; n++){
				box_up[m][n] = box[m][n];
				printf("%d ", box[m][n]);
			}
			printf("\n");
		}
		printf("\n");

		//�p�Y�������ւ���O�̏�Ԃɖ߂�
		box[x_0 + 1][y_0] = box[x_0][y_0];
		box[x_0][y_0] = 0;

		printf("\n");

		//�e�}���n�b�^�������̑��a�Ɍo�H�R�X�g�𑫂�
		printf("---COST---\n\n");
		f1 = g + m1;
		f2 = g + m2;
		f3 = g + m3;
		f4 = g + m4;

		printf("f1=%d\nf2=%d\nf3=%d\nf4=%d\n", f1, f2, f3, f4);

		printf("\n");

		if (f1 < f2 && f1 < f3 && f1 < f4){
			for (m = 0; m < 3; m++){
				for (n = 0; n < 3; n++){
					box[m][n] = box_up[m][n];
					printf("%d ", box[m][n]);
				}
				printf("\n");
			}
		}
		


	//}
}