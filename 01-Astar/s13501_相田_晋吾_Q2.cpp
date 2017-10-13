// A_starALGORITHM.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>


//�}���n�b�^�������v�Z�֐�
int Manhattan_Distance(int Puzzle[][3]) {

	int Goal[3][3]{ { 1, 2, 3 },				//�p�Y���̃S�[�����
	{ 4, 5, 6 },
	{ 7, 8, 0 }
	};



	int x_dist = 0;
	int y_dist = 0;

	int Tortal_M_dist = 0;		//���v�}���n�b�^�������v�Z�p

								//	 while (Puzzle != Goal){		//�p�Y���̌��ݏ�ԂƃS�[����Ԃ����S��v����܂Ń��[�v

								//�}���n�b�^�������̌v�Z�J�n
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			int a = Puzzle[i][j];		//��[j+1]�ԖځA �c[i+1]�Ԗڂ̌��݃p�Y���̐��l��[a]�ɑ��
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (a == Goal[k][l] && a != 0) {	//�������A����ƃS�[���̒l����v�A���u�����N�ł͖����ꏊ�𔭌������ꍇ
						x_dist = j - l;	//���̃Y�����v�Z
						y_dist = i - k;	//�c�̃Y�����v�Z

						if (x_dist < 0)		//jl_dist��0������������
							x_dist *= (-1);	//jl_dist��-1���|����(������+��)

						if (y_dist < 0)		//ik_dist��0������������
							y_dist *= (-1);	//ik_dist��-1���|����(������+��)

						Tortal_M_dist += x_dist + y_dist;				//[���̃Y��]+[�c�̃Y��] = [a]�̃}���n�b�^������

					}
				}
			}


		}

	}			//�}���n�b�^�������̌v�Z����

	return Tortal_M_dist;	//���v�}���n�b�^��������Ԃ�
}




