Array1 = ["鳥", "is-a", "生物"]
Array2 = ["オウム", "is-a", "鳥"]
Array3 = ["生物", "has-a", "呼吸"]
Array4 = ["鳥", "has-a", "翼"]
Array5 = ["オウムの特技","has-a", "モノマネ"]

#モノマネ
input = gets
		if input.include?(Array1[0]) == true and (Array1[1]) == "has-a"
			p "モノマネ"
		end
		if input.include?(Array2[0]) == true and (Array2[1]) == "has-a"
			p "モノマネ"
		end
		if input.include?(Array3[0]) == true and (Array3[1]) == "has-a"
			p "モノマネ"
		end
		if input.include?(Array4[0]) == true and (Array4[1]) == "has-a"
			p "モノマネ"
		end
		if input.include?(Array5[0]) == true and (Array5[1]) == "has-a"
			p "モノマネ"
		end
		
		
#呼吸
input2 = gets
#オウムは鳥か否か
		if input.include?(Array1[0]) == true and (Array1[1]) == "is-a"
			a = Array1[2]
		end
		if input.include?(Array2[0]) == true and (Array2[1]) == "is-a"
			a = Array2[2]
		end
		if input.include?(Array3[0]) == true and (Array3[1]) == "is-a"
			a = Array3[2]
		end
		if input.include?(Array4[0]) == true and (Array4[1]) == "is-a"
			a = Array4[2]
		end
		if input.include?(Array5[0]) == true and (Array5[1]) == "is-a"
			a = Array5[2]
		end
p "オウムis-a"
p a

#鳥は生物か否か
		if (Array1[0]) == a and (Array1[1]) == "is-a"
			b = Array1[2]
		end
		if (Array2[0]) == a and (Array2[1]) == "is-a"
			b = Array2[2]
		end
		if (Array3[0]) == a and (Array3[1]) == "is-a"
			b = Array3[2]
		end
		if (Array4[0]) == a and (Array4[1]) == "is-a"
			b = Array4[2]
		end
		if (Array5[0]) == a and (Array5[1]) == "is-a"
			b = Array5[2]
		end
p "鳥is-a"
p b
#生物は呼吸するか否か
		if (Array1[0]) == b and (Array1[1]) == "has-a"
			p "yes"
		end
		if (Array2[0]) == b and (Array2[1]) == "has-a"
			p "yes"
		end
		if (Array3[0]) == b and (Array3[1]) == "has-a"
			p "yes"
		end
		if (Array4[0]) == b and (Array4[1]) == "has-a"
			p "yes"
		end
		if (Array5[0]) == b and (Array5[1]) == "has-a"
			p "yes"
		end
		