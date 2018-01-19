#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace cv;

int main(){
	Mat image_src_1;
	Mat image_temp_1;
	Mat image_result_1;

	Mat image_src_2;
	Mat image_temp_2;
	Mat image_result_2;

	int x = 10000000;
	int y = 10000000;

	

	//画像1
	image_src_1 = imread("imagas/img_1.bmp");
	image_temp_1 = imread("images/Timg_1.bmp");

	namedWindow("元画像_画像1");
	imshow("元画像_画像1", image_src_1);
	namedWindow("テンプレート_画像1");
	imshow("テンプレート_画像1", image_temp_1);

	//そのまま探索
	matchTemplate(image_src_1, image_temp_1, image_result_1, CV_TM_CCORR);
	Point max_1;
	minMaxLoc(image_result_1, 0, 0, 0, &max_1);
	rectangle(image_src_1, max_1, Point(max_1.x + image_temp_1.cols, max_1.y + image_temp_1.rows), Scalar(0, 0, 255), 2, 8, 0);
	printf("画像1_1...max.x:%d,max.y:%d\n", max_1.x, max_1.y);
	
	if (x > max_1.x&&y > max_1.y){
		x = max_1.x;
		y = max_1.y;
	}

	circle(image_src_1, Point(max_1.x, max_1.y), 3, Scalar(0, 255, 0),-1);

	//左に90度回転させて探索
	Point2f center = Point2f(static_cast<float>(image_temp_1.cols / 2), static_cast<float>(image_temp_1.rows / 2));
	double angle = 90.0;
	double scale = 1.0;

	Mat affine;
	getRotationMatrix2D(center, angle, scale).copyTo(affine);

	int ipf = INTER_CUBIC;

	warpAffine(image_temp_1, image_temp_1, affine, image_temp_1.size(), ipf);

	namedWindow("テンプレート_画像1_90");
	imshow("テンプレート_画像1_90", image_temp_1);

	matchTemplate(image_src_1, image_temp_1, image_result_1, CV_TM_CCORR);
	minMaxLoc(image_result_1, 0, 0, 0, &max_1);
	rectangle(image_src_1, max_1, Point(max_1.x + image_temp_1.cols, max_1.y + image_temp_1.rows), Scalar(0, 0, 255), 2, 8, 0);
	printf("画像1_2...max.x:%d,max.y:%d\n", max_1.x, max_1.y);

	if (x > max_1.x&&y > max_1.y){
		x = max_1.x;
		y = max_1.y;
	}

	circle(image_src_1, Point(max_1.x, max_1.y), 3, Scalar(0, 255, 0), -1);

	//左に180度回転させて探索
	center = Point2f(static_cast<float>(image_temp_1.cols / 2), static_cast<float>(image_temp_1.rows / 2));
	angle = 180.0;
	scale = 1.0;

	getRotationMatrix2D(center, angle, scale).copyTo(affine);

	ipf = INTER_CUBIC;

	warpAffine(image_temp_1, image_temp_1, affine, image_temp_1.size(), ipf);

	namedWindow("テンプレート_画像1_180");
	imshow("テンプレート_画像1_180", image_temp_1);

	matchTemplate(image_src_1, image_temp_1, image_result_1, CV_TM_CCORR);
	minMaxLoc(image_result_1, 0, 0, 0, &max_1);
	rectangle(image_src_1, max_1, Point(max_1.x + image_temp_1.cols, max_1.y + image_temp_1.rows), Scalar(0, 0, 255), 2, 8, 0);
	printf("画像1_3...max.x:%d,max.y:%d\n", max_1.x, max_1.y);

	if (x > max_1.x&&y > max_1.y){
		x = max_1.x;
		y = max_1.y;
	}

	circle(image_src_1, Point(max_1.x, max_1.y), 3, Scalar(0, 255, 0), -1);

	//左に270度回転させて探索
	center = Point2f(static_cast<float>(image_temp_1.cols / 2), static_cast<float>(image_temp_1.rows / 2));
	angle = 270.0;
	scale = 1.0;

	getRotationMatrix2D(center, angle, scale).copyTo(affine);

	ipf = INTER_CUBIC;

	warpAffine(image_temp_1, image_temp_1, affine, image_temp_1.size(), ipf);

	namedWindow("テンプレート_画像1_270");
	imshow("テンプレート_画像1_270", image_temp_1);

	matchTemplate(image_src_1, image_temp_1, image_result_1, CV_TM_CCORR);
	minMaxLoc(image_result_1, 0, 0, 0, &max_1);
	rectangle(image_src_1, max_1, Point(max_1.x + image_temp_1.cols, max_1.y + image_temp_1.rows), Scalar(0, 0, 255), 2, 8, 0);
	printf("画像1_4...max.x:%d,max.y:%d\n", max_1.x, max_1.y);

	if (x > max_1.x&&y > max_1.y){
		x = max_1.x;
		y = max_1.y;
	}

	circle(image_src_1, Point(max_1.x, max_1.y), 3, Scalar(0, 255, 0), -1);


	//結果表示
	namedWindow("結果_画像1");
	imshow("結果_画像1", image_src_1);
	printf("x=%d,y=%d\n", x, y);

	

	


	//画像2
	image_src_2 = imread("images/img_2.bmp");
	image_temp_2 = imread("images/Timg_2.bmp");

	namedWindow("元画像_画像2");
	imshow("元画像_画像2", image_src_2);
	namedWindow("テンプレート_画像2");
	//imshow("テンプレート_画像2", image_temp_2);

	//そのまま探索
	matchTemplate(image_src_2, image_temp_2, image_result_2, CV_TM_CCORR);
	Point max_2;
	minMaxLoc(image_result_2, 0, 0, 0, &max_2);
	rectangle(image_src_2, max_2, Point(max_2.x + image_temp_2.cols, max_2.y + image_temp_2.rows), Scalar(0, 0, 255), 2, 8, 0);
	printf("画像2_1...max.x:%d,max.y:%d\n", max_2.x, max_2.y);

	if (x > max_2.x&&y > max_2.y){
	x = max_2.x;
	y = max_2.y;
	}

	circle(image_src_2, Point(max_2.x, max_2.y), 3, Scalar(0, 255, 0),-1);

	//左に90度回転させて探索
	Mat image_temp_2_90(Size(image_temp_2.rows, image_temp_2.cols), CV_8U, Scalar::all(0));

	Point2f center_2 = Point2f(static_cast<float>(image_temp_2.cols / 2), static_cast<float>(image_temp_2.rows / 2));
	imshow("テンプレート_画像2", image_temp_2);

	double angle_2 = 90.0;
	double scale_2 = 1.0;

	Mat affine_2;
	getRotationMatrix2D(center_2, angle_2, scale_2).copyTo(affine_2);

	int ipf_2 = INTER_CUBIC;

	warpAffine(image_temp_2, image_temp_2_90, affine_2, image_temp_2_90.size(), ipf_2);

	namedWindow("テンプレート_画像2_90");
	imshow("テンプレート_画像2_90", image_temp_2_90);

	matchTemplate(image_src_2, image_temp_2_90, image_result_2, CV_TM_CCORR);
	minMaxLoc(image_result_2, 0, 0, 0, &max_2);
	rectangle(image_src_2, max_2, Point(max_2.x + image_temp_2_90.cols, max_2.y + image_temp_2_90.rows), Scalar(0, 0, 255), 2, 8, 0);
	printf("画像2_2...max.x:%d,max.y:%d\n", max_2.x, max_2.y);

	if (x > max_2.x&&y > max_2.y){
	x = max_2.x;
	y = max_2.y;
	}

	circle(image_src_2, Point(max_2.x, max_2.y), 3, Scalar(0, 255, 0), -1);

	//左に180度回転させて探索
	center_2 = Point2f(static_cast<float>(image_temp_2.cols / 2), static_cast<float>(image_temp_2.rows / 2));
	angle_2 = 180.0;
	scale_2 = 1.0;

	affine_2;
	getRotationMatrix2D(center_2, angle_2, scale_2).copyTo(affine_2);

	ipf_2 = INTER_CUBIC;

	warpAffine(image_temp_2, image_temp_2, affine_2, image_temp_2.size(), ipf_2);

	namedWindow("テンプレート_画像2_180");
	imshow("テンプレート_画像2_180", image_temp_2);

	matchTemplate(image_src_2, image_temp_2, image_result_2, CV_TM_CCORR);
	minMaxLoc(image_result_2, 0, 0, 0, &max_2);
	rectangle(image_src_2, max_2, Point(max_2.x + image_temp_2.cols, max_2.y + image_temp_2.rows), Scalar(0, 0, 255), 2, 8, 0);
	printf("画像2_3...max.x:%d,max.y:%d\n", max_2.x, max_2.y);

	if (x > max_2.x&&y > max_2.y){
		x = max_2.x;
		y = max_2.y;
	}

	circle(image_src_2, Point(max_2.x, max_2.y), 3, Scalar(0, 255, 0), -1);

	//左に270度回転させて探索
	center_2 = Point2f(static_cast<float>(image_temp_2.cols / 2), static_cast<float>(image_temp_2.rows / 2));
	angle_2 = 270.0;
	scale_2 = 1.0;

	affine_2;
	getRotationMatrix2D(center_2, angle_2, scale_2).copyTo(affine_2);

	ipf_2 = INTER_CUBIC;

	warpAffine(image_temp_2, image_temp_2, affine_2, image_temp_2.size(), ipf_2);

	namedWindow("テンプレート_画像2_270");
	imshow("テンプレート_画像2_270", image_temp_2);

	matchTemplate(image_src_2, image_temp_2, image_result_2, CV_TM_CCORR);
	minMaxLoc(image_result_2, 0, 0, 0, &max_2);
	rectangle(image_src_2, max_2, Point(max_2.x + image_temp_2.cols, max_2.y + image_temp_2.rows), Scalar(0, 0, 255), 2, 8, 0);
	printf("画像2_4...max.x:%d,max.y:%d\n", max_2.x, max_2.y);

	if (x > max_2.x&&y > max_2.y){
		x = max_2.x;
		y = max_2.y;
	}

	circle(image_src_2, Point(max_2.x, max_2.y), 3, Scalar(0, 255, 0), -1);

	//結果表示
	namedWindow("結果_画像2");
	imshow("結果_画像2", image_src_2);
	printf("x=%d,y=%d\n", x, y);



	waitKey(0);

}