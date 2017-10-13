#include<stdio.h>
#include <time.h>//プログラムの実行にかかる時間を計測するため
#pragma warning(disable:4996)
main() {
	clock_t start, end;//開始時間と終了時間用
	int i = 0, j = 0, K = 0, n = 0;//カウントと入れ替え用
	int h = 20, g = 0;//マンハッタン距離の総和(初期は20)とタイルのスライド回数
	int H_1 = 0, H_2 = 0, H_3 = 0, H_4 = 0;//移動後の仮の総和(最大選択肢は4)
	int f = 0;//f=h+g//コスト

	int Block_b[9] =
	{ 8, 1, 5,
	2, 0, 4,
	6, 3, 7 };//移動前のブロック(空白を0と置く)

	int Block_a[9] =
	{ 1, 2, 3,
	4, 5, 6,
	7, 8, 0 };//移動後のブロック(空白を0と置く)

	int Block_M[9] =
	{ 3, 1, 2,
	2, 2, 2,
	3, 3, 2 };//初期位置のマンハッタン距離=20

	int Block_N[9];//コストの仮定に使用する行列N
	start = clock();
	FILE *fp;
	printf("ファイルを作成します\n");
	fp = fopen("J:/5年/人工知能Ⅱ/20170929/解答.txt", "w");//任意の場所にファイルを作成
	if (fp == NULL) {
		printf("ファイルオープン失敗\n");
		return 1;
	}
	else {
		printf("ファイルオープン成功\n");
	}
	printf("パズルを解き始めます\n");
	while (Block_b[0] != Block_a[0] && Block_b[1] != Block_a[1] &&
		Block_b[2] != Block_a[2] && Block_b[3] != Block_a[3] &&
		Block_b[4] != Block_a[4] && Block_b[5] != Block_a[5] &&
		Block_b[6] != Block_a[6] && Block_b[7] != Block_a[7] &&
		Block_b[8] != Block_a[8]) {//移動前と移動後の配列が等しくなければ計算を続ける
		g++;//スライド回数を1回追加
		printf("移動%d回目\n", g);
		for (j = 0; j < 9; j++) {//0の位置を探す
			Block_N[j] = Block_M[j];//コピー
			if (Block_b[j] = 0) {
				n = j;//0の位置を記録
				break;
			}
		}
		//0の位置から隣接する数を割り出す
		switch (n) {
			//#pragma region 0が左上
		case 0://Block_b[n+1]とBlock_b[n+3]の交換後のコストを調べる	
			switch (Block_b[n + 1]) {						//Block_b[n+1]がどの数字か判別し値を返す	//(0 n+1 x
				//n+3 x x
			case 1:
				Block_N[n] = 0;//1が1に到着するので距離がゼロ
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 1;//2が1に到着するので距離が1増加
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 2;//3が1に到着するので距離が1増加
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 1;//4が1に到着するので距離が1減少
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 2;//5が1に到着するので距離が1増加
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 3;//6が1に到着するので距離が1増加
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 2;//7が1に到着するので距離が1減少
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 3;//8が1に到着するので距離が1増加
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;

			}
			switch (Block_b[n + 3]) {						//Block_b[n+3]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 0;//1の距離がゼロ
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 1;//2の距離が1
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 2;//3の距離が2
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 1;//4の距離が1
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 2;//5の距離が2
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 3;//6の距離が3
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 2;//7の距離が2
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 3;//8の距離が3
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			}
			if (H_2 > H_1) {//もしBlock_b[n+1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 1];
				Block_b[n + 1] = K;//値の入れ替え
				f = H_1 + g;//発見的関数の計算

			}
			else if (H_1 > H_2) {//もしBlock_b[n+3]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 3];
				Block_b[n + 3] = K;//値の入れ替え
				f = H_1 + g;//発見的関数の計算

			}
			else {
				printf("マンハッタン距離が等しいため計算できません\n");
				break;
			}

			break;
			//#pragma endregion	

			//#pragma region 0が真ん中上
		case 1://Block_b[n-1]とBlock_b[n+1]とBlock_b[n+3]の交換後のコストを調べる
			//(n-1 0 n+1
			// x n+3 x
			//x x x)
			switch (Block_b[n - 1]) {						//Block_b[n-1]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 1;//1の距離が1
				Block_N[n - 1] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 0;//2の距離が0
				Block_N[n - 1] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 1;//3の距離が1
				Block_N[n - 1] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 2;//4の距離が2
				Block_N[n - 1] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n - 1] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 2;//6の距離が2
				Block_N[n - 1] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 3;//7の距離が3
				Block_N[n - 1] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 2;//8の距離が2
				Block_N[n - 1] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			}

			switch (Block_b[n + 1]) {						//Block_b[n+1]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 1;//1の距離が1
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 0;//2の距離がゼロ
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 1;//3の距離が1
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 2;//4の距離が2
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 2;//6の距離が2
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 3;//7の距離が3
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 2;//8の距離が2
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;

			}

			switch (Block_b[n + 3]) {						//Block_b[n+3]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 1;//1の距離が1
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 0;//2の距離が0
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 1;//3の距離が1
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 2;//4の距離が2
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 2;//6の距離が2
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 3;//7の距離が3
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 2;//8の距離が2
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			}
			if (H_2 > H_1 && H_3 > H_1) {//もしBlock_b[n-1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n - 1];
				Block_b[n - 1] = K;//値の入れ替え
				f = H_1 + g;//発見的関数の計算

			}
			else if (H_1 > H_2 && H_3 > H_2) {//もしBlock_b[n+1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 1];
				Block_b[n + 1] = K;//値の入れ替え
				f = H_2 + g;//発見的関数の計算

			}
			else if (H_2 > H_3 && H_1 > H_3) {//もしBlock_b[n+3]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 3];
				Block_b[n + 3] = K;//値の入れ替え
				f = H_3 + g;//発見的関数の計算

			}
			else {
				printf("マンハッタン距離が等しいため計算できません\n");
				break;
			}

			break;
			//#pragma endregion

			//#pragma region 0が右斜め上
		case 2://Block_b[n-1]とBlock_b[n+1]の交換後のコストを調べる		
			//(x n-1 0
			//x x n+1
			//x x x)
			switch (Block_b[n - 1]) {						//Block_b[n-1]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 2;//1の距離が2
				Block_N[n - 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 1;//2の距離が1
				Block_N[n - 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 0;//3の距離が0
				Block_N[n - 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 3;//4の距離が3
				Block_N[n - 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 2;//5の距離が2
				Block_N[n - 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 1;//6の距離が1
				Block_N[n - 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 4;//7の距離が4
				Block_N[n - 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 3;//8の距離が3
				Block_N[n - 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			}

			switch (Block_b[n + 1]) {						//Block_b[n+1]がどの数字か判別
			case 1:
				Block_N[n] = 2;//1の距離が2
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 1;//2の距離が1
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 0;//3の距離が0
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 3;//4の距離が3
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 2;//5の距離が2
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 1;//6の距離が1
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 4;//7の距離が4
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 3;//8の距離が3
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			}
			if (H_2 > H_1) {//もしBlock_b[n-1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n - 1];
				Block_b[n - 1] = K;//値の入れ替え
				f = H_1 + g;//発見的関数の計算

			}
			else if (H_1 > H_2) {//もしBlock_b[n+1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 1];
				Block_b[n + 1] = K;//値の入れ替え
				f = H_2 + g;//発見的関数の計算

			}
			else {
				printf("マンハッタン距離が等しいため計算できません\n");
				break;
			}
			break;
			//#pragma endregion


			//#pragma region 0が左中央
		case 3://Block_b[n-3]とBlock_b[n+1]とBlock_b[n+3]の交換後のコストを調べる
			//(n-3 x x
			//0 n+1 x
			//n+3 x x)
			switch (Block_b[n - 3]) {						//Block_b[n-3]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 1;//1の距離が1
				Block_N[n - 3] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 2;//2の距離が2
				Block_N[n - 3] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 3;//3の距離が3
				Block_N[n - 3] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 0;//4の距離が0
				Block_N[n - 3] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n - 3] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 2;//6の距離が2
				Block_N[n - 3] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 1;//7の距離が1
				Block_N[n - 3] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 2;//8の距離が2
				Block_N[n - 3] = 4;//0の距離が4
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			}

			switch (Block_b[n + 1]) {						//Block_b[n+1]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 1;//1の距離が1
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 2;//2の距離が2
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 3;//3の距離が3
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 0;//4の距離が0
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 2;//6の距離が2
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 1;//7の距離が1
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 2;//8の距離が2
				Block_N[n + 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			}

			switch (Block_b[n + 3]) {						//Block_b[n+3]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 1;//1の距離が1
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 2;//2の距離が2
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 3;//3の距離が3
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 0;//4の距離が0
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 2;//6の距離が2
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 1;//7の距離が1
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 2;//8の距離が2
				Block_N[n + 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			}
			if (H_2 > H_1 && H_3 > H_1) {//もしBlock_b[n-3]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n - 3];
				Block_b[n - 3] = K;//値の入れ替え
				f = H_1 + g;//発見的関数の計算

			}
			else if (H_1 > H_2 && H_3 > H_2) {//もしBlock_b[n+1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 1];
				Block_b[n + 1] = K;//値の入れ替え
				f = H_2 + g;//発見的関数の計算

			}
			else if (H_2 > H_3 && H_1 > H_3) {//もしBlock_b[n+3]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 3];
				Block_b[n + 3] = K;//値の入れ替え
				f = H_3 + g;//発見的関数の計算

			}
			else {
				printf("マンハッタン距離が等しいため計算できません\n");
				break;
			}
			break;
			//#pragma endregion 

			//#pragma region 0が中央
		case 4://Block_b[n-3]とBlock_b[n-1]とBlock_b[n+1]とBlock_b[n+3]の交換後のコストを調べる
			//(x n-3  x
			//n-1 0 n+1
			//x n+3 x)
			switch (Block_b[n - 3]) {						//Block_b[n-3]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 2;//1の距離が2
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 1;//2の距離が1
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 2;//3の距離が2
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 1;//4の距離が1
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 0;//5の距離が0
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 1;//6の距離が1
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 2;//7の距離が2
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 1;//8の距離が1
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			}

			switch (Block_b[n - 1]) {						//Block_b[n-1]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 2;//1の距離が2
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 1;//2の距離が1
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 2;//3の距離が2
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 1;//4の距離が1
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 0;//5の距離が0
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 1;//6の距離が1
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 2;//7の距離が2
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 1;//8の距離が1
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			}

			switch (Block_b[n + 1]) {						//Block_b[n+1]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 2;//1の距離が2
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 1;//2の距離が1
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}				break;
			case 3:
				Block_N[n] = 2;//3の距離が2
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 1;//4の距離が1
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}				break;
			case 5:
				Block_N[n] = 0;//5の距離が0
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 1;//6の距離が1
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 2;//7の距離が2
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 1;//8の距離が1
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			}

			switch (Block_b[n + 3]) {						//Block_b[n+3]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 2;//1の距離が2
				Block_N[n + 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_4 = H_4 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 1;//2の距離が1
				Block_N[n + 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_4 = H_4 + Block_N[i];
				}				break;
			case 3:
				Block_N[n] = 2;//3の距離が2
				Block_N[n + 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_4 = H_4 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 1;//4の距離が1
				Block_N[n + 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_4 = H_4 + Block_N[i];
				}				break;
			case 5:
				Block_N[n] = 0;//5の距離が0
				Block_N[n + 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_4 = H_4 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 1;//6の距離が1
				Block_N[n + 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_4 = H_4 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 2;//7の距離が2
				Block_N[n + 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_4 = H_4 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 1;//8の距離が1
				Block_N[n + 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_4 = H_4 + Block_N[i];
				}
				break;
			}
			if (H_2 > H_1 && H_3 > H_1 && H_4 > H_1) {//もしBlock_b[n-3]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n - 3];
				Block_b[n - 3] = K;//値の入れ替え
				f = H_1 + g;//発見的関数の計算

			}
			else if (H_1 > H_2 && H_3 > H_2 && H_4 > H_2) {//もしBlock_b[n-1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n - 1];
				Block_b[n - 1] = K;//値の入れ替え
				f = H_2 + g;//発見的関数の計算

			}
			else if (H_2 > H_3 && H_1 > H_3 && H_4 > H_3) {//もしBlock_b[n+1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 1];
				Block_b[n + 1] = K;//値の入れ替え
				f = H_3 + g;//発見的関数の計算

			}
			else if (H_2 > H_4 && H_1 > H_4 && H_3 > H_4) {//もしBlock_b[n+3]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 3];
				Block_b[n + 3] = K;//値の入れ替え
				f = H_4 + g;//発見的関数の計算

			}
			else {
				printf("マンハッタン距離が等しいため計算できません\n");
				break;
			}
			break;
			//#pragma endregion

			//#pragma region 0が右中央
		case 5://Block_b[n-3]とBlock_b[n-1]とBlock_b[n+3]の交換後のコストを調べる		
			//(x x n-3
			//x n-1 0
			//x x n+3)
			switch (Block_b[n - 3]) {						//Block_b[n-3]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 3;//1の距離が3
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 2;//2の距離が2
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 1;//3の距離が1
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 2;//4の距離が2
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 0;//6の距離が0
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 4;//7の距離が4
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 3;//8の距離が3
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			}

			switch (Block_b[n - 1]) {						//Block_b[n-1]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 3;//1の距離が3
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 2;//2の距離が2
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 1;//3の距離が1
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 2;//4の距離が2
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 0;//6の距離が0
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 4;//7の距離が4
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 3;//8の距離が3
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			}

			switch (Block_b[n + 1]) {						//Block_b[n+3]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 3;//1の距離が3
				Block_N[n + 3] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 2;//2の距離が2
				Block_N[n + 3] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 1;//3の距離が1
				Block_N[n + 3] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 2;//4の距離が2
				Block_N[n + 3] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n + 3] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 0;//6の距離が0
				Block_N[n + 3] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 4;//7の距離が4
				Block_N[n + 3] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 3;//8の距離が3
				Block_N[n + 3] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			}

			if (H_2 > H_1 && H_3 > H_1) {//もしBlock_b[n-3]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n - 3];
				Block_b[n - 3] = K;//値の入れ替え
				f = H_1 + g;//発見的関数の計算

			}
			else if (H_1 > H_2 && H_3 > H_2) {//もしBlock_b[n-1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n - 1];
				Block_b[n - 1] = K;//値の入れ替え
				f = H_2 + g;//発見的関数の計算

			}
			else if (H_2 > H_3 && H_1 > H_3) {//もしBlock_b[n+3]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 3];
				Block_b[n + 3] = K;//値の入れ替え
				f = H_3 + g;//発見的関数の計算

			}
			else {
				printf("マンハッタン距離が等しいため計算できません\n");
				break;
			}

			break;
			//#pragma endregion


			//#pragma region 0が左下
		case 6://Block_b[n-3]とBlock_b[n+1]の交換後のコストを調べる		
			//(x x x
			//n-3 x x
			//0 n+1 x)
			switch (Block_b[n - 3]) {						//Block_b[n-3]がどの数字か判別し値を返す

			case 1:
				Block_N[n] = 2;//1の距離が2
				Block_N[n - 3] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 3;//2の距離が3
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 4;//3の距離が4
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 1;//4の距離が1
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 2;//5の距離が2
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 3;//6の距離が3
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 0;//7の距離が0
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 1;//8の距離が1
				Block_N[n + 1] = 3;//0の距離が3
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;

			}

			switch (Block_b[n + 1]) {						//Block_b[n+1]がどの数字か判別し値を返す

			case 1:
				Block_N[n] = 2;//1の距離が2
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 3;//2の距離が3
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 4;//3の距離が4
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 1;//4の距離が1
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 2;//5の距離が2
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 3;//6の距離が3
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 0;//7の距離が0
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 1;//8の距離が1
				Block_N[n + 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			}
			if (H_2 > H_1) {//もしBlock_b[n-3]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n - 3];
				Block_b[n - 3] = K;//値の入れ替え
				f = H_1 + g;//発見的関数の計算

			}
			else if (H_1 > H_2) {//もしBlock_b[n+1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 1];
				Block_b[n + 1] = K;//値の入れ替え
				f = H_2 + g;//発見的関数の計算

			}
			else {
				printf("マンハッタン距離が等しいため計算できません\n");
				break;
			}
			break;
			//#pragma endregion

			//#pragma region 0が真ん中下
		case 7://Block_b[n-3]とBlock_b[n-1]とBlock_b[n+1]の交換後のコストを調べる		
			//(x x x
			//x n-3 x
			//n-1 0 n+1)
			switch (Block_b[n - 3]) {						//Block_b[n-3]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 3;//1の距離が3
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 2;//2の距離が2
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 3;//3の距離が3
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 2;//4の距離が2
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 2;//6の距離が2
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 1;//7の距離が1
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 0;//8の距離が0
				Block_N[n - 3] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			}

			switch (Block_b[n - 1]) {						//Block_b[n-1]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 3;//1の距離が3
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 2;//2の距離が2
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 3;//3の距離が3
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 2;//4の距離が2
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 2;//6の距離が2
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 1;//7の距離が1
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 0;//8の距離が0
				Block_N[n - 1] = 2;//0の距離が2
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;

			}
			switch (Block_b[n + 1]) {						//Block_b[n+1]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 3;//1の距離が3
				Block_N[n + 1] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 2;//2の距離が2
				Block_N[n + 1] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 3;//3の距離が3
				Block_N[n + 1] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 2;//4の距離が2
				Block_N[n + 1] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 1;//5の距離が1
				Block_N[n + 1] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 2;//6の距離が2
				Block_N[n + 1] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 1;//7の距離が1
				Block_N[n + 1] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 0;//8の距離が0
				Block_N[n + 1] = 0;//0の距離が0
				for (i = 0; i < 9; i++) {
					H_3 = H_3 + Block_N[i];
				}
				break;

			}
			if (H_2 > H_1 && H_3 > H_1) {//もしBlock_b[n-3]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n - 3];
				Block_b[n - 3] = K;//値の入れ替え
				f = H_1 + g;//発見的関数の計算

			}
			else if (H_1 > H_2 && H_3 > H_2) {//もしBlock_b[n-1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n - 1];
				Block_b[n - 1] = K;//値の入れ替え
				f = H_2 + g;//発見的関数の計算

			}
			else if (H_2 > H_3 && H_1 > H_3) {//もしBlock_b[n+1]のほうがコストが小さくなるようだったら
				for (i = 0; i < 9; i++) {
					Block_M[i] = Block_N[i];//コストの更新
				}
				K = Block_b[n];
				Block_b[n] = Block_b[n + 1];
				Block_b[n + 1] = K;//値の入れ替え
				f = H_3 + g;//発見的関数の計算

			}
			else {
				printf("マンハッタン距離が等しいため計算できません\n");
				break;
			}
			break;
			//#pragma endregion

			//#pragma region 0が右下
		case 8://Block_b[n-3]とBlock_b[n-1]の交換後のコストを調べる		
			//(x x x
			//x x n-3 
			//x n-1 0 )
			switch (Block_b[n - 3]) {						//Block_b[n-3]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 4;//1の距離が4
				Block_N[n - 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 3;//2の距離が3
				Block_N[n - 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 2;//3の距離が2
				Block_N[n - 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 3;//4の距離が3
				Block_N[n - 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 2;//5の距離が2
				Block_N[n - 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 1;//6の距離が1
				Block_N[n - 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 2;//7の距離が2
				Block_N[n - 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 1;//8の距離が1
				Block_N[n - 3] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_1 = H_1 + Block_N[i];
				}
				break;
			}

			switch (Block_b[n - 1]) {						//Block_b[n-1]がどの数字か判別し値を返す
			case 1:
				Block_N[n] = 4;//1の距離が4
				Block_N[n - 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 2:
				Block_N[n] = 3;//2の距離が3
				Block_N[n - 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 3:
				Block_N[n] = 2;//3の距離が2
				Block_N[n - 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 4:
				Block_N[n] = 3;//4の距離が3
				Block_N[n - 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 5:
				Block_N[n] = 2;//5の距離が2
				Block_N[n - 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 6:
				Block_N[n] = 1;//6の距離が1
				Block_N[n - 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 7:
				Block_N[n] = 2;//7の距離が2
				Block_N[n - 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			case 8:
				Block_N[n] = 1;//8の距離が1
				Block_N[n - 1] = 1;//0の距離が1
				for (i = 0; i < 9; i++) {
					H_2 = H_2 + Block_N[i];
				}
				break;
			}
			break;
			//#pragma endregion
		}

		fprintf(fp, "%d回目 コスト %d\n", g, f);
		fprintf(fp, "%d %d %d\n%d %d %d\n%d %d %d\n",
			Block_b[0], Block_b[1], Block_b[2],
			Block_b[3], Block_b[4], Block_b[5],
			Block_b[6], Block_b[7], Block_b[8]);
		

	}
	fclose(fp);
	printf("パズルを解き終わりました\n");
	end = clock();
	printf("処理時間:%dms\n", end - start);
}