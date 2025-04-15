//羁绊效果->动态规划

#include<bits/stdc++.h>
using namespace std;

int main() {
	int row;
	cin >> row;
	int dp[100][100] = { 0 };
	dp[1][1] = 1;//初始化塔尖
	for(int i=2;i<=row+1;i++)
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i)dp[i][j] = 1;//每一层最两边都是1
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];//上层左右两个相加
		}
	for (int i = 1; i <= row+1; i++)
		cout << dp[row + 1][i] << " ";
	return 0;
}