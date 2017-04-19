#include<stdio.h>
#include<stdlib.h>
typedef int QElemType;
typedef struct node
{
	QElemType data;
	struct node *next;
}Qnode,*QueuePtr;
typedef struct queue
{
	QueuePtr front;
	QueuePtr rear;
} *LinkQueue;
int InitQ(LinkQueue Q);
int DestroyQ(LinkQueue Q);
int EnQueue(LinkQueue Q,QElemType x);
int DelNode(LinkQueue Q);

int main(void)
{
	LinkQueue test;
	test = (LinkQueue)malloc(sizeof(struct queue));
	InitQ(test);
	for(int i=0;i<6;i++) 
		EnQueue(test,i);
	QueuePtr head;
	head = test->front->next;
	while(head)
	{
		printf("%d\n",head->data);
		head = head->next;
	}
	DelNode(test);
	return 0;
}
int InitQ(LinkQueue Q)
{
	Q->front = (QueuePtr)malloc(sizeof(Qnode));
	if(!Q->front) exit(-1);
	Q->front->next = NULL;
	Q->rear = Q->front;
	return 0;
}
int DestroyQ(LinkQueue Q)
{
	while(!Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return 0;
}
int EnQueue(LinkQueue Q,QElemType x)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(Qnode));
	if(!p) exit(-1);
	p->data = x;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return 0;
}
int DelNode(LinkQueue Q)
{
	QueuePtr p;
	int m;
	if(Q->front == Q->rear) exit(-1);
	p = Q->front->next;
	m = p->data;
	Q->front->next = p->next;
	printf("%d\n",m);
	free(p);
	return 0;
}
