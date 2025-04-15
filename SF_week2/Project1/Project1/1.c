#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int N,max=0;
	scanf("%d", &N);
	int input[100000];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input[i]);
		if (max < input[i])max = input[i];
	}
	printf("%d", max);
	return 0;
}