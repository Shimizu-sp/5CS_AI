#include<stdio.h>
int main(){

	char First[11] = {'g', 'f', 'e', 'd', 'c','b', 'a', '+','-', '*',  '/' };//11種類の文字列
	int i = 0, j = 0;//カウント用
	int where = 0;//文字の位置記憶
	char n = '1';//文字列の保存用

	for (i = 0; i < 11; i++){
		printf("%c", First[i]);//初期状態を最初に表示
	}
	printf("\n");
	printf("並び替えを開始します\n");

	while (First[0] != 'g'){//R1_文字列gは1番目でなければ前と交換する
		for (j = 0; j < 11; j++){
			if (First[j] == 'g'){
				where = j;//gの場所取得
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//交換
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//移動過程(WMの状態変化)
		}
		printf("\n");
	}
	printf("gが正しい位置に移動しました。\n");

	while (First[1] != 'f'){//R2_文字列fは2番目でなければ前と交換する
		for (j = 0; j < 11; j++){
			if (First[j] == 'f'){
				where = j;//fの場所取得
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//交換
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//移動過程(WMの状態変化)
		}
		printf("\n");
	}
	printf("fが正しい位置に移動しました。\n");

	while (First[2] != 'e'){//R3_文字列eは3番目でなければ前と交換する
		for (j = 0; j < 11; j++){
			if (First[j] == 'e'){
				where = j;//eの場所取得
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//交換
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//移動過程(WMの状態変化)
		}
		printf("\n");
	}
	printf("eが正しい位置に移動しました。\n");

	while (First[3] != 'd'){//R4_文字列dは4番目でなければ前と交換する
		for (j = 0; j < 11; j++){
			if (First[j] == 'd'){
				where = j;//dの場所取得
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//交換
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//移動過程(WMの状態変化)
		}
		printf("\n");
	}
	printf("dが正しい位置に移動しました。\n");

	while (First[4] != 'c'){//R5_文字列cは5番目でなければ前と交換する
		for (j = 0; j < 11; j++){
			if (First[j] == 'c'){
				where = j;//cの場所取得
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//交換
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//移動過程(WMの状態変化)
		}
		printf("\n");
	}
	printf("cが正しい位置に移動しました。\n");
	while (First[5] != 'b'){//R6_文字列bは6番目でなければ前と交換する
		for (j = 0; j < 11; j++){
			if (First[j] == 'b'){
				where = j;//bの場所取得
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//交換
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//移動過程(WMの状態変化)
		}
		printf("\n");
	}
	printf("bが正しい位置に移動しました。\n");

	while (First[6] != 'a'){//R7_文字列aは7番目でなければ前と交換する
		for (j = 0; j < 11; j++){
			if (First[j] == 'a'){
				where = j;//aの場所取得
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//交換
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//移動過程(WMの状態変化)
		}
		printf("\n");
	}
	printf("aが正しい位置に移動しました。\n");

		while (First[7] != '+'){//R8_文字列+は8番目でなければ前と交換する
		for (j = 0; j < 11; j++){
			if (First[j] == '+'){
				where = j;//+の場所取得
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//交換
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//移動過程(WMの状態変化)
		}
		printf("\n");
	}
	printf("+が正しい位置に移動しました。\n");

	while (First[8] != '-'){//R9_文字列-は9番目でなければ前と交換する
		for (j = 0; j < 11; j++){
			if (First[j] == '-'){
				where = j;//-の場所取得
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//交換
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//移動過程(WMの状態変化)
		}
		printf("\n");
	}
	printf("-が正しい位置に移動しました。\n");

	while (First[9] != '*'){//R10_文字列*は10番目でなければ前と交換する
		for (j = 0; j < 11; j++){
			if (First[j] == '*'){
				where = j;//*の場所取得
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//交換
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//移動過程(WMの状態変化)
		}
		printf("\n");
	}
	printf("*が正しい位置に移動しました。\n");

	while (First[10] != '/'){//R11_文字列/は11番目でなければ前と交換する
		for (j = 0; j < 11; j++){
			if (First[j] == '/'){
				where = j;// /の場所取得
				break;
			}
		}
		n = First[where];
		First[where] = First[where - 1];
		First[where - 1] = n;//交換
		for (j = 0; j < 11; j++){
			printf("%c", First[j]);//移動過程(WMの状態変化)
		}
		printf("\n");
	}
	printf("/が正しい位置に移動しました。\n");
	printf("\n");
	for (i = 0; i < 11; i++){
		printf("%c", First[i]);//ゴール状態を表示
	}
	printf("\n");
	printf("並び替えを終了しました。\n");

}
