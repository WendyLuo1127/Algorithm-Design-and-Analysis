<<<<<<< HEAD
//设计两个状态：
//dp[n][0]: 长度为 n 的排列，首尾不相同
//dp[n][1]: 长度为 n 的排列，首尾相同
=======
//璁捐涓や釜鐘舵�侊細
//dp[n][0]: 闀垮害涓?n 鐨勬帓鍒楋紝棣栧熬涓嶇浉鍚?
//dp[n][1]: 闀垮害涓?n 鐨勬帓鍒楋紝棣栧熬鐩稿悓
>>>>>>> ad4a1f21ff5ef0d35c5690d6568ca2cc749853f6

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 50

long long dp[MAX_N + 1][2];

void preprocess() {
<<<<<<< HEAD
    dp[1][0] = 3;  // 首尾不同
    dp[1][1] = 0;  // 首尾相同不可能

    for (int i = 2; i <= MAX_N; ++i) {
        dp[i][0] = dp[i - 1][0] * 1 + dp[i - 1][1] * 2; //首尾不同
        dp[i][1] = dp[i - 1][0] * 1; //首尾相同
=======
    dp[1][0] = 3;  // 棣栧熬涓嶅悓
    dp[1][1] = 0;  // 棣栧熬鐩稿悓涓嶅彲鑳?

    for (int i = 2; i <= MAX_N; ++i) {
        dp[i][0] = dp[i - 1][0] * 1 + dp[i - 1][1] * 2; //棣栧熬涓嶅悓
        dp[i][1] = dp[i - 1][0] * 1; //棣栧熬鐩稿悓
>>>>>>> ad4a1f21ff5ef0d35c5690d6568ca2cc749853f6
    }
}

int main() {
    int n;
    preprocess();

    while (scanf("%d", &n) == 1) {
        printf("%lld\n", dp[n][0]);
    }

    return 0;
}
