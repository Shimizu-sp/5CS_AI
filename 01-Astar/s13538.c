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
			   {7,8,9}}; /*最終的な8パズルの形*/
int a[3][3] = {{8,1,5},
			   {2,9,4},
			   {6,3,7}}; /*課題の8パズルの初期状態*/

int save[3][3];/*一時保管する配列*/
int nowue[3][3];/*それぞれの方向の現在状態を保管する配列*/
int nowmigi[3][3];
int nowhidari[3][3];
int nowshita[3][3];

int man, h=0, y, x;
int Fue = 0, Fmigi = 0, Fhidari = 0, Fshita = 0; /*それぞれの方向の発見的関数*/

FILE *file;


int main(){

	int end = 0;

	/*実引数*/
    int upi = 0, upj = 0;
	int righti = 0, rightj = 0;
	int lefti = 0, leftj = 0;
	int downi = 0, downj = 0;

	file = fopen("結果.txt","w");

	printf("\n初期状態\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
	fprintf(file,"\n初期状態\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);

	for(end=0; end<1;){ /*もしendが0ならパズルをスライドし続ける*/

		printf("--------------------\n");
		fprintf(file,"--------------------\n");

		/*-------------------------------------発見的関数の計算↓------------------------------------------*/

		for(i=0;i<3;i++){
			for(j=0;j<3;j++){

				for(k=0;k<3;k++){
					for(l=0;l<3;l++){
						save[k][l] = a[k][l]; /*現在状態の配列を保存*/
					}
				}
				
				if(a[i][j] == 9 && a[i-1][j]<9){ /*もしそこが9(空白)で上が9より小さかったら*/

					a[i][j] = a[i-1][j];/*空白に上の値を上書き*/
					a[i-1][j] = 9;/*上に9(空白)を入れる*/
					Fue = ue(upi, upj); 
					Fue = Fue + 1;/*コスト計算*/
					printf("発見的関数(上)：%d\n",Fue);
					printf("%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"発見的関数(上)：%d\n",Fue);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					h = 0;/*hを初期化*/

					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							nowue[k][l] = a[k][l];/*現在状態を保存*/
						}
					}
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = save[k][l];/*初期化*/
						}
					}

					x = 0; y = 0; /*初期化*/

				}
			}
		}



		for(i=0;i<3;i++){
			for(j=0;j<3;j++){

				for(k=0;k<3;k++){
					for(l=0;l<3;l++){
						save[k][l] = a[k][l]; /*現在状態の配列を保存*/
					}
				}

				if(a[i][j] == 9 && a[i][j+1]<9){ /*もしそこが9(空白)で右が9より小さかったら*/
					a[i][j] = a[i][j+1]; /*空白に右の値を上書き*/
					a[i][j+1] = 9; /*右に空白を入れる*/

					Fmigi = migi(righti, rightj);
					Fmigi = Fmigi + 1;/*コスト計算*/
					printf("発見的関数(右)：%d\n",Fmigi);
					printf("%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"発見的関数(右)：%d\n",Fmigi);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					h = 0;/*hを初期化*/
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							nowmigi[k][l] = a[k][l];/*現在状態を保存*/
						}
					}
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = save[k][l];/*初期化*/
						}
					}
					x = 0; y = 0; /*初期化*/

				}
			}
		}



		for(i=0;i<3;i++){
			for(j=0;j<3;j++){

				for(k=0;k<3;k++){
					for(l=0;l<3;l++){
						save[k][l] = a[k][l]; /*現在状態の配列を保存*/
					}
				}

				if(a[i][j] == 9 && a[i][j-1]<9){ /*もしそこが9(空白)で左が9より小さかったら*/
					a[i][j] = a[i][j-1]; /*空白に左の値を上書き*/
					a[i][j-1] = 9; /*左に空白を入れる*/
					Fhidari = hidari(lefti, leftj);
					Fhidari = Fhidari + 1; /*コスト計算*/
					printf("発見的関数(左)：%d\n",Fhidari);
					printf("%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"発見的関数(左)：%d\n",Fhidari);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					h = 0; /*初期化*/
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							nowhidari[k][l] = a[k][l];/*現在状態を保存*/
						}
					}
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = save[k][l];/*初期化*/
						}
					}
					x = 0; y = 0; /*初期化*/

				}
			}
		}



		for(i=0;i<3;i++){
			for(j=0;j<3;j++){

				for(k=0;k<3;k++){
					for(l=0;l<3;l++){
						save[k][l] = a[k][l]; /*現在状態の配列を保存*/
					}
				}

				if(a[i][j] == 9 && a[i+1][j]<9){ /*もしそこが9(空白)で下が9より小さかったら*/
					a[i][j] = a[i+1][j]; /*空白に下の値を上書き*/
					a[i+1][j] = 9; /*下に空白を入れる*/
					Fshita = shita(downi, downj);
					Fshita = Fshita + 1; /*コスト計算*/
					h = 0;/*初期化*/					
					printf("発見的関数(下)：%d\n",Fshita);
					printf("%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"発見的関数(下)：%d\n",Fshita);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							nowshita[k][l] = a[k][l];/*現在状態を保存*/
						}
					}
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = save[k][l];/*初期化*/
						}
					}
					x = 0; y = 0; /*初期化*/

				}
			}
		}

		/*-------------------------------------発見的関数の計算↑------------------------------------------*/

		/*-----------------------------------------最小を選ぶ↓--------------------------------------------*/
		
				if(Fue<Fmigi && Fue<Fhidari && Fue<Fshita){ /*もし上にスライドしたときの発見的関数が一番小さかったら*/
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = nowue[k][l];/*上にスライドしたときの配列に更新*/
						}
					}
					printf("\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
				}



				else if(Fmigi<Fue && Fmigi<Fhidari && Fmigi<Fshita){ /*もし右にスライドしたときの発見的関数が一番小さかったら*/		
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = nowmigi[k][l];/*上にスライドしたときの配列に更新*/
						}
					}
					printf("\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
				}



				else if(Fhidari<Fue && Fhidari<Fmigi && Fhidari<Fshita){ /*もし左にスライドしたときの発見的関数が一番小さかったら*/
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = nowhidari[k][l];/*上にスライドしたときの配列に更新*/
						}
					}
					printf("\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
				}



				else if(Fshita<Fue && Fshita<Fmigi && Fshita<Fhidari){ /*もし下にスライドしたときの発見的関数が一番小さかったら*/
					for(k=0;k<3;k++){
						for(l=0;l<3;l++){
							a[k][l] = nowshita[k][l];/*上にスライドしたときの配列に更新*/
						}
					}
					printf("\n%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
					fprintf(file,"%d%d%d\n%d%d%d\n%d%d%d\n\n",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
				}

				

				/*-----------------------------------------最小を選ぶ↑-----------------------------------------------*/

		for(k=0;k<3;k++){
			for(l=0;l<3;l++){
				if(a[k][l] == b[k][l]){/*もしパズルが終わったら、endに1を足す*/
					end = end + 1;
				}
			}
			return 0; /*プログラムが完成していないので、ループしてしまうのでここで止める*/
		}

	}

	fclose(file);
	return 0;

}


