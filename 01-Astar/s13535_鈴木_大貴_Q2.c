
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int input[3][3]={{8,1,5},{2,0,4},{6,3,7}};
int answer[3][3]={{1,2,3},{4,5,6},{7,8,0}};

//�p�Y���f�[�^
typedef struct _Pazzle{
	int data[3][3];			//�p�Y���̃f�[�^
	int g;					//�}���n�b�^�������̑��a
	int f;					//�T���؂̊K�w
	int cost;				//�����I�֐��̒l
	unsigned long int ID;	//�N���[�Y���X�g�Ɏg��ID �p�Y���̃f�[�^��unsigned long int�^�ɂ܂Ƃ߂�����

	//�T���؂̎q�̃|�C���^
	struct _Pazzle *t_next[4];
	//�T���؂̐e�̃|�C���^
	struct _Pazzle *t_prev;

	//"�T���I����"�Ɍ�����������H�邽�߂̃|�C���^
	//�T������NULL
	struct _Pazzle *ans;

}Pazzle;

//Open���X�g
typedef struct _OpenList {

	//�Ώۂ̃p�Y���f�[�^
	struct _Pazzle *pzl;

	//�o�������X�g�̂��߂̃|�C���^
	struct _OpenList *next;
	struct _OpenList *prev;
}OpenList;


//Close���X�g
typedef struct _ClozeList{

	//�p�Y���̃f�[�^��unsigned long int�^�ɂ܂Ƃ߂�����
	unsigned long int ID;

	//�P�������X�g�̂��߂̃|�C���^
	struct _ClozeList *next;
}CloseList;


int MainSearch(Pazzle *pazzle);
int O_ListAdd(OpenList *openL, Pazzle *pazzle);
void O_ListClear(OpenList *openL);
int C_ListAdd(CloseList *closeL, unsigned long int ID);
int C_ListCheck(CloseList *closeL, unsigned long int ID);
void C_ListClear(CloseList *closeL);
int Manhattan(int data[3][3]);
unsigned long int SetID(int data[3][3]);
void ShowPazzle(int data[3][3]);
int FileOutput(Pazzle *pazzle);
int F_Output(int F, int start_flag);


int main(){
	Pazzle *pazzle;
	int i,n;

	//�������m��
	pazzle = (Pazzle*)malloc(sizeof(Pazzle));
	if(pazzle == NULL) return -1;
	
	//�����ݒ�
	//�p�Y���̏����f�[�^��ǂݍ��ݑ��
	pazzle->ID = 0;
	for (i = 0; i < 3; i++) for (n = 0; n < 3; n++) {
		pazzle->data[i][n] = input[i][n];
		pazzle->ID += pow(10, (8 - (i*3 + n)))*input[i][n];
	}
	//�}���n�b�^���������v�Z�����
	pazzle->g = Manhattan(pazzle->data);
	//�o�H�R�X�g(�K�w��)�̏����l����
	pazzle->f = 0;
	//�����I�֐����v�Z�����
	pazzle->cost = pazzle->f + pazzle->g;
	//���X�g�̏����ݒ�
	for(i = 0; i < 4; i++) pazzle->t_next[i] = NULL;
	pazzle->t_prev = NULL;

	//�T���J�n
	MainSearch(pazzle);

	//�t�@�C���o��
	FileOutput(pazzle);

	getchar();

	return 0;
}

