#include <vector>
#include <iostream>
using namespace std;

vector<int> calculatePower(int n) {
    vector<int> dp(n + 1); // dp[i] ��ʾ i �Ķ������� 1 �ĸ���
    dp[0] = 0; // �߽�����
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = dp[i / 2]; // ż��
        }
        else {
            dp[i] = dp[i / 2] + 1; // ����
        }
    }
    return dp;
}

int main() {
    int n;
    cin >> n; // ���� n
    vector<int> result = calculatePower(n); // ��ȡ���

    // ������
    for (int i = 0; i <= n; i++) {
        cout << result[i] << " ";
    }
    return 0;
}