//leetcode 357
#include<bits/stdc++.h>
using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1; // ���������ֻ������0
    int count = 9; // ��λ��9��ѡ��(1-9)
    for (int i = 1; i < n; i++) {
        count *= (10 - i); // ����λ��9,8,7...��ѡ��
    }
    // �ۼ�����kλ���Ľ��(k=1��n)
    return count + countNumbersWithUniqueDigits(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << countNumbersWithUniqueDigits(n);
    return 0;
}