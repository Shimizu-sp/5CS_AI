import cv2
#画像をグレースケールで読み込む
temp_1 =cv2.imread("Timg_1.bmp")
data_1 =cv2.imread("img_1.bmp")
temp_2 =cv2.imread("Timg_2.bmp")
data_2 =cv2.imread("img_2.bmp")
#差の絶対値の和で画像の類似度を出す
match_1=cv2.matchTemplate(data_1, temp_1, cv2.TM_SQDIFF_NORMED)
match_2=cv2.matchTemplate(data_2, temp_2, cv2.TM_SQDIFF_NORMED)

#match_～の最小の類似度をだす
min_val_1, max_val_1, min_loc_1, max_loc_1 = cv2.minMaxLoc(match_1) 
min_val_2, max_val_2, min_loc_2, max_loc_2 = cv2.minMaxLoc(match_2) 
#結果の出力
print("img_1.bmp", min_loc_1)
print("img_1.bmp", min_loc_2)
