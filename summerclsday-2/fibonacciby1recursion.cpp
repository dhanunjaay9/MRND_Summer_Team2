#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<map>
long fibonacci(int n)
{
	static int *array = (int *)calloc(n,sizeof(int));
	if (n < 0)
		return -1;
	if (n == 0 || n == 1)
	{
		return n;
	}
	long sum = 0;
	if (array[n - 1] && array[n - 2])
		sum+= array[n - 1] + array[n - 2];
	else
	{
		int sum1 = fibonacci(n - 1) ,sum2 = fibonacci(n - 2);
		array[n - 1] = sum1;
		array[n - 2] = sum2;
		sum = sum1 + sum2;
	}
	return sum;
}
int main()
{
	printf("\n%d", fibonacci(8));
	return 0;
}