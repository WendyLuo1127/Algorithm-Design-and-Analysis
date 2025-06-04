#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 8;
vector<int> queens(N); // queens[i] 表示第 i 行皇后放在第几列
int solutionCount = 0;

// 判断当前位置是否合法
bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || abs(queens[i] - col) == row - i) {
            return false; // 同列或对角线冲突
        }
    }
    return true;
}

// 回溯递归放置皇后
void solve(int row) {
    if (row == N) {
        // 找到一个解，打印
        ++solutionCount;
        cout << "Solution #" << solutionCount << ": ";
        for (int i = 0; i < N; ++i) {
            cout << queens[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col)) {
            queens[row] = col;  // 尝试将皇后放在 (row, col)
            solve(row + 1);     // 递归处理下一行
            // 回溯省略：下次循环会覆盖 queens[row]
        }
    }
}

int main() {
    solve(0);
    cout << "Total solutions: " << solutionCount << endl;
    return 0;
}
