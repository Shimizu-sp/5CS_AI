#include<stdio.h>
#include <stdlib.h>

main(){
	int i,j;
	int binary = 0;
	int base = 1;
	int kn[20];
	int ga[27] = {0,-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int ga_U10[10] = { 1, 1, 1, 1, 1, 1, 0, 1, 1, 0 };
	int ga_U09[10] = { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 };
	int ga_U08[10] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 };
	int ga_U07[10] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 1 };
	int ga_U06[10] = { 1, 1, 1, 1, 1, 1, 1, 0, 1, 0 };
	int ga_U05[10] = { 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 };
	int ga_U04[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 };
	int ga_U03[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 };
	int ga_U02[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };
	int ga_U01[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int ga_00[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int ga_01[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	int ga_02[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 };
	int ga_03[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };
	int ga_04[10] = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
	int ga_05[10] = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 };
	int ga_06[10] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 };
	int ga_07[10] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 };
	int ga_08[10] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 };
	int ga_09[10] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 };
	int ga_10[10] = { 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 };
	int ga_11[10] = { 0, 0, 0, 0, 0, 0, 1, 0, 1, 1 };
	int ga_12[10] = { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 };
	int ga_13[10] = { 0, 0, 0, 0, 0, 0, 1, 1, 0, 1 };
	int ga_14[10] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 };
	int ga_15[10] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 };
	int tn[20];

	srand((unsigned)time(NULL));

	for (i = 0; i < 20; i++){
	int x = rand() % 27;


			printf("%d,", ga[x]);

			tn[i] = ga[x];

		}
	printf("\n");

	for (i = 0; i < 20; i++){
		 kn[i] = (rand() % 10000)/10000.00;


		printf("%f,", kn[i]);


	}
	printf("\n");


	for (i = 0; i < 20; i++){
		if (tn[i] == -10){
			for (j = 0; j < 10; j++){
				printf("%d", ga_U10[j]);
			}
			printf(",");
		}
		else if (tn[i] == -9){
			for (j = 0; j < 10; j++){
				printf("%d", ga_U09[j]);
			}
			printf(",");
		}
		else if (tn[i] == -8){
			for (j = 0; j < 10; j++){
				printf("%d", ga_U08[j]);
			}
			printf(",");
		}
		else if (tn[i] == -7){
			for (j = 0; j < 10; j++){
				printf("%d", ga_U07[j]);
			}
			printf(",");
		}
		else if (tn[i] == -6){
			for (j = 0; j < 10; j++){
				printf("%d", ga_U06[j]);
			}
			printf(",");
		}
		else if (tn[i] == -5){
			for (j = 0; j < 10; j++){
				printf("%d", ga_U05[j]);
			}
			printf(",");
		}
		else if (tn[i] == -4){
			for (j = 0; j < 10; j++){
				printf("%d", ga_U04[j]);
			}
			printf(",");
		}
		else if (tn[i] == -3){
			for (j = 0; j < 10; j++){
				printf("%d", ga_U03[j]);
			}
			printf(",");
		}
		else if (tn[i] == -2){
			for (j = 0; j < 10; j++){
				printf("%d", ga_U02[j]);
			}
			printf(",");
		}
		else if (tn[i] == -1){
			for (j = 0; j < 10; j++){
				printf("%d", ga_U01[j]);
			}
			printf(",");
		}
		else if (tn[i] == 0){
			for (j = 0; j < 10; j++){
				printf("%d", ga_00[j]);
			}
			printf(",");
		}
		else if (tn[i] == 1){
			for (j = 0; j < 10; j++){
				printf("%d", ga_01[j]);
			}
			printf(",");
		}
		else if (tn[i] == 2){
			for (j = 0; j < 10; j++){
				printf("%d", ga_02[j]);
			}
			printf(",");
		}
		else if (tn[i] == 3){
			for (j = 0; j < 10; j++){
				printf("%d", ga_03[j]);
			}
			printf(",");
		}
		else if (tn[i] == 4){
			for (j = 0; j < 10; j++){
				printf("%d", ga_04[j]);
			}
			printf(",");
		}
		else if (tn[i] == 5){
			for (j = 0; j < 10; j++){
				printf("%d", ga_05[j]);
			}
			printf(",");
		}
		else if (tn[i] == 6){
			for (j = 0; j < 10; j++){
				printf("%d", ga_06[j]);
			}
			printf(",");
		}
		else if (tn[i] == 7){
			for (j = 0; j < 10; j++){
				printf("%d", ga_07[j]);
			}
			printf(",");
		}
		else if (tn[i] == 8){
			for (j = 0; j < 10; j++){
				printf("%d", ga_08[j]);
			}
			printf(",");
		}
		else if (tn[i] == 9){
			for (j = 0; j < 10; j++){
				printf("%d", ga_09[j]);
			}
			printf(",");
		}
		else if (tn[i] == 10){
			for (j = 0; j < 10; j++){
				printf("%d", ga_10[j]);
			}
			printf(",");
		}
		else if (tn[i] == 11){
			for (j = 0; j < 10; j++){
				printf("%d", ga_11[j]);
			}
			printf(",");
		}
		else if (tn[i] == 12){
			for (j = 0; j < 10; j++){
				printf("%d", ga_12[j]);
			}
			printf(",");
		}
		else if (tn[i] == 13){
			for (j = 0; j < 10; j++){
				printf("%d", ga_13[j]);
			}
			printf(",");
		}
		else if (tn[i] == 14){
			for (j = 0; j < 10; j++){
				printf("%d", ga_14[j]);
			}
			printf(",");
		}
		else if (tn[i] == 15){
			for (j = 0; j < 10; j++){
				printf("%d", ga_15[j]);
			}
			printf(",");
		}
		printf("\n");
	}
	
		}
	
	


