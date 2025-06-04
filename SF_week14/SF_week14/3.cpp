#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;
int n, S;  // n是节点数，S是起点编号
vector<vector<int>> adj;  // 邻接矩阵

// 动态规划 - 最短路径问题
vector<vector<int>> dp;

//(1 << i)   表示第 i 个点的掩码
//mask& (1 << i)   检查点 i 是否已访问
// mask | (1 << i)   将点 i 标记为“已访问”

int tsp(int mask, int pos) {
    // 如果所有的点都已经访问过了，返回起点的距离
    if (mask == (1 << n) - 1) {
        return adj[pos][S];  // 从当前节点返回起点
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];  // 如果已经计算过这个状态，直接返回结果
    }

    int ans = INF;
    for (int city = 0; city < n; ++city) {
        // 如果city没有被访问过
        if ((mask & (1 << city)) == 0) {
            int newAns = adj[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;  // 存储并返回最优解
}

int main() {
    cin >> n;
    adj.resize(n, vector<int>(n));

    // 输入邻接矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    // 输入起点S
    cin >> S;
    S--;  // 调整为0-index

    dp.assign(1 << n, vector<int>(n, -1));  // 初始化dp数组

    int result = tsp(1 << S, S);  // 从起点出发
    if (result == INF) {
        cout << -1 << endl;  // 如果无法找到路径，输出-1
    }
    else {
        cout << result << endl;  // 输出最短路径
    }

    return 0;
}
