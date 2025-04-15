//最长的回文子串

#include<bits/stdc++.h>
using namespace std;

int expand(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; ++i) {
        // 处理奇数长度回文
        int len1 = expand(s, i, i);
        // 处理偶数长度回文
        int len2 = expand(s, i, i + 1);
        int curMax = max(len1, len2);
        if (curMax > maxLen) {
            maxLen = curMax;
            start = i - (curMax - 1) / 2;
        }
    }
    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}