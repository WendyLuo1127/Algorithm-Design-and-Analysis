//��������,��Ʒ�����ظ�

#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    int dp[1001] = { 0 }; // dp[j] ��ʾ��������Ϊ j ʱ�����ս����

    for (int i = 0; i < N; ++i) {
        int vi, wi;
        cin >> vi >> wi;
        // ������������ظ�ʹ��ͬһ��Ʒ
        for (int j = V; j >= vi; --j) {
            dp[j] = max(dp[j], dp[j - vi] + wi);
        }
    }
    cout << dp[V] << endl;
    return 0;
}