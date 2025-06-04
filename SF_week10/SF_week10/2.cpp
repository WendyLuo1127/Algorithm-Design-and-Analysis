//207.课程表
// 拓扑排序：邻接表+队列——>将所有先修课程为0的课去除，其后面的课，先修需求数减1
#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // 构建邻接表和入度数组（Kahn算法）
    vector<vector<int>> adj(numCourses);       // 邻接表：存储后续课程
    vector<int> inDegrees(numCourses, 0);      // 入度：每个课程的先修课程数量

    for (const auto& pair : prerequisites) {
        int from = pair[1];  // 先修课程（前置条件）
        int to = pair[0];    // 目标课程（依赖前者）
        adj[from].push_back(to);  // 添加边 from -> to
        inDegrees[to]++;       // 目标课程的入度+1
    }

    // 初始化队列：入度为0的课程（无先修要求）
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegrees[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;  // 记录已完成的课程数
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        count++;

        // 遍历该课程的所有后续课程，减少它们的入度
        for (int next : adj[course]) {
            inDegrees[next]--;
            if (inDegrees[next] == 0) {
                q.push(next);
            }
        }
    }

    return count == numCourses;  // 所有课程都完成则无环，返回true
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