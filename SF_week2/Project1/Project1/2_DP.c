#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[100][100];
    int dp[100][100];  // dp���������洢·����

    // �������
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // ��ʼ��dp����ĵ�һ��λ��
    dp[0][0] = matrix[0][0];

    // ����һ�У�ֻ�ܴ���߹�����
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
    }

    // ����һ�У�ֻ�ܴ����������
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }

    // ���ʣ�µ�dp���飨���Դ�����ߴ��Ϲ�����
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = matrix[i][j] + (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
        }
    }

    // ������½ǵ����·����
    printf("%d", dp[m - 1][n - 1]);

    return 0;
}
