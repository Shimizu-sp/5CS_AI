#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
	// �T���摜1
	cv::Mat search_img1 = cv::imread("../../images/img_1.bmp", 1);//�\�[�X�R�[�h��u�����t�H���_�̓���image�t�H���_��u����
	if (search_img1.empty()){//�T���摜���Ȃ��ꍇ�̓v���O�������I��
		std::cout << "�T���摜������܂���" << std::endl;
		abort();
	}
	// �e���v���[�g�摜1
	cv::Mat tmp_img1 = cv::imread("../../images/Timg_1.bmp", 1);
	if (tmp_img1.empty()) {
		std::cout << "�e���v���[�g�摜������܂���" << std::endl;
		abort();
	}

	// �T���摜2
	cv::Mat search_img2 = cv::imread("../../images/img_2.bmp", 1);
	if (search_img2.empty()){
		std::cout << "�T���摜������܂���" << std::endl;
		abort();
	}
	// �e���v���[�g�摜2
	cv::Mat tmp_img2 = cv::imread("../../images/Timg_2.bmp", 1);
	if (tmp_img2.empty()) { 
		std::cout << "�e���v���[�g�摜������܂���" << std::endl;
		abort();
	}


	cv::Mat result_img;
	// �e���v���[�g�}�b�`���O
	cv::matchTemplate(search_img1, tmp_img1, result_img, CV_TM_CCOEFF_NORMED);

	// �ގ��x���ő�̃X�R�A�̏ꏊ��T��
	cv::Rect roi_rect1(0, 0, tmp_img1.cols, tmp_img1.rows);
	cv::Point max_pt;
	double maxVal;
	cv::minMaxLoc(result_img, NULL, &maxVal, NULL, &max_pt);

	roi_rect1.x = max_pt.x;
	roi_rect1.y = max_pt.y;
	std::cout << "������W(" << max_pt.x << ", " << max_pt.y << "), score=" << maxVal << std::endl;
	// �T�����ʂ̏ꏊ�ɋ�`��`��
	cv::rectangle(search_img1, roi_rect1, cv::Scalar(0, 0, 255), 3);

	cv::namedWindow("�T���摜1", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::namedWindow("����", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::imshow("�T���摜1", search_img1);
	cv::imshow("����", result_img);
	//���͑҂�
	cv::waitKey(0);
	//�E�B���h�E������
	cv::destroyWindow("�T���摜1");
	cv::destroyWindow("����");

	// �e���v���[�g�}�b�`���O
	cv::matchTemplate(search_img2, tmp_img2, result_img, CV_TM_CCOEFF_NORMED);
	// �ގ��x���ő�̃X�R�A�̏ꏊ��T��
	cv::Rect roi_rect2(0, 0, tmp_img2.cols, tmp_img2.rows);
	cv::minMaxLoc(result_img, NULL, &maxVal, NULL, &max_pt);
	roi_rect2.x = max_pt.x;
	roi_rect2.y = max_pt.y;
	std::cout << "������W(" << max_pt.x << ", " << max_pt.y << "), score=" << maxVal << std::endl;
	// �T�����ʂ̏ꏊ�ɋ�`��`��
	cv::rectangle(search_img2, roi_rect2, cv::Scalar(0, 0, 255), 3);

	cv::namedWindow("�T���摜2", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::namedWindow("����", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::imshow("�T���摜2", search_img2);
	cv::imshow("����", result_img);
	//���͑҂�
	cv::waitKey(0);
}