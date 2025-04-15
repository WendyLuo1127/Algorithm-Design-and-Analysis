//背包问题，物体可重复

#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    int dp[1001] = { 0 }; // dp[j] 表示背包容量为 j 时的最大战斗力

    for (int i = 0; i < N; ++i) {
        int vi, wi;
        cin >> vi >> wi;
        // 顺序遍历可重复使用同一物品
        for (int j = vi; j <= V; ++j) {
            dp[j] = max(dp[j], dp[j - vi] + wi);
            //cout << dp[j] << " ";
        }
        //cout << endl;
    }
    cout << dp[V] << endl;
    return 0;
}