#include<stdio.h>					
#include<stdlib.h>
#define MinStackSize 5
typedef int ElementType;
typedef struct node
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
} *stack;
int IsEmpty(stack S);
int IsFull(stack S);
stack CreateStack(int max);
void Push(stack S,ElementType x);
ElementType Top(stack S);
void Pop(stack S);

int main(void)
{
	stack test;
	test = CreateStack(5);
	for(int i=0;i<5;i++)
		Push(test,i);
	for(int i=0;i<5;i++)
		printf("%d\n",test->Array[i]);
	Pop(test);
	Pop(test);
	return 0;
}

stack CreateStack(int max)
{
	stack S;
	if(max < MinStackSize)
	{
		puts("The stack size is too small!");			//c语言不是python，两行及以上要用大括号括起来，不然只执行条件中的第一个语句
		exit(-1);
	}
	S = (struct node *)malloc(sizeof(struct node));
	if(S == NULL)
	{
		puts("Out of space!!");
		exit(-1);
	}
	S->Array = (ElementType *)malloc(max*sizeof(ElementType));
	if(S->Array == NULL)
	{
		puts("Out of space!!");
		exit(-1);
	}
	S->Capacity = max;
	S->TopOfStack = -1;
	return S;
}
int IsEmpty(stack S)
{
	return S->TopOfStack == -1;
}
int IsFull(stack S)
{
	return S->TopOfStack == S->Capacity-1;
}

void Push(stack S,ElementType x)
{
	if(S == NULL)
	{
		puts("You have to cteate a stack first!");
		exit(-1);
	}
	if(!IsFull(S))
		S->Array[++S->TopOfStack] = x;
}
ElementType Top(stack S)
{
	if(S->TopOfStack == -1)
	{
		puts("Empty stack!");
		exit(-1);
	}
	return S->Array[S->TopOfStack];
}
void Pop(stack S)
{
	if(IsEmpty(S))
	{
		puts("Empty stack!");
		exit(-1);
	}
	printf("%d\n",Top(S));
	S->TopOfStack--;
}
