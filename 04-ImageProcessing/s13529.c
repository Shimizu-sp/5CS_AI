#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define IMG_MAX_SIZE 512
#define TIMG_MAX_SIZE 200

int main(){
    char ctmp;
    int itmp;
    int img[IMG_MAX_SIZE][IMG_MAX_SIZE] = {0}, timg[TIMG_MAX_SIZE][TIMG_MAX_SIZE] = {0};
    FILE *img_data;
    FILE *timg_data;
    
    FILE *img_csv;
    FILE *timg_csv;
    FILE *r_csv;
    FILE *r_csv_most;
    
    
    //ファイルストリーム
    if(NULL == (img_data = fopen("images/img_data_1.txt", "r"))){
        printf("Image open error\n");
        return -1;
    }
    if(NULL == (timg_data = fopen("images/Timg_data_1.txt", "r"))){
        printf("Timg open error\n");
        return -1;
    }
    
    //CSV用
    img_csv = fopen("img.csv", "w");
    timg_csv = fopen("timg.csv", "w");
    r_csv = fopen("r.csv", "w");
    
    //画像データ読み込み(同時にint型に変換)
    printf("Image load : ");
    for(int cnt1 = 0; cnt1 < IMG_MAX_SIZE; cnt1++){
        for(int cnt2 = 0; cnt2 < IMG_MAX_SIZE; cnt2++){
            for(int cnt3 = 0; cnt3 < 3; cnt3 ++){
                ctmp = fgetc(img_data);
                //スペース0埋め
                if(ctmp == 32)
                    ctmp = 48;
                itmp = ctmp - 48;
                if(cnt3 == 0)
                    itmp *= 100;
                else if(cnt3 == 1)
                    itmp *= 10;
                img[cnt1][cnt2] += itmp;
            }
            fprintf(img_csv, "%d,", img[cnt1][cnt2]);
        }
        fprintf(img_csv, "\n");
    }
    fclose(img_data);
    fclose(img_csv);
    printf("DONE\n");
    
    //テンプレート読み込み
    printf("Template load : ");
    for(int cnt1 = 0; cnt1 < TIMG_MAX_SIZE; cnt1++){
        for(int cnt2 = 0; cnt2 < TIMG_MAX_SIZE; cnt2++){
            for(int cnt3 = 0; cnt3 < 3; cnt3 ++){
                ctmp = fgetc(timg_data);
                //スペース0埋め
                if(ctmp == 32)
                    ctmp = 48;
                itmp = ctmp - 48;
                if(cnt3 == 0)
                    itmp *= 100;
                else if(cnt3 == 1)
                    itmp *= 10;
                timg[cnt1][cnt2] += itmp;
            }
            fprintf(timg_csv, "%d,", timg[cnt1][cnt2]);
        }
        fprintf(timg_csv, "\n");
    }
    fclose(timg_data);
    fclose(timg_csv);
    printf("DONE\n");
    
    
    //差の絶対値
    printf("Matching : ");
    
    int R, x, y;
    int Ans_x, Ans_y, Ans_value;
    
    //左上座標
    for(x = 0; x < IMG_MAX_SIZE - TIMG_MAX_SIZE; x++){
        for(y = 0; y < IMG_MAX_SIZE - TIMG_MAX_SIZE; y++){
            
            //Rを求める
            R = 0;
            for(int cnt1 = 0; cnt1 < TIMG_MAX_SIZE; cnt1++){
                for(int cnt2 = 0; cnt2 < TIMG_MAX_SIZE; cnt2++){
                    R += abs(img[cnt1 + x][cnt2 + y] - timg[cnt1][cnt2]);
                }
            }
            fprintf(r_csv, "%d,", R);
            //Rが最小か否か
            if(x == 0 && y == 0){
                Ans_value = R;
                Ans_x = x;
                Ans_y = y;
            }
            else{
                if(Ans_value > R){
                    Ans_value = R;
                    Ans_x = x;
                    Ans_y = y;
                }
            }
            
        }
        fprintf(r_csv, "\n");
    }
    fclose(r_csv);
    printf("DONE\n");
    
    printf("Result : R = %d (%d,%d)\n\n", Ans_value, Ans_x + 1, Ans_y + 1);
    
    return 0;
}

