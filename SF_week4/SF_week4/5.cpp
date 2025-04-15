#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// 判断是否可以将数组分成两个和相等的子集
bool canPartition(vector<int>& nums) {
    int sum = 0;
    // 计算数组中所有元素的总和
    for (int num : nums) {
        sum += num;
    }
    // 如果总和是奇数，无法分成两个和相等的子集
    if (sum % 2 != 0) {
        return false;
    }
    int target = sum / 2;
    int n = nums.size();
    // 创建一个二维布尔数组 dp，dp[i][j] 表示前 i 个元素是否可以组成和为 j
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    // 初始化：前 0 个元素可以组成和为 0 的子集
    dp[0][0] = true;
    // 动态规划填充 dp 数组
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
            // 不选择第 i 个元素
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                // 选择第 i 个元素
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][target];
}

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<int> nums;
    int num;
    // 从输入字符串中提取整数并存储到数组中
    while (iss >> num) {
        nums.push_back(num);
    }
    // 调用 canPartition 函数判断是否可以分割
    if (canPartition(nums)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}