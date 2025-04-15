#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���� S(n) �ĳ��ȣ��� 2^(n+1) - 1
long long get_length(long long n) {
    return (1LL << (n + 1)) - 1;
}

// ��ȡ S(n) ��λ�� pos ���ַ�
char get_char(long long n, long long pos) {
    if (n == 0) {
        return 'S'; // S(0) ֻ����һ�� S
    }

    long long len = get_length(n); // S(n) �ĳ���
    long long mid = len / 2 + 1;   // S(n) ���м�λ��

    if (pos <= mid - 1) {
        return get_char(n - 1, pos);  // �� S(n-1) ����벿��
    }
    else if (pos == mid) {
        return 'S';  // �м�� S
    }
    else {
        long long right_pos = len - pos + 1;  // �����ڷ�ת���Ұ벿�ֵĶ�Ӧλ��
        return (get_char(n - 1, right_pos) == 'S') ? 'D' : 'S';  // ��ת����Ұ벿��
    }
}

// �������� [L, R] �ڵ� 'S' ����
long long count_S(long long n, long long L, long long R) {
    long long count = 0;
    for (long long i = L; i <= R; i++) {
        if (get_char(n, i) == 'S') {
            count++;
        }
    }
    return count;
}

// �������� n��ʹ�� S(n) �ĳ��ȴ��ڵ��� R
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

        long long n = find_n(R); // �ҵ����� n��ʹ�� S(n) �ĳ��ȴ��ڵ��� R
        printf("%lld\n", count_S(n, L, R)); // ������� [L, R] �е� S ������
    }

    return 0;
}
