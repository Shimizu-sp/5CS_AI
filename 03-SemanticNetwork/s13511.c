#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

main(){

	char array_name_1[100]; //配列名保存用
	char array_name_2[100];
	char array_name_3[100];
	char array_name_4[100];
	char array_name_5[100];

	//is-a関係
	char is_a_1[50] = "生物";
	char is_a_2[50] = "鳥"; //生物の概念
	char is_a_3[50] = "オーム"; //鳥の概念　

	//属性
	char attribute_1[50] = "呼吸" ; //生物の属性
	char attribute_2[50] = "翼がある"; //鳥の属性
	char attribute_3[50] = "モノマネ"; //オームの属性
	char attribute_name3[50] = "特技"; //オームの属性(詳細)

	//質問用配列
	char question_1[30] = "何ですか";
	char question_2[30] = "か";

	int flag1,flag2,flag3;
	int trueth = 0;
	int input = 0,mugen = 0;

	while(mugen == 0){

	flag1 = 0; flag2 = 0; flag3 = 0; trueth = 0;

	printf("\nメニュー(数字を入力してください)\n1:質問入力\n2:終了\n\n");

	scanf("%d",&input);
    
	if(input == 1){

	printf("\n 質問の単語間に半角スペースを入れてください\n");
	printf(" レポート内の質問文をコピペして頂ければ動きます\n\n");
	printf("===========================================================\n");
	printf("Q:");

	scanf("%s", array_name_1);
	scanf("%s", array_name_2);
	scanf("%s", array_name_3);
	scanf("%s", array_name_4);
	scanf("%s", array_name_5);

	//質問判定===============================================================

	//is-a関係判定s
	if(strcmp(array_name_1,is_a_1) == 0){ //入力されたis-aが「生物」であるか？
		flag1++;
		printf("\n生物　→");

	}else if(strcmp(array_name_1,is_a_2) == 0){ //入力されたis-aが「鳥」であるか？
		flag2++;
		printf("\n鳥　→");
	
	}else if(strcmp(array_name_1,is_a_3) == 0){ //入力されたis-aが「オーム」であるか？
		flag3++;
		printf("\nオーム　→");
	}

	//属性判定

	//オーム=======
	if(flag3 == 1){
		if(strcmp(array_name_3,attribute_name3) == 0){
			
			printf(" (特技)モノマネ");

			//質問語判定
	        if(strcmp(array_name_5,question_1) == 0){
			  printf("\nA:%s\n",attribute_3);
	        }else if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		}
	    }else if(strcmp(array_name_3,attribute_2) == 0){
			
           printf(" 鳥 →　翼がある");

		   //質問語判定
	       if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		}
		}else if(strcmp(array_name_3,attribute_1) == 0){

			printf(" 鳥 →　生物　→　呼吸する");

		   //質問語判定
	       if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		}
	}}

	//鳥=========
	if(flag2 == 1){
		if(strcmp(array_name_3,attribute_2) == 0){

			printf(" 翼がある");

		   //質問語判定
	       if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		}
		}else if(strcmp(array_name_3,attribute_1) == 0){
			
			printf(" 生物　→　呼吸する");

		   //質問語判定
		   if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		   }
	}}

	//生物=========
    if(flag1 == 1){
		if(strcmp(array_name_3,attribute_1) == 0){
			
		   printf(" 呼吸する");

		   //質問語判定
		   if(strcmp(array_name_5,question_2) == 0){
			  printf("\nA:YES\n");
		   }
    }}

	}else if(input==2){

		break;

	}
	
	input = 0;

	}

}