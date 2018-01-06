#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;
	printf("�ǂ���̉摜�̃e���v���[�g�}�b�`���O���s���܂����H\n1.img_1\n2.img_2\n");
	scanf("%d", &i);

	switch (i) {
	case(1):
		//�e�摜�̓ǂݍ���
		Mat image_1 = imread("img_1.bmp");
		namedWindow("���̉摜(img_1)");
		imshow("���̉摜(img_1)", img_1);
		//img_1.bmp�̓ǂݍ��݂ƕ\��

		Mat Timg_1 = imread("Timg_1.bmp");
		namedWindow("�e���v���[�g�摜(Timg_1)");
		imshow("�e���v���[�g�摜(Timg_1)", Timg_1);
		//Timg_1.bmp�̓ǂݍ��݂ƕ\��

		//img_1��Timg_1�̃e���v���[�g�}�b�`���O
		Mat result_1;
		matchTemplate(img_1, Timg_1, result, TM_CCORR_NORED);
		namedWindow("�}�b�`���O�摜_1");
		imshow("�}�b�`���O�摜", result_1);
		Point maxPt;
		minMaxLoc(result_1, 0, 0, 0, &maxPt);
		//�}�b�`���O�̕\��
		rectangle(img_1, maxPt, Point(maxPt.x + Timg_1.cols, maxPt.y + Timg_1.rows), Scalar(0, 255, 255), 2, 8, 0);
		namedWindow("img_1��Timg_1�̃}�b�`���O�\��");
		imshow("img_1��Timg_1�̃}�b�`���O�\��", img_1)

			break;

	case(2):
		image_2 = imread("img_2.bmp");
		namedWindow("���̉摜(img_2)");
		imshow("���̉摜(img_2)", img_2);
		//img_2.bmp�̓ǂݍ��݂ƕ\��

		Timg_2 = imread("Timg_2.bmp");
		namedWindow("�e���v���[�g�摜(Timg_2)");
		imshow("�e���v���[�g�摜(Timg_2)", Timg_2);
		//Timg_2.bmp�̓ǂݍ��݂ƕ\��

		//img_2��Timg_2�̃e���v���[�g�}�b�`���O
		Mat result_2;
		matchTemplate(img_2, Timg_2, result, TM_CCORR_NORED);
		namedWindow("�}�b�`���O�摜_2");
		imshow("�}�b�`���O�摜", result_2);
		Point maxPt;
		minMaxLoc(result_2, 0, 0, 0, &maxPt);
		//�}�b�`���O�̕\��
		rectangle(img_2, maxPt, Point(maxPt.x + Timg_2.cols, maxPt.y + Timg_2.rows), Scalar(0, 255, 255), 2, 8, 0);
		namedWindow("img_2��Timg_2�̃}�b�`���O�\��");
		imshow("img_2��Timg_2�̃}�b�`���O�\��", img_2)

			break;

	default:
		printf("�l������������܂���\n");
		break;
	}
}