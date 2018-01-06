#include "stdafx.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(int argc, _TCHAR* argv[]) {
	Mat src_image = imread("img_n.bmp");
	imshow(src_image);
	Mat temp_image = imread("Timg_n.bmp");
	imshow(temp_image);
	Mat result;
	matchTemplate(src_image, temp_image, result, TM_CCORR_NORMED);
	imshow(result);
}
