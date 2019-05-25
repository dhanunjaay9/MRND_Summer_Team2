#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct AuxLL
{
	int data;
	struct AuxLL *next;
	struct AuxLL *random;
};
struct AuxLL* getnewnode(int k)
{
	struct AuxLL *newnode = (struct AuxLL *)malloc(sizeof(struct AuxLL));
	newnode->data = k;
	newnode->next = NULL;
	newnode->random = NULL;
	return newnode;
}
struct AuxLL* createauxLL(int a[], int n)
{
	struct AuxLL *head = getnewnode(a[0]);
	struct AuxLL *temp = head;
	struct AuxLL **table = (struct AuxLL **)malloc(n*sizeof(struct AuxLL *));
	table[0] = head;
	for (int i = 1; i < n; i++)
	{
		struct AuxLL *newnode = getnewnode(a[i]);
		temp->next = newnode;
		temp = temp->next;
		table[i] = temp;
	}
	temp = head;
	head->random = table[2];
	temp = head->next;
	temp->random = table[4];
	temp = temp->next;
	temp = temp->next;
	temp->random = table[4];
	temp = temp->next;
	temp = temp->next;
	temp->random = table[3];
	return head;
}
struct AuxLL* cloneauxLL(struct AuxLL *head)
{
	struct AuxLL* temp = head;
	struct AuxLL *newauxhead = getnewnode(head->data);
	struct AuxLL *clonetemp = newauxhead;
	temp = temp->next;
	while (temp != NULL)
	{
		struct AuxLL *newnode = getnewnode(temp->data);
		clonetemp->next = newnode;
		clonetemp = clonetemp->next;
		temp = temp->next;
	}
	clonetemp = newauxhead;
	temp = head;
	clonetemp = newauxhead;
	while (temp != NULL)
	{
		struct AuxLL *duplicate = temp;
		temp = temp->next;
		duplicate->next = clonetemp;
		clonetemp->random = duplicate->random;
		clonetemp = clonetemp->next;
	}
	clonetemp = newauxhead;
	while (clonetemp != NULL)
	{
		if (clonetemp->random)
			clonetemp->random = clonetemp->random->next;
		clonetemp = clonetemp->next;
	}
	return newauxhead;
}
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	struct AuxLL *head = createauxLL(array, 6);
	struct AuxLL *newauxhead = cloneauxLL(head);
	while (newauxhead != NULL)
	{
		printf("%d", newauxhead->data);
		if (newauxhead->random)
			printf("\t%d", newauxhead->random->data);
		newauxhead = newauxhead->next;
	}
	return 0;
}