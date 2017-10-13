#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

//useful
#define SHOW(x) printf("%d %d %d\n%d %d %d\n%d %d %d\n\n",x[0][0],x[0][1],x[0][2],x[1][0],x[1][1],x[1][2],x[2][0],x[2][1],x[2][2]);
#define MEMORI(x) if(NULL == ( (x) = (Box*)malloc( sizeof(Box) ) )) perror("malloc fanction output err.");



/* 構造体の定義 */
struct Box{

	int pazzle_model[3][3];//パズルの状態
	int hierarchy;//階層
	int ID;//ノード番号
	int FChi;//F値
	struct Box* next[4];//リスト next[0]は左に移動 next[1]は上に移動 next[2]は下に移動 next[3]は右に移動
};
typedef struct Box Box;

struct List {

	Box* Addr;
	struct List* next;
}; 
typedef struct List List;

int goal[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };//ぐろーばる変数

List* openlist=NULL;
List* closelist=NULL;
List* closelistS = NULL;


Box* OpenListR();//読み込み用オープンリスト
int OpenListW(Box* box);//書き込み用オープンリスト 引数として手に持っているboxを渡す

int CloseListR(Box* box);//読み込み用クローズリスト
int CloseListW(Box* box);//書き込み用クローズリスト　引数としてboxを渡す

int Fchi(int FChi);//入力したF値(引数)書き出し用　
int Pazzle(int pazzle_model[3][3]);//入力したパズルの型書き出し

int CreateBox(Box* nextbox);//パズルの次の状態を作成してくれる関数　引数に現在のパズルの状態を渡す
int MANHATTAN(int start[3][3]);

int main(){

	int start[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } };
	int save[3][3];
	int i, j, no;
	int total = -1;
	int mannhattan;
	Box* box;
	Box* p;//ずっと手に持っておかないといけない箱

	MEMORI(box);
	//プログラムはここから
	box->ID=1;
	box->hierarchy = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			box->pazzle_model[i][j] = start[i][j];
		}
	}
	box->FChi = box->hierarchy + MANHATTAN(box->pazzle_model);
	if(MANHATTAN(box->pazzle_model) == 0){
		Fchi(box->FChi);
		Pazzle(box->pazzle_model);
		return 0;
	}
	CloseListW(box);

	p = box;
	while(1){
		CreateBox(box);
		Fchi(box->FChi);
		Pazzle(box->pazzle_model);
		if (MANHATTAN(box->pazzle_model) == 0) {
			Fchi(box->FChi);
			Pazzle(box->pazzle_model);
			return 0;
		}
		CloseListW(box);
		for (i = 0; i < 4; i++) {
			if (box->next[i] != NULL) {
				if (CloseListR(closelistS)== 0){
					OpenListW(box->next[i]);
				}
			}
		}
			box = OpenListR();
	}
	//ここまで
	free(box);
	getchar();
}

int MANHATTAN(int start[3][3]){
	int i, j, s;
	int mani[9], manj[9];
	int total = 0;
	int subi[9], subj[9];

	//マンハッタン距離の計算
	for (s = 1; s < 9; s++){
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (start[i][j] == s){

					//printf("現在%dの場所 %d %d\n", s, i, j);//値の座標表示
					mani[s] = i;
					manj[s] = j;

				}
			}
		}
	}
	for (s = 1; s < 9; s++){
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (goal[i][j] == s){

					//printf("最終の%dの場所 %d %d\n", s, i, j);//値の座標表示
					subi[s] = i;
					subj[s] = j;
				}
			}
		}
	}
	for (s = 1; s < 9; s++){
		total += abs(mani[s] - subi[s]) + abs(manj[s] - subj[s]);
	}

	printf("%d\n", total);

	return total;

}

//読み込み用オープンリスト
Box* OpenListR() {
	List* p = openlist;
	int fnow,fnext;
	List* smallmemo;
	List* b = NULL;
	Box* addr;

	fnow = p->Addr->FChi;
	p = p->next;
	if (p == NULL) {
		addr = openlist->Addr;
		free(openlist);
		openlist = NULL;
		return addr;
	}
	fnext = p->Addr->FChi;
	if (fnow > fnext) {
		smallmemo = p;
	}
	else {
		smallmemo = openlist;
	}
	while (1) {
		fnow = p->Addr->FChi;
		p = p->next;
		if (p->next == NULL) {
			
			p = openlist;
			
			while (1) {
				if (p == smallmemo && b==NULL) {
					openlist = p->next;
					break;
				}
				b = p;
				p = p->next;
				if (p == smallmemo ) {
					b->next = p->next;
					break;
				}
			}
			addr = smallmemo->Addr;
			free(p);
			return addr;
		}
	}
}

//書き込み用オープンリスト 引数として手に持っているboxを渡す
int OpenListW(Box* box){
	List* memo;//今持っている箱のアドレスのメモ
	if (1==CloseListR(box)) {//もしCloselistに同じのがあった場合
		return 0;
	}
	if (openlist == NULL) {
		MEMORI(openlist);
		openlist->Addr = box;
		openlist->next = NULL;
	}

	memo = openlist;
	MEMORI(openlist);
	openlist->Addr = box;
	openlist->next = memo;
	return 0;
}

