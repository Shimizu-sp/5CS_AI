#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning(disable:4996)

FILE *img, *timg;
int i, j, x, y;
int pix, fp_int;
int sum = 0, ans = 5000000;
int ans_x, ans_y, a, b, c;
int img_1[512][512], timg_1[200][200];
int count0 = 0, count255 = 0;
char buf[1];

int main(void){

	//�Ώۉ摜�̓ǂݍ���
	img = fopen("img_data_1.txt","r");
		
	for(i = 0; i < 512; i++)
	{
		for (j = 0; j < 512; j++)
		{
			pix = fread(&buf,1,1,img);
			fp_int = strtol(buf,NULL,10);

			if(fp_int!=0)
			{
				 pix = fread(&buf,1,2,img);
				fp_int = 255;
			}

			img_1[i][j] = (int)fp_int;
		}
	}

	fclose(img);

	//�e���v���[�g�̓ǂݍ���
	timg = fopen("Timg_data_1.txt","r");

	for(i = 0; i < 200; i++)
	{
		for(j = 0; j < 200; j++)
		{
			pix = fread(&buf,1,1,timg);
			fp_int = strtol(buf,NULL,10);

			if(fp_int!=0)
			{
				pix = fread(&buf,1,2,timg);
				fp_int = 255;
			}

			timg_1[i][j] = (int)fp_int;
		}
	}

	fclose(timg);

	//�ގ��x�̔���
	for(x= 0; x < 312; x++)
	{
		for(y = 0; y < 312; y++)
		{
			for(i = 0; i < 200; i++)
			{
				for(j = 0; j < 200; j++)
				{

					sum += fabs(img_1[y+i][x+j] - timg_1[i][j]);
				}
			}
			if(ans >= sum)
			{
			ans = sum;
			ans_x = x;
			ans_y = y;
			}
			sum = 0;
		}
		//sum = 0;
	}
	printf("�e���v���[�g�ƃ}�b�`���O��������̍��W��[%d %d]\n",ans_x,ans_y);
}