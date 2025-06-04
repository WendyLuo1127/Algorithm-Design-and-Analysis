#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    cin >> t >> n;
    vector<vector<int>> dis(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dis[i][j];

    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, INT_MAX));
    vector<vector<int>> pre(N, vector<int>(n, -1));

    dp[1][0] = 0;  // 从城市0出发，状态为000...001

    for (int mask = 1; mask < N; ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u)) || dp[mask][u] == INT_MAX) continue;
            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) continue; // 已访问
                int next_mask = mask | (1 << v);
                int new_dist = dp[mask][u] + dis[u][v];
                if (new_dist < dp[next_mask][v]) {
                    dp[next_mask][v] = new_dist;
                    pre[next_mask][v] = u;
                }
            }
        }
    }

    // 找以任意城市 u 结尾的最短路径
    int end_city = -1, min_cost = INT_MAX;
    int final_mask = (1 << n) - 1;
    for (int u = 0; u < n; ++u) {
        if (dp[final_mask][u] < min_cost) {
            min_cost = dp[final_mask][u];
            end_city = u;
        }
    }

    // 回溯路径
    vector<int> path;
    int mask = final_mask, u = end_city;
    while (u != -1) {
        path.push_back(u);
        int prev = pre[mask][u];
        mask ^= (1 << u);
        u = prev;
    }

    reverse(path.begin(), path.end());

    // 输出
    cout << t << endl;
    for (int i = 0; i < n; ++i) {
        cout << path[i] + 1; // 输出从1开始编号
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