//読み込み用クローズリスト
int CloseListR(Box* box) {
	List* p = closelist;
	int n, m;
	int counter = 0;

	if (closelist == NULL) {
		return 1;
	}
	while (1) {
		for (n = 0; n < 3; n++) {
			for (m = 0; m < 3; m++) {
				if (p->Addr->pazzle_model[n][m] == box->pazzle_model[n][m]) {
					counter++;
				}
			}
		}
		if (counter == 8) {
			return 1;
		}
		counter = 0;

		p = p->next;
		if (p->next == NULL) {
			return 0;
		}
	}
}

//書き込み用クローズリスト　引数としてboxを渡す
int CloseListW(Box* box){
	List* memo;//今持っている箱のアドレスのメモ
	
	if (closelist == NULL) {
		MEMORI(closelist);
		closelist->Addr = box;
		closelist->next = NULL;
		closelistS = closelist;
	}

	memo = closelist;
	MEMORI(closelist);
	closelist->Addr = box;
	closelist->next = memo;
	return 0;
}

//F値書き出し用　
int Fchi(int FChi) {
	FILE* outfchi;         // 出力ストリーム

	outfchi = fopen("fchi.txt", "a+");  // ファイルを書き込み用にオープン(開く)
	if (outfchi == NULL) {          // オープンに失敗した場合
		printf("can't open\n");         // エラーメッセージを出して
		exit(1);                         // 異常終了
	}

	fprintf(outfchi,"%d\n",FChi); // ファイルに書く

	fclose(outfchi);          // ファイルをクローズ(閉じる)
	return 0;
}

//パズルの型書き出し
int Pazzle(int pazzle_model[3][3]){
	FILE* outpazzlemodel;         // 出力ストリーム

	outpazzlemodel = fopen("pazzle.txt", "a+");  // ファイルを書き込み用にオープン(開く)
	if (outpazzlemodel == NULL) {          // オープンに失敗した場合
		printf("can't open\n");         // エラーメッセージを出して
		exit(1);                         // 異常終了
	}

	fprintf(outpazzlemodel, "%d %d %d\n%d %d %d\n%d %d %d\n\n",pazzle_model[0][0], pazzle_model[0][1], pazzle_model[0][2], pazzle_model[1][0], pazzle_model[1][1], pazzle_model[1][2], pazzle_model[2][0], pazzle_model[2][1], pazzle_model[2][2]); // ファイルに書く

	fclose(outpazzlemodel);          // ファイルをクローズ(閉じる)
	return 0;
}

int CreateBox(Box* nextbox) {
	//Boxのnextを作成したときに構造体の中身を自動作成するようにする
	int i, j;
	int q;
	static int ID = 1;
	int nowpazzle[3][3];
	int n, m;

	for (q = 0; q < 4; q++) {
		MEMORI(nextbox->next[q]);

		for (n = 0; n < 3; n++) {
			for (m = 0; m < 3; m++) {
				nowpazzle[n][m] = nextbox->pazzle_model[n][m];
			}
		}
		for (n = 0; n < 3; n++) {
			for (m = 0; m < 3; m++) {
				nextbox->next[q]->pazzle_model[n][m] = nextbox->pazzle_model[n][m];
			}
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (nowpazzle[i][j] == 0) {
				//left
				if (j != 0) {
					//座標の入れ替え
					nextbox->next[0]->pazzle_model[i][j] = nextbox->next[0]->pazzle_model[i][j - 1];
					nextbox->next[0]->pazzle_model[i][j - 1] = 0;
				}
				else {
					nextbox->next[0] = NULL;
				}

				//up
				if (i != 0) {
					//座標の入れ替え
					nextbox->next[1]->pazzle_model[i][j] = nextbox->next[1]->pazzle_model[i - 1][j];
					nextbox->next[1]->pazzle_model[i - 1][j] = 0;
				}
				else {
					nextbox->next[1] = NULL;
				}

				//down
				if (i != 2) {
					//座標の入れ替え
					nextbox->next[2]->pazzle_model[i][j] = nextbox->next[2]->pazzle_model[i + 1][j];
					nextbox->next[2]->pazzle_model[i + 1][j] = 0;
				}
				else {
					nextbox->next[2] = NULL;
				}

				//right
				if (j != 2) {
					//座標の入れ替え
					nextbox->next[3]->pazzle_model[i][j] = nextbox->next[3]->pazzle_model[i][j + 1];
					nextbox->next[3]->pazzle_model[i][j + 1] = 0;

				}
				else {
					nextbox->next[3] = NULL;
				}
			}
		}
	}
	printf("\n%d\n", nextbox->hierarchy);
	for (q = 0; q < 4; q++) {
		if (nextbox->next[q] != NULL) {
			nextbox->next[q]->hierarchy = nextbox->hierarchy + 1;
			nextbox->next[q]->ID = ID;
			nextbox->next[q]->FChi = nextbox->next[q]->hierarchy + MANHATTAN(nextbox->next[q]->pazzle_model);
			ID++;
		}
	}
}