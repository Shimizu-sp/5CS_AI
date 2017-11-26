#include<stdio.h>
typedef struct{
	int num;//値が小さいほど上位概念
	char Name[20];//概念の名前
	int num_x;//num=1…属性　num=2…特技
	char X[20];

}SNetwork;
main(){

	int i, k = 0;
	SNetwork n[3] = { { 1, "生物", 1, "呼吸する" }, { 2, "鳥", 1, "翼がある" }, { 3, "オーム", 2, "モノマネ" } };

	//オームの特技を聞く部分
	printf("Q1.オームの特技は何ですか？\n");
	for (i = 0; i < 3; i++){
		if (!strcmp(n[i].Name, "オーム") && n[i].num_x == 2){//オームに特技が記録されていれば答える
			printf("%d番の概念は%sのため特技を調べます…\n", n[i].num, n[i].Name);
			printf("A1.%sの特技は%sです。\n\n", n[i].Name, n[i].X);
		}
		else{
			printf("%d番の概念は%sだったため下位概念を調べます…\n", n[i].num, n[i].Name);
			k++;//見つからなかった回数
		}
	}
	if (k == 3){//もしオームが意味ネットワークに存在しなければ
		printf("Error:意味ネットワークに[オーム]という概念が存在しません\n");
	}

	k = 0;
	//オームは呼吸するか質問する部分
	printf("Q2.オームは呼吸しますか？\n");
	for (i = 2; i > -1; i--){
		if (!strcmp(n[i].X, "呼吸する")){//上位概念に呼吸する属性があればYes
			printf("%d番の%sに呼吸について記録がありました…\n", n[i].num, n[i].Name);
			printf("A2.Yes.\n\n");
		}
		else{
			printf("%d番の%sには呼吸について記録がなかったため上位概念を調べます…\n", n[i].num, n[i].Name);
			k++;//見つからなかった回数
		}
	}
	if (k == 3){//もし呼吸に関する記録が意味ネットワークに存在しなければ
		printf("Error:意味ネットワークに[呼吸]という属性が存在しません\n");
	}

	printf("end\n");
}