#include <stdio.h>
#include<string.h>

int min(int*);
int max(int*);

int main(void)
{
	int num[500];

	printf("xの値は：%dです。\n", min(num));
	printf("最大値は：%dです。\n", max(num));

	return 0;
}
		int min(int *all)
		{
		
				int min = all[2];
				for (int n = 1; n<9; ++n){
						if (all[0]>all[n]){
								min = all[n];
							
						}
				}
	
		}
	int max(int *all)
		
		{
				int max = all[2];
				for (int i = 1; i<9; ++i){
						if (all[0]<all[i]){
								max = all[i];
						}
				}


		}
