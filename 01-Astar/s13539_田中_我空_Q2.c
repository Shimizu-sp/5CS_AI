
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//変数宣言
int mondai[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } };//[y座標][x座標]
int kansei[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };
int tmp[3][3];

int i = 0, j = 0;
int x = 0, y = 0;

int zero_x = 0, zero_y = 0;
int kyori_tmp[4];//子のマンハッタン距離
int min_num = 0;
int min_manhattan;//子の中の最少のマンハッタン距離
int loop=0;//子のパズル移動回数
int loop_mondai;//親のパズル移動回数
int move;//パズルがどの方向に動いたか

//関数宣言
int manhattan(int[3][3]);
void zero_zahyo(int[3][3]);
void print_puzzle(int[3][3]);
void create_tmp();

//スタック
void push(int, int[3][3], int);
int pop();

int stack_manhattan[1000];
int stack_loop[1000];
int stack_pazzle[1000][3][3];
int stack_num = 0;//スタックされている数
int stack_move[1000];
int stack_num_tmp;//スタックの中身表示するとき用


void main()
{

	push(loop, mondai,-1);//初期状態をpush

	create_tmp(mondai);
	while (manhattan(tmp) > 0 && stack_num > 0)//完成するかスタックが空になるまで
	{
		loop_mondai = pop();
		print_puzzle(mondai);

		if (loop_mondai < 30)
		{

			loop = loop_mondai;
			//print_puzzle(mondai);
			loop++;
			


			kyori_tmp[1] = 99999999;
			kyori_tmp[3] = 99999999;
			create_tmp(mondai);//tmpにmondaiをコピー
			zero_zahyo(mondai);//０の座標get

			switch (zero_x)		//tmpを使ってパズルの移動と距離の計算
			{
			case 0:
				tmp[zero_y][zero_x] = tmp[zero_y][zero_x + 1];//パズル移動
				tmp[zero_y][zero_x + 1] = 0;

				kyori_tmp[0] = manhattan(tmp);//比較するために距離を保存


				break;
			case 1:
				tmp[zero_y][zero_x] = tmp[zero_y][zero_x - 1];
				tmp[zero_y][zero_x - 1] = 0;

				kyori_tmp[0] = manhattan(tmp);


				create_tmp(mondai);//tmpをリセット


				tmp[zero_y][zero_x] = tmp[zero_y][zero_x + 1];
				tmp[zero_y][zero_x + 1] = 0;

				kyori_tmp[1] = manhattan(tmp);


				break;
			case 2:
				tmp[zero_y][zero_x] = tmp[zero_y][zero_x - 1];
				tmp[zero_y][zero_x - 1] = 0;

				kyori_tmp[0] = manhattan(tmp);

				break;
			}


			create_tmp(mondai);//tmpをリセット



			switch (zero_y)//yでも同じことを
			{
			case 0:
				tmp[zero_y][zero_x] = tmp[zero_y + 1][zero_x];
				tmp[zero_y + 1][zero_x] = 0;

				kyori_tmp[2] = manhattan(tmp);

				break;
			case 1:
				tmp[zero_y][zero_x] = tmp[zero_y - 1][zero_x];
				tmp[zero_y - 1][zero_x] = 0;

				kyori_tmp[2] = manhattan(tmp);


				create_tmp(mondai);//tmpを元に戻す



				tmp[zero_y][zero_x] = tmp[zero_y + 1][zero_x];
				tmp[zero_y + 1][zero_x] = 0;

				kyori_tmp[3] = manhattan(tmp);


				break;
			case 2:
				tmp[zero_y][zero_x] = tmp[zero_y - 1][zero_x];
				tmp[zero_y - 1][zero_x] = 0;

				kyori_tmp[2] = manhattan(tmp);

				break;
			}





			min_manhattan = 100000000;
			for (i = 0; i < 4; i++)//マンハッタン距離の比較
			{
				if (min_manhattan > kyori_tmp[i])
				{
					min_manhattan = kyori_tmp[i];

				}
			}

			


			//moveは、0が→移動で1,←2,↓3,↑4

			create_tmp(mondai);
			zero_zahyo(mondai);//０の座標get

			switch (zero_x)//最少のマンハッタン距離のものをpush
			{
			case 0:

				tmp[zero_y][zero_x] = tmp[zero_y][zero_x + 1];//パズル移動
				tmp[zero_y][zero_x + 1] = 0;

				//子の中で最少のマンハッタン距離のときのみpush（また、moveを使うことで前回の盤面に戻る動きをさせない）
				if (min_manhattan == manhattan(tmp) && move != 2)
				{
					push(loop, tmp,1);
				}
				break;

			case 1:
				tmp[zero_y][zero_x] = tmp[zero_y][zero_x - 1];
				tmp[zero_y][zero_x - 1] = 0;

				if (min_manhattan == manhattan(tmp) && move != 1)
				{
					push(loop, tmp,2);
				}

				create_tmp(mondai);//tmpをリセット


				tmp[zero_y][zero_x] = tmp[zero_y][zero_x + 1];
				tmp[zero_y][zero_x + 1] = 0;

				if (min_manhattan == manhattan(tmp) && move != 2)
				{
					push(loop, tmp,1);
				}


				break;
			case 2:
				tmp[zero_y][zero_x] = tmp[zero_y][zero_x - 1];
				tmp[zero_y][zero_x - 1] = 0;

				if (min_manhattan == manhattan(tmp) && move != 1)
				{
					push(loop, tmp,2);
				}

				break;
			}
			create_tmp(mondai);//tmpをリセット



			switch (zero_y)//yでも同じことを
			{
			case 0:
				tmp[zero_y][zero_x] = tmp[zero_y + 1][zero_x];
				tmp[zero_y + 1][zero_x] = 0;

				if (min_manhattan == manhattan(tmp) && move != 4)
				{
					push(loop, tmp,3);
				}

				break;
			case 1:
				tmp[zero_y][zero_x] = tmp[zero_y - 1][zero_x];
				tmp[zero_y - 1][zero_x] = 0;

				if (min_manhattan == manhattan(tmp) && move != 3)
				{
					push(loop, tmp,4);
				}


				create_tmp(mondai);//tmpを元に戻す



				tmp[zero_y][zero_x] = tmp[zero_y + 1][zero_x];
				tmp[zero_y + 1][zero_x] = 0;

				if (min_manhattan == manhattan(tmp) && move != 4)
				{
					push(loop, tmp,3);
				}


				break;
			case 2:
				tmp[zero_y][zero_x] = tmp[zero_y - 1][zero_x];
				tmp[zero_y - 1][zero_x] = 0;

				if (min_manhattan == manhattan(tmp) && move != 3)
				{
					push(loop, tmp,4);
				}

				break;
			}
		}
	}



	print_puzzle(tmp);
	
	//スタックの要素を全て出力(現状スタックが全て空の状態で終了するため意味無し)
	for (stack_num_tmp = stack_num - 1; 0 <= stack_num_tmp; stack_num_tmp--)
	{
		printf("manhattan:%d\n", manhattan(stack_pazzle[stack_num_tmp]));
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%d ", stack_pazzle[stack_num_tmp][i][j]);

			}
			printf("\n");
		}
		printf("\n");
	}
}



