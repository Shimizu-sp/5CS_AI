/*
**What is this programm:Template Matching
**Author:Daisuke Kuwahara
**Mail:abcexe1@gmail.com
**Operating environment:
	-OS:Windows 10 64bit Pro
	-IDE:Visual studio 2012
**Language:C
*/

#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�}�N����`��

//�}�N���֐���`��

//�񋓑̐錾��
//Winodws��OS2���������񋓑�
enum Format{
	OS2,
	Windows
};

//�\���̐錾��

//Bitmap File Header�p�\����
struct file_header{
	unsigned int bfType;			//�t�@�C���^�C�v
	unsigned long bfSize;			//�t�@�C���T�C�Y[byte]
	unsigned int bfReserved1;		//�\��̈�P
	unsigned int bfReserved2;		//�\��̈�Q
	unsigned long bfOffBit;			//�t�@�C���擪����摜�f�[�^�܂ł̃I�t�Z�b�g[byte]	
};

//Windows�p���w�b�_�p�\����
struct information_header_Windows{
	unsigned long biSize;			//���w�b�_�T�C�Y[byte]
	long biWidth;					//�摜�̕�[�s�N�Z��]
	long biHeight;					//�摜�̍���[�s�N�Z��]
	unsigned int biPlanes;			//�v���[����
	unsigned int biBitCount;		//�F�r�b�g��[bit]
	unsigned long biCompression;	//���k�`��
	unsigned long biSizeImage;		//�摜�f�[�^�T�C�Y[byte]	
	long biXPixPerMeter;			//�����𑜓x[dot/m]
	long biYPixPerMeter;			//�����𑜓x[dot/m]
	unsigned long biClrUsed;		//�i�[�p���b�g��[�g�p�F��]
	unsigned long biCirImportant;	//�d�v�F��
};

//OS2�p���w�b�_�p�\����

struct information_header_OS2{
	unsigned long bcSize;			//���w�b�_�T�C�Y[byte]
	int bcWidth;					//�摜�̕�[�s�N�Z��]
	int bcHeight;					//�摜�̍���[�s�N�Z��]
	unsigned int bcPlanes;			//�v���[����
	unsigned int bcBitCount;		//�F�r�b�g��[bit]
};

//Windows�p�p���b�g�f�[�^
struct palette_data_Windows{
	unsigned char rgbBlue;			//��
	unsigned char rgbGreen;			//��
	unsigned char rgbRed;			//��
	unsigned char rgbReserved;		//�\��̈�
};

//OS2�p�p���b�g�f�[�^
struct palette_data_OS2{
	unsigned char rgbBlue;			//��
	unsigned char rgbGreen;			//��
	unsigned char rgbRed;			//��
};

//��f�f�[�^
typedef struct pix_data{
	unsigned char rgbBlue;			//��
	unsigned char rgbGreen;			//��
	unsigned char rgbRed;			//��
	unsigned char rgbReserved;		//�\��̈�
} RGB;

//BMP�t�@�C���f�[�^���i�[����\����
typedef struct def_BMP{
	enum Format format;							//Winodws�K�i��OS2�K�i���������񋓑�
	struct file_header fh;						//BMP�̃t�@�C���w�b�_
	struct information_header_Windows ih_w;		//Winodws�̏ꍇ�̏��w�b�_
	struct information_header_OS2 ih_o;			//OS2�̏ꍇ�̏��w�b�_
	struct palette_data_Windows *pd_w;			//Winodws�̏ꍇ�̃p���b�g�f�[�^
	struct palette_data_OS2 *pd_o;				//OS2�̏ꍇ�̃p���b�g�f�[�^
	unsigned char **def_color_data;				//BMP�t�@�C�����̉�f�z��
	RGB **color_data;							//�l�Ԃ��F�����₷���cx���̉�f�z��
	size_t palette_size;						//�p���b�g�f�[�^�̔z�񐔂��i�[����
	size_t def_color_data_row_size;				//BMP���̉摜�f�[�^�̍s�T�C�Y[byte]
	size_t def_color_data_calumn_size;			//BMP���̉摜�f�[�^�̏c�T�C�Y[byte]
	size_t color_data_row_size;				//�l�Ԃ��F�����₷���摜�f�[�^�̍s�T�C�Y[byte]
	size_t color_data_calumn_size;			//�l�Ԃ��F�����₷���摜�f�[�^�̏c�T�C�Y[byte]
} BMP;

//�֐���`��

