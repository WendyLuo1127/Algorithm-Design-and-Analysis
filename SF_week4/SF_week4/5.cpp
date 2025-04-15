#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// �ж��Ƿ���Խ�����ֳ���������ȵ��Ӽ�
bool canPartition(vector<int>& nums) {
    int sum = 0;
    // ��������������Ԫ�ص��ܺ�
    for (int num : nums) {
        sum += num;
    }
    // ����ܺ����������޷��ֳ���������ȵ��Ӽ�
    if (sum % 2 != 0) {
        return false;
    }
    int target = sum / 2;
    int n = nums.size();
    // ����һ����ά�������� dp��dp[i][j] ��ʾǰ i ��Ԫ���Ƿ������ɺ�Ϊ j
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    // ��ʼ����ǰ 0 ��Ԫ�ؿ�����ɺ�Ϊ 0 ���Ӽ�
    dp[0][0] = true;
    // ��̬�滮��� dp ����
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
            // ��ѡ��� i ��Ԫ��
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                // ѡ��� i ��Ԫ��
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
    // �������ַ�������ȡ�������洢��������
    while (iss >> num) {
        nums.push_back(num);
    }
    // ���� canPartition �����ж��Ƿ���Էָ�
    if (canPartition(nums)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}