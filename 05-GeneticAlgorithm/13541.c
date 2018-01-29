#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int i, binary = 0, decimal, base = 1, bin[20];
	float n[20], c[20], a[20];
	srand((unsigned)time(NULL));

	for (i = 0; i < 20; i++)
	{
		n[i] = rand() % 26 - 10; //-10~15の整数を生成
		c[i] = (rand() % 100000) / 100000.00;

		decimal = n[i];
		if (decimal < 0)
		{
			decimal = decimal * (-1) - 1;
		}

		while (decimal > 0)
		{ //2進数変換

			binary = binary + (decimal % 2) * base;
			decimal = decimal / 2;
			base = base * 10;
		}

		printf("2進数＝%d　", binary);
		a[i] = n[i] + c[i]; //10進数乱数の生成
		printf("10進数＝%f\n", a[i]);
		bin[i] = binary;

		binary = 0;
		base = 1;
	}
}