#include <stdio.h>
#define S 11

int main(){
	char String[S][1] = {'a','*','b','-','c','d','/','e','+','f','g'};		//������
	char Evacuate[1];

	int Finish_Flag = 1;		//�����������������ǂ������Ǘ�����t���O
	int Counter = 0;				//���[�v�J�E���^

	printf("---�������---\n");
	
	for (int i = 0; i < S; i++)
		printf("%c", String[i][0]);

	printf("\n\n");
	while (Finish_Flag == 1){	//��������������܂Ń��[�v�����
		Finish_Flag = 0;		//�t���O��������(��������x�����Ă��Ȃ��Ƃ�����Ԃɂ���)
		Counter++;
		printf("---����%d���---\n",Counter);

		for (int i = 0; i < S; i++){
				//R1�̏���
			if ((String[i][0] >= 33 && String[i][0] <= 64)	//�����L��(ASCII�R�[�h��33�ȏォ��64�ȉ�)
					&& String[i+1][0] >= 97){					//�����A�E����������(97�ȏ�)�̏ꍇ

				Finish_Flag = 1;	//��Ƃ��s�����t���O�𗧂Ă�
				Evacuate[0] = String[i][0];			//�L����Evacuate�ɃR�s�[
				String[i][0] = String[i + 1][0];	//�L���̈ʒu�ɉE���̏�����������
				String[i + 1][0] = Evacuate[0];		//�������̈ʒu��Evacuate�ɑޔ������Ă����L��������
			}

				//R2�̏���
			if ((String[i][0] >= 97 && String[i][0] <= 122)			//������(ASCII�R�[�h��97�ȏ�122�ȉ�)
					&& (String[i+1][0] >= 97 && String[i+1][0] <= 122)	//�����E��������
						&& String[i][0] < String[i+1][0]) {					//���������E�̕���ASCII�R�[�h�̒l���傫���ꍇ

				Finish_Flag = 1;	//��Ƃ��s�����t���O�𗧂Ă�
				Evacuate[0] = String[i][0];			//���̏�������Evacuate�ɃR�s�[
				String[i][0] = String[i + 1][0];	//���ɉE���̏�����������
				String[i + 1][0] = Evacuate[0];		//�E��Evacuate�ɑޔ������Ă���������������
			}

				//R3�̏���
			if (String[i][0] == 47						//�����u/�v(ASCII�R�[�h��47)
					&& (String[i + 1][0] >= 33 && String[i+1][0] <=126)) {	//�����A�E�ɉ�������̕���������

				Finish_Flag = 1;	//��Ƃ��s�����t���O�𗧂Ă�
				Evacuate[0] = String[i][0];			//���́u/�v��Evacuate�ɃR�s�[
				String[i][0] = String[i + 1][0];	//���ɉE���̕���������
				String[i + 1][0] = Evacuate[0];		//�E��Evacuate�ɑޔ������Ă����u/�v������
			}

				//R4�̏���
			if ((String[i][0] >= 33 && String[i][0] <= 64)		//�����L��(ASCII�R�[�h��33�ȏォ��64�ȉ�)
				&& String[i+1][0] == 43) {								//�����A�E�����u+�v(ASCII�R�[�h��43)
			
				Finish_Flag = 1;	//��Ƃ��s�����t���O�𗧂Ă�
				Evacuate[0] = String[i][0];			//���̋L����Evacuate�ɃR�s�[
				String[i][0] = String[i + 1][0];	//���ɉE���́u+�v������
				String[i + 1][0] = Evacuate[0];		//�E��Evacuate�ɑޔ������Ă����L��������
			}

				//R5�̏���
			if (String[i][0] == 42				//�����u*�v(ASCII�R�[�h��42)
				&& String[i + 1][0] == 45) {		//�����A�E���u-�v(ASCII�R�[�h��45)
			

				Finish_Flag = 1;	//��Ƃ��s�����t���O�𗧂Ă�
				Evacuate[0] = String[i][0];			//���́u*�v��Evacuate�ɃR�s�[
				String[i][0] = String[i + 1][0];	//���ɉE���́u-�v������
				String[i + 1][0] = Evacuate[0];		//�E��Evacuate�ɑޔ������Ă����u*�v������
			}



		}
		if (Finish_Flag == 0)
			printf("***�������������܂���***\n");
		else
			for (int i = 0; i < S; i++)		//�����_�̕������printf
				printf("%c", String[i][0]);
		printf("\n\n");

	}
	getchar();
}