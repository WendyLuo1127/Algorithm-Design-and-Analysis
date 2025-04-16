#include<bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<int>g(m);
	vector<int>s(n);
	for (int i = 0; i < m; i++)cin >> g[i];
	for (int i = 0; i < n; i++)cin >> s[i];

	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int count = 0;
	int max = min(m, n);
	int j = 0, i = 0;
	while (i < n && j < m) {
		if (s[i] >= g[j]) {
			count++;
			j++;
		}
		i++;
	}
	cout << count;
	return 0;
}