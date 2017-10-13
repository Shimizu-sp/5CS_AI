#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

//useful
#define SHOW(x) printf("%d %d %d\n%d %d %d\n%d %d %d\n\n",x[0][0],x[0][1],x[0][2],x[1][0],x[1][1],x[1][2],x[2][0],x[2][1],x[2][2]);
#define MEMORI(x) if(NULL == ( (x) = (Box*)malloc( sizeof(Box) ) )) perror("malloc fanction output err.");



/* �\���̂̒�` */
struct Box{

	int pazzle_model[3][3];//�p�Y���̏��
	int hierarchy;//�K�w
	int ID;//�m�[�h�ԍ�
	int FChi;//F�l
	struct Box* next[4];//���X�g next[0]�͍��Ɉړ� next[1]�͏�Ɉړ� next[2]�͉��Ɉړ� next[3]�͉E�Ɉړ�
};
typedef struct Box Box;

struct List {

	Box* Addr;
	struct List* next;
}; 
typedef struct List List;

int goal[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };//����[�΂�ϐ�

List* openlist=NULL;
List* closelist=NULL;
List* closelistS = NULL;


Box* OpenListR();//�ǂݍ��ݗp�I�[�v�����X�g
int OpenListW(Box* box);//�������ݗp�I�[�v�����X�g �����Ƃ��Ď�Ɏ����Ă���box��n��

int CloseListR(Box* box);//�ǂݍ��ݗp�N���[�Y���X�g
int CloseListW(Box* box);//�������ݗp�N���[�Y���X�g�@�����Ƃ���box��n��

int Fchi(int FChi);//���͂���F�l(����)�����o���p�@
int Pazzle(int pazzle_model[3][3]);//���͂����p�Y���̌^�����o��

int CreateBox(Box* nextbox);//�p�Y���̎��̏�Ԃ��쐬���Ă����֐��@�����Ɍ��݂̃p�Y���̏�Ԃ�n��
int MANHATTAN(int start[3][3]);

int main(){

	int start[3][3] = { { 8, 1, 5 }, { 2, 0, 4 }, { 6, 3, 7 } };
	int save[3][3];
	int i, j, no;
	int total = -1;
	int mannhattan;
	Box* box;
	Box* p;//�����Ǝ�Ɏ����Ă����Ȃ��Ƃ����Ȃ���

	MEMORI(box);
	//�v���O�����͂�������
	box->ID=1;
	box->hierarchy = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			box->pazzle_model[i][j] = start[i][j];
		}
	}
	box->FChi = box->hierarchy + MANHATTAN(box->pazzle_model);
	if(MANHATTAN(box->pazzle_model) == 0){
		Fchi(box->FChi);
		Pazzle(box->pazzle_model);
		return 0;
	}
	CloseListW(box);

	p = box;
	while(1){
		CreateBox(box);
		Fchi(box->FChi);
		Pazzle(box->pazzle_model);
		if (MANHATTAN(box->pazzle_model) == 0) {
			Fchi(box->FChi);
			Pazzle(box->pazzle_model);
			return 0;
		}
		CloseListW(box);
		for (i = 0; i < 4; i++) {
			if (box->next[i] != NULL) {
				if (CloseListR(closelistS)== 0){
					OpenListW(box->next[i]);
				}
			}
		}
			box = OpenListR();
	}
	//�����܂�
	free(box);
	getchar();
}

int MANHATTAN(int start[3][3]){
	int i, j, s;
	int mani[9], manj[9];
	int total = 0;
	int subi[9], subj[9];

	//�}���n�b�^�������̌v�Z
	for (s = 1; s < 9; s++){
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (start[i][j] == s){

					//printf("����%d�̏ꏊ %d %d\n", s, i, j);//�l�̍��W�\��
					mani[s] = i;
					manj[s] = j;

				}
			}
		}
	}
	for (s = 1; s < 9; s++){
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (goal[i][j] == s){

					//printf("�ŏI��%d�̏ꏊ %d %d\n", s, i, j);//�l�̍��W�\��
					subi[s] = i;
					subj[s] = j;
				}
			}
		}
	}
	for (s = 1; s < 9; s++){
		total += abs(mani[s] - subi[s]) + abs(manj[s] - subj[s]);
	}

	printf("%d\n", total);

	return total;

}

//�ǂݍ��ݗp�I�[�v�����X�g
Box* OpenListR() {
	List* p = openlist;
	int fnow,fnext;
	List* smallmemo;
	List* b = NULL;
	Box* addr;

	fnow = p->Addr->FChi;
	p = p->next;
	if (p == NULL) {
		addr = openlist->Addr;
		free(openlist);
		openlist = NULL;
		return addr;
	}
	fnext = p->Addr->FChi;
	if (fnow > fnext) {
		smallmemo = p;
	}
	else {
		smallmemo = openlist;
	}
	while (1) {
		fnow = p->Addr->FChi;
		p = p->next;
		if (p->next == NULL) {
			
			p = openlist;
			
			while (1) {
				if (p == smallmemo && b==NULL) {
					openlist = p->next;
					break;
				}
				b = p;
				p = p->next;
				if (p == smallmemo ) {
					b->next = p->next;
					break;
				}
			}
			addr = smallmemo->Addr;
			free(p);
			return addr;
		}
	}
}

//�������ݗp�I�[�v�����X�g �����Ƃ��Ď�Ɏ����Ă���box��n��
int OpenListW(Box* box){
	List* memo;//�������Ă��锠�̃A�h���X�̃���
	if (1==CloseListR(box)) {//����Closelist�ɓ����̂��������ꍇ
		return 0;
	}
	if (openlist == NULL) {
		MEMORI(openlist);
		openlist->Addr = box;
		openlist->next = NULL;
	}

	memo = openlist;
	MEMORI(openlist);
	openlist->Addr = box;
	openlist->next = memo;
	return 0;
}

