#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>

main(){
	char Seibutu[10] = "Yes";
	//////////�����̌ċz�ɂ��Ẵ^�O�ǉ�
	char SeibutuT[10] = "�ċz����";

	char Tori[10] = "Yes";
	/////////���̓����ɂ��Ẵ^�O�ǉ�
	char ToriT[10] = "��������";

	char Oumu[10] = "���m�}�l";
	//////////�I�[���̓��Z�ɂ��Ẵ^�O�ǉ�
	char OumuT[10] = "���Z�͉�";
	char Situmon[100];

	printf("�I�[���ɂ��Ă̎�������Ă�������\n");
	//�u���Z�͉��v�u��������v�u�ċz����v�������Ă�΂���
	scanf("%s", Situmon);

	if (strstr(Situmon, OumuT) != NULL)///�u���Z�͉��v�ɔ�������Oumu��Ԃ�
	{
		printf("%s\n", Oumu);
	}
	else{

		printf("�I�[���̓��Z�ɂ��Ăł͂Ȃ��̂Œ��ɂ��Č���\n");
		if (strstr(Situmon, ToriT) != NULL)///�u��������v�ɔ�������Tori��Ԃ�
		{
			printf("%s\n", Tori);
		}
		else{
			printf("�I�[���̓��Z�Ⓓ�̓����ɂ��Ăł͂Ȃ��̂Ő����ɂ��Č���\n");
			if (strstr(Situmon, SeibutuT) != NULL)///�u�ċz����v�ɔ�������Seibutu��Ԃ�
			{
				printf("%s\n", Seibutu);
			}
			else{
				printf("���݊m�F�ł��Ă��Ȃ��̂ŏI�����܂��B\n");
			}
		}

	}

}