//�����I�֐������߂�
int MainSearch(Pazzle *pazzle){

	//�I�[�v�����X�g
	OpenList *openL, *openL_now;

	//�N���[�Y���X�g�Ƃ��̐擪
	CloseList *closeL, *closeL_start;
	int i,n,m;
	int count = 0;

	//�I�[�v�����X�g�������m��
	openL = (OpenList*)malloc(sizeof(OpenList));
	if (openL == NULL) return -1;
	//�I�[�v�����X�g������
	openL->prev = NULL;
	openL->next = NULL;
	openL->pzl = pazzle;

	//�N���[�Y���X�g�������m��
	closeL = (CloseList*)malloc(sizeof(CloseList));
	if (closeL == NULL) return -1;
	//�N���[�Y���X�g������
	closeL->ID = 0;
	closeL->next = NULL;

	//�N���[�Y���X�g�̏����n�_���L��
	closeL_start = closeL;

	//�T�����I������܂Ń��[�v���J��Ԃ�
	while (1){

		count+=1;

		//�Ώۂ̎q�m�[�h�ipazzle->t_next[]�j�̏�����
		for (i = 0; i < 4; i++) {
			//�������m��
			pazzle->t_next[i] = (Pazzle*)malloc(sizeof(Pazzle));
			if (pazzle->t_next[i] == NULL) return -1;
			//�K�w�̍X�V
			pazzle->t_next[i]->f = pazzle->f + 1;
			//�e�̃f�[�^���R�s�[
			for (n = 0; n < 3; n++) for (m = 0; m < 3; m++)
				pazzle->t_next[i]->data[n][m] = pazzle->data[n][m];
			//�R�X�g�̏�����
			pazzle->t_next[i]->cost = pazzle->cost;
			//�}���n�b�^�������̏�����
			pazzle->t_next[i]->g = pazzle->g;
			//�|�C���^�̏�����
			for (n = 0; n < 4; n++) pazzle->t_next[i]->t_next[n] = NULL;
			pazzle->t_next[i]->t_prev = pazzle;
		}

		//��̃p�Y���f�[�^���L��
		openL_now = openL;
		C_ListAdd(closeL, pazzle->ID);

		//�󗓂̓���ւ����s��
		for (n = 0; n < 3; n++) for (m = 0; m < 3; m++){
			//�󗓂̈ړ��悪�͈͊O�������ꍇ�A�R�X�g�𕉐��ɂ���(�t���O�̑�p)
			if (pazzle->data[n][m] == 0){
				//��
				if (n != 0){
					pazzle->t_next[0]->data[n][m] = pazzle->t_next[0]->data[n - 1][m];
					pazzle->t_next[0]->data[n - 1][m] = 0;
					pazzle->t_next[0]->ID = SetID(pazzle->t_next[0]->data);
					pazzle->t_next[0]->t_prev = pazzle;
				}
				else pazzle->t_next[0]->cost = -1;
				//��
				if (m != 0){
					pazzle->t_next[1]->data[n][m] = pazzle->t_next[1]->data[n][m - 1];
					pazzle->t_next[1]->data[n][m - 1] = 0;
					pazzle->t_next[1]->ID = SetID(pazzle->t_next[1]->data);
					pazzle->t_next[1]->t_prev = pazzle;
				}
				else pazzle->t_next[1]->cost = -1;
				//��
				if (n != 2){
					pazzle->t_next[2]->data[n][m] = pazzle->t_next[2]->data[n + 1][m];
					pazzle->t_next[2]->data[n + 1][m] = 0;
					pazzle->t_next[2]->ID = SetID(pazzle->t_next[2]->data);
					pazzle->t_next[2]->t_prev = pazzle;
				}
				else pazzle->t_next[2]->cost = -1;
				//�E
				if (m != 2){
					pazzle->t_next[3]->data[n][m] = pazzle->t_next[3]->data[n][m + 1];
					pazzle->t_next[3]->data[n][m + 1] = 0;
					pazzle->t_next[3]->ID = SetID(pazzle->t_next[3]->data);
					pazzle->t_next[3]->t_prev = pazzle;
				}
				else pazzle->t_next[3]->cost = -1;
			}
		}

		//�󗓂��ړ��ł����ꍇ�A�}���n�b�^�������Ɣ����I�֐����v�Z����
		for (i = 0; i < 4; i++){
			//�����ŋ󗓂��ړ��ł��������f�A�X�ɃN���[�Y���X�g���ɑΏۂ�ID�����݂��Ȃ����Ƃ��m�F
			if (pazzle->t_next[i]->cost != -1 && C_ListCheck(closeL_start, pazzle->t_next[i]->ID) == 0) {
				//�}���n�b�^�������̑��a���v�Z���A�R�X�g���Z�o�A���̌�I�[�v�����X�g�ɉ�����
				pazzle->t_next[i]->g = Manhattan(pazzle->t_next[i]->data);
				pazzle->t_next[i]->cost = pazzle->t_next[i]->f + pazzle->t_next[i]->g;
				O_ListAdd(openL, pazzle->t_next[i]);
			}
		}

		//���݂�OpenList���L�^����
		openL = openL_now;

		//�|�C���^�̈ʒu�����[�łȂ��ꍇ���X�g���Ȃ��Ȃ���
		if (openL->prev != NULL) {
			openL->prev->next = openL->next;
		}
		if (openL->next != NULL) {
			openL->next->prev = openL->prev;
		}

		//���̃|�C���^�Ɉړ�
		openL = openL->next;

		//�I�[�v�����X�g�������
		free(openL_now);

		//���X�g��擪�ɖ߂�
		while (openL->prev != NULL) openL = openL->prev;
		//�I�[�v�����X�g�̒��g�\��
		while (1) {
			if (openL->next == NULL) break;
			else openL = openL->next;
		}

		//���X�g��擪�ɖ߂�
		while (openL->prev != NULL) openL = openL->prev;
		//�}���n�b�^�������̑��a����0�ɂȂ����Ƃ��ɒT�����I������
		if (openL->pzl->g == 0){
			printf("�T���I��");
			ShowPazzle(openL->pzl->data);
			printf("�R�X�g%d �}���n�b�^��%d �K�w%d\n", openL->pzl->cost, openL->pzl->g, openL->pzl->f);
			break;
		}
		//�I�[�v�����X�g�����ׂĒT�������Ƃ�
		if (openL->next == NULL) {
			printf("�T�����s ���ɂ��ǂ蒅���܂���\n");
			return -1;
		}

		//�����I�֐��̒l���o��
		F_Output(pazzle->cost,count);

		//�I�[�v�����X�g���玟�̃p�Y����ǂݍ���
		pazzle = openL->pzl;

	}

	//�T���I����A�e�̃m�[�h�����ǂ��Ď菇���L�^����
	if (openL->pzl->g != 0) {
		printf("�T�����������Ă��܂���\n");
		return -1;
	}
	else {
		pazzle = openL->pzl;
		pazzle->ans = NULL;
		while (pazzle->t_prev != NULL) {
			pazzle->t_prev->ans = pazzle;
			pazzle = pazzle->t_prev;
		}
	}

	//���X�g��擪�ɖ߂�
	while (openL->prev != NULL) openL = openL->prev;
	//�I�[�v�����X�g�J��
	O_ListClear(openL);
	printf("�I�[�v�����X�g���J�����܂���\n");
	//�N���[�Y���X�g�J��
	C_ListClear(closeL_start);
	printf("�N���[�Y���X�g���J�����܂���\n");

	return 0;
}

