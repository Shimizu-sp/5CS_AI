#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int i, j,k,l;
int ue(int uei, int uej);
int migi(int migii, int migij);
int hidari(int hidarii, int hidarij);
int shita(int sihitai, int shitaj);

int b[3][3] = {{1,2,3},
			   {4,5,6},
			   {7,8,9}}; /*�ŏI�I��8�p�Y���̌`*/
int a[3][3] = {{8,1,5},
			   {2,9,4},
			   {6,3,7}}; /*�ۑ��8�p�Y���̏������*/

int save[3][3];/*�ꎞ�ۊǂ���z��*/
int nowue[3][3];/*���ꂼ��̕����̌��ݏ�Ԃ�ۊǂ���z��*/
int nowmigi[3][3];
int nowhidari[3][3];
int nowshita[3][3];

int man, h=0, y, x;
int Fue = 0, Fmigi = 0, Fhidari = 0, Fshita = 0; /*���ꂼ��̕����̔����I�֐�*/

FILE *file;


int main(){

	int end = 0;

	/*������*/
    int upi = 0, upj = 0;
	int righti = 0, rightj = 0;
	int lefti = 0, leftj = 0;
	int downi = 0, downj = 0;

	file = fopen("����.txt","w");

	printf("\n�������\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
	fprintf(file,"\n�������\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);

	for(end=0; end<1;){ /*����end��0�Ȃ�p�Y�����X���C�h��������*/

		printf("--------------------\n");
		fprintf(file,"--------------------\n");

		/*-------------------------------------�����I�֐��̌v�Z��------------------------------------------*/

		for(i=0;i<3;i++){
			for(j=0;j<3;j++){

				for(k=0;k<3;k++){
					for(l=0;l<3;l++){
						save[k][l] = a[k][l]; /*���ݏ�Ԃ̔z���ۑ�*/
					}
				}
				
				if(a[i][j] == 9 && a[i-1][j]<9){ /*����������9(��)�ŏオ9��菬����������*/

					a[i][j] = a[i-1][j];/*�󔒂ɏ�̒l���㏑��*/
					a[i-1][j] = 9;/*���9(��)������*/
					Fue = ue(upi, upj); 
					Fue = Fue + 1;/*�R�X�g�v�Z*/
					printf("�����I�֐�(��)�F%d\n",Fue);
					printf("%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"�����I�֐�(��)�F%d\n",Fue);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					h = 0;/*h��������*/

					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							nowue[k][l] = a[k][l];/*���ݏ�Ԃ�ۑ�*/
						}
					}
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = save[k][l];/*������*/
						}
					}

					x = 0; y = 0; /*������*/

				}
			}
		}



		for(i=0;i<3;i++){
			for(j=0;j<3;j++){

				for(k=0;k<3;k++){
					for(l=0;l<3;l++){
						save[k][l] = a[k][l]; /*���ݏ�Ԃ̔z���ۑ�*/
					}
				}

				if(a[i][j] == 9 && a[i][j+1]<9){ /*����������9(��)�ŉE��9��菬����������*/
					a[i][j] = a[i][j+1]; /*�󔒂ɉE�̒l���㏑��*/
					a[i][j+1] = 9; /*�E�ɋ󔒂�����*/

					Fmigi = migi(righti, rightj);
					Fmigi = Fmigi + 1;/*�R�X�g�v�Z*/
					printf("�����I�֐�(�E)�F%d\n",Fmigi);
					printf("%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"�����I�֐�(�E)�F%d\n",Fmigi);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					h = 0;/*h��������*/
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							nowmigi[k][l] = a[k][l];/*���ݏ�Ԃ�ۑ�*/
						}
					}
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = save[k][l];/*������*/
						}
					}
					x = 0; y = 0; /*������*/

				}
			}
		}



		for(i=0;i<3;i++){
			for(j=0;j<3;j++){

				for(k=0;k<3;k++){
					for(l=0;l<3;l++){
						save[k][l] = a[k][l]; /*���ݏ�Ԃ̔z���ۑ�*/
					}
				}

				if(a[i][j] == 9 && a[i][j-1]<9){ /*����������9(��)�ō���9��菬����������*/
					a[i][j] = a[i][j-1]; /*�󔒂ɍ��̒l���㏑��*/
					a[i][j-1] = 9; /*���ɋ󔒂�����*/
					Fhidari = hidari(lefti, leftj);
					Fhidari = Fhidari + 1; /*�R�X�g�v�Z*/
					printf("�����I�֐�(��)�F%d\n",Fhidari);
					printf("%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"�����I�֐�(��)�F%d\n",Fhidari);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					h = 0; /*������*/
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							nowhidari[k][l] = a[k][l];/*���ݏ�Ԃ�ۑ�*/
						}
					}
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = save[k][l];/*������*/
						}
					}
					x = 0; y = 0; /*������*/

				}
			}
		}



		for(i=0;i<3;i++){
			for(j=0;j<3;j++){

				for(k=0;k<3;k++){
					for(l=0;l<3;l++){
						save[k][l] = a[k][l]; /*���ݏ�Ԃ̔z���ۑ�*/
					}
				}

				if(a[i][j] == 9 && a[i+1][j]<9){ /*����������9(��)�ŉ���9��菬����������*/
					a[i][j] = a[i+1][j]; /*�󔒂ɉ��̒l���㏑��*/
					a[i+1][j] = 9; /*���ɋ󔒂�����*/
					Fshita = shita(downi, downj);
					Fshita = Fshita + 1; /*�R�X�g�v�Z*/
					h = 0;/*������*/					
					printf("�����I�֐�(��)�F%d\n",Fshita);
					printf("%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"�����I�֐�(��)�F%d\n",Fshita);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							nowshita[k][l] = a[k][l];/*���ݏ�Ԃ�ۑ�*/
						}
					}
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = save[k][l];/*������*/
						}
					}
					x = 0; y = 0; /*������*/

				}
			}
		}

		/*-------------------------------------�����I�֐��̌v�Z��------------------------------------------*/

		/*-----------------------------------------�ŏ���I�ԁ�--------------------------------------------*/
		
				if(Fue<Fmigi && Fue<Fhidari && Fue<Fshita){ /*������ɃX���C�h�����Ƃ��̔����I�֐�����ԏ�����������*/
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = nowue[k][l];/*��ɃX���C�h�����Ƃ��̔z��ɍX�V*/
						}
					}
					printf("\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
				}



				else if(Fmigi<Fue && Fmigi<Fhidari && Fmigi<Fshita){ /*�����E�ɃX���C�h�����Ƃ��̔����I�֐�����ԏ�����������*/		
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = nowmigi[k][l];/*��ɃX���C�h�����Ƃ��̔z��ɍX�V*/
						}
					}
					printf("\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
				}



				else if(Fhidari<Fue && Fhidari<Fmigi && Fhidari<Fshita){ /*�������ɃX���C�h�����Ƃ��̔����I�֐�����ԏ�����������*/
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = nowhidari[k][l];/*��ɃX���C�h�����Ƃ��̔z��ɍX�V*/
						}
					}
					printf("\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
				}



				else if(Fshita<Fue && Fshita<Fmigi && Fshita<Fhidari){ /*�������ɃX���C�h�����Ƃ��̔����I�֐�����ԏ�����������*/
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = nowshita[k][l];/*��ɃX���C�h�����Ƃ��̔z��ɍX�V*/
						}
					}
					printf("\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
				}

				

				/*-----------------------------------------�ŏ���I�ԁ�-----------------------------------------------*/

		for(k=0;k<3;k++){
			for(l=0;l<3;l++){
				if(a[k][l] == b[k][l]){/*�����p�Y�����I�������Aend��1�𑫂�*/
					end = end + 1;
				}
			}
			return 0; /*�v���O�������������Ă��Ȃ��̂ŁA���[�v���Ă��܂��̂ł����Ŏ~�߂�*/
		}

	}

	fclose(file);
	return 0;

}


