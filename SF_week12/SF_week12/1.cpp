#include<bits/stdc++.h>
using namespace std;

int find(vector<vector<int>>in, int n, int m) {
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (in[i][j] == 1 && !visited[i][j]) {
				if (j + 1 < m && in[i][j + 1] == 1 && !visited[i][j + 1]) {
					count += 2;
					visited[i][j] = true;
					visited[i][j + 1] = true;
					cout << i << j << "right" << count << endl;
				}
				else if (i + 1 < n && in[i + 1][j] == 1 && !visited[i + 1][j]) {
					count += 2;
					visited[i][j] = true;
					visited[i + 1][j] = true;
					cout << i << j << "down" << count << endl;
				}
			}
		}
	}
	return count;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> in(n, vector<int>(m));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			cin >> in[i][j];
		}

	cout << find(in, n, m);
	return 0;
}