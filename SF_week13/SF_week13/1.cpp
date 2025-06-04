//leetcode 79
#include <bits/stdc++.h>
using namespace std;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

// 从 (r,c) 出发，尝试匹配 word[idx...]
bool dfs(const vector<vector<char>>& board,
    vector<vector<bool>>& vis,
    const string& word,
    int idx, int r, int c) {
    if (board[r][c] != word[idx]) return false;
    if (idx + 1 == (int)word.size()) return true;

    vis[r][c] = true;
    int R = board.size(), C = board[0].size();
    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k], nc = c + dc[k];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && !vis[nr][nc]) {
            if (dfs(board, vis, word, idx + 1, nr, nc)) {
                return true;
            }
        }
    }
    vis[r][c] = false;  // 回溯
    return false;
}

// 在整个 board 上找能否拼出 word
bool find_name(const string& word, const vector<vector<char>>& board) {
    int R = board.size();
    if (R == 0) return false;
    int C = board[0].size();
    vector<vector<bool>> vis(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (dfs(board, vis, word, 0, i, j))
                return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // —— 读取 word ——  
    // 假设输入形如 ABCCED（无双引号）
    string line;
    getline(cin, line);
    string word;
    for (char ch : line) {
        if (isalpha(ch))
            word.push_back(ch);
    }

    // —— 读取 board ——  
    // 假设输入形如 [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    getline(cin, line);
    vector<vector<char>> board;
    vector<char> row;
    for (char ch : line) {
        if (isalpha(ch)) {
            row.push_back(ch);
        }
        else if (ch == ']' && !row.empty()) {
            board.push_back(row);
            row.clear();
        }
    }

    // —— 调用并输出结果 ——  
    bool ok = find_name(word, board);
    cout << (ok ? "true" : "false") << "\n";
    return 0;
}
