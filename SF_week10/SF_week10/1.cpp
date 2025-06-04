//997.Find the Town Judge
#include<bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> inDegrees(n + 1, 0);   // ��ȣ�������������
    vector<int> outDegrees(n + 1, 0);  // ���ȣ����ζ�����

    for (const auto& pair : trust) {
        int a = pair[0];  // ���α��˵���
        int b = pair[1];  // �����ε���
        outDegrees[a]++;  // a�����˱��ˣ�����+1
        inDegrees[b]++;   // b�����Σ����+1
    }

    for (int i = 1; i <= n; i++) {
        // ������Ҫ���㣺���Ϊn-1�����������������ҳ���Ϊ0���������κ��ˣ�
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
        while (ss >> num) {  // ���ո�ָ�Ԫ��
            row.push_back(num);
        }
        if (!row.empty()) {  // ���Կ���
            trust.push_back(row);
        }
    }
    cout << findJudge(n, trust);
    return 0;
}
