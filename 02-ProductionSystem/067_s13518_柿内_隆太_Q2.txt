#include<stdio.h>
#include<stdlib.h>

main(){
	char wm[11] = { 'a', '*', 'b', '-', 'c', 'd', '/', 'e', '+', 'f', 'g'};//ワーキングメモリ
	char st='0';//入れ替えじに一時的に値を入れるもの
	int j,i,i2;//繰返し用
	for (j = 0; j < 10;j++){
		for (i = 0; i < 10; i++){
			//printf("今の文字%c　次の文字%c\n", wm[i], wm[i + 1]);

			//片方がアルファベットか
			if (wm[i] == 'a' || wm[i] == 'b' || wm[i] == 'c' || wm[i] == 'd' || wm[i] == 'e' || wm[i] == 'f' || wm[i] == 'g'){
				if (wm[i + 1] == 'a' || wm[i + 1] == 'b' || wm[i + 1] == 'c' || wm[i + 1] == 'd' || wm[i + 1] == 'e' || wm[i + 1] == 'f' || wm[i + 1] == 'g'){
					//両方ともアルファベットだったら
					if (wm[i] == 'a'){//もし"a"が左側だったら、右側と交換する
						st = wm[i + 1];
						wm[i + 1] = wm[i];
						wm[i] = st;
					}
					else if (wm[i]=='b'&&wm[i+1]!='a'){//もし"a"が右側ではない状態かつ、左側が"b"だと入れ替える
						st = wm[i + 1];
						wm[i + 1] = wm[i];
						wm[i] = st;
					}

					else if (wm[i] == 'c'&&wm[i + 1] != 'b'){//もし"b"が右側ではない状態かつ、左側が"c"だと入れ替える
						st = wm[i + 1];
						wm[i + 1] = wm[i];
						wm[i] = st;
					}

					else if (wm[i] == 'd'&&wm[i + 1] != 'c'){//もし"c"が右側ではない状態かつ、左側が"d"だと入れ替える
						st = wm[i + 1];
						wm[i + 1] = wm[i];
						wm[i] = st;
					}

					else if (wm[i] == 'e'&&wm[i + 1] != 'd'){//もし"d"が右側ではない状態かつ、左側が"e"だと入れ替える
						st = wm[i + 1];
						wm[i + 1] = wm[i];
						wm[i] = st;
					}

					else if (wm[i] == 'f'&&wm[i + 1] != 'e'){//もし"f"が右側ではない状態かつ、左側が"d"だと入れ替える
						st = wm[i + 1];
						wm[i + 1] = wm[i];
						wm[i] = st;
					}

				}
			}else if (i > 0){//もし、左側が記号だったら
				if (wm[i + 1] == '/' || wm[i + 1] == '*'|| wm[i + 2] == '*' && wm[i + 1] == '-'){
				}else{
					st = wm[i];
					wm[i] = wm[i + 1];
					wm[i + 1] = st;
				}
			}
		}

		printf("現在のWMは以下の通りである\n");
		for (i2 = 0; i2 < 11; i2++){
			printf("%c", wm[i2]);
		}
		printf("\n");

	}

}