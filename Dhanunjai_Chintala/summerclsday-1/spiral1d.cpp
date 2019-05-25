#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int* spiral1d(int **a, int m, int n)
{
	int *result = (int *)malloc(m*n*sizeof(int));
	int top = 0, bot = m, left = 0, right = n;
	int i = 0, j = 0, ind = 0;
	while (top <= bot && left <= right)
	{
		while (j < right)
		{
			result[ind++] = a[i][j++];
		}
		j--;
		top++;
		i++;
		while (i < bot)
			result[ind++] = a[i++][j];
		i--;
		right--;
		j--;
		while (j >= left)
			result[ind++] = a[i][j--];
		j++;
		bot--;
		i--;
		while (i >= top)
			result[ind++] = a[i--][j];
		i++;
		left--;
		j++;
	}
	result[ind] = a[i][j];
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
	int *result = spiral1d(array, m, n);
	for (int i = 0; i<m*n; i++)
		printf("%d ", result[i]);
}