//分支限界法
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, C, B0;
vector<int> recharge;
vector<vector<int>> dis;
int ans = INT_MAX;

void dfs(int u, int visited_count, int cost_sum, int battery, vector<bool>& visited, int minEdge) {
    // 剪枝1：当前路径已不优
    if (cost_sum >= ans) return;

    // 剪枝2：估价函数，最乐观的情况也也无法小于当前最优
    int optimistic = cost_sum + (n - visited_count) * minEdge;
    if (optimistic >= ans) return;

    // 剪枝3：剩2步但battery无法到终点
    if (n - visited_count <= 2 && dis[u][n - 1] > battery) return;

    // 剪枝4：battery太低且路径未完成
    if (battery < minEdge && n - visited_count > 1) return;

    // 所有节点访问完，检查终点是否合法
    if (visited_count == n) {
        if (u == n - 1)
            ans = min(ans, cost_sum);
        return;
    }

    for (int v = 0; v < n; ++v) {
        if (!visited[v] && dis[u][v] <= battery) {
            visited[v] = true;
            int new_battery = min(C, battery - dis[u][v] + recharge[v]);
            dfs(v, visited_count + 1, cost_sum + dis[u][v], new_battery, visited, minEdge);
            visited[v] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> C >> B0;
    recharge.resize(n);
    for (int i = 0; i < n; ++i) cin >> recharge[i];

    dis.assign(n, vector<int>(n));
    int minEdge = INT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> dis[i][j];
            if (i != j) minEdge = min(minEdge, dis[i][j]);
        }

    vector<bool> visited(n, false);
    visited[0] = true;
    dfs(0, 1, 0, B0, visited, minEdge);

    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}
