{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 5,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "img_1のテンプレートマッチング結果\n",
      "(275, 104)\n",
      "(37, 171)\n",
      "img_2のテンプレートマッチング結果\n",
      "(15, 358)\n",
      "(216, 6)\n"
     ]
    }
   ],
   "source": [
    "import cv2# opencvをインポート\n",
    "import numpy as np# numpyをインポート\n",
    "from matplotlib import pyplot as plt\n",
    "from PIL import Image# PILをインポート\n",
    "\n",
    "\n",
    "def print_args_1(angle):# 画像回転用関数\n",
    "    im = Image.open('Timg_1.bmp')# Timg_1.bmpを読み込む\n",
    "    im_rotate = im.rotate(90, expand=True)  # 画像を90度回転させ、expandをTrueにすることで画像全体を回転させる\n",
    "    im_rotate.save('output.bmp')# 回転させた画像をoutput.bmpとして保存\n",
    "    return 0\n",
    "\n",
    "def print_args_2(angle):  # 画像回転用関数\n",
    "    im = Image.open('Timg_2.bmp')# Timn_2.bmpを読み込む\n",
    "    im_rotate = im.rotate(270, expand=True)# 画像を270度回転させ、expandをTrueにすることで画像全体を回転させる\n",
    "    im_rotate.save('output2.bmp')# 回転させた画像をoutput.bmpとして保存\n",
    "    return 0\n",
    "\n",
    "\n",
    "img_rgb = cv2.imread('img_1.bmp')# img_1.bmpを読み込む\n",
    "img_gray = cv2.cvtColor(img_rgb, cv2.COLOR_BGR2GRAY)# グレースケール画像に変換 \n",
    "template = cv2.imread('Timg_1.bmp',0)# Timg_1.bmpをグレースケール画像として読み込む\n",
    "w, h = template.shape[::-1]# テンプレート画像の高さと幅を取得\n",
    "\n",
    "res = cv2.matchTemplate(img_gray,template,cv2.TM_CCOEFF_NORMED)# テンプレートマッチングを実行\n",
    "threshold = 0.96# 類似度を設定\n",
    "loc = np.where( res >= threshold)# 検出結果から検出領域の位置を取得\n",
    "print(\"img_1のテンプレートマッチング結果\")\n",
    "for pt in zip(*loc[::-1]):# ptに位置情報を代入し、それを表示\n",
    "    print(pt)\n",
    "\n",
    "print_args_1(90)# 画像回転用関数を呼び出す\n",
    "template = cv2.imread('output.bmp',0)# 回転させた画像を呼び出す\n",
    "w, h = template.shape[::-1]# 回転させたテンプレート画像の高さと幅を取得\n",
    "\n",
    "res = cv2.matchTemplate(img_gray,template,cv2.TM_CCOEFF_NORMED)# テンプレートマッチングを実行\n",
    "threshold = 0.958# 類似度を設定\n",
    "loc = np.where( res >= threshold)# 検出結果から検出領域の位置を取得\n",
    "for pt in zip(*loc[::-1]):# ptに位置情報を代入し、それを表示\n",
    "    print(pt)\n",
    "\n",
    "    \n",
    "\n",
    "img_rgb = cv2.imread('img_2.bmp')# img_2.bmpを読み込む\n",
    "img_gray = cv2.cvtColor(img_rgb, cv2.COLOR_BGR2GRAY)# グレースケール画像に変換 \n",
    "template = cv2.imread('Timg_2.bmp',0)# Timg_2.bmpをグレースケール画像として読み込む\n",
    "w, h = template.shape[::-1]# テンプレート画像の高さと幅を取得\n",
    "\n",
    "res = cv2.matchTemplate(img_gray,template,cv2.TM_CCOEFF_NORMED)# テンプレートマッチングを実行\n",
    "threshold = 0.984# 類似度を設定\n",
    "loc = np.where( res >= threshold)# 検出結果から検出領域の位置を取得\n",
    "print(\"img_2のテンプレートマッチング結果\")\n",
    "for pt in zip(*loc[::-1]):# ptに位置情報を代入し、それを表示\n",
    "    print(pt)\n",
    "\n",
    "print_args_2(270)# 画像回転用関数を呼び出す\n",
    "template = cv2.imread('output2.bmp',0)# 回転させた画像を呼び出す\n",
    "w, h = template.shape[::-1]# 回転させたテンプレート画像の高さと幅を取得\n",
    "\n",
    "res = cv2.matchTemplate(img_gray,template,cv2.TM_CCOEFF_NORMED)# テンプレートマッチングを実行\n",
    "threshold = 0.994# 類似度を設定\n",
    "loc = np.where( res >= threshold)# 検出結果から検出領域の位置を取得\n",
    "for pt in zip(*loc[::-1]):# ptに位置情報を代入し、それを表示\n",
    "    print(pt)    \n",
    "    "
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.6.3"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
