//洛谷 P1120 小木棍

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>l;//木棒长度
vector<bool>usd;//是否使用过
int sum = 0;
int maxL = 0;
int n;

//stickCount: 还需拼多少根完整木棍
// currLen: 当前木棍已拼的长度
// idx : 搜索起始位置，避免重复组合
// target : 每根木棍目标长度 = L
bool dfs(int stickCount, int currLen, int idx, int target) {
    if (stickCount == 0) {
        cout << "[成功] 所有木棍已拼完\n";
        return true;
    }
    if (currLen == target) {
        cout << "[拼满] 当前一根拼满，开始下一根。剩余: " << stickCount - 1 << " 根\n";
        return dfs(stickCount - 1, 0, 0, target);
    }

    int fail = -1;
    for (int i = idx; i < n; i++) {
        if (usd[i] || l[i] + currLen > target || l[i] == fail) continue;

        cout << "尝试拼接段: " << l[i] << "，当前长度: " << currLen << "，目标长度: " << target << endl;

        usd[i] = true;
        if (dfs(stickCount, currLen + l[i], i + 1, target)) return true;
        usd[i] = false;

        cout << "⚠️ 失败回溯，段: " << l[i] << "（标记为 fail）\n";
        fail = l[i];

        if (currLen == 0 || currLen + l[i] == target) {
            cout << "✂️ 剪枝触发：currLen == 0 或 拼满失败，跳出循环。\n";
            break;
        }
    }
    return false;
}


int main() {

	cin >> n;
	l.resize(n);
	usd.resize(n, false);
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		sum += l[i];
		maxL = max(maxL, l[i]);
	}
	sort(l.begin(), l.end(), greater<>());// 降序排列
	int L = maxL;
	for (; L < sum; L++) {
		if (sum % L != 0)continue; // 木棍长度必须是总长的因子
		if (dfs(sum / L, 0, 0, L))break; // 组合成功
	}
	cout << L;
	return 0;
}