#include <stdio.h>
#include <math.h>

int Man(int m);
int Man2(int m2);
int Man3(int m3);
int Man4(int m4);
int Move(int mov);
int check(int c);

#define MAX 5
#define LIMIT 10000

int p = 0; //スタック番号
int pp = 0; //close用スタック番号

typedef struct {
    int a; int b; int c;
	int d; int e; int f;
	int g; int h; int i;
} stack;

stack panel[MAX];
stack close[LIMIT];

//ループ回避用変数
int count = 0;
int roop_y = 0;
int roop_x = 0;
int roop_y1 = 0;

int roop_x1 = 0;

//初期状態
int a[3][3] = { { 8, 1, 5 },
				{ 2, 9, 4 },
				{ 6, 3, 7 } }; //a[y][x]
//ゴール状態
int b[3][3] = { { 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 } }; //b[y][x]

int c[3][3] = { { 0, 0, 0 },
				{ 0, 0, 0 },
				{ 0, 0, 0 } }; //b[y][x]


//移動用コピー
int d[3][3] = { { 0, 0, 0 },
				{ 0, 0, 0 },
				{ 0, 0, 0 } }; //b[y][x]

int f[3][3] = { { 0, 0, 0 },
				{ 0, 0, 0 },
				{ 0, 0, 0 } }; //b[y][x]

int g[3][3] = { { 0, 0, 0 },
				{ 0, 0, 0 },
				{ 0, 0, 0 } }; //b[y][x]

int h[3][3] = { { 0, 0, 0 },
				{ 0, 0, 0 },
				{ 0, 0, 0 } }; //b[y][x]

//マンハッタン距離保存用
int ans[4] = {99,99,99,99};
int ans_copy[4] = {99,99,99,99};
int check_func = 0;