//�R�X�g�����������ɃI�[�v�����X�g�ɑ}������
int O_ListAdd(OpenList *openL, Pazzle *pazzle){

	OpenList *newInput;

	newInput = (OpenList*)malloc(sizeof(OpenList));

	if(openL==NULL || pazzle==NULL || newInput==NULL){
		printf("error ���X�g�����݂��Ȃ����ߒǉ��ł��܂���\n");
		return -1;
	}

	//�l�̃R�s�[
	newInput->next = NULL;
	newInput->prev = NULL;
	newInput->pzl = pazzle;

	//���X�g��擪�Ɉړ�
	while (openL->prev != NULL) openL = openL->prev;

	//�����I�֐��̒l�A�K�w�ŏ��������ɂȂ�悤�Ƀ��X�g�ɑ}��
	while (1){
		if(newInput->pzl->cost < openL->pzl->cost){
			newInput->prev=openL->prev;
			newInput->next=openL;
			if (openL->prev != NULL) openL->prev->next=newInput;
			openL->prev=newInput;
			break;
		}
		else if(openL->next==NULL){
			newInput->next = openL->next;
			openL->next = newInput;
			newInput->prev = openL;
			break;
		}
		openL=openL->next;
	}

	return 0;

}

//�I�[�v�����X�g���폜����@�����̓��X�g�̐擪��n���K�v������
void O_ListClear(OpenList *openL_start) {

	OpenList *p;

	p = openL_start;

	if (p->next != NULL) O_ListClear(p->next);
	if (p->prev != NULL) p->prev->next = NULL;
	free(p);

}

//�N���[�Y���X�g�ɒǉ�����
int C_ListAdd(CloseList *closeL, unsigned long int ID) {
	CloseList *new_closeL;

	new_closeL = (CloseList*)malloc(sizeof(CloseList));

	if (closeL == NULL || new_closeL == NULL) return -1;

	new_closeL->next = NULL;
	new_closeL->ID = ID;

	//���[�Ɉړ�
	while (closeL->next != NULL) closeL = closeL->next;
	closeL->next = new_closeL;

	return 0;
}

