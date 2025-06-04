#include<bits/stdc++.h>
using namespace std;

bool validPalindrome(string s) {
	int left = 0, right = s.size()-1;
	while (left < right) {
		if (s[left] == s[right]) {
			left++;
			right--;
		}
		else {
			bool is_palL = true;
			int l1 = left + 1, r1 = right;
			while (l1 < r1) {
				if (s[l1] != s[r1]) {
					is_palL = false;
					break;
				}
				l1++;
				r1--;
			}
			bool is_palR = true;
			int l2 = left, r2 = right-1;
			while (l2 < r2) {
				if (s[l2] != s[r2]) {
					is_palR = false;
					break;
				}
				l2++;
				r2--;
			}
			return is_palL || is_palR;
		}
	}
	return true;
}

int main() {
	string s;
	getline(cin, s);
	if (validPalindrome(s))cout << "true";
	else cout << "false";
	return 0;
}