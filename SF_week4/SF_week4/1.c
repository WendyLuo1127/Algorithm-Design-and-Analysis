#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxN 1000

int hashtable[MaxN] = { 0 };

// 哈希函数，计算索引
int find_index(int in) {
    return in % MaxN;
}

int main() {
    int in;
    // 循环读取输入，直到遇到换行符
    while (scanf("%d", &in) == 1) {
        int index = find_index(in);
        // 处理哈希冲突，使用线性探测法
        while (hashtable[index] != 0 && hashtable[index] != in) {
            index = (index + 1) % MaxN;
        }
        // 如果该位置为空，标记该编号已出现
        if (hashtable[index] == 0) {
            hashtable[index] = in;
        }
        // 如果该位置已经是该编号，说明找到了重复编号
        else {
            printf("%d", in);
            return 0;
        }
    }
    return 0;
}