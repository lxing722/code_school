#include<stdio.h>
#include<stdlib.h>
typedef int ListData;
typedef struct node				//����ڵ�
{
	ListData data,freq;
	struct node *prior,*next;
} ListNode;
ListNode *first;
int ListInsert(ListData x,int i);
int Locate(int n,ListData x);

int main(void)
{
	first = (ListNode *)malloc(sizeof(ListNode));		//������ͷ
	first->prior = first->next = first;
	int n,l;
	ListData m;
	ListNode *curr;
	printf("Please input the link list length:");		//ȷ��������
	scanf("%d",&l);
	n=1;
	for(int i=1;i<l+1;i++)			//����ڵ�
	{
		ListInsert(n,i);
		n++;
	}
	printf("The link list data are\n");			//��ӡ��������
	curr = first->next;
	for(int i=0;i<l;i++)
	{
		printf("The node data is %d,its frequency is %d.\n",curr->data,curr->freq);
		curr = curr->next;
	}
	printf("Let's start to test Locate Function.(-1 means stopping input number)\n");			//��ʼ����Locate����
	printf("Please input the number:");
	scanf("%d",&m);
	while(m!=-1)
	{		
		Locate(n-1,m);
		printf("Please input the number:");
		scanf("%d",&m);
	}
	printf("After test,the link list data are\n");			//����֮�󣬰�Ƶ����ӡ����
	curr = first->next;
	for(int i=0;i<l;i++)
	{
		printf("The node data is %d,its frequency is %d.\n",curr->data,curr->freq);
		curr = curr->next;
	}
	return 0;
}
int ListInsert(ListData x,int i)			//�������ڵ㺯������iλ�ò���ڵ㣬����ֵΪx
{
	ListNode *p,*q;
	p = first;
	for(int k=0;k<i-1;k++)			//�ҵ���i-1���ڵ�
	{
		p = p->next;
	}
	q = (ListNode *)malloc(sizeof(ListNode));			//����ڵ�
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
	while(i<n&&a->data!=x)		//�ж�x���������Ƿ����
	{
		i++;
		a = a->next;
	}
	if(i<n)			//x������������
	{
		a->freq++;		//xƵ����1
		current = a;		//��������ժ���ڵ�
		current->prior->next = current->next;
		current->next->prior = current->prior;
		a = current->prior;
		while(a!=first&&current->freq > a->freq)		//���ڵ㰴Ƶ������
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


