/*
**�쐬�v���O����:�Ӗ��l�b�g���[�N
**�쐬��:�K�����
**�����:Visual Studio 2012
**�g�����F�l�b�g���[�N�̃m�[�h�������1�̃m�[�h����Ȃ���q�m�[�h�̐��͖���
*/
//Visual Studio�p�ݒ藓
#pragma warning(disable:4996)

//�w�b�_�ǂݍ���
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�}�N����`

//�������i�[����ϐ��̃������m�ۂ��s���}�N���֐������̈Ӗ��́ux:�쐬���镶���������Network*�Ca:�����̐��Cb:�����ƃL�[���[�h�����܂�ŏ��̒l�v
#define STR(x,a,b) \
	for(i=0;i<2;i++){\
		if(NULL==((x)->forte[i]=(char**)malloc(sizeof(char*)*(a)))){\
			perror("malloc");\
			return -1;\
		}\
		for(j=0;j<a;j++){\
			if(NULL==((x)->forte[i][j]=(char*)malloc(sizeof(char)*(b)))){\
				perror("malloc");\
				return -1;\
			}\
		}\
	}\
	(x)->char_length[0]=(a);\
	(x)->char_length[1]=(b);



//�\���̒�`

//�Ӗ��l�b�g���[�N�̊e�m�[�h�������\����
typedef struct def_Network{
	char name[100];					//�m�[�h�̖��O���i�[����
	char** forte[2];				//[1]�ɓ������C[0]�ɓ������q�b�g����L�[���[�h���i�[����
	unsigned int char_length[2];	//forte�z��̑傫�����i�[����
	unsigned int serch_flag;
	struct def_Network** next;		//���w�̃l�b�g���[�N�ɂȂ���|�C���^
	unsigned int next_num;			//�����ɂȂ����Ă���m�[�h�̐����i�[����
	struct def_Network* back;		//�����̏�ʂ̃l�b�g���[�N�ɂȂ���|�C���^
} Network;

//�֐��v���g�^�C�v��`
int CreateNetwork(Network* net,size_t create_num);//�l�b�g���[�N���쐬����֐�
int FreeNetwork(Network* head);//���ׂẴl�b�g���[�N�̃��������J������֐�
Network* GoNext(Network* net);//���ɂǂ̃m�[�h��T������΂����̂��������֐�

int main(){
	Network* head;
	Network* p;
	char question[100];
	unsigned int i,j,n;
	int flag=0;
	char* str_head;

	//���[�g�̃m�[�h���쐬
	if(NULL==(head=(Network*)malloc(sizeof(Network)))){
		perror("malloc");
		return -1;
	}

	//���݂̌����ʒu��p�Ɋi�[
	p=head;

	//���O�ɗ^����ꂽ�l�b�g���[�N���`
	head->name[0]='\0';
	head->serch_flag=1;

	CreateNetwork(p,1);
	p=head->next[0];

	CreateNetwork(p,1);
	
	//�m�[�h���̐ݒ���s��
	p=head;

	STR(p,1,100);
	sprintf(p->name,"����");
	sprintf(p->forte[0][0],"�ċz");
	sprintf(p->forte[1][0],"YES");

	p->back=NULL;

	p=p->next[0];

	STR(p,1,100);
	sprintf(p->name,"��");
	sprintf(p->forte[0][0],"�H");
	sprintf(p->forte[1][0],"�H������");

	p=p->next[0];

	STR(p,1,100);
	sprintf(p->name,"�I�[��");
	sprintf(p->forte[0][0],"���Z");
	sprintf(p->forte[1][0],"���m�}�l");

	//����̎�t
	printf("�������͂��Ă������� > ");
	scanf("%99s",question);
	
	question[99]='\0';
	printf("���� : %s\n",question);

	while('\n'!=getchar());

	//p�̏�����
	p=head;

	//����Ώۂ̒T��
	while(1){
		if(!flag){
			//����Ώۂ̂��Ƃ������m�[�h�����邩������
			if(NULL!=(str_head=strstr(question,p->name))){

				//�����Ƀq�b�g�����͎̂�ꂩ���m�F
				if(question==str_head){
					//flag��ύX
					flag=1;
					continue;
				}

			}

			if(NULL==(p=GoNext(head))) break;
		}
		else if(flag==1){
			//�m�[�h���ɋ��߂Ă��铚�������݂��邩���m�F
			for(i=0;i<p->char_length[0];i++){

				 //�����ɑ��݂��邩���m�F
				if(NULL!=strstr(question,p->forte[0][i])){
					printf("�� : %s\n",p->forte[1][i]);
					flag=2;
					break;
				}//�m�[�h�̖��O�ɑ��݂��邩���m�F	
				else if(NULL!=(str_head=strstr(&question[1],p->name))){//&question[1]�Ƃ��Ă���̂́u�����́����H�v�Ƃ����₢�̂Ƃ��ɐ擪�́u�����v�Ɉ���������Ȃ��悤�ɂ��邽��
					printf("�� : YES\n");
					flag=2;
					break;

				}
				
			}

			if(flag==2) break;

			//is-a�֌W�Ōp���֌W��T���������O��\��
			printf("�o�� : %s is a ",p->name);
			
			if(p->back==NULL){
				printf("NULL\n");
				break;
			}
			p=p->back;

			printf("%s\n",p->name);
		}
		
	}

	//������������Ȃ��ꍇ
	if(flag==0 || flag==1) printf("�l�b�g���[�N��ɓ����͑��݂��܂���");

	//�������̉��
	FreeNetwork(head);

	getchar();

	return 0;

}

