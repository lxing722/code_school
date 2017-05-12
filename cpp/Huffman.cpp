#include<stdio.h>

const int n = 4;
const int m = 2*n-1;
typedef struct {
	int weight;
	int parent,leftchild,rightchild;
} HTNode;
typedef HTNode HuffmanTree[m];

void CreateHuffmanTree(HuffmanTree T,int fr[])
{
	for(int i=0;i<n;i++)
		T[i].weight = fr[i];
	for(int i=0;i<m;i++)
	{
		T[i].parent = -1;
		T[i].leftchild = -1;
		T[i].rightchild = -1;
	}
	int MaxNum=fr[0];
	int pos = 0;
	for(int i=n;i<m;i++)
	{
		int min1,min2;
		int pos1,pos2;
		pos1 = pos2 = pos;
		min1 = min2 = MaxNum;
		for(int j=0;j<i;j++)
		{
			if(T[j].parent == -1)
			{
				if(T[j].weight < min1)
				{
					pos2 = pos1,min2 = min1;
					pos1 = j,min1 = T[j].weight;
				}
				else if(T[j].weight < min2)
				{
					pos2 = j;
					min2 = T[j].weight;
				}
			}
		}
		T[i].weight = T[pos1].weight + T[pos2].weight;
		T[pos1].parent = T[pos2].parent = i;
		T[i].leftchild = pos1,T[i].rightchild = pos2;
		if(T[i].weight>MaxNum)
		{
			MaxNum = T[i].weight;
		    pos = i;
		}
	}
}

int main(void)
{
	HuffmanTree test;
	int test2[n]={7,4,2,5};
	//for(int i=0;i<n;i++)
		//printf("%d\n",test2[i]);
	CreateHuffmanTree(test,test2);
	for(int i=0;i<m;i++)
		printf("%d %d %d %d\n",test[i].weight,test[i].parent,test[i].leftchild,test[i].rightchild);
	return 0;
}