#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MaxK 16

int k;  // 玩家数量
vector<vector<int>> scores;  // 得分矩阵
vector<bool> visited;  // 标记位置是否已被分配
int max_score = 0;  // 最大得分

void branch_bound(int player, int current_score) {
	if (player == k) {
		// 所有玩家已分配，更新最大得分
		max_score = max(max_score, current_score);
		return;
	}

	// 对每个位置进行尝试
	for (int i = 0; i < k; ++i) {
		if (!visited[i]) {  // 如果位置i没有被分配
			visited[i] = true;  // 标记位置i为已分配
			branch_bound(player + 1, current_score + scores[player][i]);  // 分配第player个玩家到位置i
			visited[i] = false;  // 回溯，撤销选择
		}
	}
}


int main() {
	cin >> k;

	scores.resize(k, vector<int>(k));
	visited.resize(k, false);

	// 输入得分矩阵
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> scores[i][j];
		}
	}

	// 从第0个玩家开始进行分配
	branch_bound(0, 0);

	// 输出最大得分
	cout << max_score << endl;
	return 0;
}