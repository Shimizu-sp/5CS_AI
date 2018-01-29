/*
**What is this program:GA to search the max function value.
**Author:Daisuke Kuwahara
**Mail:abcexe1@gmail.com
**Operating environment:
	-OS:Windows 10 64bit Pro
	-IDE:Visual studio 2012
**Language:C
**環境依存性について；
**　本プログラムは，"_finite(x)"(xが否数か無限化を調べる関数)を使用しているため，VisualStudio2012環境に依存しています．
**　"_finite(x)"の動作を保証しているコンパイラか否かは各コンパイルメーカのリファレンスを確認してください．
**　Visual Stusioシリーズにおける"_finite(x)"の動作環境は"https://msdn.microsoft.com/en-us/library/sb8es7a8(v=vs.110).aspx"に記載されています．
**　本プログラムでは，"_finite(x)"以外の否数，無限大確認方法として"isinf(x)"と"isnan(x)"を使用したソースを用意しています．
**　"isinf(x)"と"isnan(x)"を利用したソースでコンパイルを行いたい場合には"VISUALSTUDIO2012"マクロを削除してください．
**　ただし，動作は保証しません
*/

//コンパイラ定義用マクロ

/*
Visual Studio 2012でコンパイルを行う際には，このマクロを定義してください．
VS2012以外でのコンパイル時に，コンパイルに失敗する場合には，このマクロを消去することでコンパイル可能になる可能性があります．
*/
#define VISUALSTUDIO2012

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include <math.h>

/*マクロ定義域*/
#define GENE_NUM 20				   //遺伝子の個数
#define MAX_GENERATION 500		   //何世代まで計算するか
#define MUTATION_NUM GENE_NUM / 20 //突然変異を起こす個数
#define MAX_RANGE 15			   //探索範囲の最大値
#define MIN_RANGE -10			   //探索範囲の最小値
#define PI 3.14159265			   //円周率の定義

/*関数マクロ定義域*/
#define FUNC(x) (sin(((x)*PI) / 7.0) * ((4.0 * log((x) + 15.0)) / ((x) + 15.0)) + (0.35 * sqrt((x) + 8.5)))			 //探索対象の関数．必ず入力変数は()の中に記述すること
#define G2V(x) ((double)MIN_RANGE + ((double)((x).gene.G_num) * (((double)MAX_RANGE - (double)MIN_RANGE) / 1024.0))) //探索範囲の刻み幅

/*各種変数宣言域*/
//遺伝子を格納数する構造体
typedef struct def_Gene
{
	unsigned int gene_0 : 1;
	unsigned int gene_1 : 1;
	unsigned int gene_2 : 1;
	unsigned int gene_3 : 1;
	unsigned int gene_4 : 1;
	unsigned int gene_5 : 1;
	unsigned int gene_6 : 1;
	unsigned int gene_7 : 1;
	unsigned int gene_8 : 1;
	unsigned int gene_9 : 1;
	unsigned int gene_del : (sizeof(unsigned int) * 8) - 10; //遺伝子のビットを10進数として示すため，unsigned int型の先頭bitを，10bit分を除いて，確保する．
} Gene;

//遺伝子を0を含む自然数に変換するための共用体
typedef union def_Gene_Union {
	Gene G;				//遺伝子のデータ
	unsigned int G_num; //遺伝子を整数値で示すための変数
} GU;

//適合値と遺伝子を含む構造体
typedef struct def_G
{
	GU gene;		//遺伝子
	double conform; //適合値
} Ge;

