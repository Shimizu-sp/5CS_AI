#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define renge (10)
#define sym (7)

using namespace std;

vector<char> str_sym = { '+', '-', '*', '/' };

int Check(vector<char> input){
	//�̂��݂�����ɂ�
	return input[0] > input[1] &&
		input[1] > input[2] &&
		input[2] > input[3] &&
		input[3] > input[4] &&
		input[4] > input[5] &&
		input[5] > input[6] &&
		input[6] > input[7] &&
		input[7] > input[8] &&
		input[8] > input[9] &&
		input[9] > input[10];
}

int SymChk(vector<char> input){
	//����������ɂ�
	return input[0] == str_sym[0] &&
		input[1] == str_sym[1] &&
		input[2] == str_sym[2] &&
		input[3] == str_sym[3];
}

int main(){
	//std::vector<char> question = { 'b', 'a', 'd', 'c', 'f', 'e', 'g' };

	vector<char> question = { 'a', '*', 'b', '-', 'c', 'd', '/', 'e', '+', 'f', 'g' };

	int i = 0;

	//�A���t�@�x�b�g�̏����E�L���u��

	while (!Check(question))
	{
		for (i = 0; i < renge; i++)
		{
			if (question[i] < question[i + 1])
			{
				swap(question[i], question[i + 1]);
				for (auto x : question) {
					cout << x << ",";
				}
				cout << endl;
			}
		}
	}

		//reverse(question.begin(), question.end());

	//�L����

	vector<char> symbol;
	//assign�ŋL�����̂݃R�s�[�B�������ςȂ��ƂɂȂ����̂ł����͕ʌ˂�����
	symbol.assign(&question[sym], &question[renge]);
	symbol.push_back(question[renge]);


	i = 0;
	int temp = 0;
	while (!SymChk(symbol)){
		for (i = 0; i < 4; i++)
		{
			if (symbol[i] == '+'){//+����0�ɂ˂�����
				temp = i;
				while (temp != 0){
					swap(symbol[temp], symbol[temp - 1]);
					temp--;
					for (auto x : symbol) {
						cout << x << ",";
					}
					cout << endl;
				}
			}
			if (symbol[i] == '-'){//-����1�ɂ˂�����
				temp = i;
				while (temp != 1){
					if (temp < 1)
						swap(symbol[temp], symbol[temp + 1]);
					else
						swap(symbol[temp], symbol[temp - 1]);
					
					temp--;
					for (auto x : symbol) {
						cout << x << ",";
					}
					cout << endl;
				}
			}
			if (symbol[i] == '*'){//*����2�ɂ˂�����
				temp = i;
				while (temp != 2){
					if (temp < 2)
						swap(symbol[temp], symbol[temp + 1]);
					else
						swap(symbol[temp], symbol[temp - 1]);
					temp--;
					for (auto x : symbol) {
						cout << x << ",";
					}
					cout << endl;
				}
			}
			if (symbol[i] == '/'){//[/]����3�ɂ˂�����
				temp = i;
				while (temp != 3){
					if (temp < 3){
						swap(symbol[temp], symbol[temp + 1]);
						temp++;
					}
					else{
						swap(symbol[temp], symbol[temp - 1]);
						temp--;
					}
					for (auto x : symbol) {
						cout << x << ",";
					}
					cout << endl;
				}
			}
		}
	}
	//�ŏI���ʂ̏o�͏���
	vector<char> answer;
	//symbol.assign(&question[sym], &question[renge]);

	//�A���t�@�x�b�g���A�T�C��+�����ɋL������}��
	answer.assign(&question[0], &question[7]);
	for (i = 0; i < 4; i++)
	{
		answer.push_back(symbol[i]);

	}
	//�ŏI���ʏo��
	for (auto x : answer) {
		cout << x << ",";
	}
	cout << endl;

	return 0;
}
