#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <cstdbool>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main()
{
	int loop;
	int i, j, y;

	bool DNA[20][10];
	double TEKIO[20];
	double x[20];

	int tmp_DNA[10];
	double tmp_TEKIO;
	double tmp_x;

	double max_T = 0;
	double max_x = 0;



	srand(time(NULL));
	for (i = 0; i < 20;i++)
	{
		for (j = 0; j < 10; j++)
		{
			//0or1の乱数生成してDNAにぶっこむ
			DNA[i][j] = rand() % 2;
		}
	}


	for (loop = 0; loop < 500; loop++)//500回
	{
		//突然変異（2回目以降）
		if (loop > 0)
		{
			i = rand() % 20;
			j = rand() % 10;

			if (DNA[i][j] == 0)
			{
				DNA[i][j] = 1;
			}
			else
			{
				DNA[i][j] = 0;
			}
		}


		for (i = 0; i < 20; i++)
		{

			//xを求める
			x[i] = -10;
			for (j = 0; j < 10; j++)
			{
				if (DNA[i][j] == 1)
				{

					x[i] += 0.02443792766373411534701857282502 * pow(2, j);

					
				}
			}

			//適応度
			TEKIO[i] = sin(x[i]*M_PI / 7)*(4 * logf(x[i] + 15)) + (0.35*sqrt(x[i] + 8.5));

			if (TEKIO[i] > max_T)
			{
				max_T = TEKIO[i];
				max_x = x[i];
			}

		}


		for (i = 0; i < 19; i++)
		{
			for (j = 0; j < 19; j++)
			{
				if (TEKIO[j] < TEKIO[j + 1]) //[0]大 [19]小となるように
				{
					tmp_TEKIO = TEKIO[j];
					TEKIO[j] = TEKIO[j + 1];
					TEKIO[j + 1] = tmp_TEKIO;

					tmp_x = x[j];
					x[j] = x[j + 1];
					x[j + 1] = tmp_x;

					for (y = 0; y < 10; y++)
					{
						tmp_DNA[y] = DNA[i][y];
						DNA[i][y] = DNA[i + 1][y];
						DNA[i + 1][y] = tmp_DNA[y];
					}
					

				}
			}
		}

		//交叉
		for (i = 0; i < 20; i += 2)
		{
			for (j = 0; j < 5; j++)
			{

				tmp_DNA[j] = DNA[i][j];
				DNA[i][j] = DNA[i + 1][j];
				DNA[i + 1][j] = tmp_DNA[j];

			}
		}

	}

	
	printf("500世代最大適応度:%f,x:%f\n",TEKIO[0],x[0]);
	printf("全世代最大適応度:%f,x:%f\n", max_T, max_x);
	printf("\n");
}