int ue(int uei, int uej){
	/* ----------------------- h(p) --------------------------- */
	for(i=0; i<3; i++){

	 /*j�̒l��������*/
		for(j=0; j<3; j++){

			 /*�}���n�b�^������*/
				switch(a[i][j]){
					case 1:
						x = j - 0;
						y = i - 0;
						break;
					case 2:
						x = j - 1;
						y = i - 0;
						break;
					case 3:
						x = j - 2;
						y = i - 0;
						break;
					case 4:
						x = j - 0;
						y = i - 1;
						break;
					case 5:
						x = j - 1;
						y = i - 1;
						break;
					case 6:
						x = j - 2;
						y = i - 1;
						break;
					case 7:
						x = j - 0;
						y = i - 2;
						break;
					case 8:
						x = j - 1;
						y = i - 2;
						break;
					case 9:
						x = 0;
						y = 0;
						break;
				} 

				man = abs(x)+abs(y); /*�}���n�b�^�����������ꂼ�ꑫ���Ă���*/
				h = man + h; /*�}���n�b�^�������̑��a*/
				/*printf("man�̒l�́A%d\n",man);*/		
	}
}
	printf("�}���n�b�^�������̑��a�́A%d\n",h);
	fprintf(file,"�}���n�b�^�������̑��a�́A%d\n",h);
	return h;
}

