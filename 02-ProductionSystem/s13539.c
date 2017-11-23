
#include<stdio.h>
#include<stdbool.h>

//変数宣言
char moji[11] = "a*b-cd/e+fg";
char kotae[11] = "gfedcba+-*/";
bool seigyo = 1;
int i = 0, j = 0;
int tmp;

void migi_ido(int);
void print();

main()
{

	print();
	
	while (seigyo == 1 && moji != kotae)
	{
		seigyo = 0;
		for (i = 0; seigyo == 0 && i < 10; i++)
		{
			//moji[i]が記号で右隣が文字のとき入れ替える
			if (moji[i] < 50 && moji[i+1] > 90)
			{
				migi_ido(i);
				seigyo++;
				print();
			}
		}

		for (i = 0; seigyo == 0 && i < 10; i++)
		{		
			//moji[i]が文字で右のほうが大きいとき入れ替える
			if (moji[i] > 90 && moji[i] < moji[i+1])
			{
				migi_ido(i);
				seigyo++;
				print();
			}
		}

		for (i = 0; seigyo == 0 && i < 10; i++)
		{
			//moji[i]が記号で右が"*"以外で右のほうが大きいとき入れ替える
			if (moji[i] < 50 && moji[i] > moji[i+1] && moji[i+1] != 42)
			{
				migi_ido(i);
				seigyo++;
				print();
			}
		}
		
		for (i = 0; seigyo == 0 && i < 10; i++)
		{
			//moji[i]"*"で右が"/"以外のとき入れ替える
			if (moji[i] == 42 && moji[i + 1] != 47)
			{
				migi_ido(i);
				seigyo++;
				print();
			}
		}

		for (i = 0; seigyo == 0 && i < 10; i++)
		{
			//moji[i]"/"で右が"*"のとき入れ替える
			if (moji[i] == 47 && moji[i + 1] == 42)
			{
				migi_ido(i);
				seigyo++;
				print();
			}
		}
	}
}

//右隣と入れ替える関数
void migi_ido(int i)
{
	tmp = moji[i];
	moji[i] = moji[i + 1];
	moji[i + 1] = tmp;
}

//文字列を出力
void print()
{
	for (j = 0; j < 11; j++)
	{
		printf("%c", moji[j]);
	}
	printf("\n");
}