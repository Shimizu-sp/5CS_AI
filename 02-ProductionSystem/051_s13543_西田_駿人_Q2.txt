#include <stdio.h>

void change(char *);
char str[11] = "a*b-cd/e+fg";//初期配列
char strS[11] = "a*b-cd/e+fg"; //サンプル用初期配列

main()
{
	printf("初期状態 : %s\n\n", str);//初期状態を表示

	change(str);//実行する関数

	printf("\n完成　%s\n\n", str);//完成状態を表示
	
}
void change(char *ansstr) {
	int ans = 0;
	int i = 0;
	int j = 0; //文字数を管理
	int strans[] = { 11,10,8,6,5,3,1,9,4,2,7 }; //ルール
	char tmp = "";//仮保存用

	for (j=0; j < 11; j++) {

		ans = strans[j]-1;//配列にぶち込む関係で-1する
		printf("%cを探して移動\n", strS[ans]);
		
			
			//printf("%cを探します\n", str[ans]);
			//printf("I = %d\n", i);
			//printf("J = %d\n", j);
		while (str[j] != strS[ans]) {
			for (i = 0; i < 11; i++) { //1文字目から順にチェック
				if (str[i] == strS[ans]) { //見つけたら左と交換
					tmp = str[i];
					str[i] = str[i - 1];
					str[i - 1] = tmp;
					printf("%s\n", str);
				}
			}
		}
		
		printf("%d 文字目(%c)おわり\n", j + 1,strS[ans]);//進捗報告
		printf("現在　%s\n\n", str);//進捗報告
	
	}
}

