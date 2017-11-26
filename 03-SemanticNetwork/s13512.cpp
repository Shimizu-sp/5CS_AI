#include <iostream>
#include <string>

using namespace std;

class seibutu{//生物クラスを生成
public:
	string shubetsu ="生物";
	string name;
	string tokuchou1="呼吸する";

	seibutu(string s){//nameに名前を代入するコンストラクタ
		name = s;
	}
	void tokuchouprint(){

		cout <<  "Yes" << endl;
	}
};
class tori:public seibutu{//生物クラスを継承した鳥クラスを生成
public:
	string shurui = "鳥";
	string tokuchou2 = "翼がある";

	tori(string s) :seibutu(s){}

};

class oumu :public tori{//鳥クラスを継承したオームクラスを生成
public:
	string tokugi = "モノマネ";

	oumu(string s) :tori(s){}
	void tokugiha(){//特技を示すメンバ関数
		cout << tokugi << endl;
	}
	void relationship(){//is-a関係を示すメンバ関数
		cout << name << "　is-a　" << shurui << "　is-a　" << shubetsu << endl;
		cout << name << "の特技は" << tokugi << endl;
		cout << shurui << "には" << tokuchou2 << endl;
		cout << shubetsu << "は" << tokuchou1 << endl;
	}
};

int main(){
	int flag = 0;
	oumu baka("オーム");

	std::string temp;
	cout << "質問1を入力してください" << endl;
	cin >> temp;
	while (flag == 0){
		if (temp == "オームの特技はなんですか"){
			baka.tokugiha();
			flag = 1;
		}
		else{
			cout << "よく分かりませんでした。もう一度お願いします。" << endl;
			cin >> temp;
		}
		
	}
	flag = 0;
	cout << "質問2を入力してください" << endl;
	cin >> temp;
	while (flag == 0){
		if (temp == "オームは呼吸するか"){
			baka.relationship();
			baka.tokuchouprint();
			flag = 1;
		}
		else{
			cout << "よく分かりませんでした。もう一度お願いします。" << endl;
			cin >> temp;
		}
	}

}