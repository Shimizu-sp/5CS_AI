#include <stdio.h>
#include <stdlib.h>
int pn[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };

main(){
	//-------------������`------------
	int p[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } };
	int pnow[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } };
	int p_patern[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
	int ma[4] = { 0, 0, 0, 0 };
	int gp, i, i2, patern = 4 , pt, min, min_i,flag;//g(p):�^�C���X���C�h��
	gp = 0;

	while (1){
		gp++;

		printf("���݂̃p�Y����\n");
		for (i = 0; i < 3; i++){
			for (i2 = 0; i2 < 3; i2++){
				printf("%d ", pnow[i][i2]);
			}
			printf("\n");
		}

		for (i = 0; i < 4; i++){
			ma[i] = 0;
		}

		//����ւ���
		for (pt = 0; pt < patern; pt++){
			flag = 0;//flag�̏�����
			//p_patern�ɑ����
			for (i = 0; i < 3; i++){
				for (i2 = 0; i2 < 3; i2++){
					p_patern[i][i2] = pnow[i][i2];
				}
			}
			for (i = 0; i < 3; i++){
				for (i2 = 0; i2 < 3; i2++){
					if (pnow[i][i2] == 0){
						if (pt == 0&&i2+1<3){//�E�Ɉړ�
							p_patern[i][i2] = pnow[i][i2 + 1];
							p_patern[i][i2 + 1] = 0;
							flag = 1;
						}
						if (pt == 1&&i2-1>=0){//���Ɉړ�
							p_patern[i][i2] = pnow[i][i2 - 1];
							p_patern[i][i2 - 1] = 0;
							flag = 1;
						}
						if (pt == 2&&i+1<3){//���Ɉړ�
							p_patern[i][i2] = pnow[i + 1][i2];
							p_patern[i + 1][i2] = 0;
							flag = 1;
						}
						if (pt == 3&&i-1>=0){//��Ɉړ�
							p_patern[i][i2] = pnow[i - 1][i2];
							p_patern[i - 1][i2] = 0;
							flag = 1;
						}
					}
				}
			}
			//---------�\��---------
			for (i = 0; i < 3; i++){
				for (i2 = 0; i2 < 3; i2++){

					printf("%d ", p_patern[i][i2]);
				}
				printf("\n");
			}
			printf("\n");

			/*----�}���n�b�^������-----*/
			if (flag == 1){
				ma[pt] = Manhattan(p_patern);
			}
			else{
				ma[pt] = 100;
			}
			printf("�p�^�[��%d�ڂ̃}���n�b�^��=%d\n", pt + 1, ma[pt]);
		}


		/*--pnow�X�V--*/
		for (i = 0; i < 4; i++){
			if (i == 0){
				min = ma[i];
				min_i = i;
			}
			else if (min > ma[i]){
				min = ma[i];
				min_i = i;
			}
		}

		printf("min_i=%d\n", min_i);

		//p_patern�ɑ����
		for (i = 0; i < 3; i++){
			for (i2 = 0; i2 < 3; i2++){
				p_patern[i][i2] = pnow[i][i2];
			}
		}
		for (i = 0; i < 3; i++){
			for (i2 = 0; i2 < 3; i2++){
				if (pnow[i][i2] == 0){
					if (min_i == 0&&i2+1<3){
						p_patern[i][i2] = pnow[i][i2 + 1];
						p_patern[i][i2 + 1] = 0;
					}
					if (min_i == 1&&i2-1>=0){
						p_patern[i][i2] = pnow[i][i2 - 1];
						p_patern[i][i2 - 1] = 0;
					}
					if (min_i == 2&&i+1<3){
						p_patern[i][i2] = pnow[i + 1][i2];
						p_patern[i + 1][i2] = 0;
					}
					if (min_i == 3&&i-1>=0){
						p_patern[i][i2] = pnow[i - 1][i2];
						p_patern[i - 1][i2] = 0;
					}
				}
			}
		}

		/*---���݂̃p�Y���\��----*/
		for (i = 0; i < 3; i++){
			for (i2 = 0; i2 < 3; i2++){
				pnow[i][i2] = p_patern[i][i2];
				printf("%d ", pnow[i][i2]);
			}
			printf("\n");
		}
		printf("\n");

		/*---�S�[����ԁipn�j���̔��f---*/
		printf("\ngp=%d\n\n",gp);
		if (pnow ==pn ){
			break;
		}

	}
}
int Manhattan(int input[3][3]){ 		/*--�}���n�b�^�������̌v�Z--*/
	int M,i3,i4,i5,i6,i7;
	M = 0;
	for (i5 = 1; i5 < 9;i5++){
		for (i3 = 0; i3 < 3; i3++){
			for (i4 = 0; i4 < 3; i4++){
				if (input[i3][i4]==i5){
					for (i6 = 0; i6 < 3; i6++){
						for (i7 = 0; i7 < 3; i7++){
							if (pn[i6][i7]==i5){
								M = M + abs(i3 - i6) + abs(i4 - i7);
							}
						}
					}
				}
			}
		}
	}

	return M;
}