#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Hyouji(char array[]);	// 状態表示用関数
void rule1(char array[]);	// ルール1
void rule2(char array[]);	// ルール2
void rule3(char array[]);	// ルール3
void rule4(char array[]);	// ルール4

int main() {
	int	pattern = 0;

	char start[12] = "gfedcba+-*/";	// 初期状態
	char goal[12] = "gfedcba+-*/";

	Hyouji(start); // 配列全部表示

		rule1(start);  // 記号が右に来る　ルール適応

		rule2(start);  // 数字をちゃんと並べる　ルール適応

		rule3(start);	// 記号を小さい順に入れ替える　ルール適応

		rule4(start);	// 「*」を正しい場所に入れ替える　ルール適応
}



//関数

//------------------------------------

void Hyouji(char array[]){
	int i;

	for (i = 0; i < 11; i++){
		printf("%c", array[i]);
	}
	printf("\n");
}

void rule1(char array[]) {
	int k, m, i;
	int stay;

	printf("\n");
	printf("ルール1 記号を右に寄せる\n");
	// 記号を右に寄せる
	for (k = 0; k < 11; k++) {
		for (m = 0; m < 10; m++) {
			if (ispunct(array[m]) != 0) {	// mが記号なら
				stay = array[m + 1];		// 一つ隣と交換
				array[m + 1] = array[m];
				array[m] = stay;
				Hyouji(array);
			}
		}

	}

}

void rule2(char array[]) {
	int i, m;
	int stay;

	printf("\n");
	printf("ルール2 アルファベットを入れ替える(昇順)\n");
	// アルファベットを入れ替える
	for (m = 0; m < 11; m++) {
		for (i = 0; i < 11; i++) {
			if (ispunct(array[i]) == 0) {		// アルファベットなら
				if (array[i] < array[i + 1]) {	// なおかつ右のほうがデカい
					stay = array[i + 1];
					array[i + 1] = array[i];
					array[i] = stay;
					Hyouji(array);
				}
			}

		}
	}

}

void rule3(char array[]) {
	int i, m;
	int stay;

	printf("\n");
	printf("ルール3 記号を小さい順に並べる\n");

	for (m = 0; m < 11; m++) {
		for (i = 0; i < 10; i++) {
			if (ispunct(array[i]) != 0) {		// 記号なら
				if (array[i + 1] < array[i]) {	// 隣が小さいなら
					stay = array[i + 1];
					array[i + 1] = array[i];
					array[i] = stay;
					Hyouji(array);
				}
			}

		}
	}
}

void rule4(char array[]) {
	int i, m;
	int stay;

	printf("\n");
	printf("ルール4 「*」を正しい位置にもってく\n");

	for (m = 7; m < 8; m++) {
		for (i = m; i < 9; i++) {
		  if (ispunct(array[i]) != 0) {		// 記号なら
			if (array[i] < array[i + 1]) {	// 隣がでかいなら

					stay = array[i];
					array[i] = array[i + 1];
					array[i+1] = stay;
					Hyouji(array);
				}
			 }

		    }
		}


}
