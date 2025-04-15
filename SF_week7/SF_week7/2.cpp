//��̬�滮
//�����i�����䣬���Ҫô����һ����������dp[i-1]
//Ҫô�����ϸ�������������ڵķ���dp[i-2]+nums[i]

#include<bits/stdc++.h>
using namespace std;

int main() {
	//����
	string line;
	getline(cin, line);
	istringstream iss(line);
	
	vector<int>nums;
	int num;
	while (iss >> num) {
		nums.push_back(num);
	}
	//����
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