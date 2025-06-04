#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, S;
vector<vector<int>> t;
int best = INT_MAX;

void dfs(int cur, int count, int cost, vector<bool>& visited) {
    if (cost >= best) return; // 剪枝1：当前耗时已超过最优解

    if (count == n) {
        if (t[cur][S] > 0) { // 回到起点
            best = min(best, cost + t[cur][S]);
        }
        return;
    }

    for (int next = 0; next < n; ++next) {
        if (!visited[next] && t[cur][next] > 0) {
            visited[next] = true;
            dfs(next, count + 1, cost + t[cur][next], visited);
            visited[next] = false;
        }
    }
}

int main() {
    cin >> n;
    t.assign(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> t[i][j];
    cin >> S;
    S--; // 转为0下标

    vector<bool> visited(n, false);
    visited[S] = true;
    dfs(S, 1, 0, visited);

    cout << (best == INT_MAX ? -1 : best) << endl;
    return 0;
}
