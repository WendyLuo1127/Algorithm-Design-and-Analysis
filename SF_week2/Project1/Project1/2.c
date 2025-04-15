#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int count = 0;  // 记录结果的个数

void find(int m, int n, int right, int down, int sum, int matrix[][100], int result[])
{
    // 如果到达右下角，记录当前路径的和
    if (right == n - 1 && down == m - 1) {
        result[count] = sum;
        count++;
        return;
    }

    // 如果可以向右移动
    if (right < n - 1) {
        find(m, n, right + 1, down, sum + matrix[down][right + 1], matrix, result);
    }

    // 如果可以向下移动
    if (down < m - 1) {
        find(m, n, right, down + 1, sum + matrix[down + 1][right], matrix, result);
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[100][100];

    // 读取矩阵数据
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result[100];  // 存储所有路径的和

    // 从矩阵的左上角开始递归查找路径
    find(m, n, 0, 0, matrix[0][0], matrix, result);

    // 找出最大路径和
    int max = result[0];
    for (int i = 1; i < count; i++) {
        if (max < result[i]) {
            max = result[i];
        }
    }

    printf("%d", max);  // 输出最大路径和
    return 0;
}
