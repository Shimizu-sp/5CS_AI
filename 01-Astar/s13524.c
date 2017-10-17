/*
**  作成者:Daisuke Kuwahara
**  作成年:2017
**	動作環境:
**      ・Linux
**          - Linux version 3.10.0-514.26.2.el7.x86_64 (builder@kbuilder.dev.centos.org) (gcc version 4.8.5 20150623 (Red Hat 4.8.5-11) (GCC) ) #1 SMP Tue Jul 4 15:04:05 UTC 2017
**          - CentOS Linux release 7.3.1611 (Core) 
**          - gcc version 4.8.5 20150623 (Red Hat 4.8.5-11) (GCC) 
**      ・Windows
**          - Windows 10 pro 64bit
**          - Microsoft Visual Studio Express 2012 for Windows Desktop
**  機能説明:
**	・A*アルゴリズムを用いて3*3のパズルを完成させるプログラム
**      ・木構造は各ノードを双方向チェインを用いで表現している
**	・空白部は0で示します
**      ・実行時に「Segmentation fault (core dumped)」が出力されますが結果は全て正しく出力されます。発生理由はよくわかりません。
*/

//ヘッダ読み込み部
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Visual Studioのみ必要　VisualStudioで動かす場合には #pragma~ の部分のコメントを消すこと
//#pragma warning(disable:4996) 

//構造体定義部

typedef struct def_tree{
	unsigned int f;				//このパズルの状態が持つ発見的関数の値
	unsigned int g;				//このリストが何手目に存在するか(木構造上の深さ)を示す変数
	unsigned int x;				//このノードの空白のx座標を格納
	unsigned int y;				//このノードの空白のy座標を格納
	unsigned int v[3][3];		//このノードのパズルの状態を格納する変数
	unsigned int before_type;	//このリストの親ノードからどの方向に進んだ場合にこのノードに到着するのかを示す変数(0:左 1:右 2:上 3:下 4:無し(自身がルート))
	struct def_tree* before;	//親のノードを示すポインタ(NULL : ルート)
	struct def_tree* p[4];		//現在の状態から動かした場合のリストを示すポインタ配列(0:左 1:右 2:上 3:下 存在しない場合:NULL)
} Tree;

//Open List
typedef struct def_List{
	Tree* tree;				//Tree構造体のアドレスを格納する変数
	struct def_List* next;	//次の検索対象へのポインタ
} List;

//関数プロトタイプ宣言部
//関数は一括して成功時には0,失敗時にはマイナスを返す

int LoadData(unsigned int c[3][3],unsigned int g[3][3],unsigned int* x,unsigned int* y,unsigned int gc[9][2]);
int PrintLog( unsigned int c[3][3], unsigned int f);
int CaluculateF(Tree* t, unsigned int gc[9][2]);
int PrintGoalRoot(Tree* t);
int CreateTree(Tree* now);
int OpenList(Tree** t,unsigned char do_type);
int CloseList(Tree* t,unsigned char do_type);
int MoveTo(unsigned int v[3][3],unsigned int* x,unsigned int* y, unsigned int move);
int Close(Tree* head);

