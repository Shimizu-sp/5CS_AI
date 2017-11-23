/*
** プロダクションシステムのためのプログラム
** 作成者：桑原大輔
*/

#include<stdio.h>
#include<string.h>

//関数プロトタイプ宣言部

//strの中から1文字を先頭から線形検索し、その文字が最初に発見された時のインデックスを返す関数
int StrSearch(char* str,char target);

//targetの一つ右にmeが配置されていない場合meの一つ右に向けて一つ移動する
int MoveLeftofTarget(char* str,char me,char target);

int main(){
	char production[12]="gfedcba+-*/";	//ワーキングメモリの開始状態
	char goal[12]="gfedcba+-*/";		//ワーキングメモリの終了状態
	int k;								//関数の戻り値を格納する変数

	printf("初期状態:%s\n",production);

	//ワーキングメモリを割り当てる
	while(1){
		//R1;gが一番先頭にないときには一つ左に移動する
		if('g'!=production[0]){
			if(0>(k=StrSearch(production,'g'))){
				perror("production memory has broken.");
				return -1;
			}

			//gを一つ左に移動
			production[k]=production[k-1];
			production[k-1]='g';
		}

		//R2:fがgの右に存在しない場合には一つgの右方向に向かってに移動する
		else if(1!=(k=MoveLeftofTarget(production,'f','g'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R3:eがfの右に存在しない場合には一つfの右方向に移動する
		else if(1!=(k=MoveLeftofTarget(production,'e','f'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R4:dがeの右に存在しない場合には一つeの右方向に移動する
		else if(1!=(k=MoveLeftofTarget(production,'d','e'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R5:cがdの右に存在しない場合には一つdの右方向に移動する
		else if(1!=(k=MoveLeftofTarget(production,'c','d'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R6:bがcの右に存在しない場合には一つcの右方向に移動する
		else if(1!=(k=MoveLeftofTarget(production,'b','c'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R7:aがbの右に存在しない場合には一つbの右方向に移動する
		else if(1!=(k=MoveLeftofTarget(production,'a','b'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R8:+がaの右に存在しない場合には一つaの右方向に移動する
		else if(1!=(k=MoveLeftofTarget(production,'+','a'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R9:-が+の右に存在しない場合には一つ+の右方向に移動する
		else if(1!=(k=MoveLeftofTarget(production,'-','+'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R10:*が-の右に存在しない場合には一つ-の右方向に移動する
		else if(1!=(k=MoveLeftofTarget(production,'*','-'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R11:/が*の右に存在しない場合には一つ*の右方向に移動する
		else if(1!=(k=MoveLeftofTarget(production,'/','*'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}


		printf("演算途中の文字列:%s\n",production);

		//終了確認
		if(0==strcmp(production,goal)) break;

	}

	printf("結果:%s\nEnterを押して終了...\n",production);
	getchar();

}


//関数の中から1文字を先頭から線形検索し、その文字が最初に発見された時のインデックスを返す関数
//戻り値が-1の場合には発見できなかったことを示す
//引数 : str;検索する文字列 target;検索目的の文字列
int StrSearch(char* str,char target){
	size_t i;	//ループカウンタ

	for(i=0;i<strlen(str);i++){
		if(str[i]=='\0') return -1;

		if(str[i]==target) return (int)i;
	}

	return -1;
}

//targetの一つ右にmeが配置されていない場合meの一つ右に向けて一つ移動する
//戻り値がマイナスの場合にはエラー、1の場合にはすでに既定の位置に存在することを示す
//引数 : str;移動する文字が格納された文字列 me;移動元 target;移動方向を決める文字
int MoveLeftofTarget(char* str,char me,char target){
	int k,n;

	if(0>(k=StrSearch(str,target))){
		perror("production memory has broken.");
		return -1;
	}
	if(0>(n=StrSearch(str,me))){
		perror("production memory has broken.");
		return -1;
	}

	if(k+1!=n){
		if(k>n){
			//fがgの左側に存在する場合
			str[n]=str[n+1];
			str[n+1]=me;
		}
		else{
			//fがgの右側に存在するとき
			str[n]=str[n-1];
			str[n-1]=me;
		}
	}
	else return 1;

	return 0;
}
