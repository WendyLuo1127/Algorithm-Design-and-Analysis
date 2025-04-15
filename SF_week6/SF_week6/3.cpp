//����ʻ�->��̬�滮
//dp[i] -> s��ǰi���ַ��ܷ�ƴ��

#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true; // ���ַ�����ƴ��

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordSet.count(s.substr(j, i - j)) > 0) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    string s ;
    vector<string> wordDict ;
    cin >> s;
    int i = 0;
    string word;
    while ((cin >> word) ) {
        if (word == "\n")break;
        wordDict.push_back(word);
    }
    cout << (wordBreak(s, wordDict) ? "true" : "false") << endl;
    return 0;
}