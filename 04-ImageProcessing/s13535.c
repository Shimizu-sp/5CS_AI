#include <stdio.h>
#include <stdlib.h>
#include <Math.h>
#pragma warning(disable : 4996)

//���� �Q�l http://www.umekkii.jp/data/computer/file_format/bitmap.cgi

typedef struct _BMP{

	//�t�@�C���w�b�_
	//�t�@�C���^�C�v�ȊO�͓ǂݎ̂�
	unsigned  bfType;

	//���w�b�_
	//���A�����ȊO�͓ǂݎ̂�
	long biWidth; //�摜�̕�
	long biHeight; //�摜�̍���
	int biBitCount; //�F�r�b�g�� 

	//�p���b�g�f�[�^
	//�ǂݎ̂�

	//�摜�f�[�^
	unsigned int *pixels;

}BMP;

//�v���g�^�C�v�錾
int BmpInit(char *filepass, BMP *bmp);
int SetPixels(BMP *bmp, FILE *fp);
long int SADmatching(BMP *input, BMP *trim, int num);


int main(){

	//�ǂݍ��ݗp�r�b�g�}�b�v�쐬
	BMP *input, *trim;
	int i,q;
	long int sad;
	long int result;
	int x, y;
	int tx, ty;

	//2�p�^�[���̑g�ݍ��킹���s��
	for (q = 0; q < 2; q++) {

		sad = -1;
		result = -1;

		//�������m��
		input = (BMP*)malloc(sizeof(BMP));
		trim = (BMP*)malloc(sizeof(BMP));

		//�t�@�C����ǂݍ���
		switch (q) {
		case 0:
			BmpInit("img_1.bmp", input);
			BmpInit("Timg_1.bmp", trim);
			break;
		case 1:
			BmpInit("img_2.bmp", input);
			BmpInit("Timg_2.bmp", trim);
			break;
		default:
				return -1;
				break;
		}

		printf("�T�����ł��B���΂炭���҂���������");
		//���͉摜�̂��ׂẲ�f������
		for (i = 0; i < input->biHeight*input->biWidth; i++) {
			//�T���i�s�x������
			if (i % (input->biHeight*input->biWidth / 10) == 0) printf("�E");
			//�Ώۂ̉�f�������͈͓��Ȃ�e���v���[�g�}�b�`���O���s��
			tx = i % input->biWidth;
			ty = i / input->biWidth;
			if (tx <= input->biWidth - trim->biWidth && ty <= input->biHeight - trim->biHeight) {
				result = SADmatching(input, trim, i);
				//�}�b�`���O���ʂ̍X�V
				if (sad == -1 || result < sad && result > 0) {
					sad = result;
					x = tx;
					y = ty;
					if (sad == 0) break;
				}
			}
		}

		printf("\n�T�����ʂ�\�����܂�\nx=%d,y=%d sad=%ld\n\n", x, y, sad);

		//���������
		free(input->pixels);
		free(trim->pixels);
		free(input);
		free(trim);

		printf("\n");

	}

	getchar();
}

