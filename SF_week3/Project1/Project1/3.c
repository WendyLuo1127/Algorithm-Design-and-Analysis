#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 计算 S(n) 的长度，即 2^(n+1) - 1
long long get_length(long long n) {
    return (1LL << (n + 1)) - 1;
}

// 获取 S(n) 中位置 pos 的字符
char get_char(long long n, long long pos) {
    if (n == 0) {
        return 'S'; // S(0) 只包含一个 S
    }

    long long len = get_length(n); // S(n) 的长度
    long long mid = len / 2 + 1;   // S(n) 的中间位置

    if (pos <= mid - 1) {
        return get_char(n - 1, pos);  // 在 S(n-1) 的左半部分
    }
    else if (pos == mid) {
        return 'S';  // 中间的 S
    }
    else {
        long long right_pos = len - pos + 1;  // 计算在反转的右半部分的对应位置
        return (get_char(n - 1, right_pos) == 'S') ? 'D' : 'S';  // 反转后的右半部分
    }
}

// 计算区间 [L, R] 内的 'S' 数量
long long count_S(long long n, long long L, long long R) {
    long long count = 0;
    for (long long i = L; i <= R; i++) {
        if (get_char(n, i) == 'S') {
            count++;
        }
    }
    return count;
}

// 查找最大的 n，使得 S(n) 的长度大于等于 R
long long find_n(long long R) {
    long long low = 0, high = 60, best = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (get_length(mid) >= R) {
            best = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return best;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        long long L, R;
        scanf("%lld %lld", &L, &R);

        long long n = find_n(R); // 找到最大的 n，使得 S(n) 的长度大于等于 R
        printf("%lld\n", count_S(n, L, R)); // 输出区间 [L, R] 中的 S 的数量
    }

    return 0;
}
