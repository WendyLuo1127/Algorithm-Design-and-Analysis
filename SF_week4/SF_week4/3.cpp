#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// 计算最大子数组和的函数
int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int maxSum = nums[0];
    int currentSum = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        // 如果当前和变小了（如加了一个负数），就要从当前位置重新开始，否则继续
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    string line;
    vector<int> nums;
    // 读取整行输入
    getline(cin, line);

    istringstream iss(line);
    int num;
    // 从输入行中解析出各个整数
    while (iss >> num) {
        nums.push_back(num);
    }

    if (!nums.empty()) {
        // 计算并输出最大子数组和
        cout <<  maxSubArray(nums) << endl;
    }
    else {
        cout << "没有输入有效的数组元素。" << endl;
    }

    return 0;
}