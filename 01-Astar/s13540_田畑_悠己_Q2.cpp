
#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<queue>

using namespace std;



#define N 3		//�p�Y���̑傫�����w��
#define N2 9	//N~2

//�ړ��Ǘ��p
static const int dx[4] = { 0,-1,0,1 };
static const int dy[4] = { 1,0,-1,0 };
static const char dir[4] = { 'r','u','l','d' };


//�}���n�b�^�������̌v�Z�p
int MDT[N2][N2];



//�p�Y���\����
struct Puzzle {
	int f[N2], space, MD;
	int count;

	bool operator<(const Puzzle &p)const {
		for (int i = 0;i < N2;i++) {
			if (f[i] == p.f[i])continue;
			return f[i] < p.f[i];
		}
		return false;
	}
};

//�p�Y���\���̂������X�e�C�g�\����
struct State {
	Puzzle puzzle;
	int estimated;
	bool operator<(const State &s)const {
		return estimated > s.estimated;
	}
};

int GetALLMD(Puzzle m); //�}���n�b�^���������v�Z
int astar(Puzzle s); //�T���֐�
void result(int n); //�T����̌o�H�\��

//�o�H�L�^�p
vector<State> Log(50);


//��������J�n
int main() {

	//�}���n�b�^�������̐ݒ�
	for (int i = 0;i < N2;i++)
		for (int j = 0;j < N2;j++) 
			MDT[i][j] = abs(i / N - j / N) + abs(i%N - j%N);


	Puzzle in;

	//�����Ֆʂ����
	in.f[0] = 8; in.f[1] = 1; in.f[2] = 5;
	in.f[3] = 2; in.f[4] = 0; in.f[5] = 4;
	in.f[6] = 6; in.f[7] = 3; in.f[8] = 7;
	for (int i = 0;i < N2;i++) {
		//if (i % 3 == 0)printf("\n");
		if (in.f[i] == 0) {
			in.f[i] = N2;
			in.space = i;
		}
		//printf("%d ",in.f[i]);
	}
	//printf("\n");

	//�萔��Ԃ�l�Ƃ���
	int n=astar(in);

	//����(�o�H�Ɣ����I�֐�)���o��
	
		result(n);
	

	getchar();
	return 0;
}

//�}���n�b�^���������v�Z
int GetALLMD(Puzzle m) {
	int sum = 0;
	for (int i = 0;i < N2;i++) {
		if (m.f[i] == N2)continue;
		sum += MDT[i][m.f[i] - 1];
	}
	return sum;
}

//�T���֐�
int astar(Puzzle s) {

	priority_queue<State> Qu; //�T�������i�[����L���[
	s.MD = GetALLMD(s); //���݂̔ՖʂŃ}���n�b�^���������v�Z
	s.count = 0; //�T���̐[��
	map<Puzzle, bool>V; //���o�Ֆʂ̔���
	Puzzle u, v;
	State first;
	first.puzzle = s; //�����Ֆʂ��i�[
	first.estimated = GetALLMD(s); //�}���n�b�^���������i�[
	Qu.push(first); //�L���[�ɏ�����ʂ��i�[

	while (!Qu.empty()) {
		State st = Qu.top();Qu.pop();	//�L���[����Ֆʂ����o��
		u = st.puzzle;


		Log[st.puzzle.count] = st; //�o�H���i�[

		if (u.MD == 0)return u.count; //�}���n�b�^��������0�Ȃ�ΏI��

		V[u] = true;

		//�}���n�b�^�������v�Z�p
		int sx = u.space / N;
		int sy = u.space % N;

		for (int r = 0;r < 4;r++) {
			//�T�����̔Ֆʍ쐬�p
			int tx = sx + dx[r];
			int ty = sy + dy[r];

			if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
			v = u;

			//�}���n�b�^���������X�V���Čv�Z
			v.MD -= MDT[tx * N + ty][v.f[tx * N + ty] - 1];
			v.MD += MDT[sx * N + sy][v.f[tx * N + ty] - 1];


			//�T�����̔Ֆʂ��쐬
			swap(v.f[sx * N + sy], v.f[tx * N + ty]);
			v.space = tx * N + ty;


			//�Ֆʂ����o�łȂ���΃L���[�Ɋi�[
			if (!V[v]) {
				v.count++;
				State next;
				next.puzzle = v;
				next.estimated = v.count + v.MD;
				Qu.push(next); //�L���[�Ɋi�[
			}

		}

	}
	return -1; //�G���[����
}

//�T����̌o�H�\���c������������
void result(int n) {

	FILE *fp1, *fp2,*fp3;

	fopen_s(&fp1, "�o�H.txt", "w");
	fopen_s(&fp2, "�����I�֐�.txt","w");
	fopen_s(&fp3, "�}���n�b�^������.txt", "w");
	for (int i = 0;i <= n;i++) {
		for (int j = 0;j < N2;j++) {
			if (j % 3 == 0) {
				printf("\n");
				fprintf(fp1, "\n");
			}
			printf("%d ", Log[i].puzzle.f[j]);
			fprintf(fp1,"%d ", Log[i].puzzle.f[j]);
		}
		printf("\n");
		fprintf(fp1, "\n");
		printf("%d\n", GetALLMD(Log[i].puzzle)+i);
		fprintf(fp2,"%d %d\n",i,GetALLMD(Log[i].puzzle)+i);
		fprintf(fp3, "%d %d\n", i, GetALLMD(Log[i].puzzle));
	}
	fprintf(fp1, "\n�萔%d\n",n);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