//�N���[�Y���X�g���폜����@�����̓��X�g�̐擪��n���K�v������
void C_ListClear(CloseList *closeL_start) {

	CloseList *p;
	
	while (1) {
		p = closeL_start;
		if (closeL_start->next != NULL) {
			closeL_start = closeL_start->next;
			free(p);
		}
		else {
			free(p);
			break;
		}
	}
}

//�N���[�Y���X�g�Ɉ�����ID�����邩�m�F����(���X�g�̐擪�������ɂ���K�v����)
//�߂�l0�E�E�E�N���[�Y���X�g���ɑ��݂��Ȃ�
//�߂�l1�E�E�E�N���[�Y���X�g���ɑ��݂���
int C_ListCheck(CloseList *closeL, unsigned long int ID) {

	if (closeL == NULL) return -1;

	while (closeL->next != NULL) {
		if (closeL->ID == ID) return 1;
		//printf("%ld\n", closeL->ID);
		closeL = closeL->next;
	}

	return 0;
}

//�p�Y������}���n�b�^�������̑��a���v�Z���߂�l�Ƃ��ĕԂ�
int Manhattan(int data[3][3]){
	int sum=0;
	int i,n,m,l,j;

	//1�`8�̒l�����ԂɒT��
	for(i=1;i<9;i++){
		//���̓f�[�^����T��
		for(n=0;n<3;n++) for(m=0;m<3;m++){
			if(data[n][m]==i){
				//�����f�[�^����T��
				for(l=0;l<3;l++) for(j=0;j<3;j++){
					if(answer[l][j]==i){
						//�v�f���̂��ꂩ��}���n�b�^���������v�Z
						sum += abs(n-l)+abs(m-j);
					}
				}
			}
		}
	}
	return sum;
}

//�p�Y���f�[�^����ID�𔭍s���߂�l�Ƃ��ĕԂ�
unsigned long int SetID(int data[3][3]) {
	unsigned long int ID = 0;
	int n, m;

	for (n = 0; n<3; n++) for (m = 0; m<3; m++) {
		ID += pow(10, (8 - (n*3 + m)))*data[n][m];
	}
	//printf("%ld\n", ID);

	return ID;
}

//�p�Y���̔z�u��\������
void ShowPazzle(int data[3][3]){
	int n,m;
	printf("\n");
	for(n=0;n<3;n++){
		for(m=0;m<3;m++){
			printf("%d ",data[n][m]);
		}
		printf("\n");
	}
}

//�t�@�C���o��
int FileOutput(Pazzle *pazzle) {
	int n, m;
	FILE *file;
	errno_t error;

	if ((error = fopen_s(&file, "8puzzle.txt", "w+")) != 0) {
		// �G���[����
		printf("error �t�@�C�����J�����Ƃ��ł��܂���\n");
		return -1;
	}

	//���X�g�̐擪��
	while (pazzle->t_prev != NULL) pazzle = pazzle->t_prev;

	//�|�C���^��H���ăt�@�C���ɏ�������
	while (1) {
		for (n = 0; n < 3; n++) {
			for (m = 0; m < 3; m++) {
				fprintf(file, "%d ", pazzle->data[n][m]);
			}
			fprintf(file, "\n");
		}
		fprintf(file, "�����I�֐��̒l:%d\n�}���n�b�^�������̑��a:%d �K�w:%d\n\n", pazzle->cost, pazzle->g, pazzle->f);

		if (pazzle->ans == NULL) break;
		else pazzle = pazzle->ans;
	}

	fclose(file);

	return 0;

}

//�����I�֐��̒l���o�͂���
//start_flag��1�Ȃ�t�@�C�����㏑�����A����ȊO�Ȃ�t�@�C���ɒǉ�����
int F_Output(int F,int start_flag) {
	FILE *file;
	errno_t error;

	if(start_flag==1){
		if ((error = fopen_s(&file, "8puzzle_F.txt", "w+")) != 0) {
			// �G���[����
			printf("error �t�@�C�����J�����Ƃ��ł��܂���\n");
			return -1;
		}
	}
	else {
		if ((error = fopen_s(&file, "8puzzle_F.txt", "a+")) != 0) {
			// �G���[����
			printf("error �t�@�C�����J�����Ƃ��ł��܂���\n");
			return -1;
		}
	}

	fprintf(file, "%d\n", F);

	fclose(file);

	return 0;
}