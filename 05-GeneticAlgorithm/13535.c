//期限内にプログラムが完成せず
//第一世代の生成、指定された関数、および暫定的なエリート選択のみの実装になります
//ルーレット選択及び突然変異につきましては実装しておりません

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
#include <math.h>
#pragma warning(disable : 4996)

#define S 25 / 1000
#define num 20
#define fit_min -1

typedef struct _GE
{

	double x;
	double y;
	double fit;   //適応度
	double parse; //ルーレット選択に用いる比率
	char data[10];
	int flag;

} GE;

//プロトタイプ宣言
void RAM(GE *ge);
void GEA(GE ge[num]);
void Sort(GE *ge);
void Elite(GE *ge);
void Roulette(GE *ge);
GE GE_Copy(GE input);
double F(double x);

int main()
{

	GE ge[num];
	int i;

	//乱数生成に必要
	srand((unsigned)time(NULL));

	//第1世代生成
	for (i = 0; i < num; i++)
	{
		RAM(&ge[i]);

		ge[i].flag = 0;
		ge[i].fit = 0;
		ge[i].parse = 0;

		//printf("\nr=%lf\n", ge[i].x);
	}

	GEA(ge);

	getchar();
}

void GEA(GE ge[num])
{
	GE honor;
	int i, n, m;

	honor.y = 0;

	//500世代ループ
	for (i = 0; i < 500; i++)
	{

		//関数処理をしてf(x)を求める
		for (n = 0; n < num; n++)
		{
			ge[n].y = F(ge[n].x);
			//printf("x=%lf\ny=%lf\n\n", ge[n].x, ge[n].y);
			//y=f(x)の値が最も大きかったものを記憶
			if (ge[n].y > honor.y)
				honor = ge[n];
		}

		//現在のデータ表示
		printf("第%d世代　遺伝子コード\n", i + 1);
		//表示
		for (n = 0; n < num; n++)
		{
			for (m = 0; m < 10; m++)
			{
				printf("%d", ge[n].data[m]);
			}
			printf("\n");
		}

		//適応度計算をする
		honor.fit = 1;
		printf("%d世代適応度表示\n", i + 1);
		for (n = 0; n < num; n++)
		{
			ge[n].fit = ge[n].y - fit_min;
			printf("x=%10lf,y=%10lf,fit=%10lf\n", ge[n].x, ge[n].y, ge[n].fit);
		}

		//f(x)の値が大きかったもの順にソート
		Sort(ge);

		//並び替え後
		printf("\n適応度により並び替え\n");
		for (n = 0; n < num; n++)
			printf("x=%10lf,y=%10lf,fit=%10lf\n", ge[n].x, ge[n].y, ge[n].fit);

		//適応度から比率を計算
		Elite(ge);
		//Roulette(ge);

		getchar();
	}
}

//エリート選択
void Elite(GE *ge)
{
	int i, n;
	int next_data[2][10];
	double strint[2];

	for (i = 0; i < 10; i = i + 2)
	{

		//中央の位置で一点交差
		for (n = 0; n < 10; n++)
		{
			if (n < 5)
			{
				next_data[0][n] = (ge + i)->data[n];
				next_data[1][n] = (ge + i + 1)->data[n];
			}
			else
			{
				next_data[1][n] = (ge + i)->data[n];
				next_data[0][n] = (ge + i + 1)->data[n];
			}
		}

		//データ更新
		strint[0] = 0;
		strint[1] = 0;
		for (n = 0; n < 10; n++)
		{
			(ge + i)->data[n] = next_data[0][n];
			(ge + i + 1)->data[n] = next_data[1][n];
		}
		for (n = 0; n < 10; n++)
		{
			strint[0] += (ge + i)->data[9 - n] * pow(2.0, n);
			strint[1] += (ge + i + 1)->data[9 - n] * pow(2.0, n);
		}
		(ge + i)->x = -10 + strint[0] * S;
		(ge + i + 1)->x = -10 + strint[1] * S;
	}
}

void Roulette(GE *ge)
{
	int i, n;
	double fit_sum = 0;
	double p;
	double pa;
	int next_data[10][10];

	//適応度の合計を計算
	for (i = 10; i < num; i++)
	{
		fit_sum += (ge + i)->fit;
	}

	printf("fit_sum=%lf\n", fit_sum);

	for (i = 10; i < num; i++)
	{
		(ge + i)->parse = (ge + i)->fit / fit_sum;
		printf("割合%lf\n", (ge + i)->parse);
	}

	for (i = num / 2; i < num; i = i + 2)
	{

		i = 10;
		p = 0;
		pa = (double)(rand() % 100) / 100;
		while (1)
		{
			p += (ge + i)->parse;
			if (p > pa)
				break;
			else
				i++;
		}
		printf("pa=%lf, i=%d\n", pa, i);
	}
}

//乱数から2進10ケタの値を生成、それを-10〜15の実数に直してGE構造体のxに代入する
void RAM(GE *ge)
{
	int i;
	double strint;

	while (1)
	{
		strint = 0;
		for (i = 9; i >= 0; i--)
		{
			ge->data[9 - i] = rand() % 2;
			strint += ge->data[9 - i] * pow(2.0, i);
		}

		ge->x = -10 + strint * S;
		if (ge->x <= 15.0)
			break;
	}
	//printf("%lf strint=%lf\n",ge->r,strint);
}

//yの値が高い順にソート
void Sort(GE *ge)
{
	GE save;
	int n, m, m_save;

	for (n = 0; n < num; n++)
	{
		save = *(ge + n);
		m_save = n;
		for (m = n; m < num; m++)
		{
			if (save.y < (ge + m)->y)
			{
				save = *(ge + m);
				m_save = m;
			}
		}
		*(ge + m_save) = *(ge + n);
		*(ge + n) = save;
	}
}

GE GE_Copy(GE input)
{
	GE copy;
	int i;

	for (i = 0; i < 10; i++)
	{
		copy.data[i] = input.data[i];
	}
	copy.fit = input.fit;
	copy.x = input.x;
	copy.y = input.y;
	copy.parse = input.parse;
	copy.flag = input.flag;

	return copy;
}

//提示された関数
double F(double x)
{
	double y;

	y = sin((x * M_PI) / 7) * (4 * log(x + 15) / (x + 15)) + (0.35 * sqrt(x + 8.5));
	if (isfinite(y) == 0)
		y = fit_min;

	return y;
}
