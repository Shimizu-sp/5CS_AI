#include<stdio.h>

main() {
	//�錾
	struct imi
	{
		int youso_bangou[10];//�v�f�𔻕ʂ��邽�߂̔ԍ�
		char youso[10];//�v�f

	};

	//�v�f�Ƃ������Ă��鏊
	struct imi imi[6]={

		{1,"����"}, 
		{2, "�ċz������" },
		{3, "��"},
		{4,"��������" },
		{5,"�I�[��"},
		{6,"���m�}�l" },

	};
	int shitsumon;
	printf("�u�I�[���̓��Z�ɂ��āv���₷��ꍇ�́u1�v���A�u�I�[���ɂ��āv���₷��ꍇ�́u2�v����͂��Ă��������B");
	scanf("%d", shitsumon);

	int a = 0;
	//������e�ɉ������Ή�������
	if (shitsumon == 1) {
		printf("�I�[���̓��Z�͂Ȃɂ��H\n");
		printf("�I�[���̓��Z�́u%s�v�ł���B", imi.youso[6]);
	}
	else {
		printf("�I�[���͌ċz�����邩�H\n");
		printf("�I�[���́u%s�v�Ȃ̂Łu%s�v�B", imi[1], imi[2]);
	}
	
}