#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;

int main(void) {
	//opencv320を使用

	int i=1;

	for (i = 1;i < 3;i++) {
		char base[20], temp[20];

		sprintf_s(base, 20, "images/img_%d.bmp", i); //ファイルのパス(元画像)
		sprintf_s(temp, 20, "images/Timg_%d.bmp", i);//ファイルのパス(テンプレート画像)

		Mat image_base = imread(base); //元画像の読み込み

		Mat image_temp = imread(temp); //テンプレート画像の読み込み

		//テンプレート画像の表示
		namedWindow("Template");
		imshow("Template", image_temp);

		Mat result;
		matchTemplate(image_base, image_temp, result, TM_CCOEFF_NORMED); //アルゴリズムに基づいたテンプレートマッチング

		Point rPt; 
		minMaxLoc(result, 0, 0, 0, &rPt); //結果座標の取得

		rectangle(image_base, rPt, Point(rPt.x + image_temp.cols, rPt.y + image_temp.rows), Scalar(0, 0, 255), 2, 8, 0); //元画像にマッチングした箇所の描画

		printf("img_%d  %d,%d\n\n",i,rPt.x,rPt.y); //座標の表示

		//マッチング画像の表示
		namedWindow("Matching");
		imshow("Matching", image_base);

		waitKey(0);
		destroyAllWindows();
	}
	return 0;
}