#!/usr/bin/env python
# -*- coding: utf-8 -*-
from PIL import Image
import os
try:
    os.mkdir("./textimage")
    print "./textimageを作成しました．"
except:
    print "既に./textimageは作成されています．"
Timg_1 = Image.open("./images/Timg_1.bmp")
Timg_2 = Image.open("./images/Timg_2.bmp")

#縮小
Timg_1.thumbnail((120,120))
Timg_2.thumbnail((108,68), getattr(Image, 'ANTIALIAS'))

#テキストに書き出し
f = open("./textimage/Timg_1.txt","w")
for i in range(Timg_1.size[1]):
    linestr = str()
    for j in range(Timg_1.size[0]):
        r,g,b = Timg_1.getpixel((j,i))
        if r > 128:
            linestr += str(255)
        else:
            linestr +=  "  " + str(0)
    f.write(linestr + "\n")
f.close()



f = open("./textimage/Timg_2.txt","w")
for i in range(Timg_2.size[1]):
    linestr = str()
    for j in range(Timg_2.size[0]):
        r,g,b = Timg_2.getpixel((j,i))
        if r >= 100:
            linestr += str(r)
        elif r >= 10 and r <= 99:
            linestr += " " + str(r)
        else:
            linestr += "  " + str(r)
    f.write(linestr + "\n")
f.close()
