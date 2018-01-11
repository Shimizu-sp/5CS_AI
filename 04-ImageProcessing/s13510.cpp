#include<stdlib.h>
#include<stdio.h>
#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;
void matching1();
void matching2();


void main(){
	//テンプレート1でのテンプレートマッチング
	printf("matching1結果　使用画像：img_1.bmp Timg_1.bmp\n");
	matching1();

	
	//テンプレート2でのテンプレートマッチング
	printf("matching2結果 使用画像：img_2.bmp Timg_2.bmp\n");
	matching2();
}

void matching1(){
	Mat src_image1;
	Mat src_tmp1;
	Mat result_image3;

	double pv = 0;

	//画像読み込み
	src_image1 = imread("img_1.bmp", 0);
	src_tmp1 = imread("Timg_1.bmp", 0);

	//テンプレートマッチングの計算
	matchTemplate(src_image1, src_tmp1, result_image3, CV_TM_CCORR_NORMED);
	Rect roi_rect(0, 0, src_tmp1.cols, src_tmp1.rows);
	Point max_pt;
	//類似度が最大・最小となる画素の位置の取得
	minMaxLoc(result_image3, NULL, NULL, NULL, &max_pt);
	roi_rect.x = max_pt.x;
	roi_rect.y = max_pt.y;

	//一致する部分を囲む
	rectangle(src_image1, Point(roi_rect.x, roi_rect.y), Point(roi_rect.x + src_tmp1.cols, roi_rect.y + src_tmp1.rows), Scalar(0, 0, 0), 3, 4);


	//座標表示
	printf("座標 x=%d y=%d\n", roi_rect.x, roi_rect.y);


	imshow("Timg_1", src_image1);
}

void matching2(){
	Mat src_image1;
	Mat src_tmp1;
	Mat result_image3;

	double pv = 0;

	//画像読み込み
	src_image1 = imread("img_2.bmp", 0);
	src_tmp1 = imread("Timg_2.bmp", 0);
	

	//テンプレートマッチングの計算(テンプレート2)
	matchTemplate(src_image1, src_tmp1, result_image3, CV_TM_CCORR_NORMED);
	Rect roi_rect(0, 0, src_tmp1.cols, src_tmp1.rows);
	Point max_pt;
	//類似度が最大・最小となる画素の位置の取得
	minMaxLoc(result_image3, NULL, NULL, NULL, &max_pt);
	roi_rect.x = max_pt.x;
	roi_rect.y = max_pt.y;

	//マッチング部分を囲む
	rectangle(src_image1, Point(roi_rect.x, roi_rect.y), Point(roi_rect.x + src_tmp1.cols, roi_rect.y + src_tmp1.rows), Scalar(0, 0, 0), 3, 4);

	//座標表示
	printf("座標 x=%d y=%d\n", roi_rect.x, roi_rect.y);

	imshow("Timg_2", src_image1);
	waitKey(0);

}