#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int process[3][3];
//void disp();
int start[3][3] = {
	{ 8, 1, 5 },
	{ 2, 0, 4 },
	{ 6, 3, 7 }
};
int goal[3][3] = {
	{ 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 0 }
};

main() {
	int x = 0;
	int y = 0;
	int n = 0;
	int k = 0;
	int j = 0;
	int m[8] = { 0 };
	for (x = 0; x <= 2; x++) {
		for (y = 0; y <= 2; y++) {
			n = start[x][y];
			switch (n) {
			case 1:
				m[0] = abs(0 - x) + abs(0 - y);
				break;
			case 2:
				m[1] = abs(0 - x) + abs(1 - y);
				break;
			case 3:
				m[2] = abs(0 - x) + abs(2 - y);
				break;
			case 4:
				m[3] = abs(1 - x) + abs(0 - y);
				break;
			case 5:
				m[4] = abs(1 - x) + abs(1 - y);
				break;
			case 6:
				m[5] = abs(1 - x) + abs(2 - y);
				break;
			case 7:
				m[6] = abs(2 - x) + abs(0 - y);
				break;
			case 8:
				m[7] = abs(2 - x) + abs(1 - y);
				break;
			}
		}
	}
	for (k = 0; k < 8; k++) {
		j += m[k];
	}
	printf("j=%d \n", j);
	//getchar();
}

/*void disp() {
for (int y = 0; y < 3; y++) {
for (int x = 0; x < 3; x++) {
printf("[%d] ", process[y][x]);
}
printf("\n");
}
}*/