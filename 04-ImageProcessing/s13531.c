#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main() {

	FILE *IMG_1_main, *IMG_1_match, *IMG_2_main, *IMG_2_match;

	int yy = 0, xx = 0, k = 0, l = 0;
	int R_sad = 0;						//�ގ��x
	int R_sad_min,min_X,min_Y;			//�ގ��x�̍ŏ�,���̎��̍��W
	//��f�l�ۑ��p�̔z��쐬
	int img_1[512][512], img_2[512][512], Timg_1[200][200], Timg_2[136][215];

	//�e�L�X�g�t�@�C���ǂݍ���
	fopen_s(&IMG_1_main, "img_data_1.txt", "r");
	fopen_s(&IMG_1_match, "Timg_data_1.txt", "r");
	fopen_s(&IMG_2_main, "img_data_2.txt", "r");
	fopen_s(&IMG_2_match, "Timg_data_1.txt", "r");

	/******************************************************************/
	//�t�@�C�����̃f�[�^��z��Ɉړ�

	/***������***/

	/******************************************************************/
	//img_1 ����
	R_sad_min = 10200000;		//�ގ��x�@�����l�ݒ�
	printf("img_1 ���ʊJ�n");
	for (yy = 0; yy < 312; yy++) {				//img_1 Y���W�ړ��͈́@512-200
		for (xx = 0; xx < 312; xx++){			//img_1 X���W�ړ��͈́@512-200
			R_sad = 0;
			for (k = 0; k < 200; k++){			//img_1 �}�b�`���O�@200*200
				for (l = 0; l < 200; l++) {
					if (img_1[yy+k][xx+l] != Timg_1[k][l]) { R_sad = R_sad+255; }
				}
			}
			printf("���WI(%d�C%d)�@�ގ����ʊ��� %d\n",xx+1,yy+1,R_sad);
			if (R_sad_min > R_sad) {			//�ގ��x�ō��@����
				R_sad_min = R_sad;
				min_X = xx;
				min_Y = yy;
			}
		}
	}
	//�}�b�`���O���W�\��
	printf("���ʁ@I( %d�C%d )\n", min_X, min_Y);
	/******************************************************************/
	//img_2 ����
	printf("img_2 ���ʊJ�n");
	R_sad_min = 7456200;		//�ގ��x�@�����l�ݒ�
	for (yy = 0; yy < 376; yy++) {				//img_2 Y���W�ړ��͈́@512-136
		for (xx = 0; xx < 297; xx++) {			//img_2 X���W�ړ��͈́@512-215
			R_sad = 0;
			for (k = 0; k < 136; k++) {			//img_2 �}�b�`���O�@215*136
				for (l = 0; l < 215; l++) {
					R_sad = R_sad + abs(img_2[yy+k][xx+l]-Timg_2[k][l]);//���̐�Βl�̘a�@�v�Z
				}
			}
			printf("���WI(%d�C%d)�@�ގ����ʊ��� %d\n",xx+1,yy+1,R_sad);
			if (R_sad_min > R_sad) {			//�ގ��x�ō��@����
			R_sad_min = R_sad;
			min_X = xx;
			min_Y = yy;
			}
		}

	}
	//�}�b�`���O���W�\��
	printf("���ʁ@I( %d�C%d )\n", min_X, min_Y);
	/******************************************************************/

	fclose(IMG_1_main);
	fclose(IMG_1_match);
	fclose(IMG_2_main);
	fclose(IMG_2_match);
}