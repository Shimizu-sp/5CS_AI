# -*- encoding: utf-8 -*-

arrQ = ['a', '*', 'b', '-', 'c', 'd', '/', 'e', '+', 'f', 'g']
x = 0
y = 0
i = 0
print arrQ
puts
# 文字を文字コードが大きい順に入れ替える
for j in 0..9 do
  for i in 0..9 do
    if arrQ[i].bytes.map{|v| v.to_s(16)}.join < arrQ[i + 1].bytes.map{|v| v.to_s(16)}.join then
      x = arrQ[i]
      y = arrQ[i + 1]
      arrQ[i] = y
      arrQ[i + 1] = x
      print arrQ
      puts
      File.open("arrQ.txt", "a") do |f|
        f.print(arrQ)
        f.puts
      end
    end
  end
end

# 記号を並び替える(+を前に出す)
for j in 0..2 do
  for i in 7..9 do
    if arrQ[i].bytes.map{|v| v.to_s(16)}.join > '+'.bytes.map{|v| v.to_s(16)}.join then
      x = arrQ[i]
      y = arrQ[i + 1]
      arrQ[i] = y
      arrQ[i + 1] = x
      print arrQ
      puts
      File.open("arrQ.txt", "a") do |f|
        f.print(arrQ)
        f.puts
      end
    end
  end
end

# 記号を並び替える(-を前に出す)
for j in 0..1 do
  for i in 8..9 do
    if arrQ[i].bytes.map{|v| v.to_s(16)}.join < '-'.bytes.map{|v| v.to_s(16)}.join then
      x = arrQ[i]
      y = arrQ[i + 1]
      arrQ[i] = y
      arrQ[i + 1] = x
      print arrQ
      puts
      File.open("arrQ.txt", "a") do |f|
        f.print(arrQ)
        f.puts
      end
    end
  end
end

# 記号を入れ替える(*と/を入れ替える)
i = 9
if arrQ[i].bytes.map{|v| v.to_s(16)}.join > '*'.bytes.map{|v| v.to_s(16)}.join then
  x = arrQ[i]
  y = arrQ[i + 1]
  arrQ[i] = y
  arrQ[i + 1] = x
end

print arrQ
puts
File.open("arrQ.txt", "a") do |f|
  f.print(arrQ)
  f.puts
end
