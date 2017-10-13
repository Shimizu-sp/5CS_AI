#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define N 3		// パネルの縦横の長さ
#define A 100


int Tp[N][N] = {	//正解パネル
	{ 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 0 } };

int Fp[N][N] = {	//問題パネル
	{ 8, 1, 5 },
	{ 2, 0, 4 },
	{ 6, 3, 7 } };

int hantei[N][N];

int Openlist[A][N][N],
	Closelist[A][N][N];

int hp(int hantei[N][N]);


int hp(int hantei[N][N]) {		//マンハッタン距離を求める
	int a, b, x, y, i;
	int manhattan;
	manhattan = 0;
	i = 0;

	for (a = 0; a < N; a++) {
		for (b = 0; b < N; b++) {
			for (y = 0; y < N; y++) {
				if (hantei[a][b] == 0) {
					break;
				}
				for (x = 0; x < N; x++) {
					if (hantei[a][b] == Tp[y][x]) {
						//printf("%d%d\n", Tp[a][b],hantei[x][y]);
						manhattan = manhattan + abs(a - y) + abs(b - x);

						
					}
				}
			}
		}
	}

	for (x = 0; x < N; x++) {
		for (y = 0; y < N; y++) {
			printf("%d", hantei[x][y]);
		}
		printf("\n");
	}printf("\n");
	return manhattan;
}


int main() {
	int open[N][N], close[N][N], p1[N][N], p2[N][N], p3[N][N],
		p4[N][N], hantei[N][N],
		i, x, y, p1_hantei, p2_hantei, p3_hantei, p4_hantei, x2, y2;

	int manhattan = hp(Fp,hantei);
	//printf("%d", manhattan);

	for (x = 0; x < N; x++) {
		for (y = 0; y < N; y++) {
			p1[x][y] = Fp[x][y];
			p2[x][y] = Fp[x][y];
			p3[x][y] = Fp[x][y];
			p4[x][y] = Fp[x][y];
		}
	}


	for (x = 0; x < N; x++) {	//0の座標を求める
		for (y = 0; y < N; y++) {
			if (Fp[x][y] == 0) {
				x2 = x;
				y2 = y;
				break;
			}
		}
	}
	//printf("%d,%d", x2, y2);


	switch (x2) {	//0の回りのマスのマンハッタン距離を計算（縦）
	case 0:
		p1[x2][y2] = Fp[x2 + 1][y2];
		p1[x2 + 1][y2] = 0;

		p1_hantei = hp(p1);

		break;
	case 1:
		p1[x2][y2] = Fp[x2 - 1][y2];
		p1[x2 - 1][y2] = 0;
		p2[x2][y2] = Fp[x2 + 1][y2];
		p2[x2 + 1][y2] = 0;

		p1_hantei = hp(p1);
		p2_hantei = hp(p2);

		break;
	case 2:
		p1[x2][y2] = Fp[x2 - 1][y2];
		p1[x2 - 1][y2] = 0;

		p1_hantei = hp(p1);

		break;
	}


	switch (y2) {	//0の回りのマスのマンハッタン距離を計算（横）
	case 0:
		p3[x2][y2] = Fp[x2][y2 + 1];
		p3[x2][y2 + 1] = 0;

		p3_hantei = hp(p3);

		break;
	case 1:
		p3[x2][y2] = Fp[x2][y2 - 1];
		p3[x2][y2 - 1] = 0;
		p4[x2][y2] = Fp[x2][y2 + 1];
		p4[x2][y2 + 1] = 0;

		p3_hantei = hp(p3);
		p4_hantei = hp(p4);

		break;
	case 2:
		p3[x2][y2] = Fp[x2][y2 - 1];
		p3[x2][y2 - 1] = 0;

		p3_hantei = hp(p3);

		break;
	}

	/*/for (x = 0; x < N; x++) {
		for (y = 0; y < N; y++) {
			Openlist[i][x][y] = p1[x][y];
		}
	}/*/
	
		printf("マンハッタン距離：%d,%d,%d,%d\n", p1_hantei, p2_hantei, p3_hantei, p4_hantei);
}