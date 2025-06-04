#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MaxK 16

int k;  // �������
vector<vector<int>> scores;  // �÷־���
vector<bool> visited;  // ���λ���Ƿ��ѱ�����
int max_score = 0;  // ���÷�

void branch_bound(int player, int current_score) {
	if (player == k) {
		// ��������ѷ��䣬�������÷�
		max_score = max(max_score, current_score);
		return;
	}

	// ��ÿ��λ�ý��г���
	for (int i = 0; i < k; ++i) {
		if (!visited[i]) {  // ���λ��iû�б�����
			visited[i] = true;  // ���λ��iΪ�ѷ���
			branch_bound(player + 1, current_score + scores[player][i]);  // �����player����ҵ�λ��i
			visited[i] = false;  // ���ݣ�����ѡ��
		}
	}
}


int main() {
	cin >> k;

	scores.resize(k, vector<int>(k));
	visited.resize(k, false);

	// ����÷־���
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> scores[i][j];
		}
	}

	// �ӵ�0����ҿ�ʼ���з���
	branch_bound(0, 0);

	// ������÷�
	cout << max_score << endl;
	return 0;
}