#include<stdio.h>
#include <string.h>

int main(void)
{
	char concept[3][100] = {{"����"},{"��"},{"�I�[��"}};
	char    prop[3][100] = {{"�ċz"},{"��"},{"���m�}�l"}};

	int loop, a = 0, b = 0;

	printf("�I�[���̓��Z�͉��ł���\n\n");
	for(loop = 0; loop<3; loop++)
	{
		if(!strcmp(concept[loop],"�I�[��"))
		{
			printf("%s�̓��Z��%s�ł�\n\n",concept[loop],prop[loop]);
		}
	}

	printf("�I�[���͌ċz���܂���\n\n");
	for(loop = 0; loop<3; loop++)
	{
		//�ċz�����݂���Ƃ�a���P��
		if(!strcmp(prop[loop],"�ċz"))
		{
			a++;
		}

		//�p����ɃI�[�������݂���Ƃ�b���P��
		if(!strcmp(concept[loop],"�I�[��"))
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