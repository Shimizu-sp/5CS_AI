#include<iostream>
#include<string>
#include<stdio.h>
#include<typeinfo.h>

using namespace std;

class Creature{	//����
public:
	bool breath = true;	// �ċz����

	bool breathless3() 
	{
		printf("����\n");
		return breath;
	}

};

class Bird : public Creature{	//��
public:
	bool HaveWing = true; // ������
	
	bool breathless2()
	{
		printf("�� ��");
		return breathless3();
	}

};

class Parrot : public Bird{	//�I�E��
public:
	string Speciality = "���m�}�l";	// ���Z�̓��m�}�l

	string tokugi()
	{
		return Speciality;
	}

	bool breathless1()
	{

		printf("�I�E�� ��");
		return breathless2();

	}
};



int main()
{
	Parrot P_Bird;
	string Havetokugi = P_Bird.tokugi();


	char answer[100] = "";


	//���m�}�l
	printf("�u�I�[���̓��Z�͉��ł����v�Ƃ����͂�������\n");
	
	cin >> answer;

	if (strcmp("�I�[���̓��Z�͉��ł���", answer) == 0)
	{
		printf("%s\n", Havetokugi.c_str());
	}


	//�p��
	printf("�u�I�[���͌ċz���邩�v�Ƃ����͂�������\n");
	cin >> answer;

	if (strcmp("�I�[���͌ċz���邩", answer) == 0)
	{
		if (P_Bird.breathless1() == 1){
			printf("Yes\n");
		}

	}
		

}