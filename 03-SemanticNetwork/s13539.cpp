#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <typeinfo.h>

using namespace std;

class seibutu
{
private:
	bool seibutu_bless = true;

public:
	//�������������邩�ǂ�����Ԃ��֐�
	bool get_seibutu_bless()
	{
		cout << "����" << endl;
		return seibutu_bless;
	}
};

class tori : public seibutu
{
private:
	bool wing = true;

public:
	//�����������邩�ǂ�����Ԃ��֐�
	bool get_tori_bless()
	{
		cout << "��is a";
		return get_seibutu_bless();
	}
};

class oumu : public tori
{
private:
	char *oumu_tokugi = "���m�}�l";

public:
	//�I�E���̓��Z��Ԃ��֐�
	char *get_oumu_tokugi()
	{
		return oumu_tokugi;
	}
	//�I�E�����������邩�ǂ�����Ԃ��֐�
	bool get_oumu_bless()
	{
		cout << "�I�[��is a";
		return get_tori_bless();
	}
};


int main()
{	
	char *toi="a",buf[100];
	char *tokugi;
	bool bless;
	oumu o_mu;
	cout << "�I������ꍇ�́u�I���v�Ɠ��͂��Ă�������" << endl;

	//�I���Ɠ��͂����܂Ń��[�v
	while (strcmp(toi, "�I��"))
	{
		cout << "�������͂��Ă��������B" << endl;
		cin >> buf;

		//�^�ϊ�
		toi = (char *)malloc(strlen(buf) + 1);
		strcpy(toi, buf);

		//�I�E���̓��Z���o�͂���
		if (!strcmp(toi, "�I�[���̓��Z�͉��ł���"))
		{
			tokugi = o_mu.get_oumu_tokugi();
			cout << "�I�[���̓��Z��" << tokugi << endl << endl;

		}
		//�I�E�����ċz���邩���o�͂���
		else if (!strcmp(toi, "�I�[���͌ċz���邩"))
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