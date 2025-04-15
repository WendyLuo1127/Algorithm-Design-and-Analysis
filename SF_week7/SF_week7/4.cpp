//动规——>环形不相邻最大物资问题
// 需要分两种情况考虑：1.不考虑最后一个，2.不考虑第一个
// 这样可以避免同时选到第一和最后一个。注意处理只有1个输入的情况
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 输入 (Input)
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> nums;
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }

    // 动归 (Dynamic Programming)
    int n = nums.size();
    if (n == 1) {
        cout << nums[0]; // Special case: only one building
    }
    else {
        vector<int> dp(n);
        vector<int> dp2(n);

        // Case 1: Exclude the last building
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        // Case 2: Exclude the first building
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        for (int i = 3; i < n; i++) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]); // Fixed: dp2 instead of dp
        }

        // Debugging output (optional)
        for (int i = 0; i < n - 1; i++) cout << dp[i] << " ";
        cout << endl;
        for (int i = 1; i < n; i++) cout << dp2[i] << " ";
        cout << endl;

        // Final result
        cout << max(dp[n - 2], dp2[n - 1]);
    }
    return 0;
}