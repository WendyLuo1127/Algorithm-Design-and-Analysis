#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int count = 0;  // ��¼����ĸ���

void find(int m, int n, int right, int down, int sum, int matrix[][100], int result[])
{
    // ����������½ǣ���¼��ǰ·���ĺ�
    if (right == n - 1 && down == m - 1) {
        result[count] = sum;
        count++;
        return;
    }

    // ������������ƶ�
    if (right < n - 1) {
        find(m, n, right + 1, down, sum + matrix[down][right + 1], matrix, result);
    }

    // ������������ƶ�
    if (down < m - 1) {
        find(m, n, right, down + 1, sum + matrix[down + 1][right], matrix, result);
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[100][100];

    // ��ȡ��������
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result[100];  // �洢����·���ĺ�

    // �Ӿ�������Ͻǿ�ʼ�ݹ����·��
    find(m, n, 0, 0, matrix[0][0], matrix, result);

    // �ҳ����·����
    int max = result[0];
    for (int i = 1; i < count; i++) {
        if (max < result[i]) {
            max = result[i];
        }
    }

    printf("%d", max);  // ������·����
    return 0;
}
