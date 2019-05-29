#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct DoubleLL
{
	int data;
	struct DoubleLL *next;
	struct DoubleLL *prev;
};
struct DoubleLL* getnewnode(int k)
{
	struct DoubleLL *newnode = (struct DoubleLL *)malloc(sizeof(struct DoubleLL));
	newnode->data = k;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
struct DoubleLL* createaDLL(int array[], int size)
{
	struct DoubleLL *head = getnewnode(array[0]);
	struct DoubleLL *temp = head;
	for (int index = 1; index < size; index++)
	{
		struct DoubleLL *newnode = getnewnode(array[index]);
		temp->next = newnode;
		newnode->prev = temp;
		temp = temp->next;
	}
	return head;
}
int getsizeofdll(struct DoubleLL *head)
{
	int size;
	for (size = 0; head != NULL; head = head->next, size++);
	return size;
}
struct DoubleLL* merge2sortedDLL(struct DoubleLL *newhead, struct DoubleLL *newtail)
{
	struct DoubleLL *temp, *originalhead;
	if (newhead->data < newtail->data)
		originalhead = newhead;
	else
		originalhead = newtail;
	while (newhead != NULL&&newtail != NULL&&newhead->next != NULL && newtail->next != NULL)
	{
		if (newhead->data < newtail->data)
		{
			while (newhead->next != NULL&&newhead->next->data < newtail->data)
				newhead = newhead->next;
			temp = newhead->next;
			newhead->next = newtail;
			newtail->prev = newhead;
			newhead = temp;
		}
		else
		{
			while (newtail->next != NULL && newtail->next->data <= newhead->data)
				newtail = newtail->next;
			temp = newtail->next;
			newtail->next = newhead;
			newhead->prev = newtail;
			newtail = temp;
		}
	}
	if (newhead == NULL || newtail == NULL)
		return originalhead;
	if (newhead->next == NULL && newtail->next == NULL)
	{
		if (newhead->data < newtail->data)
		{
			newhead->next = newtail;
			newtail->prev = newhead;
		}
		else
		{
			newtail->next = newhead;
			newhead->prev = newtail;
		}
		return originalhead;
	}
	if (newhead->next == NULL)
	{
		if (newtail->data < newhead->data)
		{
			while (newtail->next != NULL && newtail->next->data < newhead->data)
				newtail = newtail->next;
			temp = newtail->next;
			newtail->next = newhead;
			newhead->prev = newtail;
			newhead->next = temp;
		}
		else
		{
			newtail->prev = newhead;
			newhead->next = newtail;
		}
	}
	else
	{
		if (newhead->data < newtail->data)
		{
			while (newhead->next != NULL&&newhead->next->data < newtail->data)
				newhead = newhead->next;
			temp = newhead->next;
			newhead->next = newtail;
			newtail->prev = newhead;
			newtail->next = temp;
		}
		else
		{
			newhead->prev = newtail;
			newtail->next = newhead;
		}
	}
	return originalhead;
}
struct DoubleLL* sortDLL(struct DoubleLL *head, int size)
{
	if (size == 1)
		return head;
	struct DoubleLL *tail = head;
	struct DoubleLL *originalhead = NULL;
	for (int index = 0; index < size / 2; index++, tail = tail->next);
	struct DoubleLL *temp = tail->prev;
	temp->next = NULL;
	tail->prev = NULL;
	int tailsize = size % 2 ? size / 2 + 1 : size / 2;
	struct DoubleLL *newhead = sortDLL(head, size / 2);
	struct DoubleLL *newtail = sortDLL(tail, tailsize);
	originalhead = merge2sortedDLL(newhead, newtail);
	return originalhead;
}
int main()
{
	int size = 0;
	printf("Enter the size of DoubleLL");
	scanf("%d", &size);
	int *array = (int *)malloc(size*sizeof(int));
	for (int index = 0; index < size; index++)
		scanf("%d", &array[index]);
	struct DoubleLL *head = createaDLL(array, size);
	int sizeofDLL = getsizeofdll(head);
	struct DoubleLL *newhead = sortDLL(head, size);
	while (newhead != NULL)
	{
		printf("%d ", newhead->data);
		newhead = newhead->next;
	}
	return 0;
}