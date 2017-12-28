#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <typeinfo>

using namespace std;

class seibutu
{
private:
	bool seibutu_bless = true;

public:
	//生物が息をするかどうかを返す関数
	bool get_seibutu_bless()
	{
		cout << "生物" << endl;
		return seibutu_bless;
	}
};

class tori : public seibutu
{
private:
	bool wing = true;

public:
	//鳥が息をするかどうかを返す関数
	bool get_tori_bless()
	{
		cout << "鳥is a";
		return get_seibutu_bless();
	}
};

class oumu : public tori
{
private:
	char *oumu_tokugi = "モノマネ";

public:
	//オウムの特技を返す関数
	char *get_oumu_tokugi()
	{
		return oumu_tokugi;
	}
	//オウムが息をするかどうかを返す関数
	bool get_oumu_bless()
	{
		cout << "オームis a";
		return get_tori_bless();
	}
};


int main()
{
	char *toi="a",buf[100];
	char *tokugi;
	bool bless;
	oumu o_mu;
	cout << "終了する場合は「終了」と入力してください" << endl;

	//終了と入力されるまでループ
	while (strcmp(toi, "終了"))
	{
		cout << "質問を入力してください。" << endl;
		cin >> buf;

		//型変換
		toi = (char *)malloc(strlen(buf) + 1);
		strcpy(toi, buf);

		//オウムの特技を出力する
		if (!strcmp(toi, "オームの特技は何ですか"))
		{
			tokugi = o_mu.get_oumu_tokugi();
			cout << "オームの特技は" << tokugi << endl << endl;

		}
		//オウムが呼吸するかを出力する
		else if (!strcmp(toi, "オームは呼吸するか"))
		{
			bless = o_mu.get_oumu_bless();

			if (bless == true)
			{
				cout << "yes" << endl << endl;
			}
			else
			{
				cout << "no" << endl << endl;
			}
		}
	}
}
