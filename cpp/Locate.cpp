#include<stdio.h>
#include<stdlib.h>
typedef int ListData;
typedef struct node				//定义节点
{
	ListData data,freq;
	struct node *prior,*next;
} ListNode;
ListNode *first;
int ListInsert(ListData x,int i);
int Locate(int n,ListData x);

int main(void)
{
	first = (ListNode *)malloc(sizeof(ListNode));		//创建表头
	first->prior = first->next = first;
	int n,l;
	ListData m;
	ListNode *curr;
	printf("Please input the link list length:");		//确定链表长度
	scanf("%d",&l);
	n=1;
	for(int i=1;i<l+1;i++)			//插入节点
	{
		ListInsert(n,i);
		n++;
	}
	printf("The link list data are\n");			//打印链表数据
	curr = first->next;
	for(int i=0;i<l;i++)
	{
		printf("The node data is %d,its frequency is %d.\n",curr->data,curr->freq);
		curr = curr->next;
	}
	printf("Let's start to test Locate Function.(-1 means stopping input number)\n");			//开始测试Locate函数
	printf("Please input the number:");
	scanf("%d",&m);
	while(m!=-1)
	{		
		Locate(n-1,m);
		printf("Please input the number:");
		scanf("%d",&m);
	}
	printf("After test,the link list data are\n");			//测试之后，按频数打印链表
	curr = first->next;
	for(int i=0;i<l;i++)
	{
		printf("The node data is %d,its frequency is %d.\n",curr->data,curr->freq);
		curr = curr->next;
	}
	return 0;
}
int ListInsert(ListData x,int i)			//定义插入节点函数，在i位置插入节点，其数值为x
{
	ListNode *p,*q;
	p = first;
	for(int k=0;k<i-1;k++)			//找到第i-1个节点
	{
		p = p->next;
	}
	q = (ListNode *)malloc(sizeof(ListNode));			//插入节点
	q->data = x;
	q->freq = 0;
	q->next = p->next;
	p->next = q;
	q->prior = p;	
	q->next->prior = q;	
	return 0;
}
int Locate(int n,ListData x)
{
	ListNode *current,*a;
	int i;
	i = 0;
	a = first->next;
	while(i<n&&a->data!=x)		//判断x在链表中是否存在
	{
		i++;
		a = a->next;
	}
	if(i<n)			//x存在于链表中
	{
		a->freq++;		//x频数加1
		current = a;		//从链表中摘除节点
		current->prior->next = current->next;
		current->next->prior = current->prior;
		a = current->prior;
		while(a!=first&&current->freq > a->freq)		//将节点按频数排列
		{
			a = a->prior;
		}
		current->next = a->next;
		a->next = current;
		current->prior = a;		
		current->next->prior = current;
	}
	else
	{
		printf("Wrong data!\n");
	}
	
	return 0;
}


