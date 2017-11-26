#include<stdio.h>
#include <string.h>

int main(void)
{
	char concept[3][100] = {{"生物"},{"鳥"},{"オーム"}};
	char    prop[3][100] = {{"呼吸"},{"翼"},{"モノマネ"}};

	int loop, a = 0, b = 0;

	printf("オームの特技は何ですか\n\n");
	for(loop = 0; loop<3; loop++)
	{
		if(!strcmp(concept[loop],"オーム"))
		{
			printf("%sの特技は%sです\n\n",concept[loop],prop[loop]);
		}
	}

	printf("オームは呼吸しますか\n\n");
	for(loop = 0; loop<3; loop++)
	{
		//呼吸が存在するときaを１に
		if(!strcmp(prop[loop],"呼吸"))
		{
			a++;
		}

		//継承先にオームが存在するときbを１に
		if(!strcmp(concept[loop],"オーム"))
		{
			b++;
		}

		printf("%s	-----	%s\n"
			  ,concept[loop],prop[loop]);

		if(a == 1 && b == 1)
		{
			printf("\nYES\n\n");
		}else{
			printf("|\n");
		}
	}
}