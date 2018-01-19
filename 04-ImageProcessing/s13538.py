#-*- coding:utf-8 -*-
import cv2
import numpy as np

def main():
    # 入力画像とテンプレート画像を取得
    img1 = cv2.imread("images/img_1.bmp")
    temp1 = cv2.imread("images/Timg_1.bmp")

    img2 = cv2.imread("images/img_2.bmp")
    temp2 = cv2.imread("images/Timg_2.bmp")


    # グレースケールに変換
    Gimg1 = cv2.cvtColor(img1, cv2.COLOR_RGB2GRAY)
    Gtemp1 = cv2.cvtColor(temp1, cv2.COLOR_RGB2GRAY)
    
    Gimg2 = cv2.cvtColor(img2, cv2.COLOR_RGB2GRAY)   
    Gtemp2 = cv2.cvtColor(temp2, cv2.COLOR_RGB2GRAY)
    
    # opencvでテンプレートマッチング(差の二乗和)
    match1 = cv2.matchTemplate(Gimg1, Gtemp1, cv2.TM_SQDIFF)
    min_value1, max_value1, min_pt1, max_pt1 = cv2.minMaxLoc(match1)
    pt1 = min_pt1

    match2 = cv2.matchTemplate(Gimg2, Gtemp2, cv2.TM_SQDIFF)
    min_value2, max_value2, min_pt2, max_pt2 = cv2.minMaxLoc(match2)
    pt2 = min_pt2

    
    # テンプレートと合致した領域の左上座標(x,y)を表示
    print('img_1:({0},{1})'.format(pt1[0],pt1[1]))
    print('img_2:({0},{1})'.format(pt2[0],pt2[1]))

if __name__ == "__main__":
    main()
