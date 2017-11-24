# -*- coding: utf-8 -*-
import sys

def main():
	is_a = {"鳥":'生物', "オーム":'鳥'} #is-a関係の辞書
	has_a = {"生物":'呼吸',"鳥":'翼',"オーム":'モノマネ'} #has-a関係の辞書
	print("何を聴きますか？オームの特技が聴きたかったら1を入力してください。オームは呼吸するか聴きたかったら2を入力してください")
	input_question = input('>> ')
	#オームの特技について
	if(input_question == "1"):
		print("オームの特技は"+has_a["オーム"]+"です")
	#オームは呼吸するのか調べる
	elif(input_question == "2"):
		tansaku='オーム'
		#オームのis-a関係を調べる
		for i in is_a.items():
			if(i[0]==tansaku):
				tansaku = i[1]
				print(i[0]+"と"+i[1]+"はis-a関係にあります")
				break
		#鳥のis-a関係をしらべる
		for i in is_a.items():
			if(i[0]==tansaku):
				tansaku = i[1]
				print(i[0]+"と"+i[1]+"はis-a関係にあります")
				break
		#生物のhas-a関係を調べる
		for i in has_a.items():
			if(i[0]==tansaku and i[1]=='呼吸'):
				print("YES")
				break
	else:
		print("1もしくは2を入力してください")
		sys.exit()

if __name__ == "__main__":
	main()