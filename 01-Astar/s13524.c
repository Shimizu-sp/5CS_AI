/*
**  �쐬��:Daisuke Kuwahara
**  �쐬�N:2017
**	�����:
**      �ELinux
**          - Linux version 3.10.0-514.26.2.el7.x86_64 (builder@kbuilder.dev.centos.org) (gcc version 4.8.5 20150623 (Red Hat 4.8.5-11) (GCC) ) #1 SMP Tue Jul 4 15:04:05 UTC 2017
**          - CentOS Linux release 7.3.1611 (Core) 
**          - gcc version 4.8.5 20150623 (Red Hat 4.8.5-11) (GCC) 
**      �EWindows
**          - Windows 10 pro 64bit
**          - Microsoft Visual Studio Express 2012 for Windows Desktop
**  �@�\����:
**	�EA*�A���S���Y����p����3*3�̃p�Y��������������v���O����
**      �E�؍\���͊e�m�[�h��o�����`�F�C����p���ŕ\�����Ă���
**	�E�󔒕���0�Ŏ����܂�
**      �E���s���ɁuSegmentation fault (core dumped)�v���o�͂���܂������ʂ͑S�Đ������o�͂���܂��B�������R�͂悭�킩��܂���B
*/

//�w�b�_�ǂݍ��ݕ�
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Visual Studio�̂ݕK�v�@VisualStudio�œ������ꍇ�ɂ� #pragma~ �̕����̃R�����g����������
//#pragma warning(disable:4996) 

//�\���̒�`��

typedef struct def_tree{
	unsigned int f;				//���̃p�Y���̏�Ԃ��������I�֐��̒l
	unsigned int g;				//���̃��X�g������ڂɑ��݂��邩(�؍\����̐[��)�������ϐ�
	unsigned int x;				//���̃m�[�h�̋󔒂�x���W���i�[
	unsigned int y;				//���̃m�[�h�̋󔒂�y���W���i�[
	unsigned int v[3][3];		//���̃m�[�h�̃p�Y���̏�Ԃ��i�[����ϐ�
	unsigned int before_type;	//���̃��X�g�̐e�m�[�h����ǂ̕����ɐi�񂾏ꍇ�ɂ��̃m�[�h�ɓ�������̂��������ϐ�(0:�� 1:�E 2:�� 3:�� 4:����(���g�����[�g))
	struct def_tree* before;	//�e�̃m�[�h�������|�C���^(NULL : ���[�g)
	struct def_tree* p[4];		//���݂̏�Ԃ��瓮�������ꍇ�̃��X�g�������|�C���^�z��(0:�� 1:�E 2:�� 3:�� ���݂��Ȃ��ꍇ:NULL)
} Tree;

//Open List
typedef struct def_List{
	Tree* tree;				//Tree�\���̂̃A�h���X���i�[����ϐ�
	struct def_List* next;	//���̌����Ώۂւ̃|�C���^
} List;

//�֐��v���g�^�C�v�錾��
//�֐��͈ꊇ���Đ������ɂ�0,���s���ɂ̓}�C�i�X��Ԃ�

int LoadData(unsigned int c[3][3],unsigned int g[3][3],unsigned int* x,unsigned int* y,unsigned int gc[9][2]);
int PrintLog( unsigned int c[3][3], unsigned int f);
int CaluculateF(Tree* t, unsigned int gc[9][2]);
int PrintGoalRoot(Tree* t);
int CreateTree(Tree* now);
int OpenList(Tree** t,unsigned char do_type);
int CloseList(Tree* t,unsigned char do_type);
int MoveTo(unsigned int v[3][3],unsigned int* x,unsigned int* y, unsigned int move);
int Close(Tree* head);

