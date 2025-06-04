//leetcode306
#include <bits/stdc++.h>
using namespace std;

// 高精度加法，处理大数字相加
string addStrings(const string& num1, const string& num2) {
    string res;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += (num1[i--] - '0');
        if (j >= 0) sum += (num2[j--] - '0');
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    reverse(res.begin(), res.end());
    return res;
}


// 深度优先搜索验证后续数字是否符合累加序列
bool dfs(const string& num, int start, const string& s1, const string& s2) {
    if (start == num.size()) return true;

    string sum_str = addStrings(s1, s2);
    // 检查当前和是否从start位置开始匹配
    if (num.compare(start, sum_str.size(), sum_str) != 0) return false;

    return dfs(num, start + sum_str.size(), s2, sum_str);
}

bool isAdditiveNumber(string num) {
    int n = num.size();
    // 枚举前两个数的所有可能分割方式
    for (int i = 1; i <= n / 2; ++i) {
        // 避免前导零，除非是单个0
        if (i > 1 && num[0] == '0') break;
        string s1 = num.substr(0, i);

        for (int j = 1; max(i, j) <= n - i - j; ++j) {
            // 避免前导零，除非是单个0
            if (j > 1 && num[i] == '0') break;
            string s2 = num.substr(i, j);

            if (dfs(num, i + j, s1, s2)) return true;
        }
    }
    return false;
}

int main() {
    string line;
    getline(cin, line);
    if (isAdditiveNumber(line))cout << "true";
    else cout << "false";
    return 0;
}