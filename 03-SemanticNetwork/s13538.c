#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
	char tori[] = {"���͐����ł���"},
		 oumu[] = {"�I�[���͒��ł���"},
		 seibutsu[] = {"�����͌ċz����"},
		 tsubasa[] = {"���ɂ͗�������"},
		 monomane[] = {"�I�[���̓��Z�̓��m�}�l�ł���"};

	char check_tori[] = {"��"},
		 check_oumu[] = {"�I�[��"},
		 check_seibutsu[] = {"����"},
		 check_kokyuu[] = {"�ċz"},
		 check_monomane[] = {"���m�}�l"};
	
	char Q[1000], Q2[1000];
	int i;


	printf("�u�I�[���̓��Z�͂Ȃ�ł����v�Ǝ��₵�Ă��������B\n����F");
	gets(Q);/*�I�[���̓��Z�͂Ȃ�ł����Ɠ���*/

	if(!strcmp(Q, "�I�[���̓��Z�͂Ȃ�ł���")){ /*�I�[���̓��Z�͂Ȃ�ł����@�Ɠ��͂���Ă�����if���ɓ���*/

		if(strstr(Q,check_oumu)){ /*���͂��ꂽ���ɔz��check_oumu���܂܂ꂽ������check_monomane��\��*/

			printf("\n%s\n",check_monomane);

		}

	}else{/*�Ⴄ�����񂪓��͂��ꂽ�ꍇ*/

		printf("\n�w�肳�ꂽ�������͂��Ă�������\n");
		exit(0);/*�v���O�����I��*/

	}

	printf("\n------------------------------\n");
	printf("\n�u�I�[���͌ċz���邩�v�Ǝ��₵�Ă��������B\n����F");
	gets(Q2);/*�I�[���͌ċz���邩�Ɠ���*/

	if(!strcmp(Q2, "�I�[���͌ċz���邩")){ /*�I�[���͌ċz���邩�@�Ɠ��͂��ꂽ��if���ɓ���*/

		if(strstr(Q2,check_oumu)){ /*���͂��ꂽ���ɔz��check_oumu���܂܂�Ă�����if���ɓ���*/

			if(strstr(oumu,check_tori)){ /*�z��oumu�ɔz��check_tori���܂܂�Ă�����ȉ��̕���\�����Aif���ɓ���*/

				printf("\n�E�I�[�� is-a ���ł���");

				if(strstr(tori,check_seibutsu)){ /*�z��tori�ɔz��check_seibutsu���܂܂�Ă�����ȉ��̕���\�����Aif���ɓ���*/

					printf("\n�E�� is-a �����ł���");

					if(strstr(seibutsu,check_kokyuu)){ /*�z��seibutsu�ɔz��check_kokyuu���܂܂�Ă�����ȉ��̕���\������*/

						printf("\n�E�����͌ċz����\n�ȏ���A�I�[���͐����ł���");
						printf("\nAns�FYes\n\n");

					}
				}
			}
		}
	}else{ /*�Ⴄ�����񂪓��͂��ꂽ�ꍇ*/
		printf("\n�w�肳�ꂽ�������͂��Ă�������\n");
		exit(0);/*�v���O�����I��*/
	}
}
