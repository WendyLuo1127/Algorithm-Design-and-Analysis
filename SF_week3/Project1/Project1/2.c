#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//使用归并排序的思想来优化这个问题，在归并排序的合并过程中统计逆序对的数量，逆序对的数量就是我们要找的正确排名的总数
// 其时间复杂度可以优化到 O(n log n)。

// 合并两个有序子数组并统计逆序对数量
long long merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    if (L == NULL || R == NULL) {
        // 内存分配失败
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // 复制数据到临时数组 L[] 和 R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long inv_count = 0;

    // 归并临时数组到 arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            // 如果 L[i] > R[j]，则 L[i...n1-1] 都与 R[j] 构成逆序对
            inv_count += (n1 - i);
            j++;
        }
        k++;
    }

    // 复制 L[] 的剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 复制 R[] 的剩余元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
    return inv_count;
}

// 归并排序并统计逆序对数量
long long mergeSort(int arr[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 递归排序左半部分
        inv_count += mergeSort(arr, left, mid);
        // 递归排序右半部分
        inv_count += mergeSort(arr, mid + 1, right);

        // 合并两个有序子数组并统计逆序对
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}

int main() {
    int n;
    // 读取英雄的个数
    scanf("%d", &n);

    int powers[100000];
    // 读取每个英雄的战斗力
    for (int i = 0; i < n; i++) {
        scanf("%d", &powers[i]);
    }

    // 调用归并排序函数统计逆序对数量
    long long correct_rankings = mergeSort(powers, 0, n - 1);

    // 输出正确排名的总数
    printf("%lld\n", correct_rankings);

    return 0;
}