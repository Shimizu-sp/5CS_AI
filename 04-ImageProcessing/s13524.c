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

//マクロ定義部

//マクロ関数定義部

//列挙体宣言部
//WinodwsかOS2かを示す列挙体
enum Format{
	OS2,
	Windows
};

//構造体宣言部

//Bitmap File Header用構造体
struct file_header{
	unsigned int bfType;			//ファイルタイプ
	unsigned long bfSize;			//ファイルサイズ[byte]
	unsigned int bfReserved1;		//予約領域１
	unsigned int bfReserved2;		//予約領域２
	unsigned long bfOffBit;			//ファイル先頭から画像データまでのオフセット[byte]	
};

//Windows用情報ヘッダ用構造体
struct information_header_Windows{
	unsigned long biSize;			//情報ヘッダサイズ[byte]
	long biWidth;					//画像の幅[ピクセル]
	long biHeight;					//画像の高さ[ピクセル]
	unsigned int biPlanes;			//プレーン数
	unsigned int biBitCount;		//色ビット数[bit]
	unsigned long biCompression;	//圧縮形式
	unsigned long biSizeImage;		//画像データサイズ[byte]	
	long biXPixPerMeter;			//水平解像度[dot/m]
	long biYPixPerMeter;			//垂直解像度[dot/m]
	unsigned long biClrUsed;		//格納パレット数[使用色数]
	unsigned long biCirImportant;	//重要色数
};

//OS2用情報ヘッダ用構造体

struct information_header_OS2{
	unsigned long bcSize;			//情報ヘッダサイズ[byte]
	int bcWidth;					//画像の幅[ピクセル]
	int bcHeight;					//画像の高さ[ピクセル]
	unsigned int bcPlanes;			//プレーン数
	unsigned int bcBitCount;		//色ビット数[bit]
};

//Windows用パレットデータ
struct palette_data_Windows{
	unsigned char rgbBlue;			//青
	unsigned char rgbGreen;			//緑
	unsigned char rgbRed;			//赤
	unsigned char rgbReserved;		//予約領域
};

//OS2用パレットデータ
struct palette_data_OS2{
	unsigned char rgbBlue;			//青
	unsigned char rgbGreen;			//緑
	unsigned char rgbRed;			//赤
};

//画素データ
typedef struct pix_data{
	unsigned char rgbBlue;			//青
	unsigned char rgbGreen;			//緑
	unsigned char rgbRed;			//赤
	unsigned char rgbReserved;		//予約領域
} RGB;

//BMPファイルデータを格納する構造体
typedef struct def_BMP{
	enum Format format;							//Winodws規格かOS2規格かを示す列挙体
	struct file_header fh;						//BMPのファイルヘッダ
	struct information_header_Windows ih_w;		//Winodwsの場合の情報ヘッダ
	struct information_header_OS2 ih_o;			//OS2の場合の情報ヘッダ
	struct palette_data_Windows *pd_w;			//Winodwsの場合のパレットデータ
	struct palette_data_OS2 *pd_o;				//OS2の場合のパレットデータ
	unsigned char **def_color_data;				//BMPファイル内の画素配列
	RGB **color_data;							//人間が認識しやすい縦x横の画素配列
	size_t palette_size;						//パレットデータの配列数を格納する
	size_t def_color_data_row_size;				//BMP内の画像データの行サイズ[byte]
	size_t def_color_data_calumn_size;			//BMP内の画像データの縦サイズ[byte]
	size_t color_data_row_size;				//人間が認識しやすい画像データの行サイズ[byte]
	size_t color_data_calumn_size;			//人間が認識しやすい画像データの縦サイズ[byte]
} BMP;

//関数定義部

