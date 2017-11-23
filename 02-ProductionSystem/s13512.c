#include <stdio.h>
#include <string.h>

int production_mem(int x, int y);

char str_start[11] = { "/*g-dc+bfea" };
int strcode = 0;

char working_mem[2][11];//ワーキングメモリ

int printmemory(char str[2][11]);

int iter = 0;

int symboliter = 0;


int main(){
	int i = 0, alphabet = 0, symbol = 0;
	//インタープリタ
	//推論メモリ
	while (str_start[i] != '\0'){
		strcode = (int)str_start[i];
		//プロダクションメモリ
		if (strcode > 50){
			working_mem[0][alphabet] = str_start[i];
			alphabet++;
		}
		else if (strcode < 50){
			working_mem[1][symbol] = str_start[i];
			symbol++;

		}
		i++;
	}

	printmemory(working_mem);
	irekae(working_mem);

}
//ワーキングメモリの中身を表示する関数
int printmemory(char str[][11]){
	int i = 0;
	printf("配列の中身[");
	while (str[0][i] != '\0'){
		printf("%c ", str[0][i]);
		i++;
	}

	i = 0;

	while (str[1][i] != '\0'){
		printf("%c ", str[1][i]);
		i++;
	}
	printf("]\n");
	getchar();
}

//入れ替えをする関数
int irekae(char x[][11]){
	int i = 0;
	int j, num;
	char temp;
	while (x[iter][i] != '\0'){
		i++;
	}
	num = i;
	i = 0;
	if (iter==0){
		while (x[iter][i] != '\0'){
			for (j = num-1; j > i; j--){
				if ((int)x[iter][j - 1] < (int)x[iter][j]){
					temp = x[iter][j];
					x[iter][j] = x[iter][j - 1];
					x[iter][j - 1] = temp;
					printmemory(x);
				}
			}
			i++;
		}
		iter++;
		irekae(x);
	}
	else if(iter==1){
		while (x[iter][i] != '\0'){
			for (j = num - 1; j > i; j--){
				//プロダクションメモリ
				if ((int)x[iter][j - 1] > (int)x[iter][j]){
					temp = x[iter][j];
					x[iter][j] = x[iter][j - 1];
					x[iter][j - 1] = temp;
					printmemory(x);
				}
			}
			i++;
		}
		i = 0;
		while (x[iter][i + 1] != '/'){
			temp = x[iter][i];
			x[iter][i] = x[iter][i + 1];
			x[iter][i + 1] = temp;
			printmemory(x);
			i++;

		}


	}


}
