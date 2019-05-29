#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void statetree(int distinctnumber[], int array[], int currentstate, int limit)
{
	if (currentstate == limit)
	{
		for (int i = 0; i < limit; i++)
			printf("%d", array[i]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i < limit; i++)
		{
			if (distinctnumber[i])
			{
				array[currentstate] = distinctnumber[i];
				int temp = distinctnumber[i];
				distinctnumber[i] = 0;
				statetree(distinctnumber, array, currentstate + 1, limit);
				distinctnumber[i] = temp;
			}
		}
	}
}
void printpremutations(int distinctnumbers[], int n)
{
	int *array = (int *)calloc(n, sizeof(int));
	statetree(distinctnumbers,array, 0, n);
}
int main()
{
	int distinctnumbers[] = { 1,3,4,9 };
	printpremutations(distinctnumbers, 4);
	return 0;
}