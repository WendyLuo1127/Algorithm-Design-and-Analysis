//�Ч��->��̬�滮

#include<bits/stdc++.h>
using namespace std;

int main() {
	int row;
	cin >> row;
	int dp[100][100] = { 0 };
	dp[1][1] = 1;//��ʼ������
	for(int i=2;i<=row+1;i++)
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i)dp[i][j] = 1;//ÿһ�������߶���1
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];//�ϲ������������
		}
	for (int i = 1; i <= row+1; i++)
		cout << dp[row + 1][i] << " ";
	return 0;
}