#include<stdio.h>
typedef struct{
	int num;//�l���������قǏ�ʊT�O
	char Name[20];//�T�O�̖��O
	int num_x;//num=1�c�����@num=2�c���Z
	char X[20];

}SNetwork;
main(){

	int i, k = 0;
	SNetwork n[3] = { { 1, "����", 1, "�ċz����" }, { 2, "��", 1, "��������" }, { 3, "�I�[��", 2, "���m�}�l" } };

	//�I�[���̓��Z�𕷂�����
	printf("Q1.�I�[���̓��Z�͉��ł����H\n");
	for (i = 0; i < 3; i++){
		if (!strcmp(n[i].Name, "�I�[��") && n[i].num_x == 2){//�I�[���ɓ��Z���L�^����Ă���Γ�����
			printf("%d�Ԃ̊T�O��%s�̂��ߓ��Z�𒲂ׂ܂��c\n", n[i].num, n[i].Name);
			printf("A1.%s�̓��Z��%s�ł��B\n\n", n[i].Name, n[i].X);
		}
		else{
			printf("%d�Ԃ̊T�O��%s���������߉��ʊT�O�𒲂ׂ܂��c\n", n[i].num, n[i].Name);
			k++;//������Ȃ�������
		}
	}
	if (k == 3){//�����I�[�����Ӗ��l�b�g���[�N�ɑ��݂��Ȃ����
		printf("Error:�Ӗ��l�b�g���[�N��[�I�[��]�Ƃ����T�O�����݂��܂���\n");
	}

	k = 0;
	//�I�[���͌ċz���邩���₷�镔��
	printf("Q2.�I�[���͌ċz���܂����H\n");
	for (i = 2; i > -1; i--){
		if (!strcmp(n[i].X, "�ċz����")){//��ʊT�O�Ɍċz���鑮���������Yes
			printf("%d�Ԃ�%s�Ɍċz�ɂ��ċL�^������܂����c\n", n[i].num, n[i].Name);
			printf("A2.Yes.\n\n");
		}
		else{
			printf("%d�Ԃ�%s�ɂ͌ċz�ɂ��ċL�^���Ȃ��������ߏ�ʊT�O�𒲂ׂ܂��c\n", n[i].num, n[i].Name);
			k++;//������Ȃ�������
		}
	}
	if (k == 3){//�����ċz�Ɋւ���L�^���Ӗ��l�b�g���[�N�ɑ��݂��Ȃ����
		printf("Error:�Ӗ��l�b�g���[�N��[�ċz]�Ƃ������������݂��܂���\n");
	}

	printf("end\n");
}