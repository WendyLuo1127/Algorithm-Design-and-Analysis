
//�������״̬��
//dp[n][0]: ����Ϊ n �����У���β����ͬ
//dp[n][1]: ����Ϊ n �����У���β��ͬ


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 50

long long dp[MAX_N + 1][2];

void preprocess() {

    dp[1][0] = 3;  // ��β��ͬ
    dp[1][1] = 0;  // ��β��ͬ������

    for (int i = 2; i <= MAX_N; ++i) {
        dp[i][0] = dp[i - 1][0] * 1 + dp[i - 1][1] * 2; //��β��ͬ
        dp[i][1] = dp[i - 1][0] * 1; //��β��ͬ
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
