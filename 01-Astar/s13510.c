#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#pragma warning(disable:4996)
#define QUEUE_SIZE 50

//隣接リスト
int rin[9][6] = {
	1, 2, -1, -1, -1, 8, 0, 5, -1, -1, 1, 4, -1, -1, -1,
	8, 0, 6, -1, -1, 1, 2, 3, 4, -1, -1, 5, 0, 7, -1, -1,
	2, 3, -1, -1, -1, 6, 0, 7, -1, -1, 4, 3, -1, -1, -1, };

int goal[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };//ゴール状態
int cell1[3][3] = { { 8, 1, 5 },
					{ 2, 0, 4 },
					{ 6, 3, 7 } };//初期状態
int q, r, j = 0;
//キュー用関数
int enqueue(int min);
int dequeue(int min2);
int queue[QUEUE_SIZE];
int head, tail = 0;
//パズルを動かすための関数
int moveup(int cell1[3][3]);
int movedown(int cell1[3][3]);
int moveleft(int cell1[3][3]);
int moveright(int cell1[3][3]);
//マンハッタン用関数
int manhattan(int cell[3][3]);
//最小コスト用関数
int mostmin(int min1, int min2, int min3, int min4);

int hozon(int cell1[3][3]);
typedef int data_t;

int moveup(int cell1[][3]){//０を発見して上と入れ替え
	int x1, y1=0;
	int c = 0;
	int con1  =  0 ;
	int c1[3][3] = { 0 };

	for (x1 = 0; x1 <= 2; x1++){
		for (y1 = 0; y1 <= 2; y1++){
			if (cell1[x1][y1] == 0 && c==0){//上
				con1 = cell1[x1 - 1][y1];
				cell1[x1][y1] = con1;
				cell1[x1 - 1][y1] = 0;
				c++;//一回以上入れ替わらないようにする
			}
		}
	}
	return cell1[x1][y1];
}

int movedown(int cell1[][3]){//０を発見して下と入れ替え
	int x1, y1,n=0;
	int con2=0;
	int c = 0;

	for (x1 = 0; x1 <3; x1++){
		for (y1 = 0; y1 <3; y1++){
			if (cell1[x1][y1] == 0 && c==0){
				con2= cell1[x1 + 1][y1];
				cell1[x1 + 1][y1] = 0;
				cell1[x1][y1] = con2;
				c++; //一回以上入れ替わらないようにする
			}
		}
	}
	return cell1[x1][y1];
}

int moveleft(int cell1[][3]){//０を発見して左と入れ替え
	int x1, y1;
	int con3 =  0 ;
	int c = 0;

	for (x1 = 0; x1 <= 2; x1++){
		for (y1 = 0; y1 <= 2; y1++){
			if (cell1[x1][y1] == 0 && c==0){//上
				con3 = cell1[x1][y1 - 1];
				cell1[x1][y1 - 1] = 0;
				cell1[x1][y1] = con3;
				c++;//一回以上入れ替わらないようにする
			}
		}
	}
	return cell1[x1][y1];
}

int moveright(int cell1[][3]){//０を発見して右と入れ替え
	int x1, y1;
	int con4 =  0 ;
	int c = 0;
	
	for (x1 = 0; x1 <= 2; x1++){
		for (y1 = 0; y1 <= 2; y1++){
			if (cell1[x1][y1] == 0 && c==0){//上
				con4 = cell1[x1][y1 + 1];

				cell1[x1][y1 + 1] = 0;
				cell1[x1][y1] = con4; 
				c++;//一回以上入れ替わらないようにする
			}
		}
	}
	return cell1[x1][y1];
}

int manhattan(int cell[][3]){ //マンハッタン距離を求める
	
	int value[8] = { 0 };
	int value2 = 0;
	int i, j,n=0;
	int x1, y1 = 0;
	int w, t = 0;

	for (x1 = 0; x1 <= 2; x1++){
	 for (y1 = 0; y1 <= 2; y1++){
		n = cell[x1][y1];//セルの中身取得
		//printf("n==%d\n", n);
		w = x1;//座標位置取得
		t = y1;

		switch (n){ //マンハッタン計算(中身に応じて変動)
			case 0:
				break;
			case 1:
				q = abs(0 - w);
				r = abs(0 - t);
				value[0] = abs(q + r);
				break;

			case 2:
				q = abs(0 - w);//x
				r = abs(1 - t);//y
				value[1] = abs(q + r);
				break;

			case 3:
				q = abs(0 - w);//x
				r = abs(2 - t);//y
				value[2] = abs(q + r);
				break;

			case 4:
				q = abs(1 - w);//x
				r = abs(0 - t);//y
				value[3] = abs(q + r);
				break;

			case 5:
				q = abs(1 - w);//x
				r = abs(1 - t);//y
				value[4] = abs(q + r);
				break;

			case 6:
				q = abs(1 - w);//x
				r = abs(2 - t);//y
				value[5] = abs(q + r);
				break;

			case 7:
				q = abs(2 - w);//x
				r = abs(0 - t);//y
				value[6] = abs(q + r);
				break;

			case 8:
				q = abs(2 - w);//x
				r = abs(1 - t);//y
				value[7] = abs(q + r);
				break;
			}
		}
	}

//マンハッタン集計------------------------
	for (i = 0; i < 8; i++){
		value2 +=  abs(value[i]);
	}
	value2 = value2 + 1;
	return value2;
//---------------------------------------
}