//�l�b�g���[�N�̃m�[�h���쐬����֐�
//���� net:�쐬�����m�[�h��A�������錳, create_num:�쐬����m�[�h�̐�
int CreateNetwork(Network* net,size_t create_num){
	Network** p;
	size_t i;

	//��O����
	if(create_num<=0){
		perror("create_num");
		return -1;
	}
	
	//�������m��
	if(NULL==(p=(Network**)malloc(sizeof(Network*)*create_num))){
		perror("CreateNetwork->malloc");
		return -2;
	}
	for(i=0;i<create_num;i++){
		if(NULL==(p[i]=(Network*)malloc(sizeof(Network)))){
			perror("CreateNetwork->malloc");
			return -2;
		}
	}

	//net�̒l�ɕK�v�ȏ�����
	net->next_num=(unsigned int)create_num;

	//�쐬�����l�b�g���[�N�̒l��������
	for(i=0;i<create_num;i++){
		net->next=p;

		p[i]->serch_flag=0;
		p[i]->forte[0]=NULL;
		p[i]->forte[1]=NULL;
		p[i]->name[0]='\0';
		p[i]->char_length[0]=0;
		p[i]->char_length[1]=0;
		p[i]->next=NULL;
		p[i]->next_num=0;
		p[i]->back=net;
	}
	

	return 0;
}

//���ׂẴl�b�g���[�N�̃��������J������֐�
//���� head:�l�b�g���[�N�̃m�[�h�������|�C���^
int FreeNetwork(Network* head){
	int i;

	//������̉��
	for(i=0;i<head->char_length[0];i++) free(head->forte[0][i]);
	for(i=0;i<head->char_length[0];i++) free(head->forte[1][i]);
	free(head->forte[0]);
	free(head->forte[1]);

	//������艺�̃m�[�h�����
	if(head->next!=NULL) for(i=0;i<head->next_num;i++) FreeNetwork(head->next[i]);

	//���M�����
	free(head);

	return 0;

}

//���ɂǂ̃m�[�h��T������΂����̂��������ċN�֐�
//�S�T���ŒT�����Ă��Ȃ����̂�T��
//���� head:�l�b�g���[�N�̃m�[�h�������|�C���^
Network* GoNext(Network* head){
	unsigned int i;
	Network* ret=NULL;

	//���g�����T���ł���Ύ�����Ԃ�
	if(head->serch_flag==0){
		head->serch_flag=1;
		return head;
	}

	//next==NULL�Ȃ��NULL��Ԃ�
	if(head->next==NULL) return NULL;

	//���g�����T���łȂ��ꍇ�C���̑w��T������
	for(i=0;i<head->next_num;i++) if(NULL!=(ret=GoNext(head->next[i]))) break;
	
	//���w�̒T������߂��Ă����߂�l��Ԃ�
	return ret;

}