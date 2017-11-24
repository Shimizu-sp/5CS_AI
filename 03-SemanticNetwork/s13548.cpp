#include <iostream>
#include <string>
using namespace std;

/* 上級クラス */
class Creature  //生物クラス
{
protected:
  string attribute;
  bool breath;
public:
  Creature(){
      this -> setAttribute("/生物");  //属性は鳥
      this -> setBreath(true);      //翼を持っている
      this -> disp();
      cout << "is-a" << endl;
  }
  void disp(){ this->getAttribute();  this->getBreath(); }
  void setAttribute (string str){  attribute = str;  }
  void setBreath(bool bl){ breath = bl; }
  void getAttribute(){ cout <<  attribute << endl; }
  void getBreath(){ if(breath == true) cout << "呼吸する\n"; else cout << "呼吸しない\n"; }

};

/* 下級クラス */
//鳥は生物を継承
class Bird : public Creature
{
private:
  string attribute;   //クラスの属性 鳥
  string name;        //鳥の名前
  string skill;       //鳥の特技
  bool wing;          //鳥は翼があるか
public:
  Bird() : Creature(){
    this -> setAttribute("/鳥");  //属性は鳥
    this -> setName("オーム");         //鳥の名前設定
    this -> setSkill("モノマネ");  //ohmに特技の設定
    this -> setWing(true);      //翼を持っている
    this -> disp();                 //情報の表示
  }
  void disp(){ this->getAttribute(); this->getName(); this->getSkill(); this->getWing(); }
  void setAttribute (string str){ attribute = str; }
  void getAttribute(){ cout <<  attribute << endl; }
  void setName (string str){  name = str; }
  void getName(){ cout <<  name << endl; }
  void setSkill(string str){ skill = str; }
  void getSkill(){ cout << skill << endl; }
  void setWing(bool bl){ wing = bl; }
  void getWing(){ if(wing == true) cout << "翼がある\n"; else cout << "翼がない\n"; }
};

int main(){
  cout << "  クラス構造" << endl;
  Bird ohm;                   //birdクラスのohmを作成

  //オームの特技は何ですか →　オームのスキルを表示する
  cout << "Q. オームの特技は何ですか？\n";
  cout << "A. ";
  ohm.getSkill();   //Birdに属している
  cout << endl;

  //オームは呼吸するか　→  オームから生物クラスのパラメータにアクセス
  cout << "Q. オームは呼吸するか？\n";
  cout << "A. ";
  ohm.getBreath();  //Bird < Creature に属している
  cout << endl;

  return 0;
}
