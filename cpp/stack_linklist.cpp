#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int ElementType;
typedef struct node *PtrToNode;
typedef PtrToNode stack;
typedef struct node
{
	ElementType element;
	PtrToNode next;
};
int IsEmpty(stack S);
stack CreatStack(void);
void MakeEmpty(stack S);
void Push(stack S,ElementType x);
void Pop(stack S);

int main(void)
{
	stack test,current;
	test = CreatStack();
	for(int i=0;i<5;i++)
		Push(test,i);
	current = test->next;
	while(current!=NULL)
	{
		printf("%d\n",current->element);
		current = current->next;
	}
	Pop(test);
	return 0;
}

int IsEmpty(stack S)
{
	return S->next == NULL;
}
stack CreatStack(void)
{
	stack S;
	S = (PtrToNode)malloc(sizeof(PtrToNode));
	if(S == NULL)
		exit(-1);
	S->next = NULL;
	S->element = 0;
	return S;
}

void MakeEmpty(stack S)
{
	if(S == NULL)
		exit(-1);
	while(!IsEmpty(S))
		Pop(S);
}
void Push(stack S,ElementType x)
{
	PtrToNode TmpCell;
	TmpCell = (PtrToNode)malloc(sizeof(PtrToNode));
	if(TmpCell == NULL)
		exit(-1);
	TmpCell->element = x;
	TmpCell->next = S->next;
	S->next = TmpCell;
}
int Top(stack S)
{
	if(S->next == NULL)
		exit(-1);
	return S->next->element;
}
void Pop(stack S)
{
	PtrToNode FirstCell;
	if(S->next == NULL)
		exit(-1);
	FirstCell = S->next;
	printf("%d\n",FirstCell->element);
	S->next = S->next->next;
	//free(FirstCell);
}