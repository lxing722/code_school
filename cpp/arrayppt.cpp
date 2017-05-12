#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#define AddSize 10
typedef int ElementType;
typedef struct
{
	ElementType *top;
	ElementType *base;
	int stacksize;
} *stack;
stack InitStack(void);
void Push(stack S,ElementType x);
void Pop(stack S);
ElementType top(stack S);

int main(void)
{
	stack test;
	test = InitStack();
	for(int i=0;i<5;i++)
		Push(test,i);
	printf("%d\n",top(test));
	Pop(test);
	printf("%d\n",top(test));
	return 0;
}

stack InitStack(void)
{
	stack S;
	S = (stack)malloc(sizeof(stack));
	S->base = (ElementType *)malloc(MaxSize*sizeof(ElementType));
	if(!S->base)
		exit(-1);
	S->top = S->base;
	S->stacksize = MaxSize;
	return S;
}
void Push(stack S,ElementType x)
{
	if((S->top-S->base)>=S->stacksize)
	{
		S->base = (ElementType *)realloc(S->base,(MaxSize+AddSize)*sizeof(ElementType));
	    if(!S->base)
		exit(-1);
	    S->top = S->base+S->stacksize;
	    S->stacksize += AddSize;
	}
	*S->top++ = x;
}
void Pop(stack S)
{
	if(S->top == S->base)
	{
		puts("Empty stack!");
		exit(-1);
	}
	S->top--;
}
ElementType top(stack S)
{
	if(S->top == S->base)
	{
		puts("Empty stack!");
		exit(-1);
	}
	return *(S->top-1);
}
    