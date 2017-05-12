#include<stdio.h>
#include<stdlib.h>
typedef char BinTreeData;
typedef struct node
{
	BinTreeData data;
	struct node *leftChild,*rightChild;
} BinTreeNode;
typedef BinTreeNode *BinTree;
typedef struct node
{
	BinTree e;
	struct node *next;
} *Stack;

void InitStack(Stack S)
{
	if(S)
		exit(-1);
	S = (Stack)malloc(sizeof(struct node));
	S->e = NULL;
	S->next = NULL;
}
void Push(Stack S,BinTree e)
{
	struct node *temp;
	temp = (Stack)malloc(sizeof(struct node));

void CreateTree(BinTree &T)
{
	char ch;
	ch = getchar();
	if(ch == '@') 
		T = NULL;
	else
	{
		if(!(T = (BinTree)malloc(sizeof(BinTreeNode))))
			exit(-1);
		T->data = ch;
		CreateTree(T->leftChild);
		CreateTree(T->rightChild);
	}
}