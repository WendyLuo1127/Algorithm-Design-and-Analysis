#include<bits/stdc++.h>
using namespace std;

bool judge(int your_money[], int money) {
	if (money == 5) {
		your_money[0] += 1;
		return true;
	}
	else if (money == 10) {
		if (your_money[0] > 0) {
			your_money[0] -= 1;
			your_money[1] += 1;
			return true;
		}
		else return false;
	}
	else if (money == 20) {
		if (your_money[0] > 0 && your_money[1] > 0) {
			your_money[0] -= 1;
			your_money[1] -= 1;
			your_money[2] += 1;
			return true;
		}
		else if (your_money[0] > 2) {
			your_money[0] -= 3;
			your_money[2] += 1;
			return true;
		}
		else return false;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int>money(n);
	int your_money[3] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> money[i];
		if (!judge(your_money, money[i])) {
			cout << "false";
			return 0;
		}
		/*
		cout << i+1 << endl;
		cout << "5:" << your_money[0] << endl;
		cout << "10:" << your_money[1] << endl;
		cout << "20:" << your_money[2] << endl;*/
	}
	cout << "true";
	return 0;
}