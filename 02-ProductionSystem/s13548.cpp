#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* -----マクロ----- */
#define ploop(n, N, M) for(int n = N ; i < (int)(M) ; n++) //昇順ループ
#define mloop(n, N, M) for(int n = N ; i > M ; n--)        //降順ループ
#define LF cout << endl;

/* 初期状態 */
string start_str = "a*b-cd/e+fg";
/* 操作用配列 */
char* str = new char[ start_str.size() ];
int strt = 0,fin = 0,flg = 0; //パラメータ
/* プロダクションメモリ　ルール */
//  R1  アルファベット記号の順に整列
void pm_rules(char *ptr){
  ploop(i, 0, start_str.size()){
    // gを一番左
    if(ptr[i] == 'g' && flg == 0){
      cout << "R2:”;
      strt = i; fin = 0;
      break;
    }
    // fはgの右
    else if(ptr[i] == 'f' && flg == 1){
      cout << "R3:”;
      strt = i; fin = 1;
      break;
    }
    // eはfの右
    else if(ptr[i] == 'e' && flg == 2){
      cout << "R4:”;
      strt = i; fin = 2;
      break;
    }
    // dはeの右
    else if(ptr[i] == 'd' && flg == 3){
      cout << "R5:”;
      strt = i; fin = 3;
      break;
    }
    // cはdの右
    else if(ptr[i] == 'c' && flg == 4){
      cout << "R6:”;
      strt = i; fin = 4;
      break;
    }
    // bはcの右
    else if(ptr[i] == 'b' && flg == 5){
      cout << "R7:”;
      strt = i; fin = 5;
      break;
    }
    // aはbの右
    else if(ptr[i] == 'a' && flg == 6){
      cout << "R8:”;
      strt = i; fin = 6;
      break;
    }
    // +のaの右
    else if(ptr[i] == '+' && flg == 7){
      cout << "R9:”;
      strt = i; fin = 7;
      break;
    }
    // -の+の右
    else if(ptr[i] == '-' && flg == 8){
      cout << "R10:”;
      strt = i; fin = 8;
      break;
    }
    // *の-の右
    else if(ptr[i] == '*' && flg == 9){
      cout << "R11:”;
      strt = i; fin = 9;
      break;
    }
    // /の*の右
    else if(ptr[i] == '/' && flg == 10){
      cout << "R12:";
      strt = i; fin = 10;
      break;
    }
  }
  flg++;
}
/* ルールに従った並び替えの実行 */
void pm_change(char *pstr){
  char temp;
  /* 隣接する配列同士の並び替え */
  mloop(i , strt, fin){
    temp = pstr[i-1];
    pstr[i-1] = pstr[i];
    pstr[i] = temp;
    if(i == fin) break;
    cout << str;LF;
  }
  LF;
}

int main(){
  int i = 0;
  strcpy(str, start_str.c_str() );
  cout << "working_memory"; LF;
  cout << str; LF;             //初期状態の表示
  //プロダクションシステムの実行 字数分
  while(i < start_str.size()){
    pm_rules(str); //ルールの読み出し
    pm_change(str); //組み替え
    i++;
  }

  delete[] str;
}