int migi(int migii, int migij){
	/* ----------------------- h(p) --------------------------- */
	for(i=0; i<3; i++){

	 /*j�̒l��������*/
		for(j=0; j<3; j++){

			 /*�}���n�b�^������*/
				switch(a[i][j]){
					case 1:
						x = j - 0;
						y = i - 0;
						break;
					case 2:
						x = j - 1;
						y = i - 0;
						break;
					case 3:
						x = j - 2;
						y = i - 0;
						break;
					case 4:
						x = j - 0;
						y = i - 1;
						break;
					case 5:
						x = j - 1;
						y = i - 1;
						break;
					case 6:
						x = j - 2;
						y = i - 1;
						break;
					case 7:
						x = j - 0;
						y = i - 2;
						break;
					case 8:
						x = j - 1;
						y = i - 2;
						break;
					case 9:
						x = 0;
						y = 0;
						break;
				} 

				man = abs(x)+abs(y); /*�}���n�b�^�����������ꂼ�ꑫ���Ă���*/
				h = man + h; /*�}���n�b�^�������̑��a*/
				/*printf("man�̒l�́A%d\n",man);*/		
	}
}
	printf("�}���n�b�^�������̑��a�́A%d\n",h);
	fprintf(file,"�}���n�b�^�������̑��a�́A%d\n",h);
	return h;
}

int hidari(int hidarii, int hidarij){
	/* ----------------------- h(p) --------------------------- */
	for(i=0; i<3; i++){

	 /*j�̒l��������*/
		for(j=0; j<3; j++){

			 /*�}���n�b�^������*/
				switch(a[i][j]){
					case 1:
						x = j - 0;
						y = i - 0;
						break;
					case 2:
						x = j - 1;
						y = i - 0;
						break;
					case 3:
						x = j - 2;
						y = i - 0;
						break;
					case 4:
						x = j - 0;
						y = i - 1;
						break;
					case 5:
						x = j - 1;
						y = i - 1;
						break;
					case 6:
						x = j - 2;
						y = i - 1;
						break;
					case 7:
						x = j - 0;
						y = i - 2;
						break;
					case 8:
						x = j - 1;
						y = i - 2;
						break;
					case 9:
						x = 0;
						y = 0;
						break;
				} 

				man = abs(x)+abs(y); /*�}���n�b�^�����������ꂼ�ꑫ���Ă���*/
				h = man + h; /*�}���n�b�^�������̑��a*/
				/*printf("man�̒l�́A%d\n",man);*/		
	}
}
	printf("�}���n�b�^�������̑��a�́A%d\n",h);
	fprintf(file,"�}���n�b�^�������̑��a�́A%d\n",h);
	return h;
}

int shita(int sihitai, int shitaj){
	/* ----------------------- h(p) --------------------------- */
	for(i=0; i<3; i++){

	 /*j�̒l��������*/
		for(j=0; j<3; j++){

			 /*�}���n�b�^������*/
				switch(a[i][j]){
					case 1:
						x = j - 0;
						y = i - 0;
						break;
					case 2:
						x = j - 1;
						y = i - 0;
						break;
					case 3:
						x = j - 2;
						y = i - 0;
						break;
					case 4:
						x = j - 0;
						y = i - 1;
						break;
					case 5:
						x = j - 1;
						y = i - 1;
						break;
					case 6:
						x = j - 2;
						y = i - 1;
						break;
					case 7:
						x = j - 0;
						y = i - 2;
						break;
					case 8:
						x = j - 1;
						y = i - 2;
						break;
					case 9:
						x = 0;
						y = 0;
						break;
				} 

				man = abs(x)+abs(y); /*�}���n�b�^�����������ꂼ�ꑫ���Ă���*/
				h = man + h; /*�}���n�b�^�������̑��a*/
				/*printf("man�̒l�́A%d\n",man);*/		
	}
}
	printf("�}���n�b�^�������̑��a�́A%d\n",h);
	fprintf(file,"�}���n�b�^�������̑��a�́A%d\n",h);
	return h;
}