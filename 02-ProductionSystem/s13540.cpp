#include <iostream>

using namespace std;

void main() {
	char WM[12] = "a*b-cd/e+fg";
	printf("%s\n", WM);

	//バブルソート
	for (int i = 0; i < 10; i++) {
		for (int j = 10; j > i; j--) {

			//PM1:左側が「/」の場合入れ替え
			if (WM[j - 1] == 47) {
				swap(WM[j - 1], WM[j]);
				printf("%s\n", WM);
			}
			//PM2:右側に「/」がある場合何もしない
			else if (WM[j] == 47);

			/*
			PM3:PM1~2のいずれかを満たさない場合かつ、
			左側が「*」かつ右側が「/」以外の場合入れ替え
			*/
			else if (WM[j - 1] == 42 && WM[j] != 47) {
				swap(WM[j - 1], WM[j]);
				printf("%s\n", WM);
			}

			/*
			PM4:PM1~3のいずれかを満たさない場合かつ、
			左側が「-」かつ右側が「/」「*」以外の場合入れ替え
			*/
			else if (WM[j - 1] == 45 && WM[j] != 47 && WM[j] != 42) {
				swap(WM[j - 1], WM[j]);
				printf("%s\n", WM);
			}

			/*
			PM5:PM1~4のいずれかを満たさない場合かつ、
			左側の文字コードの値が右側の文字コードの値より小さい場合
			入れ替え
			*/
			else if (WM[j - 1] < WM[j]) {
				swap(WM[j - 1], WM[j]);
				printf("%s\n", WM);
			}
		}
	}
}