//�r�b�g�}�b�v��BMP�\���̂ŕۑ�����
int BmpInit(char *filepass, BMP *bmp){

	FILE *fp;
	char c[4];
	int rc;
	int i;

	int color=0;

	bmp->bfType = 0;
	bmp->biBitCount = 0;
	bmp->biHeight = 0;
	bmp->biWidth = 0;

	printf("�t�@�C����:%s �̓ǂݍ��݂��J�n���܂�\n", filepass);

	//�r�b�g�}�b�v�ǂݍ���
	fp = fopen(filepass, "r");
	if (fp == NULL){
		printf("�G���[:�t�@�C�����J���܂���ł���\n");
		return -1;
	}

	//�t�@�C���w�b�_�ǂݍ���
	//�g���q����
	rc = fread(c, 1, 2, fp);
	if (rc == 0){
		printf("�G���[�F�ǂݍ��݃f�[�^������܂���\n");
		return -1;
	}
	bmp->bfType = 0;
	for (i = 0; i < 2; i++){
		bmp->bfType = (bmp->bfType << (i*8)) | c[i];
	}

	printf("%x\n", bmp->bfType);
	if (bmp->bfType != 0x424d){
		printf("�G���[�F�r�b�g�}�b�v�ȊO�����͂���܂���\n");
		return -1;
	}
	//�ȉ��ǂݎ̂āi�t�@�C���T�C�Y�A�\��̈�A�t�@�C���擪����摜�f�[�^�܂ł̃I�t�Z�b�g�j
	for (i = 0; i < 3; i++){
		rc = fread(c, 1, 4, fp);
		if (rc == 0){
			printf("�G���[�F�ǂݍ��݃f�[�^������܂���\n");
			return -1;
		}
	}
	
	//���w�b�_�ǂݍ���
	//�ǂݎ̂āi���w�b�_�T�C�Y�j
	rc = fread(c, 1, 4, fp);
	if (rc == 0){
		printf("�G���[�F�ǂݍ��݃f�[�^������܂���\n");
		return -1;
	}
	//�r�b�g�}�b�v�̕��ƍ������擾
	rc = fread(&bmp->biWidth, 1, 4, fp);
	if (rc == 0){
		printf("�G���[�F�ǂݍ��݃f�[�^������܂���\n");
		return -1;
	}
	rc = fread(&bmp->biHeight, 1, 4, fp);
	if (rc == 0){
		printf("�G���[�F�ǂݍ��݃f�[�^������܂���\n");
		return -1;
	}

	printf("���F%ld �����F%ld\n", bmp->biWidth, bmp->biHeight);
	
	rc = fread(c, 1, 2, fp);
	if (rc == 0) {
		printf("�G���[�F�ǂݍ��݃f�[�^������܂���\n");
		return -1;
	}

	//�F�r�b�g�����擾
	rc = fread(&bmp->biBitCount, 1, 2, fp);
	if (rc == 0) {
		printf("�G���[�F�ǂݍ��݃f�[�^������܂���\n");
		return -1;
	}
	if (bmp->biBitCount != 24) {
		printf("�r�b�g�}�b�v�̐F�r�b�g����24�ł͂���܂���\n");
		return -1;
	}

	printf("�F�r�b�g��:%d\n", bmp->biBitCount);

	//�ȉ��ǂݎ̂�
	for (i = 0; i < 6; i++) {
		rc = fread(c, 1, 4, fp);
		if (rc == 0) {
			printf("�G���[�F�ǂݍ��݃f�[�^������܂���\n");
			return -1;
		}
	}

	//�p���b�g�f�[�^�ǂݎ̂�
	//����͐F�r�b�g����24�r�b�g�݂̂�ǂݍ���ł��邽�ߏ������΂�(�p���b�g�f�[�^�����݂��Ȃ�����)
	/*
	for (i = 0; i < 4; i++) {
		rc = fread(c, 1, 1, fp);
		if (rc == 0) {
			printf("�G���[�F�ǂݍ��݃f�[�^������܂���\n");
			return -1;
		}
			
	}*/

	//�摜�f�[�^�ǂݍ���
	SetPixels(bmp, fp);

	rc = fread(c, 1, 1, fp);
	if (rc != 0) {
		printf("�G���[�F�f�[�^���܂��c���Ă��܂�\n\n");
		return -1;
	}

	fclose(fp);
}

//�摜�f�[�^���́@
int SetPixels(BMP *bmp, FILE *fp){

	int color = 0;
	int rc = 0;
	int i = 0, n = 0;;

	//�Ώۉ�f�̕��A����
	int w, h;
	//�r�b�g�}�b�v�w�b�_�̋l�ߕ�
	int pad;

	//��f�l��ۑ�����z����쐬
	bmp->pixels = (int*)malloc((bmp->biHeight*bmp->biWidth) * sizeof(int));
	
	//�l�ߕ��̕����v�Z(�r�b�g�}�b�v�̕���4�̔{���ɂ���)
	pad = bmp->biWidth % 4;
	if (pad != 0) pad = 4 - pad;

	//��f�l��ǂݍ���
	for (h = bmp->biHeight - 1; h >= 0; h--) {
		for(w = 0; w < bmp->biWidth; w++) {
			rc = fread(&color, 1, 3, fp);
			if (rc != 0) {
				bmp->pixels[h*bmp->biWidth+w] = color;
			}
			else {
				printf("�G���[�F�ǂݍ��݃f�[�^������܂��� ��%d����%d\n", w, h);
				return -1;
			}
		}
		//�l�ߕ��̕���ǂݎ̂Ă�
		for (n = pad; n > 0; n--) {
			rc = fread(&color, 1, 3, fp);
			if (rc == 0) {
				printf("�G���[�F�ǂݍ��݃f�[�^������܂��� ��%d����%d\n", w, h);
				return -1;
			}
		}
	}

	printf("����ɉ摜�f�[�^��ǂݍ��݂܂���\n\n");

	return 0;

}

//SAD�}�b�`���O(��f�l�̍����̐�Βl�̘a���v�Z)
long int SADmatching(BMP *input, BMP *trim, int num) {
	int x, y;
	int w, h;

	long int sad=0;
	int result;

	//��f�l�擾�p
	int r=0x000011;
	//����̃r�b�g�}�b�v��r=g=b���������ߊ���
	//int g=0x001100;
	//int b=0x110000;

	//�Ώۂ̉�f�l
	int Icolor,Tcolor;

	//���������f�l�̂�����v�Z
	x = num % input->biWidth;
	y = num / input->biWidth;
	
	//�g���~���O�摜�̂��ׂẲ�f�l���v�Z
	for (h = 0; h < trim->biHeight; h++) {
		for (w = 0; w < trim->biWidth; w++) {

			//�r�b�g���Z�ɂ���f�l���擾
			Icolor = input->pixels[((y + h)*input->biWidth) + (x + w)] & r;
			Tcolor = trim->pixels[(h*trim->biWidth) + w] & r;

			//result = abs(Icolor - Tcolor);
			sad += abs(Icolor - Tcolor);
			//sad���傫���Ȃ肷�����璆�~
			if (sad < 0) return -1;
		}
	}

	return sad;
}
