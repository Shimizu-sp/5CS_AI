#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
	char tori[] = {"鳥は生物である"},
		 oumu[] = {"オームは鳥である"},
		 seibutsu[] = {"生物は呼吸する"},
		 tsubasa[] = {"鳥には翼がある"},
		 monomane[] = {"オームの特技はモノマネである"};

	char check_tori[] = {"鳥"},
		 check_oumu[] = {"オーム"},
		 check_seibutsu[] = {"生物"},
		 check_kokyuu[] = {"呼吸"},
		 check_monomane[] = {"モノマネ"};
	
	char Q[1000], Q2[1000];
	int i;


	printf("「オームの特技はなんですか」と質問してください。\n質問：");
	gets(Q);/*オームの特技はなんですかと入力*/

	if(!strcmp(Q, "オームの特技はなんですか")){ /*オームの特技はなんですか　と入力されていたらif文に入る*/

		if(strstr(Q,check_oumu)){ /*入力された文に配列check_oumuが含まれたいたらcheck_monomaneを表示*/

			printf("\n%s\n",check_monomane);

		}

	}else{/*違う文字列が入力された場合*/

		printf("\n指定された質問を入力してください\n");
		exit(0);/*プログラム終了*/

	}

	printf("\n------------------------------\n");
	printf("\n「オームは呼吸するか」と質問してください。\n質問：");
	gets(Q2);/*オームは呼吸するかと入力*/

	if(!strcmp(Q2, "オームは呼吸するか")){ /*オームは呼吸するか　と入力されたらif文に入る*/

		if(strstr(Q2,check_oumu)){ /*入力された文に配列check_oumuが含まれていたらif文に入る*/

			if(strstr(oumu,check_tori)){ /*配列oumuに配列check_toriが含まれていたら以下の文を表示し、if文に入る*/

				printf("\n・オーム is-a 鳥である");

				if(strstr(tori,check_seibutsu)){ /*配列toriに配列check_seibutsuが含まれていたら以下の文を表示し、if文に入る*/

					printf("\n・鳥 is-a 生物である");

					if(strstr(seibutsu,check_kokyuu)){ /*配列seibutsuに配列check_kokyuuが含まれていたら以下の文を表示する*/

						printf("\n・生物は呼吸する\n以上より、オームは生物である");
						printf("\nAns：Yes\n\n");

					}
				}
			}
		}
	}else{ /*違う文字列が入力された場合*/
		printf("\n指定された質問を入力してください\n");
		exit(0);/*プログラム終了*/
	}
}