int ue(int uei, int uej){
	/* ----------------------- h(p) --------------------------- */
	for(i=0; i<3; i++){

	 /*jの値を初期化*/
		for(j=0; j<3; j++){

			 /*マンハッタン距離*/
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

				man = abs(x)+abs(y); /*マンハッタン距離をそれぞれ足していく*/
				h = man + h; /*マンハッタン距離の総和*/
				/*printf("manの値は、%d\n",man);*/		
	}
}
	printf("マンハッタン距離の総和は、%d\n",h);
	fprintf(file,"マンハッタン距離の総和は、%d\n",h);
	return h;
}

int migi(int migii, int migij){
	/* ----------------------- h(p) --------------------------- */
	for(i=0; i<3; i++){

	 /*jの値を初期化*/
		for(j=0; j<3; j++){

			 /*マンハッタン距離*/
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

				man = abs(x)+abs(y); /*マンハッタン距離をそれぞれ足していく*/
				h = man + h; /*マンハッタン距離の総和*/
				/*printf("manの値は、%d\n",man);*/		
	}
}
	printf("マンハッタン距離の総和は、%d\n",h);
	fprintf(file,"マンハッタン距離の総和は、%d\n",h);
	return h;
}

int hidari(int hidarii, int hidarij){
	/* ----------------------- h(p) --------------------------- */
	for(i=0; i<3; i++){

	 /*jの値を初期化*/
		for(j=0; j<3; j++){

			 /*マンハッタン距離*/
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

				man = abs(x)+abs(y); /*マンハッタン距離をそれぞれ足していく*/
				h = man + h; /*マンハッタン距離の総和*/
				/*printf("manの値は、%d\n",man);*/		
	}
}
	printf("マンハッタン距離の総和は、%d\n",h);
	fprintf(file,"マンハッタン距離の総和は、%d\n",h);
	return h;
}

int shita(int sihitai, int shitaj){
	/* ----------------------- h(p) --------------------------- */
	for(i=0; i<3; i++){

	 /*jの値を初期化*/
		for(j=0; j<3; j++){

			 /*マンハッタン距離*/
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

				man = abs(x)+abs(y); /*マンハッタン距離をそれぞれ足していく*/
				h = man + h; /*マンハッタン距離の総和*/
				/*printf("manの値は、%d\n",man);*/		
	}
}
	printf("マンハッタン距離の総和は、%d\n",h);
	fprintf(file,"マンハッタン距離の総和は、%d\n",h);
	return h;
}