#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<bool>> visited;
vector<pair<int, int>> path;
int dr[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dc[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };
int start_r, start_c;
bool found = false;

inline bool in_bounds(int r, int c) {
    return r >= 0 && r < m && c >= 0 && c < n;
}

int degree(int r, int c) {
    int cnt = 0;
    for (int k = 0; k < 8; ++k) {
        int nr = r + dr[k], nc = c + dc[k];
        if (in_bounds(nr, nc) && !visited[nr][nc])
            cnt++;
    }
    return cnt;
}

void dfs(int r, int c, int step) {
    if (found) return;
    visited[r][c] = true;
    path.emplace_back(r, c);

    if (step == m * n) {
        // Check if can return to start
        for (int k = 0; k < 8; ++k) {
            if (r + dr[k] == start_r && c + dc[k] == start_c) {
                path.emplace_back(start_r, start_c);
                found = true;
                break;
            }
        }
    }
    else {
        // Generate moves and sort by Warnsdorff
        vector<pair<int, pair<int, int>>> moves;
        for (int k = 0; k < 8; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (in_bounds(nr, nc) && !visited[nr][nc]) {
                moves.push_back({ degree(nr, nc), {nr, nc} });
            }
        }
        sort(moves.begin(), moves.end());
        for (auto& mv : moves) {
            if (found) break;
            dfs(mv.second.first, mv.second.second, step + 1);
        }
    }

    if (!found) {
        visited[r][c] = false;
        path.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter board rows m, cols n: ";
    cin >> m >> n;
    cout << "Enter starting row and col (0-based): ";
    cin >> start_r >> start_c;

    visited.assign(m, vector<bool>(n, false));
    path.reserve(m * n + 1);

    dfs(start_r, start_c, 1);

    if (found) {
        cout << "Closed knight's tour found! Path length = " << path.size() << "\n";
        for (auto& p : path) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << "\n";
    }
    else {
        cout << "No closed knight's tour exists from the given start.\n";
    }
    return 0;
}
