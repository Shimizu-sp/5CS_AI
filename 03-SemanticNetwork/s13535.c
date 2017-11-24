#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct _NODE {

	//���O��������i�[�����
	char chara[100];
	//�m�[�h�̐���������
	//1�E�E�E�u�����v��u���v�Ƃ����������������Ƃ�
	//2�E�E�E�u�ċz����v��u��������v�Ƃ����������������Ƃ�
	//3�E�E�E�u���m�}�l�v�Ƃ��������Z�������Ƃ�
	int type;

	//�u�����`����
	//�����m�[�h�ɂȂ���
	struct _NODE *ch;
	//is-a�֌W�Őe�����ǂ�
	struct _NODE *back;
}NODE;

NODE *MakeTree();
int Answer(NODE *node, char str[100]);

int main() {

	char str[101];
	int str_len;
	int flag=0;
	NODE *node;

	//�؂��쐬����
	node = MakeTree();

	while (flag != 2) {
		//�L�[�{�[�h����̓��͂��󂯕t����
		flag = 0;
		while (flag == 0) {
			printf("��������͂��Ă��������i100�����ȓ��j\n�I���Ɠ��͂���ƃv���O�������I�����܂�\n");
			printf("->");
			scanf("%100s", str);
			//�L���b�V���N���A
			scanf("%*[^\n]%*c");
			//�������m�F
			str_len = strlen(str);

			if (str_len == 101) {
				printf("100�����ȓ��œ��͂��Ă�������\n");
			}
			else if (strcmp(str, "�I��") == 0) flag = 2;
			else flag = 1;
		}

		//�؂̒T�����s���A���ʂ�\������
		Answer(node, str);
	}

	return 0;
}

NODE *MakeTree() {
	//is-a�֌W�łȂ����
	NODE *seibutu, *tori, *oumu;
	//������������
	NODE *kokyu, *tubasa, *monomane;
	
	seibutu = (NODE*)malloc(sizeof(NODE));
	tori = (NODE*)malloc(sizeof(NODE));
	oumu = (NODE*)malloc(sizeof(NODE));

	if (seibutu == NULL || tori == NULL || oumu == NULL) {
		printf("�������̊m�ۂɎ��s���܂����i�����m�[�h���j");
		return -1;
	}

	kokyu = (NODE*)malloc(sizeof(NODE));
	tubasa = (NODE*)malloc(sizeof(NODE));
	monomane = (NODE*)malloc(sizeof(NODE));

	if (kokyu == NULL || tubasa == NULL || monomane == NULL) {
		printf("�������̊m�ۂɎ��s���܂����i�����m�[�h���j");
		return -1;
	}
	//�����m�[�h�쐬
	seibutu->type = 1;
	strcpy(seibutu->chara,"����");
	seibutu->ch = kokyu;
	seibutu->back = NULL;

	//�ċz������m�[�h�쐬
	kokyu->type = 2;
	strcpy(kokyu->chara, "�ċz");
	kokyu->ch = NULL;
	kokyu->back = seibutu;

	//���m�[�h�쐬
	tori->type = 1;
	strcpy(tori->chara, "��");
	tori->ch = tubasa;
	tori->back = seibutu;

	//��������m�[�h�쐬
	tubasa->type = 2;
	strcpy(tubasa->chara, "��");
	tubasa->ch = NULL;
	tubasa->back = tori;

	//�I�E���m�[���쐬
	oumu->type = 1;
	strcpy(oumu->chara, "�I�[��");
	oumu->ch = monomane;
	oumu->back = tori;

	//���m�}�l�m�[�h�쐬
	monomane->type = 3;
	strcpy(monomane->chara, "���m�}�l");
	monomane->ch = NULL;
	monomane->back = oumu;

	return oumu;

}

int Answer(NODE *node, char str[100]){
	NODE *start;
	char *subject, *question, *sub;
	char *ret;
	int flag=0;

	if(node==NULL){
		printf("�Ӗ��l�b�g���[�N�����͂���Ă��܂���");
	}

	start = node;

	//���Ǝ��╔���ɕ�����
	subject = _mbstok(str, "��");
	if (subject == NULL) {
		printf("���₪��͂ł��܂���ł���\n");
		return -1;
	}
	question = _mbstok(NULL, "?�H");
	
	//�u����"��"�����́`�v����yes/no�ł͓������Ȃ�����
	//�u�����́`�v����yes/no�œ������鎿��Ɖ���
	if ((ret = strstr(subject, "��")) != NULL) {
		subject = _mbstok(subject, "��");
		sub = _mbstok(NULL, "");

		
		while (flag == 0) {
			if (strcmp(node->chara, subject) == 0) {
				while (1) {
					//���Z�������u�����`��type3�ɕ��ނ��Ă���̂ł���ŕ���
					if (strcmp(sub,"���Z")==0 && node->ch->type == 3) {
						printf("%s\n", node->ch->chara);
						flag = 1;
						break;
					}
					else if(node->back != NULL){
						printf("�T�O�F%s�ł́u%s�v��������Ȃ����ߏ�ʊT�O�F%s���Q�Ƃ��܂�\n",node->chara,sub,node->back->chara);
						node = node->back;
					}
					else {
						printf("�T�O�F%s�ɁA%s�ɂ��Ă̊֌W������܂���\n", subject, sub);
						flag = 1;
						break;
					}
				}
			}
			else {
				if (node->back != NULL) node = node->back;
				else {
					printf("�Ӗ��l�b�g���[�N��%s�����݂��܂���\n", subject);
					flag = 1;
				}
			}
		}
	}
	else {
		while (flag == 0) {
			if (strcmp(node->chara, subject) == 0) {
				while (1) {
					if ((ret = _mbsstr(question, node->ch->chara)) != NULL) {
						printf("Yes\n");
						flag = 1;
						break;
					}
					else if (node->back != NULL) { 
						printf("�T�O�F%s�ł́u%s�v��������Ȃ����ߏ�ʊT�O�F%s���Q�Ƃ��܂�\n", node->chara, question, node->back->chara);
						node = node->back;
					}
					else {
						printf("No\n");
						flag = 1;
						break;
					}
				}
			}
			else {
				if (node->back != NULL) node = node->back;
				else {
					printf("�Ӗ��l�b�g���[�N��%s�����݂��܂���\n", subject);
					flag = 1;
				}
			}
		}
	}

	printf("\n");
	
	return 0;
}