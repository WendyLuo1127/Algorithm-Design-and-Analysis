#include<bits/stdc++.h>
using namespace std;
#define maxNode  1000


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int u, v;
    vector <bool> visited(maxNode, false);
    // ����ֱ�� EOF��ÿ��һ�������
    while (cin >> u >> v) {
        if (visited[u] && visited[v]) {
            cout << u << " " << v;
            return 0;
        }
        visited[u] = visited[v] = true;
    }
}