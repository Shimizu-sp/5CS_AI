#include <stdio.h>
#include<string.h>

void main(){
	/*
	����-�ċz����
	|
	��-��������
	|
	�I�[��-���Z�̓��m�}�l
	*/

	//�e�v�f���i�[
	char element[6][10] = {
		 "����",
		 "�ċz����",
		 "��",
		 "��������",
		 "�I�[��",
		 "���m�}�l"
	};

	//�e�v�f�̗אڃ��X�g
	int connect[6][4]{
		{-1,2,1,-1},
		{0,-1,-1,-1},
		{0,4,3,-1},
		{2,-1,-1,-1},
		{2,-1,-1,5},
		{4,-1,-1,-1},
	};
	//{"��ʊT�O","���ʊT�O","����","���Z"}

	//�Ӗ��l�b�g���[�N���o��
	int i = 0;
	while (1){
		printf("%s", element[i]);
		if (connect[i][2] != -1){
			printf("�\(����)%s", element[connect[i][2]]);
		}
		if (connect[i][3] != -1){
			printf("�\(���Z)%s", element[connect[i][3]]);
		}
		if (connect[i][1] != -1){
			i = connect[i][1];
			printf("\n�b\n");
		}
		else break;
	}

	//����:�I�[���̓��Z�͂Ȃ�ł���
	printf("\n\n����:�I�[���̓��Z�͂Ȃ�ł���\n");
	int c = 4; //�I�[���̊i�[����Ă���ʒu
	int d = 3; //���Z�̊i�[����Ă���ʒu

	//���Z�����݂���ꍇ���̓��e���o�͂���
	if (connect[c][d] != -1)printf("��:%s\n", element[connect[c][d]]);
	else{
		while (1){
			if (connect[c][0] != -1)c = connect[c][0]; //��ʊT�O�����݂���ꍇ���̊T�O�Ɉړ�����

			//��ʊT�O�����݂��Ȃ��ꍇ=������Ȃ����� �����no��Ԃ�
			else {
				printf("��:�Ȃ�\n");
				break;
			}

			//���Z�����݂���ꍇ���̓��e���o�͂���
			if (connect[c][d] != -1){
				printf("��:%s\n", element[connect[c][d]]);
				break;
			}
		}
	}

	//����:�I�[���͌ċz���邩
	printf("\n����:�I�[���͌ċz���邩\n");
	c=4; //�I�[���̊i�[����Ă���ʒu
	char question[10] = "�ċz����"; //������e(���̕�����ƈ�v���邩���ׂ�)

	printf("%s", element[c]); 

	//���������݂��� ���� ������e�Ƒ����̓��e����v 
	//�̏ꍇyes��Ԃ�
	if (connect[c][2] != -1 && strcmp(element[connect[c][2]], question)==0){
		printf("�\%s��\n", element[connect[c][2]]);
		printf("��:yes\n");
	}
	else{
		
		while (1){
			//��ʊT�O�����݂���ꍇ���̊T�O�Ɉړ�����
			if (connect[c][0] != -1){
				c = connect[c][0];
				printf("\n|\n%s", element[c]);
			}

			//��ʊT�O�����݂��Ȃ��ꍇ=������Ȃ����� �����no��Ԃ�
			else {
				printf("\n��:no\n");
				break;
			}

			//���������݂��� ���� ������e�Ƒ����̓��e����v �̏ꍇyes��Ԃ�
			if (connect[c][2] != -1 && strcmp(element[connect[c][2]], question) == 0){
				printf("�\%s��\n", element[connect[c][2]]);
				printf("\n��:yes\n");
				break;
			}

		}
	}
}