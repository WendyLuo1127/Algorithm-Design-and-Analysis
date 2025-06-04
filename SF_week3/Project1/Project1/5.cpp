#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> s;
    int x;
    while (cin >> x) {
        s.push_back(x);
        if (cin.peek() == '\n') break; // 一行读完
    }

    sort(s.begin(), s.end());
    int mid = s[s.size() / 2];  // 下中位数
    cout << mid << endl;

    return 0;
}
