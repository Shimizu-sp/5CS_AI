import cv2
import numpy as np
from matplotlib import pyplot as plt
from PIL import Image, ImageDraw

img_1 = cv2.imread('images/img_1.bmp')    #画像の読み込み
img_2 = cv2.imread('images/img_2.bmp')    #画像の読み込み

img_1_gray = cv2.cvtColor(img_1, cv2.COLOR_BGR2GRAY)    #グレースケール化
img_2_gray = cv2.cvtColor(img_2, cv2.COLOR_BGR2GRAY)    #グレースケール化

temp_1 = cv2.imread('images/Timg_1.bmp',0)    #テンプレート読み込み
temp_2 = cv2.imread('images/img_2.bmp',0)    #テンプレート読み込み

w1, h1 = temp_1.shape[::-1]     #領域調整
w2, h2 = temp_2.shape[::-1]     #領域調整

result1 = cv2.matchTemplate(img_1_gray,temp_1,cv2.TM_CCOEFF_NORMED)    #正規化相互相関を使用してマッチング
result2 = cv2.matchTemplate(img_2_gray,temp_2,cv2.TM_CCOEFF_NORMED)    #正規化相互相関を使用してマッチング

threshold = 0.8 #係数
loc1 = np.where( result1 >= threshold)
loc2 = np.where( result2 >= threshold)

for pt in zip(*loc1[::-1]):     #マッチング開始
    if(pt[0]==274 and pt[1]==101):
        print('img_1 = [' + str(pt[0]) + ',' + str(pt[1]) + ']' )   #マッチング位置表示
    cv2.rectangle(img_1, pt, (pt[0] + w1, pt[1] + h1), (255,0,0), 2)
for pt in zip(*loc2[::-1]):     #マッチング開始
    if(pt[0]==12 and pt[1]==351):
        print('img_2 = [' + str(pt[0]) + ',' + str(pt[1]) + ']' )   #マッチング位置表示
    cv2.rectangle(img_2, pt, (pt[0] + w2, pt[1] + h2), (255,0,0), 2)

cv2.imwrite('./images/result_img_1.bmp',img_1)  #結果の書き出し
cv2.imwrite('./images/result_img_2.bmp',img_2)  #結果の書き出し