int main(){
	Tree* head;								//ツリーのルートを示すポインタ
	Tree* p;								//ツリーのどこを参照しているのかを示すポインタ
	unsigned int start[3][3];				//パズルの初期状態を格納する構造体
	unsigned int goal[3][3];				//パズルの完成形を格納する構造体
	unsigned int coordinates_of_goal[9][2];	//パズルのゴールの各パネルの座標
	unsigned int start_x;			        //空白の初期x座標を示す変数
	unsigned int start_y;			        //空白の初期y座標を示す変数

	FILE* fp;						    	//ファイル作成用ポインタ
	unsigned int i,k;						//ループ用カウンタ
	int ret=0;								//関数の戻り値を格納する変数

	//パズルのデータを読み込む
	if(0>LoadData(start,goal,&start_x,&start_y,coordinates_of_goal)){
		perror("LoadData");
		return -1;
	}

	//出力ファイルを生成
	if(NULL==(fp=fopen("output.txt","w+"))){
		perror("fopen");
		return -1;
	}
	fclose(fp);

	if(NULL==(fp=fopen("f.txt","w+"))){
		perror("fopen");
		return -1;
	}
	fclose(fp);

	//ルートのメモリ確保
	if(NULL==(head=(Tree*)malloc(sizeof(Tree)))){
		perror("malloc");
		return -2;
	}

	//ルートの初期化
	head->before_type=4;
	head->g=0;
	head->x=start_x;
	head->y=start_y;
	head->before=NULL;
	for(i=0;i<4;i++) head->p[0]=NULL;
	for(i=0;i<3;i++) for(k=0;k<3;k++) head->v[i][k]=start[i][k];


	//発見的関数の値を計算
	if(0>CaluculateF(head,coordinates_of_goal)){
		perror("CaluculateF");
		return -2;
	}

	//ログを出力
	PrintLog(head->v,head->f);

	p=head;

	while(1){
		//選択されたノードが目標状態化を確認する( f(p)=g(p)+h(p) より、 h(p)=f(p)-g(p) h(p)=0は目標状態)
		if(0==((p->f)-(p->g))){
			printf("found!\n");
			break;
		}

		//Open Listから取り出したノードに隣接しているノードを作成
		if(0>CreateTree(p)){
			perror("CreateTree");
			return -3;
		}
		//作成したノードの発見的関数を計算
		for(i=0;i<4;i++){
			if(p->p[i]!=NULL){
				if(0>CaluculateF(p->p[i],coordinates_of_goal)){
					perror("CalucurateF");
					return -2;
				}
			}
		}
		//新規作成したノードをOpen Listに追加
		if(0>OpenList(&p,0)){
			perror("Priority - 0");
			return -4;
		}
		//Open List内で最も発見的関数の値が低いものを次の対象とする
		if(0>(ret=OpenList(&p,1))){
			perror("Priority - 1");
			return -5;
		}
		else if(ret==1){
			printf("not found...\n");
			break;
		}
		PrintLog(p->v,p->f);
	}
		
	//初期状態からゴール状態までの移動経路を解析
	if(0>PrintGoalRoot(p)){
		perror("PrintGoalRoot");
		return -6;
	}

	OpenList(NULL,2);
	CloseList(NULL,2);
	Close(head);

	return 0;
}

//ファイルからパズルの初期状態・目標状態を読み込む関数
//引数	:	パズルの初期値が格納される配列,パズルのゴールが格納される配列,空白のx座標が格納される変数,空白のy座標が格納される変数,ゴール状態の各パネルの座標が格納される配列
int LoadData(unsigned int c[3][3],unsigned int g[3][3],unsigned int* x,unsigned int* y,unsigned int gc[9][2]){
	FILE* fp;
	int i,k;

	//ファイル記述子の確保とエラー処理
	if(NULL==(fp=fopen("input.txt","r"))){
		perror("fopen");
		return -1;
	}

	//ファイルからデータを読み込む
	//初期条件
	fscanf(fp,"%u %u %u",&c[0][0],&c[0][1],&c[0][2]);
	fscanf(fp,"%u %u %u",&c[1][0],&c[1][1],&c[1][2]);
	fscanf(fp,"%u %u %u",&c[2][0],&c[2][1],&c[2][2]);
	fgetc(fp);

	//目標状態
	fscanf(fp,"%u %u %u",&g[0][0],&g[0][1],&g[0][2]);
	fscanf(fp,"%u %u %u",&g[1][0],&g[1][1],&g[1][2]);
	fscanf(fp,"%u %u %u",&g[2][0],&g[2][1],&g[2][2]);

	fclose(fp);

	for(i=0;i<3;i++){
		for(k=0;k<3;k++){
			//空白の位置を線形探索し、各変数に格納する。
			if(c[i][k]==0){
				*x=i;
				*y=k;
			}

			//ゴール状態のパネルの座標を格納
			gc[g[i][k]][0]=i;
			gc[g[i][k]][1]=k;

		}
	}

	return 0;
}

//ファイルに発見的関数とパズルの状態を書き込む関数
//引数	:	パズルの現在の状態が格納された関数,発見的関数の値
int PrintLog(unsigned int c[3][3], unsigned int f){
	FILE* fp;

	//ファイル記述子の確保とエラー処理
	if(NULL==(fp=fopen("output.txt","a+"))){
		perror("fopen");
		return -1;
	}

	fprintf(fp,"%u %u %u\n",c[0][0],c[0][1],c[0][2]);
	fprintf(fp,"%u %u %u\n",c[1][0],c[1][1],c[1][2]);
	fprintf(fp,"%u %u %u\n",c[2][0],c[2][1],c[2][2]);
	fprintf(fp,"f = %u\n",f);
	fprintf(fp,"\n");

	fclose(fp);

	//ファイル記述子の確保とエラー処理
	if(NULL==(fp=fopen("f.txt","a+"))){
		perror("fopen");
		return -1;
	}

	fprintf(fp,"%u,",f);

	fclose(fp);

	return 0;
}

