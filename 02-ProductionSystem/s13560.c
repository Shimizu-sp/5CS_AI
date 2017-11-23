//
//  main.c
//  production
//
//  Created by 隆太鷲尾 on 2017/10/13.
//  Copyright © 2017年 隆太鷲尾. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>


 
int str[] = {'a', '*', 'b', '-', 'c','d', '/','e', '+', 'f', 'g'}; //初期の状態


 

int i,j;
int temp;






void R1(int a[], int n){ //R1 ASCII codeを参照して数値が大きい文字を左側に寄せる
    
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-1; j++){
            
            if (a[j] < a[j+1]){ //右側の文字の数値を比較して右側が大きい場合
                
                temp = a[j+1]; //一時的に保存
                a[j+1] = a[j]; //左の文字と右側の文字を入れ替える
                a[j] = temp;
                
            }
           
            for (int s = 0; s < n; s++) { printf("%c",a[s]); } //配列表示
            printf("  R1");
            printf("\n");

        }
    }
}



void R2(int b[]){ //str[7]に+が来るように演算子の部分だけを移動させる
    
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){

    if (b[7] != '+'){//str[7] が +でない場合
        
        temp = b[7+j];  //左と右の演算子を入れ替える
        b[7+j] = b[8+j];
        b[8+j] = temp;
    
    }else{ //str[7] に +が入ったら終了
        break;
    }

   
    for (int s = 0; s < 11; s++) { printf("%c",str[s]); }
            printf("  R2");
    printf("\n");
    
        }}}

int main(void){
    
    R1(str, 11);
    R2(str);
    
    
    }






















/*

#include <stdio.h>

int main(void)
{
    
    int i = 0;
    char moji[100];
    
    

    printf("文字列を入力してください = ");
    scanf("%s", moji);
    

    while(moji[i])
    printf("%d " , moji[i++]);
    
    printf("\n");
    
    return 0;
}

*/
