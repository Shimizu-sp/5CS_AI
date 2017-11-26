/*
**作成プログラム:意味ネットワーク
**作成者:桑原大輔
**動作環境:Visual Studio 2012
**拡張性：ネットワークのノード数および1つのノードからつながる子ノードの数は無限
*/
//Visual Studio用設定欄
#pragma warning(disable:4996)

//ヘッダ読み込み
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//マクロ定義

//特長を格納する変数のメモリ確保を行うマクロ関数引数の意味は「x:作成する文字列を持つNetwork*，a:特徴の数，b:特長とキーワードが収まる最小の値」
#define STR(x,a,b) \
	for(i=0;i<2;i++){\
		if(NULL==((x)->forte[i]=(char**)malloc(sizeof(char*)*(a)))){\
			perror("malloc");\
			return -1;\
		}\
		for(j=0;j<a;j++){\
			if(NULL==((x)->forte[i][j]=(char*)malloc(sizeof(char)*(b)))){\
				perror("malloc");\
				return -1;\
			}\
		}\
	}\
	(x)->char_length[0]=(a);\
	(x)->char_length[1]=(b);



//構造体定義

//意味ネットワークの各ノードを示す構造体
typedef struct def_Network{
	char name[100];					//ノードの名前を格納する
	char** forte[2];				//[1]に特長を，[0]に特徴がヒットするキーワードを格納する
	unsigned int char_length[2];	//forte配列の大きさを格納する
	unsigned int serch_flag;
	struct def_Network** next;		//下層のネットワークにつながるポインタ
	unsigned int next_num;			//自分につながっているノードの数を格納する
	struct def_Network* back;		//自分の上位のネットワークにつながるポインタ
} Network;

//関数プロトタイプ定義
int CreateNetwork(Network* net,size_t create_num);//ネットワークを作成する関数
int FreeNetwork(Network* head);//すべてのネットワークのメモリを開放する関数
Network* GoNext(Network* net);//次にどのノードを探索すればいいのかを示す関数

int main(){
	Network* head;
	Network* p;
	char question[100];
	unsigned int i,j,n;
	int flag=0;
	char* str_head;

	//ルートのノードを作成
	if(NULL==(head=(Network*)malloc(sizeof(Network)))){
		perror("malloc");
		return -1;
	}

	//現在の検索位置をpに格納
	p=head;

	//事前に与えられたネットワークを定義
	head->name[0]='\0';
	head->serch_flag=1;

	CreateNetwork(p,1);
	p=head->next[0];

	CreateNetwork(p,1);
	
	//ノード毎の設定を行う
	p=head;

	STR(p,1,100);
	sprintf(p->name,"生物");
	sprintf(p->forte[0][0],"呼吸");
	sprintf(p->forte[1][0],"YES");

	p->back=NULL;

	p=p->next[0];

	STR(p,1,100);
	sprintf(p->name,"鳥");
	sprintf(p->forte[0][0],"羽");
	sprintf(p->forte[1][0],"羽がある");

	p=p->next[0];

	STR(p,1,100);
	sprintf(p->name,"オーム");
	sprintf(p->forte[0][0],"特技");
	sprintf(p->forte[1][0],"モノマネ");

	//質問の受付
	printf("質問を入力してください > ");
	scanf("%99s",question);
	
	question[99]='\0';
	printf("質問 : %s\n",question);

	while('\n'!=getchar());

	//pの初期化
	p=head;

	//質問対象の探索
	while(1){
		if(!flag){
			//質問対象のことを示すノードがあるかを検索
			if(NULL!=(str_head=strstr(question,p->name))){

				//検索にヒットしたのは主語かを確認
				if(question==str_head){
					//flagを変更
					flag=1;
					continue;
				}

			}

			if(NULL==(p=GoNext(head))) break;
		}
		else if(flag==1){
			//ノード内に求めている答えが存在するかを確認
			for(i=0;i<p->char_length[0];i++){

				 //特長に存在するかを確認
				if(NULL!=strstr(question,p->forte[0][i])){
					printf("回答 : %s\n",p->forte[1][i]);
					flag=2;
					break;
				}//ノードの名前に存在するかを確認	
				else if(NULL!=(str_head=strstr(&question[1],p->name))){//&question[1]としているのは「○○は△△？」という問いのときに先頭の「○○」に引っかからないようにするため
					printf("回答 : YES\n");
					flag=2;
					break;

				}
				
			}

			if(flag==2) break;

			//is-a関係で継承関係を探索したログを表示
			printf("経過 : %s is a ",p->name);
			
			if(p->back==NULL){
				printf("NULL\n");
				break;
			}
			p=p->back;

			printf("%s\n",p->name);
		}
		
	}

	//答えが見つからない場合
	if(flag==0 || flag==1) printf("ネットワーク上に答えは存在しません");

	//メモリの解放
	FreeNetwork(head);

	getchar();

	return 0;

}

//ネットワークのノードを作成する関数
//引数 net:作成したノードを連結させる元, create_num:作成するノードの数
int CreateNetwork(Network* net,size_t create_num){
	Network** p;
	size_t i;

	//例外処理
	if(create_num<=0){
		perror("create_num");
		return -1;
	}
	
	//メモリ確保
	if(NULL==(p=(Network**)malloc(sizeof(Network*)*create_num))){
		perror("CreateNetwork->malloc");
		return -2;
	}
	for(i=0;i<create_num;i++){
		if(NULL==(p[i]=(Network*)malloc(sizeof(Network)))){
			perror("CreateNetwork->malloc");
			return -2;
		}
	}

	//netの値に必要な情報を代入
	net->next_num=(unsigned int)create_num;

	//作成したネットワークの値を初期化
	for(i=0;i<create_num;i++){
		net->next=p;

		p[i]->serch_flag=0;
		p[i]->forte[0]=NULL;
		p[i]->forte[1]=NULL;
		p[i]->name[0]='\0';
		p[i]->char_length[0]=0;
		p[i]->char_length[1]=0;
		p[i]->next=NULL;
		p[i]->next_num=0;
		p[i]->back=net;
	}
	

	return 0;
}

//すべてのネットワークのメモリを開放する関数
//引数 head:ネットワークのノードを示すポインタ
int FreeNetwork(Network* head){
	int i;

	//文字列の解放
	for(i=0;i<head->char_length[0];i++) free(head->forte[0][i]);
	for(i=0;i<head->char_length[0];i++) free(head->forte[1][i]);
	free(head->forte[0]);
	free(head->forte[1]);

	//自分より下のノードを解放
	if(head->next!=NULL) for(i=0;i<head->next_num;i++) FreeNetwork(head->next[i]);

	//自信を解放
	free(head);

	return 0;

}

//次にどのノードを探索すればいいのかを示す再起関数
//全探索で探索していないものを探す
//引数 head:ネットワークのノードを示すポインタ
Network* GoNext(Network* head){
	unsigned int i;
	Network* ret=NULL;

	//自身が未探索であれば自分を返す
	if(head->serch_flag==0){
		head->serch_flag=1;
		return head;
	}

	//next==NULLならばNULLを返す
	if(head->next==NULL) return NULL;

	//自身が未探索でない場合，次の層を探索する
	for(i=0;i<head->next_num;i++) if(NULL!=(ret=GoNext(head->next[i]))) break;
	
	//下層の探索から戻ってきた戻り値を返す
	return ret;

}