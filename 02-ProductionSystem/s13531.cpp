#include<stdio.h>
#include<string.h>

int main(void){
	char a[12] = "a*b-cd/e+fg";   //����WM
	char b[12] = "gfedcba+-*/";   //�I���\��WM
	int i,k=0;
	char change1;

	while(strcmp(a,b)){
		k = k++;
		//�E���獶�܂ň��
		for (i = 0; i <= 9; i++){
			//PM R1:�A���t�@�x�b�g�����ɁA�L�����E��
			if (a[i] <= a[i+1]){           
				change1 = a[i];
				a[i] = a[i + 1];
				a[i + 1] = change1;
			}
			//PM R2:�A���t�@�x�b�g���m�ł̏��ԕύX
			if (a[i]>=60 && a[i+1] >= 60 && a[i] <= a[i+1] ){      
				change1 = a[i];
				a[i] = a[i + 1];
				a[i + 1] = change1;
			}
			//PM R3:�L�����m�ł̏��ԕύX
			if (a[i] <= 60 && a[i + 1] <= 60){
				switch (a[i + 1]){
				//�L�����m�Ŕ�r�����Ƃ��u+�v���E�ɂ���ꍇ
				case 43:
					change1 = a[i];
					a[i] = a[i + 1];
					a[i + 1] = change1;
					break;
				//�L�����m�Ŕ�r�����Ƃ��u-�v���E�ɂ���A�^�����u+�v�ł͂Ȃ��ꍇ
				case 45:
					if (a[i] != 43){
						change1 = a[i];
						a[i] = a[i + 1];
						a[i + 1] = change1;
					}
					break;
				//�L�����m�Ŕ�r�����Ƃ��u*�v���E�ɂ���A�^�����u+�v���u-�v�ł͂Ȃ��ꍇ
				case 42:
					if (a[i] != 43 && a[i] != 45){
						change1 = a[i];
						a[i] = a[i + 1];
						a[i + 1] = change1;
					}
					break;
				default:
					break;
				}
			}
			//WM�̕\�� 
			printf("WM %s \n",a);         
		}
		//�������
		printf("%d���� �����I��\n",k);
	}
	//WM�ύX����
	printf("�ύX����\n");
}

