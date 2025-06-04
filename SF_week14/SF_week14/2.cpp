#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
vector<vector<int>> skill;  // 熟练度矩阵
int maxScore = 0;
vector<int> maxInCol;       // 每列最大值，用于估价函数

// dfs + 剪枝
void dfs(int player, int currentScore, vector<bool>& visited) {
    if (player == k) {
        maxScore = max(maxScore, currentScore);
        return;
    }

    // 乐观估计：当前分数 + 剩下所有列最大值之和
    int optimistic = currentScore;
    for (int i = player; i < k; i++) {
        optimistic += maxInCol[i];
    }
    if (optimistic <= maxScore) return;  // 剪枝1：无法超越已有最优解

    for (int pos = 0; pos < k; pos++) {
        if (!visited[pos]) {
            visited[pos] = true;
            dfs(player + 1, currentScore + skill[player][pos], visited);
            visited[pos] = false;
        }
    }
}

int main() {
    cin >> k;
    skill.assign(k, vector<int>(k));
    maxInCol.assign(k, 0);

    // 读取熟练度矩阵
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> skill[i][j];
            maxInCol[j] = max(maxInCol[j], skill[i][j]);  // 提前计算每列最大值
        }
    }

    vector<bool> visited(k, false);
    dfs(0, 0, visited);

    cout << maxScore << endl;
    return 0;
}
