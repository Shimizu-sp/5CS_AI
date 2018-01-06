#include<stdlib.h>
#include<stdio.h>
#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;
void matching1();
void matching2();


void main(){
	//�e���v���[�g1�ł̃e���v���[�g�}�b�`���O
	printf("matching1���ʁ@�g�p�摜�Fimg_1.bmp Timg_1.bmp\n");
	matching1();

	
	//�e���v���[�g2�ł̃e���v���[�g�}�b�`���O
	printf("matching2���� �g�p�摜�Fimg_2.bmp Timg_2.bmp\n");
	matching2();
}

void matching1(){
	Mat src_image1;
	Mat src_tmp1;
	Mat result_image3;

	double pv = 0;

	//�摜�ǂݍ���
	src_image1 = imread("img_1.bmp", 0);
	src_tmp1 = imread("Timg_1.bmp", 0);

	//�e���v���[�g�}�b�`���O�̌v�Z
	matchTemplate(src_image1, src_tmp1, result_image3, CV_TM_CCORR_NORMED);
	Rect roi_rect(0, 0, src_tmp1.cols, src_tmp1.rows);
	Point max_pt;
	//�ގ��x���ő�E�ŏ��ƂȂ��f�̈ʒu�̎擾
	minMaxLoc(result_image3, NULL, NULL, NULL, &max_pt);
	roi_rect.x = max_pt.x;
	roi_rect.y = max_pt.y;

	//��v���镔�����͂�
	rectangle(src_image1, Point(roi_rect.x, roi_rect.y), Point(roi_rect.x + src_tmp1.cols, roi_rect.y + src_tmp1.rows), Scalar(0, 0, 0), 3, 4);


	//���W�\��
	printf("���W x=%d y=%d\n", roi_rect.x, roi_rect.y);


	imshow("Timg_1", src_image1);
}

void matching2(){
	Mat src_image1;
	Mat src_tmp1;
	Mat result_image3;

	double pv = 0;

	//�摜�ǂݍ���
	src_image1 = imread("img_2.bmp", 0);
	src_tmp1 = imread("Timg_2.bmp", 0);
	

	//�e���v���[�g�}�b�`���O�̌v�Z(�e���v���[�g2)
	matchTemplate(src_image1, src_tmp1, result_image3, CV_TM_CCORR_NORMED);
	Rect roi_rect(0, 0, src_tmp1.cols, src_tmp1.rows);
	Point max_pt;
	//�ގ��x���ő�E�ŏ��ƂȂ��f�̈ʒu�̎擾
	minMaxLoc(result_image3, NULL, NULL, NULL, &max_pt);
	roi_rect.x = max_pt.x;
	roi_rect.y = max_pt.y;

	//�}�b�`���O�������͂�
	rectangle(src_image1, Point(roi_rect.x, roi_rect.y), Point(roi_rect.x + src_tmp1.cols, roi_rect.y + src_tmp1.rows), Scalar(0, 0, 0), 3, 4);

	//���W�\��
	printf("���W x=%d y=%d\n", roi_rect.x, roi_rect.y);

	imshow("Timg_2", src_image1);
	waitKey(0);

}