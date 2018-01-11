#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//img_1.txtに対するプログラム

main(){

	//Timg_1.txt処理用
	char temp[201][600]; //テンプレート
	char image[513][1536]; //イメージ画像

	int line = 0; //行番号を数える
	int row = 0;  //列番号を数える

	int line_img = 0,row_img = 0; //イメージ用行列番号
	int start_line = 0,start_row = 0;

	int file_read = 0; //ファイル読み込み用
	
	//類似度判定用
	int temp_hantei;
	int image_hantei;
	int RSSD; //差の二乗和
	int RSSD_now = 99999999; //差の絶対値保存用

	int aiko=0;

	int i;

	int test = 0;

	FILE *temp_file, *image_file;

	//以下より処理開始===========================
	

	//Timg_1.txtを読み込む=======================

	fopen_s(&temp_file, "Timg_data_1.txt", "r");

	while (file_read != EOF){

		file_read = fgetc(temp_file); //Timg_1.txtより数値(int型)を1文字読み込む
		temp[line][row] = file_read; //テンプレートとして保存

		row++; //列番号を数える

		if (row == 600){
			row = 0; //列番号を初期化
			line++; //行番号を数える
	}}

	fclose(temp_file);


	//img_1.txtを読み込む=======================

	fopen_s(&image_file, "img_data_1.txt", "r");

	line = 0; row = 0; //行列番号の初期化

	for (i = 0; i < 786432; i++){

		file_read = fgetc(image_file); //img_1.txtより数値を1読み込む
		image[line][row] = file_read; //intr型→char型に変換してイメージとして保存
		
		row++; //列番号を数える

		if (row == 1536){
			row = 0; //列番号を初期化
			line++; //行番号を数える
	}}

	fclose(image_file);

    //テンプレートマッチング====================

	do{

    line_img = start_line; 
	row_img  = start_row;

	line = 0; row = 0; //行列番号の初期化
	RSSD = 0;

    //類似を判定する処理=========================

	for (i = 0; i < 40000; i++){

		temp_hantei = image_hantei = 0; //初期化

		//テンプレート=======================================================
		if(temp[line][row] < 48){ temp_hantei += 0; }else{
			temp_hantei  += (48 - temp[line][row]) * 100; } //百位を保存
		
		if(temp[line][row + 1] < 48){ temp_hantei += 0; }else{
			temp_hantei  += (48 - temp[line][row + 1]) * 10; } //十位を保存
		
		if(temp[line][row + 2] < 48){ temp_hantei += 0; }else{
			temp_hantei  += (48 - temp[line][row + 2]); } //一位を保存
		//===================================================================

		//イメージ===========================================================
		if(image[line_img][row_img] < 48){ temp_hantei += 0; }else{
			image_hantei += (48 - image[line_img][row_img]) * 100; } //百位を保存
		
		if(image[line_img][row_img + 1] < 48){ temp_hantei += 0; }else{
			image_hantei += (48 - image[line_img][row_img + 1]) * 10; } //十位を保存
		
		if(image[line_img][row_img + 2] < 48){ temp_hantei += 0; }else{
			image_hantei += (48 - image[line_img][row_img + 2]); } //一位を保存
		//===================================================================
 
		RSSD += abs(image_hantei - temp_hantei); //判定式

		row = row + 3; //列番号を数える
		row_img = row_img + 3;

		if (row == 600){
			
			row = 0; //列番号を初期化
			line++; //行番号を数える

			line_img++; //行番号を数える
	}}

	if (RSSD_now > RSSD){
		RSSD_now = RSSD; //差の絶対値を保存する
		printf("RSAD %d\n",RSSD_now);
	}

	start_row++;

	if (row == 600){
			
		row = 0; //列番号を初期化
		start_line++; //行番号を数える
	}

 }while(RSSD_now != 0);

	printf("%d",start_line,start_row);

}