// ������� 
// ��������С����

#include <iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

// �� (x,y) ���뵽һ�� 64 λ����
inline ll code(int x, int y) {
    return (ll(x) << 32) ^ (unsigned long long)(y);
}

// ���еĺ��ӺͰ��Ӽ��ϣ������
unordered_set<ll> blackSet, whiteSet;

// �˸�����һһ���ֻ���ĸ�
const int dx[4] = { 1, 0, 1, 1 };
const int dy[4] = { 0, 1, 1, -1 };

// ����ڼ��� S �У�������� (x,y) ������ӣ��Ƿ��Ѿ����� 5 ��
bool checkWin(int x, int y, const unordered_set<ll>& S) {
    for (int dir = 0; dir < 4; ++dir) {
        int cnt = 1;
        // ������
        for (int step = 1; step < 5; ++step) {
            ll c = code(x + step * dx[dir], y + step * dy[dir]);
            if (!S.count(c)) break;
            ++cnt;
        }
        // ������
        for (int step = 1; step < 5; ++step) {
            ll c = code(x - step * dx[dir], y - step * dy[dir]);
            if (!S.count(c)) break;
            ++cnt;
        }
        if (cnt >= 5) return true;
    }
    return false;
}

// �������к�ѡ���ӵ㣺
// ��ÿ����������Χ ��2 ��Χ�ڵĿյ�����Ѽ�
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

// minimax ������
// ����ֵ��1 = �ڷ���ʤ��-1 = �׷���ʤ��0 = ���������˱�ʤ
int dfs(int depth, bool blackTurn) {
    if (depth == 0) return 0;
    auto cands = genCandidates();
    if (blackTurn) {
        int best = -2;  // ����裺�ڷ�����
        for (auto& p : cands) {
            int x = p.first, y = p.second;
            ll cd = code(x, y);
            blackSet.insert(cd);
            int cur;
            if (checkWin(x, y, blackSet)) {
                cur = 1;  // ������� 5 ������ʤ
            }
            else {
                cur = dfs(depth - 1, false);
            }
            blackSet.erase(cd);
            best = max(best, cur);
            if (best == 1) break; // �ҵ���ʤ�����̼�֦
        }
        return best;
    }
    else {
        int best = 2;   // ����裺�׷����� => �ڷ���ʤ
        for (auto& p : cands) {
            int x = p.first, y = p.second;
            ll cd = code(x, y);
            whiteSet.insert(cd);
            int cur;
            if (checkWin(x, y, whiteSet)) {
                cur = -1; // ������� 5 ������ʤ
            }
            else {
                cur = dfs(depth - 1, true);
            }
            whiteSet.erase(cd);
            best = min(best, cur);
            if (best == -1) break; // �׷���ʤ�ķ�֧����֦
        }
        return best;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ���� pieces��ֱ�� EOF
    int x, y, c;
    while ((cin >> x >> y >> c)) {
        ll cd = code(x, y);
        if (c == 0) blackSet.insert(cd);
        else         whiteSet.insert(cd);
    }

    // �Ӻ��忪ʼ���������Ϊ 3���ڡ��ס��ڣ�
    int res = dfs(3, true);
    if (res == 1)  cout << "Black\n";
    else if (res == -1) cout << "White\n";
    else                cout << "None\n";
    return 0;
}