/*
BMP��ǂݍ��ފ֐�
�G���[���ɂ�NULL��Ԃ�
*/
BMP* ReadBMP(const char* filename){
	BMP* bmp;
	FILE* fp;
	size_t s;
	size_t t;

	int bmp_type=0;//BMP���{�g���A�b�v�ŕۑ�����Ă���ꍇ1�ɂȂ�t���O

	//BMP�̍\���̂��m��
	if(NULL==(bmp=(BMP*)malloc(sizeof(BMP)))){
		perror("malloc:BMP");
		return 0;
	}

	//�\���̓��̒l��������
	memset(bmp,0,sizeof(BMP));

	//�t�@�C���̓ǂݍ���
	if (NULL == (fp = fopen(filename, "r"))){ 
		perror("Readbmp->fopen");
		return 0;
	}

	//�t�@�C���w�b�_�̓ǂݍ���
	fread(&(bmp->fh.bfType), 2, 1, fp);

	//BMP�t�@�C���ł��邩���m�F(bfType="BM"�����m�F)
	if (bmp->fh.bfType != 0x4d42){
		perror("Not BMP file");
		return 0;
	}

	fread(&(bmp->fh.bfSize), 4, 1, fp);
	fread(&(bmp->fh.bfReserved1), 2, 1, fp);
	fread(&(bmp->fh.bfReserved2), 2, 1, fp);
	fread(&(bmp->fh.bfOffBit), 4, 1, fp);

	//���w�b�_�̓ǂݍ���
	fread(&(bmp->ih_o.bcSize), 4, 1, fp);

	//OS2�K�i��Windows�K�i���𔻒f
	if (bmp->ih_o.bcSize == 12){
		//OS2
		bmp->format = OS2;
		fread(&(bmp->ih_o.bcWidth), 2, 1, fp);
		fread(&(bmp->ih_o.bcHeight), 2, 1, fp);
		fread(&(bmp->ih_o.bcPlanes), 2, 1, fp);
		fread(&(bmp->ih_o.bcBitCount), 2, 1, fp);

		//�{�g���A�b�v�ł��邩�𔻒�
		if(bmp->ih_o.bcHeight>0){
			//�����������@-> �{�g���A�b�v�ł���
			bmp_type=1;
		}
	}
	else if (bmp->ih_o.bcSize == 40){
		//Winodws
		bmp->format = Windows;
		bmp->ih_w.biSize = 40;
		fread(&(bmp->ih_w.biWidth), 4, 1, fp);
		fread(&(bmp->ih_w.biHeight), 4, 1, fp);
		fread(&(bmp->ih_w.biPlanes), 2, 1, fp);
		fread(&(bmp->ih_w.biBitCount), 2, 1, fp);
		fread(&(bmp->ih_w.biCompression), 4, 1, fp);
		fread(&(bmp->ih_w.biSizeImage), 4, 1, fp);
		fread(&(bmp->ih_w.biXPixPerMeter), 4, 1, fp);
		fread(&(bmp->ih_w.biYPixPerMeter), 4, 1, fp);
		fread(&(bmp->ih_w.biClrUsed), 4, 1, fp);
		fread(&(bmp->ih_w.biCirImportant), 4, 1, fp);

		//�{�g���A�b�v�ł��邩�𔻒�
		if(bmp->ih_w.biHeight>0){
			//�����������@-> �{�g���A�b�v�ł���
			bmp_type=1;
		}
	}
	else{
		perror("Unknown BMP format");
		return 0;
	}

	//�p���b�g�f�[�^�̓ǂݍ���
	if (bmp->format == OS2){
		switch (bmp->ih_o.bcBitCount){
		case 1:
			perror("�p���b�g�T�C�Y=1�͖��Ή��ł��D");
			return 0;
			/*
			//�p���b�g�f�[�^�̃������m��
			bmp->palette_size=2;
			if(NULL==(bmp->pd_o=(struct palette_data_OS2*)malloc(sizeof(struct palette_data_OS2)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//�p���b�g�f�[�^�̓ǂݍ���
			for(s=0;s<bmp->palette_size;s++){
				fread(&(bmp->pd_o[s].rgbBlue), 1, 1, fp);
				fread(&(bmp->pd_o[s].rgbGreen), 1, 1, fp);
				fread(&(bmp->pd_o[s].rgbRed), 1, 1, fp);
			}
			*/
			break;
		case 4:
			perror("�p���b�g�T�C�Y=4�͖��Ή��ł��D");
			return 0;
			/*
			//�p���b�g�f�[�^�̃������m��
			bmp->palette_size=16;
			if(NULL==(bmp->pd_o=(struct palette_data_OS2*)malloc(sizeof(struct palette_data_OS2)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//�p���b�g�f�[�^�̓ǂݍ���
			for(s=0;s<bmp->palette_size;s++){
				fread(&(bmp->pd_o[s].rgbBlue), 1, 1, fp);
				fread(&(bmp->pd_o[s].rgbGreen), 1, 1, fp);
				fread(&(bmp->pd_o[s].rgbRed), 1, 1, fp);
			}
			*/
			break;
		case 8:
			//�p���b�g�f�[�^�̃������m��
			bmp->palette_size=256;
			if(NULL==(bmp->pd_o=(struct palette_data_OS2*)malloc(sizeof(struct palette_data_OS2)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//�p���b�g�f�[�^�̓ǂݍ���
			for(s=0;s<bmp->palette_size;s++){
				fread(&(bmp->pd_o[s].rgbBlue), 1, 1, fp);
				fread(&(bmp->pd_o[s].rgbGreen), 1, 1, fp);
				fread(&(bmp->pd_o[s].rgbRed), 1, 1, fp);
			}

			break;
		}
	}
	else if (bmp->format == Windows){
		switch (bmp->ih_w.biBitCount){
		case 1:
			perror("�p���b�g�T�C�Y=1�͖��Ή��ł��D");
			return 0;
			/*
			//�p���b�g�f�[�^�̃������m��
			bmp->palette_size=2;
			if(NULL==(bmp->pd_w=(struct palette_data_Windows*)malloc(sizeof(struct palette_data_Windows)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//�p���b�g�f�[�^�̓ǂݍ���
			for(s=0;s<bmp->palette_size;s++){
				fread(&(bmp->pd_w[s].rgbBlue), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbGreen), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbRed), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbReserved), 1, 1, fp);
			}
			*/
			break;
		case 4:
			perror("�p���b�g�T�C�Y=4�͖��Ή��ł��D");
			return 0;
			/*
			//�p���b�g�f�[�^�̃������m��
			bmp->palette_size=16;
			if(NULL==(bmp->pd_w=(struct palette_data_Windows*)malloc(sizeof(struct palette_data_Windows)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//�p���b�g�f�[�^�̓ǂݍ���
			for(s=0;s<bmp->palette_size;s++){
				fread(&(bmp->pd_w[s].rgbBlue), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbGreen), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbRed), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbReserved), 1, 1, fp);
			}

			break;
			*/
		case 8:
			//�p���b�g�f�[�^�̃������m��
			bmp->palette_size=256;
			if(NULL==(bmp->pd_w=(struct palette_data_Windows*)malloc(sizeof(struct palette_data_Windows)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//�p���b�g�f�[�^�̓ǂݍ���
			for(s=0;s<bmp->palette_size;s++){
				fread(&(bmp->pd_w[s].rgbBlue), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbGreen), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbRed), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbReserved), 1, 1, fp);
			}

			break;
		}
	}

	//�摜�f�[�^�̓ǂݍ���
	//BitCount��8,24,32�ȊO�̏ꍇ�͌���ł͂�������ɐi�ނ��Ƃ͂���܂���D

	//�摜�f�[�^�̊i�[�T�C�Y����
	if(bmp->format==Windows){

		//�p���b�g�f�[�^����̏ꍇ
		if(bmp->ih_w.biBitCount==1 || bmp->ih_w.biBitCount==4 || bmp->ih_w.biBitCount==8){
			unsigned int real_Width_size=bmp->ih_w.biWidth*bmp->ih_w.biBitCount;	//���ۂ̉摜�f�[�^�̃T�C�Y[bit]
			unsigned int padding=32-((bmp->ih_w.biWidth*bmp->ih_w.biBitCount)%32);		//�l�ߕ��̃T�C�Y[bit]

			//�l�ߕ��T�C�Y��32bit�ɂȂ��Ă��܂��ꍇ�́C32bit=4byte�Ȃ̂ŋl�߂Ȃ��Ă���
			if(padding==32) padding=0;

			//�\���̂ɁC�摜�f�[�^�̔z��T�C�Y���i�[
			bmp->def_color_data_row_size=(real_Width_size+padding)/8;//0�l�߂��ꂽ����
			bmp->def_color_data_calumn_size=bmp->ih_w.biHeight;
			bmp->color_data_row_size=bmp->ih_w.biWidth;
			bmp->color_data_calumn_size=bmp->ih_w.biHeight;

			//�{�g���A�b�v�łȂ��ꍇ�CbiHeight���}�C�i�X�Ȃ̂ŁC�v���X�ɒ���
			if(!bmp_type){
				bmp->def_color_data_calumn_size*=-1;
				bmp->color_data_calumn_size*=-1;
			}

			//�摜�f�[�^�p�̃������m��
			if(NULL==(bmp->def_color_data=(unsigned char**)malloc(sizeof(unsigned char*)*(bmp->def_color_data_calumn_size+1)))){
				perror("RGBRead->malloc->unsigned char**");
				return 0;
			}
			for(s=0;s<bmp->def_color_data_calumn_size;s++){
				if(NULL==(bmp->def_color_data[s]=(unsigned char*)malloc(sizeof(unsigned char)*(bmp->def_color_data_row_size+1)))){
					perror("RGBRead->malloc->unsigned char*");
					return 0;
				}
			}

			//�摜�f�[�^��RGB�l�ɕϊ��������p�̃������m��
			if(NULL==(bmp->color_data=(RGB**)malloc(sizeof(RGB*)*(bmp->color_data_calumn_size+1)))){
				perror("RGBRead->malloc->RGB**");
				return 0;
			}
			for(s=0;s<bmp->color_data_calumn_size;s++){
				if(NULL==(bmp->color_data[s]=(RGB*)malloc(sizeof(RGB)*(bmp->color_data_row_size+1)))){
					perror("RGBRead->malloc->RGB*");
					return 0;
				}
			}

			//�摜�f�[�^�̎擾(8bit�̂݁j
			for(t=0;t<bmp->def_color_data_calumn_size;t++){
				for(s=0;s<bmp->def_color_data_row_size;s++){
					fread(&(bmp->def_color_data[t][s]), 1, 1, fp);
				}
			}

			//�p���b�h�f�[�^�ɏ]���CRGB�l�ɕϊ�
			for(t=0;t<bmp->color_data_calumn_size;t++){
				for(s=0;s<bmp->color_data_row_size;s++){
					//RGB�f�[�^�̊i�[�\��.�F�̎�� = �p���b�g�f�[�^�z��[�摜�f�[�^].�F�̎��
					bmp->color_data[t][s].rgbBlue=bmp->pd_w[bmp->def_color_data[t][s]].rgbBlue;
					bmp->color_data[t][s].rgbGreen=bmp->pd_w[bmp->def_color_data[t][s]].rgbGreen;
					bmp->color_data[t][s].rgbRed=bmp->pd_w[bmp->def_color_data[t][s]].rgbRed;
				}
			}

		}//�p���b�g�f�[�^�Ȃ��̏ꍇ
		else{
			unsigned int real_Width_size=bmp->ih_w.biWidth*bmp->ih_w.biBitCount;	//���ۂ̉摜�f�[�^�̃T�C�Y[bit]
			unsigned int padding=32-((bmp->ih_w.biWidth*bmp->ih_w.biBitCount)%32);	//�l�ߕ��̃T�C�Y[bit]

			//�l�ߕ��T�C�Y��32bit�ɂȂ��Ă��܂��ꍇ�́C32bit=4byte�Ȃ̂ŋl�߂Ȃ��Ă���
			if(padding==32) padding=0;

			//�\���̂ɁC�摜�f�[�^�̔z��T�C�Y���i�[
			bmp->def_color_data_row_size=(real_Width_size+padding)/8;//0�l�߂��ꂽ����
			bmp->def_color_data_calumn_size=bmp->ih_w.biHeight;
			bmp->color_data_row_size=bmp->ih_w.biWidth;
			bmp->color_data_calumn_size=bmp->ih_w.biHeight;

			//�{�g���A�b�v�łȂ��ꍇ�CbiHeight���}�C�i�X�Ȃ̂ŁC�v���X�ɒ���
			if(!bmp_type){
				bmp->def_color_data_calumn_size*=-1;
				bmp->color_data_calumn_size*=-1;
			}

			//�摜�f�[�^��RGB�l�ɕϊ��������p�̃������m��
			if(NULL==(bmp->color_data=(RGB**)malloc(sizeof(RGB*)*(bmp->color_data_calumn_size+1)))){
				perror("RGBRead->malloc->RGB**");
				return 0;
			}
			for(s=0;s<bmp->color_data_calumn_size;s++){
				if(NULL==(bmp->color_data[s]=(RGB*)malloc(sizeof(RGB)*(bmp->color_data_row_size+1)))){
					perror("RGBRead->malloc->RGB*");
					return 0;
				}
			}

			//�摜�f�[�^�̎擾
			for(t=0;t<bmp->def_color_data_calumn_size;t++){
				unsigned char delete_data;
				
				for(s=0;s<(bmp->color_data_row_size);s++){
					fread(&(bmp->color_data[t][s].rgbBlue), 1, 1, fp);
					fread(&(bmp->color_data[t][s].rgbGreen), 1, 1, fp);
					fread(&(bmp->color_data[t][s].rgbRed), 1, 1, fp);

					//�\��̈��bitCount=32�Ȃ�ǂݍ��݁C�����łȂ��ꍇ�ɂ�0��������D
					if(bmp->ih_w.biBitCount==32) fread(&(bmp->color_data[t][s].rgbReserved), 1, 1, fp);
					bmp->color_data[t][s].rgbReserved=0;
				}

				//0�l�ߕ�����ǂݎ̂�
				for(s=0;s<(padding/8);s++) fread(&delete_data,1,1,fp);
			}

		}
			
	}
	else if(bmp->format==OS2){
		//�p���b�g�f�[�^����̏ꍇ
		if(bmp->ih_o.bcBitCount==1 || bmp->ih_o.bcBitCount==4 || bmp->ih_o.bcBitCount==8){
			unsigned int real_Width_size=bmp->ih_o.bcWidth*bmp->ih_o.bcBitCount;	//���ۂ̉摜�f�[�^�̃T�C�Y[bit]
			unsigned int padding=32-((bmp->ih_o.bcWidth*bmp->ih_o.bcBitCount)%32);	//�l�ߕ��̃T�C�Y[bit]

			//�l�ߕ��T�C�Y��32bit�ɂȂ��Ă��܂��ꍇ�́C32bit=4byte�Ȃ̂ŋl�߂Ȃ��Ă���
			if(padding==32) padding=0;

			//�\���̂ɁC�摜�f�[�^�̔z��T�C�Y���i�[
			bmp->def_color_data_row_size=(real_Width_size+padding)/8;//0�l�߂��ꂽ����
			bmp->def_color_data_calumn_size=bmp->ih_o.bcHeight;
			bmp->color_data_row_size=bmp->ih_o.bcWidth;
			bmp->color_data_calumn_size=bmp->ih_o.bcHeight;

			//�{�g���A�b�v�łȂ��ꍇ�CbcHeight���}�C�i�X�Ȃ̂ŁC�v���X�ɒ���
			if(!bmp_type){
				bmp->def_color_data_calumn_size*=-1;
				bmp->color_data_calumn_size*=-1;
			}

			//�摜�f�[�^�p�̃������m��
			if(NULL==(bmp->def_color_data=(unsigned char**)malloc(sizeof(unsigned char*)*(bmp->def_color_data_calumn_size+1)))){
				perror("RGBRead->malloc->unsigned char**");
				return 0;
			}
			for(s=0;s<bmp->def_color_data_calumn_size;s++){
				if(NULL==(bmp->def_color_data[s]=(unsigned char*)malloc(sizeof(unsigned char)*(bmp->def_color_data_row_size+1)))){
					perror("RGBRead->malloc->unsigned char*");
					return 0;
				}
			}

			//�摜�f�[�^��RGB�l�ɕϊ��������p�̃������m��
			if(NULL==(bmp->color_data=(RGB**)malloc(sizeof(RGB*)*(bmp->color_data_calumn_size+1)))){
				perror("RGBRead->malloc->RGB**");
				return 0;
			}
			for(s=0;s<bmp->color_data_calumn_size;s++){
				if(NULL==(bmp->color_data[s]=(RGB*)malloc(sizeof(RGB)*(bmp->color_data_row_size+1)))){
					perror("RGBRead->malloc->RGB*");
					return 0;
				}
			}

			//�摜�f�[�^�̎擾(8bit�̂݁j
			for(t=0;t<bmp->def_color_data_calumn_size;t++){
				for(s=0;s<bmp->def_color_data_row_size;s++){
					fread(&(bmp->def_color_data[t][s]), 1, 1, fp);
				}
			}

			//�p���b�h�f�[�^�ɏ]���CRGB�l�ɕϊ�
			for(t=0;t<bmp->color_data_calumn_size;t++){
				for(s=0;s<bmp->color_data_row_size;s++){
					//RGB�f�[�^�̊i�[�\��.�F�̎�� = �p���b�g�f�[�^�z��[�摜�f�[�^].�F�̎��
					bmp->color_data[t][s].rgbBlue=bmp->pd_w[bmp->def_color_data[t][s]].rgbBlue;
					bmp->color_data[t][s].rgbGreen=bmp->pd_w[bmp->def_color_data[t][s]].rgbGreen;
					bmp->color_data[t][s].rgbRed=bmp->pd_w[bmp->def_color_data[t][s]].rgbRed;
				}
			}

		}//�p���b�g�f�[�^�Ȃ��̏ꍇ
		else{
			unsigned int real_Width_size=bmp->ih_o.bcWidth*bmp->ih_o.bcBitCount;	//���ۂ̉摜�f�[�^�̃T�C�Y[bit]
			unsigned int padding=32-((bmp->ih_o.bcWidth*bmp->ih_o.bcBitCount)%32);	//�l�ߕ��̃T�C�Y[bit]

			//�l�ߕ��T�C�Y��32bit�ɂȂ��Ă��܂��ꍇ�́C32bit=4byte�Ȃ̂ŋl�߂Ȃ��Ă���
			if(padding==32) padding=0;

			//�\���̂ɁC�摜�f�[�^�̔z��T�C�Y���i�[
			bmp->def_color_data_row_size=(real_Width_size+padding)/8;//0�l�߂��ꂽ����
			bmp->def_color_data_calumn_size=bmp->ih_o.bcHeight;
			bmp->color_data_row_size=bmp->ih_o.bcWidth;
			bmp->color_data_calumn_size=bmp->ih_o.bcHeight;

			//�{�g���A�b�v�łȂ��ꍇ�CbcHeight���}�C�i�X�Ȃ̂ŁC�v���X�ɒ���
			if(!bmp_type){
				bmp->def_color_data_calumn_size*=-1;
				bmp->color_data_calumn_size*=-1;
			}

			//�摜�f�[�^��RGB�l�ɕϊ��������p�̃������m��
			if(NULL==(bmp->color_data=(RGB**)malloc(sizeof(RGB*)*(bmp->color_data_calumn_size+1)))){
				perror("RGBRead->malloc->RGB**");
				return 0;
			}
			for(s=0;s<bmp->color_data_calumn_size;s++){
				if(NULL==(bmp->color_data[s]=(RGB*)malloc(sizeof(RGB)*(bmp->color_data_row_size+1)))){
					perror("RGBRead->malloc->RGB*");
					return 0;
				}
			}

			//�摜�f�[�^�̎擾
			for(t=0;t<bmp->color_data_calumn_size;t++){
				unsigned char delete_data;

				//�摜�f�[�^��ǂݍ���
				for(s=0;s<bmp->color_data_row_size;s++){
					fread(&(bmp->color_data[t][s].rgbBlue), 1, 1, fp);
					fread(&(bmp->color_data[t][s].rgbGreen), 1, 1, fp);
					fread(&(bmp->color_data[t][s].rgbRed), 1, 1, fp);
					
					//�\��̈��bitCount=32�Ȃ�ǂݍ��݁C�����łȂ��ꍇ�ɂ�0��������D
					if(bmp->ih_w.biBitCount==32) fread(&(bmp->color_data[t][s].rgbReserved), 1, 1, fp);
					bmp->color_data[t][s].rgbReserved=0;
				}

				//0�l�ߕ�����ǂݎ̂�
				for(s=0;s<(padding/8);s++) fread(&delete_data,1,1,fp);
			}

		}
	}

	//�{�g���A�b�v�ŕۑ�����Ă���ꍇ�C�摜�f�[�^���㉺���]����K�v������
	if(bmp_type){
		RGB** rgb;	//�ꎞ�I�ɁC�ǂݍ��񂾉摜�f�[�^��ۑ����邽�߂̕ϐ�

		//��������ۑ�
		if(NULL==(rgb=(RGB**)malloc(sizeof(RGB*)*(bmp->color_data_calumn_size+1)))){
			perror("RGBRead->malloc->RGB**");
			return 0;
		}
		for(s=0;s<bmp->color_data_calumn_size;s++){
			if(NULL==(rgb[s]=(RGB*)malloc(sizeof(RGB)*(bmp->color_data_row_size+1)))){
				perror("RGBRead->malloc->RGB*");
				return 0;
			}
		}

		//�f�[�^���ꎞ�I�ɃR�s�[
		for(t=0;t<bmp->color_data_calumn_size;t++) for(s=0;s<bmp->color_data_row_size;s++) rgb[t][s]=bmp->color_data[t][s];

		//�f�[�^�𔽓]�����Ȃ���bmp->color_data�Ɋi�[
		for(t=1;t<=bmp->color_data_calumn_size;t++) for(s=1;s<=bmp->color_data_row_size;s++) bmp->color_data[bmp->color_data_calumn_size-t][s-1]=rgb[t-1][s-1];

		//�����������
		for(s=0;s<bmp->color_data_calumn_size;s++) free(rgb[s]);
		free(rgb);

	}

	return bmp;

}

/*
BMP�\���̂̃��������������֐�
*/
int freeBMP(BMP* bmp){
	size_t i;

	if(bmp->format==Windows){
		//�p���b�g�f�[�^���L���ȏꍇ -> �p���b�g�f�[�^�����
		if(bmp->ih_w.biBitCount==1 || bmp->ih_w.biBitCount==4 || bmp->ih_w.biBitCount==8){
			free(bmp->pd_w);

			//�ǂݍ��񂾉摜�f�[�^�����
			for(i=0;i<bmp->def_color_data_calumn_size;i++) free(bmp->def_color_data[i]);
			free(bmp->def_color_data);

			//RGB�f�[�^���i�[�����ϐ������
			for(i=0;i<bmp->color_data_calumn_size;i++) free(bmp->color_data[i]);
			free(bmp->color_data);

		}//�p���b�g�f�[�^���g�p���Ă��Ȃ��ꍇ
		else{
			//RGB�f�[�^���i�[�����ϐ������
			for(i=0;i<bmp->color_data_calumn_size;i++) free(bmp->color_data[i]);
			free(bmp->color_data);
		}
	}
	else if(bmp->format==OS2){
		//�p���b�g�f�[�^���L���ȏꍇ -> �p���b�g�f�[�^�����
		if(bmp->ih_o.bcBitCount==1 || bmp->ih_o.bcBitCount==4 || bmp->ih_o.bcBitCount==8){
			free(bmp->pd_o);

			//�ǂݍ��񂾉摜�f�[�^�����
			for(i=0;i<bmp->def_color_data_calumn_size;i++) free(bmp->def_color_data[i]);
			free(bmp->def_color_data);

			//RGB�f�[�^���i�[�����ϐ������
			for(i=0;i<bmp->color_data_calumn_size;i++) free(bmp->color_data[i]);
			free(bmp->color_data);

		}//�p���b�g�f�[�^���g�p���Ă��Ȃ��ꍇ
		else{
			//RGB�f�[�^���i�[�����ϐ������
			for(i=0;i<bmp->color_data_calumn_size;i++) free(bmp->color_data[i]);
			free(bmp->color_data);
		}
	}

	free(bmp);

	return 0;
}

int main(){
	BMP *target1,*target2;		//�����Ώۂ̉摜
	BMP *temp1,*temp2;			//�e���v���[�g�摜
	unsigned int min=UINT_MAX;	//�ł��ގ��x���Ⴂ�l���i�[����ϐ�
	unsigned int mi=-1,mk=-1;	//min�̒l���o�͂����摜�̍���̍��W
	unsigned int i,k,p,q;		//���[�v�p�ϐ�	

	unsigned int sum=0;			//�ގ��x�i�[�p�ϐ�

	/*�摜�ǂݍ��ݕ�*/

	//img_1.bmp�̓ǂݍ���
	target1=ReadBMP("img_1.bmp");
	if(target1==NULL){
		perror("ReadBMP");
		return -1;
	}
	//img_2.bmp�̓ǂݍ���
	target2=ReadBMP("img_2.bmp");
	if(target2==NULL){
		perror("ReadBMP");
		return -1;
	}
	//img_1.bmp�̓ǂݍ���
	temp1=ReadBMP("Timg_1.bmp");
	if(temp1==NULL){
		perror("ReadBMP");
		return -1;
	}
	//img_1.bmp�̓ǂݍ���
	temp2=ReadBMP("Timg_2.bmp");
	if(temp2==NULL){
		perror("ReadBMP");
		return -1;
	}

	/*
	**�}�b�`���O��
	**�}�b�`���O���@�F�T���Ώۂ̉摜�ɑ΂��āC�p�x��ύX���Ȃ��S�Ẵp�^�[���Ńe���v���[�g�摜�Ƃ̗ގ��x���o�͂���D
	**�ގ��x�̎Z�o�@�F�F��f���g�p�����C�덷�̐�Βl�̑��a�D
	**�摜�̔��ʖ@�F�ގ��x���ł��Ⴂ���̂���v���Ă���ƈ����D
	*/

	//�}�b�`���O���@���o��
	printf("�}�b�`���O���@�F\n�@�@�T���Ώۂ̉摜�ɑ΂��āC�p�x��ύX���Ȃ��S�Ẵp�^�[���Ńe���v���[�g�摜�Ƃ̗ގ��x���o�͂���D\n");
	printf("�ގ��x�̎Z�o�@�F\n�@�@�F��f���g�p�����C�덷�̐�Βl�̑��a�D\n");
	printf("�摜�̔��ʖ@�F\n�@�@�ގ��x���ł��Ⴂ���̂���v���Ă���ƈ����D\n");
	printf("\n");

	/*target1 & temp1*/

	printf("img_1�ɑ΂���Timag_1�ł̃}�b�`���O���s���D\n");

	//�摜�̏ƍ�
	for(i=0;i<=(target1->color_data_calumn_size-temp1->color_data_calumn_size);i++){
		for(k=0;k<=(target1->color_data_row_size-temp1->color_data_row_size);k++){
			
			//�ގ��x�̌v�Z
			for(p=0;p<temp1->color_data_calumn_size;p++){
				for(q=0;q<temp1->color_data_row_size;q++){
					sum+=(unsigned int)abs((int)(target1->color_data[i+p][k+q].rgbBlue)-(int)(temp1->color_data[p][q].rgbBlue));
				}
			}

			//�ގ��x�̍ŏ��l���X�V
			if(min>sum){
				min=sum;
				mi=i;
				mk=k;
			}

			//�ގ��x�i�[�p�̕ϐ������Z�b�g
			sum=0;

		}
	}

	printf("�ł����v���Ă���摜�̍���̍��W��(%u,%u)�ł��D\n�ގ��x��%u�ł����D\n",mk,mi,min);

	printf("\n");

	/*target1 & temp2*/

	printf("img_1�ɑ΂���Timag_2�ł̃}�b�`���O���s���D\n");

	//�e��ϐ������Z�b�g
	sum=0;
	min=UINT_MAX;
	mi=-1;
	mk=-1;

	//�摜�̏ƍ�
	for(i=0;i<(target1->color_data_calumn_size-temp2->color_data_calumn_size);i++){
		for(k=0;k<(target1->color_data_row_size-temp2->color_data_row_size);k++){
			
			//�ގ��x�̌v�Z
			for(p=0;p<temp2->color_data_calumn_size;p++){
				for(q=0;q<temp2->color_data_row_size;q++){
					sum+=(unsigned int)abs((int)(target1->color_data[i+p][k+q].rgbBlue)-(int)(temp2->color_data[p][q].rgbBlue));
				}
			}

			//�ގ��x�̍ŏ��l���X�V
			if(min>sum){
				min=sum;
				mi=i;
				mk=k;
			}

			//�ގ��x�i�[�p�̕ϐ������Z�b�g
			sum=0;
		}
	}

	printf("�ł����v���Ă���摜�̍���̍��W��(%u,%u)�ł��D\n�ގ��x��%u�ł����D\n",mk,mi,min);

	printf("\n");
	
	/*target2 & temp1*/

	printf("img_2�ɑ΂���Timag_1�ł̃}�b�`���O���s���D\n");

	//�e��ϐ������Z�b�g
	sum=0;
	min=UINT_MAX;
	mi=-1;
	mk=-1;

	//�摜�̏ƍ�
	for(i=0;i<(target2->color_data_calumn_size-temp1->color_data_calumn_size);i++){
		for(k=0;k<(target2->color_data_row_size-temp1->color_data_row_size);k++){
			
			//�ގ��x�̌v�Z
			for(p=0;p<temp1->color_data_calumn_size;p++){
				for(q=0;q<temp1->color_data_row_size;q++){
					sum+=(unsigned int)abs((int)(target2->color_data[i+p][k+q].rgbBlue)-(int)(temp1->color_data[p][q].rgbBlue));
				}
			}

			//�ގ��x�̍ŏ��l���X�V
			if(min>sum){
				min=sum;
				mi=i;
				mk=k;
			}

			//�ގ��x�i�[�p�̕ϐ������Z�b�g
			sum=0;

		}
	}

	printf("�ł����v���Ă���摜�̍���̍��W��(%u,%u)�ł��D\n�ގ��x��%u�ł����D\n",mk,mi,min);

	printf("\n");

	/*target2 & temp2*/

	printf("img_2�ɑ΂���Timag_2�ł̃}�b�`���O���s���D\n");

	//�e��ϐ������Z�b�g
	sum=0;
	min=UINT_MAX;
	mi=-1;
	mk=-1;

	//�摜�̏ƍ�
	for(i=0;i<(target2->color_data_calumn_size-temp2->color_data_calumn_size);i++){
		for(k=0;k<(target2->color_data_row_size-temp2->color_data_row_size);k++){
			
			//�ގ��x�̌v�Z
			for(p=0;p<temp2->color_data_calumn_size;p++){
				for(q=0;q<temp2->color_data_row_size;q++){
					sum+=(unsigned int)abs((int)(target2->color_data[i+p][k+q].rgbBlue)-(int)(temp2->color_data[p][q].rgbBlue));
				}
			}
			
			//�ގ��x�̍ŏ��l���X�V
			if(min>sum){
				min=sum;
				mi=i;
				mk=k;
			}
			
			//�ގ��x�i�[�p�̕ϐ������Z�b�g
			sum=0;

		}
	}

	printf("�ł����v���Ă���摜�̍���̍��W��(%u,%u)�ł��D\n�ގ��x��%u�ł����D\n",mk,mi,min);

	printf("\n");


	/*�摜�����*/
	freeBMP(target1);
	freeBMP(target2);
	freeBMP(temp1);
	freeBMP(temp2);

	getchar();

	return 0;

}