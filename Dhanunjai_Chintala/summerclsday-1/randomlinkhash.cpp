#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<stdio.h>
struct LL
{
	int data;
	struct LL *next;
	struct LL *random;
};
struct LL* getnewNode(int k)
{
	struct LL* newnode = (struct LL *)malloc(sizeof(struct LL));
	newnode->data = k;
	newnode->next = NULL;
	newnode->random = NULL;
	return newnode;
}
struct LL* createrandomLL(int a[], int n)
{
	struct LL *head = getnewNode(a[0]);
	struct LL *temp = head;
	struct LL **table = (struct LL **)malloc(n*sizeof(struct LL *));
	table[0] = head;
	for (int i = 1; i < n; i++)
	{
		struct LL *newnode = getnewNode(a[i]);
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
struct LL* cloneLL(struct LL *head)
{
	std::map<struct LL *, struct LL *> hashtable;
	struct LL *clonehead = getnewNode(head->data);
	struct LL *clonetemp = clonehead, *temp = head;
	hashtable[temp] = clonetemp;
	temp = temp->next;
	while (temp != NULL)
	{
		struct LL *newnode = getnewNode(temp->data);
		clonetemp->next = newnode;
		clonetemp = clonetemp->next;
		hashtable[temp] = clonetemp;
		temp = temp->next;
	}
	temp = head;
	clonetemp = clonehead;
	while (temp != NULL)
	{
		if (temp->random)
		{
			clonetemp->random = hashtable[temp->random];
		}
		temp = temp->next;
		clonetemp = clonetemp->next;
	}
	return clonehead;
}
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	struct LL *head = createrandomLL(array, 6);
	struct LL *clonehead = cloneLL(head);
	while (clonehead != NULL)
	{
		printf("%d", clonehead->data);
		if (clonehead->random)
			printf("\t%d\n", clonehead->random->data);
		clonehead = clonehead->next;
	}
		return 0;
}