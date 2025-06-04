//jump game
#include<iostream>
#include<vector>
using namespace std;



bool CanJump(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n; i++)

		//First step:find 0
		if (nums[i] == 0) {

			//Second step:judge can jump 0 or not
			if (n == 1)return true;  //nums=[0],true
			int j = i - 1;
			if (i == n - 1) {  //last one can be arrived
				while (j >= 0) {
					if (nums[j] >= (i - j))break;
					else j--;
				}
			}
			else  //else should jump
				while (j >= 0) {
					if (nums[j] > (i - j))break;
					else j--;
				}
			if (j < 0)return false;
		}
	return true;
}

int main() {
	vector<int>nums;
	vector<int>zeros;
	int num, index = 0;

	while (cin >> num) {
		nums.push_back(num);
	}
	
	cout << CanJump(nums);
	return 0;
}