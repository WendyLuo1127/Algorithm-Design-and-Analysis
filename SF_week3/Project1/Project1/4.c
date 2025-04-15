#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 50

// �洢Ԥ������������
long long ans[MAX_N + 1];

// Ԥ�������п��ܵĽ��
void preprocess() {
    ans[1] = 3;  // �� n = 1 ʱ��ֱ�ӷ��� 3
    long long prev0 = 0, prev1 = 3;  // �ֱ��Ӧ dp[1][0] �� dp[1][1]

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

    // Ԥ������
    preprocess();

    // ��ȡ���벢������
    while (scanf("%d", &n) == 1) {
        printf("%lld\n", ans[n]);
    }

    return 0;
}