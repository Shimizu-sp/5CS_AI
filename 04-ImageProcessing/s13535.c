#include <stdio.h>
#include <stdlib.h>
#include <Math.h>
#pragma warning(disable : 4996)

//メモ 参考 http://www.umekkii.jp/data/computer/file_format/bitmap.cgi

typedef struct _BMP{

	//ファイルヘッダ
	//ファイルタイプ以外は読み捨て
	unsigned  bfType;

	//情報ヘッダ
	//幅、高さ以外は読み捨て
	long biWidth; //画像の幅
	long biHeight; //画像の高さ
	int biBitCount; //色ビット数 

	//パレットデータ
	//読み捨て

	//画像データ
	unsigned int *pixels;

}BMP;

//プロトタイプ宣言
int BmpInit(char *filepass, BMP *bmp);
int SetPixels(BMP *bmp, FILE *fp);
long int SADmatching(BMP *input, BMP *trim, int num);


int main(){

	//読み込み用ビットマップ作成
	BMP *input, *trim;
	int i,q;
	long int sad;
	long int result;
	int x, y;
	int tx, ty;

	//2パターンの組み合わせを行う
	for (q = 0; q < 2; q++) {

		sad = -1;
		result = -1;

		//メモリ確保
		input = (BMP*)malloc(sizeof(BMP));
		trim = (BMP*)malloc(sizeof(BMP));

		//ファイルを読み込む
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

		printf("探索中です。しばらくお待ちください");
		//入力画像のすべての画素を検査
		for (i = 0; i < input->biHeight*input->biWidth; i++) {
			//探索進行度を可視化
			if (i % (input->biHeight*input->biWidth / 10) == 0) printf("・");
			//対象の画素が検査範囲内ならテンプレートマッチングを行う
			tx = i % input->biWidth;
			ty = i / input->biWidth;
			if (tx <= input->biWidth - trim->biWidth && ty <= input->biHeight - trim->biHeight) {
				result = SADmatching(input, trim, i);
				//マッチング結果の更新
				if (sad == -1 || result < sad && result > 0) {
					sad = result;
					x = tx;
					y = ty;
					if (sad == 0) break;
				}
			}
		}

		printf("\n探索結果を表示します\nx=%d,y=%d sad=%ld\n\n", x, y, sad);

		//メモリ解放
		free(input->pixels);
		free(trim->pixels);
		free(input);
		free(trim);

		printf("\n");

	}

	getchar();
}

//ビットマップをBMP構造体で保存する
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

	printf("ファイル名:%s の読み込みを開始します\n", filepass);

	//ビットマップ読み込み
	fp = fopen(filepass, "r");
	if (fp == NULL){
		printf("エラー:ファイルが開けませんでした\n");
		return -1;
	}

	//ファイルヘッダ読み込み
	//拡張子判定
	rc = fread(c, 1, 2, fp);
	if (rc == 0){
		printf("エラー：読み込みデータがありません\n");
		return -1;
	}
	bmp->bfType = 0;
	for (i = 0; i < 2; i++){
		bmp->bfType = (bmp->bfType << (i*8)) | c[i];
	}

	printf("%x\n", bmp->bfType);
	if (bmp->bfType != 0x424d){
		printf("エラー：ビットマップ以外が入力されました\n");
		return -1;
	}
	//以下読み捨て（ファイルサイズ、予約領域、ファイル先頭から画像データまでのオフセット）
	for (i = 0; i < 3; i++){
		rc = fread(c, 1, 4, fp);
		if (rc == 0){
			printf("エラー：読み込みデータがありません\n");
			return -1;
		}
	}
	
	//情報ヘッダ読み込み
	//読み捨て（情報ヘッダサイズ）
	rc = fread(c, 1, 4, fp);
	if (rc == 0){
		printf("エラー：読み込みデータがありません\n");
		return -1;
	}
	//ビットマップの幅と高さを取得
	rc = fread(&bmp->biWidth, 1, 4, fp);
	if (rc == 0){
		printf("エラー：読み込みデータがありません\n");
		return -1;
	}
	rc = fread(&bmp->biHeight, 1, 4, fp);
	if (rc == 0){
		printf("エラー：読み込みデータがありません\n");
		return -1;
	}

	printf("幅：%ld 高さ：%ld\n", bmp->biWidth, bmp->biHeight);
	
	rc = fread(c, 1, 2, fp);
	if (rc == 0) {
		printf("エラー：読み込みデータがありません\n");
		return -1;
	}

	//色ビット数を取得
	rc = fread(&bmp->biBitCount, 1, 2, fp);
	if (rc == 0) {
		printf("エラー：読み込みデータがありません\n");
		return -1;
	}
	if (bmp->biBitCount != 24) {
		printf("ビットマップの色ビット数が24ではありません\n");
		return -1;
	}

	printf("色ビット数:%d\n", bmp->biBitCount);

	//以下読み捨て
	for (i = 0; i < 6; i++) {
		rc = fread(c, 1, 4, fp);
		if (rc == 0) {
			printf("エラー：読み込みデータがありません\n");
			return -1;
		}
	}

	//パレットデータ読み捨て
	//今回は色ビット数が24ビットのみを読み込んでいるため処理を飛ばす(パレットデータが存在しないため)
	/*
	for (i = 0; i < 4; i++) {
		rc = fread(c, 1, 1, fp);
		if (rc == 0) {
			printf("エラー：読み込みデータがありません\n");
			return -1;
		}
			
	}*/

	//画像データ読み込み
	SetPixels(bmp, fp);

	rc = fread(c, 1, 1, fp);
	if (rc != 0) {
		printf("エラー：データがまだ残っています\n\n");
		return -1;
	}

	fclose(fp);
}

