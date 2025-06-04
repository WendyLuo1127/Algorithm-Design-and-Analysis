#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 8;
vector<int> queens(N); // queens[i] ��ʾ�� i �лʺ���ڵڼ���
int solutionCount = 0;

// �жϵ�ǰλ���Ƿ�Ϸ�
bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || abs(queens[i] - col) == row - i) {
            return false; // ͬ�л�Խ��߳�ͻ
        }
    }
    return true;
}

// ���ݵݹ���ûʺ�
void solve(int row) {
    if (row == N) {
        // �ҵ�һ���⣬��ӡ
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
            queens[row] = col;  // ���Խ��ʺ���� (row, col)
            solve(row + 1);     // �ݹ鴦����һ��
            // ����ʡ�ԣ��´�ѭ���Ḳ�� queens[row]
        }
    }
}

int main() {
    solve(0);
    cout << "Total solutions: " << solutionCount << endl;
    return 0;
}
