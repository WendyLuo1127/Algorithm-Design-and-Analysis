#include <bits/stdc++.h>
using namespace std;

int main() {
    // Step 1: Read input
    string line;
    getline(cin, line);
    istringstream iss(line);

    vector<int> price;
    int num;
    while (iss >> num) {
        price.push_back(num);
    }

    // Step 2: Handle edge cases
    int n = price.size();
    if (n < 2) {
        cout << 0 << endl; // No profit possible with less than 2 days
        return 0;
    }

    // Step 3: Compute maximum profit for the first transaction
    vector<int> first(n, 0);
    int minprice = price[0];
    for (int i = 1; i < n; i++) {
        minprice = min(minprice, price[i]); // Track the minimum price seen so far
        first[i] = max(first[i - 1], price[i] - minprice); // Max profit up to day i
    }

    // Step 4: Compute maximum profit with a second transaction
    int maxprofit = 0;
    int maxprice = price[n - 1];
    int second = 0;
    for (int i = n - 2; i >= 0; i--) {
        maxprice = max(maxprice, price[i]); // Track the maximum price seen so far (from the end)
        second = max(second, maxprice - price[i]); // Max profit from second transaction
        // Total profit = profit from first transaction up to day i + profit from second transaction after day i
        maxprofit = max(maxprofit, first[i] + second);
    }

    // Step 5: Output the result
    cout << maxprofit << endl;

    return 0;
}