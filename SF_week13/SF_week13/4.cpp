//leetcode 773
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int slidingPuzzle(vector<vector<int>>& board) {
    string start, target = "123450";
    for (auto& row : board) for (int x : row) start += char('0' + x);

    // ÿ��λ�ã�0��5����ո�ɽ�����λ��
    vector<vector<int>> moves = {
        {1,3}, {0,2,4}, {1,5},
        {0,4}, {1,3,5}, {2,4}
    };

    queue<string> q;//BFS����
    unordered_map<string, int> dist;//��ϣ��
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        string cur = q.front(); q.pop();
        if (cur == target) return dist[cur];//�ҵ�

        int z = cur.find('0');//��0�˿̵�λ�ÿ�ʼ
        for (int m : moves[z]) {//bfs�������п����ƶ���λ��
            string nxt = cur;
            swap(nxt[z], nxt[m]);
            if (!dist.count(nxt)) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    return -1;//����δ�ҵ�
}

int main() {
    string line;
    getline(cin, line);
    vector<vector<int>> board(2, vector<int>(3));
    int i = 0;
    for (char c : line) if (isdigit(c)) {
        board[i / 3][i % 3] = c - '0';
        i++;
        if (i == 6) break;
    }
    cout << slidingPuzzle(board) << "\n";
    return 0;
}