//画像データ入力　
int SetPixels(BMP *bmp, FILE *fp){

	int color = 0;
	int rc = 0;
	int i = 0, n = 0;;

	//対象画素の幅、高さ
	int w, h;
	//ビットマップヘッダの詰め物
	int pad;

	//画素値を保存する配列を作成
	bmp->pixels = (int*)malloc((bmp->biHeight*bmp->biWidth) * sizeof(int));
	
	//詰め物の幅を計算(ビットマップの幅を4の倍数にする)
	pad = bmp->biWidth % 4;
	if (pad != 0) pad = 4 - pad;

	//画素値を読み込む
	for (h = bmp->biHeight - 1; h >= 0; h--) {
		for(w = 0; w < bmp->biWidth; w++) {
			rc = fread(&color, 1, 3, fp);
			if (rc != 0) {
				bmp->pixels[h*bmp->biWidth+w] = color;
			}
			else {
				printf("エラー：読み込みデータがありません 幅%d高さ%d\n", w, h);
				return -1;
			}
		}
		//詰め物の分を読み捨てる
		for (n = pad; n > 0; n--) {
			rc = fread(&color, 1, 3, fp);
			if (rc == 0) {
				printf("エラー：読み込みデータがありません 幅%d高さ%d\n", w, h);
				return -1;
			}
		}
	}

	printf("正常に画像データを読み込みました\n\n");

	return 0;

}

//SADマッチング(画素値の差分の絶対値の和を計算)
long int SADmatching(BMP *input, BMP *trim, int num) {
	int x, y;
	int w, h;

	long int sad=0;
	int result;

	//画素値取得用
	int r=0x000011;
	//今回のビットマップはr=g=bだったため割愛
	//int g=0x001100;
	//int b=0x110000;

	//対象の画素値
	int Icolor,Tcolor;

	//検査する画素値のずれを計算
	x = num % input->biWidth;
	y = num / input->biWidth;
	
	//トリミング画像のすべての画素値を計算
	for (h = 0; h < trim->biHeight; h++) {
		for (w = 0; w < trim->biWidth; w++) {

			//ビット演算により画素値を取得
			Icolor = input->pixels[((y + h)*input->biWidth) + (x + w)] & r;
			Tcolor = trim->pixels[(h*trim->biWidth) + w] & r;

			//result = abs(Icolor - Tcolor);
			sad += abs(Icolor - Tcolor);
			//sadが大きくなりすぎたら中止
			if (sad < 0) return -1;
		}
	}

	return sad;
}
