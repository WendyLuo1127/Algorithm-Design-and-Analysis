//Traversal(pass)
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int>nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
	}
	int n = nums.size();
	int max = 0;
	for(int i=0;i<n-1;i++)
		for (int j = i + 1; j < n; j++) {
			int v = min(nums[i], nums[j]) * (j - i);
			if (v > max)max = v;
		}
	cout << max;
	return 0;
}