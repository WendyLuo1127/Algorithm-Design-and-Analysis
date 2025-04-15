//×î´óÀûÈó

#include<bits/stdc++.h>
using namespace std;

int main() {
	int mincost, maxprofit=0;
	int price;
	cin >> price;
	mincost = price;
	while (cin >> price) {
		if (price < mincost)mincost = price;
		else if (price > mincost) {
			int profit = price - mincost;
			maxprofit = max(maxprofit, profit);
		}
		//cout << mincost << " " << maxprofit << endl;
	}
	cout << maxprofit;
}