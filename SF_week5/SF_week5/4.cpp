//最长严格递增长度——>动态规划
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>num(n);
	vector<int>dp(n, 1);
	for (int i = 0; i < n; i++)cin >> num[i];
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1];
		for (int j = 0; j < i; j++) {
					if (num[j] < num[i])dp[i] = max(dp[i], dp[j] + 1);
				}
	}
	/*
	for (int i = 0; i < n; i++)cout << dp[i] << " ";
	cout << endl;
	*/
	cout << dp[n-1];
	return 0;
}