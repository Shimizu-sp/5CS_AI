#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>

main(){
	char Seibutu[10] = "Yes";
	//////////生物の呼吸についてのタグ追加
	char SeibutuT[10] = "呼吸する";

	char Tori[10] = "Yes";
	/////////鳥の特徴についてのタグ追加
	char ToriT[10] = "翼がある";

	char Oumu[10] = "モノマネ";
	//////////オームの特技についてのタグ追加
	char OumuT[10] = "特技は何";
	char Situmon[100];

	printf("オームについての質問をしてください\n");
	//「特技は何」「翼がある」「呼吸する」が入ってればおｋ
	scanf("%s", Situmon);

	if (strstr(Situmon, OumuT) != NULL)///「特技は何」に反応してOumuを返す
	{
		printf("%s\n", Oumu);
	}
	else{

		printf("オームの特技についてではないので鳥について検索\n");
		if (strstr(Situmon, ToriT) != NULL)///「翼がある」に反応してToriを返す
		{
			printf("%s\n", Tori);
		}
		else{
			printf("オームの特技や鳥の特徴についてではないので生物について検索\n");
			if (strstr(Situmon, SeibutuT) != NULL)///「呼吸する」に反応してSeibutuを返す
			{
				printf("%s\n", Seibutu);
			}
			else{
				printf("現在確認できていないので終了します。\n");
			}
		}

	}

}