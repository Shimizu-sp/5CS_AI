#include<stdio.h>
#include<string.h>

int main(void){
	char a[12] = "a*b-cd/e+fg";   //初期WM
	char b[12] = "gfedcba+-*/";   //終了予定WM
	int i,k=0;
	char change1;

	while(strcmp(a,b)){
		k = k++;
		//右から左まで一周
		for (i = 0; i <= 9; i++){
			//PM R1:アルファベットを左に、記号を右に
			if (a[i] <= a[i+1]){           
				change1 = a[i];
				a[i] = a[i + 1];
				a[i + 1] = change1;
			}
			//PM R2:アルファベット同士での順番変更
			if (a[i]>=60 && a[i+1] >= 60 && a[i] <= a[i+1] ){      
				change1 = a[i];
				a[i] = a[i + 1];
				a[i + 1] = change1;
			}
			//PM R3:記号同士での順番変更
			if (a[i] <= 60 && a[i + 1] <= 60){
				switch (a[i + 1]){
				//記号同士で比較したとき「+」が右にある場合
				case 43:
					change1 = a[i];
					a[i] = a[i + 1];
					a[i + 1] = change1;
					break;
				//記号同士で比較したとき「-」が右にあり、真横が「+」ではない場合
				case 45:
					if (a[i] != 43){
						change1 = a[i];
						a[i] = a[i + 1];
						a[i + 1] = change1;
					}
					break;
				//記号同士で比較したとき「*」が右にあり、真横が「+」か「-」ではない場合
				case 42:
					if (a[i] != 43 && a[i] != 45){
						change1 = a[i];
						a[i] = a[i + 1];
						a[i + 1] = change1;
					}
					break;
				default:
					break;
				}
			}
			//WMの表示 
			printf("WM %s \n",a);         
		}
		//一周完了
		printf("%d周目 交換終了\n",k);
	}
	//WM変更完了
	printf("変更完了\n");
}

