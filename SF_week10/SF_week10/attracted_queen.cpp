#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> attacked;
int coveredCount = 0;
vector<pair<int, int>> solution;
bool found = false;

// �� pos ת��Ϊ (r,c)
inline pair<int, int> idx2rc(int pos) {
    return { pos / n, pos % n };
}

// ���û���һ���ʺ�delta = +1 ���ã�-1 ����
void updateAttack(int r, int c, int delta) {
    // �������
    if (attacked[r][c] == 0 && delta == +1) coveredCount++;
    attacked[r][c] += delta;
    if (attacked[r][c] == 0 && delta == -1) coveredCount--;

    // �ĸ�������������
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
    // �����Խ���
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

// ���ݣ���һάλ�� start ��ʼ���ѷ� depth ���ʺ�
void dfs(int start, int depth, vector<pair<int, int>>& cur) {
    if (found) return;
    if (depth == k) {
        if (coveredCount == n * n) {
            solution = cur;
            found = true;
        }
        return;
    }

    // ʣ��ɷ�λ�ò��㣬��֦
    if ((n * n - start) < (k - depth)) return;

    for (int pos = start; pos < n * n && !found; ++pos) {
        pair<int, int> rc = idx2rc(pos);
        int r = rc.first;
        int c = rc.second;
        // �Żʺ�
        updateAttack(r, c, +1);
        cur.emplace_back(r, c);

        dfs(pos + 1, depth + 1, cur);

        // ����
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