//ノードから派生するノードを計算、作成し、発見的関数の値を計算する関数
//引数	:	計算したいノード,パズルの目標状態の各パネルの座標
int CaluculateF(Tree* t, unsigned int gc[9][2]){
	unsigned int h=0;		//マンハッタン距離を格納する変数
	int i,k;				//ループカウンタ
	
	for(i=0;i<3;i++) for(k=0;k<3;k++){
		if(t->v[i][k]==0) continue;
		h+=(unsigned int)(abs((int)(i-gc[t->v[i][k]][0]))+abs((int)(k-gc[t->v[i][k]][1])));
	}

	//このルートを選択した場合の発見的関数の値を計算
	t->f=t->g+h;
        
	return 0;
}

//ユーザに入力されたパズル状態から引数に入力されたノードの状態までの移動方向を計算する関数
//引数	:	計算したいノード,ユーザから入力されたパズルの配置
int PrintGoalRoot(Tree* t){
	FILE *fp;			//出力ファイル作成用変数
	Tree *p;			//計算用のポインタ
	unsigned int i;    	//ループ用カウンタ
	unsigned int *root;	//目標状態までのルートを格納する変数
	
	p=t;
	
      	//ルート用のメモリを確保
       	if(NULL==(root=(unsigned int*)malloc( (sizeof(unsigned int)*( ((size_t)t->g) +10 )) ))){
		perror("malloc");
		return -1;
	}
	
	//ルート情報をroot配列に格納する
	for(i=t->g;i>0;i--){
		if(p->before_type!=4) root[i-1]=p->before_type;
		if(p->before!=NULL) p=p->before;
	}
		
       	//出力用ファイルを作成
	if(NULL==(fp=fopen("start_goal.txt","w+"))){
		perror("fopen");
		return -1;
	}	
	
	for(i=0;i<t->g;i++){
		//ファイルに出力
		fprintf(fp,"%u %u %u\n",p->v[0][0],p->v[0][1],p->v[0][2]);
		fprintf(fp,"%u %u %u\n",p->v[1][0],p->v[1][1],p->v[1][2]);
		fprintf(fp,"%u %u %u\n",p->v[2][0],p->v[2][1],p->v[2][2]);
		fprintf(fp,"f = %u\n\n",p->f);
		
		//次に移動
		if(p->p[root[i]]!=NULL) p=p->p[root[i]];
	}
	
	fprintf(fp,"%u %u %u\n",p->v[0][0],p->v[0][1],p->v[0][2]);
	fprintf(fp,"%u %u %u\n",p->v[1][0],p->v[1][1],p->v[1][2]);
	fprintf(fp,"%u %u %u\n",p->v[2][0],p->v[2][1],p->v[2][2]);
        fprintf(fp,"f = %u\n\n",p->f);
	
	fclose(fp);
	free(root);
	
	return 0;
}

//リストから左右上下に動かした場合のリストを作成
//引数	:	チェイン元のリスト
int CreateTree(Tree* now){
	unsigned int p,i,k;		//ループカウンタ
	Tree* chain;			//確保した変数を格納するポインタ
	unsigned int ret;		//関数の戻り値を受け取る変数

	for(p=0;p<4;p++){
		//新しいノードを作成
		if(NULL==(chain=(Tree*)malloc(sizeof(Tree)))){
			perror("malloc");
			return -1;
		}
		
		//空白の移動先の推定
		switch(p){
		case 0:
			//左に移動できるか確認
			if(now->x==0){
				now->p[p]=NULL;
				free(chain);
				continue;
			}
			break;
		case 1:
			//右に移動できるか確認
			if((now->x+1)>2){
				now->p[p]=NULL;
				free(chain);
				continue;
			}
			break;
		case 2:
			//上に移動できるか確認
			if(now->y==0){
				now->p[p]=NULL;
				free(chain);
				continue;
			}
			break;
		case 3:
			//下に移動できるか確認
			if((now->y+1)>2){
				now->p[p]=NULL;
				free(chain);
				continue;
			}
			break;
		default:
			perror("counter for loop was broken.");
			return -2;

			break;
		}

		//変数の初期化
		chain->before_type=p;
		chain->g=now->g+1;
		chain->before=now;
		chain->x=now->x;
		chain->y=now->y;
		for(i=0;i<4;i++) chain->p[i]=NULL;

		//ノードのパズルを変形
		for(i=0;i<3;i++) for(k=0;k<3;k++) chain->v[i][k]=now->v[i][k];
		//Memo : MoveTo関数の中でx,y座標は移動される
		if(0>MoveTo(chain->v,&(chain->x),&(chain->y),p)){
			perror("MoveTo");
			return -3;
		}

		//CloseListに存在する場合にはNULLにする
		if(1==(ret=CloseList(chain,1))){
			free(chain);
			chain=NULL;
		}
		else if(ret<0){
			perror("CloseList");
			return -4;
		}


		//リスト同士をつなげる
		now->p[p]=chain;
	}
	
	return 0;
}

