#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct Linkedlist
{
	int data;
	struct Linkedlist *next;
};
struct Linkedlist* getnewLLnode(int k)
{
	struct Linkedlist *newnode = (struct Linkedlist *)malloc(sizeof(struct Linkedlist));
	newnode->data = k;
	newnode->next = NULL;
	return newnode;
}
struct Linkedlist* createLoopedLinkedList(int array[], int size, int position)
{
	struct Linkedlist *head = getnewLLnode(array[0]);
	struct Linkedlist *tempnode = head;
	for (int i = 1; i < size; i++)
	{
		struct Linkedlist *newnode = getnewLLnode(array[i]);
		tempnode->next = newnode;
		tempnode = tempnode->next;
	}
	if (position > 1)
	{
		struct Linkedlist *start = head;
		for (int i = 0; i < position - 1; i++)
			start = start->next;
		tempnode->next = start;
	}
	return head;
}
int detectloopinaLL(struct Linkedlist *head)
{
	struct Linkedlist *slowptr = head->next, *fastptr = head->next;
	fastptr = fastptr->next;
	int flag = 0;
	while (1)
	{
		if (slowptr == NULL || fastptr == NULL)
		{
			flag = 1;
			break;
		}
		if (slowptr == fastptr)
			break;
		slowptr = slowptr->next;
		fastptr = fastptr->next;
		if (fastptr == NULL)
		{
			flag = 1;
			break;
		}
		fastptr = fastptr->next;
	}
	if (flag)
		return -1;
	else
	{
		int count = 0;
		while (head != slowptr)
		{
			head = head->next;
			slowptr = slowptr->next;
			count++;
		}
		return count + 1;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int *array = (int *)malloc(n*sizeof(int));
	for (int i = 0; i<n; i++)
		scanf("%d", &array[i]);
	int position;
	scanf("%d", &position);
	struct Linkedlist *head = createLoopedLinkedList(array, n, position);
	printf("%d", detectloopinaLL(head));
	return 0;
}