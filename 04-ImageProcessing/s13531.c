#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main() {

	FILE *IMG_1_main, *IMG_1_match, *IMG_2_main, *IMG_2_match;

	int yy = 0, xx = 0, k = 0, l = 0;
	int R_sad = 0;						//類似度
	int R_sad_min,min_X,min_Y;			//類似度の最小,その時の座標
	//画素値保存用の配列作成
	int img_1[512][512], img_2[512][512], Timg_1[200][200], Timg_2[136][215];

	//テキストファイル読み込み
	fopen_s(&IMG_1_main, "img_data_1.txt", "r");
	fopen_s(&IMG_1_match, "Timg_data_1.txt", "r");
	fopen_s(&IMG_2_main, "img_data_2.txt", "r");
	fopen_s(&IMG_2_match, "Timg_data_1.txt", "r");

	/******************************************************************/
	//ファイル内のデータを配列に移動

	/***未実装***/

	/******************************************************************/
	//img_1 処理
	R_sad_min = 10200000;		//類似度　初期値設定
	printf("img_1 判別開始");
	for (yy = 0; yy < 312; yy++) {				//img_1 Y座標移動範囲　512-200
		for (xx = 0; xx < 312; xx++){			//img_1 X座標移動範囲　512-200
			R_sad = 0;
			for (k = 0; k < 200; k++){			//img_1 マッチング　200*200
				for (l = 0; l < 200; l++) {
					if (img_1[yy+k][xx+l] != Timg_1[k][l]) { R_sad = R_sad+255; }
				}
			}
			printf("座標I(%d，%d)　類似判別完了 %d\n",xx+1,yy+1,R_sad);
			if (R_sad_min > R_sad) {			//類似度最高　判別
				R_sad_min = R_sad;
				min_X = xx;
				min_Y = yy;
			}
		}
	}
	//マッチング座標表示
	printf("結果　I( %d，%d )\n", min_X, min_Y);
	/******************************************************************/
	//img_2 処理
	printf("img_2 判別開始");
	R_sad_min = 7456200;		//類似度　初期値設定
	for (yy = 0; yy < 376; yy++) {				//img_2 Y座標移動範囲　512-136
		for (xx = 0; xx < 297; xx++) {			//img_2 X座標移動範囲　512-215
			R_sad = 0;
			for (k = 0; k < 136; k++) {			//img_2 マッチング　215*136
				for (l = 0; l < 215; l++) {
					R_sad = R_sad + abs(img_2[yy+k][xx+l]-Timg_2[k][l]);//差の絶対値の和　計算
				}
			}
			printf("座標I(%d，%d)　類似判別完了 %d\n",xx+1,yy+1,R_sad);
			if (R_sad_min > R_sad) {			//類似度最高　判別
			R_sad_min = R_sad;
			min_X = xx;
			min_Y = yy;
			}
		}

	}
	//マッチング座標表示
	printf("結果　I( %d，%d )\n", min_X, min_Y);
	/******************************************************************/

	fclose(IMG_1_main);
	fclose(IMG_1_match);
	fclose(IMG_2_main);
	fclose(IMG_2_match);
}