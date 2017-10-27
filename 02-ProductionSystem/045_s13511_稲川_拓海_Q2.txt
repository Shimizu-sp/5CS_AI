#include<stdio.h>
#include<ctype.h>

int prodaction_R1();
int prodaction_R2();
int prodaction_R3();
int prodaction_R4();

char string[] = { 'a', '*', 'b', '-', 'c', 'd', '/', 'e', '+', 'f', 'g', '0' };

int i, j=0;
int ireko;

int ascii_l = 0;
int ascii_r = 0;

//========================================================================

main(){
	printf("R1適用\n");
		prodaction_R1();
	printf("R2適用\n");
		prodaction_R2();
	printf("R3適用\n");
		prodaction_R3();
	printf("R4適用\n");
		prodaction_R4();
}

prodaction_R1(){

	int flug_R1;

	do{ //R1：文字が右にある　∧　記号が左にある　→　文字を左に移動する

		flug_R1 = 0; //フラグ初期化

		for (i = 0; i < 12; i++){

			if (ispunct(string[i]) && isalpha(string[i + 1])){ //ispunctは記号，isalphaはアルファベットであるか判定する関数

				ireko = string[i];
				string[i] = string[i + 1]; //R1適用　
				string[i + 1] = ireko;

				flug_R1 = flug_R1 + 1; //フラグに加算する
			}

			for (j = 0; j < 11; j++){
				printf("%c ", string[j]);
			}
			printf("\n");
		}

	} while (flug_R1 != 0); //交換がなかったとき終了

	return 0;
}

prodaction_R2(){

	int flug_R2;

	do{ //R2：文字順序下が右にある　∧　文字順序上が左にある　→　文字順序下を左に移動する

		flug_R2 = 0; //フラグ初期化

		for (i = 0; i < 12; i++){

			if (isalpha(string[i]) && isalpha(string[i+1])){
				ascii_l = string[i];
				ascii_r = string[i+1];
			if (ascii_l < ascii_r){ //アスキーコード順で判定

				ireko = string[i];
				string[i] = string[i + 1]; //R1適用　
				string[i + 1] = ireko;

				flug_R2 = flug_R2 + 1; //フラグに加算する
			}}

			for (j = 0; j < 11; j++){
				printf("%c ", string[j]);
			}
			printf("\n");

		}
	} while (flug_R2 != 0); //交換がなかったとき終了

	return 0;
}

prodaction_R3(){

	int flug_R3;

	do{ //R3：記号順序上が右にある　∧　記号順序下が左にある　→　記号順序上を左に移動する

		flug_R3 = 0; //フラグ初期化

		for (i = 0; i < 12; i++){

			if (ispunct(string[i]) && ispunct(string[i + 1])){ //ispunctは記号であるか判定する関数
				ascii_l = string[i];
				ascii_r = string[i + 1];
			if (ascii_l > ascii_r){ //アスキーコード順で判定

				ireko = string[i];
				string[i] = string[i + 1]; //R1適用　
				string[i + 1] = ireko;

				flug_R3 = flug_R3 + 1; //フラグに加算する
			}}

			for (j = 0; j < 11; j++){
				printf("%c ", string[j]);
			}
			    printf("\n");
			}

	} while (flug_R3 != 0); //交換がなかったとき終了

	return 0;
}

prodaction_R4(){

	int flug_R4;

	do{ //R4：「*」が「/」の左以外にある　∧　「/」が「*」の右以外にある　→　「*」を右に移動する

		flug_R4 = 0; //フラグ初期化

		for (i = 0; i < 12; i++){

			if (string[i] == '*' && string[i+1] != '/'){
				ireko = string[i+1];
				string[i+1] = string[i]; //R1適用　
				string[i] = ireko;

				flug_R4 = flug_R4 + 1; //フラグに加算する
			}}

			for (j = 0; j < 11; j++){
				printf("%c ", string[j]);
			}
			printf("\n");
		
	}while (flug_R4 != 0); //交換がなかったとき終了

	return 0;
}