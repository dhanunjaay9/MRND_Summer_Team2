#include<stdio.h>
#include<stdlib.h>
struct LL
{
    int data;
    struct LL *next;
};
struct LL* getNewNode(int k)
{
    struct LL* node=(struct LL *)malloc(sizeof(struct LL));
    node->data=k;
    node->next=NULL;
}
struct LL* createLL(int a[],int n)
{
    struct LL *head=getNewNode(a[0]);
    struct LL *temp=head;
    for(int i=1;i<n;i++)
    {
        struct LL *newnode=getNewNode(a[i]);
        temp->next=newnode;
        temp=temp->next;
    }
    return head;
}
int hasknodes(struct LL *head,int k)
{
    for(int i=0;i<k;i++)
    {
        if(head==NULL)
            return 0;
        head=head->next;
    }
    return 1;
}
struct LL* connector(struct LL *start,int k)
{
    if(k==1)
        return start->next;
    struct LL *head=connector(start->next,k-1);
    struct LL *temp=start->next;
    temp->next=start;
    return head;
}
struct LL* reverse(struct LL *head,int k)
{
    struct LL *temp=head;
    for(int i=0;i<k-1;i++)
        temp=temp->next;
    struct LL *newhead=connector(head,k);
    head->next=newhead;
    return temp;
}
struct LL* getnewhead(struct LL *head,int k)
{
    for(int i=0;i<k-1;i++)
        head=head->next;
    return head;
}
struct LL* kswap(int k,struct LL *head)
{
    struct LL *temp=head;
    if(hasknodes(temp,k))
    {
        head=getnewhead(temp,k);
        temp=reverse(temp,k);
    }
    for(int i=0;i<k-1;i++)
        temp=temp->next;
    struct LL *newhead=temp;
    temp=temp->next;
    while(temp!=NULL && hasknodes(temp,k))
    {
        temp=reverse(temp,k);
        newhead->next=temp;
        for(int i=0;i<k-1;i++)
            temp=temp->next;
        newhead=temp;
        temp=temp->next;
    }
    return head;
}
int main()
{
    int n;
    scanf("%d",&n);
    int *array=(int *)malloc(n*sizeof(int));
    printf("Enter %d elements",n);
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);
    printf("Enter the swap length");
    int k;
    scanf("%d",&k);
    struct LL *head=createLL(array,n);
    struct LL *newhead=kswap(k,head);
    while(newhead!=NULL)
    {
        printf("%d",newhead->data);
        newhead=newhead->next;
    }
    return 0;
}
