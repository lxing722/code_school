#include<stdio.h>
#include<stdlib.h>
typedef int BinTreeData;
typedef int KeyType;
typedef struct node
{
	BinTreeData data;
	struct node *leftChild,*rightChild;
} BinTreeNode;
typedef BinTreeNode *BinTree;

void CreateTree(BinTree &T)
{
	int ch;
	scanf("%d",&ch);
	if(ch == -1) 
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
int SearchBST(BinTree T,KeyType kval,BinTree f,BinTree &p)
{
	if(!T)
	{
		p = f;
		return 0;
	}
	else if(kval == T->data)
		return 1;
	else if(kval < T->data)
		return SearchBST(T->leftChild,kval,T,p);
	else
		return SearchBST(T->rightChild,kval,T,p);
}
int Insert(BinTree T,int e)
{
	BinTree p;
	if(SearchBST(T,e,NULL,p) == 0)
	{
		BinTreeNode *s;
		if(!(s = (BinTreeNode*)malloc(sizeof(BinTreeNode))))
			exit(-1);
		s->data = e;
		s->leftChild = s->rightChild = NULL;
		if(!p) T = s;
		else if(e < p->data)
			p->leftChild = s;
		else
			p->rightChild = s;
		return 1;
	}
	return 0;
}
int main(void)
{
	BinTree test,f = NULL,p;
	CreateTree(test);
	printf("%d\n",SearchBST(test,85,f,p));
	printf("%d\n",Insert(test,85));
	printf("%d\n",SearchBST(test,85,f,p));
	return 0;
}