int mostmin(int min1, int min2, int min3, int min4){
	//マンハッタン距離の最小値の算出		
	int min = 0;
	
	min = min1;
	if (min>=min2){
		min = min2;	
	}
	
	if (min>=min3){
		min = min3;
	}

	if (min>=min4){
		min = min4;		
	}
	

	printf("MIN=%d \n",min);
	return min; //最小のコストを返す
}

int enqueue(int min){//キューに最小コスト挿入
		queue[tail++] = min;
		return 0;	
}

int dequeue(int *min2){//キューから値を取り出し
		*min2 = queue[head++];
		return 0;
}

int hozon(int cell1[][3]){
	int c_hozon[3][3] = { 0 };
	for (int x1 = 0; x1 <= 2; x1++){
		for (int y1 = 0; y1 <= 2; y1++){
			c_hozon[x1][y1] = cell1[x1][y1];
			//printf("c_hozon = %d\n", c_hozon[x1][y1]);
		}
	}
	return c_hozon;
}

int main(void){
	int man = 0;
	int man2 = 0;
	int man3 = 0;
	int man4 = 0;
	int min = 0;
	int max = 0;
	//パズルの状態を保存
	int c_1[3][3] = { 0 };
	int c_2[3][3] = { 0 };
	int c_3[3][3] = { 0 };
	int c_4[3][3] = { 0 };

	//while (cell1 != goal){
	
		//上に動かす-------------------------------------------------------------
		moveup(cell1);
		man = manhattan(cell1);
		//盤面保存
		for (int x1 = 0; x1 <= 2; x1++){
			for (int y1 = 0; y1 <= 2; y1++){
				c_1[x1][y1] = cell1[x1][y1];
			}
		}
		movedown(cell1);//元に戻す
		printf("MAN1=%d\n", man);

		//下に動かす--------------------------------------------------------------
		movedown(cell1);
		man2 = manhattan(cell1);
		for (int x1 = 0; x1 <= 2; x1++){//盤面保存

			for (int y1 = 0; y1 <= 2; y1++){
				c_2[x1][y1] = cell1[x1][y1];
			}
		}
		moveup(cell1);//元に戻す
		printf("MAN2=%d\n", man2);

		//左に動かす--------------------------------------------------------------
		moveleft(cell1);
		man3 = manhattan(cell1);
		for (int x1 = 0; x1 <= 2; x1++){//盤面保存
			for (int y1 = 0; y1 <= 2; y1++){
				c_3[x1][y1] = cell1[x1][y1];
			}
		}
		moveright(cell1);//元に戻す
		printf("MAN3=%d\n", man3);

		//右に動かす--------------------------------------------------------------
		moveright(cell1);
		man4 = manhattan(cell1);
		for (int x1 = 0; x1 <= 2; x1++){//盤面保存
			for (int y1 = 0; y1 <= 2; y1++){
				c_4[x1][y1] = cell1[x1][y1];
			}
		}
		moveleft(cell1);//元に戻す
		printf("MAN4=%d\n", man4);
		//-パズルの移動ここまで-------------------------------------------------------------

		//最小コストを求めてminに入れる
		min = mostmin(man, man2, man3, man4);

		if (min == man){//man1が最小コストだった時
			//最小コストをスタックに入れる
			printf("最小はman1\n");
			enqueue(min);
			hozon(c_1);
			for (int x1 = 0; x1 <= 2; x1++){
				for (int y1 = 0; y1 <= 2; y1++){
					cell1[x1][y1] = c_1[x1][y1];
				}
			}
		}

		if (min == man2){//man2のとき
			//最小コストをスタックに入れる
			enqueue(min);
			hozon(c_2);
			for (int x1 = 0; x1 <= 2; x1++){
				for (int y1 = 0; y1 <= 2; y1++){
					cell1[x1][y1] = c_2[x1][y1];
				}
			}
		}
		if (min == man3){
			//最小コストをスタックに入れる
			enqueue(min);
			hozon(c_3);
			for (int x1 = 0; x1 <= 2; x1++){
				for (int y1 = 0; y1 <= 2; y1++){
					cell1[x1][y1] = c_3[x1][y1];
				}
			}
		}
		if (min == man4){
			//最小コストをスタックに入れる
			enqueue(min);
			hozon(c_4);
			for (int x1 = 0; x1 <= 2; x1++){
				for (int y1 = 0; y1 <= 2; y1++){
					cell1[x1][y1] = c_4[x1][y1];


				}
			}
		}



		//ファイル出力
		FILE *outputfile;
		outputfile = fopen("output.txt", "w");
		for (int x1 = 0; x1 <= 2; x1++){
			for (int y1 = 0; y1 <= 2; y1++){
				fprintf(outputfile, "%d \n", cell1[x1][y1]);
			}
		}
		fprintf(outputfile, "発見的関数の値＝%d \n", min);
		fclose(outputfile);

	}






