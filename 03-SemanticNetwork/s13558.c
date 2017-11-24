#include<stdio.h>

main() {
	//宣言
	struct imi
	{
		int youso_bangou[10];//要素を判別するための番号
		char youso[10];//要素

	};

	//要素とかを入れている所
	struct imi imi[6]={

		{1,"生物"}, 
		{2, "呼吸をする" },
		{3, "鳥"},
		{4,"翼がある" },
		{5,"オーム"},
		{6,"モノマネ" },

	};
	int shitsumon;
	printf("「オームの特技について」質問する場合は「1」を、「オームについて」質問する場合は「2」を入力してください。");
	scanf("%d", shitsumon);

	int a = 0;
	//質問内容に応じた対応をする
	if (shitsumon == 1) {
		printf("オームの特技はなにか？\n");
		printf("オームの特技は「%s」である。", imi.youso[6]);
	}
	else {
		printf("オームは呼吸をするか？\n");
		printf("オームは「%s」なので「%s」。", imi[1], imi[2]);
	}
	
}