#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char defalut[11] = { 'a', '*', 'b', '-', 'c', 'd', '/', 'e', '+', 'f', 'g' }; //初期状態
char end[11] = { 'g', 'f', 'e', 'd', 'c', 'b', 'a', '+', '-', '*', '/' };//終了条件

int hantei();
int r1();
int r2();
int r3();
int r4();
int r5();
int r6();
int r7();
int r8();

int main(){

	int i, count = 0;
	
	printf("初期状態\n"); //初期状態
	for (i = 0; i < 11; i++)
	{
		printf("%c", defalut[i]); //初期状態
	}
	r1();
	r2();
	r3();
	r4();
	r5();
	r6();
	r7();
	r8();

	printf("\n\n");
	printf("\n最終状態\n");
	for (i = 0; i < 11; i++)
	{
		printf("%c", defalut[i]); //結果
	}
	count = hantei();
	printf("\n最終状態と一致した数:%d\n", count);
	printf("\n");
	return(0);
}
	//**********************************************************************
int r1(){
	int i, count = 0;
	char s;
	s = defalut[10];
	for (i = 0; i < 11; i++){	//gを先頭にソート
		if (i == 10){
			break;
		}
		defalut[10 - i] = defalut[9 - i];
	}
	defalut[0] = s;
	printf("\n");
	printf("\n");
	for (i = 0; i < 11; i++)
	{
		printf("%c", defalut[i]); //途中結果
	}
	count = hantei();
	printf("\nR1: gは配列の1番最初にソートされた 一致数:%d\n", count);
	printf("\n");
	return(0);
}
	//**********************************************************************
int r2(){
	int i, count = 0;
	char s;

	s = defalut[10];
	for (i = 0; i < 11; i++){	//fを2番目にソート
		if (i == 9){
			break;
		}
		defalut[10 - i] = defalut[9 - i];
	}
	defalut[1] = s;

	for (i = 0; i < 11; i++)
	{
		printf("%c", defalut[i]); //途中結果
	}
	count = hantei();
	printf("\nR2: fは配列の2番最初にソートされた 一致数:%d\n", count);
	printf("\n");
	return(0);
}
	//**********************************************************************
int r3(){
	int i, count = 0;
	char s;
	s = defalut[9];
	for (i = 0; i < 11; i++){	//eを3番目にソート
		if (i == 8){
			break;
		}
		defalut[9 - i] = defalut[8 - i];
	}
	defalut[2] = s;

	for (i = 0; i < 11; i++)
	{
		printf("%c", defalut[i]); //途中結果
	}
	count = hantei();
	printf("\nR3: eは配列の3番最初にソートされた 一致数:%d\n", count);
	printf("\n");
	return(0);
}
	//**********************************************************************
int r4(){
	int i, count = 0;
	char s;
	s = defalut[8];
	for (i = 0; i < 11; i++){	//dを4番目にソート
		if (i == 6){
			break;
		}
		defalut[8 - i] = defalut[7 - i];
	}
	defalut[3] = s;

	for (i = 0; i < 11; i++)
	{
		printf("%c", defalut[i]); //途中結果
	}
	count = hantei();
	printf("\nR4: dは配列の4番最初にソートされた 一致数:%d\n", count);
	printf("\n");
	return(0);
}
	//**********************************************************************
int r5(){
	int i, count = 0;
	char s;
	s = defalut[8];
	for (i = 0; i < 11; i++){	//cを5番目にソート
		if (i == 5){
			break;
		}
		defalut[8 - i] = defalut[7 - i];
	}
	defalut[4] = s;

	for (i = 0; i < 11; i++)
	{
		printf("%c", defalut[i]); //途中結果
	}
	count = hantei();
	printf("\nR5: cは配列の5番最初にソートされた 一致数:%d\n", count);
	printf("\n");
	return(0);
}
	//**********************************************************************
int r6(){
	int i, count = 0;
	char s;
	s = defalut[7];
	for (i = 0; i < 11; i++){	//bを6番目にソート
		if (i == 3){
			break;
		}
		defalut[7 - i] = defalut[6 - i];
	}
	defalut[5] = s;

	for (i = 0; i < 11; i++)
	{
		printf("%c", defalut[i]); //途中結果
	}
	count = hantei();
	printf("\nR6: bは配列の6番最初にソートされた 一致数:%d\n", count);
	printf("\n");
	return(0);
}
	//**********************************************************************
int r7(){
	int i, count = 0;
	char s;
	s = defalut[10];
	for (i = 0; i < 11; i++){	//+を8番目にソート
		if (i == 3){
			break;
		}
		defalut[10 - i] = defalut[9 - i];
	}
	defalut[7] = s;

	for (i = 0; i < 11; i++)
	{
		printf("%c", defalut[i]); //途中結果
	}
	count = hantei();
	printf("\nR7: +は配列の8番最初にソートされた 一致数:%d\n", count);
	printf("\n");
	return(0);
}
	//**********************************************************************
int r8(){
	int i, count = 0;
	char s;
	s = defalut[9];
	for (i = 0; i < 11; i++){	//-をを9番目にソート
		if (i == 1){
			break;
		}
		defalut[9 - i] = defalut[8 - i];
	}
	defalut[8] = s;

	for (i = 0; i < 11; i++)
	{
		printf("%c", defalut[i]); //途中結果
	}
	count = hantei();
	printf("\nR8: -は配列の9番最初にソートされた 一致数:%d\n", count);
	printf("\n");
	return(0);
}
	//**********************************************************************

int hantei(){		//最終状態との一致度
	int i, count = 0;
	for (i = 0; i < 11; i++)
	{
		if (defalut[i] == end[i]){
			count = count + 1;
		}
	}
	return(count);

}