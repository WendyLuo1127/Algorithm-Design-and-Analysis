#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string line;
	getline(cin, line);
	istringstream iss(line);
	vector<int>nums;
	int num;
	while (iss >> num) {
		nums.push_back(num);
	}
	//Ωµ–Ú≈≈¡–
	sort(nums.begin(), nums.end(), greater<int>());

	long long maxCoins = 0;
	for (int i = 1; i <= n; i++)maxCoins += nums[i * 2 - 1];
	cout << maxCoins;
	return 0;
}

