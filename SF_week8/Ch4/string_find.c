#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXS 30

char* search(char* s, char* t);
void ReadString(char s[]); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], * pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if (pos != NULL)
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
char* search(char* s, char* t)
{
    int i = 0, j = 0, k;
    for (i = 0; s[i] != '\0'; i++)
    {
        k = i;
        j = 0;//每次比较都从t所指的第一个开始比较
        while (s[k] == t[j] && s[k] != '\0' && t[j] != '\0')
            //判断时要考虑两个是否为\0，如果有一个是则跳出
        {
            k++;
            j++;
        }
        if (j != 0 && t[j] == '\0')
            break;
    }
    if (s[i] != '\0')
    {
        s = i + s;      //注意先比较再加，否则可能会数组越值
        return s;
    }
    return NULL;
}
