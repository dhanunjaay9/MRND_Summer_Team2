#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int getfibonacci(int **A,int n)
{
	int Aux[2][2] = { { 0, 1 },{1, 1} },B[2][2];
	if (n == 0)
		return 0;
	if (n ==1)
	{
		return A[1][1];
	}
	int key = getfibonacci(A, n / 2);
	for (int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			int sum = 0;
			for (int dummy = 0; dummy < 2; dummy++)
				sum += A[row][dummy] * A[dummy][column];
			B[row][column] = sum;
		}
	}
	A[0][0] = B[0][0];
	A[0][1] = B[0][1];
	A[1][0] = B[1][0];
	A[1][1] = B[1][1];
	if (n % 2)
	{
		for (int row = 0; row < 2; row++)
		{
			for (int column = 0; column < 2; column++)
			{
				int sum = 0;
				for (int dummy = 0; dummy < 2; dummy++)
					sum += A[row][dummy] * Aux[dummy][column];
				B[row][column] = sum;
			}
		}
		A[0][0] = B[0][0];
		A[0][1] = B[0][1];
		A[1][0] = B[1][0];
		A[1][1] = B[1][1];
	}
	return A[1][1];
}
int main()
{
	int n;
	int **A = (int **)malloc(2 * sizeof(int *));
	A[0] = (int *)malloc(2 * sizeof(int));
	A[1] = (int *)malloc(2 * sizeof(int));
	A[0][0] = 0;
	A[0][1] = 1;
	A[1][0] = 1;
	A[1][1] = 1;
	scanf("%d", &n);
	int fib01[2] = { 0, 1 };
	printf("%d",getfibonacci(A,n-1));
}