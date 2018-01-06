# -*- coding: utf-8 -*-
import cv2
import sys
import numpy as np


def main():
	print("画像1と画像2のどっちが見たいですか？")
	print("画像1なら1を入力してください。画像2なら2を入力してください。")
	select = input('>> ')
	if select == "1":
		pic1()
	elif select == "2":
		pic2()
	else:
		print("ちゃんと入力してください")
		sys.exit()


#画像1
def pic1():
	#画像の読み込み
	img = cv2.imread("img_1.bmp")
	temp = cv2.imread("Timg_1.bmp")
	yAxis = cv2.flip(temp, 1) #テンプレート画像を左右反転する

	#テンプレートと同じやつがないか調べる
	result = cv2.matchTemplate(img,temp,cv2.TM_SQDIFF) #類似度は差の二乗和を使う(値が小さいほど似ている)
	result_1 = cv2.matchTemplate(img,yAxis,cv2.TM_SQDIFF) #類似度は差の二乗和を使う(値が小さいほど似ている)

	#左上の座標を取得
	min_val,mac_val,min_loc,max_loc = cv2.minMaxLoc(result)
	print("テンプレートと一致した領域の左上座標は"+str(min_loc)+"です")

	min_val_1,mac_val_1,min_loc_1,max_loc_1 = cv2.minMaxLoc(result_1)
	print("テンプレートと一致した領域(左右反転)の左上座標は"+str(min_loc_1)+"です")

	return 0

#画像2
def pic2():
	#画像の読み込み
	img = cv2.imread("img_2.bmp",0)
	temp = cv2.imread("Timg_2.bmp",0)

	#テンプレートと同じやつがないか調べる
	result = cv2.matchTemplate(img,temp,cv2.TM_SQDIFF) #類似度は差の二乗和を使う(値が小さいほど似ている)

	#左上の座標を取得
	min_val,mac_val,min_loc,max_loc = cv2.minMaxLoc(result)
	print("テンプレートと一致した領域の左上座標は"+str(min_loc)+"です")

	return 0

if __name__ == '__main__':
    main()