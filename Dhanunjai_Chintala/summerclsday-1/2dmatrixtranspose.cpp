#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int** twodtranspose(int **a, int m, int n)
{
	int **result = (int **)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
		result[i] = (int *)malloc(m*sizeof(int));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			result[j][i] = a[i][j];
	return result;
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int **array = (int **)malloc(m*sizeof(int *));
	for (int i = 0; i < m; i++)
		array[i] = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &array[i][j]);
	int **result = twodtranspose(array, m, n);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}

	return 0;
}