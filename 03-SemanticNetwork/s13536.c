#include<stdio.h>
#include<string.h>

	struct a{
		char *topic;
		char *connect;
		char *chara;
	}
	main(void){
		char input[30];
		char *w1 = "オーム";
		char *w2 = "特技";
		char *w3 = "呼吸をする";
		int i , n , count = 0;

		struct a owm[20] = 
		{
			{"オーム","分類","鳥"},
			{"オーム","特技","モノマネ"},
			{"鳥","分類","生物"},
			{"鳥","特徴","翼を持つ"},
			{"生物","特徴","呼吸をする"},
		};// 知識記憶 {"第一項目","第二項目","第三項目"}

	while(1){
	scanf("%s",input);		
		if(strcmp(input,"オームの特技は何ですか") == 0){
			for(i=0;i<5;i++){
				if(owm[i].connect == w2){// i番目の第二項目が"特技"だった場合
					printf("%s",owm[i].chara);// 表示
					getchar();
					count++;
					break;// 終了
			}
			}
		}
			getchar();
		if(strcmp(input,"オームは呼吸するか") == 0){
			for(i=0;i<5;i++){
				printf("%sの%sは%s\n",owm[i].topic,owm[i].connect,owm[i].chara);// i番目の表示　{}
				for(n=0;n<5;n++){
					// i番目の第三項目がn番目の第一項目だった場合
					if(owm[i].chara == owm[n].topic){
						i = n - 1;// iにn-1を代入
						break;
					}
				}
				// i番目の第三項目が"呼吸をする"だった場合
				if(owm[i].chara == w3){
					printf("Yes");// Yesと表示
					getchar();
					count++;
					break;// 終了
				}
			}
		}
	if(count == 1){
		break;
	}else{
		printf("もう一度入力してください\n");
	}
	}
	}