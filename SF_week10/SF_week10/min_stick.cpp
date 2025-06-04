#include <bits/stdc++.h>
using namespace std;

int N;                        // С���Ӷ���
vector<int> sticks;           // ���γ���
vector<bool> used;            // ���ĳ���Ƿ��ѷ���
int totalLen;                 // ����С�γ���֮��
int targetLen;                // ��ǰ���Ե�ԭʼ���ӳ��� L
int targetGroups;             // ��Ҫ��ɵĹ����� K

// �ݹ鳢�Խ�С�η��䵽�� groupCnt �飬��ǰ���Ѵճ��� currSum��
// �´ο�ѡ���±�� startIdx ��ʼ
bool dfs(int groupCnt, int currSum, int startIdx) {
    if (groupCnt == targetGroups)
        return true;              // �����鶼�ѳɹ�����

    if (currSum == targetLen) {
        // ������ɣ���ʼ��һ��
        return dfs(groupCnt + 1, 0, 0);
    }

    int prev = -1;  // ��������ͬ���ȵ�С�Σ������ظ�
    for (int i = startIdx; i < N; ++i) {
        if (used[i]
            || currSum + sticks[i] > targetLen
            || sticks[i] == prev)
            continue;
        // ѡ�õ� i ��
        used[i] = true;
        if (dfs(groupCnt, currSum + sticks[i], i + 1))
            return true;
        // ����
        used[i] = false;
        prev = sticks[i];

        // ��֦��������黹���žͷŵ� i ��ʧ�ܣ�
        // �������÷���ʧ�ܣ���˵��������Ҳû����
        if (currSum == 0 || currSum + sticks[i] == targetLen)
            break;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ����
    cin >> N;
    sticks.resize(N);
    totalLen = 0;
    for (int i = 0; i < N; ++i) {
        cin >> sticks[i];
        totalLen += sticks[i];
    }

    // ���򣺽��������ڼ�֦
    sort(sticks.begin(), sticks.end(), greater<int>());
    used.assign(N, false);

    int answer = totalLen;      // ���������ж�����һ��
    // ö�ٿ��ܵ�ԭʼ���ӳ��� L
    for (int L = sticks[0]; L <= totalLen; ++L) {
        if (totalLen % L != 0)
            continue;
        targetLen = L;
        targetGroups = totalLen / L;
        fill(used.begin(), used.end(), false);
        // �ӵ� 0 �顢�� 0 �ο�ʼ����
        if (dfs(0, 0, 0)) {
            answer = L;
            break;
        }
    }

    cout << answer << "\n";
    return 0;
}
