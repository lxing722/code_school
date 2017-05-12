#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
	float coef;
	int expn;
	struct node *next;
} Node;
enum status{OK,ERROR};
Node *CreatePoly(void);
void InsertList(Node *head,int coef,int expn);
float AddData(Node *head,int arry[],float x);

int main(void)
{
	Node *ha,*p;
	int test[2] = {1,2};
	//int x = 1;
	ha = CreatePoly();
	for(int i=0;i<2;i++)
	{
		InsertList(ha,test[i],i);
	}
	p = ha->next;
	while(p!=NULL)
	{
		printf("%d,%d",p->coef,p->expn);
		p = p->next;
	}

	//printf("%f",AddData(ha,test,1));
	return OK;
}

Node *CreatePoly(void)
{
	Node *first;
	first = (Node *)malloc(sizeof(Node));
	first->coef = 0;
	first->expn = -1;
	first->next = NULL;
	return first;
}
void InsertList(Node *head,int coef,int expn)
{
	Node *p,*q;
	q = (Node *)malloc(sizeof(Node));
	p = head->next;
	while(p!=NULL) 
	{
		p = p->next; 
	}
	q = p->next;
	q->coef = coef;
	q->expn = expn;
	q->next = NULL;
}
float AddData(Node *head,int arry[],float x)
{
	Node *p;
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
	
