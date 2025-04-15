//星海信息序列

#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> memo;// 记忆化存储，记录已经计算过的位置pos对应的S数量

// 获取位置pos对应的层级k，使得2^k - 1 >= pos
long long get_k(long long pos) {
    if (pos == 0) return 0;
    // __builtin_clzll 计算pos在64位表示下前导零的数量，用于确定最高位
    int leading_zeros = __builtin_clzll(pos);
    long long k = 64 - leading_zeros;
    // 检查当前k对应的长度是否满足条件，不满足则k自增
    if ((1LL << k) - 1 < pos) {
        k++;
    }
    return k;
}

// 计算序列前pos个字符中'S'的数量
long long count(long long pos) {
    if (pos == 0) return 0; // 边界条件：没有字符时，S数量为0
    if (memo.count(pos)) return memo[pos]; // 记忆化查询，直接返回已计算结果

    long long k = get_k(pos); // 获取当前位置pos对应的层级k
    long long len_prev = (1LL << (k - 1)) - 1; // S(k-1)的长度，即2^(k-1) - 1

    if (pos <= len_prev) { // pos位于S(k-1)部分
        return memo[pos] = count(pos);
    }
    else if (pos == len_prev + 1) { // pos正好是中间新增的单个'S'
        return memo[pos] = count(len_prev) + 1;
    }
    else { // 处理reverse(flip(S(k-1)))部分
        long long x = pos - (len_prev + 1);
        // 利用序列的对称性质计算当前部分的S数量
        return memo[pos] = 1 + x + count(len_prev - x);
    }
}

int main() {
    ios_base::sync_with_stdio(false); // 关闭同步，优化输入输出效率
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        long long L, R;
        cin >> L >> R;
        // 计算区间[L, R]的S数量：前R个的S数量 - 前L-1个的S数量
        long long ans = count(R) - (L > 1 ? count(L - 1) : 0);
        cout << ans << '\n';
    }
    return 0;
}