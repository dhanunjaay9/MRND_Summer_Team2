#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<map>
void stateTree(int distinctnumber[], int array[], int currentstate, int limit)
{
	if (limit==0)
	{
		for (int i = 0; i < currentstate; i++)
			printf("%d", array[i]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i < limit; i++)
		{
			int temp = distinctnumber[i];
			array[currentstate] = distinctnumber[i];
			//hashmap[distinctnumber[i]] = 1;
			distinctnumber[i] = distinctnumber[limit - 1];
			stateTree(distinctnumber, array, currentstate + 1, limit-1);
			distinctnumber[i] = temp;
			while (distinctnumber[i] == distinctnumber[i + 1]&&i<limit)i++;
		}
	}
}
void printnondistinctpremutations(int distinctnumbers[], int n)
{
	int *array = (int *)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n;j++)
			if (distinctnumbers[i]>distinctnumbers[j])
			{
				int temp = distinctnumbers[i];
				distinctnumbers[i] = distinctnumbers[j];
				distinctnumbers[j] = temp;
			}
	stateTree(distinctnumbers, array, 0, n);
}
int main()
{
	int distinctnumbers[] = { 1, 4, 1, 9 };
	printnondistinctpremutations(distinctnumbers, 4);
	return 0;
}