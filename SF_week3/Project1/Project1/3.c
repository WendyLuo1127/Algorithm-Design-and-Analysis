#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> memo;//记忆

//找出pos属于S(k)
long long get_k(long long pos) {
    if (pos == 0) return 0;
    int leading_zeros = __builtin_clzll(pos);
    long long k = 64 - leading_zeros;
    if ((1LL << k) - 1 < pos) {
        k++;
    }
    return k;
}

//返回S(K)的前pos位中有多少个s
long long count(long long pos) {
    if (pos == 0) return 0;
    if (memo.count(pos)) return memo[pos];
    long long k = get_k(pos);
    long long len_prev = (1LL << (k - 1)) - 1;
    if (pos <= len_prev) {
        return memo[pos] = count(pos);
    }
    else if (pos == len_prev + 1) {
        return memo[pos] = count(len_prev) + 1;
    }
    else {
        long long x = pos - (len_prev + 1);
        return memo[pos] = 1 + x + count(len_prev - x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    // 多组区间询问
    while (T--) {
        long long L, R;
        cin >> L >> R;
        long long ans = count(R) - (L > 1 ? count(L - 1) : 0);
        cout << ans << '\n';
    }
    return 0;
}