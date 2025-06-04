//TSP���������� 
// ������dijistra�㷨
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int n;
vector<vector<int>> dis;
vector<bool> visited;
int res = INT_MAX;

void dfs(int u, int depth, int cost) {
    if (depth == n - 1) { // ��ʣһ������û����
        // �������ߵ����� n-1
        if (!visited[n - 1]) {
            res = min(res, cost + dis[u][n - 1]);
        }
        return;
    }

    for (int v = 0; v < n; v++) {
        if (!visited[v] && v != n - 1) { // ���ߵ� n-1 �������һ��
            visited[v] = true;
            dfs(v, depth + 1, cost + dis[u][v]);
            visited[v] = false;
        }
    }
}

int main() {
    cin >> n;
    dis = vector<vector<int>>(n, vector<int>(n));
    visited = vector<bool>(n, false);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dis[i][j];

    visited[0] = true; // �ӳ��� 0 ����
    dfs(0, 1, 0);

    cout << res << endl;
    return 0;
}
