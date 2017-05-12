#include<stdio.h>
#include<stdlib.h>
typedef int ListData;
typedef struct node{
	ListData data;
	struct node *link;
} ListNode;			//定义节点
ListNode *first,*last;			//定义第一个节点和最后一个节点
int ListInsert(ListData x,int i);
int ListRemove(int m);
int Joseph(int n,int m,int s);

int main(void)
{
	int n,m,s;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Enter m:");
	scanf("%d",&m);
	printf("Enter s:");
	scanf("%d",&s);
	printf("########### Solve Joseph Problem　#############\n");
	Joseph(n,m,s);
	printf("##################### End　####################\n");
	return 0;
}

int ListInsert(ListData x,int i)		//定义一个函数用于插入节点
{
	ListNode *p;
	p = first;
	for(int k=0;k<i-1;k++)		//找到第i-1个节点
	{
		if(p==NULL) break;
		else p = p->link;
	}
	if(p==NULL&&first!=NULL)
	{
		printf("无效的插入位置！\n");
		return 0;
	}
	ListNode *newnode;		//定义一个新节点
	newnode = (ListNode *)malloc(sizeof(ListNode));
	if(first==NULL||i==0)		//插在表头
	{
		newnode->data = x;
		newnode->link = first;
		if(first==NULL) last = newnode;
		first = newnode;
	}
	else			//插在表中或表尾
	{
		newnode->data = x;
		newnode->link = p->link;
		if(p->link==NULL) last = newnode;
		p->link = newnode;
	}
	return 0;
}
int ListRemove(int m)			//定义一个函数删除第m个节点
{
	ListNode *p,*temp;
	p = first;
	if(m==1)
	{
		p = last;
	}
	for(int i=0;i<m-2;i++)				//找到第m-1个节点
	{
		p = p->link;
	}
	temp = p->link;					//删除第m个节点
	p->link = temp->link;
	last = p;
	first = p->link;	
	printf("Number %d is out!\n",temp->data);
	free(temp);
	return 0;
}
int Joseph(int n,int m,int s)
{
	int a;
	a = 1;
	for(int i=0;i<n;i++)			//插入n个节点
	{
		ListInsert(a,i);
		a++;
	}
	last->link = first;				//构成单循环链表
	for(int i=0;i<s-1;i++)			//将first移动到第s个节点
	{
		first = first->link;
	}
	while(n>1)			//删除第m个节点知道剩余一个节点
	{
		ListRemove(m);
		n--;
	}
	printf("The winner is number %d!\n",first->data);
	return 0;
}