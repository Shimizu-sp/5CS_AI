#include <iostream>
#include <math.h>
#include <fstream>
#define WIDTH 3         //パズルの幅
#define HEIGHT 3        //パズルの高さ
#define SIZE 15         //手数
#define DEPTH_LIMIT 10   //深さ制限
#define STACK_MAX 100   //スタックの大きさ
#define forf(i, n) for(int i=0; i<(int)(n); i++)
//#define disp(x) cout << #x << " : " << x << endl
#define disp(x) cout << "" << x;

using namespace std;

typedef unsigned int Uint;

//発見的関数逐次算出
int calc_f();  int calc_g();  int calc_h();
//配列内部表示
void showMat();
//深さ等の情報
void showDist();
//配列の組み替え
void up(); void down(); void left(); void right();
//全方位動かして最小のヒューリスティック関数を得る
void move_get();
//0の場所を取得
void zeroSearch();
//最小値実行関数
int min_get();
void min_do(int);
void min_set(int);
//終了処理
bool end();

int push(int,int,int,int);
int pop(int*,int*,int*,int*);
int showdata();
int spt = -1;

typedef struct{
  int mat[WIDTH][HEIGHT];
  int up,down,left,right;
}tree_t;
tree_t stack[SIZE];
typedef struct{
  int mat[WIDTH][HEIGHT];
}list_t;

/* ------ グローバル変数 -----*/
//初期状態
Uint first[WIDTH][HEIGHT] =
{  { 2, 3, 5 },
   { 1, 0, 4, },
   { 7, 8, 6 } };
//操作用配列
Uint temp[WIDTH][HEIGHT] =
{  { 0, 0, 0 },
   { 0, 0, 0 },
   { 0, 0, 0 } };
//現在の状態を表現する配列
Uint back[WIDTH][HEIGHT] =
{  { 0, 0, 0 },
   { 0, 0, 0 },
   { 0, 0, 0 } };
//ゴール配列
Uint goal[WIDTH][HEIGHT] =
{  { 1, 2, 3 },
   { 4, 5, 6 },
   { 7, 8, 0 } };

Uint tempM;                   //配列操作用変数
int xnow,ynow;                //配列上での現在位置を取得
int up_g,down_g,left_g,right_g;   //木構造内保存用
int depth = 1;
int slide = 0;

ofstream outputfile("output.txt");

