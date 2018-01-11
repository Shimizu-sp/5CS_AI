import cv2
import numpy as np
from PIL import Image

#画像の読み込み
img = cv2.imread("img_1.bmp", 0)
temp = cv2.imread("Timg_1.bmp", 0)

#cv2.TM_CCOEFF_NORMEDによるテンプレートマチングを行う
result = cv2.matchTemplate(img, temp, cv2.TM_CCOEFF_NORMED)

#検出領域の位置を取得する
min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
top_left = max_loc
w, h = temp.shape[::-1]
bottom_right = (top_left[0] + w, top_left[1] + h)

result = cv2.imread("img_1.bmp")
cv2.rectangle(result,top_left, bottom_right, (255, 0, 0), 2)
cv2.imwrite("result.bmp", result)
#座標の表示
print(top_left)


#指定した画像を縮小する
img = Image.open('Timg_1.bmp')
img_resize = img.resize((100, 100))
#output.bmpに出力する
img_resize.save('output.bmp')

img = cv2.imread("img_1.bmp", 0)
temp = cv2.imread("output.bmp", 0)

#cv2.TM_CCOEFF_NORMEDによるテンプレートマチングを行う
result = cv2.matchTemplate(img, temp, cv2.TM_CCOEFF_NORMED)

#検出領域の位置を取得する
min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
top_left = max_loc
w, h = temp.shape[::-1]
bottom_right = (top_left[0] + w, top_left[1] + h)

result = cv2.imread("result.bmp")
cv2.rectangle(result,top_left, bottom_right, (255, 0, 0), 2)
cv2.imwrite("result.bmp", result)
#座標の表示
print(top_left)


#指定した画像を回転させる
img = Image.open('Timg_1.bmp')
img_rotate = img.rotate(90)
#output.bmpに出力する
img_rotate.save('output.bmp')

img = cv2.imread("img_1.bmp", 0)
temp = cv2.imread("output.bmp", 0)

#cv2.TM_CCOEFF_NORMEDによるテンプレートマチングを行う
result = cv2.matchTemplate(img, temp, cv2.TM_CCOEFF_NORMED)

#検出領域の位置を取得する
min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
top_left = max_loc
w, h = temp.shape[::-1]
bottom_right = (top_left[0] + w, top_left[1] + h)

result = cv2.imread("result.bmp")
cv2.rectangle(result,top_left, bottom_right, (255, 0, 0), 2)
cv2.imwrite("result.bmp", result)
#座標の表示
print(top_left)



im = Image.open('result.bmp')
im.show()


#画像の読み込み
img = cv2.imread("img_2.bmp", 0)
temp = cv2.imread("Timg_2.bmp", 0)

#cv2.TM_CCOEFF_NORMEDによるテンプレートマチングを行う
result = cv2.matchTemplate(img, temp, cv2.TM_CCOEFF_NORMED)

#検出領域の位置を取得する
min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
top_left = max_loc
w, h = temp.shape[::-1]
bottom_right = (top_left[0] + w, top_left[1] + h)

result = cv2.imread("img_2.bmp")
cv2.rectangle(result,top_left, bottom_right, (255, 0, 0), 2)
cv2.imwrite("result.bmp", result)
#座標の表示
print(top_left)


#指定した画像を縮小する
img = Image.open('Timg_2.bmp')
img_resize = img.resize((100, 100))
#output.bmpに出力する
img_resize.save('output.bmp')

img = cv2.imread("img_2.bmp", 0)
temp = cv2.imread("output.bmp", 0)

#cv2.TM_CCOEFF_NORMEDによるテンプレートマチングを行う
result = cv2.matchTemplate(img, temp, cv2.TM_CCOEFF_NORMED)

#検出領域の位置を取得する
min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
top_left = max_loc
w, h = temp.shape[::-1]
bottom_right = (top_left[0] + w, top_left[1] + h)

result = cv2.imread("result.bmp")
cv2.rectangle(result,top_left, bottom_right, (255, 0, 0), 2)
cv2.imwrite("result.bmp", result)
#座標の表示
print(top_left)


#指定した画像を回転させる
img = Image.open('Timg_2.bmp')
img_rotate = img.rotate(90)
#output.bmpに出力する
img_rotate.save('output.bmp')

img = cv2.imread("img_2.bmp", 0)
temp = cv2.imread("output.bmp", 0)

#cv2.TM_CCOEFF_NORMEDによるテンプレートマチングを行う
result = cv2.matchTemplate(img, temp, cv2.TM_CCOEFF_NORMED)

#検出領域の位置を取得する
min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
top_left = min_loc
w, h = temp.shape[::-1]
bottom_right = (top_left[0] + w, top_left[1] + h)

result = cv2.imread("result.bmp")
cv2.rectangle(result,top_left, bottom_right, (255, 0, 0), 2)
cv2.imwrite("result.bmp", result)
#座標の表示
print(top_left)



im = Image.open('result.bmp')
im.show()
