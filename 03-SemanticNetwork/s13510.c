#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>

class SEIBUTU{//�����Ɋւ���T�O
public:
	int zokusei(int num1){
		
		int number = 1;//�T�O���Ƃɔԍ���ݒ肵�Ă���
		if (number == num1){
			printf("YES%d \n",num1);//�����͌ċz����
		}
		else{
			return 1;//�����Ȃ��ꍇ��1��Ԃ�
		}
	};
};

class TORI : public SEIBUTU{//�����̊T�O�������p���ł��钹�Ɋւ���T�O
public:
	int Zokusei(int num2){//�����̑����Ɋւ���֐�
		int torinum = 0;
		int number = 2;

		if (torinum == num2){
			printf("�H������\n");//���ɂ͉H�������
		}
		if (number == num2){
			printf("YES\n");
		}
		else{
			return 2;//�����Ȃ��ꍇ��2��Ԃ�
		}

	}
};

class OUMU : public TORI{//���̊T�O�������p���ł���I�[���Ɋւ���T�O
public:
	int tokugi(int num3){//�I�E���̓��Z�Ɋւ���֐�
		int oumunum = 0;
		int number = 3;
		if (oumunum == num3){
			printf("���m�}�l \n");//�I�E���̓��Z�̓��m�}�l
		}
		
		if (number == num3){
			printf("YES\n");
		}
		else{
			return 3; //�����Ȃ��ꍇ��3��Ԃ�
		}
	}
};


int main(){
	char query[30];
	int sp;
	int i;
	char *h, *j, *k, *l = 0;
	SEIBUTU seibutu;//�p���֌W���Ăяo���Ă���
	TORI tori;
	OUMU oumu;
	//��������
	printf("���������\n");
	scanf("%s", query);

	//����̓����ɃI�[���������Ă��邩���ׂ�
	j = strstr(query, "�I�[��");
	
	//�����Ă���ꍇ�ȉ��̏������s��
	if (j != NULL){
		k = strstr(query, "���Z");//������ɓ��Z�������Ă��邩��������
		l = strstr(query, "�ċz");//������Ɍċz�������Ă��邩��������

		if (k != NULL){//���Z�������Ă���ꍇ�A�I�E���̓��Z�Ɋւ���Ӗ��l�b�g���[�N���Q�Ƃ���
			oumu.tokugi(0);
		}

		if (l != NULL){//�ċz�������Ă���ꍇ�A
			sp = 1;
			i=oumu.tokugi(sp);//�I�[���̈Ӗ��l�b�g���[�N������������
			if (i == 3){//�����Ȃ��ꍇ�A��ʊT�O(��)����������
				i = 0;
				printf("�I�E���̒��ɂ͉�������܂��� %d\n", i);
				i = tori.Zokusei(sp);

				if (i == 2){//���̒��ɉ����Ȃ��ꍇ�A��ʊT�O�i�����j����������
					i = 0;
					printf("���̒��ɂ͉�������܂��� %d\n", sp);
					i = seibutu.zokusei(sp);
					
					if (i == 1){//�Ȃ������ꍇ�͉��Ȃ��ƂȂ�
						printf("���Ȃ�\n");
					}
				}
			}
		}
	}
}



