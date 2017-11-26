#include <stdio.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

vector<string> attribute = {
	//ぞくせい
	"生物",
	"呼吸",
	"鳥",
	"翼",
	"オーム",
	"モノマネ",
	"NULL",
};

int rooting[6][4] = {
	//上位,下位,特徴,特技へのルーティング
	{ -1, 2, 1, -1 },
	{ 0, -1, -1, -1 },
	{ 0, 4, 3, -1 },
	{ 2, -1, -1, -1 },
	{ 2, -1, -1, 5 },
	{ 4, -1, -1, -1 }
};


int _tmain(int argc, _TCHAR* argv[])
{

	//質問：オームの特技は何か

	int flg[2]{
		-1, -1
	};

	cout << "オームの特技は何か" << endl;

	vector<string> question = {
		"オーム",
		"特技"
	};

	auto begin = attribute.begin();
	auto end = attribute.end();
	int i = 0;

	//対象IDサーチ

	for (auto itr = attribute.begin(); itr < attribute.end(); ++itr, ++i){
		if (*itr == question[0] && flg[0] == -1){
			flg[0] = i;
			flg[1] = 3;
		}
	}

	string answer;

	//特徴をFetch

	if (flg[0] != -1) {
		int read = rooting[flg[0]][flg[1]];
		answer = attribute[read];
	}
	else {
		answer = "error";
	}

	//
	//getchar();

	cout << "オームの特技は" << answer << "です" << endl;

	cout << "オームは呼吸するか" << endl;

	question = {
		"オーム",
		"呼吸"
	};

	flg[0] = -1;

	//対象IDサーチ

	for (auto itr = attribute.begin(); itr < attribute.end(); ++itr, ++i) {
		if (*itr == question[0] && flg[0] == -1)
			flg[0] = i;
	}

	//上位層に向かって掘る

	do {
		//特徴検出
		int read = rooting[flg[0]][2];
		if (read != -1)
			answer = attribute[read];

		if (answer == question[1])
		{
			//あったらYesと返答、終了
			cout << "Yes" << endl;
			return 0;
			//break;
		}
		else {
			//上位層に対象を変更
			flg[0] = rooting[flg[0]][0];
		}
	} while (flg[0] != -1);
	//なかったらNoと返答、終了
	cout << "No" << endl;
	return 0;
}