int main(){
	Tree* head;								//�c���[�̃��[�g�������|�C���^
	Tree* p;								//�c���[�̂ǂ����Q�Ƃ��Ă���̂��������|�C���^
	unsigned int start[3][3];				//�p�Y���̏�����Ԃ��i�[����\����
	unsigned int goal[3][3];				//�p�Y���̊����`���i�[����\����
	unsigned int coordinates_of_goal[9][2];	//�p�Y���̃S�[���̊e�p�l���̍��W
	unsigned int start_x;			        //�󔒂̏���x���W�������ϐ�
	unsigned int start_y;			        //�󔒂̏���y���W�������ϐ�

	FILE* fp;						    	//�t�@�C���쐬�p�|�C���^
	unsigned int i,k;						//���[�v�p�J�E���^
	int ret=0;								//�֐��̖߂�l���i�[����ϐ�

	//�p�Y���̃f�[�^��ǂݍ���
	if(0>LoadData(start,goal,&start_x,&start_y,coordinates_of_goal)){
		perror("LoadData");
		return -1;
	}

	//�o�̓t�@�C���𐶐�
	if(NULL==(fp=fopen("output.txt","w+"))){
		perror("fopen");
		return -1;
	}
	fclose(fp);

	if(NULL==(fp=fopen("f.txt","w+"))){
		perror("fopen");
		return -1;
	}
	fclose(fp);

	//���[�g�̃������m��
	if(NULL==(head=(Tree*)malloc(sizeof(Tree)))){
		perror("malloc");
		return -2;
	}

	//���[�g�̏�����
	head->before_type=4;
	head->g=0;
	head->x=start_x;
	head->y=start_y;
	head->before=NULL;
	for(i=0;i<4;i++) head->p[0]=NULL;
	for(i=0;i<3;i++) for(k=0;k<3;k++) head->v[i][k]=start[i][k];


	//�����I�֐��̒l���v�Z
	if(0>CaluculateF(head,coordinates_of_goal)){
		perror("CaluculateF");
		return -2;
	}

	//���O���o��
	PrintLog(head->v,head->f);

	p=head;

	while(1){
		//�I�����ꂽ�m�[�h���ڕW��ԉ����m�F����( f(p)=g(p)+h(p) ���A h(p)=f(p)-g(p) h(p)=0�͖ڕW���)
		if(0==((p->f)-(p->g))){
			printf("found!\n");
			break;
		}

		//Open List������o�����m�[�h�ɗאڂ��Ă���m�[�h���쐬
		if(0>CreateTree(p)){
			perror("CreateTree");
			return -3;
		}
		//�쐬�����m�[�h�̔����I�֐����v�Z
		for(i=0;i<4;i++){
			if(p->p[i]!=NULL){
				if(0>CaluculateF(p->p[i],coordinates_of_goal)){
					perror("CalucurateF");
					return -2;
				}
			}
		}
		//�V�K�쐬�����m�[�h��Open List�ɒǉ�
		if(0>OpenList(&p,0)){
			perror("Priority - 0");
			return -4;
		}
		//Open List���ōł������I�֐��̒l���Ⴂ���̂����̑ΏۂƂ���
		if(0>(ret=OpenList(&p,1))){
			perror("Priority - 1");
			return -5;
		}
		else if(ret==1){
			printf("not found...\n");
			break;
		}
		PrintLog(p->v,p->f);
	}
		
	//������Ԃ���S�[����Ԃ܂ł̈ړ��o�H�����
	if(0>PrintGoalRoot(p)){
		perror("PrintGoalRoot");
		return -6;
	}

	OpenList(NULL,2);
	CloseList(NULL,2);
	Close(head);

	return 0;
}

//�t�@�C������p�Y���̏�����ԁE�ڕW��Ԃ�ǂݍ��ފ֐�
//����	:	�p�Y���̏����l���i�[�����z��,�p�Y���̃S�[�����i�[�����z��,�󔒂�x���W���i�[�����ϐ�,�󔒂�y���W���i�[�����ϐ�,�S�[����Ԃ̊e�p�l���̍��W���i�[�����z��
int LoadData(unsigned int c[3][3],unsigned int g[3][3],unsigned int* x,unsigned int* y,unsigned int gc[9][2]){
	FILE* fp;
	int i,k;

	//�t�@�C���L�q�q�̊m�ۂƃG���[����
	if(NULL==(fp=fopen("input.txt","r"))){
		perror("fopen");
		return -1;
	}

	//�t�@�C������f�[�^��ǂݍ���
	//��������
	fscanf(fp,"%u %u %u",&c[0][0],&c[0][1],&c[0][2]);
	fscanf(fp,"%u %u %u",&c[1][0],&c[1][1],&c[1][2]);
	fscanf(fp,"%u %u %u",&c[2][0],&c[2][1],&c[2][2]);
	fgetc(fp);

	//�ڕW���
	fscanf(fp,"%u %u %u",&g[0][0],&g[0][1],&g[0][2]);
	fscanf(fp,"%u %u %u",&g[1][0],&g[1][1],&g[1][2]);
	fscanf(fp,"%u %u %u",&g[2][0],&g[2][1],&g[2][2]);

	fclose(fp);

	for(i=0;i<3;i++){
		for(k=0;k<3;k++){
			//�󔒂̈ʒu����`�T�����A�e�ϐ��Ɋi�[����B
			if(c[i][k]==0){
				*x=i;
				*y=k;
			}

			//�S�[����Ԃ̃p�l���̍��W���i�[
			gc[g[i][k]][0]=i;
			gc[g[i][k]][1]=k;

		}
	}

	return 0;
}

