#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define _USE_MATH_DEFINES
#include<math.h>

int x, y, j, count = 0, skip = 0;
double i, a = 25.0 / 1024.0;//2進数1あたりの増分
double tes = 0.50; //2進数生成
double roulette = 0; 
int gen[20][10]; //初期，子
int mother[4][10]; //親
double ten[20];  //-10~15
double fx[20]; //適応度

int main(void)
{
	srand(time(NULL));

	/*初期集団生成*/
	printf("初期集団生成\n");
	for(x = 0; x < 20; x++)
	{
		for(y = 9; y > -1; y--)
		{
			if((double)rand() / RAND_MAX < tes)
			{
				gen[x][y] = 1;
			}
			else
			{
				gen[x][y] = 0;
			}
			printf("%d", gen[x][y]);
		}
		printf("\n");
	}
	printf("\n");

	/*適応度評価*/
	printf("適応度評価\n");
	for(x = 0; x < 20; x++)
	{
		//2進数を10進数に変換
		for(y = 0; y < 10; y++)
		{
			if(gen[x][y] == 1)
			{
				ten[x] += pow(2, y);
			}
		}
		printf("%g	", ten[x]);

		//値を-10~15に直す
		ten[x] = ten[x] * a - 10;
		printf("%f	", ten[x]);

		//適応度評価
		fx[x] = sin((ten[x] * M_PI) / 7) * ((4 * log(ten[x] + 15)) / (ten[x] + 15)) + (0.35*sqrt(x + 8.5));
		printf("%f\n", fx[x]);
	}
	printf("\n");

	/*適応度の降順に並べ替える*/
	printf("適応度を降順に並べ替え\n");
	for(x = 0; x < 20; x++)
	{
		for(y = 0; y < x; y++)
		{
			if(fx[x] > fx[y])
			{
				/*10進数*/
				//-10~15
				i = ten[y];
				ten[y] = ten[x];
				ten[x] = i;

				//適応度
				i = fx[y];
				fx[y] = fx[x];
				fx[x] = i;

				/*2進数*/
				for(j = 0; j < 10; j++)
				{
					i = gen[y][j];
					gen[y][j] = gen[x][j];
					gen[x][j] = i;
				}
			}
		}
	}
	for(x = 0; x < 20; x++)
	{
		printf("%f	", ten[x]);
		printf("%f	", fx[x]);

		for(y = 9; y > -1; y--)
		{
			printf("%d", gen[x][y]);
		}
		printf("\n");
	}
	printf("\n");

	/*選択*/
	//エリート選択
	printf("エリート選択\n");
	for(x = 0; x < 2; x++)
	{
		printf("%f	", ten[x]);
		printf("%f	", fx[x]);

		for(y = 9; y > -1; y--)
		{
			mother[x][y] = gen[x][y];
			printf("%d", mother[x][y]);
		}
		printf("\n");
	}
	printf("\n");

	//ルーレット選択
	printf("ルーレット選択\n");
	for(x = 10; x < 20; x++)
	{
		roulette += fx[x];
	}

	count = 0;
	j = 0;
	for(x = 10; x < 20; x++)
	{
		if(j == 1)
			break;
		if((double)rand() / RAND_MAX < fx[x] / roulette)
		{
			if(x == 10)
			{
				skip++;
			}

			for(y = 9; y > -1; y--)
			{
				mother[3][y] = gen[x][y];
				printf("%d", mother[3][y]);
			}
			printf("\n");
			j++;
		}
	}
	if(j == 0)
	{
		for(y = 9; y > -1; y--)
		{
			mother[3][y] = gen[19][y];
			printf("%d", mother[3][y]);
		}
		printf("\n");
		count++;
		j++;
	}

	for(x = 10; x < 20; x++)
	{
		if(skip == 1)
		{
			x++;
		}
		if(j == 2)
			break;
		if((double)rand() / RAND_MAX < fx[x] / roulette)
		{
			for(y = 9; y > -1; y--)
			{
				mother[4][y] = gen[x][y];
				printf("%d", mother[4][y]);
			}
			printf("\n");
			j++;

		}
	}
	if(j == 1)
	{
		if(count == 0)
		{
			for(y = 9; y > -1; y--)
			{
				mother[4][y] = gen[19][y];
				printf("%d", mother[4][y]);
			}
			printf("\n");
		}
		else if(count == 1)
		{
			for(y = 9; y > -1; y--)
			{
				mother[4][y] = gen[18][y];
				printf("%d", mother[4][y]);
			}
			printf("\n");
		}
	}

	//交差

	//突然変異

}