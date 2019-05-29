#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int kstepways(int n, int k)
{
	if (n==0)
		return 1;
	if (n < 0)
		return 0;
	int sum = 0;
	for (int i = 1; i <= k; i++)
		sum += kstepways(n-i,k);
	return sum;
}
int main()
{
	printf("%d", kstepways(4,1));
	return 0;
}