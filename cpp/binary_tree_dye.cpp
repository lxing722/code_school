#include<stdio.h>
#include<stdlib.h>
int b=3,c=3;
int num[3];
typedef int BinTreeData;
typedef struct node
{
	BinTreeData data;
	struct node *leftChild,*rightChild;
} *BinTree;
void CreateTree(BinTree &T);
void PreOrder(BinTree T);

int main(void)
{
	BinTree test=NULL;
	CreateTree(test);
	PreOrder(test);
	int min=num[0],max=num[0];
	for(int i=0;i<3;i++)
	{
		if(num[i]<min)
			min = num[i];
		if(num[i]>max)
			max = num[i];
	}
	printf("%d %d\n",max,min);
	return 0;
}

void CreateTree(BinTree &T)
{
	if(!(T = (BinTree)malloc(sizeof(struct node))))
		exit(-1);
	char ch;
	if(b!=c)
	{
		if((b==0&&c==2)||(b==2&&c==0))
			T->data = 1;
		else if((b==1&&c==0)||(b==0&&c==1))
			T->data = 2;
		else
			T->data = 0;
	}
	else
	{
		if(c == 0)
			T->data = 1;
		else
			T->data = 0;
	}
	b = c = T->data;
	if((ch = getchar()) != '\n')
	{		
		switch(ch)
		{
			case '0':				
				T->leftChild = NULL;
				T->rightChild = NULL;
				break;
			case '1':
				CreateTree(T->leftChild);
				T->rightChild = NULL;
				break;
			case '2':
				//c = T->data; 不能在这里，影响后续判断
				CreateTree(T->leftChild);
				c = T->data;
				b = T->leftChild->data;
				CreateTree(T->rightChild);
				break;
		}
	}
}
void PreOrder(BinTree T)
{
	if(T)
	{
		num[T->data]++;
		PreOrder(T->leftChild);
		PreOrder(T->rightChild);
	}
}

