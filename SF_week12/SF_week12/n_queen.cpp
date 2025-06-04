#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct QueenNode {
    int row;
    vector<int> cols;
    bool operator>(const QueenNode& other) const {
        return row > other.row;
    }
};

bool isSafe(const vector<int>& cols, int newCol) {
    int row = cols.size();
    for (int i = 0; i < row; ++i) {
        if (cols[i] == newCol || abs(row - i) == abs(newCol - cols[i])) {
            return false;
        }
    }
    return true;
}

vector<vector<int>> nQueenBB(int n) {
    vector<vector<int>> solutions;
    priority_queue<QueenNode, vector<QueenNode>, greater<QueenNode>> pq;
    pq.push({ 0, {} });

    while (!pq.empty()) {
        QueenNode node = pq.top();
        pq.pop();

        if (node.row == n) {
            solutions.push_back(node.cols);
            continue;
        }

        for (int j = 0; j < n; ++j) {
            if (isSafe(node.cols, j)) {
                vector<int> newCols = node.cols;
                newCols.push_back(j);
                pq.push({ node.row + 1, newCols });
            }
        }
    }

    return solutions;
}

int main() {
    int n = 8;
    vector<vector<int>> solutions = nQueenBB(n);
    cout << "ÕÒµ½ " << solutions.size() << " ¸ö½â¡£" << endl;
    for (const auto& sol : solutions) {
        for (int col : sol) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}