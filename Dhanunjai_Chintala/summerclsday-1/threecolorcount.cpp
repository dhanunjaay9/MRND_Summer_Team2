#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void threecolorcount(int *array, int size)
{
	int countzero = 0, countone = 0, counttwo = 0;
	for (int index = 0; index < size; index++)
	{
		if (!array[index])
			countzero++;
		else if (array[index] == 1)
			countone++;
		else
			counttwo++;
	}
	for (int index = 0; index < countzero; index++)
		array[index] = 0;
	for (int index = countzero; index < countzero + countone-1; index++)
		array[index] = 1;
	for (int index = countzero + countone; index < size; index++)
		array[index] = 2;
}
int main()
{
	int n;
	scanf("%d", &n);
	int *array = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);
	threecolorcount(array, n);
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	return 0;
}