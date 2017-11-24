#include<stdio.h>
#include<string.h>
int main(void) {
	int s = 0, t = 0, o = 0, k = 0, tu = 0, tk = 0, y = 0, n = 0, b = 0, d = 0, a = 0, lp = 0;//変数の定義
	char str1[] = "生物";//事前設定の単語の設定
	char str2[] = "鳥";//事前設定の単語の設定
	char str3[] = "オーム";//事前設定の単語の設定
	char str4[] = "呼吸";//事前設定の単語の設定
	char str5[] = "翼";//事前設定の単語の設定
	char str6[] = "特技";//事前設定の単語の設定
	char str7[] = "ある";//事前設定の単語の設定
	char str8[] = "ない";//事前設定の単語の設定
	char str9[] = "する";//事前設定の単語の設定
	char str10[] = "しない";//事前設定の単語の設定
	char str11[50];//入力する文字の定義
	while (b = !0) {
		printf("文字列を入力してください\n");
		scanf_s("%s", str11,50);//文字の入力
		if (strstr(str11, str1) != NULL) {//文字に生物があるか確認
			s = 1;
			d = 1;
		}
		if (strstr(str11, str2) != NULL) {//文字に鳥があるか確認
			t = 1;
			d = 1;
		}
		if (strstr(str11, str3) != NULL) {//文字にオームがあるか確認
			o = 1;
			d = 1;
		}
		if (strstr(str11, str4) != NULL) {//文字に呼吸があるか確認
			k = 1;
			lp = 1;
		}
		if (strstr(str11, str5) != NULL) {//文字に翼があるか確認
			tu = 1;
			lp = 1;
		}
		if (strstr(str11, str6) != NULL) {//文字に特技があるか確認
			tk = 1;
			lp = 1;
		}
		if (strstr(str11, str7) != NULL) {//文字にあるがあるか確認
			y = 1;
		}
		if (strstr(str11, str8) != NULL) {//文字にないがあるか確認
			n = 1;
		}
		if (strstr(str11, str9) != NULL) {//文字にするがあるか確認
			y = 1;
		}
		if (strstr(str11, str10) != NULL) {//文字にしないがあるか確認
			n = 1;
		}if (d == 1) {//whileを抜ける
			break;
		}if (d = !1) {//違う文字が入力された場合
			printf("もう一度お願いします");
		}
	}
	while (b = !0) {
		if (o == 1) {//文字にオームがある場合
			if (tk == 1) {//文字に特技がある場合
				a = 1;
				printf("オームの特技はモノマネである\n");
				break;
			}
			else {//文字に特技がない場合
				t++;
				o++;
				printf("オームは鳥である\n");
			}
		}
		if (t >= 1) {//文字に鳥がある場合か上位として呼ばれた場合
			if (tu == 1) {//文字に翼がある場合
				a = 2;
				printf("鳥には翼がある\n");
				break;
			}
			else {//文字に翼がない場合
				s++;
				printf("鳥は生物である\n");
			}
		}
		if (s >= 1) {//文字に生物がある場合か上位として呼ばれた場合
			if (k == 1) {//文字に呼吸がある場合
				a = 3;
				printf("生物は呼吸をする\n");
				break;
			}
			else {//文字に呼吸がない場合
				a = 4;
				break;
			}
		}
	}
	if (a == 1) {
		printf("モノマネ\n");
	}
	if (a == 2) {
		if (y == 1) {
			printf("Yes\n");
		}
		if (n == 1) {
			printf("No\n");
		}
	}if (a == 3) {
		if (y == 1) {
			printf("Yes\n");
		}
		if (n == 1) {
			printf("No\n");
		}
	}
	return 0;
}