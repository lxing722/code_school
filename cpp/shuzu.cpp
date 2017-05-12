#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MaxSize 7
typedef struct node
{
	int *base;
	int front;
	int rear;
} *Queue;
void InitQ(Queue Q);
void EnQueue(Queue Q,int x);
void DelQueue(Queue Q);

int main(void)
{
	Queue test;
	test = (Queue)malloc(sizeof(struct node));
	InitQ(test);
	printf("%d\n",test->front);
	for(int i=0;i<6;i++)
		EnQueue(test,i);
	DelQueue(test);
	for(int j=0;j<4;j++)
		printf("%d\n",test->base[j]);
	return 0;
}

void InitQ(Queue Q)
{
	Q->base = (int *)malloc(MaxSize*sizeof(int));
	if(!Q->base) exit(-1);
	Q->front = Q->rear =0;
}
void EnQueue(Queue Q,int x)
{
	if((Q->rear+1)%MaxSize == Q->front)
		exit(-1);
	Q->base[Q->rear] = x;
	Q->rear = (Q->rear+1)%MaxSize;
}
void DelQueue(Queue Q)
{
	if(Q->rear == Q->front)
		exit(-1);
	printf("%d\n",Q->base[Q->front]);
	Q->front = (Q->front+1)%MaxSize;
}
