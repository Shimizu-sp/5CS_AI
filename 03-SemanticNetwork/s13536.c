#include<stdio.h>
#include<string.h>

	struct a{
		char *topic;
		char *connect;
		char *chara;
	}
	main(void){
		char input[30];
		char *w1 = "�I�[��";
		char *w2 = "���Z";
		char *w3 = "�ċz������";
		int i , n , count = 0;

		struct a owm[20] = 
		{
			{"�I�[��","����","��"},
			{"�I�[��","���Z","���m�}�l"},
			{"��","����","����"},
			{"��","����","��������"},
			{"����","����","�ċz������"},
		};// �m���L�� {"��ꍀ��","��񍀖�","��O����"}

	while(1){
	scanf("%s",input);		
		if(strcmp(input,"�I�[���̓��Z�͉��ł���") == 0){
			for(i=0;i<5;i++){
				if(owm[i].connect == w2){// i�Ԗڂ̑�񍀖ڂ�"���Z"�������ꍇ
					printf("%s",owm[i].chara);// �\��
					getchar();
					count++;
					break;// �I��
			}
			}
		}
			getchar();
		if(strcmp(input,"�I�[���͌ċz���邩") == 0){
			for(i=0;i<5;i++){
				printf("%s��%s��%s\n",owm[i].topic,owm[i].connect,owm[i].chara);// i�Ԗڂ̕\���@{}
				for(n=0;n<5;n++){
					// i�Ԗڂ̑�O���ڂ�n�Ԗڂ̑�ꍀ�ڂ������ꍇ
					if(owm[i].chara == owm[n].topic){
						i = n - 1;// i��n-1����
						break;
					}
				}
				// i�Ԗڂ̑�O���ڂ�"�ċz������"�������ꍇ
				if(owm[i].chara == w3){
					printf("Yes");// Yes�ƕ\��
					getchar();
					count++;
					break;// �I��
				}
			}
		}
	if(count == 1){
		break;
	}else{
		printf("������x���͂��Ă�������\n");
	}
	}
	}