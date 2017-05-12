#include<stdio.h>
#include<stdlib.h>
typedef char BinTreeData;
typedef struct node
{
	BinTreeData data;
	struct node *leftChild,*rightChild;
} BinTreeNode;
typedef BinTreeNode *BinTree;

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

void InOrder(BinTree T)
{
	if(T != NULL)
	{
		InOrder(T->leftChild);
		printf("%c\n",T->data);
		InOrder(T->rightChild);
	}
}

void PreOrder(BinTree T)
{
	if(T != NULL)
	{
		printf("%c\n",T->data);
		PreOrder(T->leftChild);
		PreOrder(T->rightChild);
	}
}

void PostOrder(BinTree T)
{
	if(T != NULL)
	{
		PostOrder(T->leftChild);
		PostOrder(T->rightChild);
		printf("%c\n",T->data);
	}
}

int Count(BinTree T)
{
	if(T == NULL) return 0;
	else return 1+Count(T->leftChild)+Count(T->rightChild);
}

int Leaf_Count(BinTree T)
{
	if(!T) return 0;
	else if(!T->leftChild&&!T->rightChild) return 1;
	else return Leaf_Count(T->leftChild)+Leaf_Count(T->rightChild);
}

int Height(BinTree T)
{
	if(!T) return 0;
	else
	{
		int m = Height(T->leftChild);
		int n = Height(T->rightChild);
		return (m>n)?m+1:n+1;
	}
}

BinTree Copy(BinTree T)
{
	BinTree temp;
	if(!T) return NULL;
	if(!(temp = (BinTree)malloc(sizeof(struct node))))
		exit(-1);
	temp->data = T->data;
	temp->leftChild = Copy(T->leftChild);
	temp->rightChild = Copy(T->rightChild);
	return temp;
}

int Equal(BinTree a,BinTree b)
{
	if(!a&&!b) return 1;
	if(a&&b&&a->data == b->data&&Equal(a->leftChild,b->leftChild)&&Equal(a->rightChild,b->rightChild))
		return 1;
	return 0;
}

int main(void)
{
	BinTree test,test1;
	int nodes;
	CreateTree(test);
	InOrder(test);
	nodes = Count(test);
	printf("%d\n",nodes);
	printf("%d\n",Leaf_Count(test));
	printf("%d\n",Height(test));
	test1 = Copy(test);
	InOrder(test);
	printf("%d\n",Equal(test,test1));
	//PostOrder(test);
	return 0;
}