main(){

	int i = 0, n = 0, j = 0;
	int box = 0;
	int pass = 0;
	int pattern = 0;
	int func = 0;
	int cnt = 0;
	int d_cnt = 0;
	int search = 0;

	//初期スタック入れ
		panel[p].a = a[0][0];
		panel[p].b = a[0][1];
		panel[p].c = a[0][2];
		panel[p].d = a[1][0];
		panel[p].e = a[1][1];
		panel[p].f = a[1][2];
		panel[p].g = a[2][0];
		panel[p].h = a[2][1];
		panel[p].i = a[2][2];

		close[pp].a = panel[p].a;
		close[pp].b = panel[p].b;
		close[pp].c = panel[p].c;
		close[pp].d = panel[p].d;
		close[pp].e = panel[p].e;
		close[pp].f = panel[p].f;
		close[pp].g = panel[p].g;
		close[pp].h = panel[p].h;
		close[pp].i = panel[p].i;

	//メモ...配列d〜hはコピー用配列。マンハッタン距離用配列と照らし合わせると、
	//d = ans[0] f = ans[1] g = ans[2] h = ans[3]

	while(1){

		d_cnt = 0;

		search++;
		printf("探索 %d 回目\n",search);
		printf("現在深さ %d\n",p);

		a[0][0] = panel[p].a;
		a[0][1] = panel[p].b;
		a[0][2] = panel[p].c;
		a[1][0] = panel[p].d;
		a[1][1] = panel[p].e;
		a[1][2] = panel[p].f;
		a[2][0] = panel[p].g;
		a[2][1] = panel[p].h;
		a[2][2] = panel[p].i;

		for(i=0;i<4;i++){
			ans[i] = 99;
		}
		//for(i = 0; i < 4; i++){
		//printf("%d ",ans[i]);
		//}
	

		//表示
			printf("pの状態\n");
			printf("%d %d %d\n%d %d %d\n%d %d %d\n",panel[p].a, panel[p].b, panel[p].c
												     ,panel[p].d, panel[p].e, panel[p].f
												     ,panel[p].g, panel[p].h, panel[p].i);
		getchar();
		printf("↓\n\n");

	if(a[0][0] == 1 && a[0][1] == 2 && a[0][2] == 3 &&
	   a[1][0] == 4 && a[1][1] == 5 && a[1][2] == 6 &&
	   a[2][0] == 7 && a[2][1] == 8){
		   printf("終了\n");
		   return 0;
	}

	pattern = Move(pass);
	printf("%d方向移動可\n",pattern);

	for(i = 0; i < pattern; i++){
		ans_copy[i] = ans[i];
	}

	box = 0;

	//昇順バブルソート
	for (i = 0; i < (pattern-1); i++){
        for (j = (pattern-1); j > i; j--){
            if (ans[j-1] >= ans[j]){
                box = ans[j-1];
                ans[j-1] = ans[j];
                ans[j]= box;
			}
		}
	}

	for(i = 0; i < pattern; i++){
		printf("%d ",ans[i]);
	}
	printf("の順に探索\n\n");
	
	i = 0;

	while(1){

		if(ans[i] == ans_copy[0]){
			printf("check\n");
			if(p < MAX){p++;}else{p--;break;}
				panel[p].a = d[0][0];
				panel[p].b = d[0][1];
				panel[p].c = d[0][2];
				panel[p].d = d[1][0];
				panel[p].e = d[1][1];
				panel[p].f = d[1][2];
				panel[p].g = d[2][0];
				panel[p].h = d[2][1];
				panel[p].i = d[2][2];
				
				check_func = check(func);
				if(check_func == 2){
					break;
				}else{
					d_cnt++;
					if(p > 0){p--;}
				}

		}
		printf("1通過\n");
		if(ans[i] == ans_copy[1]){
			if(p < MAX){p++;}else{p--;break;}
				panel[p].a = f[0][0];
				panel[p].b = f[0][1];
				panel[p].c = f[0][2];
				panel[p].d = f[1][0];
				panel[p].e = f[1][1];
				panel[p].f = f[1][2];
				panel[p].g = f[2][0];
				panel[p].h = f[2][1];
				panel[p].i = f[2][2];

				check_func = check(func);
				if(check_func == 2){
					break;
				}else{
					d_cnt++;
					if(p > 0){p--;}
				}
		}
		printf("2通過\n");
		if(pattern >= 3){
		if(ans[i] == ans_copy[2]){
			if(p < MAX){p++;}else{p--;break;}
				panel[p].a = g[0][0];
				panel[p].b = g[0][1];
				panel[p].c = g[0][2];
				panel[p].d = g[1][0];
				panel[p].e = g[1][1];
				panel[p].f = g[1][2];
				panel[p].g = g[2][0];
				panel[p].h = g[2][1];
				panel[p].i = g[2][2];

				check_func = check(func);
				if(check_func == 2){
					break;
				}else{
					d_cnt++;
					if(p > 0){p--;}
				}
		}
		}
		printf("3通過\n");
		i++;
		if(pattern >= 4){
		if(ans[i] == ans_copy[3]){
			if(p < MAX){p++;}else{p--;break;}
				panel[p].a = h[0][0];
				panel[p].b = h[0][1];
				panel[p].c = h[0][2];
				panel[p].d = h[1][0];
				panel[p].e = h[1][1];
				panel[p].f = h[1][2];
				panel[p].g = h[2][0];
				panel[p].h = h[2][1];
				panel[p].i = h[2][2];

				check_func = check(func);
				if(check_func == 2){
				}else{
					d_cnt++;
					if(p > 0){p--;}
				}
		}
		}
		//printf("3通過\n");
		if(d_cnt == 4){
			p--;
		}

		printf("%d\n順目",i);
		i = i++;

		if(p == MAX){
			printf("深さが最大になりました\n");
			p--;
			break;
		}

		if(i = pattern){
		pp++;
		close[pp].a = panel[p].a;
		close[pp].b = panel[p].b;
		close[pp].c = panel[p].c;
		close[pp].d = panel[p].d;
		close[pp].e = panel[p].e;
		close[pp].f = panel[p].f;
		close[pp].g = panel[p].g;
		close[pp].h = panel[p].h;
		close[pp].i = panel[p].i;
		if(p > 0){p--;}
		break;
		}

	}
		pp++;
		close[pp].a = panel[p].a;
		close[pp].b = panel[p].b;
		close[pp].c = panel[p].c;
		close[pp].d = panel[p].d;
		close[pp].e = panel[p].e;
		close[pp].f = panel[p].f;
		close[pp].g = panel[p].g;
		close[pp].h = panel[p].h;
		close[pp].i = panel[p].i;

	}
	}

