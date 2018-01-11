#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int
main(int argc, char **argv)
{
	cv::Mat search_img = cv::imread("img/img_1.bmp", 1);
	cv::Mat tmp_img = cv::imread("img/Timg_1.bmp", 1);

	cv::cvtColor(search_img, search_img, CV_BGR2GRAY);//グレースケールに変更
	//cv::equalizeHist(search_img, search_img);//ヒストグラム均一化

	cv::cvtColor(tmp_img, tmp_img, CV_BGR2GRAY);//グレースケールに変更
	//cv::equalizeHist(tmp_img, tmp_img);//ヒストグラム均一化

	cv::Mat result_img;
	cv::matchTemplate(search_img, tmp_img, result_img, 3);

	cv::Rect roi_rect(0, 0, tmp_img.cols, tmp_img.rows);
	cv::Point max_pt;
	double maxVal;
	cv::minMaxLoc(result_img, NULL, &maxVal, NULL, &max_pt);
	roi_rect.x = max_pt.x;
	roi_rect.y = max_pt.y;

	std::cout << "(" << max_pt.x << "," << max_pt.y << ") score="
		<< maxVal << std::endl;
	cv::rectangle(search_img, roi_rect, cv::Scalar(0, 0, 255, 3));

	std::cout << "rectangle: (" << roi_rect.x << ", " <<
		roi_rect.y << ") size (" << roi_rect.width << ", " <<
		roi_rect.height << ")" << std::endl;

	imshow("result_1", search_img);
	cv::imwrite("output_1.png", search_img);

	search_img = cv::imread("img/img_2.bmp", 1);
	tmp_img = cv::imread("img/Timg_2.bmp", 1);

	cv::cvtColor(search_img, search_img, CV_BGR2GRAY);//グレースケールに変更
													  //cv::equalizeHist(search_img, search_img);//ヒストグラム均一化

	cv::cvtColor(tmp_img, tmp_img, CV_BGR2GRAY);//グレースケールに変更
												//cv::equalizeHist(tmp_img, tmp_img);//ヒストグラム均一化

	
	cv::matchTemplate(search_img, tmp_img, result_img, 3);

	roi_rect.x = 0;
	roi_rect.y = 0;
	max_pt.x = 0;
	max_pt.y = 0;
	maxVal = 0;
	cv::minMaxLoc(result_img, NULL, &maxVal, NULL, &max_pt);
	roi_rect.x = max_pt.x;
	roi_rect.y = max_pt.y;

	std::cout << "(" << max_pt.x << "," << max_pt.y << ") score="
		<< maxVal << std::endl;
	cv::rectangle(search_img, roi_rect, cv::Scalar(0, 0, 255, 3));

	std::cout << "rectangle: (" << roi_rect.x << ", " <<
		roi_rect.y << ") size (" << roi_rect.width << ", " <<
		roi_rect.height << ")" << std::endl;

	imshow("result_2", search_img);

	cv::imwrite("output_2.png", search_img);

	getchar();
	return 0;
}