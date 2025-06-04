#include<bits/stdc++.h>
using namespace std;
#define maxNode  1000


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int u, v;
    vector <bool> visited(maxNode, false);
    // 读入直到 EOF，每行一条无向边
    while (cin >> u >> v) {
        if (visited[u] && visited[v]) {
            cout << u << " " << v;
            return 0;
        }
        visited[u] = visited[v] = true;
    }
}