#include <bits/stdc++.h>
using namespace std;

int N;                        // 小棍子段数
vector<int> sticks;           // 各段长度
vector<bool> used;            // 标记某段是否已分配
int totalLen;                 // 所有小段长度之和
int targetLen;                // 当前尝试的原始棍子长度 L
int targetGroups;             // 需要组成的棍子数 K

// 递归尝试将小段分配到第 groupCnt 组，当前组已凑长度 currSum，
// 下次可选段下标从 startIdx 开始
bool dfs(int groupCnt, int currSum, int startIdx) {
    if (groupCnt == targetGroups)
        return true;              // 所有组都已成功凑齐

    if (currSum == targetLen) {
        // 本组完成，开始下一组
        return dfs(groupCnt + 1, 0, 0);
    }

    int prev = -1;  // 用于跳过同长度的小段，避免重复
    for (int i = startIdx; i < N; ++i) {
        if (used[i]
            || currSum + sticks[i] > targetLen
            || sticks[i] == prev)
            continue;
        // 选用第 i 段
        used[i] = true;
        if (dfs(groupCnt, currSum + sticks[i], i + 1))
            return true;
        // 回溯
        used[i] = false;
        prev = sticks[i];

        // 剪枝：如果本组还空着就放第 i 段失败，
        // 或者正好放满失败，都说明后面试也没意义
        if (currSum == 0 || currSum + sticks[i] == targetLen)
            break;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读入
    cin >> N;
    sticks.resize(N);
    totalLen = 0;
    for (int i = 0; i < N; ++i) {
        cin >> sticks[i];
        totalLen += sticks[i];
    }

    // 排序：降序，有助于剪枝
    sort(sticks.begin(), sticks.end(), greater<int>());
    used.assign(N, false);

    int answer = totalLen;      // 最坏情况：所有段连成一根
    // 枚举可能的原始棍子长度 L
    for (int L = sticks[0]; L <= totalLen; ++L) {
        if (totalLen % L != 0)
            continue;
        targetLen = L;
        targetGroups = totalLen / L;
        fill(used.begin(), used.end(), false);
        // 从第 0 组、第 0 段开始尝试
        if (dfs(0, 0, 0)) {
            answer = L;
            break;
        }
    }

    cout << answer << "\n";
    return 0;
}
