#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    vector<int> dp(W + 1, 0);

    // 遍历每个物品
    for (int i = 0; i < n; i++) {
        // 倒序遍历重量，确保每个物品只被考虑一次
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[W];
    return 0;
}