#include <stdio.h>

int main(int  argc, char*argv[])
{
	int  Pst[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } };
	int  Pgo[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };
	int  PL[3][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	int  PU[3][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	int  PR[3][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	int  PD[3][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	int MHT = 0;
	int X = 0;//0�̈ʒu��ۑ�(�s)
	int Y = 0; //0�̈ʒu��ۑ�(��)
	int X2 = 0;
	int Y2 = 0;
	int End =0,End2=0;
	int c1 = 0, c2 = 0;//�J�E���g
	int zero_left = 0;
	int zero_up = 0;
	int zero_right = 0;
	int zero_down = 0;
	int tmp = 0;
	int arien = -1;
	int Count = 0;
	int Xs = 0, Ys = 0;
	int C = 0;
	///////////////////////////////////////////////////////////////////////////////////////////////////

	//�����\��
	printf("�����̏��             �S�[�����\n");
	for (int PreG = 0; PreG < 3; PreG++) {
		for (int PreR = 0; PreR < 3; PreR++) {
			printf(" %d ", Pst[PreG][PreR]);

		}
		printf("		");
		for (int PreR = 0; PreR < 3; PreR++) {
			printf(" %d ", Pgo[PreG][PreR]);

		}
		printf("\n");

	}
	//�����\���I���

	///////////////////////////////////////////////////////////////////////////////////////////////////

	//0��T��
	for (c1 = 0; c1 < 3; c1++) {
		for (c2 = 0; c2 < 3; c2++) {
			if (Pst[c1][c2] == 0) {

				X = c1;
				Y = c2;

				printf("���݂�0�̈ʒu��T���܂�\n�s=%d  ��=%d\n\n",X+1,Y+1);
				
				End = 1;
				break;
			}
			if (End == 1) {
				break;
			}

		}

		if (End == 1) {
			break;
		}
	}
	if (End == 0) {
		printf("0�������ĂȂ����\n\n");
		exit();
	}

	End = 0;
	//0�T���I���

	//////////////////////////////////////////////////////////////////////////////////////////////////

	//0�̎���̏��擾
	if (X == 0) {	//��i�̏ꍇ

		zero_up = arien;//X=0���オ�Ȃ����Ƃ͊m��

		if (Y == 1) {
			zero_left = Pst[X][Y - 1];
			zero_right = Pst[X][Y + 1];
			zero_down = Pst[X + 1][Y];
		}
		else if (Y == 0) {
			zero_left = arien;
			zero_right = Pst[X][Y + 1];
			zero_down = Pst[X + 1][Y];
		}
		else if (Y == 2) {
			zero_left = Pst[X][Y - 1];
			zero_right = arien;
			zero_down = Pst[X + 1][Y];
		}

	}
	else if (X == 1) {	//���i�̏ꍇ
		if (Y == 1) {
			zero_left = Pst[X][Y - 1];
			zero_up = Pst[X - 1][Y];
			zero_right = Pst[X][Y + 1];
			zero_down = Pst[X + 1][Y];
		}
		else if (Y == 0) {
			zero_left = arien;
			zero_up = Pst[X - 1][Y];
			zero_right = Pst[X][Y + 1];
			zero_down = Pst[X + 1][Y];
		}
		else if (Y == 2) {
			zero_left = Pst[X][Y - 1];
			zero_up = Pst[X - 1][Y];
			zero_right = arien;
			zero_down = Pst[X + 1][Y];
		}
		
	}
	else if (X == 2) {	//���i�̏ꍇ

		zero_down = arien;//X=0��艺���Ȃ����Ƃ͊m��

		if (Y == 1) {
			zero_left = Pst[X][Y - 1];
			zero_right = Pst[X][Y + 1];
			zero_up = Pst[X-1][Y];
		}
		else if (Y == 0) {
			zero_left = arien;
			zero_right = Pst[X][Y + 1];
			zero_up = Pst[X - 1][Y];
		}
		else if (Y == 2) {
			zero_left = Pst[X][Y - 1];
			zero_right = arien;
			zero_up = Pst[X - 1][Y];
		}

	}


	if (zero_left==-1) {
		printf("0�̍���...�Ȃ��ł�\n");
	}
	else {
		printf("0�̍���...%d\n", zero_left);
	}
		if (zero_up == -1) {
			printf("0�̏��...�Ȃ��ł�\n");
		}else{
			printf("0�̏��...%d\n", zero_up);

		}if (zero_right == -1) {
			printf("0�̉E��...�Ȃ��ł�\n");
		}
		else {
			printf("0�̉E��...%d\n", zero_right);
		}if (zero_down == -1) {
			printf("0�̉���...�Ȃ��ł�\n");
		}else {
			printf("0�̉���...%d\n\n", zero_down);


		


	}

		//�}���n�b�^�������v������

		if (zero_left != -1) { //���ɃV�t�g�\�Ȃ�v�Z�J�n
			for (int PreG = 0; PreG < 3; PreG++) {
				for (int PreR = 0; PreR < 3; PreR++) {
					PL[PreG][PreR] = Pst[PreG][PreR];
				}
			}

			tmp = Pst[X][Y - 1];
			PL[X][Y] = tmp;

			PL[X][Y - 1] = 0;
			tmp = 0;
			//���Ƃ̓���ւ��I��(�z��PL)
		}
		if (zero_up != -1) { //��ɃV�t�g�\�Ȃ�v�Z�J�n
			for (int PreG = 0; PreG < 3; PreG++) {
				for (int PreR = 0; PreR < 3; PreR++) {
					PU[PreG][PreR] = Pst[PreG][PreR];
				}
			}

			tmp = Pst[X-1][Y];
			PU[X][Y] = tmp;

			PU[X-1][Y] = 0;
			tmp = 0;
			//��Ƃ̓���ւ��I��(�z��PU)
		}
		if (zero_right != -1) { //�E�ɃV�t�g�\�Ȃ�v�Z�J�n
			for (int PreG = 0; PreG < 3; PreG++) {
				for (int PreR = 0; PreR < 3; PreR++) {
					PR[PreG][PreR] = Pst[PreG][PreR];
				}
			}

			tmp = Pst[X][Y + 1];
			PR[X][Y] = tmp;

			PR[X][Y+1] = 0;
			tmp = 0;
			//�E�Ƃ̓���ւ��I��(�z��PR)
		}
		if (zero_down != -1) { //���ɃV�t�g�\�Ȃ�v�Z�J�n
			for (int PreG = 0; PreG < 3; PreG++) {
				for (int PreR = 0; PreR < 3; PreR++) {
					PD[PreG][PreR] = Pst[PreG][PreR];
				}
			}

			tmp = Pst[X+1][Y];
			PD[X][Y] = tmp;

			PD[X+1][Y] = 0;
			tmp = 0;
			//���Ƃ̓���ւ��I��(�z��PD)
		}
		else {
			printf("�G���[");
		}



			//�e������T���ăS�[����ԂƓ����ɂȂ�悤�Ɉړ�
			//SeachAndMove(Xs,Ys);
			/*for (C = 1; C <= 9; C++) {
				for (c1 = 0; c1 < 3; c1++) {
					for (c2 = 0; c2 < 3; c2++) {
						if (Pst[c1][c2] == C) {

							End = 0;

							X = c1;
							Y = c2;


							printf("���݂�%d�̈ʒu��T���܂�\n�s=%d  ��=%d\n\n", C, X + 1, Y + 1);
							

									X2 = c1;
									Y2 = c2;
									printf("�S�[����%d�̈ʒu��T���܂�\n�s=%d  ��=%d\n\n", C, X2 + 1, Y2 + 1);
									End2 = 1;
									
				


						}
					}





				}

			}*/


		

				//�}���n�b�^���I���

			//�\��
				Count++;
				printf("��������%d���\n", Count);
				printf("���݂̏��             �S�[�����\n");
				for (int PreG = 0; PreG < 3; PreG++) {
					for (int PreR = 0; PreR < 3; PreR++) {
						printf(" %d ", Pst[PreG][PreR]);

					}
					printf("		");
					for (int PreR = 0; PreR < 3; PreR++) {
						printf(" %d ", Pgo[PreG][PreR]);

					}
					printf("\n");

				}
				//�\���I���

			}



		
