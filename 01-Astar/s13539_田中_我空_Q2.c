
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//�ϐ��錾
int mondai[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } };//[y���W][x���W]
int kansei[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };
int tmp[3][3];

int i = 0, j = 0;
int x = 0, y = 0;

int zero_x = 0, zero_y = 0;
int kyori_tmp[4];//�q�̃}���n�b�^������
int min_num = 0;
int min_manhattan;//�q�̒��̍ŏ��̃}���n�b�^������
int loop=0;//�q�̃p�Y���ړ���
int loop_mondai;//�e�̃p�Y���ړ���
int move;//�p�Y�����ǂ̕����ɓ�������

//�֐��錾
int manhattan(int[3][3]);
void zero_zahyo(int[3][3]);
void print_puzzle(int[3][3]);
void create_tmp();

//�X�^�b�N
void push(int, int[3][3], int);
int pop();

int stack_manhattan[1000];
int stack_loop[1000];
int stack_pazzle[1000][3][3];
int stack_num = 0;//�X�^�b�N����Ă��鐔
int stack_move[1000];
int stack_num_tmp;//�X�^�b�N�̒��g�\������Ƃ��p


void main()
{

	push(loop, mondai,-1);//������Ԃ�push

	create_tmp(mondai);
	while (manhattan(tmp) > 0 && stack_num > 0)//�������邩�X�^�b�N����ɂȂ�܂�
	{
		loop_mondai = pop();
		print_puzzle(mondai);

		if (loop_mondai < 30)
		{

			loop = loop_mondai;
			//print_puzzle(mondai);
			loop++;
			


			kyori_tmp[1] = 99999999;
			kyori_tmp[3] = 99999999;
			create_tmp(mondai);//tmp��mondai���R�s�[
			zero_zahyo(mondai);//�O�̍��Wget

			switch (zero_x)		//tmp���g���ăp�Y���̈ړ��Ƌ����̌v�Z
			{
			case 0:
				tmp[zero_y][zero_x] = tmp[zero_y][zero_x + 1];//�p�Y���ړ�
				tmp[zero_y][zero_x + 1] = 0;

				kyori_tmp[0] = manhattan(tmp);//��r���邽�߂ɋ�����ۑ�


				break;
			case 1:
				tmp[zero_y][zero_x] = tmp[zero_y][zero_x - 1];
				tmp[zero_y][zero_x - 1] = 0;

				kyori_tmp[0] = manhattan(tmp);


				create_tmp(mondai);//tmp�����Z�b�g


				tmp[zero_y][zero_x] = tmp[zero_y][zero_x + 1];
				tmp[zero_y][zero_x + 1] = 0;

				kyori_tmp[1] = manhattan(tmp);


				break;
			case 2:
				tmp[zero_y][zero_x] = tmp[zero_y][zero_x - 1];
				tmp[zero_y][zero_x - 1] = 0;

				kyori_tmp[0] = manhattan(tmp);

				break;
			}


			create_tmp(mondai);//tmp�����Z�b�g



			switch (zero_y)//y�ł��������Ƃ�
			{
			case 0:
				tmp[zero_y][zero_x] = tmp[zero_y + 1][zero_x];
				tmp[zero_y + 1][zero_x] = 0;

				kyori_tmp[2] = manhattan(tmp);

				break;
			case 1:
				tmp[zero_y][zero_x] = tmp[zero_y - 1][zero_x];
				tmp[zero_y - 1][zero_x] = 0;

				kyori_tmp[2] = manhattan(tmp);


				create_tmp(mondai);//tmp�����ɖ߂�



				tmp[zero_y][zero_x] = tmp[zero_y + 1][zero_x];
				tmp[zero_y + 1][zero_x] = 0;

				kyori_tmp[3] = manhattan(tmp);


				break;
			case 2:
				tmp[zero_y][zero_x] = tmp[zero_y - 1][zero_x];
				tmp[zero_y - 1][zero_x] = 0;

				kyori_tmp[2] = manhattan(tmp);

				break;
			}





			min_manhattan = 100000000;
			for (i = 0; i < 4; i++)//�}���n�b�^�������̔�r
			{
				if (min_manhattan > kyori_tmp[i])
				{
					min_manhattan = kyori_tmp[i];

				}
			}

			


			//move�́A0�����ړ���1,��2,��3,��4

			create_tmp(mondai);
			zero_zahyo(mondai);//�O�̍��Wget

			switch (zero_x)//�ŏ��̃}���n�b�^�������̂��̂�push
			{
			case 0:

				tmp[zero_y][zero_x] = tmp[zero_y][zero_x + 1];//�p�Y���ړ�
				tmp[zero_y][zero_x + 1] = 0;

				//�q�̒��ōŏ��̃}���n�b�^�������̂Ƃ��̂�push�i�܂��Amove���g�����ƂőO��̔Ֆʂɖ߂铮���������Ȃ��j
				if (min_manhattan == manhattan(tmp) && move != 2)
				{
					push(loop, tmp,1);
				}
				break;

			case 1:
				tmp[zero_y][zero_x] = tmp[zero_y][zero_x - 1];
				tmp[zero_y][zero_x - 1] = 0;

				if (min_manhattan == manhattan(tmp) && move != 1)
				{
					push(loop, tmp,2);
				}

				create_tmp(mondai);//tmp�����Z�b�g


				tmp[zero_y][zero_x] = tmp[zero_y][zero_x + 1];
				tmp[zero_y][zero_x + 1] = 0;

				if (min_manhattan == manhattan(tmp) && move != 2)
				{
					push(loop, tmp,1);
				}


				break;
			case 2:
				tmp[zero_y][zero_x] = tmp[zero_y][zero_x - 1];
				tmp[zero_y][zero_x - 1] = 0;

				if (min_manhattan == manhattan(tmp) && move != 1)
				{
					push(loop, tmp,2);
				}

				break;
			}
			create_tmp(mondai);//tmp�����Z�b�g



			switch (zero_y)//y�ł��������Ƃ�
			{
			case 0:
				tmp[zero_y][zero_x] = tmp[zero_y + 1][zero_x];
				tmp[zero_y + 1][zero_x] = 0;

				if (min_manhattan == manhattan(tmp) && move != 4)
				{
					push(loop, tmp,3);
				}

				break;
			case 1:
				tmp[zero_y][zero_x] = tmp[zero_y - 1][zero_x];
				tmp[zero_y - 1][zero_x] = 0;

				if (min_manhattan == manhattan(tmp) && move != 3)
				{
					push(loop, tmp,4);
				}


				create_tmp(mondai);//tmp�����ɖ߂�



				tmp[zero_y][zero_x] = tmp[zero_y + 1][zero_x];
				tmp[zero_y + 1][zero_x] = 0;

				if (min_manhattan == manhattan(tmp) && move != 4)
				{
					push(loop, tmp,3);
				}


				break;
			case 2:
				tmp[zero_y][zero_x] = tmp[zero_y - 1][zero_x];
				tmp[zero_y - 1][zero_x] = 0;

				if (min_manhattan == manhattan(tmp) && move != 3)
				{
					push(loop, tmp,4);
				}

				break;
			}
		}
	}



	print_puzzle(tmp);
	
	//�X�^�b�N�̗v�f��S�ďo��(����X�^�b�N���S�ċ�̏�ԂŏI�����邽�߈Ӗ�����)
	for (stack_num_tmp = stack_num - 1; 0 <= stack_num_tmp; stack_num_tmp--)
	{
		printf("manhattan:%d\n", manhattan(stack_pazzle[stack_num_tmp]));
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%d ", stack_pazzle[stack_num_tmp][i][j]);

			}
			printf("\n");
		}
		printf("\n");
	}
}



