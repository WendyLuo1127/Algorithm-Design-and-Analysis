//计算所有字符串与目标串的距离是否小于目标次数——>动态规划
#include<bits/stdc++.h>
using namespace std;

// 标准的编辑距离（Levenshtein Distance）DP算法
//插入（dp[i][j-1] + 1）
//删除（dp[i - 1][j] + 1）
//替换（dp[i - 1][j - 1] + 1）
bool edit(string s, string t, int num) {
	int m = s.size(), n = t.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= m; ++i) dp[i][0] = i;
	for (int j = 0; j <= n; ++j) dp[0][j] = j;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
			}
		}
	}
	if (dp[m][n] < n)return true;
	else return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string>s(n);
	for (int i = 0; i < n; i++)cin >> s[i];
	string t;
	int num;
	for (int i=0; i < m; i++){
		cin >> t >> num;
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (edit(s[j], t, num))count++;
			//cout <<i<<":"<<j<<"->" << count <<endl;
		}
		cout << count << endl;
	}
	return 0;
}