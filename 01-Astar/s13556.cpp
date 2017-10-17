
#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<queue>

using namespace std;

#define N (3)
#define N2 (9)
#define MBAN (30);

//�ړ������̐ݒ�
static const int dx[4] = { 0, -1, 0, 1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'r', 'u', 'l', 'd' };
static const int question[N2] = {
	8, 1, 5,
	2, 0, 4,
	6, 3, 7
};

//�}���n�b�^�������ꗗ
int man_d[N2][N2];

//�p�Y���{��
struct Puzzle {
	int f[N2], space, man;
	int cost;

	bool operator<(const Puzzle &p)const {
		for (int i = 0; i < N2; i++) {
			if (f[i] == p.f[i])continue;
			return f[i] < p.f[i];
		}
		return false;
	}
};

//�K�� ���R�X�g���p��
struct State {
	Puzzle puzzle;
	int estimated;
	bool operator<(const State &s)const {
		return estimated > s.estimated;
	}
};

//�����o���p
vector<State> ban(30);

//�}���n�b�^�������Z�o
//��������abs���̖ʓ|�Ȃ̂ňꗗ����擾
int GetManhattan(Puzzle pz) {
	int sum = 0;
	for (int i = 0; i < N2; i++) {
		if (pz.f[i] == N2) {
			continue;
		}
		sum += man_d[i][pz.f[i] - 1];
	}
	return sum;
}

//�\���A�t�@�C����������
void Write(int count){
	FILE *fp, *fp2,*fp3;//fp�͐��ځAfp2�̓R�X�g�ƃ}���n�b�^������
	fopen_s(&fp, "Puzzle.txt", "w");
	fopen_s(&fp2, "Cost.txt", "w");
	fopen_s(&fp3, "Man.txt", "w");
	for (int i = 0; i <= count; i++){
		for (int j = 0; j < N2; j++){
			printf("%d ", ban[i].puzzle.f[j]);
			fprintf(fp,"%d ", ban[i].puzzle.f[j]);
			if (j == 2)printf(" cost:%d", ban[i].puzzle.cost);
			if (j == 5)printf(" dist:%d", ban[i].puzzle.man);
			if (j % N == N - 1) {
				printf("\n");
				fprintf(fp, "\n");
			}
		}
		printf("\n");
		fprintf(fp, "\n");
		fprintf(fp2, "%d,%d\n", ban[i].puzzle.cost, ban[i].estimated);
		fprintf(fp3, "%d,%d\n", ban[i].puzzle.cost, ban[i].puzzle.man);
	}
	fclose(fp);
	fclose(fp2);
	fclose(fp3);
}

bool Answer(Puzzle p){
	return
		p.f[0] == 1 &&
		p.f[1] == 2 &&
		p.f[2] == 3 &&
		p.f[3] == 4 &&
		p.f[4] == 5 &&
		p.f[5] == 6 &&
		p.f[6] == 7 &&
		p.f[7] == 8 &&
		p.f[8] == 9;
}

//�{��
int Astar(Puzzle s) {
	//�����錾
	priority_queue<State> PQ;
	s.man = GetManhattan(s);
	s.cost = 0;
	map<Puzzle, bool>V;
	Puzzle u, v, temp;
	//�����l�쐬
	State init;
	init.puzzle = s;
	init.estimated = GetManhattan(s);
	PQ.push(init);

	ban[init.puzzle.cost] = init;

	while (!PQ.empty()) {
		//�擪���o��
		State st = PQ.top(); PQ.pop();

		u = st.puzzle;

		//�}���n�b�^���Z�o
		if (u.man == 0){
			ban[st.puzzle.cost] = st;
			return u.cost;
		}
		V[u] = true;

		//Write(u);

		//���W�擾
		int sx = u.space / N;
		int sy = u.space % N;

		for (int r = 0; r < 4; r++) {
			//�e�����ƌ���
			int tx = sx + dx[r];
			int ty = sy + dy[r];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
			v = u;
			v.man -= man_d[tx * N + ty][v.f[tx * N + ty] - 1];
			v.man += man_d[sx * N + sy][v.f[tx * N + ty] - 1];

			//���W����
			swap(v.f[sx * N + sy], v.f[tx * N + ty]);

			v.space = tx * N + ty;
			//���o���ۂ�
			if (!V[v]) {
				//������̔Ֆʂ��L���[�ɃV���D�D�D�[�b�I
				v.cost++;
				State news;
				news.puzzle = v;
				news.estimated = v.cost + v.man;
				PQ.push(news);
				ban[news.puzzle.cost] = news;
			}
		}
	}
	return -1;
}

int main() {
	//�}���n�b�^���������˂�����
	for (int i = 0; i < N2; i++)
		for (int j = 0; j < N2; j++)
			man_d[i][j] = abs(i / N - j / N) + abs(i%N - j%N);
	//�����z�u
	Puzzle in;

	/*
	for (int i = 0;i < N2;i++) {
	cin >> in.f[i];
	if (in.f[i] == 0) {
	in.f[i] = N2;
	in.space = i;
	}
	}
	*/
	//�����錾
	in.f[0] = 8; in.f[1] = 1; in.f[2] = 5;
	in.f[3] = 2; in.f[4] = 0; in.f[5] = 4;
	in.f[6] = 6; in.f[7] = 3; in.f[8] = 7;
	for (int i = 0; i < N2; i++) {
		if (i % 3 == 0)printf("\n");
		if (in.f[i] == 0) {
			in.f[i] = N2;
			in.space = i;
		}
		printf("%d ", in.f[i]);
	}
	printf("\n\n");

	int n = Astar(in);

	Write(n);


	//getchar();
	return 0;
}