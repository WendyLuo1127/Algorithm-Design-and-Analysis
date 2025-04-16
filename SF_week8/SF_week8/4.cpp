#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>>costs(2 * n, vector<int>(2));
	for (int i = 0; i < 2 * n; i++) {
		cin >> costs[i][0] >> costs[i][1];
	}
	sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
		return (a[0] - a[1]) < (b[0] - b[1]); });

	int total = 0;

	for (int i = 0; i < n; i++)total += costs[i][0];
	for (int i = n; i < n * 2; i++)total += costs[i][1];
	cout << total;
	return 0;
}