#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> attacked;
int coveredCount = 0;
vector<pair<int, int>> solution;
bool found = false;

// 将 pos 转换为 (r,c)
inline pair<int, int> idx2rc(int pos) {
    return { pos / n, pos % n };
}

// 放置或撤销一个皇后，delta = +1 放置，-1 撤销
void updateAttack(int r, int c, int delta) {
    // 自身格子
    if (attacked[r][c] == 0 && delta == +1) coveredCount++;
    attacked[r][c] += delta;
    if (attacked[r][c] == 0 && delta == -1) coveredCount--;

    // 四个方向：上下左右
    for (int dr = -1; dr <= 1; dr += 2) {
        for (int step = 1; ; ++step) {
            int rr = r + dr * step;
            if (rr < 0 || rr >= n) break;
            if (attacked[rr][c] == 0 && delta == +1) coveredCount++;
            attacked[rr][c] += delta;
            if (attacked[rr][c] == 0 && delta == -1) coveredCount--;
        }
        for (int step = 1; ; ++step) {
            int cc = c + dr * step;
            if (cc < 0 || cc >= n) break;
            if (attacked[r][cc] == 0 && delta == +1) coveredCount++;
            attacked[r][cc] += delta;
            if (attacked[r][cc] == 0 && delta == -1) coveredCount--;
        }
    }
    // 两条对角线
    for (int dr : {-1, +1}) {
        for (int dc : {-1, +1}) {
            for (int step = 1; ; ++step) {
                int rr = r + dr * step, cc = c + dc * step;
                if (rr < 0 || rr >= n || cc < 0 || cc >= n) break;
                if (attacked[rr][cc] == 0 && delta == +1) coveredCount++;
                attacked[rr][cc] += delta;
                if (attacked[rr][cc] == 0 && delta == -1) coveredCount--;
            }
        }
    }
}

// 回溯：从一维位置 start 开始，已放 depth 个皇后
void dfs(int start, int depth, vector<pair<int, int>>& cur) {
    if (found) return;
    if (depth == k) {
        if (coveredCount == n * n) {
            solution = cur;
            found = true;
        }
        return;
    }

    // 剩余可放位置不足，剪枝
    if ((n * n - start) < (k - depth)) return;

    for (int pos = start; pos < n * n && !found; ++pos) {
        pair<int, int> rc = idx2rc(pos);
        int r = rc.first;
        int c = rc.second;
        // 放皇后
        updateAttack(r, c, +1);
        cur.emplace_back(r, c);

        dfs(pos + 1, depth + 1, cur);

        // 撤销
        cur.pop_back();
        updateAttack(r, c, -1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter board size n and number of queens k: ";
    cin >> n >> k;

    attacked.assign(n, vector<int>(n, 0));
    vector<pair<int, int>> cur;
    dfs(0, 0, cur);

    if (found) {
        cout << "Found a placement covering all squares:\n";
        for (auto& p : solution) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << "\n";
    }
    else {
        cout << "No such placement exists for n=" << n
            << ", k=" << k << "\n";
    }
    return 0;
}
