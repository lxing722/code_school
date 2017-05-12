#include<stdio.h>
#include<stdlib.h>
typedef int ListData;
typedef struct node{
	ListData data;
	struct node *link;
} ListNode;			//����ڵ�
ListNode *first,*last;			//�����һ���ڵ�����һ���ڵ�
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
	printf("########### Solve Joseph Problem��#############\n");
	Joseph(n,m,s);
	printf("##################### End��####################\n");
	return 0;
}

int ListInsert(ListData x,int i)		//����һ���������ڲ���ڵ�
{
	ListNode *p;
	p = first;
	for(int k=0;k<i-1;k++)		//�ҵ���i-1���ڵ�
	{
		if(p==NULL) break;
		else p = p->link;
	}
	if(p==NULL&&first!=NULL)
	{
		printf("��Ч�Ĳ���λ�ã�\n");
		return 0;
	}
	ListNode *newnode;		//����һ���½ڵ�
	newnode = (ListNode *)malloc(sizeof(ListNode));
	if(first==NULL||i==0)		//���ڱ�ͷ
	{
		newnode->data = x;
		newnode->link = first;
		if(first==NULL) last = newnode;
		first = newnode;
	}
	else			//���ڱ��л��β
	{
		newnode->data = x;
		newnode->link = p->link;
		if(p->link==NULL) last = newnode;
		p->link = newnode;
	}
	return 0;
}
int ListRemove(int m)			//����һ������ɾ����m���ڵ�
{
	ListNode *p,*temp;
	p = first;
	if(m==1)
	{
		p = last;
	}
	for(int i=0;i<m-2;i++)				//�ҵ���m-1���ڵ�
	{
		p = p->link;
	}
	temp = p->link;					//ɾ����m���ڵ�
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
	for(int i=0;i<n;i++)			//����n���ڵ�
	{
		ListInsert(a,i);
		a++;
	}
	last->link = first;				//���ɵ�ѭ������
	for(int i=0;i<s-1;i++)			//��first�ƶ�����s���ڵ�
	{
		first = first->link;
	}
	while(n>1)			//ɾ����m���ڵ�֪��ʣ��һ���ڵ�
	{
		ListRemove(m);
		n--;
	}
	printf("The winner is number %d!\n",first->data);
	return 0;
}