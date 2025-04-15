//最长操作序列->动态规划

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;

    // 使用 vector 定义二维数组，支持变量大小
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}