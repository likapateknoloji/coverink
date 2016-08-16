#!/bin/bash
cd /home/pi/Desktop/books
dosyaismi=/home/pi/Desktop/books/111.html
mkdir ${dosyaismi%.html}
cutycapt --url="file:${dosyaismi}" --out="${dosyaismi%.html}/1.bmp"
mkdir ${dosyaismi%.html}/pages
a=$(identify -format "%h" ${dosyaismi%.html}/1.bmp)
i=0
while [  $i -lt $a ]; do
  convert "${dosyaismi%.html}/1.bmp" -crop 800x600+0+$i "${dosyaismi%.html}/pages/$(($i/600)).bmp"
  let i=i+600 
  echo $i
done

#for i in {0..15}
#do
#	convert "/home/pi/Desktop/books/111/1.bmp" -crop 800x600+0+$(($i*600)) "/home/pi/Desktop/books/111/pages/$i.bmp"
#done
