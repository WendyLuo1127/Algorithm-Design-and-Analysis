//连招顺序
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 计算两个数的运算结果
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

// 分治计算所有可能的结果
vector<int> Compute(string s)
{
    vector<int> result;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '+' || c == '-' || c == '*')
        {
            // 分割字符串为左右两部分
            string lefts = s.substr(0, i);
            string rights = s.substr(i + 1);
            // 递归计算左右两部分的所有可能结果
            vector<int> leftresult = Compute(lefts);
            vector<int> rightresult = Compute(rights);
            // 组合左右两部分的结果
            for (int left : leftresult)
            {
                for (int right : rightresult)
                {
                    result.push_back(calculate(left, right, c));
                }
            }
        }
    }

    // 处理纯数字字符串的情况
    if (result.empty()) {
        result.push_back(stoi(s));
    }

    return result;
}

int main() {
    string s;
    cin >> s;
    // 计算所有可能的结果
    vector<int> result = Compute(s);
    // 对结果进行排序
    sort(result.begin(), result.end());
    // 按要求输出结果，每个结果占一行
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}