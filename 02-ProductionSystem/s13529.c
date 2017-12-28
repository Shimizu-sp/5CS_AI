#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 11

char PM(char now[MAX]);
void swap(char *x, char *y);


int main(){
    //ワーキングメモリ(p)
    char p[12] = "gfedcba+-*/";

    int count = 0;
    int c_rule[4] = {0};

    printf("P = %s\n", p);

    //+:43    -:45    *:42      /:47
    //a:97    g:103
    while(1){
        count++;
        printf(":::::::Count is %d:::::::\n", count);

        for(int cnt = 0; cnt < MAX; cnt++){
            //ルールPM
            //1.現在の文字が記号 かつ 最後の要素でなければ、一つ後の文字と交換
            if(p[cnt] <= 47 && cnt < MAX - 1){
                printf("R1 ");
                swap(&p[cnt], &p[cnt + 1]);
                printf("\t%s\n", p);
            }
            //2.現在の文字が記号 かつ 最後の要素でない かつ 一つ後の要素より大きければ、一つ後の文字と交換
            if(p[cnt] <= 47 && cnt < MAX - 1 && p[cnt] > p[cnt + 1]){
                printf("R2 ");
                swap(&p[cnt], &p[cnt + 1]);
                printf("\t%s\n", p);
            }
            //3.現在の文字が* かつ 一つ後の文字が/でなければ、一つ後の文字と交換
            if(p[cnt] == 42 && p[cnt + 1] != 47){
                printf("R3 ");
                swap(&p[cnt], &p[cnt + 1]);
                printf("\t%s\n", p);
            }
            //4.現在の文字がアルファベット かつ 最初の要素でない かつ 前の値より高ければ、一つ前の文字と交換
            if(p[cnt] >= 97 && cnt != 0 && p[cnt] > p[cnt - 1]){
                printf("R4 ");
                swap(&p[cnt], &p[cnt - 1]);
                printf("\t%s\n", p);
            }
        }


        if(!strcmp(p, "gfedcba+-*/")){
            break;
        }

    }

    return 0;
}

void swap(char *x, char *y){
    printf("swap: %c %c\n", *x, *y);
    char tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