//�t�@�C���ɔ����I�֐��ƃp�Y���̏�Ԃ��������ފ֐�
//����	:	�p�Y���̌��݂̏�Ԃ��i�[���ꂽ�֐�,�����I�֐��̒l
int PrintLog(unsigned int c[3][3], unsigned int f){
	FILE* fp;

	//�t�@�C���L�q�q�̊m�ۂƃG���[����
	if(NULL==(fp=fopen("output.txt","a+"))){
		perror("fopen");
		return -1;
	}

	fprintf(fp,"%u %u %u\n",c[0][0],c[0][1],c[0][2]);
	fprintf(fp,"%u %u %u\n",c[1][0],c[1][1],c[1][2]);
	fprintf(fp,"%u %u %u\n",c[2][0],c[2][1],c[2][2]);
	fprintf(fp,"f = %u\n",f);
	fprintf(fp,"\n");

	fclose(fp);

	//�t�@�C���L�q�q�̊m�ۂƃG���[����
	if(NULL==(fp=fopen("f.txt","a+"))){
		perror("fopen");
		return -1;
	}

	fprintf(fp,"%u,",f);

	fclose(fp);

	return 0;
}

//�m�[�h����h������m�[�h���v�Z�A�쐬���A�����I�֐��̒l���v�Z����֐�
//����	:	�v�Z�������m�[�h,�p�Y���̖ڕW��Ԃ̊e�p�l���̍��W
int CaluculateF(Tree* t, unsigned int gc[9][2]){
	unsigned int h=0;		//�}���n�b�^���������i�[����ϐ�
	int i,k;				//���[�v�J�E���^
	
	for(i=0;i<3;i++) for(k=0;k<3;k++){
		if(t->v[i][k]==0) continue;
		h+=(unsigned int)(abs((int)(i-gc[t->v[i][k]][0]))+abs((int)(k-gc[t->v[i][k]][1])));
	}

	//���̃��[�g��I�������ꍇ�̔����I�֐��̒l���v�Z
	t->f=t->g+h;
        
	return 0;
}

//���[�U�ɓ��͂��ꂽ�p�Y����Ԃ�������ɓ��͂��ꂽ�m�[�h�̏�Ԃ܂ł̈ړ��������v�Z����֐�
//����	:	�v�Z�������m�[�h,���[�U������͂��ꂽ�p�Y���̔z�u
int PrintGoalRoot(Tree* t){
	FILE *fp;			//�o�̓t�@�C���쐬�p�ϐ�
	Tree *p;			//�v�Z�p�̃|�C���^
	unsigned int i;    	//���[�v�p�J�E���^
	unsigned int *root;	//�ڕW��Ԃ܂ł̃��[�g���i�[����ϐ�
	
	p=t;
	
      	//���[�g�p�̃��������m��
       	if(NULL==(root=(unsigned int*)malloc( (sizeof(unsigned int)*( ((size_t)t->g) +10 )) ))){
		perror("malloc");
		return -1;
	}
	
	//���[�g����root�z��Ɋi�[����
	for(i=t->g;i>0;i--){
		if(p->before_type!=4) root[i-1]=p->before_type;
		if(p->before!=NULL) p=p->before;
	}
		
       	//�o�͗p�t�@�C�����쐬
	if(NULL==(fp=fopen("start_goal.txt","w+"))){
		perror("fopen");
		return -1;
	}	
	
	for(i=0;i<t->g;i++){
		//�t�@�C���ɏo��
		fprintf(fp,"%u %u %u\n",p->v[0][0],p->v[0][1],p->v[0][2]);
		fprintf(fp,"%u %u %u\n",p->v[1][0],p->v[1][1],p->v[1][2]);
		fprintf(fp,"%u %u %u\n",p->v[2][0],p->v[2][1],p->v[2][2]);
		fprintf(fp,"f = %u\n\n",p->f);
		
		//���Ɉړ�
		if(p->p[root[i]]!=NULL) p=p->p[root[i]];
	}
	
	fprintf(fp,"%u %u %u\n",p->v[0][0],p->v[0][1],p->v[0][2]);
	fprintf(fp,"%u %u %u\n",p->v[1][0],p->v[1][1],p->v[1][2]);
	fprintf(fp,"%u %u %u\n",p->v[2][0],p->v[2][1],p->v[2][2]);
        fprintf(fp,"f = %u\n\n",p->f);
	
	fclose(fp);
	free(root);
	
	return 0;
}

