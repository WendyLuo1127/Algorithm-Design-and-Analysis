//¶¯Ì¬¹æ»®

#include<bits/stdc++.h>
#define MAX_N 100
using namespace std;

int main() {
	
	int n;
	int dp[MAX_N][MAX_N];
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> dp[i][j];

	for (int i = 1; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)dp[i][j] = dp[i - 1][j] + dp[i][j];
			else if (j == i)dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
			else {
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (dp[n - 1][i] > max)max = dp[n - 1][i];
	}
	cout << max;
	return 0;
} 