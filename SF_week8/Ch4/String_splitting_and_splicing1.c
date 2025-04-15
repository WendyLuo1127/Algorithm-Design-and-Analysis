#include <stdio.h>
#include <string.h>

int main() {
    char in[1010]="\0",split, join[1000]="\0";
    gets(in);   
    split = getchar();           // 分割字符
    getchar();// 提取连接字符串，跳过分割字符和空格
    gets(join);

    int len = strlen(in);      // 原始字符串的长度
    int join_len = strlen(join); // 连接字符串的长度

    // 1. 处理 split 分割
    printf("[");
    int start = 0;   // 用来标记每一段子串的起始
    int first_part = 1;  // 标记是否是第一个子串
    for (int i = 0; i <= len; i++) {  // 注意 i <= len, 用于处理最后一部分
        if (in[i] == split || i == len) {
            // 如果遇到分割字符或者到达字符串末尾
            if (!first_part) {
                printf(", ");
            }
            printf("\"");
            for (int j = start; j < i; j++) {
                printf("%c", in[j]);
            }
            printf("\"");
            first_part = 0;  // 第一个子串结束
            start = i + 1;   // 下一个子串的起始位置
        }
    }
    printf("]\n");

    // 2. 处理 join 连接
    start = 0;
    first_part = 1;
    for (int i = 0; i <= len; i++) {
        if (in[i] == split || i == len) {
            // 处理每个子串
            if (!first_part) {
                printf("%s", join);  // 插入连接字符串
            }
            for (int j = start; j < i; j++) {
                printf("%c", in[j]);
            }
            first_part = 0;  // 第一个子串结束
            start = i + 1;   // 下一个子串的起始位置
        }
    }
    printf("\n");

    return 0;
}
