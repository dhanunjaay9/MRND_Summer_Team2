#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void stateSpaceTree(int array[], int curr, int n)
{
	if (curr == n - 1)
	{
		int i = 0;
		char encode[11] = "012Eh59L86";
		for (; i < curr - 1 && array[i] == 0; i++);
		for (; i < curr; i++)
			printf("%c", encode[array[i]]);
		printf("\n");
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		array[curr] = i;
		stateSpaceTree(array, curr + 1, n);
	}
	return;
}
int printnlen(int n)
{
	int *array = (int *)calloc((n - 1), sizeof(int));
	stateSpaceTree(array, 0, n);
	return 0;
}
int main()
{
printnlen(4);
return 0;
}