#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int x, y, step;
    Node(int a, int b, int s) : x(a), y(b), step(s) {}
};

int main() {
    int n, sx, sy, ex, ey;
    cin >> n >> sx >> sy >> ex >> ey;

    int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    int dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<Node> q;
    q.push(Node(sx, sy, 0));
    visited[sx][sy] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == ex && cur.y == ey) {
            cout << cur.step << endl;
            return 0;
        }

        for (int i = 0; i < 8; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(Node(nx, ny, cur.step + 1));
            }
        }
    }

    cout << -1 << endl; // 无法到达时输出 -1
    return 0;
}