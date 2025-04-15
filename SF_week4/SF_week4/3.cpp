#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// �������������͵ĺ���
int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int maxSum = nums[0];
    int currentSum = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    string line;
    vector<int> nums;
    // ��ȡ��������
    getline(cin, line);

    istringstream iss(line);
    int num;
    // ���������н�������������
    while (iss >> num) {
        nums.push_back(num);
    }

    if (!nums.empty()) {
        // ���㲢�������������
        cout <<  maxSubArray(nums) << endl;
    }
    else {
        cout << "û��������Ч������Ԫ�ء�" << endl;
    }

    return 0;
}