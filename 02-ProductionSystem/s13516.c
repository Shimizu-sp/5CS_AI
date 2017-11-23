#include <stdio.h>
#include <ctype.h>
#include<string.h>

//int ProductionMemory(char *W);

main(){
	char W[] = "gfed-cba+*/";  //初期値
	char end[] = "gfedcba+-*/";  //ゴール

	int i;
	int hikaku = 0;


	ProductionMemory(W,end);

}

int ProductionMemory(char *W,char *end){
	int i;
	int j;
	int change;
	int place_g, place_f, place_e, place_d, place_c, place_b, place_a, place_plus, place_mai, place_kake, place_wa;
	int hikaku=0;

	while (hikaku!=1){
			if (W[0] != 'g'){   //gが一番左じゃなかったらgを一つ左にずらす
				for (j = 0; j < 11; j++){
					if (W[j] == 'g'){
						place_g = j;
						break;
					}
				}
				change = W[place_g];
				W[place_g] = W[place_g - 1];
				W[place_g - 1] = change;

				for (j = 0; j < 11; j++){

					printf("%c", W[j]);
				}printf("  R1を適用");
				printf("\n");
			}
			else if (W[1] != 'f'){   //fが左から2番目じゃなかったらfを一つ左にずらす
				for (j = 0; j < 11; j++){
					if (W[j] == 'f'){
						place_f = j;
						break;
					}
				}
				change = W[place_f];
				W[place_f] = W[place_f - 1];
				W[place_f - 1] = change;

				for (j = 0; j < 11; j++){

					printf("%c", W[j]);
				}printf("  R2を適用");
				printf("\n");
			}
			else if (W[2] != 'e'){   //eが左から3番目じゃなかったらeを一つ左にずらす
				for (j = 0; j < 11; j++){
					if (W[j] == 'e'){
						place_e = j;
						break;
					}
				}
				change = W[place_e];
				W[place_e] = W[place_e - 1];
				W[place_e - 1] = change;

				for (j = 0; j < 11; j++){

					printf("%c", W[j]);
				}printf("  R3を適用");
				printf("\n");
			}
			else if (W[3] != 'd'){   //dが左から4番目じゃなかったらdを一つ左にずらす
				for (j = 0; j < 11; j++){
					if (W[j] == 'd'){
						place_d = j;
						break;
					}
				}
				change = W[place_d];
				W[place_d] = W[place_d - 1];
				W[place_d - 1] = change;

				for (j = 0; j < 11; j++){

					printf("%c", W[j]);
				}printf("  R4を適用");
				printf("\n");
			}
			else if (W[4] != 'c'){   //cが左から5番目じゃなかったらcを一つ左にずらす
				for (j = 0; j < 11; j++){
					if (W[j] == 'c'){
						place_c = j;
						break;
					}
				}
				change = W[place_c];
				W[place_c] = W[place_c - 1];
				W[place_c - 1] = change;

				for (j = 0; j < 11; j++){

					printf("%c", W[j]);
				}printf("  R5を適用");
				printf("\n");
			}
			else if (W[5] != 'b'){   //bが左から6番目じゃなかったらbを一つ左にずらす
				for (j = 0; j < 11; j++){
					if (W[j] == 'b'){
						place_b = j;
						break;
					}
				}
				change = W[place_b];
				W[place_b] = W[place_b - 1];
				W[place_b - 1] = change;

				for (j = 0; j < 11; j++){

					printf("%c", W[j]);
				}printf("  R6を適用");
				printf("\n");
			}
			else if (W[6] != 'a'){   //aが左から7番目じゃなかったらaを一つ右にずらす
				for (j = 0; j < 11; j++){
					if (W[j] == 'a'){
						place_a = j;
						break;
					}
				}
				change = W[place_a];
				W[place_a] = W[place_a + 1];
				W[place_a + 1] = change;

				for (j = 0; j < 11; j++){

					printf("%c", W[j]);
				}printf("  R7を適用");
				printf("\n");
			}
			else if (W[7] != '+'){   //+が左から8番目じゃなかったら+を一つ左にずらす
				for (j = 0; j < 11; j++){
					if (W[j] == '+'){
						place_plus = j;
						break;
					}
				}
				change = W[place_plus];
				W[place_plus] = W[place_plus - 1];
				W[place_plus - 1] = change;

				for (j = 0; j < 11; j++){

					printf("%c", W[j]);
				}printf("  R8を適用");
				printf("\n");
			}
			else if (W[8] != '-'){   //-が左から9番目じゃなかったら-を一つ左にずらす
				for (j = 0; j < 11; j++){
					if (W[j] == '-'){
						place_mai = j;
						break;
					}
				}
				change = W[place_mai];
				W[place_mai] = W[place_mai - 1];
				W[place_mai - 1] = change;

				for (j = 0; j < 11; j++){

					printf("%c", W[j]);
				}printf("  R9を適用");
				printf("\n");
			}
			else if (W[9] != '*'){   //*が左から10番目じゃなかったら*を一つ右にずらす
				for (j = 0; j < 11; j++){
					if (W[j] == '*'){
						place_kake = j;
						break;
					}
				}
				change = W[place_kake];
				W[place_kake] = W[place_kake + 1];
				W[place_kake + 1] = change;

				for (j = 0; j < 11; j++){

					printf("%c", W[j]);
				}printf("  R10を適用");
				printf("\n");
			}
			else if (W[10] != '/'){   ///が左から11番目じゃなかったら/を一つ右にずらす
				for (j = 0; j < 11; j++){
					if (W[j] == '/'){
						place_wa = j;
						break;
					}
				}
				change = W[place_wa];
				W[place_wa] = W[place_wa + 1];
				W[place_wa + 1] = change;

				for (j = 0; j < 11; j++){

					printf("%c", W[j]);
				}printf("  R11を適用");
				printf("\n");
			}
			if (strcmp(W,end)==0){
				hikaku = 1;
			}
		}

	}