//Open Listを操作するための関数
//この関数は例外的に1を返す。1を返す場合はdo_type=1であり、Open Listがからであった時である
//引数	:	パズルの状態を示すノードの構造体ポインタ,この関数の動作を決める変数(0:新しいノードを追加 1:リスト内から発見的関数の値が最も低いものをtに格納する 2:メモリを解放する)
int OpenList(Tree** t,unsigned char do_type){
	static List* head=NULL;				//構造体リストの先頭を示すポインタ
	List *p,*keep;	       				//各種操作に利用するポインタ
	unsigned int i;	       				//ループ用カウンタ
	int found_flag;					//すでに挿入ずみかを判断するフラグ

	//Open Listに何も入っていない場合、作成
	if(head==NULL){
		//メモリ確保
		if(NULL==(head=(List*)malloc(sizeof(List)))){
			perror("malloc");
			return -1;
		}
		//作成した変数の初期化
		head->next=NULL;
		head->tree=NULL;
	}

	switch(do_type){
	case 0:
		for(i=0;i<4;i++){
			//エラー処理
			if((*t)->p[i]==NULL) continue;
			
			if(head->tree==NULL){
				head->tree=(*t)->p[i];
				continue;
			}
			
			//変数の初期化
			p=head;
			keep=NULL;
			found_flag=1;
	
			//線形探索でどの順位に挿入するかを決める
			while(1){
				//入る位置があるかを比較
				if((p->tree->f) >= ((*t)->p[i]->f)){
					//発見的関数の値が同じ場合、gの値が相手よりも大きいのであれば次のループに移動する
					if((p->tree->f) == ((*t)->p[i]->f) && (p->tree->g) < ((*t)->p[i]->g)){
						//このリストが末端かを確認
						if(p->next==NULL){
							//入る位置が存在しなかった場合は最後尾に追加する
					
							//メモリを確保
							if(NULL==(p->next=(List*)malloc(sizeof(List)))){
								perror("malloc");
								return -1;
							}
							//初期化
							p->next->next=NULL;
							//挿入
							p->next->tree=(*t)->p[i];

							break;
						}
						
						//次のリストに進む
						keep=p;
						p=p->next;
						continue;
					}
											
					//Open List内で発見的関数の値が最も低い場合の処理
					if(keep==NULL){
						//メモリを確保
						if(NULL==(keep=(List*)malloc(sizeof(List)))){
							perror("malloc");
							return -1;
						}
						//挿入
						keep->next=p;
						//ノードと紐づけ
						keep->tree=(*t)->p[i];
						//headの移動
						head=keep;
						//フラグを下げる
						found_flag=0;
						break;
					}
					
					//メモリを確保
					if(NULL==(keep->next=(List*)malloc(sizeof(List)))){
						perror("malloc");
						return -1;
					}
					//挿入
					keep->next->next=p;
					//ノードと紐づけ
					keep->next->tree=(*t)->p[i];
					//フラグを解除する
					found_flag=0;

					break;
				}

				//このリストが末端かを確認
				if(p->next==NULL){
					//入る位置が存在しなかった場合は最後尾に追加する
					
					//メモリを確保
					if(NULL==(p->next=(List*)malloc(sizeof(List)))){
						perror("malloc");
						return -1;
					}
					//初期化
					p->next->next=NULL;
					//挿入
					p->next->tree=(*t)->p[i];

					break;
				}
				
				//次のリストに進む
				keep=p;
				p=p->next;
			}

		}
		break;

	case 1:
		//エラー処理
		if(head->tree==NULL) return 1;

		//引数のポインタに最も発見的関数の値が小さいノードを渡す
		*t=head->tree;

		//Open Listから消すものをClose Listに追加
		CloseList(head->tree,0);

		//エラー処理
		if(head->next==NULL){
			head->tree=NULL;
			return 0;
		}

		//一つリストを詰める
		head->tree=head->next->tree;
		keep=head;
		head=head->next;

		//使用しなくなったリストをメモリ開放
		free(keep);

		break;

	case 2:
	        if(head==NULL) break;
		
		//メモリを解放する機能
		keep=head->next;
		p=head;
		
		while(1){
			//メモリを解放
			free(p);

			//次がないのなら終了
			if(keep==NULL) break;

                	p=keep;

			keep=keep->next;
		}

		break;

	default:
		perror("do_type number broken!");
		return -1;
	}

	return 0;
}

