#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//img_1.txt�ɑ΂���v���O����

main(){

	//Timg_1.txt�����p
	char temp[201][600]; //�e���v���[�g
	char image[513][1536]; //�C���[�W�摜

	int line = 0; //�s�ԍ��𐔂���
	int row = 0;  //��ԍ��𐔂���

	int line_img = 0,row_img = 0; //�C���[�W�p�s��ԍ�
	int start_line = 0,start_row = 0;

	int file_read = 0; //�t�@�C���ǂݍ��ݗp
	
	//�ގ��x����p
	int temp_hantei;
	int image_hantei;
	int RSSD; //���̓��a
	int RSSD_now = 99999999; //���̐�Βl�ۑ��p

	int aiko=0;

	int i;

	int test = 0;

	FILE *temp_file, *image_file;

	//�ȉ���菈���J�n===========================
	

	//Timg_1.txt��ǂݍ���=======================

	fopen_s(&temp_file, "Timg_data_1.txt", "r");

	while (file_read != EOF){

		file_read = fgetc(temp_file); //Timg_1.txt��萔�l(int�^)��1�����ǂݍ���
		temp[line][row] = file_read; //�e���v���[�g�Ƃ��ĕۑ�

		row++; //��ԍ��𐔂���

		if (row == 600){
			row = 0; //��ԍ���������
			line++; //�s�ԍ��𐔂���
	}}

	fclose(temp_file);


	//img_1.txt��ǂݍ���=======================

	fopen_s(&image_file, "img_data_1.txt", "r");

	line = 0; row = 0; //�s��ԍ��̏�����

	for (i = 0; i < 786432; i++){

		file_read = fgetc(image_file); //img_1.txt��萔�l��1�ǂݍ���
		image[line][row] = file_read; //intr�^��char�^�ɕϊ����ăC���[�W�Ƃ��ĕۑ�
		
		row++; //��ԍ��𐔂���

		if (row == 1536){
			row = 0; //��ԍ���������
			line++; //�s�ԍ��𐔂���
	}}

	fclose(image_file);

    //�e���v���[�g�}�b�`���O====================

	do{

    line_img = start_line; 
	row_img  = start_row;

	line = 0; row = 0; //�s��ԍ��̏�����
	RSSD = 0;

    //�ގ��𔻒肷�鏈��=========================

	for (i = 0; i < 40000; i++){

		temp_hantei = image_hantei = 0; //������

		//�e���v���[�g=======================================================
		if(temp[line][row] < 48){ temp_hantei += 0; }else{
			temp_hantei  += (48 - temp[line][row]) * 100; } //�S�ʂ�ۑ�
		
		if(temp[line][row + 1] < 48){ temp_hantei += 0; }else{
			temp_hantei  += (48 - temp[line][row + 1]) * 10; } //�\�ʂ�ۑ�
		
		if(temp[line][row + 2] < 48){ temp_hantei += 0; }else{
			temp_hantei  += (48 - temp[line][row + 2]); } //��ʂ�ۑ�
		//===================================================================

		//�C���[�W===========================================================
		if(image[line_img][row_img] < 48){ temp_hantei += 0; }else{
			image_hantei += (48 - image[line_img][row_img]) * 100; } //�S�ʂ�ۑ�
		
		if(image[line_img][row_img + 1] < 48){ temp_hantei += 0; }else{
			image_hantei += (48 - image[line_img][row_img + 1]) * 10; } //�\�ʂ�ۑ�
		
		if(image[line_img][row_img + 2] < 48){ temp_hantei += 0; }else{
			image_hantei += (48 - image[line_img][row_img + 2]); } //��ʂ�ۑ�
		//===================================================================
 
		RSSD += abs(image_hantei - temp_hantei); //���莮

		row = row + 3; //��ԍ��𐔂���
		row_img = row_img + 3;

		if (row == 600){
			
			row = 0; //��ԍ���������
			line++; //�s�ԍ��𐔂���

			line_img++; //�s�ԍ��𐔂���
	}}

	if (RSSD_now > RSSD){
		RSSD_now = RSSD; //���̐�Βl��ۑ�����
		printf("RSAD %d\n",RSSD_now);
	}

	start_row++;

	if (row == 600){
			
		row = 0; //��ԍ���������
		start_line++; //�s�ԍ��𐔂���
	}

 }while(RSSD_now != 0);

	printf("%d",start_line,start_row);

}