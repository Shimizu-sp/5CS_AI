#include <stdio.h>
#include <math.h>
#include <string.h>

#define STACK_SIZE  100   /* スタックに積むことのできるデータの最大個数 */


int puzzle_cost[STACK_SIZE];  /* スタック本体 */
int puzzle[STACK_SIZE][3][3];

int stack_amount=0;                  /* スタック内のデータ数 */

int node_array;

int p[3][3] = { { 8, 1, 5 },
				{ 2, 0, 4 },
				{ 6, 3, 7 } };

int p_n[3][3] = { { 1, 2, 3 },
				  { 4, 5, 6 },
				  { 7, 8, 0 } };




int popo;

int main(){
	int i, j;

	puzzle_cost[0] = 1000;
	for(i = 0; i < 3; i++){
		for (j = 0; j < 3;j++){
			puzzle[0][i][j] = p[i][j];
		}
	}

	distance(p,p_n);//マンハッタン距離をだす
	xnotoki(puzzle);

}

int distance(int puzzle_s[][3], int puzzle_e[][3]){
	int x1,y1,x2,y2,kyori,dist=0;
	for (x1 = 0; x1 < 3;x1++){
		for (y1 = 0; y1 < 3; y1++){
			for (x2 = 0; x2 < 3;x2++){
				for (y2 = 0; y2 < 3;y2++){
					if (puzzle_s[x1][y1]==puzzle_e[x2][y2]){
						kyori = abs(x1 - x2) + abs(y1 - y2); //pとp_nのx,yの差を求める
						dist = dist + kyori;
					}
				}
			}
		}
	}
	printf("コスト=%d\n", dist);
	return dist;
}

int xnotoki(int x_mtrx[][3][3]){//パズルを動かす(xのとき)
	int x1, y1, x2, y2;
	int costx[2],costy[2];
	for (x1 = 0; x1 < 3; x1++){
		for (y1 = 0; y1 < 3; y1++){
			if (x_mtrx[stack_amount - 1][x1][y1] == 0){
				x2 = x1;//空白の座標x
				y2 = y1;//空白の座標y
				
			}
		}
	}

	switch (x2){
	case 0:

			x_mtrx[stack_amount - 1][x2][y2] = x_mtrx[stack_amount - 1][x2 + 1][y2];//下に動かす
			x_mtrx[stack_amount - 1][x2 + 1][y2] = 0;
			costx[0] = distance(x_mtrx, p_n);
			printpuzzle(x_mtrx);
			ynotoki(x_mtrx, x2, y2);
			//判別

			if (puzzle_cost[stack_amount - 1]<costx[0]){
				x_mtrx[stack_amount - 1][x2 + 1][y2] = x_mtrx[stack_amount - 1][x2][y2];//元に戻す
				x_mtrx[stack_amount - 1][x2][y2] = 0;

				ynotoki(x_mtrx,x2,y2);
			}
			else if (puzzle_cost[stack_amount - 1]>costx[0]){
				pop();
				push(costx[0],x_mtrx[stack_amount - 1][x2][y2]);
				ynotoki(x_mtrx,x2,y2);
			}
			else if (puzzle_cost[stack_amount - 1 ] == costx[0] ){
				pop();
				push(costx[0], x_mtrx[stack_amount - 1][x2][y2]);
				ynotoki(x_mtrx, x2, y2);
				//ヒューリスティック値が同じだったときの処理を入れる
			}
			else if (puzzle_cost[stack_amount - 1] == 0){//コストが0だったら終わる
				break;
			}



			break;
	case 1://真ん中の場合
			x_mtrx[stack_amount - 1][x2][y2] = x_mtrx[stack_amount - 1][x2 + 1][y2];//下に動かす
			x_mtrx[stack_amount - 1][x2 + 1][y2] = 0;
			costx[0] = distance(x_mtrx, p_n);//コストを求める
			printpuzzle(x_mtrx);

			x_mtrx[stack_amount - 1][x2 + 1][y2] = x_mtrx[stack_amount - 1][x2][y2];//元に戻す
			x_mtrx[stack_amount - 1][x2][y2] = 0;

			x_mtrx[stack_amount - 1][x2][y2] = x_mtrx[stack_amount - 1][x2 - 1][y2];//上に動かす
			x_mtrx[stack_amount - 1][x2 - 1][y2] = 0;
			costx[1] = distance(x_mtrx, p_n);
			printpuzzle(x_mtrx);

			x_mtrx[stack_amount - 1][x2 - 1][y2] = x_mtrx[stack_amount - 1][x2][y2];//元に戻す
			x_mtrx[stack_amount - 1][x2][y2] = 0;
			printf("xのコスト=%d %d \n", costx[0], costx[1]);
			ynotoki(x_mtrx, x2, y2);
			break;
	case 2:
			x_mtrx[stack_amount - 1][x2][y2] = x_mtrx[stack_amount - 1][x2 - 1][y2];//上に動かす
			x_mtrx[stack_amount - 1][x2 - 1][y2] = 0;
			costx[0] = distance(x_mtrx, p_n);//コストを求める
			printpuzzle(x_mtrx);

			x_mtrx[stack_amount - 1][x2 - 1][y2] = x_mtrx[stack_amount - 1][x2][y2];//元に戻す
			x_mtrx[stack_amount - 1][x2][y2] = 0;
			ynotoki(x_mtrx, x2, y2);
			break;
	}
	//ynotoki
	return 0;
}

