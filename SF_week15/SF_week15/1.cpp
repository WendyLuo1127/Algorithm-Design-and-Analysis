// 无线棋局 
// 三步极大极小博弈

#include <iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

// 将 (x,y) 编码到一个 64 位整数
inline ll code(int x, int y) {
    return (ll(x) << 32) ^ (unsigned long long)(y);
}

// 已有的黑子和白子集合（编码后）
unordered_set<ll> blackSet, whiteSet;

// 八个方向，一一配对只需四个
const int dx[4] = { 1, 0, 1, 1 };
const int dy[4] = { 0, 1, 1, -1 };

// 检查在集合 S 中，最近落在 (x,y) 的这颗子，是否已经连成 5 子
bool checkWin(int x, int y, const unordered_set<ll>& S) {
    for (int dir = 0; dir < 4; ++dir) {
        int cnt = 1;
        // 正方向
        for (int step = 1; step < 5; ++step) {
            ll c = code(x + step * dx[dir], y + step * dy[dir]);
            if (!S.count(c)) break;
            ++cnt;
        }
        // 反方向
        for (int step = 1; step < 5; ++step) {
            ll c = code(x - step * dx[dir], y - step * dy[dir]);
            if (!S.count(c)) break;
            ++cnt;
        }
        if (cnt >= 5) return true;
    }
    return false;
}

// 生成所有候选落子点：
// 对每颗已落子周围 ±2 范围内的空点进行搜集
vector<pair<int, int> > genCandidates() {
    unordered_set<ll> vis;
    vector<pair<int, int> > cand;
    auto tryAdd = [&](int x, int y) {
        ll c = code(x, y);
        if (blackSet.count(c) || whiteSet.count(c) || vis.count(c)) return;
        vis.insert(c);
        cand.emplace_back(x, y);
        };
    for (auto& c : blackSet) {
        int x = int(c >> 32), y = int(c & 0xffffffff);
        for (int dx = -2; dx <= 2; ++dx)
            for (int dy = -2; dy <= 2; ++dy)
                if (dx || dy) tryAdd(x + dx, y + dy);
    }
    for (auto& c : whiteSet) {
        int x = int(c >> 32), y = int(c & 0xffffffff);
        for (int dx = -2; dx <= 2; ++dx)
            for (int dy = -2; dy <= 2; ++dy)
                if (dx || dy) tryAdd(x + dx, y + dy);
    }
    return cand;
}

// minimax 搜索：
// 返回值：1 = 黑方必胜，-1 = 白方必胜，0 = 三步内无人必胜
int dfs(int depth, bool blackTurn) {
    if (depth == 0) return 0;
    auto cands = genCandidates();
    if (blackTurn) {
        int best = -2;  // 最坏假设：黑方必输
        for (auto& p : cands) {
            int x = p.first, y = p.second;
            ll cd = code(x, y);
            blackSet.insert(cd);
            int cur;
            if (checkWin(x, y, blackSet)) {
                cur = 1;  // 黑棋落成 5 连，黑胜
            }
            else {
                cur = dfs(depth - 1, false);
            }
            blackSet.erase(cd);
            best = max(best, cur);
            if (best == 1) break; // 找到必胜，立刻剪枝
        }
        return best;
    }
    else {
        int best = 2;   // 最坏假设：白方必输 => 黑方必胜
        for (auto& p : cands) {
            int x = p.first, y = p.second;
            ll cd = code(x, y);
            whiteSet.insert(cd);
            int cur;
            if (checkWin(x, y, whiteSet)) {
                cur = -1; // 白棋落成 5 连，白胜
            }
            else {
                cur = dfs(depth - 1, true);
            }
            whiteSet.erase(cd);
            best = min(best, cur);
            if (best == -1) break; // 白方必胜的分支，剪枝
        }
        return best;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读入 pieces，直到 EOF
    int x, y, c;
    while ((cin >> x >> y >> c)) {
        ll cd = code(x, y);
        if (c == 0) blackSet.insert(cd);
        else         whiteSet.insert(cd);
    }

    // 从黑棋开始，深度设置为 3（黑→白→黑）
    int res = dfs(3, true);
    if (res == 1)  cout << "Black\n";
    else if (res == -1) cout << "White\n";
    else                cout << "None\n";
    return 0;
}