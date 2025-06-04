//LeetCode:1363(hard)
//利用 3 的倍数的性质：一个数的各位数字之和是 3 的倍数，那么这个数就是 3 的倍数
// 计算总和余数：计算数组中所有数字的总和对 3 的余数。
//处理余数：
//如果余数为 0，直接使用所有数字。
//如果余数为 1，尝试去掉一个模 3 余 1 的最小数字，或者去掉两个模 3 余 2 的最小数字。
//如果余数为 2，尝试去掉一个模 3 余 2 的最小数字，或者去掉两个模 3 余 1 的最小数字。
//组成结果字符串：处理完数字后，将剩余数字组成字符串，去掉前导零。如果结果为空，返回 "0"，否则返回处理后的字符串。

#include<bits/stdc++.h>
using namespace std;

string largestMultipleOfThree(vector<int>& digits) {
    sort(digits.rbegin(), digits.rend()); // 降序排序
    int sum = 0;
    for (int d : digits) sum += d;
    int rem = sum % 3;
    if (rem == 0) {
        // 直接处理
    }
    else {
        vector<int> mod1, mod2;
        for (int d : digits) {
            if (d % 3 == 1) mod1.push_back(d);
            if (d % 3 == 2) mod2.push_back(d);
        }
        if (rem == 1) {
            // 尝试去掉一个 mod1 或两个 mod2
            vector<int> temp = digits;
            if (!mod1.empty()) {
                auto it = find(temp.begin(), temp.end(), mod1.back());
                if (it != temp.end()) {
                    temp.erase(it);
                    int new_sum = 0;
                    for (int d : temp) new_sum += d;
                    if (new_sum % 3 == 0) {
                        digits = temp;
                        goto process;
                    }
                }
            }
            if (mod2.size() >= 2) {
                vector<int> temp = digits;
                auto it1 = find(temp.begin(), temp.end(), mod2[mod2.size() - 1]);
                temp.erase(it1);
                auto it2 = find(temp.begin(), temp.end(), mod2[mod2.size() - 2]);
                temp.erase(it2);
                int new_sum = 0;
                for (int d : temp) new_sum += d;
                if (new_sum % 3 == 0) {
                    digits = temp;
                    goto process;
                }
            }
            return "";
        }
        else { // rem == 2
            // 尝试去掉一个 mod2 或两个 mod1
            vector<int> temp = digits;
            if (!mod2.empty()) {
                auto it = find(temp.begin(), temp.end(), mod2.back());
                if (it != temp.end()) {
                    temp.erase(it);
                    int new_sum = 0;
                    for (int d : temp) new_sum += d;
                    if (new_sum % 3 == 0) {
                        digits = temp;
                        goto process;
                    }
                }
            }
            if (mod1.size() >= 2) {
                vector<int> temp = digits;
                auto it1 = find(temp.begin(), temp.end(), mod1[mod1.size() - 1]);
                temp.erase(it1);
                auto it2 = find(temp.begin(), temp.end(), mod1[mod1.size() - 2]);
                temp.erase(it2);
                int new_sum = 0;
                for (int d : temp) new_sum += d;
                if (new_sum % 3 == 0) {
                    digits = temp;
                    goto process;
                }
            }
            return "";
        }
    }
    process:
        if (digits.empty()) return "";
        string res;
        bool has_non_zero = false;
        for (int d : digits) {
            if (d == 0 && !has_non_zero) {
                continue; // 跳过前导零
            }
            res += to_string(d);
            has_non_zero = true;
        }
        return res.empty() ? "0" : res;
}

int main() {
	vector<int>digits;
	int num;
	while (cin >> num)digits.push_back(num);
	cout << largestMultipleOfThree(digits);
}