int ynotoki(int y_mtrx[][3],int ynotoki_x,int ynotoki_y){
	int costy[2];

	switch (ynotoki_y){
	case 0:

		y_mtrx[ynotoki_x][ynotoki_y] = y_mtrx[ynotoki_x][ynotoki_y + 1];//右に動かす
		y_mtrx[ynotoki_x][ynotoki_y + 1] = 0;
		costy[0] = distance(y_mtrx, p_n);
		printpuzzle(y_mtrx);

		if (puzzle_cost[stack_amount - 1] < costy[0]){
			y_mtrx[ynotoki_x][ynotoki_y + 1] = y_mtrx[ynotoki_x][ynotoki_y];//元に戻す
			y_mtrx[ynotoki_x][ynotoki_y] = 0;
			xnotoki(y_mtrx,ynotoki_x,ynotoki_y);
		}
		else if (puzzle_cost[stack_amount - 1]>costy[0]){//コストが小さかった時
			pop();//一回ポップ
			push(costy[0],y_mtrx);//プッシュする
			xnotoki(y_mtrx, ynotoki_x, ynotoki_y);
		}
		else if (puzzle_cost[stack_amount - 1] == costy[0]){
			y_mtrx[ynotoki_x][ynotoki_y + 1] = y_mtrx[ynotoki_x][ynotoki_y];//元に戻す
			y_mtrx[ynotoki_x][ynotoki_y] = 0;


			//ヒューリスティック値が同じだったときの処理を入れる


		}
		else if (puzzle_cost[stack_amount - 1] == 0){//コストが0だったら終わる
			break;
		}
		break;
	case 1:
		y_mtrx[ynotoki_x][ynotoki_y] = y_mtrx[ynotoki_x][ynotoki_y + 1];//右に動かす
		y_mtrx[ynotoki_x][ynotoki_y + 1] = 0;
		costy[0] = distance(y_mtrx, p_n);
		printpuzzle(y_mtrx);

		y_mtrx[ynotoki_x][ynotoki_y + 1] = y_mtrx[ynotoki_x][ynotoki_y];//元に戻す
		y_mtrx[ynotoki_x][ynotoki_y] = 0;

		y_mtrx[ynotoki_x][ynotoki_y] = y_mtrx[ynotoki_x][ynotoki_y - 1];//左に動かす
		y_mtrx[ynotoki_x][ynotoki_y - 1] = 0;
		costy[1] = distance(y_mtrx, p_n);
		printpuzzle(y_mtrx);

		y_mtrx[ynotoki_x][ynotoki_y - 1] = y_mtrx[ynotoki_x][ynotoki_y];//元に戻す
		y_mtrx[ynotoki_x][ynotoki_y] = 0;

		printf("yのコスト=%d %d \n", costy[0], costy[1]);
		break;
	case 2:
		y_mtrx[ynotoki_x][ynotoki_y] = y_mtrx[ynotoki_x][ynotoki_y - 1];//左に動かす
		y_mtrx[ynotoki_x][ynotoki_y - 1] = 0;
		costy[1] = distance(y_mtrx, p_n);
		printpuzzle(y_mtrx);

		y_mtrx[ynotoki_x][ynotoki_y - 1] = y_mtrx[ynotoki_x][ynotoki_y];//元に戻す
		y_mtrx[ynotoki_x][ynotoki_y] = 0;
		break;
	}
}

int printpuzzle(int print_puzzle[][3]){//パズルの状態を表示する関数
	int i,j;
	for (i = 0; i < 3;i++){
		for (j = 0; j < 3;j++){
			printf("%d ", print_puzzle[i][j]);
		}
		printf("\n");
	}
	getchar();
}

int push(int push_cost,int push_puzzle[][3])//ブッシュ
{
	int i, j;
	if (stack_amount < STACK_SIZE) {
		puzzle_cost[stack_amount] = push_cost;
		for (i = 0; i < 3;i++){
			for (j = 0; j < 3;j++){
				puzzle[stack_amount][i][j] = push_puzzle[i][j];
			}
		}
		stack_amount++;
		return 1;
	}
	else {
		return 0;
	}
}

int pop()//ポップ
{
	int i, j;
	if (stack_amount > 0) {
		stack_amount--;
		puzzle_cost[stack_amount]=STACK_SIZE;
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
		puzzle[stack_amount][i][j] = 0;
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}

int printstack()
{
	int i;

	printf("stack [");
	for (i = 0; i < stack_amount; i++) {
		printf("%3d", puzzle_cost[i]);
	}
	printf("]\n");
}

int dainyuu(int dainyuu_mtrx1[][3],int dainyuu_mtrx2[][3]){//代入元、代入先
	int i, j;
	for (i = 0; i < 3;i++){
		for (j = 0; j < 3;j++){
			dainyuu_mtrx2[i][j] = dainyuu_mtrx1[i][j];
		}
	}

}
