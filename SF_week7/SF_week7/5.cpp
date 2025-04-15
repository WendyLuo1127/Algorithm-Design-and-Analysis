#include <vector>
#include <iostream>
using namespace std;

vector<int> calculatePower(int n) {
    vector<int> dp(n + 1); // dp[i] 表示 i 的二进制中 1 的个数
    dp[0] = 0; // 边界条件
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = dp[i / 2]; // 偶数
        }
        else {
            dp[i] = dp[i / 2] + 1; // 奇数
        }
    }
    return dp;
}

int main() {
    int n;
    cin >> n; // 输入 n
    vector<int> result = calculatePower(n); // 获取结果

    // 输出结果
    for (int i = 0; i <= n; i++) {
        cout << result[i] << " ";
    }
    return 0;
}