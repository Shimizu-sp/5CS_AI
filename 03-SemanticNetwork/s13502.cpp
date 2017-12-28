#include<iostream>
#include<string>
#include<stdio.h>
#include<typeinfo>

using namespace std;

class Creature{	//生物
public:
	bool breath = true;	// 呼吸する

	bool breathless3()
	{
		printf("生物\n");
		return breath;
	}

};

class Bird : public Creature{	//鳥
public:
	bool HaveWing = true; // 翼ある

	bool breathless2()
	{
		printf("鳥 →");
		return breathless3();
	}

};

class Parrot : public Bird{	//オウム
public:
	string Speciality = "モノマネ";	// 特技はモノマネ

	string tokugi()
	{
		return Speciality;
	}

	bool breathless1()
	{

		printf("オウム →");
		return breathless2();

	}
};



int main()
{
	Parrot P_Bird;
	string Havetokugi = P_Bird.tokugi();


	char answer[100] = "";


	//モノマネ
	printf("「オームの特技は何ですか」とご入力ください\n");

	cin >> answer;

	if (strcmp("オームの特技は何ですか", answer) == 0)
	{
		printf("%s\n", Havetokugi.c_str());
	}


	//継承
	printf("「オームは呼吸するか」とご入力ください\n");
	cin >> answer;

	if (strcmp("オームは呼吸するか", answer) == 0)
	{
		if (P_Bird.breathless1() == 1){
			printf("Yes\n");
		}

	}


}
