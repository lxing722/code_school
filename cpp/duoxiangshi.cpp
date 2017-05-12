#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
	int coef;
	int expn;
	struct node *next;
} Node;
typedef Node *ListNode;
enum status{OK,ERROR};
ListNode CreatePoly(void);
void InsertList(ListNode head,int coef,int expn);
float AddData(ListNode head,int arry[],float x);

int main(void)
{
	ListNode ha,p;
	int test[4] = {1,2,3,4};
	float x = 2.5;
	ha = CreatePoly();
	for(int i=0;i<4;i++)
	{
		InsertList(ha,test[i],i);
	}
	p = ha->next;
	while(p!=NULL)
	{
		printf("%d,%d\n",p->coef,p->expn);
		p = p->next;
	}

	printf("sum = %f",AddData(ha,test,x));
	return OK;
}

ListNode CreatePoly(void)
{
	ListNode first;
	first = (Node *)malloc(sizeof(Node));
	first->coef = 0;
	first->expn = -1;
	first->next = NULL;
	return first;
}
void InsertList(ListNode head,int coef,int expn)
{
	ListNode p,q;
	q = (Node *)malloc(sizeof(Node));
	p = head;				//容易搞混的地方
	while(p->next!=NULL) 
	{
		p = p->next; 
	}
	p->next = q;
	q->coef = coef;
	q->expn = expn;
	q->next = NULL;
}
float AddData(ListNode head,int arry[],float x)
{
	ListNode p;
	int n;
	float sum;
	n = sizeof(arry)/sizeof(arry[0]);
	for(int i=0;i<n-1;i++)
	{
		InsertList(head,arry[i],i);
	}
	sum = 0.0;
	p = head->next;
	while(p!=NULL)
	{
		sum += (p->coef)*pow(x,p->expn);
		p = p->next;
	}
	return sum;
}