//�ǂݍ��ݗp�N���[�Y���X�g
int CloseListR(Box* box) {
	List* p = closelist;
	int n, m;
	int counter = 0;

	if (closelist == NULL) {
		return 1;
	}
	while (1) {
		for (n = 0; n < 3; n++) {
			for (m = 0; m < 3; m++) {
				if (p->Addr->pazzle_model[n][m] == box->pazzle_model[n][m]) {
					counter++;
				}
			}
		}
		if (counter == 8) {
			return 1;
		}
		counter = 0;

		p = p->next;
		if (p->next == NULL) {
			return 0;
		}
	}
}

//�������ݗp�N���[�Y���X�g�@�����Ƃ���box��n��
int CloseListW(Box* box){
	List* memo;//�������Ă��锠�̃A�h���X�̃���
	
	if (closelist == NULL) {
		MEMORI(closelist);
		closelist->Addr = box;
		closelist->next = NULL;
		closelistS = closelist;
	}

	memo = closelist;
	MEMORI(closelist);
	closelist->Addr = box;
	closelist->next = memo;
	return 0;
}

//F�l�����o���p�@
int Fchi(int FChi) {
	FILE* outfchi;         // �o�̓X�g���[��

	outfchi = fopen("fchi.txt", "a+");  // �t�@�C�����������ݗp�ɃI�[�v��(�J��)
	if (outfchi == NULL) {          // �I�[�v���Ɏ��s�����ꍇ
		printf("can't open\n");         // �G���[���b�Z�[�W���o����
		exit(1);                         // �ُ�I��
	}

	fprintf(outfchi,"%d\n",FChi); // �t�@�C���ɏ���

	fclose(outfchi);          // �t�@�C�����N���[�Y(����)
	return 0;
}

//�p�Y���̌^�����o��
int Pazzle(int pazzle_model[3][3]){
	FILE* outpazzlemodel;         // �o�̓X�g���[��

	outpazzlemodel = fopen("pazzle.txt", "a+");  // �t�@�C�����������ݗp�ɃI�[�v��(�J��)
	if (outpazzlemodel == NULL) {          // �I�[�v���Ɏ��s�����ꍇ
		printf("can't open\n");         // �G���[���b�Z�[�W���o����
		exit(1);                         // �ُ�I��
	}

	fprintf(outpazzlemodel, "%d %d %d\n%d %d %d\n%d %d %d\n\n",pazzle_model[0][0], pazzle_model[0][1], pazzle_model[0][2], pazzle_model[1][0], pazzle_model[1][1], pazzle_model[1][2], pazzle_model[2][0], pazzle_model[2][1], pazzle_model[2][2]); // �t�@�C���ɏ���

	fclose(outpazzlemodel);          // �t�@�C�����N���[�Y(����)
	return 0;
}

int CreateBox(Box* nextbox) {
	//Box��next���쐬�����Ƃ��ɍ\���̂̒��g�������쐬����悤�ɂ���
	int i, j;
	int q;
	static int ID = 1;
	int nowpazzle[3][3];
	int n, m;

	for (q = 0; q < 4; q++) {
		MEMORI(nextbox->next[q]);

		for (n = 0; n < 3; n++) {
			for (m = 0; m < 3; m++) {
				nowpazzle[n][m] = nextbox->pazzle_model[n][m];
			}
		}
		for (n = 0; n < 3; n++) {
			for (m = 0; m < 3; m++) {
				nextbox->next[q]->pazzle_model[n][m] = nextbox->pazzle_model[n][m];
			}
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (nowpazzle[i][j] == 0) {
				//left
				if (j != 0) {
					//���W�̓���ւ�
					nextbox->next[0]->pazzle_model[i][j] = nextbox->next[0]->pazzle_model[i][j - 1];
					nextbox->next[0]->pazzle_model[i][j - 1] = 0;
				}
				else {
					nextbox->next[0] = NULL;
				}

				//up
				if (i != 0) {
					//���W�̓���ւ�
					nextbox->next[1]->pazzle_model[i][j] = nextbox->next[1]->pazzle_model[i - 1][j];
					nextbox->next[1]->pazzle_model[i - 1][j] = 0;
				}
				else {
					nextbox->next[1] = NULL;
				}

				//down
				if (i != 2) {
					//���W�̓���ւ�
					nextbox->next[2]->pazzle_model[i][j] = nextbox->next[2]->pazzle_model[i + 1][j];
					nextbox->next[2]->pazzle_model[i + 1][j] = 0;
				}
				else {
					nextbox->next[2] = NULL;
				}

				//right
				if (j != 2) {
					//���W�̓���ւ�
					nextbox->next[3]->pazzle_model[i][j] = nextbox->next[3]->pazzle_model[i][j + 1];
					nextbox->next[3]->pazzle_model[i][j + 1] = 0;

				}
				else {
					nextbox->next[3] = NULL;
				}
			}
		}
	}
	printf("\n%d\n", nextbox->hierarchy);
	for (q = 0; q < 4; q++) {
		if (nextbox->next[q] != NULL) {
			nextbox->next[q]->hierarchy = nextbox->hierarchy + 1;
			nextbox->next[q]->ID = ID;
			nextbox->next[q]->FChi = nextbox->next[q]->hierarchy + MANHATTAN(nextbox->next[q]->pazzle_model);
			ID++;
		}
	}
}