//���X�g���獶�E�㉺�ɓ��������ꍇ�̃��X�g���쐬
//����	:	�`�F�C�����̃��X�g
int CreateTree(Tree* now){
	unsigned int p,i,k;		//���[�v�J�E���^
	Tree* chain;			//�m�ۂ����ϐ����i�[����|�C���^
	unsigned int ret;		//�֐��̖߂�l���󂯎��ϐ�

	for(p=0;p<4;p++){
		//�V�����m�[�h���쐬
		if(NULL==(chain=(Tree*)malloc(sizeof(Tree)))){
			perror("malloc");
			return -1;
		}
		
		//�󔒂̈ړ���̐���
		switch(p){
		case 0:
			//���Ɉړ��ł��邩�m�F
			if(now->x==0){
				now->p[p]=NULL;
				free(chain);
				continue;
			}
			break;
		case 1:
			//�E�Ɉړ��ł��邩�m�F
			if((now->x+1)>2){
				now->p[p]=NULL;
				free(chain);
				continue;
			}
			break;
		case 2:
			//��Ɉړ��ł��邩�m�F
			if(now->y==0){
				now->p[p]=NULL;
				free(chain);
				continue;
			}
			break;
		case 3:
			//���Ɉړ��ł��邩�m�F
			if((now->y+1)>2){
				now->p[p]=NULL;
				free(chain);
				continue;
			}
			break;
		default:
			perror("counter for loop was broken.");
			return -2;

			break;
		}

		//�ϐ��̏�����
		chain->before_type=p;
		chain->g=now->g+1;
		chain->before=now;
		chain->x=now->x;
		chain->y=now->y;
		for(i=0;i<4;i++) chain->p[i]=NULL;

		//�m�[�h�̃p�Y����ό`
		for(i=0;i<3;i++) for(k=0;k<3;k++) chain->v[i][k]=now->v[i][k];
		//Memo : MoveTo�֐��̒���x,y���W�͈ړ������
		if(0>MoveTo(chain->v,&(chain->x),&(chain->y),p)){
			perror("MoveTo");
			return -3;
		}

		//CloseList�ɑ��݂���ꍇ�ɂ�NULL�ɂ���
		if(1==(ret=CloseList(chain,1))){
			free(chain);
			chain=NULL;
		}
		else if(ret<0){
			perror("CloseList");
			return -4;
		}


		//���X�g���m���Ȃ���
		now->p[p]=chain;
	}
	
	return 0;
}

