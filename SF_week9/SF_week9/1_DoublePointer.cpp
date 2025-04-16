//double pointer:the lower one move
//T=O(n);

#include<vector>
#include <iostream>
using namespace std;

int main() {
	vector<int>height;
	int in;
	while (cin >> in)height.push_back(in);
	int left = 0, right = height.size() - 1;
	int MaxWater = 0;
	while (left < right) {
		int cur = min(height[left], height[right]) * (right - left);
		MaxWater = max(cur, MaxWater);
		height[left] > height[right] ? right-- : left++;
	}
	cout << MaxWater;
}