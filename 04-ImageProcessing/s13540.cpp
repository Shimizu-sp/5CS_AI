#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;

int main(void) {
	//opencv320���g�p

	int i=1;

	for (i = 1;i < 3;i++) {
		char base[20], temp[20];

		sprintf_s(base, 20, "images/img_%d.bmp", i); //�t�@�C���̃p�X(���摜)
		sprintf_s(temp, 20, "images/Timg_%d.bmp", i);//�t�@�C���̃p�X(�e���v���[�g�摜)

		Mat image_base = imread(base); //���摜�̓ǂݍ���

		Mat image_temp = imread(temp); //�e���v���[�g�摜�̓ǂݍ���

		//�e���v���[�g�摜�̕\��
		namedWindow("Template");
		imshow("Template", image_temp);

		Mat result;
		matchTemplate(image_base, image_temp, result, TM_CCOEFF_NORMED); //�A���S���Y���Ɋ�Â����e���v���[�g�}�b�`���O

		Point rPt; 
		minMaxLoc(result, 0, 0, 0, &rPt); //���ʍ��W�̎擾

		rectangle(image_base, rPt, Point(rPt.x + image_temp.cols, rPt.y + image_temp.rows), Scalar(0, 0, 255), 2, 8, 0); //���摜�Ƀ}�b�`���O�����ӏ��̕`��

		printf("img_%d  %d,%d\n\n",i,rPt.x,rPt.y); //���W�̕\��

		//�}�b�`���O�摜�̕\��
		namedWindow("Matching");
		imshow("Matching", image_base);

		waitKey(0);
		destroyAllWindows();
	}
	return 0;
}