//Open List�𑀍삷�邽�߂̊֐�
//���̊֐��͗�O�I��1��Ԃ��B1��Ԃ��ꍇ��do_type=1�ł���AOpen List������ł��������ł���
//����	:	�p�Y���̏�Ԃ������m�[�h�̍\���̃|�C���^,���̊֐��̓�������߂�ϐ�(0:�V�����m�[�h��ǉ� 1:���X�g�����甭���I�֐��̒l���ł��Ⴂ���̂�t�Ɋi�[���� 2:���������������)
int OpenList(Tree** t,unsigned char do_type){
	static List* head=NULL;				//�\���̃��X�g�̐擪�������|�C���^
	List *p,*keep;	       				//�e�푀��ɗ��p����|�C���^
	unsigned int i;	       				//���[�v�p�J�E���^
	int found_flag;					//���łɑ}�����݂��𔻒f����t���O

	//Open List�ɉ��������Ă��Ȃ��ꍇ�A�쐬
	if(head==NULL){
		//�������m��
		if(NULL==(head=(List*)malloc(sizeof(List)))){
			perror("malloc");
			return -1;
		}
		//�쐬�����ϐ��̏�����
		head->next=NULL;
		head->tree=NULL;
	}

	switch(do_type){
	case 0:
		for(i=0;i<4;i++){
			//�G���[����
			if((*t)->p[i]==NULL) continue;
			
			if(head->tree==NULL){
				head->tree=(*t)->p[i];
				continue;
			}
			
			//�ϐ��̏�����
			p=head;
			keep=NULL;
			found_flag=1;
	
			//���`�T���łǂ̏��ʂɑ}�����邩�����߂�
			while(1){
				//����ʒu�����邩���r
				if((p->tree->f) >= ((*t)->p[i]->f)){
					//�����I�֐��̒l�������ꍇ�Ag�̒l����������傫���̂ł���Ύ��̃��[�v�Ɉړ�����
					if((p->tree->f) == ((*t)->p[i]->f) && (p->tree->g) < ((*t)->p[i]->g)){
						//���̃��X�g�����[�����m�F
						if(p->next==NULL){
							//����ʒu�����݂��Ȃ������ꍇ�͍Ō���ɒǉ�����
					
							//���������m��
							if(NULL==(p->next=(List*)malloc(sizeof(List)))){
								perror("malloc");
								return -1;
							}
							//������
							p->next->next=NULL;
							//�}��
							p->next->tree=(*t)->p[i];

							break;
						}
						
						//���̃��X�g�ɐi��
						keep=p;
						p=p->next;
						continue;
					}
											
					//Open List���Ŕ����I�֐��̒l���ł��Ⴂ�ꍇ�̏���
					if(keep==NULL){
						//���������m��
						if(NULL==(keep=(List*)malloc(sizeof(List)))){
							perror("malloc");
							return -1;
						}
						//�}��
						keep->next=p;
						//�m�[�h�ƕR�Â�
						keep->tree=(*t)->p[i];
						//head�̈ړ�
						head=keep;
						//�t���O��������
						found_flag=0;
						break;
					}
					
					//���������m��
					if(NULL==(keep->next=(List*)malloc(sizeof(List)))){
						perror("malloc");
						return -1;
					}
					//�}��
					keep->next->next=p;
					//�m�[�h�ƕR�Â�
					keep->next->tree=(*t)->p[i];
					//�t���O����������
					found_flag=0;

					break;
				}

				//���̃��X�g�����[�����m�F
				if(p->next==NULL){
					//����ʒu�����݂��Ȃ������ꍇ�͍Ō���ɒǉ�����
					
					//���������m��
					if(NULL==(p->next=(List*)malloc(sizeof(List)))){
						perror("malloc");
						return -1;
					}
					//������
					p->next->next=NULL;
					//�}��
					p->next->tree=(*t)->p[i];

					break;
				}
				
				//���̃��X�g�ɐi��
				keep=p;
				p=p->next;
			}

		}
		break;

	case 1:
		//�G���[����
		if(head->tree==NULL) return 1;

		//�����̃|�C���^�ɍł������I�֐��̒l���������m�[�h��n��
		*t=head->tree;

		//Open List����������̂�Close List�ɒǉ�
		CloseList(head->tree,0);

		//�G���[����
		if(head->next==NULL){
			head->tree=NULL;
			return 0;
		}

		//����X�g���l�߂�
		head->tree=head->next->tree;
		keep=head;
		head=head->next;

		//�g�p���Ȃ��Ȃ������X�g���������J��
		free(keep);

		break;

	case 2:
	        if(head==NULL) break;
		
		//���������������@�\
		keep=head->next;
		p=head;
		
		while(1){
			//�����������
			free(p);

			//�����Ȃ��̂Ȃ�I��
			if(keep==NULL) break;

                	p=keep;

			keep=keep->next;
		}

		break;

	default:
		perror("do_type number broken!");
		return -1;
	}

	return 0;
}

