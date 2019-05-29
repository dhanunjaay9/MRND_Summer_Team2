#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void statespacetree(int array[],int curr,int n)
{
	if (curr == n-1)
	{
		int i = 0;
		for (; i < curr - 1 && array[i] == 0; i++);
		for (; i < curr; i++)
				printf("%d", array[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		array[curr] = i;
		statespacetree(array, curr + 1, n);
	}
	return;
}
int printlen(int n)
{
	int *array = (int *)calloc((n-1) , sizeof(int));
	statespacetree(array, 0, n);
	return 0;
}
int main()
{
	printlen(4);
	return 0;
}