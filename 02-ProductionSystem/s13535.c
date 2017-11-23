#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


//文字列をリストで表現
typedef struct _Data{
	char c;		//文字
	int x;		//文字コード
	int type;	//タグ　アルファベットなら1、記号なら0

	//単方向リスト
	struct _Data *next;
}Data;


//入力状態と終了状態
char start[11] = "a*b-cd/e+fg";
char goal[11] = "gfedcba+-*/";


//プロダクションメモリ
//R1・・・文字コードの値が0x41以上0x5a以下または、0x61以上0x7a以下ならその文字はアルファベット
//R2・・・文字コードの値がR1に満たない場合、その文字は記号
//R3・・・隣り合った2つの文字が記号とアルファベットならアルファベットを前に持っていく
//R4・・・隣り合った2つの文字がどちらもアルファベットなら文字コードの値を比較し、大きいほうを前に持っていく
//R5・・・隣り合った2つの文字列の前の文字が'*'のとき、後ろの文字が'/'でないなら'*'を後ろに持っていく
//R6・・・後ろの文字が'*'でないとき、隣り合った2つの文字がどちらも記号なら文字コードの値を比較し、小さいほうを前に持っていく


//関数プロトタイプ宣言
int MainSearch(Data *data);
int Add(Data *data, char c);
int ListChange(Data *data);
int PM_R1R2(Data *data);
int PM_R3(Data *data);
int PM_R4(Data *data);
int PM_R5(Data *data);
int PM_R6(Data *data);
void ShowString(Data *data);


int main(){

	int i;
	Data *data, *data_s;

	//リストの先頭を作成
	data = (Data*)malloc(sizeof(Data));
	data->c = 'S';
	data->x = -1;
	data->type = -1;
	data->next = NULL;

	//リストの先頭を記憶
	data_s = data;

	//初期入力
	for (i = 0; i < 11;i++){
		Add(data, start[i]);
		data = data->next;
		PM_R1R2(data);
	}

	//メインループ
	MainSearch(data_s);

	getchar();

	return 0;
}

//引数にはリストの先頭を渡す必要がある
int MainSearch(Data *data){
	int i;
	int count=0;

	Data *data_s;

	data_s = data;

	//現在の状態を表示
	ShowString(data_s);

	//メイン探索
	while (1){
		//リストの先頭へ
		data = data_s;
		//リスト内探索
		while (1) {
			if (data->x > 0){
				//PMにひとつでも当てはまるものがあれば適用したのち、文字列(リスト)の先頭に戻る
				if (PM_R3(data) == 1)break;
				if (PM_R4(data) == 1)break;
				if (PM_R5(data) == 1)break;
				if (PM_R6(data) == 1)break;
			}
			data = data->next;
			if (data->next == NULL) break;
		}

		//現在の状態を表示
		ShowString(data_s);

		//リストの先頭へ
		data = data_s;
		//ゴール状態と同様の並び順の時、並び替えを終了する
		count = 0;
		for (i = 0; i < 11; i++){
			data = data->next;
			if (data->c == goal[i]) count++;
		}
		if (count == 11) break;	
	}
}

//リストに追加する
int Add(Data *data, char c){

	Data *input;

	input = (Data*)malloc(sizeof(Data));

	input->x = c;
	input->c = c;
	input->next = NULL;

	data->next = input;

	return 0;
}

//リストから２つのノードを並び替える
//並び替えたい２つのノードのうち、前のノードを引数とする
int ListChange(Data *data){
	Data save; //ノードを置き換えるために使う

	if (data == NULL || data->next == NULL){
		printf("error: ListChange 不正な値が入力されました");
		return -1;
	}

	//一時的に保存
	save.c = data->next->c;
	save.x = data->next->x;
	save.type = data->next->type;
	save.next = data->next;

	//データの入れ替え作業
	data->next->c = data->c;
	data->next->x = data->x;
	data->next->type = data->type;
	data->next->next = data->next->next;

	data->c = save.c;
	data->x = save.x;
	data->type = save.type;
	data->next = save.next;

	return 0;
}

//プロダクションメモリの内容を適用する

//R1・・・文字コードの値が0x41以上0x5a以下または、0x61以上0x7a以下ならその文字はアルファベット
//R2・・・文字コードの値がR1に満たない場合、その文字は記号
int PM_R1R2(Data *data){
	if (data == NULL){
		printf("error: PM_R1R2 不正な値が入力されました");
		return -1;
	}
	if (data->x >= 0x41 && data->x <= 0x5a || data->x >= 0x61 && data->x <= 0x7a) data->type = 1;
	else data->type = 0;

	return 0;
}

//条件を満たし、ルールを適用したら1を返す
//R3・・・隣り合った2つの文字が記号とアルファベットならアルファベットを前に持っていく
int PM_R3(Data *data){
	if (data == NULL || data->next == NULL){
		printf("error: PM_R3 不正な値が入力されました");
		return -1;
	}

	if (data->type == 0 && data->next->type == 1) {
		ListChange(data);
		return 1;
	}

	return 0;
}

//条件を満たし、ルールを適用したら1を返す
//R4・・・隣り合った2つの文字がどちらもアルファベットなら文字コードの値を比較し、大きいほうを前に持っていく
int PM_R4(Data *data){
	if (data == NULL || data->next == NULL){
		printf("error: PM_R4 不正な値が入力されました");
		return -1;
	}

	if (data->type == 1 && data->next->type == 1 && data->x < data->next->x) {
		ListChange(data);
		return 1;
	}

	return 0;
}

//条件を満たし、ルールを適用したら1を返す
//R5・・・隣り合った2つの文字列の前の文字が'*'のとき、後ろの文字が'/'でないなら'*'を後ろに持っていく
int PM_R5(Data *data){
	if (data == NULL || data->next == NULL){
		printf("error: PM_R5 不正な値が入力されました");
		return -1;
	}

	if (data->c == '*' && data->next->c != '/') {
		ListChange(data);
		return 1;
	}

	return 0;
}

//条件を満たし、ルールを適用したら1を返す
//R6・・・後ろの文字が'*'でないとき、隣り合った2つの文字がどちらも記号なら文字コードの値を比較し、小さいほうを前に持っていく
int PM_R6(Data *data){
	if (data == NULL || data->next == NULL){
		printf("error: PM_R6 不正な値が入力されました");
		return -1;
	}

	if (data->type == 0 && data->next->type == 0 && data->x > data->next->x && data->next->c != '*') {
		ListChange(data);
		return 1;
	}

	return 0;
}

//文字列を表示する 引数にはリストの先頭を渡す必要あり
void ShowString(Data *data){

	while (1){
		if (data->x > 0) printf("%c", data->c);
		if (data->next == NULL) break;
		data = data->next;
	}

	printf("\n");
}