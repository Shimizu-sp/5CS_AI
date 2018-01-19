#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)  //4996エラーの表示をしない

int manhattan(int A[][3], int E[][3], int search);  //関数の宣言

int main(){
	int B = 0;
	int A[3][3] = { { 8, 1, 5 }, { 2, B, 4 }, { 6, 3, 7 } };  //初期状態
	int C_ue[3][3] = { { 8, 1, 5 }, { 2, B, 4 }, { 6, 3, 7 } }; //交換用
	int C_sita[3][3] = { { 8, 1, 5 }, { 2, B, 4 }, { 6, 3, 7 } };
	int C_migi[3][3] = { { 8, 1, 5 }, { 2, B, 4 }, { 6, 3, 7 } };
	int C_hidari[3][3] = { { 8, 1, 5 }, { 2, B, 4 }, { 6, 3, 7 } };
	int E[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, B } };  //最終

	int i = 0, j = 0;  //初期状態の行列用
	int x = 0, y = 0;  //最終状態の行列用

	int change = 0;

	int B_i, B_j;
	
	int hp = 0;   //マンハッタン距離
	int ue = 10, sita = 10, migi = 10, hidari = 10;

	int search = 0;

	int total_ue = 0, total_sita = 0, total_migi = 0, total_hidari = 0;
	int min = 0;
	int f_ue = 0, f_sita = 0, f_migi = 0, f_hidari = 0;

	FILE *outputfile;   //出力ストリーム


	for (i = 0; i < 3; i++){    //空白のところを探索
		for (j = 0; j < 3; j++){
			if (A[i][j] == B){
				B_i = i;
				B_j = j;
				break;
			}
		}
	}

	//printf("空白のある位置：( %d , %d )\n\n", B_i, B_j);   //空白のある位置(x,y)

	//近傍
	if (B_i - 1>0 || B_i<3)      //もし空白の上に行があれば、変数ueにその位置にある値を入れる
		ue = A[B_i - 1][B_j];
	if (B_i + 1>0 || B_i<3)
		sita = A[B_i + 1][B_j];
	if (B_j - 1>0 || B_j<3)
		migi = A[B_i][B_j + 1];
	if (B_j + 1>0 || B_j<3)
		hidari = A[B_i][B_j - 1];

	//printf("%d %d\n", ue,sita);

	//交換
	if (ue < 10){
		//Bとueの位置を交換
		change = C_ue[B_i - 1][B_j];
		C_ue[B_i - 1][B_j] = C_ue[B_i][B_j];
		C_ue[B_i][B_j] = change;

		for (i = 0; i < 9; i++){
			hp = manhattan(C_ue, E, i);
			//printf("マンハッタン距離：%d \n", hp);
			total_ue = total_ue + hp;
		}//printf("上　合計：%d\n", total_ue);
	}
	if (sita < 10){
		change = C_sita[B_i + 1][B_j];
		C_sita[B_i + 1][B_j] = C_sita[B_i][B_j];
		C_sita[B_i][B_j] = change;

		for (i = 0; i < 9; i++){
			hp = manhattan(C_sita, E, i);
			//printf("マンハッタン距離：%d \n", hp);
			total_sita = total_sita + hp;
		}//printf("下　合計：%d\n", total_sita);
	}
	if (migi < 10){
		change = C_migi[B_i][B_j + 1];
		C_migi[B_i][B_j + 1] = C_migi[B_i][B_j];
		C_migi[B_i][B_j] = change;

		for (i = 0; i < 9; i++){
			hp = manhattan(C_migi, E, i);
			//printf("マンハッタン距離：%d \n", hp);
			total_migi = total_migi + hp;
		}//printf("右　合計：%d\n", total_migi);
	}
	if (hidari < 10){
		change = C_hidari[B_i][B_j - 1];
		C_hidari[B_i][B_j - 1] = C_hidari[B_i][B_j];
		C_hidari[B_i][B_j] = change;

		for (i = 0; i < 9; i++){
			hp = manhattan(C_hidari, E, i);
			//printf("マンハッタン距離：%d \n", hp);
			total_hidari = total_hidari + hp;
		}//printf("左　合計：%d\n", total_hidari);
	}
	
	//最小を選択
	if (total_ue <= total_sita){
		min = total_ue;
		f_ue = 1;
	}
	else{
		min = total_sita;
		f_sita = 1;
	}
	if (total_migi <= min){
		min = total_migi;
		f_migi = 1;
		f_ue = 0, f_sita = 0;
	}
	if (total_hidari <= min){
		min = total_hidari;
		f_hidari = 1;
		f_ue = 0, f_sita = 0, f_migi = 0;
	}
	printf("\n最小：%d\n\n", min);

	//ファイル出力
	outputfile = fopen("d.txt", "w");  //書き込み用
	if (outputfile == NULL){
		printf("cannot open\n");
		exit(1);
	}


	//最小を表示
	if (f_ue == 1){
		//printf("%d %d %d\n%d %d %d\n%d %d %d\n\n", C_ue[0][0], C_ue[0][1], C_ue[0][2], C_ue[1][0], C_ue[1][1], C_ue[1][2], C_ue[2][0], C_ue[2][1], C_ue[2][2]);  //ターミナル表示
		fprintf(outputfile, "%d %d %d\n%d %d %d\n%d %d %d\n\n", C_ue[0][0], C_ue[0][1], C_ue[0][2], C_ue[1][0], C_ue[1][1], C_ue[1][2], C_ue[2][0], C_ue[2][1], C_ue[2][2]);  //ファイルに書く
	}
	if (f_sita == 1){
		//printf("%d %d %d\n%d %d %d\n%d %d %d\n\n", C_sita[0][0], C_sita[0][1], C_sita[0][2], C_sita[1][0], C_sita[1][1], C_sita[1][2], C_sita[2][0], C_sita[2][1], C_sita[2][2]);
		fprintf(outputfile, "%d %d %d\n%d %d %d\n%d %d %d\n\n", C_sita[0][0], C_sita[0][1], C_sita[0][2], C_sita[1][0], C_sita[1][1], C_sita[1][2], C_sita[2][0], C_sita[2][1], C_sita[2][2]);
	}
	if (f_migi == 1){
		//printf("%d %d %d\n%d %d %d\n%d %d %d\n\n", C_migi[0][0], C_migi[0][1], C_migi[0][2], C_migi[1][0], C_migi[1][1], C_migi[1][2], C_migi[2][0], C_migi[2][1], C_migi[2][2]);
		fprintf(outputfile, "%d %d %d\n%d %d %d\n%d %d %d\n\n", C_migi[0][0], C_migi[0][1], C_migi[0][2], C_migi[1][0], C_migi[1][1], C_migi[1][2], C_migi[2][0], C_migi[2][1], C_migi[2][2]);
	}
	if (f_hidari == 1){
		//printf("%d %d %d\n%d %d %d\n%d %d %d\n\n", C_hidari[0][0], C_hidari[0][1], C_hidari[0][2], C_hidari[1][0], C_hidari[1][1], C_hidari[1][2], C_hidari[2][0], C_hidari[2][1], C_hidari[2][2]);
		fprintf(outputfile, "%d %d %d\n%d %d %d\n%d %d %d\n\n", C_hidari[0][0], C_hidari[0][1], C_hidari[0][2], C_hidari[1][0], C_hidari[1][1], C_hidari[1][2], C_hidari[2][0], C_hidari[2][1], C_hidari[2][2]);
	}
	printf("発見的関数：%d\n", 1 + min);
	
	fprintf(outputfile, "発見的関数：%d\n", 1 + min);


	int fclose(FILE *outputfile);

	fclose(outputfile);

	printf("\n");
}

int manhattan(int A[][3], int E[][3], int search){
	int i, j;
	int A_i, A_j, E_i, E_j, hp;
	for (i = 0; i < 3; i++){		//マンハッタン距離ここから
		for (j = 0; j < 3; j++){
			if (A[i][j] == search){    //ここの数字をNにする
				A_i = i;
				A_j = j;
				break;
			}
		}
	}
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (E[i][j] == search){
				E_i = i;
				E_j = j;
				break;
			}
		}
	}
	hp = abs(A_i - E_i) + abs(A_j - E_j);

	return hp;

}