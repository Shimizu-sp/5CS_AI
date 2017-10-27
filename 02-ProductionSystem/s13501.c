#include <stdio.h>
#define S 11

int main(){
	char String[S][1] = {'a','*','b','-','c','d','/','e','+','f','g'};		//文字列
	char Evacuate[1];

	int Finish_Flag = 1;		//処理が完了したかどうかを管理するフラグ
	int Counter = 0;				//ループカウンタ

	printf("---初期状態---\n");
	
	for (int i = 0; i < S; i++)
		printf("%c", String[i][0]);

	printf("\n\n");
	while (Finish_Flag == 1){	//処理が完了するまでループするの
		Finish_Flag = 0;		//フラグを初期化(処理を一度もしていないという状態にする)
		Counter++;
		printf("---処理%d回目---\n",Counter);

		for (int i = 0; i < S; i++){
				//R1の処理
			if ((String[i][0] >= 33 && String[i][0] <= 64)	//左が記号(ASCIIコードが33以上かつ64以下)
					&& String[i+1][0] >= 97){					//↑かつ、右側が小文字(97以上)の場合

				Finish_Flag = 1;	//作業を行ったフラグを立てる
				Evacuate[0] = String[i][0];			//記号をEvacuateにコピー
				String[i][0] = String[i + 1][0];	//記号の位置に右側の小文字を入れる
				String[i + 1][0] = Evacuate[0];		//小文字の位置にEvacuateに退避させていた記号を入れる
			}

				//R2の処理
			if ((String[i][0] >= 97 && String[i][0] <= 122)			//小文字(ASCIIコードが97以上122以下)
					&& (String[i+1][0] >= 97 && String[i+1][0] <= 122)	//↑かつ右が小文字
						&& String[i][0] < String[i+1][0]) {					//↑かつ左より右の方がASCIIコードの値が大きい場合

				Finish_Flag = 1;	//作業を行ったフラグを立てる
				Evacuate[0] = String[i][0];			//左の小文字をEvacuateにコピー
				String[i][0] = String[i + 1][0];	//左に右側の小文字を入れる
				String[i + 1][0] = Evacuate[0];		//右にEvacuateに退避させていた小文字を入れる
			}

				//R3の処理
			if (String[i][0] == 47						//左が「/」(ASCIIコードが47)
					&& (String[i + 1][0] >= 33 && String[i+1][0] <=126)) {	//↑かつ、右に何かしらの文字がある

				Finish_Flag = 1;	//作業を行ったフラグを立てる
				Evacuate[0] = String[i][0];			//左の「/」をEvacuateにコピー
				String[i][0] = String[i + 1][0];	//左に右側の文字を入れる
				String[i + 1][0] = Evacuate[0];		//右にEvacuateに退避させていた「/」を入れる
			}

				//R4の処理
			if ((String[i][0] >= 33 && String[i][0] <= 64)		//左が記号(ASCIIコードが33以上かつ64以下)
				&& String[i+1][0] == 43) {								//↑かつ、右側が「+」(ASCIIコードが43)
			
				Finish_Flag = 1;	//作業を行ったフラグを立てる
				Evacuate[0] = String[i][0];			//左の記号をEvacuateにコピー
				String[i][0] = String[i + 1][0];	//左に右側の「+」を入れる
				String[i + 1][0] = Evacuate[0];		//右にEvacuateに退避させていた記号を入れる
			}

				//R5の処理
			if (String[i][0] == 42				//左が「*」(ASCIIコードが42)
				&& String[i + 1][0] == 45) {		//↑かつ、右が「-」(ASCIIコードが45)
			

				Finish_Flag = 1;	//作業を行ったフラグを立てる
				Evacuate[0] = String[i][0];			//左の「*」をEvacuateにコピー
				String[i][0] = String[i + 1][0];	//左に右側の「-」を入れる
				String[i + 1][0] = Evacuate[0];		//右にEvacuateに退避させていた「*」を入れる
			}



		}
		if (Finish_Flag == 0)
			printf("***処理が完了しました***\n");
		else
			for (int i = 0; i < S; i++)		//現時点の文字列をprintf
				printf("%c", String[i][0]);
		printf("\n\n");

	}
	getchar();
}