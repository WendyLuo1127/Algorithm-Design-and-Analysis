//背包问题,物品不可重复

#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    int dp[1001] = { 0 }; // dp[j] 表示背包容量为 j 时的最大战斗力

    for (int i = 0; i < N; ++i) {
        int vi, wi;
        cin >> vi >> wi;
        // 逆序遍历避免重复使用同一物品
        for (int j = V; j >= vi; --j) {
            dp[j] = max(dp[j], dp[j - vi] + wi);
        }
    }
    cout << dp[V] << endl;
    return 0;
}