/*
BMPを読み込む関数
エラー時にはNULLを返す
*/
BMP* ReadBMP(const char* filename){
	BMP* bmp;
	FILE* fp;
	size_t s;
	size_t t;

	int bmp_type=0;//BMPがボトムアップで保存されている場合1になるフラグ

	//BMPの構造体を確保
	if(NULL==(bmp=(BMP*)malloc(sizeof(BMP)))){
		perror("malloc:BMP");
		return 0;
	}

	//構造体内の値を初期化
	memset(bmp,0,sizeof(BMP));

	//ファイルの読み込み
	if (NULL == (fp = fopen(filename, "r"))){ 
		perror("Readbmp->fopen");
		return 0;
	}

	//ファイルヘッダの読み込み
	fread(&(bmp->fh.bfType), 2, 1, fp);

	//BMPファイルであるかを確認(bfType="BM"かを確認)
	if (bmp->fh.bfType != 0x4d42){
		perror("Not BMP file");
		return 0;
	}

	fread(&(bmp->fh.bfSize), 4, 1, fp);
	fread(&(bmp->fh.bfReserved1), 2, 1, fp);
	fread(&(bmp->fh.bfReserved2), 2, 1, fp);
	fread(&(bmp->fh.bfOffBit), 4, 1, fp);

	//情報ヘッダの読み込み
	fread(&(bmp->ih_o.bcSize), 4, 1, fp);

	//OS2規格かWindows規格かを判断
	if (bmp->ih_o.bcSize == 12){
		//OS2
		bmp->format = OS2;
		fread(&(bmp->ih_o.bcWidth), 2, 1, fp);
		fread(&(bmp->ih_o.bcHeight), 2, 1, fp);
		fread(&(bmp->ih_o.bcPlanes), 2, 1, fp);
		fread(&(bmp->ih_o.bcBitCount), 2, 1, fp);

		//ボトムアップであるかを判定
		if(bmp->ih_o.bcHeight>0){
			//高さが整数　-> ボトムアップである
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

		//ボトムアップであるかを判定
		if(bmp->ih_w.biHeight>0){
			//高さが整数　-> ボトムアップである
			bmp_type=1;
		}
	}
	else{
		perror("Unknown BMP format");
		return 0;
	}

	//パレットデータの読み込み
	if (bmp->format == OS2){
		switch (bmp->ih_o.bcBitCount){
		case 1:
			perror("パレットサイズ=1は未対応です．");
			return 0;
			/*
			//パレットデータのメモリ確保
			bmp->palette_size=2;
			if(NULL==(bmp->pd_o=(struct palette_data_OS2*)malloc(sizeof(struct palette_data_OS2)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//パレットデータの読み込み
			for(s=0;s<bmp->palette_size;s++){
				fread(&(bmp->pd_o[s].rgbBlue), 1, 1, fp);
				fread(&(bmp->pd_o[s].rgbGreen), 1, 1, fp);
				fread(&(bmp->pd_o[s].rgbRed), 1, 1, fp);
			}
			*/
			break;
		case 4:
			perror("パレットサイズ=4は未対応です．");
			return 0;
			/*
			//パレットデータのメモリ確保
			bmp->palette_size=16;
			if(NULL==(bmp->pd_o=(struct palette_data_OS2*)malloc(sizeof(struct palette_data_OS2)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//パレットデータの読み込み
			for(s=0;s<bmp->palette_size;s++){
				fread(&(bmp->pd_o[s].rgbBlue), 1, 1, fp);
				fread(&(bmp->pd_o[s].rgbGreen), 1, 1, fp);
				fread(&(bmp->pd_o[s].rgbRed), 1, 1, fp);
			}
			*/
			break;
		case 8:
			//パレットデータのメモリ確保
			bmp->palette_size=256;
			if(NULL==(bmp->pd_o=(struct palette_data_OS2*)malloc(sizeof(struct palette_data_OS2)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//パレットデータの読み込み
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
			perror("パレットサイズ=1は未対応です．");
			return 0;
			/*
			//パレットデータのメモリ確保
			bmp->palette_size=2;
			if(NULL==(bmp->pd_w=(struct palette_data_Windows*)malloc(sizeof(struct palette_data_Windows)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//パレットデータの読み込み
			for(s=0;s<bmp->palette_size;s++){
				fread(&(bmp->pd_w[s].rgbBlue), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbGreen), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbRed), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbReserved), 1, 1, fp);
			}
			*/
			break;
		case 4:
			perror("パレットサイズ=4は未対応です．");
			return 0;
			/*
			//パレットデータのメモリ確保
			bmp->palette_size=16;
			if(NULL==(bmp->pd_w=(struct palette_data_Windows*)malloc(sizeof(struct palette_data_Windows)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//パレットデータの読み込み
			for(s=0;s<bmp->palette_size;s++){
				fread(&(bmp->pd_w[s].rgbBlue), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbGreen), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbRed), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbReserved), 1, 1, fp);
			}

			break;
			*/
		case 8:
			//パレットデータのメモリ確保
			bmp->palette_size=256;
			if(NULL==(bmp->pd_w=(struct palette_data_Windows*)malloc(sizeof(struct palette_data_Windows)*bmp->palette_size))){
				perror("palettedata->malloc");
				return 0;
			}

			//パレットデータの読み込み
			for(s=0;s<bmp->palette_size;s++){
				fread(&(bmp->pd_w[s].rgbBlue), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbGreen), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbRed), 1, 1, fp);
				fread(&(bmp->pd_w[s].rgbReserved), 1, 1, fp);
			}

			break;
		}
	}

	//画像データの読み込み
	//BitCountが8,24,32以外の場合は現状ではここより先に進むことはありません．

	//画像データの格納サイズ推定
	if(bmp->format==Windows){

		//パレットデータありの場合
		if(bmp->ih_w.biBitCount==1 || bmp->ih_w.biBitCount==4 || bmp->ih_w.biBitCount==8){
			unsigned int real_Width_size=bmp->ih_w.biWidth*bmp->ih_w.biBitCount;	//実際の画像データのサイズ[bit]
			unsigned int padding=32-((bmp->ih_w.biWidth*bmp->ih_w.biBitCount)%32);		//詰め物のサイズ[bit]

			//詰め物サイズが32bitになってしまう場合は，32bit=4byteなので詰めなくていい
			if(padding==32) padding=0;

			//構造体に，画像データの配列サイズを格納
			bmp->def_color_data_row_size=(real_Width_size+padding)/8;//0詰めされた横幅
			bmp->def_color_data_calumn_size=bmp->ih_w.biHeight;
			bmp->color_data_row_size=bmp->ih_w.biWidth;
			bmp->color_data_calumn_size=bmp->ih_w.biHeight;

			//ボトムアップでない場合，biHeightがマイナスなので，プラスに直す
			if(!bmp_type){
				bmp->def_color_data_calumn_size*=-1;
				bmp->color_data_calumn_size*=-1;
			}

			//画像データ用のメモリ確保
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

			//画像データをRGB値に変換した情報用のメモリ確保
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

			//画像データの取得(8bitのみ）
			for(t=0;t<bmp->def_color_data_calumn_size;t++){
				for(s=0;s<bmp->def_color_data_row_size;s++){
					fread(&(bmp->def_color_data[t][s]), 1, 1, fp);
				}
			}

			//パレッドデータに従い，RGB値に変換
			for(t=0;t<bmp->color_data_calumn_size;t++){
				for(s=0;s<bmp->color_data_row_size;s++){
					//RGBデータの格納構造.色の種類 = パレットデータ配列[画像データ].色の種類
					bmp->color_data[t][s].rgbBlue=bmp->pd_w[bmp->def_color_data[t][s]].rgbBlue;
					bmp->color_data[t][s].rgbGreen=bmp->pd_w[bmp->def_color_data[t][s]].rgbGreen;
					bmp->color_data[t][s].rgbRed=bmp->pd_w[bmp->def_color_data[t][s]].rgbRed;
				}
			}

		}//パレットデータなしの場合
		else{
			unsigned int real_Width_size=bmp->ih_w.biWidth*bmp->ih_w.biBitCount;	//実際の画像データのサイズ[bit]
			unsigned int padding=32-((bmp->ih_w.biWidth*bmp->ih_w.biBitCount)%32);	//詰め物のサイズ[bit]

			//詰め物サイズが32bitになってしまう場合は，32bit=4byteなので詰めなくていい
			if(padding==32) padding=0;

			//構造体に，画像データの配列サイズを格納
			bmp->def_color_data_row_size=(real_Width_size+padding)/8;//0詰めされた横幅
			bmp->def_color_data_calumn_size=bmp->ih_w.biHeight;
			bmp->color_data_row_size=bmp->ih_w.biWidth;
			bmp->color_data_calumn_size=bmp->ih_w.biHeight;

			//ボトムアップでない場合，biHeightがマイナスなので，プラスに直す
			if(!bmp_type){
				bmp->def_color_data_calumn_size*=-1;
				bmp->color_data_calumn_size*=-1;
			}

			//画像データをRGB値に変換した情報用のメモリ確保
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

			//画像データの取得
			for(t=0;t<bmp->def_color_data_calumn_size;t++){
				unsigned char delete_data;
				
				for(s=0;s<(bmp->color_data_row_size);s++){
					fread(&(bmp->color_data[t][s].rgbBlue), 1, 1, fp);
					fread(&(bmp->color_data[t][s].rgbGreen), 1, 1, fp);
					fread(&(bmp->color_data[t][s].rgbRed), 1, 1, fp);

					//予約領域はbitCount=32なら読み込み，そうでない場合には0を代入する．
					if(bmp->ih_w.biBitCount==32) fread(&(bmp->color_data[t][s].rgbReserved), 1, 1, fp);
					bmp->color_data[t][s].rgbReserved=0;
				}

				//0詰め部分を読み捨て
				for(s=0;s<(padding/8);s++) fread(&delete_data,1,1,fp);
			}

		}
			
	}
	else if(bmp->format==OS2){
		//パレットデータありの場合
		if(bmp->ih_o.bcBitCount==1 || bmp->ih_o.bcBitCount==4 || bmp->ih_o.bcBitCount==8){
			unsigned int real_Width_size=bmp->ih_o.bcWidth*bmp->ih_o.bcBitCount;	//実際の画像データのサイズ[bit]
			unsigned int padding=32-((bmp->ih_o.bcWidth*bmp->ih_o.bcBitCount)%32);	//詰め物のサイズ[bit]

			//詰め物サイズが32bitになってしまう場合は，32bit=4byteなので詰めなくていい
			if(padding==32) padding=0;

			//構造体に，画像データの配列サイズを格納
			bmp->def_color_data_row_size=(real_Width_size+padding)/8;//0詰めされた横幅
			bmp->def_color_data_calumn_size=bmp->ih_o.bcHeight;
			bmp->color_data_row_size=bmp->ih_o.bcWidth;
			bmp->color_data_calumn_size=bmp->ih_o.bcHeight;

			//ボトムアップでない場合，bcHeightがマイナスなので，プラスに直す
			if(!bmp_type){
				bmp->def_color_data_calumn_size*=-1;
				bmp->color_data_calumn_size*=-1;
			}

			//画像データ用のメモリ確保
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

			//画像データをRGB値に変換した情報用のメモリ確保
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

			//画像データの取得(8bitのみ）
			for(t=0;t<bmp->def_color_data_calumn_size;t++){
				for(s=0;s<bmp->def_color_data_row_size;s++){
					fread(&(bmp->def_color_data[t][s]), 1, 1, fp);
				}
			}

			//パレッドデータに従い，RGB値に変換
			for(t=0;t<bmp->color_data_calumn_size;t++){
				for(s=0;s<bmp->color_data_row_size;s++){
					//RGBデータの格納構造.色の種類 = パレットデータ配列[画像データ].色の種類
					bmp->color_data[t][s].rgbBlue=bmp->pd_w[bmp->def_color_data[t][s]].rgbBlue;
					bmp->color_data[t][s].rgbGreen=bmp->pd_w[bmp->def_color_data[t][s]].rgbGreen;
					bmp->color_data[t][s].rgbRed=bmp->pd_w[bmp->def_color_data[t][s]].rgbRed;
				}
			}

		}//パレットデータなしの場合
		else{
			unsigned int real_Width_size=bmp->ih_o.bcWidth*bmp->ih_o.bcBitCount;	//実際の画像データのサイズ[bit]
			unsigned int padding=32-((bmp->ih_o.bcWidth*bmp->ih_o.bcBitCount)%32);	//詰め物のサイズ[bit]

			//詰め物サイズが32bitになってしまう場合は，32bit=4byteなので詰めなくていい
			if(padding==32) padding=0;

			//構造体に，画像データの配列サイズを格納
			bmp->def_color_data_row_size=(real_Width_size+padding)/8;//0詰めされた横幅
			bmp->def_color_data_calumn_size=bmp->ih_o.bcHeight;
			bmp->color_data_row_size=bmp->ih_o.bcWidth;
			bmp->color_data_calumn_size=bmp->ih_o.bcHeight;

			//ボトムアップでない場合，bcHeightがマイナスなので，プラスに直す
			if(!bmp_type){
				bmp->def_color_data_calumn_size*=-1;
				bmp->color_data_calumn_size*=-1;
			}

			//画像データをRGB値に変換した情報用のメモリ確保
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

			//画像データの取得
			for(t=0;t<bmp->color_data_calumn_size;t++){
				unsigned char delete_data;

				//画像データを読み込み
				for(s=0;s<bmp->color_data_row_size;s++){
					fread(&(bmp->color_data[t][s].rgbBlue), 1, 1, fp);
					fread(&(bmp->color_data[t][s].rgbGreen), 1, 1, fp);
					fread(&(bmp->color_data[t][s].rgbRed), 1, 1, fp);
					
					//予約領域はbitCount=32なら読み込み，そうでない場合には0を代入する．
					if(bmp->ih_w.biBitCount==32) fread(&(bmp->color_data[t][s].rgbReserved), 1, 1, fp);
					bmp->color_data[t][s].rgbReserved=0;
				}

				//0詰め部分を読み捨て
				for(s=0;s<(padding/8);s++) fread(&delete_data,1,1,fp);
			}

		}
	}

	//ボトムアップで保存されている場合，画像データを上下反転する必要がある
	if(bmp_type){
		RGB** rgb;	//一時的に，読み込んだ画像データを保存するための変数

		//メモリを保存
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

		//データを一時的にコピー
		for(t=0;t<bmp->color_data_calumn_size;t++) for(s=0;s<bmp->color_data_row_size;s++) rgb[t][s]=bmp->color_data[t][s];

		//データを反転させながらbmp->color_dataに格納
		for(t=1;t<=bmp->color_data_calumn_size;t++) for(s=1;s<=bmp->color_data_row_size;s++) bmp->color_data[bmp->color_data_calumn_size-t][s-1]=rgb[t-1][s-1];

		//メモリを解放
		for(s=0;s<bmp->color_data_calumn_size;s++) free(rgb[s]);
		free(rgb);

	}

	return bmp;

}

/*
BMP構造体のメモリを解放する関数
*/
int freeBMP(BMP* bmp){
	size_t i;

	if(bmp->format==Windows){
		//パレットデータが有効な場合 -> パレットデータを解放
		if(bmp->ih_w.biBitCount==1 || bmp->ih_w.biBitCount==4 || bmp->ih_w.biBitCount==8){
			free(bmp->pd_w);

			//読み込んだ画像データを解放
			for(i=0;i<bmp->def_color_data_calumn_size;i++) free(bmp->def_color_data[i]);
			free(bmp->def_color_data);

			//RGBデータを格納した変数を解放
			for(i=0;i<bmp->color_data_calumn_size;i++) free(bmp->color_data[i]);
			free(bmp->color_data);

		}//パレットデータを使用していない場合
		else{
			//RGBデータを格納した変数を解放
			for(i=0;i<bmp->color_data_calumn_size;i++) free(bmp->color_data[i]);
			free(bmp->color_data);
		}
	}
	else if(bmp->format==OS2){
		//パレットデータが有効な場合 -> パレットデータを解放
		if(bmp->ih_o.bcBitCount==1 || bmp->ih_o.bcBitCount==4 || bmp->ih_o.bcBitCount==8){
			free(bmp->pd_o);

			//読み込んだ画像データを解放
			for(i=0;i<bmp->def_color_data_calumn_size;i++) free(bmp->def_color_data[i]);
			free(bmp->def_color_data);

			//RGBデータを格納した変数を解放
			for(i=0;i<bmp->color_data_calumn_size;i++) free(bmp->color_data[i]);
			free(bmp->color_data);

		}//パレットデータを使用していない場合
		else{
			//RGBデータを格納した変数を解放
			for(i=0;i<bmp->color_data_calumn_size;i++) free(bmp->color_data[i]);
			free(bmp->color_data);
		}
	}

	free(bmp);

	return 0;
}

int main(){
	BMP *target1,*target2;		//検索対象の画像
	BMP *temp1,*temp2;			//テンプレート画像
	unsigned int min=UINT_MAX;	//最も類似度が低い値を格納する変数
	unsigned int mi=-1,mk=-1;	//minの値を出力した画像の左上の座標
	unsigned int i,k,p,q;		//ループ用変数	

	unsigned int sum=0;			//類似度格納用変数

	/*画像読み込み部*/

	//img_1.bmpの読み込み
	target1=ReadBMP("img_1.bmp");
	if(target1==NULL){
		perror("ReadBMP");
		return -1;
	}
	//img_2.bmpの読み込み
	target2=ReadBMP("img_2.bmp");
	if(target2==NULL){
		perror("ReadBMP");
		return -1;
	}
	//img_1.bmpの読み込み
	temp1=ReadBMP("Timg_1.bmp");
	if(temp1==NULL){
		perror("ReadBMP");
		return -1;
	}
	//img_1.bmpの読み込み
	temp2=ReadBMP("Timg_2.bmp");
	if(temp2==NULL){
		perror("ReadBMP");
		return -1;
	}

	/*
	**マッチング部
	**マッチング方法：探索対象の画像に対して，角度を変更しない全てのパターンでテンプレート画像との類似度を出力する．
	**類似度の算出法：青色画素を使用した，誤差の絶対値の総和．
	**画像の判別法：類似度が最も低いものを一致していると扱う．
	*/

	//マッチング方法を出力
	printf("マッチング方法：\n　　探索対象の画像に対して，角度を変更しない全てのパターンでテンプレート画像との類似度を出力する．\n");
	printf("類似度の算出法：\n　　青色画素を使用した，誤差の絶対値の総和．\n");
	printf("画像の判別法：\n　　類似度が最も低いものを一致していると扱う．\n");
	printf("\n");

	/*target1 & temp1*/

	printf("img_1に対してTimag_1でのマッチングを行う．\n");

	//画像の照合
	for(i=0;i<=(target1->color_data_calumn_size-temp1->color_data_calumn_size);i++){
		for(k=0;k<=(target1->color_data_row_size-temp1->color_data_row_size);k++){
			
			//類似度の計算
			for(p=0;p<temp1->color_data_calumn_size;p++){
				for(q=0;q<temp1->color_data_row_size;q++){
					sum+=(unsigned int)abs((int)(target1->color_data[i+p][k+q].rgbBlue)-(int)(temp1->color_data[p][q].rgbBlue));
				}
			}

			//類似度の最小値を更新
			if(min>sum){
				min=sum;
				mi=i;
				mk=k;
			}

			//類似度格納用の変数をリセット
			sum=0;

		}
	}

	printf("最も合致している画像の左上の座標は(%u,%u)です．\n類似度は%uでした．\n",mk,mi,min);

	printf("\n");

	/*target1 & temp2*/

	printf("img_1に対してTimag_2でのマッチングを行う．\n");

	//各種変数をリセット
	sum=0;
	min=UINT_MAX;
	mi=-1;
	mk=-1;

	//画像の照合
	for(i=0;i<(target1->color_data_calumn_size-temp2->color_data_calumn_size);i++){
		for(k=0;k<(target1->color_data_row_size-temp2->color_data_row_size);k++){
			
			//類似度の計算
			for(p=0;p<temp2->color_data_calumn_size;p++){
				for(q=0;q<temp2->color_data_row_size;q++){
					sum+=(unsigned int)abs((int)(target1->color_data[i+p][k+q].rgbBlue)-(int)(temp2->color_data[p][q].rgbBlue));
				}
			}

			//類似度の最小値を更新
			if(min>sum){
				min=sum;
				mi=i;
				mk=k;
			}

			//類似度格納用の変数をリセット
			sum=0;
		}
	}

	printf("最も合致している画像の左上の座標は(%u,%u)です．\n類似度は%uでした．\n",mk,mi,min);

	printf("\n");
	
	/*target2 & temp1*/

	printf("img_2に対してTimag_1でのマッチングを行う．\n");

	//各種変数をリセット
	sum=0;
	min=UINT_MAX;
	mi=-1;
	mk=-1;

	//画像の照合
	for(i=0;i<(target2->color_data_calumn_size-temp1->color_data_calumn_size);i++){
		for(k=0;k<(target2->color_data_row_size-temp1->color_data_row_size);k++){
			
			//類似度の計算
			for(p=0;p<temp1->color_data_calumn_size;p++){
				for(q=0;q<temp1->color_data_row_size;q++){
					sum+=(unsigned int)abs((int)(target2->color_data[i+p][k+q].rgbBlue)-(int)(temp1->color_data[p][q].rgbBlue));
				}
			}

			//類似度の最小値を更新
			if(min>sum){
				min=sum;
				mi=i;
				mk=k;
			}

			//類似度格納用の変数をリセット
			sum=0;

		}
	}

	printf("最も合致している画像の左上の座標は(%u,%u)です．\n類似度は%uでした．\n",mk,mi,min);

	printf("\n");

	/*target2 & temp2*/

	printf("img_2に対してTimag_2でのマッチングを行う．\n");

	//各種変数をリセット
	sum=0;
	min=UINT_MAX;
	mi=-1;
	mk=-1;

	//画像の照合
	for(i=0;i<(target2->color_data_calumn_size-temp2->color_data_calumn_size);i++){
		for(k=0;k<(target2->color_data_row_size-temp2->color_data_row_size);k++){
			
			//類似度の計算
			for(p=0;p<temp2->color_data_calumn_size;p++){
				for(q=0;q<temp2->color_data_row_size;q++){
					sum+=(unsigned int)abs((int)(target2->color_data[i+p][k+q].rgbBlue)-(int)(temp2->color_data[p][q].rgbBlue));
				}
			}
			
			//類似度の最小値を更新
			if(min>sum){
				min=sum;
				mi=i;
				mk=k;
			}
			
			//類似度格納用の変数をリセット
			sum=0;

		}
	}

	printf("最も合致している画像の左上の座標は(%u,%u)です．\n類似度は%uでした．\n",mk,mi,min);

	printf("\n");


	/*画像解放部*/
	freeBMP(target1);
	freeBMP(target2);
	freeBMP(temp1);
	freeBMP(temp2);

	getchar();

	return 0;

}