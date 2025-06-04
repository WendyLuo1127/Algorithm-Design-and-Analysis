//leetcode 949

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string largestTimeFromDigits(vector<int>& A) {
    sort(A.begin(), A.end());  // ������������ȫ����
    string maxTime = "";

    // �����������в������Ч��
    do {
        int hh = A[0] * 10 + A[1];
        int mm = A[2] * 10 + A[3];

        // ����Ƿ�Ϊ��Чʱ��
        if (hh >= 0 && hh <= 23 && mm >= 0 && mm <= 59) {
            string currentTime = to_string(A[0]) + to_string(A[1]) +
                ":" + to_string(A[2]) + to_string(A[3]);
            // �Ƚ��ֵ��򣬸������ʱ��
            if (currentTime > maxTime) {
                maxTime = currentTime;
            }
        }
    } while (next_permutation(A.begin(), A.end()));

    return maxTime;
}

int main() {
	vector<int>arr;
	string line;
	getline(cin, line);
	for (auto ch : line)
		if (isdigit(ch))arr.push_back(ch-'0');

	cout << largestTimeFromDigits(arr);
	return 0;
}