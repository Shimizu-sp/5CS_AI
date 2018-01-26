#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
	int gene_10[10] = { 1, 1, 1, 1, 1, 1, 0, 1, 1, 0 };
	int gene_9[10] = { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 };
	int gene_8[10] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 };
	int gene_7[10] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 1 };
	int gene_6[10] = { 1, 1, 1, 1, 1, 1, 1, 0, 1, 0 };
	int gene_5[10] = { 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 };
	int gene_4[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 };
	int gene_3[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 };
	int gene_2[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };
	int gene_1[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int gene0[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int gene1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	int gene2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 };
	int gene3[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };
	int gene4[10] = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
	int gene5[10] = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 };
	int gene6[10] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 };
	int gene7[10] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 };
	int gene8[10] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 };
	int gene9[10] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 };
	int gene10[10] = { 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 };
	int gene11[10] = { 0, 0, 0, 0, 0, 0, 1, 0, 1, 1 };
	int gene12[10] = { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 };
	int gene13[10] = { 0, 0, 0, 0, 0, 0, 1, 1, 0, 1 };
	int gene14[10] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 };
	int gene15[10] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 };

	int aaa;
	int i,j;

	printf("初期個体の生成\n");
	
	for (j = 0; j < 20; j++){
		srand((unsigned)time(NULL));
		aaa = rand() % 26 + 1;

		if (aaa == 1){
			for (i = 0; i < 10; i++){
				printf("%d", gene_10[i]);
			}
		}
		else if (aaa == 2){
			for (i = 0; i < 10; i++){
				printf("%d", gene_9[i]);
			}
		}
		else if (aaa == 3){
			for (i = 0; i < 10; i++){
				printf("%d", gene_8[i]);
			}
		}
		else if (aaa == 4){
			for (i = 0; i < 10; i++){
				printf("%d", gene_7[i]);
			}
		}
		else if (aaa == 5){
			for (i = 0; i < 10; i++){
				printf("%d", gene_6[i]);
			}
		}
		else if (aaa == 6){
			for (i = 0; i < 10; i++){
				printf("%d", gene_5[i]);
			}
		}
		else if (aaa == 7){
			for (i = 0; i < 10; i++){
				printf("%d", gene_4[i]);
			}
		}
		else if (aaa == 8){
			for (i = 0; i < 10; i++){
				printf("%d", gene_3[i]);
			}
		}
		else if (aaa == 9){
			for (i = 0; i < 10; i++){
				printf("%d", gene_2[i]);
			}
		}
		else if (aaa == 10){
			for (i = 0; i < 10; i++){
				printf("%d", gene_1[i]);
			}
		}
		else if (aaa == 11){
			for (i = 0; i < 10; i++){
				printf("%d", gene0[i]);
			}
		}
		else if (aaa == 12){
			for (i = 0; i < 10; i++){
				printf("%d", gene1[i]);
			}
		}
		else if (aaa == 13){
			for (i = 0; i < 10; i++){
				printf("%d", gene2[i]);
			}
		}
		else if (aaa == 14){
			for (i = 0; i < 10; i++){
				printf("%d", gene3[i]);
			}
		}
		else if (aaa == 15){
			for (i = 0; i < 10; i++){
				printf("%d", gene4[i]);
			}
		}
		else if (aaa == 16){
			for (i = 0; i < 10; i++){
				printf("%d", gene5[i]);
			}
		}
		else if (aaa == 17){
			for (i = 0; i < 10; i++){
				printf("%d", gene6[i]);
			}
		}
		else if (aaa == 18){
			for (i = 0; i < 10; i++){
				printf("%d", gene7[i]);
			}
		}
		else if (aaa == 19){
			for (i = 0; i < 10; i++){
				printf("%d", gene8[i]);
			}
		}
		else if (aaa == 20){
			for (i = 0; i < 10; i++){
				printf("%d", gene9[i]);
			}
		}
		else if (aaa == 21){
			for (i = 0; i < 10; i++){
				printf("%d", gene10[i]);
			}
		}
		else if (aaa == 22){
			for (i = 0; i < 10; i++){
				printf("%d", gene11[i]);
			}
		}
		else if (aaa == 23){
			for (i = 0; i < 10; i++){
				printf("%d", gene12[i]);
			}
		}
		else if (aaa == 24){
			for (i = 0; i < 10; i++){
				printf("%d", gene13[i]);
			}
		}
		else if (aaa == 25){
			for (i = 0; i < 10; i++){
				printf("%d", gene14[i]);
			}
		}
		else if (aaa == 26){
			for (i = 0; i < 10; i++){
				printf("%d", gene15[i]);
			}
		}getchar();
	}
}