int manhattan(int pazzle[3][3])
{
	int manhattan_souwa = 0;
	int x_kyori = 0, y_kyori = 0;


	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{


			for (i = 0; i < 3; i++)//tmp�Ɠ����l�̏ꏊ��T��
			{
				for (j = 0; j < 3; j++)
				{

					//0�ȊO�̎��ɓ����l���������狗�����}���n�b�^���̑��a�ɑ���
					if (pazzle[y][x] == kansei[i][j] && pazzle[y][x] != 0)
					{
						x_kyori = abs(x - j);
						y_kyori = abs(y - i);
						manhattan_souwa += x_kyori + y_kyori;

					}
				}
			}
		}
	}
	
	return manhattan_souwa;

}

void zero_zahyo(int pazzle[3][3])//��̍��W�����ł���
{
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (pazzle [i][j] == 0)//0�̍��W��ۑ�
			{
				zero_x = j;
				zero_y = i;
			}
		}
	}
}

void print_puzzle(int puzzle[3][3])//��ʏo�͂���
{
	zero_zahyo(puzzle);
	//printf("move:%d\n", move);
	printf("�}���n�b�^�������̑��a�F%d \n", manhattan(puzzle));
	printf("�ړ��R�X�g�F%d \n", loop);
	//printf("��̍��W[%d][%d] \n", zero_y, zero_x);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", puzzle[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//getchar();	
}

void create_tmp(int pazzle[3][3])//���삷��p�̔Ֆʂ��쐬����
{
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			tmp[i][j] = pazzle[i][j];
		}
	}
}

void push(int push_loop,int pazzle[3][3],int push_move)//�X�^�b�N��push
{

	stack_loop[stack_num] = push_loop;
	stack_move[stack_num] = push_move;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			stack_pazzle[stack_num][i][j] = pazzle[i][j];
		}
	}
	stack_num++;

}

int pop()//�X�^�b�N����pop
{

	stack_num--;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			mondai[i][j] = stack_pazzle[stack_num][i][j];
		}
	}
	move = stack_move[stack_num];
	return stack_loop[stack_num];
}