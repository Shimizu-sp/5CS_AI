#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


//����������X�g�ŕ\��
typedef struct _Data{
	char c;		//����
	int x;		//�����R�[�h
	int type;	//�^�O�@�A���t�@�x�b�g�Ȃ�1�A�L���Ȃ�0

	//�P�������X�g
	struct _Data *next;
}Data;


//���͏�ԂƏI�����
char start[11] = "a*b-cd/e+fg";
char goal[11] = "gfedcba+-*/";


//�v���_�N�V����������
//R1�E�E�E�����R�[�h�̒l��0x41�ȏ�0x5a�ȉ��܂��́A0x61�ȏ�0x7a�ȉ��Ȃ炻�̕����̓A���t�@�x�b�g
//R2�E�E�E�����R�[�h�̒l��R1�ɖ����Ȃ��ꍇ�A���̕����͋L��
//R3�E�E�E�ׂ荇����2�̕������L���ƃA���t�@�x�b�g�Ȃ�A���t�@�x�b�g��O�Ɏ����Ă���
//R4�E�E�E�ׂ荇����2�̕������ǂ�����A���t�@�x�b�g�Ȃ當���R�[�h�̒l���r���A�傫���ق���O�Ɏ����Ă���
//R5�E�E�E�ׂ荇����2�̕�����̑O�̕�����'*'�̂Ƃ��A���̕�����'/'�łȂ��Ȃ�'*'�����Ɏ����Ă���
//R6�E�E�E���̕�����'*'�łȂ��Ƃ��A�ׂ荇����2�̕������ǂ�����L���Ȃ當���R�[�h�̒l���r���A�������ق���O�Ɏ����Ă���


//�֐��v���g�^�C�v�錾
int MainSearch(Data *data);
int Add(Data *data, char c);
int ListChange(Data *data);
int PM_R1R2(Data *data);
int PM_R3(Data *data);
int PM_R4(Data *data);
int PM_R5(Data *data);
int PM_R6(Data *data);
void ShowString(Data *data);


int main(){

	int i;
	Data *data, *data_s;

	//���X�g�̐擪���쐬
	data = (Data*)malloc(sizeof(Data));
	data->c = 'S';
	data->x = -1;
	data->type = -1;
	data->next = NULL;

	//���X�g�̐擪���L��
	data_s = data;

	//��������
	for (i = 0; i < 11;i++){
		Add(data, start[i]);
		data = data->next;
		PM_R1R2(data);
	}

	//���C�����[�v
	MainSearch(data_s);

	getchar();

	return 0;
}

//�����ɂ̓��X�g�̐擪��n���K�v������
int MainSearch(Data *data){
	int i;
	int count=0;

	Data *data_s;

	data_s = data;

	//���݂̏�Ԃ�\��
	ShowString(data_s);

	//���C���T��
	while (1){
		//���X�g�̐擪��
		data = data_s;
		//���X�g���T��
		while (1) {
			if (data->x > 0){
				//PM�ɂЂƂł����Ă͂܂���̂�����ΓK�p�����̂��A������(���X�g)�̐擪�ɖ߂�
				if (PM_R3(data) == 1)break;
				if (PM_R4(data) == 1)break;
				if (PM_R5(data) == 1)break;
				if (PM_R6(data) == 1)break;
			}
			data = data->next;
			if (data->next == NULL) break;
		}

		//���݂̏�Ԃ�\��
		ShowString(data_s);

		//���X�g�̐擪��
		data = data_s;
		//�S�[����ԂƓ��l�̕��я��̎��A���ёւ����I������
		count = 0;
		for (i = 0; i < 11; i++){
			data = data->next;
			if (data->c == goal[i]) count++;
		}
		if (count == 11) break;	
	}
}

//���X�g�ɒǉ�����
int Add(Data *data, char c){

	Data *input;

	input = (Data*)malloc(sizeof(Data));

	input->x = c;
	input->c = c;
	input->next = NULL;

	data->next = input;

	return 0;
}

