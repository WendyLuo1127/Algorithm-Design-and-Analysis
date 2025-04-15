//动态规划——>假设S的最大子段为s1，如果再增加一个数字num，
// 那么最大子段要么是s1,要么是包括了num的最后一段子段

#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int>num;
	string line;
	getline(cin, line);
	istringstream iss(line);
	int number;
	while (iss >> number) {
		num.push_back(number);//读取数组
	}
	int n = num.size();
	int* dp = (int*)malloc(n * sizeof(int));
	if (dp == NULL) {
		std::cout << "内存分配失败！" << std::endl;
		return 1; // 退出程序或处理错误
	}

	dp[0] = num[0];

	for (int i = 1; i < n; i++) {
		int max = 0;
		int temp = 1;
		for (int j = i; j >= 0; j--) {
			
			if (num[j] != 0)temp *= num[j];//只要不为零就可以尝试
			else break;
			if (temp > max)max = temp;
		}
		if (max > dp[i - 1])dp[i] = max;
		else dp[i] = dp[i - 1];
	}
	//for (int i = 0; i < n; i++)cout << dp[i] << " ";
	//cout << endl;
	cout << dp[n - 1];
	free(dp);
}