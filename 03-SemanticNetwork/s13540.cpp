#include <stdio.h>
#include<string.h>

int main(){
	/*
	生物-呼吸する
	|
	鳥-翼がある
	|
	オーム-特技はモノマネ
	*/

	//各要素を格納
	char element[6][20] = {
		 "生物",
		 "呼吸する",
		 "鳥",
		 "翼がある",
		 "オーム",
		 "モノマネ"
	};

	//各要素の隣接リスト
	int connect[6][4]{
		{-1,2,1,-1},
		{0,-1,-1,-1},
		{0,4,3,-1},
		{2,-1,-1,-1},
		{2,-1,-1,5},
		{4,-1,-1,-1},
	};
	//{"上位概念","下位概念","属性","特技"}

	//意味ネットワークを出力
	int i = 0;
	while (1){
		printf("%s", element[i]);
		if (connect[i][2] != -1){
			printf("—(属性)%s", element[connect[i][2]]);
		}
		if (connect[i][3] != -1){
			printf("—(特技)%s", element[connect[i][3]]);
		}
		if (connect[i][1] != -1){
			i = connect[i][1];
			printf("\n｜\n");
		}
		else break;
	}

	//質問:オームの特技はなんですか
	printf("\n\n質問:オームの特技はなんですか\n");
	int c = 4; //オームの格納されている位置
	int d = 3; //特技の格納されている位置

	//特技が存在する場合その内容を出力する
	if (connect[c][d] != -1)printf("回答:%s\n", element[connect[c][d]]);
	else{
		while (1){
			if (connect[c][0] != -1)c = connect[c][0]; //上位概念が存在する場合その概念に移動する

			//上位概念が存在しない場合=見つからなかった よってnoを返す
			else {
				printf("回答:なし\n");
				break;
			}

			//特技が存在する場合その内容を出力する
			if (connect[c][d] != -1){
				printf("回答:%s\n", element[connect[c][d]]);
				break;
			}
		}
	}

	//質問:オームは呼吸するか
	printf("\n質問:オームは呼吸するか\n");
	c=4; //オームの格納されている位置
	char question[10] = "呼吸する"; //質問内容(この文字列と一致するか調べる)

	printf("%s", element[c]);

	//属性が存在する かつ 質問内容と属性の内容が一致
	//の場合yesを返す
	if (connect[c][2] != -1 && strcmp(element[connect[c][2]], question)==0){
		printf("—%s★\n", element[connect[c][2]]);
		printf("回答:yes\n");
	}
	else{

		while (1){
			//上位概念が存在する場合その概念に移動する
			if (connect[c][0] != -1){
				c = connect[c][0];
				printf("\n|\n%s", element[c]);
			}

			//上位概念が存在しない場合=見つからなかった よってnoを返す
			else {
				printf("\n回答:no\n");
				break;
			}

			//属性が存在する かつ 質問内容と属性の内容が一致 の場合yesを返す
			if (connect[c][2] != -1 && strcmp(element[connect[c][2]], question) == 0){
				printf("—%s★\n", element[connect[c][2]]);
				printf("\n回答:yes\n");
				break;
			}

		}
	}
}
