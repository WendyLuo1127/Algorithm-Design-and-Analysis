#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int m, n;
int matrix[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

// 定义方向数组，表示上下左右四个方向
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 判断是否在矩阵范围内
int isValid(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

// 深度优先搜索
void dfs(int x, int y) {
    visited[x][y] = 1;
    // 遍历四个方向
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        // 如果新位置在范围内，且未被访问过，并且是非零值
        if (isValid(newX, newY) && !visited[newX][newY] && matrix[newX][newY] != 0) {
            dfs(newX, newY);
        }
    }
}

int main() {
    // 读取矩阵的行数和列数
    scanf("%d %d", &m, &n);
    // 读取矩阵内容
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 读取每个位置的文化程度（0-9）
            scanf("%1d", &matrix[i][j]);
            visited[i][j] = 0; // 初始化访问标记
        }
    }

    int groupCount = 0;
    // 遍历整个矩阵
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 如果当前位置未被访问过且非零，表示找到一个新的讨论组
            if (!visited[i][j] && matrix[i][j] != 0) {
                dfs(i, j); // 进行深度优先搜索，标记所有连通的非零位置
                groupCount++; // 讨论组计数加1
            }
        }
    }

    // 输出学术讨论组的个数
    printf("%d\n", groupCount);
    return 0;
}
