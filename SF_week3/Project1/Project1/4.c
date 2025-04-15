#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 50

// 存储预处理结果的数组
long long ans[MAX_N + 1];

// 预处理所有可能的结果
void preprocess() {
    ans[1] = 3;  // 当 n = 1 时，直接返回 3
    long long prev0 = 0, prev1 = 3;  // 分别对应 dp[1][0] 和 dp[1][1]

    for (int k = 2; k <= MAX_N; k++) {
        long long curr0 = prev0 * 1 + prev1 * 2;
        long long curr1 = prev0 * 1;
        ans[k] = curr0;
        prev0 = curr0;
        prev1 = curr1;
    }
}

int main() {
    int n;

    // 预处理结果
    preprocess();

    // 读取输入并输出结果
    while (scanf("%d", &n) == 1) {
        printf("%lld\n", ans[n]);
    }

    return 0;
}