/*
** �v���_�N�V�����V�X�e���̂��߂̃v���O����
** �쐬�ҁF�K�����
*/

#include<stdio.h>
#include<string.h>

//�֐��v���g�^�C�v�錾��

//str�̒�����1������擪������`�������A���̕������ŏ��ɔ������ꂽ���̃C���f�b�N�X��Ԃ��֐�
int StrSearch(char* str,char target);

//target�̈�E��me���z�u����Ă��Ȃ��ꍇme�̈�E�Ɍ����Ĉ�ړ�����
int MoveLeftofTarget(char* str,char me,char target);

int main(){
	char production[12]="a*b-cd/e+fg";	//���[�L���O�������̊J�n���
	char goal[12]="gfedcba+-*/";		//���[�L���O�������̏I�����
	int k;								//�֐��̖߂�l���i�[����ϐ�

	printf("�������:%s\n",production);

	//���[�L���O�����������蓖�Ă�
	while(1){
		//R1;g����Ԑ擪�ɂȂ��Ƃ��ɂ͈���Ɉړ�����
		if('g'!=production[0]){
			if(0>(k=StrSearch(production,'g'))){
				perror("production memory has broken.");
				return -1;
			}

			//g������Ɉړ�
			production[k]=production[k-1];
			production[k-1]='g';
		}

		//R2:f��g�̉E�ɑ��݂��Ȃ��ꍇ�ɂ͈��g�̉E�����Ɍ������ĂɈړ�����
		else if(1!=(k=MoveLeftofTarget(production,'f','g'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R3:e��f�̉E�ɑ��݂��Ȃ��ꍇ�ɂ͈��f�̉E�����Ɉړ�����
		else if(1!=(k=MoveLeftofTarget(production,'e','f'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R4:d��e�̉E�ɑ��݂��Ȃ��ꍇ�ɂ͈��e�̉E�����Ɉړ�����
		else if(1!=(k=MoveLeftofTarget(production,'d','e'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R5:c��d�̉E�ɑ��݂��Ȃ��ꍇ�ɂ͈��d�̉E�����Ɉړ�����
		else if(1!=(k=MoveLeftofTarget(production,'c','d'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R6:b��c�̉E�ɑ��݂��Ȃ��ꍇ�ɂ͈��c�̉E�����Ɉړ�����
		else if(1!=(k=MoveLeftofTarget(production,'b','c'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R7:a��b�̉E�ɑ��݂��Ȃ��ꍇ�ɂ͈��b�̉E�����Ɉړ�����
		else if(1!=(k=MoveLeftofTarget(production,'a','b'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R8:+��a�̉E�ɑ��݂��Ȃ��ꍇ�ɂ͈��a�̉E�����Ɉړ�����
		else if(1!=(k=MoveLeftofTarget(production,'+','a'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R9:-��+�̉E�ɑ��݂��Ȃ��ꍇ�ɂ͈��+�̉E�����Ɉړ�����
		else if(1!=(k=MoveLeftofTarget(production,'-','+'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R10:*��-�̉E�ɑ��݂��Ȃ��ꍇ�ɂ͈��-�̉E�����Ɉړ�����
		else if(1!=(k=MoveLeftofTarget(production,'*','-'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}

		//R11:/��*�̉E�ɑ��݂��Ȃ��ꍇ�ɂ͈��*�̉E�����Ɉړ�����
		else if(1!=(k=MoveLeftofTarget(production,'/','*'))){
			if(k<0){
				perror("main:MoveLeftofTarget");
				return -2;
			}
		}


		printf("���Z�r���̕�����:%s\n",production);

		//�I���m�F
		if(0==strcmp(production,goal)) break;
		
	}

	printf("����:%s\nEnter�������ďI��...\n",production);
	getchar();

}


//�֐��̒�����1������擪������`�������A���̕������ŏ��ɔ������ꂽ���̃C���f�b�N�X��Ԃ��֐�
//�߂�l��-1�̏ꍇ�ɂ͔����ł��Ȃ��������Ƃ�����
//���� : str;�������镶���� target;�����ړI�̕�����
int StrSearch(char* str,char target){
	size_t i;	//���[�v�J�E���^

	for(i=0;i<strlen(str);i++){
		if(str[i]=='\0') return -1;

		if(str[i]==target) return (int)i;
	}

	return -1;
}

//target�̈�E��me���z�u����Ă��Ȃ��ꍇme�̈�E�Ɍ����Ĉ�ړ�����
//�߂�l���}�C�i�X�̏ꍇ�ɂ̓G���[�A1�̏ꍇ�ɂ͂��łɊ���̈ʒu�ɑ��݂��邱�Ƃ�����
//���� : str;�ړ����镶�����i�[���ꂽ������ me;�ړ��� target;�ړ����������߂镶��
int MoveLeftofTarget(char* str,char me,char target){
	int k,n;

	if(0>(k=StrSearch(str,target))){
		perror("production memory has broken.");
		return -1;
	}
	if(0>(n=StrSearch(str,me))){
		perror("production memory has broken.");
		return -1;
	}

	if(k+1!=n){
		if(k>n){
			//f��g�̍����ɑ��݂���ꍇ
			str[n]=str[n+1];
			str[n+1]=me;
		}
		else{
			//f��g�̉E���ɑ��݂���Ƃ�
			str[n]=str[n-1];
			str[n-1]=me;
		}
	}
	else return 1;

	return 0;
}

