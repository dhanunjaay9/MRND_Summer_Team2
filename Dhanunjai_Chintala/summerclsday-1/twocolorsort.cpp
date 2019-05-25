#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void twocolorsort(int *array, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i; j < n;j++)
			if (array[i]>array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}
int main()
{
	int n;
	scanf("%d", &n);
	int *array = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);
	twocolorsort(array, n);
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	return 0;
}