#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void twocolorswap(int *array, int n)
{
	int front = 0, rear = n - 1;
	while (front < rear)
	{
		while (array[front]==0&&front<rear)front++;
		while (array[rear]==1&&front<rear)rear--;
		if (front < rear)
		{
			int temp = array[front];
			array[front] = array[rear];
			array[rear] = temp;
		}
		else
		{
			front++;
			rear--;
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int *array = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);
	twocolorswap(array, n);
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	return 0;
}