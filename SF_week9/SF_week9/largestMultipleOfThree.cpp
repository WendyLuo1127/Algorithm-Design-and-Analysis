//LeetCode:1363(hard)
//���� 3 �ı��������ʣ�һ�����ĸ�λ����֮���� 3 �ı�������ô��������� 3 �ı���
// �����ܺ������������������������ֵ��ܺͶ� 3 ��������
//����������
//�������Ϊ 0��ֱ��ʹ���������֡�
//�������Ϊ 1������ȥ��һ��ģ 3 �� 1 ����С���֣�����ȥ������ģ 3 �� 2 ����С���֡�
//�������Ϊ 2������ȥ��һ��ģ 3 �� 2 ����С���֣�����ȥ������ģ 3 �� 1 ����С���֡�
//��ɽ���ַ��������������ֺ󣬽�ʣ����������ַ�����ȥ��ǰ���㡣������Ϊ�գ����� "0"�����򷵻ش������ַ�����

#include<bits/stdc++.h>
using namespace std;

string largestMultipleOfThree(vector<int>& digits) {
    sort(digits.rbegin(), digits.rend()); // ��������
    int sum = 0;
    for (int d : digits) sum += d;
    int rem = sum % 3;
    if (rem == 0) {
        // ֱ�Ӵ���
    }
    else {
        vector<int> mod1, mod2;
        for (int d : digits) {
            if (d % 3 == 1) mod1.push_back(d);
            if (d % 3 == 2) mod2.push_back(d);
        }
        if (rem == 1) {
            // ����ȥ��һ�� mod1 ������ mod2
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
            // ����ȥ��һ�� mod2 ������ mod1
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
                continue; // ����ǰ����
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