//���X�g����Q�̃m�[�h����ёւ���
//���ёւ������Q�̃m�[�h�̂����A�O�̃m�[�h�������Ƃ���
int ListChange(Data *data){
	Data save; //�m�[�h��u�������邽�߂Ɏg��

	if (data == NULL || data->next == NULL){
		printf("error: ListChange �s���Ȓl�����͂���܂���");
		return -1;
	}

	//�ꎞ�I�ɕۑ�
	save.c = data->next->c;
	save.x = data->next->x;
	save.type = data->next->type;
	save.next = data->next;

	//�f�[�^�̓���ւ����
	data->next->c = data->c;
	data->next->x = data->x;
	data->next->type = data->type;
	data->next->next = data->next->next;

	data->c = save.c;
	data->x = save.x;
	data->type = save.type;
	data->next = save.next;

	return 0;
}

//�v���_�N�V�����������̓��e��K�p����

//R1�E�E�E�����R�[�h�̒l��0x41�ȏ�0x5a�ȉ��܂��́A0x61�ȏ�0x7a�ȉ��Ȃ炻�̕����̓A���t�@�x�b�g
//R2�E�E�E�����R�[�h�̒l��R1�ɖ����Ȃ��ꍇ�A���̕����͋L��
int PM_R1R2(Data *data){
	if (data == NULL){
		printf("error: PM_R1R2 �s���Ȓl�����͂���܂���");
		return -1;
	}
	if (data->x >= 0x41 && data->x <= 0x5a || data->x >= 0x61 && data->x <= 0x7a) data->type = 1;
	else data->type = 0;

	return 0;
}

//�����𖞂����A���[����K�p������1��Ԃ�
//R3�E�E�E�ׂ荇����2�̕������L���ƃA���t�@�x�b�g�Ȃ�A���t�@�x�b�g��O�Ɏ����Ă���
int PM_R3(Data *data){
	if (data == NULL || data->next == NULL){
		printf("error: PM_R3 �s���Ȓl�����͂���܂���");
		return -1;
	}

	if (data->type == 0 && data->next->type == 1) {
		ListChange(data);
		return 1;
	}

	return 0;
}

//�����𖞂����A���[����K�p������1��Ԃ�
//R4�E�E�E�ׂ荇����2�̕������ǂ�����A���t�@�x�b�g�Ȃ當���R�[�h�̒l���r���A�傫���ق���O�Ɏ����Ă���
int PM_R4(Data *data){
	if (data == NULL || data->next == NULL){
		printf("error: PM_R4 �s���Ȓl�����͂���܂���");
		return -1;
	}

	if (data->type == 1 && data->next->type == 1 && data->x < data->next->x) {
		ListChange(data);
		return 1;
	}

	return 0;
}

//�����𖞂����A���[����K�p������1��Ԃ�
//R5�E�E�E�ׂ荇����2�̕�����̑O�̕�����'*'�̂Ƃ��A���̕�����'/'�łȂ��Ȃ�'*'�����Ɏ����Ă���
int PM_R5(Data *data){
	if (data == NULL || data->next == NULL){
		printf("error: PM_R5 �s���Ȓl�����͂���܂���");
		return -1;
	}

	if (data->c == '*' && data->next->c != '/') {
		ListChange(data);
		return 1;
	}

	return 0;
}

//�����𖞂����A���[����K�p������1��Ԃ�
//R6�E�E�E���̕�����'*'�łȂ��Ƃ��A�ׂ荇����2�̕������ǂ�����L���Ȃ當���R�[�h�̒l���r���A�������ق���O�Ɏ����Ă���
int PM_R6(Data *data){
	if (data == NULL || data->next == NULL){
		printf("error: PM_R6 �s���Ȓl�����͂���܂���");
		return -1;
	}

	if (data->type == 0 && data->next->type == 0 && data->x > data->next->x && data->next->c != '*') {
		ListChange(data);
		return 1;
	}

	return 0;
}

//�������\������ �����ɂ̓��X�g�̐擪��n���K�v����
void ShowString(Data *data){

	while (1){
		if (data->x > 0) printf("%c", data->c);
		if (data->next == NULL) break;
		data = data->next;
	}

	printf("\n");
}