#include<stdio.h>
#include<stdlib.h>
typedef char BinTreeData;
typedef struct node	//�������ڵ�
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

void CreateTree(BinTree &T)	//ǰ����������
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
void Double(BinTree T)	//˫�����������
{
	if(T)
	{
		printf("%c",T->data);
		Double(T->leftChild);
		if(T->leftChild||T->rightChild) //�ж��Ƿ�Ϊ���
			printf("%c",T->data);
		Double(T->rightChild);
	}
}