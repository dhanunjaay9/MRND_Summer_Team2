#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void twocolorcount(int *array,int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += array[i];
	for (int i = 0; i < size - sum; i++)
		array[i] = 0;
	for (int i = size-sum; i < size; i++)
		array[i] = 1;
}
int main()
{
	int n;
	scanf("%d", &n);
	int *array = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);
	twocolorcount(array, n);
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	return 0;
}