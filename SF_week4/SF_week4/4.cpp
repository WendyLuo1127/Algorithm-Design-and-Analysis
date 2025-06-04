#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // 初始情况：1种方法（什么都不跳）
    if (n >= 1) dp[1] = 1;
    if (n >= 2) dp[2] = 2;
    if (n >= 3) dp[3] = 4;

    for (int i = 4; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cout << dp[n] << endl;
    return 0;
}
