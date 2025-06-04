//TSP旅行商问题 
// 不能用dijistra算法
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int n;
vector<vector<int>> dis;
vector<bool> visited;
int res = INT_MAX;

void dfs(int u, int depth, int cost) {
    if (depth == n - 1) { // 还剩一个城市没访问
        // 最后必须走到城市 n-1
        if (!visited[n - 1]) {
            res = min(res, cost + dis[u][n - 1]);
        }
        return;
    }

    for (int v = 0; v < n; v++) {
        if (!visited[v] && v != n - 1) { // 不走到 n-1 除非最后一步
            visited[v] = true;
            dfs(v, depth + 1, cost + dis[u][v]);
            visited[v] = false;
        }
    }
}

int main() {
    cin >> n;
    dis = vector<vector<int>>(n, vector<int>(n));
    visited = vector<bool>(n, false);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dis[i][j];

    visited[0] = true; // 从城市 0 出发
    dfs(0, 1, 0);

    cout << res << endl;
    return 0;
}
