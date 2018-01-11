#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
	// 探索画像1
	cv::Mat search_img1 = cv::imread("../../images/img_1.bmp", 1);//ソースコードを置いたフォルダの二つ上にimageフォルダを置いた
	if (search_img1.empty()){//探索画像がない場合はプログラムを終了
		std::cout << "探索画像がありません" << std::endl;
		abort();
	}
	// テンプレート画像1
	cv::Mat tmp_img1 = cv::imread("../../images/Timg_1.bmp", 1);
	if (tmp_img1.empty()) {
		std::cout << "テンプレート画像がありません" << std::endl;
		abort();
	}

	// 探索画像2
	cv::Mat search_img2 = cv::imread("../../images/img_2.bmp", 1);
	if (search_img2.empty()){
		std::cout << "探索画像がありません" << std::endl;
		abort();
	}
	// テンプレート画像2
	cv::Mat tmp_img2 = cv::imread("../../images/Timg_2.bmp", 1);
	if (tmp_img2.empty()) { 
		std::cout << "テンプレート画像がありません" << std::endl;
		abort();
	}


	cv::Mat result_img;
	// テンプレートマッチング
	cv::matchTemplate(search_img1, tmp_img1, result_img, CV_TM_CCOEFF_NORMED);

	// 類似度が最大のスコアの場所を探す
	cv::Rect roi_rect1(0, 0, tmp_img1.cols, tmp_img1.rows);
	cv::Point max_pt;
	double maxVal;
	cv::minMaxLoc(result_img, NULL, &maxVal, NULL, &max_pt);

	roi_rect1.x = max_pt.x;
	roi_rect1.y = max_pt.y;
	std::cout << "左上座標(" << max_pt.x << ", " << max_pt.y << "), score=" << maxVal << std::endl;
	// 探索結果の場所に矩形を描画
	cv::rectangle(search_img1, roi_rect1, cv::Scalar(0, 0, 255), 3);

	cv::namedWindow("探索画像1", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::namedWindow("結果", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::imshow("探索画像1", search_img1);
	cv::imshow("結果", result_img);
	//入力待ち
	cv::waitKey(0);
	//ウィンドウを消去
	cv::destroyWindow("探索画像1");
	cv::destroyWindow("結果");

	// テンプレートマッチング
	cv::matchTemplate(search_img2, tmp_img2, result_img, CV_TM_CCOEFF_NORMED);
	// 類似度が最大のスコアの場所を探す
	cv::Rect roi_rect2(0, 0, tmp_img2.cols, tmp_img2.rows);
	cv::minMaxLoc(result_img, NULL, &maxVal, NULL, &max_pt);
	roi_rect2.x = max_pt.x;
	roi_rect2.y = max_pt.y;
	std::cout << "左上座標(" << max_pt.x << ", " << max_pt.y << "), score=" << maxVal << std::endl;
	// 探索結果の場所に矩形を描画
	cv::rectangle(search_img2, roi_rect2, cv::Scalar(0, 0, 255), 3);

	cv::namedWindow("探索画像2", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::namedWindow("結果", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::imshow("探索画像2", search_img2);
	cv::imshow("結果", result_img);
	//入力待ち
	cv::waitKey(0);
}