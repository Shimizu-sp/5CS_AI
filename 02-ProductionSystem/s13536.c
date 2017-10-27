#include<stdio.h>

main(void){

	int count = 0;
	int count_view = 0;
	int count_srch = 0;
	int count_sort = 0;
	int rule3_flag1 = 0, rule3_flag2 = 0;
	int tmp = 0;

	char str[12] = "a*b-cd/e+fg";
	char true_str[12] = "gfedcba+-*/";
	char true_symbol[5] = "+-*/";
	for(count = 0;count < 11;count++){
		printf("%c ",str[count]);
	}
	printf(" 初期配置\n");

	while(1){
		for(count = 0;count < 10;count++){
	if(str[count]<90 && str[count+1]>90){
		tmp = str[count];
		str[count] = str[count+1];
		str[count+1] = tmp;
		for(count_view = 0;count_view < 11;count_view++){
			printf("%c ",str[count_view]);
		}
		count_sort++;
		printf(" 入れ替え%d回\n",count_sort);

	}
	if(str[count]>90 && str[count+1]>90 && str[count]<str[count+1]){
		tmp = str[count];
		str[count] = str[count+1];
		str[count+1] = tmp;
		for(count_view = 0;count_view < 11;count_view++){
			printf("%c ",str[count_view]);
		}
		count_sort++;
		printf(" 入れ替え%d回\n",count_sort);
	}
	if(str[count]<90 && str[count]<90){

	for(count_srch = count; count_srch < 11; count_srch++){
		if(str[count] == true_str[count_srch]){
			rule3_flag1++;
		}
	}
	for(count_srch = count; count_srch > 0; count_srch--){
		if(str[count+1] == true_str[count_srch]){
			rule3_flag2++;
		}
	}

	if(rule3_flag1 == 1 || rule3_flag2 == 1){
		tmp = str[count];
		str[count] = str[count+1];
		str[count+1] = tmp;
		for(count_view = 0;count_view < 11;count_view++){
			printf("%c ",str[count_view]);
		}
		count_sort++;
		printf(" 入れ替え%d回\n",count_sort);
	}
	}
	rule3_flag1 = 0;
	rule3_flag2 = 0;
		}
		if(str[0] == true_str[0] &&
		   str[1] == true_str[1] &&
		   str[2] == true_str[2] &&
		   str[3] == true_str[3] &&
		   str[4] == true_str[4] &&
		   str[5] == true_str[5] &&
		   str[6] == true_str[6] &&
		   str[7] == true_str[7] &&
		   str[8] == true_str[8] &&
		   str[9] == true_str[9] &&
		   str[10]== true_str[10]&&
		   str[11]== true_str[11]){

			   printf("\n終了\n",count_sort);
			    printf("何かキーを押して下さい..\n",count_sort);
			   getchar();
			   break;
		}
	}
}