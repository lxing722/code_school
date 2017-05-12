#include<stdio.h>
#include<stdlib.h>
typedef int ListData;
typedef struct node
{
	ListData data;
	struct node *link;
} ListNode;
ListNode *first,*last;
int ListInsert(ListData x,int i);
int ListRemove(int i);


int main(void)
{
	int n;
	n = 1;
	for(int i=0;i<9;i++)
	{
		ListInsert(n,i);
		n++;
	}
	ListNode *current;
	current = first;
	while(current!=NULL)
	{
		printf("%d\n",current->data);
		current = current->link;
	}
	return 0;
}

int ListInsert(ListData x,int i)
{
	ListNode *p;
	p = first;
	for(int k=0;k<i-1;k++)
	{
		if(p==NULL) break;
		else p = p->link;
	}
	if(p==NULL&&first!=NULL)
	{
		printf("无效的插入位置！\n");
		return 0;
	}
	ListNode *newnode;
	newnode = (ListNode *)malloc(sizeof(ListNode));
	if(first==NULL||i==0)
	{
		newnode->data = x;
		newnode->link = first;
		if(first==NULL) last = newnode;
		first = newnode;
	}
	else
	{
		newnode->data = x;
		newnode->link = p->link;
		if(p->link==NULL) last = newnode;
		p->link = newnode;
	}
	return 1;
}
int ListRemove(int i)
{
	ListNode *p,*q;
	int k;
	if(i==0)
	{
		q = first,p = first = first->link;
	}
	else
	{
		p = first,k = 1;
		while(p!=NULL&&k < i-1)
		{
			p = p->link;
			k++;
		}
		if(p==NULL||p->link==NULL)
		{
			printf("无效额删除位置！");
			return 0;
		}
		else
		{
			q = p->link;
			p->link = q->link;
		}
		if(q==last) p = last;
		return 1;
	}
}