int _tmain(int argc, _TCHAR* argv[])
{
	int Puzzle[3][3]{ { 8, 1, 5 },			//�p�Y�����ݏ��(0�͋󂫋�ԂƂ���)
	{ 2, 0, 4 },
	{ 6, 3, 7 }
	};

	int Goal[][3]{ { 1, 2, 3 },			//�p�Y���̃S�[�����
	{ 4, 5, 6 },
	{ 7, 8, 0 }
	};

	int Tem_Save[3][3];						//�p�Y���ꎞ�ۑ��p

	int Safe_ID;							//����ŏ��R�X�g�̃p�Y��ID�ꎟ�ۑ��p

	int f;									//�ŏ��R�X�g(g+h)
	int g = 0;								//���ݏ�Ԃ܂ł̃R�X�g
	int h[2];									//���ݏ�Ԃ���S�[���܂ł̐���ŏ��R�X�g

	int zero_x = 0;								//�u�����N(0)��x���W�ۑ��p
	int zero_y = 0;								//�u�����N(0)��y���W�ۑ��p

	std::ofstream ofs("�v�Z����.txt",std::ios_base::out);
	if (! ofs) {
		std::cerr << "error" << std::endl;
		std::exit(EXIT_FAILURE);
	}

		h[0] = 200;		//����ŏ��R�X�g��������
		h[1] = 0;		//�v�Z�R�X�g��������
		Safe_ID = 0;

		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {

				Tem_Save[y][x] = Puzzle[y][x];	//�ꎟ�ۑ��p�ɁA���݂̏�Ԃ��R�s�[

				if (Puzzle[y][x] == 0) {		//�u�����N(0)�����o�����ꍇ
					zero_x = x;
					zero_y = y;				//�u�����N�̍��W��ۑ����Ă���
				}

			}
		}			//�R�s�[�ƃu�����N�̈ʒu����o���I��

					////////////////////////////
					//  �ŏ��R�X�g�̊���o��  //
					////////////////////////////

		if (zero_x <= 1) {	//0���E�ɃX���C�h�ł���ꍇ
			Tem_Save[zero_y][zero_x] = Puzzle[zero_y][zero_x + 1];
			Tem_Save[zero_y][zero_x + 1] = 0;
			h[1] = Manhattan_Distance(Tem_Save);

			printf("���X���C�h = %d\n", h[1]);

			if (h[0] > h[1]) {	//����ŏ��R�X�g���R�X�g���Ⴉ�����ꍇ
				h[0] = h[1];
				Safe_ID = 1;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						Tem_Save[i][j] = Puzzle[i][j];	//�ꎟ�ۑ��p�ɁA���݂̏�Ԃ��R�s�[
					}
				}

			}

		}

		if (zero_x >= 1) {	//0�����ɃX���C�h�ł���ꍇ
			Tem_Save[zero_y][zero_x] = Puzzle[zero_y][zero_x - 1];
			Tem_Save[zero_y][zero_x - 1] = 0;
			h[1] = Manhattan_Distance(Tem_Save);

			printf("�E�X���C�h = %d\n", h[1]);
			if (h[0] > h[1]) {	//����ŏ��R�X�g���R�X�g���Ⴉ�����ꍇ
				h[0] = h[1];
				Safe_ID = 2;
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Tem_Save[i][j] = Puzzle[i][j];	//�ꎟ�ۑ��p�ɁA���݂̏�Ԃ��R�s�[
				}
			}
		}

		if (zero_y >= 1) {	//0����ɃX���C�h�ł���ꍇ
			Tem_Save[zero_y][zero_x] = Puzzle[zero_y - 1][zero_x];
			Tem_Save[zero_y - 1][zero_x] = 0;
			h[1] = Manhattan_Distance(Tem_Save);

			printf("���X���C�h = %d\n", h[1]);

			if (h[0] > h[1]) {	//����ŏ��R�X�g���R�X�g���Ⴉ�����ꍇ
				h[0] = h[1];
				Safe_ID = 3;
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Tem_Save[i][j] = Puzzle[i][j];	//�ꎟ�ۑ��p�ɁA���݂̏�Ԃ��R�s�[
				}
			}
		}

		if (zero_y <= 1) {	//0�����ɃX���C�h�ł���ꍇ
			Tem_Save[zero_y][zero_x] = Puzzle[zero_y + 1][zero_x];
			Tem_Save[zero_y + 1][zero_x] = 0;
			h[1] = Manhattan_Distance(Tem_Save);

			printf("��X���C�h = %d\n", h[1]);

			if (h[0] > h[1]) {	//����ŏ��R�X�g���R�X�g���Ⴉ�����ꍇ
				h[0] = h[1];
				Safe_ID = 4;
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Tem_Save[i][j] = Puzzle[i][j];	//�ꎟ�ۑ��p�ɁA���݂̏�Ԃ��R�s�[
				}
			}
		}
		//����o������

		//ID����ɁA�p�Y�����X���C�h������

		if (Safe_ID == 1) {
			Puzzle[zero_y][zero_x] = Puzzle[zero_y][zero_x + 1];
			Puzzle[zero_y][zero_x + 1] = 0;
			printf("�X���C�h����:��\n");
		}

		if (Safe_ID == 2) {
			Puzzle[zero_y][zero_x] = Puzzle[zero_y][zero_x - 1];
			Puzzle[zero_y][zero_x - 1] = 0;
			printf("�X���C�h����:�E\n");

		}

		if (Safe_ID == 3) {
			Puzzle[zero_y][zero_x] = Puzzle[zero_y - 1][zero_x];
			Puzzle[zero_y - 1][zero_x] = 0;
			printf("�X���C�h����:��\n");
		}

		if (Safe_ID == 4) {
			Puzzle[zero_y][zero_x] = Puzzle[zero_y + 1][zero_x];
			Puzzle[zero_y + 1][zero_x] = 0;
			printf("�X���C�h����:��\n");
		}


		//���݂̐���ŏ��R�X�g���v�Z
		f = g + h[0];

		printf("���݂̐���ŏ��R�X�g = %d\n", f);
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				ofs<<(Puzzle[y][x]) <<" ";
				if (Puzzle[y][x] != 0)
					printf("%d ", Puzzle[y][x]);
				else
					printf("  ");
			}
			printf("\n");
			ofs << "\n";
		}
		printf("\n");

		getchar();

		g++;			

		ofs << "\n";
		ofs << "����R�X�g:"<<f<< std::endl;



	return 0;
}