//Close Listを操作するための関数
//この関数は例外的に1を返す。1を返す場合はdo_type=1であり、Open Listがからであった時である
//引数	:	パズルの状態を示すノードの構造体ポインタ,この関数の動作を決める変数(0:新しいノードを追加 1:(*t)->vに一致するものがあるかを検索する 2:メモリを解放する)
int CloseList(Tree* t,unsigned char do_type){
	static List* head=NULL;				//構造体リストの先頭を示すポインタ
	List *p,*keep;						//各種操作に利用するポインタ
	unsigned int i,k;					//ループ用カウンタ
	unsigned int end_counter=0;			//パズルの状態の一致具合を計測するためのカウンタ

	//Open Listに何も入っていない場合、作成
	if(head==NULL){
		//メモリ確保
		if(NULL==(head=(List*)malloc(sizeof(List)))){
			perror("malloc");
			return -1;
		}
		//作成した変数の初期化
		head->next=NULL;
		head->tree=NULL;
	}

	switch(do_type){
	case 0:
		//エラー処理
		if(t==NULL){
			perror("t is NULL");
			return -3;
		}
		
		if(head->tree==NULL){
			head->tree=t;
			break;
		}

		//変数の初期化
		p=head;
	
		//現在のリストの最後尾に到達する
		while(1){
			if(p->next==NULL) break;
			p=p->next;
		}

		//メモリを確保
		if(NULL==(p->next=(List*)malloc(sizeof(List)))){
			perror("malloc");
			return -1;
		}

		//新しくリストに値を追加
		p->next->tree=t;

		//新しく確保した値の初期化
		p->next->next=NULL;

		break;

	case 1:
		if(head->tree==NULL) return 0;

		//初期化
		p=head;

		//線形探索で一致するものがあるかを確認
		while(1){
		        end_counter=0;
			if(p==NULL) break;
			
			//パズル状態の比較
			for(i=0;i<3;i++) for(k=0;k<3;k++) if(t->v[i][k]==p->tree->v[i][k]) end_counter++;

			if(end_counter==9) return 1;

			p=p->next;
		}
		

		break;

	case 2:
	        if(head==NULL) break;
		
		//メモリを解放する機能
		keep=head->next;
		p=head;

		while(1){
			//メモリを解放
			free(p);

			//次がないのなら終了
			if(keep==NULL) break;

			p=keep;

			keep=keep->next;
		}

		break;

	default:
		perror("do_type number broken!");
		return -1;
	}

	return 0;
}

//パズルの空白を指定した方向に動かす関数
//引数	:	動かすパズル,空白のx座標,空白のy座標,移動させる方向(0:左 1:右 2:上 3:下)
int MoveTo(unsigned int v[3][3],unsigned int* x,unsigned int* y, unsigned int move){
	unsigned int keep;	//計算の途中結果を格納する変数

	switch(move){
	case 0:
		//左に移動
		keep=v[*x][*y];

		if((*x)==0){
			perror("Can't move");
			return -2;
		}

		v[*x][*y]=v[(*x)-1][*y];
		v[(*x)-1][*y]=keep;
		(*x)-=1;
		
		break;

	case 1:
		//右に移動
		keep=v[*x][*y];

		if((*x)+1>2){
			perror("Can't move");
			return -2;
		}

		v[*x][*y]=v[(*x)+1][*y];
		v[(*x)+1][*y]=keep;
		(*x)+=1;
		
		break;

	case 2:
		//上に移動
		keep=v[*x][*y];

		if((*y)==0){
			perror("Can't move");
			return -2;
		}

		v[*x][*y]=v[*x][(*y)-1];
		v[*x][(*y)-1]=keep;
		(*y)-=1;

		break;

	case 3:
		//左に移動
		keep=v[*x][*y];

		if((*y)+1>2){
			perror("Can't move");
			return -2;
		}

		v[*x][*y]=v[*x][(*y)+1];
		v[*x][(*y)+1]=keep;
		(*y)+=1;

		break;

	default:
		perror("Wrong : move number");
		return -1;
	}

	return 0;
}

//リストの解放を行う関数
//引数	:	リストのルート
int Close(Tree* head){
	unsigned int i;	//ループ用カウンタ

	for(i=0;i<4;i++) if(head->p[i]!=NULL) Close(head->p[i]);

	free(head);

	return 0;

}
