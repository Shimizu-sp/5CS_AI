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

int p = 0; //�X�^�b�N�ԍ�
int pp = 0; //close�p�X�^�b�N�ԍ�

typedef struct {
    int a; int b; int c;
	int d; int e; int f;
	int g; int h; int i;
} stack;

stack panel[MAX];
stack close[LIMIT];

//���[�v���p�ϐ�
int count = 0;
int roop_y = 0;
int roop_x = 0;
int roop_y1 = 0;

int roop_x1 = 0;

//�������
int a[3][3] = { { 8, 1, 5 },
				{ 2, 9, 4 },
				{ 6, 3, 7 } }; //a[y][x]
//�S�[�����
int b[3][3] = { { 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 } }; //b[y][x]

int c[3][3] = { { 0, 0, 0 },
				{ 0, 0, 0 },
				{ 0, 0, 0 } }; //b[y][x]


//�ړ��p�R�s�[
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

//�}���n�b�^�������ۑ��p
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

	//�����X�^�b�N����
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

	//����...�z��d�`h�̓R�s�[�p�z��B�}���n�b�^�������p�z��ƏƂ炵���킹��ƁA
	//d = ans[0] f = ans[1] g = ans[2] h = ans[3]

	while(1){

		d_cnt = 0;

		search++;
		printf("�T�� %d ���\n",search);
		printf("���ݐ[�� %d\n",p);

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
	

		//�\��
			printf("p�̏��\n");
			printf("%d %d %d\n%d %d %d\n%d %d %d\n",panel[p].a, panel[p].b, panel[p].c
												     ,panel[p].d, panel[p].e, panel[p].f
												     ,panel[p].g, panel[p].h, panel[p].i);
		getchar();
		printf("��\n\n");

	if(a[0][0] == 1 && a[0][1] == 2 && a[0][2] == 3 &&
	   a[1][0] == 4 && a[1][1] == 5 && a[1][2] == 6 &&
	   a[2][0] == 7 && a[2][1] == 8){
		   printf("�I��\n");
		   return 0;
	}

	pattern = Move(pass);
	printf("%d�����ړ���\n",pattern);

	for(i = 0; i < pattern; i++){
		ans_copy[i] = ans[i];
	}

	box = 0;

	//�����o�u���\�[�g
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
	printf("�̏��ɒT��\n\n");
	
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
		printf("1�ʉ�\n");
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
		printf("2�ʉ�\n");
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
		printf("3�ʉ�\n");
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
		//printf("3�ʉ�\n");
		if(d_cnt == 4){
			p--;
		}

		printf("%d\n����",i);
		i = i++;

		if(p == MAX){
			printf("�[�����ő�ɂȂ�܂���\n");
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

	//�J�E���^
	int i = 0;
	int n = 0;

	int ii = 0;
	int nn = 0;

	//��
	int aa = 0 , bb = 0;
	int x = 0 , y = 0;
	int ans = 0;

	////�}���n�b�^������
	while(1){
		for (i = 0; i < 3; i++){ // y��

			for (n = 0; n < 3; n++){ //x��

				if(c[0][0] == 1 && c[0][1] == 2 && c[0][2] == 3 &&
				   c[1][0] == 4 && c[1][1] == 5 && c[1][2] == 6 &&
				   c[2][0] == 7 && c[2][1] == 8){break;}

				if (b[ii][nn] == d[i][n] && c[ii][nn] == 0){ 

				c[ii][nn] = d[i][n];//�ʂ̃��X�gc��a����
				y = abs(i - ii);
				x = abs(n - nn);

				//printf("�ڕW%d ",a[ii][nn]);

				//printf("%d ",x+y);

				ans = ans + x + y;

				//printf("�a%d\n",ans);
				
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

	//���Z�b�g
	for (i = 0; i < 3; i++){
			for(n = 0; n < 3; n++){
				c[i][n] = 0;
			}
	}

	printf("�p�^�[���P���a%d\n",ans);
	return ans;

}
int Man2(int m2){

	//�J�E���^
	int i = 0;
	int n = 0;

	int ii = 0;
	int nn = 0;

	//��
	int aa = 0 , bb = 0;
	int x = 0 , y = 0;
	int ans = 0;

	////�}���n�b�^������
	while(1){

		for (i = 0; i < 3; i++){ // y��

			for (n = 0; n < 3; n++){ //x��

				if(c[2][1] == 8 && c[2][0] == 7){break;}

				if (b[ii][nn] == f[i][n] && c[ii][nn] == 0){ 

				c[ii][nn] = f[i][n];//�ʂ̃��X�gc��a����
				y = abs(i - ii);
				x = abs(n - nn);

				//printf("�ڕW%d ",a[ii][nn]);

				//printf("%d ",x+y);

				ans = ans + x + y;

				//printf("�a%d\n",ans);

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

	//���Z�b�g
	for (i = 0; i < 3; i++){
			for(n = 0; n < 3; n++){
				c[i][n] = 0;
			}
	}
	printf("�p�^�[���Q���a%d\n",ans);
	return ans;
	
}
int Man3(int m3){

	//�J�E���^
	int i = 0;
	int n = 0;

	int ii = 0;
	int nn = 0;

	//��
	int aa = 0 , bb = 0;
	int x = 0 , y = 0;
	int ans = 0;

	////�}���n�b�^������
	while(1){
		for (i = 0; i < 3; i++){ // y��

			for (n = 0; n < 3; n++){ //x��

				if(c[2][1] == 8 && c[2][0] == 7){break;}

				if (b[ii][nn] == g[i][n] && c[ii][nn] == 0){ 

				c[ii][nn] = g[i][n];//�ʂ̃��X�gc��a����
				y = abs(i - ii);
				x = abs(n - nn);

				//printf("�ڕW%d ",a[ii][nn]);
				
				//printf("%d ",x+y);

				ans = ans + x + y;

				//printf("�a%d\n",ans);
				
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

	//���Z�b�g
	for (i = 0; i < 3; i++){
			for(n = 0; n < 3; n++){
				c[i][n] = 0;
			}
	}
	printf("�p�^�[���R���a%d\n",ans);
	return ans;
	
}
int Man4(int m4){

	//�J�E���^
	int i = 0;
	int n = 0;

	int ii = 0;
	int nn = 0;

	//��
	int aa = 0 , bb = 0;
	int x = 0 , y = 0;
	int ans = 0;

	////�}���n�b�^������
	while(1){
		for (i = 0; i < 3; i++){ // y��

			for (n = 0; n < 3; n++){ //x��

				if(c[2][1] == 8 && c[2][0] == 7){break;}

				if (b[ii][nn] == h[i][n] && c[ii][nn] == 0){ 

				c[ii][nn] = h[i][n];//�ʂ̃��X�gc��a����
				y = abs(i - ii);
				x = abs(n - nn);

				//printf("�ڕW%d ",a[ii][nn]);
				
				//printf("%d ",x+y);

				ans = ans + x + y;

				//printf("�a%d\n",ans);
				
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

	//���Z�b�g
	for (i = 0; i < 3; i++){
			for(n = 0; n < 3; n++){
				c[i][n] = 0;
			}
	}
	printf("�p�^�[���S���a%d\n",ans);
	return ans;
	
}
int Move(int mov){

	//�ϐ�
	int root1 = 0;
	int root2 = 0;
	int root3 = 0;
	int root4 = 0;

	//��
	int x = 0 , y = 0;

	//�J�E���^
	int i = 0;
	int n = 0;

	int ii = 0;
	int nn = 0;

	int count = 0;
	int count2 = 0;

	while(1){

		//printf("ok\n");

		//���[�v�L��
		roop_y1 = roop_y;
		roop_x1 = roop_x;

		
		roop_y = i;
		roop_x = n;

		//�R�s�[���z�񃊃Z�b�g
		for (i = 0; i < 3; i++){
			for(n = 0; n < 3; n++){
				d[i][n] = a[i][n];
				f[i][n] = a[i][n];
				g[i][n] = a[i][n];
				h[i][n] = a[i][n];
			}
			ans[i] = 0;
		}
		
		///9�ړ�����
		for (i = 0; i < 3; i++){
			if(count == 1){break;}
			for (n = 0; n < 3; n++){
				if(a[i][n] == 9){ //9����

					//����L��
					if(count == 0){
						roop_y = i;
						roop_x = n;
					}

					if(i == 0 && n == 0){ //00 �E�E��
						//printf("�O��%d %d\n",roop_y1,roop_x1);
						d[i][n] = d[i][n+1];
						d[i][n+1] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i+1][n];
						f[i+1][n] = 9;
						ans[1] = Man2(root2);

						return 2;
					}
					if(i == 0 && n == 1){ //01 �E�E���E��
						//printf("�O��%d %d\n",roop_y1,roop_x1);
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
					if(i == 0 && n == 2){ //02 ���E��
						//printf("�O��%d %d\n",roop_y1,roop_x1);
						d[i][n] = d[i+1][n];
						d[i+1][n] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i][n-1];
						f[i][n-1] = 9;
						ans[1] = Man2(root2);

						return 2;
					}
					if(i == 1 && n == 0){ //10 �E�E���E��
						//printf("�O��%d %d\n",roop_y1,roop_x1);
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
					if(i == 1 && n == 1){ //11 �E�E���E���E��
						//printf("�O��%d %d\n",roop_y1,roop_x1);
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
					if(i == 1 && n == 2){ //12 ���E���E��
						//printf("�O��%d %d\n",roop_y1,roop_x1);
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
					if(i == 2 && n == 0){ //20 �E�E��
						//printf("�O��%d %d\n",roop_y1,roop_x1);
						d[i][n] = d[i][n+1];
						d[i][n+1] = 9;
						ans[0] = Man(root1);

						f[i][n] = a[i-1][n];
						f[i-1][n] = 9;
						ans[1] = Man2(root2);

						return 2;
					}
					if(i == 2 && n == 1){ //21 �E�E���E��
						//printf("�O��%d %d\n",roop_y1,roop_x1);
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
					if(i == 2 && n == 2){ //22 ���E��
						//printf("�O��%d %d\n",roop_y1,roop_x1);
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
		    //printf("�ߋ��ɓ����g�ݍ��킹������܂���\n");
				return 1;
		 }
		  i = i + 1;
		  //printf("ok");
	}
	return 2;
}