//Close List�𑀍삷�邽�߂̊֐�
//���̊֐��͗�O�I��1��Ԃ��B1��Ԃ��ꍇ��do_type=1�ł���AOpen List������ł��������ł���
//����	:	�p�Y���̏�Ԃ������m�[�h�̍\���̃|�C���^,���̊֐��̓�������߂�ϐ�(0:�V�����m�[�h��ǉ� 1:(*t)->v�Ɉ�v������̂����邩���������� 2:���������������)
int CloseList(Tree* t,unsigned char do_type){
	static List* head=NULL;				//�\���̃��X�g�̐擪�������|�C���^
	List *p,*keep;						//�e�푀��ɗ��p����|�C���^
	unsigned int i,k;					//���[�v�p�J�E���^
	unsigned int end_counter=0;			//�p�Y���̏�Ԃ̈�v����v�����邽�߂̃J�E���^

	//Open List�ɉ��������Ă��Ȃ��ꍇ�A�쐬
	if(head==NULL){
		//�������m��
		if(NULL==(head=(List*)malloc(sizeof(List)))){
			perror("malloc");
			return -1;
		}
		//�쐬�����ϐ��̏�����
		head->next=NULL;
		head->tree=NULL;
	}

	switch(do_type){
	case 0:
		//�G���[����
		if(t==NULL){
			perror("t is NULL");
			return -3;
		}
		
		if(head->tree==NULL){
			head->tree=t;
			break;
		}

		//�ϐ��̏�����
		p=head;
	
		//���݂̃��X�g�̍Ō���ɓ��B����
		while(1){
			if(p->next==NULL) break;
			p=p->next;
		}

		//���������m��
		if(NULL==(p->next=(List*)malloc(sizeof(List)))){
			perror("malloc");
			return -1;
		}

		//�V�������X�g�ɒl��ǉ�
		p->next->tree=t;

		//�V�����m�ۂ����l�̏�����
		p->next->next=NULL;

		break;

	case 1:
		if(head->tree==NULL) return 0;

		//������
		p=head;

		//���`�T���ň�v������̂����邩���m�F
		while(1){
		        end_counter=0;
			if(p==NULL) break;
			
			//�p�Y����Ԃ̔�r
			for(i=0;i<3;i++) for(k=0;k<3;k++) if(t->v[i][k]==p->tree->v[i][k]) end_counter++;

			if(end_counter==9) return 1;

			p=p->next;
		}
		

		break;

	case 2:
	        if(head==NULL) break;
		
		//���������������@�\
		keep=head->next;
		p=head;

		while(1){
			//�����������
			free(p);

			//�����Ȃ��̂Ȃ�I��
			if(keep==NULL) break;

			p=keep;

			keep=keep->next;
		}

		break;

	default:
		perror("do_type number broken!");
		return -1;
	}

	return 0;
}

//�p�Y���̋󔒂��w�肵�������ɓ������֐�
//����	:	�������p�Y��,�󔒂�x���W,�󔒂�y���W,�ړ����������(0:�� 1:�E 2:�� 3:��)
int MoveTo(unsigned int v[3][3],unsigned int* x,unsigned int* y, unsigned int move){
	unsigned int keep;	//�v�Z�̓r�����ʂ��i�[����ϐ�

	switch(move){
	case 0:
		//���Ɉړ�
		keep=v[*x][*y];

		if((*x)==0){
			perror("Can't move");
			return -2;
		}

		v[*x][*y]=v[(*x)-1][*y];
		v[(*x)-1][*y]=keep;
		(*x)-=1;
		
		break;

	case 1:
		//�E�Ɉړ�
		keep=v[*x][*y];

		if((*x)+1>2){
			perror("Can't move");
			return -2;
		}

		v[*x][*y]=v[(*x)+1][*y];
		v[(*x)+1][*y]=keep;
		(*x)+=1;
		
		break;

	case 2:
		//��Ɉړ�
		keep=v[*x][*y];

		if((*y)==0){
			perror("Can't move");
			return -2;
		}

		v[*x][*y]=v[*x][(*y)-1];
		v[*x][(*y)-1]=keep;
		(*y)-=1;

		break;

	case 3:
		//���Ɉړ�
		keep=v[*x][*y];

		if((*y)+1>2){
			perror("Can't move");
			return -2;
		}

		v[*x][*y]=v[*x][(*y)+1];
		v[*x][(*y)+1]=keep;
		(*y)+=1;

		break;

	default:
		perror("Wrong : move number");
		return -1;
	}

	return 0;
}

//���X�g�̉�����s���֐�
//����	:	���X�g�̃��[�g
int Close(Tree* head){
	unsigned int i;	//���[�v�p�J�E���^

	for(i=0;i<4;i++) if(head->p[i]!=NULL) Close(head->p[i]);

	free(head);

	return 0;

}
