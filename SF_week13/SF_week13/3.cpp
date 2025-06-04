//leetcode 357
#include<bits/stdc++.h>
using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1; // 特殊情况：只有数字0
    int count = 9; // 首位有9种选择(1-9)
    for (int i = 1; i < n; i++) {
        count *= (10 - i); // 后续位有9,8,7...种选择
    }
    // 累加所有k位数的结果(k=1到n)
    return count + countNumbersWithUniqueDigits(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << countNumbersWithUniqueDigits(n);
    return 0;
}