int Man(int m){

	//カウンタ
	int i = 0;
	int n = 0;

	int ii = 0;
	int nn = 0;

	//式
	int aa = 0 , bb = 0;
	int x = 0 , y = 0;
	int ans = 0;

	////マンハッタン距離
	while(1){
		for (i = 0; i < 3; i++){ // y軸

			for (n = 0; n < 3; n++){ //x軸

				if(c[0][0] == 1 && c[0][1] == 2 && c[0][2] == 3 &&
				   c[1][0] == 4 && c[1][1] == 5 && c[1][2] == 6 &&
				   c[2][0] == 7 && c[2][1] == 8){break;}

				if (b[ii][nn] == d[i][n] && c[ii][nn] == 0){ 

				c[ii][nn] = d[i][n];//別のリストcにaを代入
				y = abs(i - ii);
				x = abs(n - nn);

				//printf("目標%d ",a[ii][nn]);

				//printf("%d ",x+y);

				ans = ans + x + y;

				//printf("和%d\n",ans);
				
				nn = nn++;

				if(nn == 3){
					nn = 0;
					ii = ii++;
				}
				}
			}
			
		if(c[2][1] == 8 && c[2][0] == 7){break;}
		}
		i = 0;
		n = 0;
		if(c[2][1] == 8 && c[2][0] == 7){break;}
	}

	//リセット
	for (i = 0; i < 3; i++){
			for(n = 0; n < 3; n++){
				c[i][n] = 0;
			}
	}

	printf("パターン１総和%d\n",ans);
	return ans;

}
int Man2(int m2){

	//カウンタ
	int i = 0;
	int n = 0;

	int ii = 0;
	int nn = 0;

	//式
	int aa = 0 , bb = 0;
	int x = 0 , y = 0;
	int ans = 0;

	////マンハッタン距離
	while(1){

		for (i = 0; i < 3; i++){ // y軸

			for (n = 0; n < 3; n++){ //x軸

				if(c[2][1] == 8 && c[2][0] == 7){break;}

				if (b[ii][nn] == f[i][n] && c[ii][nn] == 0){ 

				c[ii][nn] = f[i][n];//別のリストcにaを代入
				y = abs(i - ii);
				x = abs(n - nn);

				//printf("目標%d ",a[ii][nn]);

				//printf("%d ",x+y);

				ans = ans + x + y;

				//printf("和%d\n",ans);

				nn = nn++;

				if(nn == 3){
					nn = 0;
					ii = ii++;
				}
				}
			}
			
			if(c[2][1] == 8 && c[2][0] == 7){break;}
		}
		i = 0;
		n = 0;
		if(c[2][1] == 8 && c[2][0] == 7){break;}
	}

	//リセット
	for (i = 0; i < 3; i++){
			for(n = 0; n < 3; n++){
				c[i][n] = 0;
			}
	}
	printf("パターン２総和%d\n",ans);
	return ans;
	
}
int Man3(int m3){

	//カウンタ
	int i = 0;
	int n = 0;

	int ii = 0;
	int nn = 0;

	//式
	int aa = 0 , bb = 0;
	int x = 0 , y = 0;
	int ans = 0;

	////マンハッタン距離
	while(1){
		for (i = 0; i < 3; i++){ // y軸

			for (n = 0; n < 3; n++){ //x軸

				if(c[2][1] == 8 && c[2][0] == 7){break;}

				if (b[ii][nn] == g[i][n] && c[ii][nn] == 0){ 

				c[ii][nn] = g[i][n];//別のリストcにaを代入
				y = abs(i - ii);
				x = abs(n - nn);

				//printf("目標%d ",a[ii][nn]);
				
				//printf("%d ",x+y);

				ans = ans + x + y;

				//printf("和%d\n",ans);
				
				nn = nn++;

				if(nn == 3){
					nn = 0;
					ii = ii++;
				}
				}
			}
			if(c[2][1] == 8 && c[2][0] == 7){break;}
		}
		i = 0;
		n = 0;
		if(c[2][1] == 8 && c[2][0] == 7){break;}
	}

	//リセット
	for (i = 0; i < 3; i++){
			for(n = 0; n < 3; n++){
				c[i][n] = 0;
			}
	}
	printf("パターン３総和%d\n",ans);
	return ans;
	
}
int Man4(int m4){

	//カウンタ
	int i = 0;
	int n = 0;

	int ii = 0;
	int nn = 0;

	//式
	int aa = 0 , bb = 0;
	int x = 0 , y = 0;
	int ans = 0;

	////マンハッタン距離
	while(1){
		for (i = 0; i < 3; i++){ // y軸

			for (n = 0; n < 3; n++){ //x軸

				if(c[2][1] == 8 && c[2][0] == 7){break;}

				if (b[ii][nn] == h[i][n] && c[ii][nn] == 0){ 

				c[ii][nn] = h[i][n];//別のリストcにaを代入
				y = abs(i - ii);
				x = abs(n - nn);

				//printf("目標%d ",a[ii][nn]);
				
				//printf("%d ",x+y);

				ans = ans + x + y;

				//printf("和%d\n",ans);
				
				nn = nn++;

				if(nn == 3){
					nn = 0;
					ii = ii++;
				}
				}
			}
			if(c[2][1] == 8 && c[2][0] == 7){break;}
		}
		i = 0;
		n = 0;
		if(c[2][1] == 8 && c[2][0] == 7){break;}
	}

	//リセット
	for (i = 0; i < 3; i++){
			for(n = 0; n < 3; n++){
				c[i][n] = 0;
			}
	}
	printf("パターン４総和%d\n",ans);
	return ans;
	
}
int Move(int mov){

	//変数
	int root1 = 0;
	int root2 = 0;
	int root3 = 0;
	int root4 = 0;

	//式
	int x = 0 , y = 0;

	//カウンタ
	int i = 0;
	int n = 0;

	int ii = 0;
	int nn = 0;

	int count = 0;
	int count2 = 0;

	while(1){

		//printf("ok\n");

		//ループ記憶
		roop_y1 = roop_y;
		roop_x1 = roop_x;

		
		roop_y = i;
		roop_x = n;

		//コピー＆配列リセット
		for (i = 0; i < 3; i++){
			for(n = 0; n < 3; n++){
				d[i][n] = a[i][n];
				f[i][n] = a[i][n];
				g[i][n] = a[i][n];
				h[i][n] = a[i][n];
			}
			ans[i] = 0;
		}
		
		///9移動部分
		for (i = 0; i < 3; i++){
			if(count == 1){break;}
			for (n = 0; n < 3; n++){
				if(a[i][n] == 9){ //9発見

					//初回記憶
					if(count == 0){
						roop_y = i;
						roop_x = n;
					}

					if(i == 0 && n == 0){ //00 右・下
						//printf("前回%d %d\n",roop_y1,roop_x1);
						d[i][n] = d[i][n+1];
						d[i][n+1] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i+1][n];
						f[i+1][n] = 9;
						ans[1] = Man2(root2);

						return 2;
					}
					if(i == 0 && n == 1){ //01 右・下・左
						//printf("前回%d %d\n",roop_y1,roop_x1);
						d[i][n] = d[i][n+1];
						d[i][n+1] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i+1][n];
						f[i+1][n] = 9;
						ans[1] = Man2(root2);

						g[i][n] = a[i][n-1];
						g[i][n-1] = 9;
						ans[2] = Man3(root3);

						return 3;
					}
					if(i == 0 && n == 2){ //02 下・左
						//printf("前回%d %d\n",roop_y1,roop_x1);
						d[i][n] = d[i+1][n];
						d[i+1][n] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i][n-1];
						f[i][n-1] = 9;
						ans[1] = Man2(root2);

						return 2;
					}
					if(i == 1 && n == 0){ //10 右・下・上
						//printf("前回%d %d\n",roop_y1,roop_x1);
						d[i][n] = d[i][n+1];
						d[i][n+1] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i+1][n];
						f[i+1][n] = 9;
						ans[1] = Man2(root2);

						g[i][n] = a[i-1][n];
						g[i-1][n] = 9;
						ans[2] = Man3(root3);

						return 3;
					}
					if(i == 1 && n == 1){ //11 右・下・左・上
						//printf("前回%d %d\n",roop_y1,roop_x1);
						//printf("ok\n");
						d[i][n] = d[i][n+1];
						d[i][n+1] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i+1][n];
						f[i+1][n] = 9;
						ans[1] = Man2(root2);

						g[i][n] = a[i][n-1];
						g[i][n-1] = 9;
						ans[2] = Man3(root3);

						h[i][n] = a[i-1][n];
						h[i-1][n] = 9;
						ans[3] = Man4(root4);

						return 4;
					}
					if(i == 1 && n == 2){ //12 下・左・上
						//printf("前回%d %d\n",roop_y1,roop_x1);
						d[i][n] = d[i+1][n];
						d[i+1][n] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i][n-1];
						f[i][n-1] = 9;
						ans[1] = Man2(root2);

						g[i][n] = a[i-1][n];
						g[i-1][n] = 9;
						ans[2] = Man3(root3);

						return 3;
					}
					if(i == 2 && n == 0){ //20 右・上
						//printf("前回%d %d\n",roop_y1,roop_x1);
						d[i][n] = d[i][n+1];
						d[i][n+1] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i-1][n];
						f[i-1][n] = 9;
						ans[1] = Man2(root2);

						return 2;
					}
					if(i == 2 && n == 1){ //21 右・左・上
						//printf("前回%d %d\n",roop_y1,roop_x1);
						d[i][n] = d[i][n+1];
						d[i][n+1] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i][n-1];
						f[i][n-1] = 9;
						ans[1] = Man2(root2);

						g[i][n] = a[i-1][n];
						g[i-1][n] = 9;
						ans[2] = Man3(root3);

						return 3;
					}
					if(i == 2 && n == 2){ //22 左・上
						//printf("前回%d %d\n",roop_y1,roop_x1);
						d[i][n] = d[i][n-1];
						d[i][n-1] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i+1][n];
						f[i+1][n] = 9;
						ans[1] = Man2(root2);

						printf("check\n");

						return 2;
					}
				}
			} //nfor
		} //ifor

		count2 = count2++;

	} //while
	}
int check(int c){

	int count;
	int i = 0;

	for(count = pp; count >= 0; count--){
		 if(panel[p].a == close[count].a &&
			panel[p].b == close[count].b &&
			panel[p].c == close[count].c &&
			panel[p].d == close[count].d &&
			panel[p].e == close[count].e &&
			panel[p].f == close[count].f &&
			panel[p].g == close[count].g &&
			panel[p].h == close[count].h){
		    //printf("過去に同じ組み合わせがありました\n");
				return 1;
		 }
		  i = i + 1;
		  //printf("ok");
	}
	return 2;
}