int main()
{
	Ge g[GENE_NUM];					 //遺伝子格納用変数
	Ge inter_upper[GENE_NUM / 4][2]; //上位交差時使用遺伝子格納用変数
	Ge inter_lower[GENE_NUM / 4][2]; //下位交差時使用遺伝子格納用変数

	int i, k, n, p;				//for文用変数
	int max[GENE_NUM / 2];		//適応度が高い遺伝子の配列番号を格納する変数
	int min[GENE_NUM / 2];		//適応度が低い遺伝子の配列番号を格納する変数
	int keep_log[MUTATION_NUM]; //突然変異を起こした遺伝子の添え字を格納
	double high[GENE_NUM / 2];  //遺伝子の適応度を高い順に格納する変数
	double keep;				//適応度を一時格納しておく変数
	double sum_conform = 0.0;   //下位の遺伝子10個の適応度の合計を格納する変数
	Ge gene_max;				//過去の関数の出力の中で最大のものを格納しておく変数

	/*初期集団生成*/

	//乱数のシードを時刻より与える
	srand(time(NULL));

	//乱数によって，初期集団を生成
	for (i = 0; i < GENE_NUM; i++)
	{
		g[i].gene.G.gene_del = 0;
		g[i].gene.G.gene_0 = rand() % 2;
		g[i].gene.G.gene_1 = rand() % 2;
		g[i].gene.G.gene_2 = rand() % 2;
		g[i].gene.G.gene_3 = rand() % 2;
		g[i].gene.G.gene_4 = rand() % 2;
		g[i].gene.G.gene_5 = rand() % 2;
		g[i].gene.G.gene_6 = rand() % 2;
		g[i].gene.G.gene_7 = rand() % 2;
		g[i].gene.G.gene_8 = rand() % 2;
		g[i].gene.G.gene_9 = rand() % 2;
	}

	//乱数でgene_maxの初期値を生成
	gene_max.gene.G.gene_del = 0;
	gene_max.gene.G.gene_0 = rand() % 2;
	gene_max.gene.G.gene_1 = rand() % 2;
	gene_max.gene.G.gene_2 = rand() % 2;
	gene_max.gene.G.gene_3 = rand() % 2;
	gene_max.gene.G.gene_4 = rand() % 2;
	gene_max.gene.G.gene_5 = rand() % 2;
	gene_max.gene.G.gene_6 = rand() % 2;
	gene_max.gene.G.gene_7 = rand() % 2;
	gene_max.gene.G.gene_8 = rand() % 2;
	gene_max.gene.G.gene_9 = rand() % 2;

	//max変数の初期化
	for (i = 0; i < GENE_NUM / 2; i++)
		max[i] = -1;

	//min変数の初期化
	for (i = 0; i < GENE_NUM / 2; i++)
		min[i] = -1;

	//各種情報の表示

	/*
	<出力内容>
	選択方法		：上位50%をエリート選択，下位50%をルーレット選択
	交差方法		：1点交差
	遺伝子の個数	：プログラム内で指定された値
	遺伝子の長さ	：10
	最大世代数		：プログラム内で指定された値
	交差位置		：中央のみの1点交差法
	突然変異発生率	：全体の5%
	突然変異法		：10桁中1桁の値を変異
	目的			：適応値の最大化
	適応値の算出法	：対象の遺伝子の関数の出力 - 過去のものを含む全遺伝子中最大値の関数の出力
	*/

	printf("選択方法\t：上位%d個をエリート選択，下位%d個をルーレット選択\n", GENE_NUM / 2, GENE_NUM / 2);
	printf("遺伝子の個数\t：%d\n", GENE_NUM);
	printf("遺伝子の長さ\t：10\n");
	printf("最大世代数\t：%d\n", MAX_GENERATION);
	printf("交差位置\t：中央のみの1点交差法\n");
	printf("突然変異発生率\t：全体の5％\n");
	printf("突然変異法\t：10桁中1桁の値を変異\n");
	printf("目的\t\t：適応値の最大化\n");
	printf("適応値の算出法\t：対象の遺伝子の関数の出力 - 過去のものを含む全遺伝子中最大値の関数の出力\n");

	//世代を繰り返すためのループ
	for (i = 0; i < MAX_GENERATION; i++)
	{
		/*変数の初期化*/
		for (k = 0; k < MUTATION_NUM; k++)
			keep_log[k] = -1;
		for (k = 0; k < GENE_NUM / 2; k++)
			high[k] = -DBL_MAX;

		/*適応度計算*/
		for (k = 0; k < GENE_NUM; k++)
		{
			//各遺伝子の適応度を計算
			g[k].conform = FUNC(G2V(g[k])) - FUNC(G2V(gene_max));

			//過去のものを含む全遺伝子中最大値の関数の出力を更新と，InfとNaNの場合の例外処理
#ifdef VISUALSTUDIO2012
			if (_finite(FUNC(G2V(g[k]))) == 0)
				g[k].conform = -DBL_MAX; //遺伝子による関数の出力が否数である場合，適応度を最低に設定する
			else if (FUNC(G2V(g[k])) > FUNC(G2V(gene_max)))
				gene_max = g[k];
#endif
#ifndef VISUALSTUDIO2012
			if (isnan(FUNC(G2V(g[k]))))
				g[k].conform = -DBL_MAX; //遺伝子による関数の出力が否数である場合，適応度を最低に設定する
			else if (isinf(FUNC(G2V(g[k]))))
				g[k].conform = -DBL_MAX; //遺伝子による関数の出力が無限大である場合，適応度を最低に設定する
			else if (FUNC(G2V(g[k])) > FUNC(G2V(gene_max)))
				gene_max = g[k];
#endif
		}

		/*選択*/

		//適応度の上位10個と下位10個を選択する(線形探索)
		for (k = 0; k < GENE_NUM; k++)
		{
			int min_cnt = 0;

			for (n = 0; n < GENE_NUM / 2; n++)
			{
				if (high[n] < g[k].conform)
				{
					double kept[2] = {g[k].conform, -1.0};
					int max_kept[2] = {k, -1};

					//順位を更新
					for (p = n; p < GENE_NUM / 2; p++)
					{
						kept[1] = high[p];
						high[p] = kept[0];
						kept[0] = kept[1];

						max_kept[1] = max[n];
						max[n] = max_kept[0];
						max_kept[0] = max_kept[1];
					}

					//配列の引数になる値(つまり，max配列の初期化で代入した値(-1)以外)がmax_kept[0]にはいるとき -> max_kept[0]の中身は上位から下位に移動する遺伝子の配列の引数となる
					if (max_kept[0] != -1)
					{
						min[min_cnt] = max_kept[1];
						min_cnt++;
					}
				}
				else
				{
					//high[n]の中のすべての値よりもg[k].conformが低い場合，配列の引数kを下位10のほうに入れる．
					min[min_cnt] = k;
					min_cnt++;
				}
			}
		}

		//上位の遺伝子のペアを決める(エリート選択)
		for (k = 0; k < GENE_NUM / 4; k++)
		{
			inter_upper[k][0] = g[max[k * 2]];
			inter_upper[k][1] = g[max[k * 2 + 1]];
		}

		//下位の遺伝子のペアを決める(ルーレット選択)
		//ルーレットで選択される確率を決める方法：(遺伝子の適応度-遺伝子群の適応度の最低値) / (遺伝子の適応度-遺伝子群の適応度の最低値)の合計

		//下位の遺伝子において最も値が低いものを探索する．
		keep = DBL_MAX;
		for (k = 0; k < GENE_NUM / 2; k++)
			if (keep > g[k].conform)
				keep = g[k].conform;

		//下位の遺伝子の適応値の最低値がマイナスにならないように調整して，比率を求める
		for (k = 0; k < GENE_NUM / 2; k++)
			sum_conform += g[min[k]].conform - keep;

		for (k = 0; k < GENE_NUM / 2; k++)
		{
			double target = (double)abs(rand()); //乱数により，0を含む自然数を生成
			double sum = 0.0;

			//選択用の値を計算する
			while (target > 1)
				target /= 10.0;

			for (n = 0; n < GENE_NUM / 2; n++)
			{
				if (target < (sum + ((g[min[n]].conform - keep) / sum_conform)))
					inter_lower[k / 2][k % 2] = g[min[n]];
				else
					sum += (g[min[n]].conform - keep) / sum_conform;
			}
		}

		/*交差*/

		for (k = 0; k < GENE_NUM / 4; k++)
		{
			//上位の遺伝子のペアを中央で交差
			g[k * 4].gene.G.gene_0 = inter_upper[k][0].gene.G.gene_0;
			g[k * 4].gene.G.gene_1 = inter_upper[k][0].gene.G.gene_1;
			g[k * 4].gene.G.gene_2 = inter_upper[k][0].gene.G.gene_2;
			g[k * 4].gene.G.gene_3 = inter_upper[k][0].gene.G.gene_3;
			g[k * 4].gene.G.gene_4 = inter_upper[k][0].gene.G.gene_4;
			g[k * 4].gene.G.gene_5 = inter_upper[k][1].gene.G.gene_5;
			g[k * 4].gene.G.gene_6 = inter_upper[k][1].gene.G.gene_6;
			g[k * 4].gene.G.gene_7 = inter_upper[k][1].gene.G.gene_7;
			g[k * 4].gene.G.gene_8 = inter_upper[k][1].gene.G.gene_8;
			g[k * 4].gene.G.gene_9 = inter_upper[k][1].gene.G.gene_9;

			g[k * 4 + 1].gene.G.gene_0 = inter_upper[k][1].gene.G.gene_0;
			g[k * 4 + 1].gene.G.gene_1 = inter_upper[k][1].gene.G.gene_1;
			g[k * 4 + 1].gene.G.gene_2 = inter_upper[k][1].gene.G.gene_2;
			g[k * 4 + 1].gene.G.gene_3 = inter_upper[k][1].gene.G.gene_3;
			g[k * 4 + 1].gene.G.gene_4 = inter_upper[k][1].gene.G.gene_4;
			g[k * 4 + 1].gene.G.gene_5 = inter_upper[k][0].gene.G.gene_5;
			g[k * 4 + 1].gene.G.gene_6 = inter_upper[k][0].gene.G.gene_6;
			g[k * 4 + 1].gene.G.gene_7 = inter_upper[k][0].gene.G.gene_7;
			g[k * 4 + 1].gene.G.gene_8 = inter_upper[k][0].gene.G.gene_8;
			g[k * 4 + 1].gene.G.gene_9 = inter_upper[k][0].gene.G.gene_9;

			//下位の遺伝子のペアを中央で交差
			g[k * 4 + 2].gene.G.gene_0 = inter_lower[k][0].gene.G.gene_0;
			g[k * 4 + 2].gene.G.gene_1 = inter_lower[k][0].gene.G.gene_1;
			g[k * 4 + 2].gene.G.gene_2 = inter_lower[k][0].gene.G.gene_2;
			g[k * 4 + 2].gene.G.gene_3 = inter_lower[k][0].gene.G.gene_3;
			g[k * 4 + 2].gene.G.gene_4 = inter_lower[k][0].gene.G.gene_4;
			g[k * 4 + 2].gene.G.gene_5 = inter_lower[k][1].gene.G.gene_5;
			g[k * 4 + 2].gene.G.gene_6 = inter_lower[k][1].gene.G.gene_6;
			g[k * 4 + 2].gene.G.gene_7 = inter_lower[k][1].gene.G.gene_7;
			g[k * 4 + 2].gene.G.gene_8 = inter_lower[k][1].gene.G.gene_8;
			g[k * 4 + 2].gene.G.gene_9 = inter_lower[k][1].gene.G.gene_9;

			g[k * 4 + 3].gene.G.gene_0 = inter_lower[k][1].gene.G.gene_0;
			g[k * 4 + 3].gene.G.gene_1 = inter_lower[k][1].gene.G.gene_1;
			g[k * 4 + 3].gene.G.gene_2 = inter_lower[k][1].gene.G.gene_2;
			g[k * 4 + 3].gene.G.gene_3 = inter_lower[k][1].gene.G.gene_3;
			g[k * 4 + 3].gene.G.gene_4 = inter_lower[k][1].gene.G.gene_4;
			g[k * 4 + 3].gene.G.gene_5 = inter_lower[k][0].gene.G.gene_5;
			g[k * 4 + 3].gene.G.gene_6 = inter_lower[k][0].gene.G.gene_6;
			g[k * 4 + 3].gene.G.gene_7 = inter_lower[k][0].gene.G.gene_7;
			g[k * 4 + 3].gene.G.gene_8 = inter_lower[k][0].gene.G.gene_8;
			g[k * 4 + 3].gene.G.gene_9 = inter_lower[k][0].gene.G.gene_9;
		}

		/*突然変異*/
		k = 0;

		while (keep_log[MUTATION_NUM - 1] != -1)
		{
			int target = rand() % GENE_NUM; //突然変異させる遺伝子の添え字を決定する変数
			int change_num = rand() % 10;   //値を変化させる桁を決定する変数

			//すでに突然変異していないかを確認
			for (p = 0; p < MUTATION_NUM; p++)
				if (keep_log[p] == target)
					continue;

			switch (change_num)
			{
			case 0:
				g[target].gene.G.gene_0 += 1; //+1することで値がオーバーフローして0と1が反転する
				break;
			case 1:
				g[target].gene.G.gene_1 += 1; //+1することで値がオーバーフローして0と1が反転する
				break;
			case 2:
				g[target].gene.G.gene_2 += 1; //+1することで値がオーバーフローして0と1が反転する
				break;
			case 3:
				g[target].gene.G.gene_3 += 1; //+1することで値がオーバーフローして0と1が反転する
				break;
			case 4:
				g[target].gene.G.gene_4 += 1; //+1することで値がオーバーフローして0と1が反転する
				break;
			case 5:
				g[target].gene.G.gene_5 += 1; //+1することで値がオーバーフローして0と1が反転する
				break;
			case 6:
				g[target].gene.G.gene_6 += 1; //+1することで値がオーバーフローして0と1が反転する
				break;
			case 7:
				g[target].gene.G.gene_7 += 1; //+1することで値がオーバーフローして0と1が反転する
				break;
			case 8:
				g[target].gene.G.gene_8 += 1; //+1することで値がオーバーフローして0と1が反転する
				break;
			case 9:
				g[target].gene.G.gene_9 += 1; //+1することで値がオーバーフローして0と1が反転する
				break;
			}

			keep_log[k] = target;
			k++;
		}
	}

	//初期化
	max[0] = -1;
	keep = -DBL_MAX;

	//適合率が最も良い遺伝子を検索
	for (i = 0; i < GENE_NUM; i++)
	{
		if (keep < g[i].conform)
		{
			max[0] = i;
			keep = g[i].conform;
		}
	}

	//エラー処理
	if (max[0] == -1)
	{
		perror("不明なエラーです");
		printf("何かキーを押して終了...\n");
		getchar();
		return -1;
	}

	//結果を出力
	printf("\n\n<500世代終了後の最大値>\n");
	printf("xの値\t\t：x = %lf\n", G2V(g[max[0]]));
	printf("関数の出力\t：y = %lf\n", FUNC(G2V(g[max[0]])));

	printf("\n<500世代全体の最大値>\n");
	printf("xの値\t\t：x = %lf\n", G2V(gene_max));
	printf("関数の出力\t：y = %lf\n", FUNC(G2V(gene_max)));

	printf("\n何かキーを押して終了...\n");
	getchar();

	return 0;
}