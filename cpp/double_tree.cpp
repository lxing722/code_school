#include<stdio.h>
#include<stdlib.h>
typedef char BinTreeData;
typedef struct node	//定义树节点
{
	BinTreeData data;
	struct node *leftChild,*rightChild;
} *BinTree;
void CreateTree(BinTree &T);
void Double(BinTree T);
int main(void)
{
	BinTree test;
	CreateTree(test);
	Double(test);
	printf("\n");
	return 0;
}

void CreateTree(BinTree &T)	//前序建立二叉树
{
	char ch;
	ch = getchar();
	if(ch == '@')
		T = NULL;
	else
	{
		if(!(T = (BinTree)malloc(sizeof(struct node))))
			exit(-1);
		else
		{
			T->data = ch;
			CreateTree(T->leftChild);
			CreateTree(T->rightChild);
		}
	}	
}
void Double(BinTree T)	//双序遍历二叉树
{
	if(T)
	{
		printf("%c",T->data);
		Double(T->leftChild);
		if(T->leftChild||T->rightChild) //判断是否为结点
			printf("%c",T->data);
		Double(T->rightChild);
	}
}