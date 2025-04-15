#include<iostream>
#include<string>
#include<cstring>
using namespace std;
//int c = 0 ;
//int cun[2] ; 
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	int n = s1.size();
	int a = 2;
	while (a--)
	{
		getline(cin, s2);
		int  n1 = s2.size();
		string s3 = s1;
		if (n1 < n)
			s3.erase(0, n - n1);
		if (n1 > n)
			s2.erase(n, n1 - n);
		int flag = 1;
		int x = 0;
		while (!s2.empty())
		{
			if (s2 == s3)
			{
				flag = 0;
				x = s2.size();
				break;
			}
			else
			{
				s3.erase(0, 1);
				s2.erase(s2.size() - 1, 1);
			}
		}
		if (flag)
			printf("0");
		//cun[c++] = 0 ;
		else
			printf("%d", x);
		//cun[c++] = x ;
		if (a == 1)
			printf(" ");
	}
	//printf("%d %d",cun[0],cun[1]) ;
	return 0;
}