int main(){
  int u,d,l,r;  //プッシュするデータ群
  int i = 0; int btflg = 0;

  //操作用の配列に初期状態を移植
  memcpy(temp,first,sizeof first);
  //showMat();

  while(i != SIZE)
  {

      //実行前をback配列に保存
      memcpy(back,temp,sizeof temp);
      //実行される前の状態を保存
      spt++; memcpy(stack[spt].mat, temp, sizeof(temp)); spt--;
      //次のノードのヒューリスティック値を取得
      if(btflg == 0) move_get();  //バックトラックしなければ通常通り
      else{ btflg = 0; }          // するのであれば次ノードのヒューリスティック値は取得しない
      //内容表示
      showMat();
      //最小値の関数を実行
      min_do( min_get() );
      //実行した関数のヒューリスティック値を99に変更してデータ格納準備 ループ対策
      min_set( min_get() );
      //スタックに値をプッシュ
      push(up_g,down_g,left_g,right_g);

      //バックトラックしたノード全てが探索済みとなったとき
      if( stack[spt].up == 99 && stack[spt].down == 99 &&
          stack[spt].left == 99 && stack[spt].right == 99 ){
            cout << "backtrack2. " << depth << "to" << depth-1 << endl;
            if(pop(&u,&d,&l,&r)== 0) {}
            if(pop(&u,&d,&l,&r)== 0) {}
            memcpy(temp, stack[spt].mat, sizeof(stack[spt].mat));
            up_g = stack[spt].up;     down_g = stack[spt].down;
            left_g = stack[spt].left; right_g = stack[spt].right;
            depth -= 1;  slide -= 1;
            btflg = 1;
      }
      //深さの制限まで達したらバックトラック
      else if(depth == DEPTH_LIMIT+1)
      {
        cout << "backtrack. "  << depth << "to" << depth-1 << endl;
        //ポップ
        if(pop(&u,&d,&l,&r)== 0) {}
        memcpy(temp, stack[spt].mat, sizeof(stack[spt].mat));
        up_g = stack[spt].up;     down_g = stack[spt].down;
        left_g = stack[spt].left; right_g = stack[spt].right;
        depth -= 1;  slide -= 1;
        btflg = 1;
      }
      if (end() == true) break;
      depth++; slide++; i++;
  }
  showMat();
  outputfile.close();
  return 0;
}
// ---- データをスタックに入れる ----
int push(int u,int d,int l,int r) {
    if( spt >= STACK_MAX-1 ) return -1;
    spt++;
    stack[spt].up = u;
    stack[spt].down = d;
    stack[spt].left = l;
    stack[spt].right = r;
    return 0;
}
// ---- スタックからデータを取り出す ----
int pop(int *u,int *d,int *l,int *r) {
    if( spt < 0 ) return -1;
    memset(stack[spt].mat, 0, sizeof(stack[spt].mat));
    *u =stack[spt].up;
    *d =stack[spt].down;
    *l =stack[spt].left;
    *r =stack[spt].right;
    spt--;
    return 0;
}
// ---- スタックからデータを表示する ----
int showdata(){
  forf(i,3){
    forf(j,3){
      disp(stack[spt].mat[i][j]);
    }
    cout << endl;
  }
  cout << endl;
  cout << stack[spt].up << " ";
  cout << stack[spt].down << " ";
  cout << stack[spt].left << " ";
  cout << stack[spt].right << " " << endl;
  return 0;
}
int calc_f(){ //発見的関数算出
  int g = calc_g(); int h = calc_h();
  return  g+h;
}
int calc_g(){ return slide; } //現時点位至る移動量
int calc_h(){
  int x,y,z;
  int xu,yv;
  int num = 0;
  z = 1;
  while(z <= 8) //8パズルのhを算出
  {
      //z = 1から8まで対応する座標の検索
      for(y = 0; y < WIDTH; y++){
        for(x = 0; x < HEIGHT; x++){
            if(temp[y][x] == z){ xu = x; yv = y;  }//現時点の座標を保存
        }
      }
      //座標の距離　配列の差分と見立てて計算
      for(y = 0; y < WIDTH; y++){
        for(x = 0; x < HEIGHT; x++){
            if(goal[y][x] == z)
              //cout << " " << abs(xu - x) + abs(yv - y);
              num += abs(xu - x) + abs(yv - y); //座標の差分の絶対値を取得
        }
      }
      z++;  //次のパズルの数へ
  }
  return num;
}
void showMat(){
  outputfile << "=============================\n";
  cout << "=============================" << endl;
  forf(y,HEIGHT){
    forf(x,WIDTH){
      cout << "[";
      disp(temp[y][x]);
      cout << "]";
      outputfile << "[";
      outputfile << temp[y][x];
      outputfile << "]";
    }
    outputfile << "\n";
    cout << endl;
  }
  outputfile << " f(p) = " << calc_f() << "";
  outputfile << " g(p) = " << calc_g() << "";
  outputfile << " h(p) = " << calc_h() << "\n";
  cout << " f(p) = " << calc_f();
  cout << " g(p) = " << calc_g();
  cout << " h(p) = " << calc_h() << endl;

}
void showDist(){
  cout << "slide:" << slide << " ";
  cout << "depth:" << depth << " ";
  cout << "up:" << up_g << " ";
  cout << "down:" << down_g << " ";
  cout << "left:" << left_g << " ";
  cout << "right:" << right_g << " " << endl;
}
void up() {
  zeroSearch();
  if(ynow == 0)up_g = 99;
  else {
    tempM = temp[ynow-1][xnow];
    temp[ynow-1][xnow] = temp[ynow][xnow];
    temp[ynow][xnow] = tempM;
    up_g = calc_f();  //取得できた場合
  }
}
void down() {
  zeroSearch();
  if(ynow == 2)down_g = 9;
  else {
    tempM = temp[ynow+1][xnow];
    temp[ynow +1][xnow] = temp[ynow][xnow];
    temp[ynow][xnow] = tempM;
    down_g = calc_f();
  }
}
void left() {
  zeroSearch();
  if(xnow == 0)left_g = 99;
  else{
    tempM = temp[ynow][xnow-1];
    temp[ynow][xnow-1] = temp[ynow][xnow];
    temp[ynow][xnow] = tempM;
    left_g = calc_f();
  }
}
void right(){
  zeroSearch();
  if(xnow == 2)right_g = 99;
  else{
    tempM = temp[ynow][xnow+1];
    temp[ynow][xnow+1] = temp[ynow][xnow];
    temp[ynow][xnow] = tempM;
    right_g = calc_f();
  }
}
void move_get(){
  //ゼロの位置を特定してから実行
  zeroSearch();
  cout << "\n";

  /* 全方位のヒューリスティック値を調べる */
  up();
  //前の状態へレストア
  memcpy(temp,back,sizeof back);

  down();
  //前の状態へレストア
  memcpy(temp,back,sizeof back);

  right();
  //前の状態へレストア
  memcpy(temp,back,sizeof back);

  left();
  //前の状態へレストア
  memcpy(temp,back,sizeof back);
}
void zeroSearch(){
  int x,y;
  for(y = 0;y < WIDTH;y++){
    for(x = 0;x < HEIGHT;x++) if(temp[y][x] == 0){ xnow = x; ynow = y; }
  }
  //cout << "ynow = " << ynow << " xnow = " << xnow << endl;
}
int min_get(){
  int min = 100;
  int ans;
  //最小値を代入 表示
  if(min > up_g){  min = up_g; ans = 1;}
  if(min > down_g){ min = down_g; ans = 2;}
  if(min > left_g){ min = left_g; ans = 3;}
  if(min > right_g){ min = right_g; ans = 4;}
  return ans;
}
void min_do(int x){
  switch(x){
      case 1:
        up();
        break;
      case 2:
        down();
        break;
      case 3:
        left();
        break;
      case 4:
        right();
        break;
    }
}
void min_set(int x){
  switch(x){
      case 1:
        up_g = 99;
        break;
      case 2:
        down_g = 99;
        break;
      case 3:
        left_g = 99;
        break;
      case 4:
        right_g = 99;
        break;
    }
}
bool end(){
  int count = 0;
  for(int y = 0; y < WIDTH; y++){
    for(int x = 0; x < HEIGHT; x++){
      if(temp[y][x] - goal[y][x] == 0) count++;
      if(count == 9) return true;
    }
  }
  return false;
}
