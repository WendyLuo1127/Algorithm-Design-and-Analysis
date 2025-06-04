//��� P1120 Сľ��

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>l;//ľ������
vector<bool>usd;//�Ƿ�ʹ�ù�
int sum = 0;
int maxL = 0;
int n;

//stickCount: ����ƴ���ٸ�����ľ��
// currLen: ��ǰľ����ƴ�ĳ���
// idx : ������ʼλ�ã������ظ����
// target : ÿ��ľ��Ŀ�곤�� = L
bool dfs(int stickCount,int currLen,int idx,int target) {
	if (stickCount == 0)return true; // ����ľ����������
	if (currLen == target)return dfs(stickCount - 1, 0, 0, target); // �����һ��

	int fail = -1;//��¼ʧ�ܵĳ���
	for (int i = idx; i < n; i++) {
		if (usd[i] || l[i] + currLen > target || l[i] == fail)continue;//����ʧ��
		usd[i] = true;
		if (dfs(stickCount, currLen + l[i], i + 1, target))return true; // ����ƴ��ǰ��һ��ľ��
		usd[i] = false;
		fail = l[i];
		if (currLen == 0 || currLen + l[i] == target)break; //�����һ��λ�ò��ɹ������в��ɹ�or��ǰľ������ƴ������ʧ��
	}
	return false;
}

int main() {
	
	cin >> n;
	l.resize(n);
	usd.resize(n,false);
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		sum += l[i];
		maxL = max(maxL, l[i]);
	}
	sort(l.begin(), l.end(),greater<>());// ��������
	int L = maxL;
	for (; L < sum; L++) {
		if (sum % L != 0)continue; // ľ�����ȱ������ܳ�������
		if (dfs(sum/L, 0, 0, L))break; // ��ϳɹ�
	}
	cout << L;
	return 0;
}