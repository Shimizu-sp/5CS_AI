#include <iostream>
#include <string>

using namespace std;

class seibutu{//�����N���X�𐶐�
public:
	string shubetsu ="����";
	string name;
	string tokuchou1="�ċz����";

	seibutu(string s){//name�ɖ��O��������R���X�g���N�^
		name = s;
	}
	void tokuchouprint(){

		cout <<  "Yes" << endl;
	}
};
class tori:public seibutu{//�����N���X���p���������N���X�𐶐�
public:
	string shurui = "��";
	string tokuchou2 = "��������";

	tori(string s) :seibutu(s){}

};

class oumu :public tori{//���N���X���p�������I�[���N���X�𐶐�
public:
	string tokugi = "���m�}�l";

	oumu(string s) :tori(s){}
	void tokugiha(){//���Z�����������o�֐�
		cout << tokugi << endl;
	}
	void relationship(){//is-a�֌W�����������o�֐�
		cout << name << "�@is-a�@" << shurui << "�@is-a�@" << shubetsu << endl;
		cout << name << "�̓��Z��" << tokugi << endl;
		cout << shurui << "�ɂ�" << tokuchou2 << endl;
		cout << shubetsu << "��" << tokuchou1 << endl;
	}
};

int main(){
	int flag = 0;
	oumu baka("�I�[��");

	std::string temp;
	cout << "����1����͂��Ă�������" << endl;
	cin >> temp;
	while (flag == 0){
		if (temp == "�I�[���̓��Z�͂Ȃ�ł���"){
			baka.tokugiha();
			flag = 1;
		}
		else{
			cout << "�悭������܂���ł����B������x���肢���܂��B" << endl;
			cin >> temp;
		}
		
	}
	flag = 0;
	cout << "����2����͂��Ă�������" << endl;
	cin >> temp;
	while (flag == 0){
		if (temp == "�I�[���͌ċz���邩"){
			baka.relationship();
			baka.tokuchouprint();
			flag = 1;
		}
		else{
			cout << "�悭������܂���ł����B������x���肢���܂��B" << endl;
			cin >> temp;
		}
	}

}