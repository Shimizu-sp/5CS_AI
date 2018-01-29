#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int ge[20][10];

double enzan1(double x1);

int main()
{
	int i = 0, j = 0;
	int num;
	int henkan = 0;
	int enzan2[100];
	int enzan = 0;
	float j2 = 0;
	float j3 = 0;

	double x1 = 0;
	float n = 10;

	//乱数生成用
	srand(time(NULL));

	//10桁の遺伝子生成・出力
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			num = rand() % 2;
			ge[i][j] = num;
			printf("%d ", ge[i][j]);
		}
		printf("\n");
	}

	//二進数から10進数に変換する
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			henkan = ge[i][j];

			if (henkan == 1)
			{
				j2 = j;
				j3 = abs(j2 - 9);
				enzan += pow(2, j3);
				printf("enzan %d   j2=%.1f \n", enzan, j2);
			}
		}
		enzan2[j] = enzan;
		enzan = 0;
		printf("enzan2 == %d\n", enzan2[j]);

		//正規化関数に入れる
		x1 = -10 + ((15 + 10) / 1024) * enzan2[j];
		printf("評価関数%f\n", x1);
		printf("\n");
		//結果を式に入れて計算する
		enzan1(x1);
		enzan2[j] = 0;
	}
}

//式計算用の関数
double enzan1(double x1)
{

	double x;
	double logn;
	double sinn;
	double sonot;
	double kekka1;

	static const double pi = 3.14159265358979323846264338327950288;

	sinn = sin(x1 * pi / 7);
	logn = (4 * log(x1 + 15)) / x1 + 15;
	sonot = 0.35 * pow((x1 + 0.85), (1 / 2));
	kekka1 = sinn * logn + sonot;

	printf("kekka1 = %.10f\n", kekka1);

	return 0;
}