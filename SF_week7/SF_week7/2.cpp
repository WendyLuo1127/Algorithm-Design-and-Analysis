//动态规划
//加入第i个房间，金额要么是上一个房间的最大dp[i-1]
//要么是上上个房间的最大加现在的房间dp[i-2]+nums[i]

#include<bits/stdc++.h>
using namespace std;

int main() {
	//输入
	string line;
	getline(cin, line);
	istringstream iss(line);
	
	vector<int>nums;
	int num;
	while (iss >> num) {
		nums.push_back(num);
	}
	//动归
	int n = nums.size();
	vector<int>dp(n);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}

	//for (int i = 0; i < n; i++)cout << dp[i] << " ";
	//cout << endl;

	cout << dp[n - 1];
	return 0;
}