int manhattan(int pazzle[3][3])
{
	int manhattan_souwa = 0;
	int x_kyori = 0, y_kyori = 0;


	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{


			for (i = 0; i < 3; i++)//tmpと同じ値の場所を探す
			{
				for (j = 0; j < 3; j++)
				{

					//0以外の時に同じ値を見つけたら距離をマンハッタンの総和に足す
					if (pazzle[y][x] == kansei[i][j] && pazzle[y][x] != 0)
					{
						x_kyori = abs(x - j);
						y_kyori = abs(y - i);
						manhattan_souwa += x_kyori + y_kyori;

					}
				}
			}
		}
	}
	
	return manhattan_souwa;

}

void zero_zahyo(int pazzle[3][3])//空の座標を入手できる
{
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (pazzle [i][j] == 0)//0の座標を保存
			{
				zero_x = j;
				zero_y = i;
			}
		}
	}
}

void print_puzzle(int puzzle[3][3])//画面出力する
{
	zero_zahyo(puzzle);
	//printf("move:%d\n", move);
	printf("マンハッタン距離の総和：%d \n", manhattan(puzzle));
	printf("移動コスト：%d \n", loop);
	//printf("空の座標[%d][%d] \n", zero_y, zero_x);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", puzzle[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//getchar();	
}

void create_tmp(int pazzle[3][3])//操作する用の盤面を作成する
{
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			tmp[i][j] = pazzle[i][j];
		}
	}
}

void push(int push_loop,int pazzle[3][3],int push_move)//スタックにpush
{

	stack_loop[stack_num] = push_loop;
	stack_move[stack_num] = push_move;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			stack_pazzle[stack_num][i][j] = pazzle[i][j];
		}
	}
	stack_num++;

}

int pop()//スタックからpop
{

	stack_num--;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			mondai[i][j] = stack_pazzle[stack_num][i][j];
		}
	}
	move = stack_move[stack_num];
	return stack_loop[stack_num];
}