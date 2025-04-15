#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct People {
	int ID;
	char gender;
	int F_ID, M_ID;
}People;

// 使用递归/循环获取五代以内的祖先
void getAncestors(int id, People* P, int* ancestors, int* count, int depth) {
    if (depth >= 5 || id == -1 || *count >= 32) return;  // 达到五代或无父母信息或超过数组容量，停止递归

    // 检查是否已经在祖先列表中
    for (int i = 0; i < *count; i++) {
        if (ancestors[i] == id) return;  // 避免重复添加
    }
    ancestors[(*count)++] = id;

    // 查找当前ID对应的人员并递归查找父母
    for (int i = 0; P[i].ID != -1; i++) {
        if (P[i].ID == id) {
            getAncestors(P[i].F_ID, P, ancestors, count, depth + 1);
            getAncestors(P[i].M_ID, P, ancestors, count, depth + 1);
            break;
        }
    }
}

// 判断两个人是否可以通婚
void judge(int ID1, int ID2, People* P, int N) {
    int i = -1, j = -1;

    // 找到ID1和ID2在数组中的位置
    for (int index = 0; index < N; index++) {
        if (P[index].ID == ID1) i = index;
        if (P[index].ID == ID2) j = index;
    }

    // 如果找不到其中一人，直接返回
    if (i == -1 || j == -1) {
        printf("Invalid IDs\n");
        return;
    }

    // 性别相同，直接输出 Never Mind
    if (P[i].gender == P[j].gender) {
        printf("Never Mind\n");
        return;
    }

    // 获取ID1和ID2的五代祖先
    int ancestors1[32] = { 0 }, ancestors2[32] = { 0 };
    int count1 = 0, count2 = 0;

    getAncestors(ID1, P, ancestors1, &count1, 0);
    getAncestors(ID2, P, ancestors2, &count2, 0);

    // 判断是否有共同祖先
    for (int k = 0; k < count1; k++) {
        for (int l = 0; l < count2; l++) {
            if (ancestors1[k] == ancestors2[l]) {
                printf("No\n");
                return;
            }
        }
    }

    // 没有共同祖先，输出 Yes
    printf("Yes\n");
}

int main() {
    int N, K;
    scanf("%d", &N);

    People* P = (People*)malloc((N + 1) * sizeof(People));
    for (int i = 0; i < N; i++) {
        scanf("%d %c %d %d", &P[i].ID, &P[i].gender, &P[i].F_ID, &P[i].M_ID);
    }
    P[N].ID = -1;  // 标记数组结尾

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int people1, people2;
        scanf("%d %d", &people1, &people2);
        judge(people1, people2, P, N);
    }

    free(P);
    return 0;
}
