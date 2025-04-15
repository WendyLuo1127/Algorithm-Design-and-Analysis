#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int BF(char S[], char T[], char A[])//BF算法
{
	int i = 0, j = 0;//i标记母串S，j标记子串T
	while (i < strlen(S) && j < strlen(A))
	{
		if (S[i] == T[j])//相等，都往下
		{
			i++;
			j++;
		}
		else//不等，母串回溯
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= strlen(A)) return 1;
	else return 0;

}
int main()
{
	char a[501], b[501];
	int n, flag = 0;
	cin >> n;//待测对数
	for (int i = 0; i < n; i++)
	{
		cin >> a;//输入病毒串
		getchar();
		cin >> b;//输入DNA
		char c[1000];
		for (int i = 0; i < strlen(a); i++)//病毒串为环串，遍历每种可能
		{
			int k = i;
			for (int j = 0; j < strlen(a); j++)//c赋值为该次判断的病毒串
			{
				c[j] = a[k++];
				if (k % strlen(a) == 0) k = 0;
			}
			if (BF(b, c, a) == 1)//用BF算法判断，病毒串为子串，DNA为母串
			{
				flag = 1;
				break;
			}
			else
				flag = 0;
		}
		if (flag == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
