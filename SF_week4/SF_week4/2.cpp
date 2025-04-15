//����˳��
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ������������������
int calculate(int left, int right, char c)
{
    if (c == '+')
    {
        return left + right;
    }
    else if (c == '-')
    {
        return left - right;
    }
    else if (c == '*')
    {
        return left * right;
    }
    return 0;
}

// ���μ������п��ܵĽ��
vector<int> Compute(string s)
{
    vector<int> result;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '+' || c == '-' || c == '*')
        {
            // �ָ��ַ���Ϊ����������
            string lefts = s.substr(0, i);
            string rights = s.substr(i + 1);
            // �ݹ�������������ֵ����п��ܽ��
            vector<int> leftresult = Compute(lefts);
            vector<int> rightresult = Compute(rights);
            // ������������ֵĽ��
            for (int left : leftresult)
            {
                for (int right : rightresult)
                {
                    result.push_back(calculate(left, right, c));
                }
            }
        }
    }

    // ���������ַ��������
    if (result.empty()) {
        result.push_back(stoi(s));
    }

    return result;
}

int main() {
    string s;
    cin >> s;
    // �������п��ܵĽ��
    vector<int> result = Compute(s);
    // �Խ����������
    sort(result.begin(), result.end());
    // ��Ҫ����������ÿ�����ռһ��
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}