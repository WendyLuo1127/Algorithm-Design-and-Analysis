#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//时间复杂度：O(n)，因为只需要对数组进行一次遍历，n 为数组的长度。
// 空间复杂度：O(1)，只使用了常数级的额外变量来存储中间结果，不随数组长度的增加而增加额外的存储空间。

int main() {
    int n;
    // 读取符文数组的长度
    scanf("%d", &n);

    int candidate;
    int count = 0;
    int num;

    for (int i = 0; i < n; i++) {
        // 读取符文数组中的每个元素
        scanf("%d", &num);
        if (count == 0) {
            // 如果计数器为 0，将当前元素设为候选元素
            candidate = num;
            count = 1;
        }
        else if (num == candidate) {
            // 如果当前元素等于候选元素，计数器加 1
            count++;
        }
        else {
            // 如果当前元素不等于候选元素，计数器减 1
            count--;
        }
    }

    // 输出候选元素，即出现次数超过一半的元素
    printf("%d\n", candidate);

    return 0;
}