#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

main(){

	char array_name_1[100]; //�z�񖼕ۑ��p
	char array_name_2[100];
	char array_name_3[100];
	char array_name_4[100];
	char array_name_5[100];

	//is-a�֌W
	char is_a_1[50] = "����";
	char is_a_2[50] = "��"; //�����̊T�O
	char is_a_3[50] = "�I�[��"; //���̊T�O�@

	//����
	char attribute_1[50] = "�ċz" ; //�����̑���
	char attribute_2[50] = "��������"; //���̑���
	char attribute_3[50] = "���m�}�l"; //�I�[���̑���
	char attribute_name3[50] = "���Z"; //�I�[���̑���(�ڍ�)

	//����p�z��
	char question_1[30] = "���ł���";
	char question_2[30] = "��";

	int flag1,flag2,flag3;
	int trueth = 0;
	int input = 0,mugen = 0;

	while(mugen == 0){

	flag1 = 0; flag2 = 0; flag3 = 0; trueth = 0;

	printf("\n���j���[(��������͂��Ă�������)\n1:�������\n2:�I��\n\n");

	scanf("%d",&input);
    
	if(input == 1){

	printf("\n ����̒P��Ԃɔ��p�X�y�[�X�����Ă�������\n");
	printf(" ���|�[�g���̎��╶���R�s�y���Ē�����Γ����܂�\n\n");
	printf("===========================================================\n");
	printf("Q:");

	scanf("%s", array_name_1);
	scanf("%s", array_name_2);
	scanf("%s", array_name_3);
	scanf("%s", array_name_4);
	scanf("%s", array_name_5);

	//���┻��===============================================================

	//is-a�֌W����s
	if(strcmp(array_name_1,is_a_1) == 0){ //���͂��ꂽis-a���u�����v�ł��邩�H
		flag1++;
		printf("\n�����@��");

	}else if(strcmp(array_name_1,is_a_2) == 0){ //���͂��ꂽis-a���u���v�ł��邩�H
		flag2++;
		printf("\n���@��");
	
	}else if(strcmp(array_name_1,is_a_3) == 0){ //���͂��ꂽis-a���u�I�[���v�ł��邩�H
		flag3++;
		printf("\n�I�[���@��");
	}

	//��������

	//�I�[��=======
	if(flag3 == 1){
		if(strcmp(array_name_3,attribute_name3) == 0){
			
			printf(" (���Z)���m�}�l");

			//����ꔻ��
	        if(strcmp(array_name_5,question_1) == 0){
			  printf("\nA:%s\n",attribute_3);
	        }else if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		}
	    }else if(strcmp(array_name_3,attribute_2) == 0){
			
           printf(" �� ���@��������");

		   //����ꔻ��
	       if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		}
		}else if(strcmp(array_name_3,attribute_1) == 0){

			printf(" �� ���@�����@���@�ċz����");

		   //����ꔻ��
	       if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		}
	}}

	//��=========
	if(flag2 == 1){
		if(strcmp(array_name_3,attribute_2) == 0){

			printf(" ��������");

		   //����ꔻ��
	       if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		}
		}else if(strcmp(array_name_3,attribute_1) == 0){
			
			printf(" �����@���@�ċz����");

		   //����ꔻ��
		   if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		   }
	}}

	//����=========
    if(flag1 == 1){
		if(strcmp(array_name_3,attribute_1) == 0){
			
		   printf(" �ċz����");

		   //����ꔻ��
		   if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		   }
    }}

	}else if(input==2){

		break;

	}
	
	input = 0;

	}

}