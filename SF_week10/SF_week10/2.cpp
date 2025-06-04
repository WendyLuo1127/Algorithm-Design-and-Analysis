//207.�γ̱�
// ���������ڽӱ�+���С���>���������޿γ�Ϊ0�Ŀ�ȥ���������ĿΣ�������������1
#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // �����ڽӱ��������飨Kahn�㷨��
    vector<vector<int>> adj(numCourses);       // �ڽӱ��洢�����γ�
    vector<int> inDegrees(numCourses, 0);      // ��ȣ�ÿ���γ̵����޿γ�����

    for (const auto& pair : prerequisites) {
        int from = pair[1];  // ���޿γ̣�ǰ��������
        int to = pair[0];    // Ŀ��γ̣�����ǰ�ߣ�
        adj[from].push_back(to);  // ��ӱ� from -> to
        inDegrees[to]++;       // Ŀ��γ̵����+1
    }

    // ��ʼ�����У����Ϊ0�Ŀγ̣�������Ҫ��
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegrees[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;  // ��¼����ɵĿγ���
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        count++;

        // �����ÿγ̵����к����γ̣��������ǵ����
        for (int next : adj[course]) {
            inDegrees[next]--;
            if (inDegrees[next] == 0) {
                q.push(next);
            }
        }
    }

    return count == numCourses;  // ���пγ̶�������޻�������true
}

int main() {
    int numCourses;
    cin >> numCourses;
    vector<vector<int>> prerequisites;
    string line;
    while (getline(cin, line)) {
        vector<int> row;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            row.push_back(num);
        }
        if (!row.empty()) {
            prerequisites.push_back(row);
        }
    }
    cout << (canFinish(numCourses, prerequisites) ? "true" : "false");
    return 0;
}