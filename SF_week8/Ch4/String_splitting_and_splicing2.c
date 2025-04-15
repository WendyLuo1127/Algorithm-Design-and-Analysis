#include <stdio.h>

// 定义最大输入长度
#define MAX_LEN 103
#define MAX_PARTS 100  // 允许最多分割的部分

// 手动读取一行输入并处理换行符
void read_line(char str[], int max_len) {
    int i = 0;
    char ch;
    while (i < max_len - 1 && (ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';  // 添加结束符
}

// 手动计算字符串长度
int my_strlen(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// 函数：实现字符串的split操作
void split(char str[], char p, char result[][MAX_LEN], int* size) {
    int idx = 0, res_idx = 0, start = 0;

    while (str[idx] != '\0') {
        if (str[idx] == p) {
            // **[start, idx) 这段内容为一个子串
            if (idx > start) {
                for (int i = start; i < idx; i++) {
                    result[res_idx][i - start] = str[i];
                }
                result[res_idx][idx - start] = '\0';  // 手动添加字符串结束符
            }
            else {
                // 处理连续的分割字符情况，产生空字符串
                result[res_idx][0] = '\0';
            }
            res_idx++;
            start = idx + 1;
        }
        idx++;
    }
    // 处理最后一段
    if (idx > start) {
        for (int i = start; i < idx; i++) {
            result[res_idx][i - start] = str[i];
        }
        result[res_idx][idx - start] = '\0';
    }
    else {
        result[res_idx][0] = '\0';  // 如果最后一个字符是分割符，产生空字符串
    }
    *size = res_idx + 1;
}

// 函数：实现字符串数组的join操作
void join(char result[][MAX_LEN], int size, char join_str[], char output[]) {
    int output_idx = 0;  // 用来追踪output的索引
    int join_len = my_strlen(join_str);  // 手动计算join_str的长度

    for (int i = 0; i < size; i++) {
        // 将当前子串拷贝到output中
        int result_len = my_strlen(result[i]);  // 手动计算当前子串的长度
        for (int j = 0; j < result_len; j++) {
            output[output_idx++] = result[i][j];
        }

        // 如果不是最后一个子串，加入连接字符串
        if (i < size - 1) {
            for (int j = 0; j < join_len; j++) {
                output[output_idx++] = join_str[j];
            }
        }
    }
    output[output_idx] = '\0';  // 终止输出字符串
}

int main() {
    char str[MAX_LEN], p, join_str[MAX_LEN], result[MAX_PARTS][MAX_LEN], output[10000];
    int size = 0;

    // 手动读取输入
    read_line(str, MAX_LEN);   // 读取输入字符串

    p = getchar();  // 读取分割字符
    getchar();  // 跳过空格
    read_line(join_str, MAX_LEN);  // 读取连接字符串

    // 调用split函数
    split(str, p, result, &size);

    // 输出split后的数组
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("\"%s\"", result[i]);
    }
    printf("]\n");

    // 调用join函数并输出结果
    join(result, size, join_str, output);
    printf("%s\n", output);

    return 0;
}
