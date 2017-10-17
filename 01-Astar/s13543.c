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
	int X = 0;//0の位置を保存(行)
	int Y = 0; //0の位置を保存(列)
	int X2 = 0;
	int Y2 = 0;
	int End =0,End2=0;
	int c1 = 0, c2 = 0;//カウント
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

	//初期表示
	printf("初期の状態             ゴール状態\n");
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
	//初期表示終わり

	///////////////////////////////////////////////////////////////////////////////////////////////////

	//0を探す
	for (c1 = 0; c1 < 3; c1++) {
		for (c2 = 0; c2 < 3; c2++) {
			if (Pst[c1][c2] == 0) {

				X = c1;
				Y = c2;

				printf("現在の0の位置を探します\n行=%d  列=%d\n\n",X+1,Y+1);
				
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
		printf("0が入ってないやん\n\n");
		exit();
	}

	End = 0;
	//0探し終わり

	//////////////////////////////////////////////////////////////////////////////////////////////////

	//0の周りの情報取得
	if (X == 0) {	//上段の場合

		zero_up = arien;//X=0より上がないことは確実

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
	else if (X == 1) {	//中段の場合
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
	else if (X == 2) {	//下段の場合

		zero_down = arien;//X=0より下がないことは確実

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
		printf("0の左は...ないです\n");
	}
	else {
		printf("0の左は...%d\n", zero_left);
	}
		if (zero_up == -1) {
			printf("0の上は...ないです\n");
		}else{
			printf("0の上は...%d\n", zero_up);

		}if (zero_right == -1) {
			printf("0の右は...ないです\n");
		}
		else {
			printf("0の右は...%d\n", zero_right);
		}if (zero_down == -1) {
			printf("0の下は...ないです\n");
		}else {
			printf("0の下は...%d\n\n", zero_down);


		


	}

		//マンハッタン距離計測準備

		if (zero_left != -1) { //左にシフト可能なら計算開始
			for (int PreG = 0; PreG < 3; PreG++) {
				for (int PreR = 0; PreR < 3; PreR++) {
					PL[PreG][PreR] = Pst[PreG][PreR];
				}
			}

			tmp = Pst[X][Y - 1];
			PL[X][Y] = tmp;

			PL[X][Y - 1] = 0;
			tmp = 0;
			//左との入れ替え終了(配列PL)
		}
		if (zero_up != -1) { //上にシフト可能なら計算開始
			for (int PreG = 0; PreG < 3; PreG++) {
				for (int PreR = 0; PreR < 3; PreR++) {
					PU[PreG][PreR] = Pst[PreG][PreR];
				}
			}

			tmp = Pst[X-1][Y];
			PU[X][Y] = tmp;

			PU[X-1][Y] = 0;
			tmp = 0;
			//上との入れ替え終了(配列PU)
		}
		if (zero_right != -1) { //右にシフト可能なら計算開始
			for (int PreG = 0; PreG < 3; PreG++) {
				for (int PreR = 0; PreR < 3; PreR++) {
					PR[PreG][PreR] = Pst[PreG][PreR];
				}
			}

			tmp = Pst[X][Y + 1];
			PR[X][Y] = tmp;

			PR[X][Y+1] = 0;
			tmp = 0;
			//右との入れ替え終了(配列PR)
		}
		if (zero_down != -1) { //下にシフト可能なら計算開始
			for (int PreG = 0; PreG < 3; PreG++) {
				for (int PreR = 0; PreR < 3; PreR++) {
					PD[PreG][PreR] = Pst[PreG][PreR];
				}
			}

			tmp = Pst[X+1][Y];
			PD[X][Y] = tmp;

			PD[X+1][Y] = 0;
			tmp = 0;
			//下との入れ替え終了(配列PD)
		}
		else {
			printf("エラー");
		}



			//各数字を探してゴール状態と同じになるように移動
			//SeachAndMove(Xs,Ys);
			/*for (C = 1; C <= 9; C++) {
				for (c1 = 0; c1 < 3; c1++) {
					for (c2 = 0; c2 < 3; c2++) {
						if (Pst[c1][c2] == C) {

							End = 0;

							X = c1;
							Y = c2;


							printf("現在の%dの位置を探します\n行=%d  列=%d\n\n", C, X + 1, Y + 1);
							

									X2 = c1;
									Y2 = c2;
									printf("ゴールの%dの位置を探します\n行=%d  列=%d\n\n", C, X2 + 1, Y2 + 1);
									End2 = 1;
									
				


						}
					}





				}

			}*/


		

				//マンハッタン終わり

			//表示
				Count++;
				printf("ただいま%d手目\n", Count);
				printf("現在の状態             ゴール状態\n");
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
				//表示終わり

			}



		
