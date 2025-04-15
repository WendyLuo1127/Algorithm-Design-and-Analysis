//�Ǻ���Ϣ����

#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> memo;// ���仯�洢����¼�Ѿ��������λ��pos��Ӧ��S����

// ��ȡλ��pos��Ӧ�Ĳ㼶k��ʹ��2^k - 1 >= pos
long long get_k(long long pos) {
    if (pos == 0) return 0;
    // __builtin_clzll ����pos��64λ��ʾ��ǰ���������������ȷ�����λ
    int leading_zeros = __builtin_clzll(pos);
    long long k = 64 - leading_zeros;
    // ��鵱ǰk��Ӧ�ĳ����Ƿ�������������������k����
    if ((1LL << k) - 1 < pos) {
        k++;
    }
    return k;
}

// ��������ǰpos���ַ���'S'������
long long count(long long pos) {
    if (pos == 0) return 0; // �߽�������û���ַ�ʱ��S����Ϊ0
    if (memo.count(pos)) return memo[pos]; // ���仯��ѯ��ֱ�ӷ����Ѽ�����

    long long k = get_k(pos); // ��ȡ��ǰλ��pos��Ӧ�Ĳ㼶k
    long long len_prev = (1LL << (k - 1)) - 1; // S(k-1)�ĳ��ȣ���2^(k-1) - 1

    if (pos <= len_prev) { // posλ��S(k-1)����
        return memo[pos] = count(pos);
    }
    else if (pos == len_prev + 1) { // pos�������м������ĵ���'S'
        return memo[pos] = count(len_prev) + 1;
    }
    else { // ����reverse(flip(S(k-1)))����
        long long x = pos - (len_prev + 1);
        // �������еĶԳ����ʼ��㵱ǰ���ֵ�S����
        return memo[pos] = 1 + x + count(len_prev - x);
    }
}

int main() {
    ios_base::sync_with_stdio(false); // �ر�ͬ�����Ż��������Ч��
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        long long L, R;
        cin >> L >> R;
        // ��������[L, R]��S������ǰR����S���� - ǰL-1����S����
        long long ans = count(R) - (L > 1 ? count(L - 1) : 0);
        cout << ans << '\n';
    }
    return 0;
}