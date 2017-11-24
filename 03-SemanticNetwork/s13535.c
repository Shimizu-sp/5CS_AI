#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct _NODE {

	//名前や特徴が格納される
	char chara[100];
	//ノードの性質を示す
	//1・・・「生物」や「鳥」といった名詞を示すとき
	//2・・・「呼吸する」や「翼がある」といった特徴を示すとき
	//3・・・「モノマネ」といった特技を示すとき
	int type;

	//ブランチ部分
	//特徴ノードにつながる
	struct _NODE *ch;
	//is-a関係で親をたどる
	struct _NODE *back;
}NODE;

NODE *MakeTree();
int Answer(NODE *node, char str[100]);

int main() {

	char str[101];
	int str_len;
	int flag=0;
	NODE *node;

	//木を作成する
	node = MakeTree();

	while (flag != 2) {
		//キーボードからの入力を受け付ける
		flag = 0;
		while (flag == 0) {
			printf("文字を入力してください（100文字以内）\n終了と入力するとプログラムを終了します\n");
			printf("->");
			scanf("%100s", str);
			//キャッシュクリア
			scanf("%*[^\n]%*c");
			//文字数確認
			str_len = strlen(str);

			if (str_len == 101) {
				printf("100文字以内で入力してください\n");
			}
			else if (strcmp(str, "終了") == 0) flag = 2;
			else flag = 1;
		}

		//木の探索を行い、結果を表示する
		Answer(node, str);
	}

	return 0;
}

NODE *MakeTree() {
	//is-a関係でつながる節
	NODE *seibutu, *tori, *oumu;
	//特徴を示す節
	NODE *kokyu, *tubasa, *monomane;
	
	seibutu = (NODE*)malloc(sizeof(NODE));
	tori = (NODE*)malloc(sizeof(NODE));
	oumu = (NODE*)malloc(sizeof(NODE));

	if (seibutu == NULL || tori == NULL || oumu == NULL) {
		printf("メモリの確保に失敗しました（名詞ノード時）");
		return -1;
	}

	kokyu = (NODE*)malloc(sizeof(NODE));
	tubasa = (NODE*)malloc(sizeof(NODE));
	monomane = (NODE*)malloc(sizeof(NODE));

	if (kokyu == NULL || tubasa == NULL || monomane == NULL) {
		printf("メモリの確保に失敗しました（特徴ノード時）");
		return -1;
	}
	//生物ノード作成
	seibutu->type = 1;
	strcpy(seibutu->chara,"生物");
	seibutu->ch = kokyu;
	seibutu->back = NULL;

	//呼吸をするノード作成
	kokyu->type = 2;
	strcpy(kokyu->chara, "呼吸");
	kokyu->ch = NULL;
	kokyu->back = seibutu;

	//鳥ノード作成
	tori->type = 1;
	strcpy(tori->chara, "鳥");
	tori->ch = tubasa;
	tori->back = seibutu;

	//翼があるノード作成
	tubasa->type = 2;
	strcpy(tubasa->chara, "翼");
	tubasa->ch = NULL;
	tubasa->back = tori;

	//オウムノーム作成
	oumu->type = 1;
	strcpy(oumu->chara, "オーム");
	oumu->ch = monomane;
	oumu->back = tori;

	//モノマネノード作成
	monomane->type = 3;
	strcpy(monomane->chara, "モノマネ");
	monomane->ch = NULL;
	monomane->back = oumu;

	return oumu;

}

int Answer(NODE *node, char str[100]){
	NODE *start;
	char *subject, *question, *sub;
	char *ret;
	int flag=0;

	if(node==NULL){
		printf("意味ネットワークが入力されていません");
	}

	start = node;

	//主語と質問部分に分ける
	subject = _mbstok(str, "は");
	if (subject == NULL) {
		printf("質問が解析できませんでした\n");
		return -1;
	}
	question = _mbstok(NULL, "?？");
	
	//「○○"の"△△は～」だとyes/noでは答えられない質問
	//「○○は～」だとyes/noで答えられる質問と仮定
	if ((ret = strstr(subject, "の")) != NULL) {
		subject = _mbstok(subject, "の");
		sub = _mbstok(NULL, "");

		
		while (flag == 0) {
			if (strcmp(node->chara, subject) == 0) {
				while (1) {
					//特技を示すブランチはtype3に分類してあるのでそれで分岐
					if (strcmp(sub,"特技")==0 && node->ch->type == 3) {
						printf("%s\n", node->ch->chara);
						flag = 1;
						break;
					}
					else if(node->back != NULL){
						printf("概念：%sでは「%s」か分からないため上位概念：%sを参照します\n",node->chara,sub,node->back->chara);
						node = node->back;
					}
					else {
						printf("概念：%sに、%sについての関係がありません\n", subject, sub);
						flag = 1;
						break;
					}
				}
			}
			else {
				if (node->back != NULL) node = node->back;
				else {
					printf("意味ネットワークに%sが存在しません\n", subject);
					flag = 1;
				}
			}
		}
	}
	else {
		while (flag == 0) {
			if (strcmp(node->chara, subject) == 0) {
				while (1) {
					if ((ret = _mbsstr(question, node->ch->chara)) != NULL) {
						printf("Yes\n");
						flag = 1;
						break;
					}
					else if (node->back != NULL) { 
						printf("概念：%sでは「%s」が分からないため上位概念：%sを参照します\n", node->chara, question, node->back->chara);
						node = node->back;
					}
					else {
						printf("No\n");
						flag = 1;
						break;
					}
				}
			}
			else {
				if (node->back != NULL) node = node->back;
				else {
					printf("意味ネットワークに%sが存在しません\n", subject);
					flag = 1;
				}
			}
		}
	}

	printf("\n");
	
	return 0;
}