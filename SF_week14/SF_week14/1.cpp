#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    vector<int> dp(W + 1, 0);

    // ����ÿ����Ʒ
    for (int i = 0; i < n; i++) {
        // �������������ȷ��ÿ����Ʒֻ������һ��
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[W];
    return 0;
}