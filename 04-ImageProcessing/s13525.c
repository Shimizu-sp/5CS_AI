#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;
	printf("どちらの画像のテンプレートマッチングを行いますか？\n1.img_1\n2.img_2\n");
	scanf("%d", &i);

	switch (i) {
	case(1):
		//各画像の読み込み
		Mat image_1 = imread("img_1.bmp");
		namedWindow("元の画像(img_1)");
		imshow("元の画像(img_1)", img_1);
		//img_1.bmpの読み込みと表示

		Mat Timg_1 = imread("Timg_1.bmp");
		namedWindow("テンプレート画像(Timg_1)");
		imshow("テンプレート画像(Timg_1)", Timg_1);
		//Timg_1.bmpの読み込みと表示

		//img_1とTimg_1のテンプレートマッチング
		Mat result_1;
		matchTemplate(img_1, Timg_1, result, TM_CCORR_NORED);
		namedWindow("マッチング画像_1");
		imshow("マッチング画像", result_1);
		Point maxPt;
		minMaxLoc(result_1, 0, 0, 0, &maxPt);
		//マッチングの表示
		rectangle(img_1, maxPt, Point(maxPt.x + Timg_1.cols, maxPt.y + Timg_1.rows), Scalar(0, 255, 255), 2, 8, 0);
		namedWindow("img_1とTimg_1のマッチング表示");
		imshow("img_1とTimg_1のマッチング表示", img_1)

			break;

	case(2):
		image_2 = imread("img_2.bmp");
		namedWindow("元の画像(img_2)");
		imshow("元の画像(img_2)", img_2);
		//img_2.bmpの読み込みと表示

		Timg_2 = imread("Timg_2.bmp");
		namedWindow("テンプレート画像(Timg_2)");
		imshow("テンプレート画像(Timg_2)", Timg_2);
		//Timg_2.bmpの読み込みと表示

		//img_2とTimg_2のテンプレートマッチング
		Mat result_2;
		matchTemplate(img_2, Timg_2, result, TM_CCORR_NORED);
		namedWindow("マッチング画像_2");
		imshow("マッチング画像", result_2);
		Point maxPt;
		minMaxLoc(result_2, 0, 0, 0, &maxPt);
		//マッチングの表示
		rectangle(img_2, maxPt, Point(maxPt.x + Timg_2.cols, maxPt.y + Timg_2.rows), Scalar(0, 255, 255), 2, 8, 0);
		namedWindow("img_2とTimg_2のマッチング表示");
		imshow("img_2とTimg_2のマッチング表示", img_2)

			break;

	default:
		printf("値が正しくありません\n");
		break;
	}
}