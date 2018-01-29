#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

// 構造体gene　10桁　式の結果
struct gene
{
	int gene[20];
	double f; //　式の結果
};

double Fitness(double resu); // 適応度関数

int main()
{
	struct gene genelation[20];
	double aa = 0;

	srand(time(NULL));

	for (int n = 0; n < 20; n++)
	{
		printf("gene%d : ", n + 1);
		for (int i = 0; i < 10; i++)
		{
			int num = rand() % 2; // 0と1に変換
			genelation[n].gene[i] = num;
			printf("%d ", genelation[n].gene[i]);
		}
		printf("\n");
	}

	Fitness(genelation[5].gene[20]);
}

double Fitness(double resu)
{
	double result;
	double x = 0;
	x = 10;

	// sin(x * π/7) * 4loge(x + 15) / (x + 15)) + 0.35√x+8.5
	result = (sin(x * M_PI / 7)) * (4 * logf(x + 15) / (x + 15)) + (0.35 * sqrt(x + 8.5));
	printf("%f\n", result);
}