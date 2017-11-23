#pragma warning(disable:4996)
#include<stdio.h>
#include <string.h>
#include <stdbool.h>
main() {
	int i = 0;
	int j = 0;
	int k = 0;
	int p = 0;
	int u = 0;
	int o = 0;
	int y = 0;
	int	h = 0;
	int w = 0;
	char m[40];
	scanf("%s", m);
	while (m[i])
		printf("%d ", m[i++]);

	printf("\n");

	for (u = 0; u < 107; u++) {
		o = 0;
		y = 0;
		w = 0;
		h = 0;
		for (i = 0; i < 40; i++) {
			if (m[i] == 37) {
				if (m[i - 1] > 50 && m[i-2]< 50) {
					y = 14;
					w = 1;
				}if (m[i - 1] > 50 && m[i - 2] > 50&&m[i-3]<50) {
					y = 13;
					w = 1;
				}if (m[i - 1] > 50 && m[i - 2] > 50 && m[i - 3]>50&&m[i-4]<50) {
					y = 12;
					w = 1;
				}if (m[i - 1] > 50 && m[i - 2] > 50 && m[i - 3]>50 && m[i - 4]>50&&m[i-5]<50) {
					y = 11;
					w = 1;
				}if (m[i - 1] > 50 && m[i - 2] > 50 && m[i - 3]>50 && m[i - 4]>50 && m[i - 5]>50&&m[i-6]<50) {
					y = 10;
					w = 1;
				}if (m[i-1]<50&&m[i-2]<50&&m[i-3]<50&&m[i-4]<50) {
					y = 9;
					w = 1;
				}if (w != 1) {
					y = 8;
				}
			}
			if (m[i] == 35) {
				if (m[i - 1] == 34&&i!=1) {
					y = 7;
				}
				if (m[i + 1] == 36) {
					y = 6;
				}if (m[i + 1] > 40) {
					y = 5;
				}
			}
			if (m[i] == 34) {
				if (m[i + 1] < 50 && m[i + 2]>50 && m[i + 3] > 50 && m[i + 4] < 50) {
					y = 4;
					w = 1;
				}
				if (m[i + 1] > 40 && w != 1) {
					y = 3;
				}
			}if (m[i] == 36) {
				if (m[i + 1] == 36) {
					y = 2;
				}
				if (m[i + 1] >= 40 && m[i + 2] >= 40) {
					y = 1;
				}
			}
			if (h < y) {
				h = y;
			}
		}
		for (i = 0; i < 40; i++) {
			if (m[i] == 37) {
				if (m[i - 1] > 50 && 40 < m[i - 2] && m[i - 2] < 50 && y == 14) {
					printf("R1適応");
					m[i] = m[i - 2];
					m[i - 2] = m[i - 1];
					m[i - 1] = 37;
					i = 40;
				}if (m[i - 1] > 50 && m[i - 2] > 50 && m[i - 3] < 50&&y==13) {
					printf("R2適応");
					m[i] = m[i - 3];
					m[i - 3] = m[i - 2];
					m[i - 2] = m[i-1];
					m[i - 1] = 37;
						i = 40;
					}if (m[i - 1] > 50 && m[i - 2] > 50 && m[i - 3]>50 && m[i - 4]<50&&y==12) {
						printf("R3適応");
						m[i] = m[i - 4];
						m[i - 4] = m[i - 3];
						m[i - 3] = m[i - 2];
						m[i - 2] = m[i - 1];
						m[i - 1] = 37;
						i = 40;
					}if (m[i - 1] > 50 && m[i - 2] > 50 && m[i - 3]>50 && m[i - 4]>50 && m[i - 5]<50&&y==11) {
						printf("R4適応");
						m[i] = m[i - 5];
						m[i - 5] = m[i - 4];
						m[i - 4] = m[i - 3];
						m[i - 3] = m[i - 2];
						m[i - 2] = m[i - 1];
						m[i - 1] = 37;
						i = 40;
					}if (m[i - 1] > 50 && m[i - 2] > 50 && m[i - 3]>50 && m[i - 4]>50 && m[i - 5]>50 && m[i - 6]<50&&y==10) {
						printf("R5適応");
						m[i] = m[i - 6];
						m[i - 6] = m[i - 5];
						m[i - 5] = m[i - 4];
						m[i - 4] = m[i - 3];
						m[i - 3] = m[i - 2];
						m[i - 2] = m[i - 1];
						m[i - 1] = 37;
						i = 40;
					}if (m[i - 1]<50 && m[i - 2]<50 && m[i - 3]<50 && m[i - 4]<50&&y==9) {
						printf("R6適応");
						k = m[i - 1];
						m[i - 1] = m[i - 2];
						m[i - 2] = k;
						m[i] = 0;
						while (m[o])
							printf("%c ", m[o++]);

						printf("\n");

						break;
					}if (y==8) {
						printf("R7適応");
						m[i] = m[i + 1];
						m[i + 1] = 37;
						i = 40;
					}
			}
			if (m[i] == 35) {
				if (m[i -1] == 34 && y == 7) {
					printf("R8適応");
					m[i-1] = 37;
					m[i] = 0;
					i = 40;

				}
				if (m[i + 1] == 36 && y == 6) {
					printf("R9適応");
					for (j = i; j < 30; j++) {

						m[j + 1] = m[j + 2];
					}
					m[i] = 35;
					i = 40;
				}if (m[i + 1] > 40 && y == 5) {
					printf("R10適応");
					m[i] = m[i + 1];
					m[i + 1] = 35;
					i = 40;
				}
			}if (m[i] == 34) {
				if (m[i + 1] < 50 && m[i + 2]>50 && m[i + 3] > 50 && m[i + 4] < 50 && y == 4) {
					printf("R11適応");
					k = m[i + 1];
					m[i] = m[i + 4];
					m[i + 1] = m[i + 2];
					m[i + 2] = m[i + 3];
					m[i + 3] = k;
					m[i + 4] = 34;
					i = 40;
				}
				if (m[i + 1] > 40 && y == 3) {
					printf("R12適応");
					m[i] = m[i + 1];
					m[i + 1] = 34;
					i = 40;
				}
			}if (m[i] == 36) {
				if (m[i + 1] == 36 && y == 2) {
					printf("R13適応");
					m[i + 1] = 35;
					m[i] = 34;
					i = 40;
				}
				if (m[i + 1] >= 40 && m[i + 2] >= 40 && y == 1) {
					printf("R14適応");
					k = m[i + 1];
					p = m[i + 2];
					m[i + 1] = m[i];
					m[i + 2] = k;
					m[i] = p;
					i = 40;
				}
			}
		}
		if (y == 0) {
			printf("R15適応");
			for (j = 30; j >= 1; j--) {
				m[j] = m[j - 1];
			}
			m[0] = 36;
		}

		while (m[o])
			printf("%c ", m[o++]);

		printf("\n");
	}
}
