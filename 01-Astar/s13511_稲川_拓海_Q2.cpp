#include<stdio.h>
#include<stdlib.h>

main(){

	//�ϐ���`
	int resul[3][3] = { { 1, 2, 3 },
						{ 4, 5, 6 },
						{ 7, 8, 0 } };

	int first[3][3] = { { 8, 1, 5 },
						{ 2, 0, 4 },
						{ 6, 3, 7 } };

	int manh[10] = { 1, 2, 2, 2, 2, 3, 2, 4 }; //�}���n�b�^������
	int kin[4];
	int min = 0; //�ŒZ�R�X�g
	int min_pazl = 0; //�ŏ��R�X�g�̎�
	int ireko0_1 = 0, ireko0_2 = 0; //�󂢂Ă����ԍ��W���L��
	int ireko1 = 0, ireko2 = 0;//���̑��̋�ԍ��W���L��

	int change1,change2; //�p�Y������ւ����̌����l�̍��W��ێ�
	
	int f = 0;
	int g = 0; //����ւ��񐔃J�E���g

	int i, j, k;
	int flug = 0; //�I���t���O
	int end = 0; //�����I���p
	int manh_i, manh_j;
	int kin1_1, kin1_2, kin2_1, kin2_2, kin3_1, kin3_2, kin4_1, kin4_2;//�󂢂Ă����Ԃɋߐڂ�����W���L��
	int manh_1 = 999, manh_2 = 999, manh_3 = 999, manh_4 = 999;
	int mang_1 = 999, mang_2 = 999, mang_3 = 999, mang_4 = 999;

	FILE *file1,*file2;

	/////////////////////////////////////////////
	////A*�A���S���Y����p�����u8�p�Y�����v///
	///////////////////////////////////////////

	//=========================================================

	fopen_s(&file1, "�p�Y�����.txt", "w"); //�t�@�C�����������ݐ�p�ɊJ��
	fopen_s(&file2, "�����I�֐�.txt", "w");

	do{

	//�z��first���"0"��T������
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (first[i][j] == 0){
				ireko0_1 = i;
				ireko0_2 = j;
				i = 999; //���d���[�v�E�o�p
				j = 999;
			}
		}
	}

	//0�̈ʒu�Ɏl���ŋߐڂ�����W�����߂�
	kin1_1 = ireko0_1 - 1; //��ŋߐڂ�����W���L�^
	kin1_2 = ireko0_2;

	kin2_1 = ireko0_1 + 1; //���ŋߐڂ�����W���L�^
	kin2_2 = ireko0_2;

	kin3_1 = ireko0_1;     //���ŋߐڂ�����W���L�^
	kin3_2 = ireko0_2 - 1;

	kin4_1 = ireko0_1;     //�E�ŋߐڂ�����W���L�^  
	kin4_2 = ireko0_2 + 1;


	//0�̈ʒu�Ɏl���ŋߐڂ���l���L��
	kin[0] = first[kin1_1][kin1_2];
	kin[1] = first[kin2_1][kin2_2];
	kin[2] = first[kin3_1][kin3_2];
	kin[3] = first[kin4_1][kin4_2];

	//=========================================================

	//=========================================================
	//=========================================================
	if (0 <= kin1_1 && kin1_1 < 3 && 0 <= kin1_2 && kin1_2 < 3){ //���W�ɒl�����݂��邩�𔻒�

		//�z��resul���"kin[0]"��T������
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (resul[i][j] == kin[0]){
					ireko1 = i;
					ireko2 = j;
					i = 999; //���d���[�v�E�o�p
					j = 999;
				}
			}
		}

		//�}���n�b�^�����������߂�
		manh_i = kin1_1 - ireko1;
		manh_j = kin1_2 - ireko2;

		manh_i = abs(manh_i); //��Βl�ɒ���
		manh_j = abs(manh_j);

		manh_1 = manh_i + manh_j;

		//�}���n�b�^������(���v)�����߂�
			mang_1 = 0;
		for (i = 0; i<10; i++){ //manh_1��manh[]�Ɋi�[�����e�}���n�b�^�����������Z����
			mang_1 = mang_1 + manh[i];
		}
			mang_1 = mang_1 - manh[kin[0] - 1];
			mang_1 = mang_1 + manh_1 + 1;
	}

	//======================================================

	if (0 <= kin2_1 && kin2_1 < 3 && 0 <= kin2_2 && kin2_2 < 3){ //���W�ɒl�����݂��邩�𔻒�

		//�z��resul���"kin[1]"��T������
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (resul[i][j] == kin[1]){
					ireko1 = i;
					ireko2 = j;
					i = 999; //���d���[�v�E�o�p
					j = 999;
				}
			}
		}

		//�}���n�b�^�����������߂�
		manh_i = kin2_1 - ireko1;
		manh_j = kin2_2 - ireko2;

		manh_i = abs(manh_i); //��Βl�ɒ���
		manh_j = abs(manh_j);

		manh_2 = manh_i + manh_j; //�}���n�b�^�������Z�o

		//�}���n�b�^������(���v)�����߂�
			mang_2 = 0;
		for (i = 0; i < 10; i++){ //manh_1��manh[]�Ɋi�[�����e�}���n�b�^�����������Z����
			mang_2 = mang_1 + manh[i];
		}
			mang_2 = mang_2 - manh[kin[1] - 1];
			mang_2 = mang_2 + manh_2 + 1;

	}

	//======================================================

	if (0 <= kin3_1 && kin3_1 < 3 && 0 <= kin3_2 && kin3_2 < 3){ //���W�ɒl�����݂��邩�𔻒�

		//�z��resul���"kin[2]"��T������
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (resul[i][j] == kin[2]){
					ireko1 = i;
					ireko2 = j;
					i = 999; //���d���[�v�E�o�p
					j = 999;
				}
			}
		}

		//�}���n�b�^�����������߂�
		manh_i = kin3_1 - ireko1;
		manh_j = kin3_2 - ireko2;

		manh_i = abs(manh_i); //��Βl�ɒ���
		manh_j = abs(manh_j);

		manh_3 = manh_i + manh_j;

		//�}���n�b�^������(���v)�����߂�
			mang_3 = 0;
		for (i = 0; i < 10; i++){ //manh_1��manh[]�Ɋi�[�����e�}���n�b�^�����������Z����
			mang_3 = mang_3 + manh[i];
		}
			mang_3 = mang_3 - manh[kin[1] - 1];
			mang_3 = mang_3 + manh_3 + 1;

	}

	//======================================================

	if (0 <= kin4_1 && kin4_1 < 3 && 0 <= kin4_2 && kin4_2 < 3){ //���W�ɒl�����݂��邩�𔻒�

		//�z��resul���"kin[3]"��T������
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (resul[i][j] == kin[3]){
					ireko1 = i;
					ireko2 = j;
					i = 999; //���d���[�v�E�o�p
					j = 999;
				}
			}
		}

		//�}���n�b�^�����������߂�
		manh_i = kin4_1 - ireko1;
		manh_j = kin4_2 - ireko2;

		manh_i = abs(manh_i); //��Βl�ɒ���
		manh_j = abs(manh_j);

		manh_4 = manh_i + manh_j;

		//�}���n�b�^������(���v)�����߂�
			mang_4 = 0;
		for (i = 0; i < 10; i++){ //manh_1��manh[]�Ɋi�[�����e�}���n�b�^�����������Z����
			mang_4 = mang_4 + manh[i];
		}
			mang_4 = mang_4 - manh[kin[1] - 1];
			mang_4 = mang_4 + manh_4 + 1;

	}
	//=========================================================
	//=========================================================

	//=========================================================
	
	//���߂��}���n�b�^������(���v)���ŏ��R�X�g�̎��I��
	min = mang_1; //manh_1���Ƃ肠�����̍ŏ��R�X�g�Ƃ���
	min_pazl = kin[0];
	change1 = kin1_1;
	change2 = kin1_2;

	if (min > mang_2){ //manh_1���manh_2�̕����R�X�g���������Ƃ��V���ȍŏ��R�X�g�Ƃ���
		min = mang_2;
		min_pazl = kin[1];
		change1 = kin2_1; 
		change2 = kin2_2;

	}if (min > mang_3){ //min���manh_3�̕����R�X�g���������Ƃ��V���ȍŏ��R�X�g�Ƃ���
		min = mang_3;
		min_pazl = kin[2];
		change1 = kin3_1;
		change2 = kin3_2;

	}if (min > mang_4){ //min3���manh_4�̕����R�X�g���������Ƃ��V���ȍŏ��R�X�g�Ƃ���
		min = mang_4;
		min_pazl = kin[3];
		change1 = kin4_1;
		change2 = kin4_2;
	}

	//=========================================================

	first[ireko0_1][ireko0_2] = min_pazl; //�ŏ��R�X�g�̎����Ԉʒu�ɓ�����
	first[change1][change2] = 0;

    g = g + 1; //����ւ��񐔂��J�E���g

	f = min + g; //�����I�֐��̌v�Z

	//=========================================================

	fprintf(file1, "%d %d %d\n", first[0][0], first[0][1], first[0][2]);
	fprintf(file1, "%d %d %d\n", first[1][0], first[1][1], first[1][2]);
	fprintf(file1, "%d %d %d\n\n", first[2][0], first[2][1], first[2][2]);

	fprintf(file2, "%d\n",f);

	//=========================================================

	//�z��resul���"kin[3]"��T������
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (resul[i][j] != first[i][j]){
				i = 999; //���d���[�v�E�o�p
				j = 999;
				flug = 0;
			
			}else{
				flug = flug + 1;
	}}}

	if(end == 100){ //100�������狭���I��
		flug = 9;
	}

	end = end + 1;

	}while(flug != 9);

	fclose(file1); //�t�@�C�������
	fclose(file2);


}

