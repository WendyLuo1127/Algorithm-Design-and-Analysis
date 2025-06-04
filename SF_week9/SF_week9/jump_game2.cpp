#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int>nums;
	int num;
	while (cin >> num)nums.push_back(num);
	int n = nums.size();
	vector<int>dp(n,-1);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int temp = i + nums[i];
		if (temp >= n)temp = n-1;
		for (int j = i; j <= temp; j++) {
			if (dp[j] < 0 || dp[j] > dp[i] + 1)dp[j] = dp[i] + 1;
		}
		//for (int i = 0; i < n; i++)cout << dp[i] << " ";
		//cout << endl;
	}
	cout << dp[n - 1];
}