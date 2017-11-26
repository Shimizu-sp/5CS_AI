#include <stdio.h>
#include <string.h>

int main(){
    //意味ネットワーク
    char sem[3][2][255] =    {{"生物", "呼吸"},
                            {"鳥", "翼"},
                            {"オウム", "モノマネ"}};
    //0:名前 1以降:要素
    
    int name_no, ans = 0;
    printf("Q1:オウムの特技はなんですか\n");
    //オウム探索
    for(int cnt_no = 0; cnt_no < 3; cnt_no++){
        if(!strcmp(sem[cnt_no][0], "オウム")){
            name_no = cnt_no;
            break;
        }
    }
    //オウムの要素
    printf("%s\n", sem[name_no][1]);
    
    printf("Q2:オウムは呼吸するか\n");
    //オウム探索
    for(int cnt_no = 0; cnt_no < 3; cnt_no++){
        if(!strcmp(sem[cnt_no][0], "オウム")){
            name_no = cnt_no;
            break;
        }
    }
    //オウムの要素探索
    for(int cnt_no = name_no; cnt_no != -1; cnt_no--){
        printf("is-a : %s - %s\n", sem[cnt_no][0], sem[cnt_no][1]);
        if(!strcmp(sem[cnt_no][1], "呼吸")){
            printf("Yes\n");
            ans = 1;
        }
    }
    if(ans != 1){
        printf("No\n");
    }
    
    return 0;
}
