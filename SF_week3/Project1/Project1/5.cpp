#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> s;
    int x;
    while (cin >> x) {
        s.push_back(x);
        if (cin.peek() == '\n') break; // һ�ж���
    }

    sort(s.begin(), s.end());
    int mid = s[s.size() / 2];  // ����λ��
    cout << mid << endl;

    return 0;
}
