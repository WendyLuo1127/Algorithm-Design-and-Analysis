#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[100][100];
    int dp[100][100];  // dp数组用来存储路径和

    // 输入矩阵
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 初始化dp数组的第一个位置
    dp[0][0] = matrix[0][0];

    // 填充第一行（只能从左边过来）
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
    }

    // 填充第一列（只能从上面过来）
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }

    // 填充剩下的dp数组（可以从左或者从上过来）
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = matrix[i][j] + (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
        }
    }

    // 输出右下角的最大路径和
    printf("%d", dp[m - 1][n - 1]);

    return 0;
}
