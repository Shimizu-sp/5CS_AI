#include <stdio.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

vector<string> attribute = {
	//��������
	"����",
	"�ċz",
	"��",
	"��",
	"�I�[��",
	"���m�}�l",
	"NULL",
};

int rooting[6][4] = {
	//���,����,����,���Z�ւ̃��[�e�B���O
	{ -1, 2, 1, -1 },
	{ 0, -1, -1, -1 },
	{ 0, 4, 3, -1 },
	{ 2, -1, -1, -1 },
	{ 2, -1, -1, 5 },
	{ 4, -1, -1, -1 }
};


int _tmain(int argc, _TCHAR* argv[])
{

	//����F�I�[���̓��Z�͉���

	int flg[2]{
		-1, -1
	};

	cout << "�I�[���̓��Z�͉���" << endl;

	vector<string> question = {
		"�I�[��",
		"���Z"
	};

	auto begin = attribute.begin();
	auto end = attribute.end();
	int i = 0;

	//�Ώ�ID�T�[�`

	for (auto itr = attribute.begin(); itr < attribute.end(); ++itr, ++i){
		if (*itr == question[0] && flg[0] == -1){
			flg[0] = i;
			flg[1] = 3;
		}
	}

	string answer;

	//������Fetch

	if (flg[0] != -1) {
		int read = rooting[flg[0]][flg[1]];
		answer = attribute[read];
	}
	else {
		answer = "error";
	}

	//
	//getchar();

	cout << "�I�[���̓��Z��" << answer << "�ł�" << endl;

	cout << "�I�[���͌ċz���邩" << endl;

	question = {
		"�I�[��",
		"�ċz"
	};

	flg[0] = -1;

	//�Ώ�ID�T�[�`

	for (auto itr = attribute.begin(); itr < attribute.end(); ++itr, ++i) {
		if (*itr == question[0] && flg[0] == -1)
			flg[0] = i;
	}

	//��ʑw�Ɍ������Č@��

	do {
		//�������o
		int read = rooting[flg[0]][2];
		if (read != -1)
			answer = attribute[read];

		if (answer == question[1])
		{
			//��������Yes�ƕԓ��A�I��
			cout << "Yes" << endl;
			return 0;
			//break;
		}
		else {
			//��ʑw�ɑΏۂ�ύX
			flg[0] = rooting[flg[0]][0];
		}
	} while (flg[0] != -1);
	//�Ȃ�������No�ƕԓ��A�I��
	cout << "No" << endl;
	return 0;
}