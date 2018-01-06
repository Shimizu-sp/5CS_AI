// ConsoleApplication1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{

	//���摜�ǂݍ���
	Mat ol_image1 = imread("img_1.bmp",1);
	if (ol_image1.empty()) return -1;
	
	Mat ol_image2 = imread("img_2.bmp", 1);
	if (ol_image2.empty()) return -1;
	
	//�e���v���[�g�ǂݍ���
	Mat tm_image1 = imread("Timg_1.bmp");
	if (ol_image1.empty()) return -1;

	Mat tm_image2 = imread("Timg_2.bmp");
	if (ol_image2.empty()) return -1;

	
	//�e���v���[�g�}�b�`���O
	Mat result1;
	matchTemplate(ol_image1,tm_image1,result1, TM_CCORR_NORMED);

	Mat result2;
	matchTemplate(ol_image2, tm_image2, result2, TM_CCORR_NORMED);

	//�}�b�`���O�_�����߂�
	Point maxPt1;
	minMaxLoc(result1,0,0,0, &maxPt1);

	Point maxPt2;
	minMaxLoc(result2, 0, 0, 0, &maxPt2);

	//�}�b�`���O��\������
	rectangle(ol_image1, maxPt1, Point(maxPt1.x + tm_image1.cols, maxPt1.y + tm_image1.rows ),Scalar(0,255,255),2,8,0);
	printf("anser1 x=%d y=%d\n",maxPt1.x,maxPt1.y);

	rectangle(ol_image2, maxPt2, Point(maxPt2.x + tm_image2.cols, maxPt2.y + tm_image2.rows), Scalar(0, 255, 255), 2, 8, 0);
	printf("anser2 x=%d y=%d\n", maxPt2.x, maxPt2.y);

	waitKey(0);
    return 0;
}

