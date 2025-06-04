//997.Find the Town Judge
#include<bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> inDegrees(n + 1, 0);   // 入度：被多少人信任
    vector<int> outDegrees(n + 1, 0);  // 出度：信任多少人

    for (const auto& pair : trust) {
        int a = pair[0];  // 信任别人的人
        int b = pair[1];  // 被信任的人
        outDegrees[a]++;  // a信任了别人，出度+1
        inDegrees[b]++;   // b被信任，入度+1
    }

    for (int i = 1; i <= n; i++) {
        // 法官需要满足：入度为n-1（所有人信任他）且出度为0（不信任任何人）
        if (inDegrees[i] == n - 1 && outDegrees[i] == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> trust;
    string line;
    while (getline(cin, line)) {
        vector<int> row;
        stringstream ss(line);
        int num;
        while (ss >> num) {  // 按空格分割元素
            row.push_back(num);
        }
        if (!row.empty()) {  // 忽略空行
            trust.push_back(row);
        }
    }
    cout << findJudge(n, trust);
    return 0;
}
