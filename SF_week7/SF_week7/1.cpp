//��̬�滮����>����S������Ӷ�Ϊs1�����������һ������num��
// ��ô����Ӷ�Ҫô��s1,Ҫô�ǰ�����num�����һ���Ӷ�

#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int>num;
	string line;
	getline(cin, line);
	istringstream iss(line);
	int number;
	while (iss >> number) {
		num.push_back(number);//��ȡ����
	}
	int n = num.size();
	int* dp = (int*)malloc(n * sizeof(int));
	if (dp == NULL) {
		std::cout << "�ڴ����ʧ�ܣ�" << std::endl;
		return 1; // �˳�����������
	}

	dp[0] = num[0];

	for (int i = 1; i < n; i++) {
		int max = 0;
		int temp = 1;
		for (int j = i; j >= 0; j--) {
			
			if (num[j] != 0)temp *= num[j];//ֻҪ��Ϊ��Ϳ��Գ���
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