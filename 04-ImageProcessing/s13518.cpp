// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{

	//原画像読み込み
	Mat ol_image1 = imread("images/img_1.bmp",1);
	if (ol_image1.empty()) return -1;
	
	Mat ol_image2 = imread("images/img_2.bmp", 1);
	if (ol_image2.empty()) return -1;
	
	//テンプレート読み込み
	Mat tm_image1 = imread("images/Timg_1.bmp");
	if (ol_image1.empty()) return -1;

	Mat tm_image2 = imread("images/Timg_2.bmp");
	if (ol_image2.empty()) return -1;

	
	//テンプレートマッチング
	Mat result1;
	matchTemplate(ol_image1,tm_image1,result1, TM_CCORR_NORMED);

	Mat result2;
	matchTemplate(ol_image2, tm_image2, result2, TM_CCORR_NORMED);

	//マッチング点を求める
	Point maxPt1;
	minMaxLoc(result1,0,0,0, &maxPt1);

	Point maxPt2;
	minMaxLoc(result2, 0, 0, 0, &maxPt2);

	//マッチングを表示する
	rectangle(ol_image1, maxPt1, Point(maxPt1.x + tm_image1.cols, maxPt1.y + tm_image1.rows ),Scalar(0,255,255),2,8,0);
	printf("anser1 x=%d y=%d\n",maxPt1.x,maxPt1.y);

	rectangle(ol_image2, maxPt2, Point(maxPt2.x + tm_image2.cols, maxPt2.y + tm_image2.rows), Scalar(0, 255, 255), 2, 8, 0);
	printf("anser2 x=%d y=%d\n", maxPt2.x, maxPt2.y);

	waitKey(0);
    return 0;
}

