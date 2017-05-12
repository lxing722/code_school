#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct hash
{
	ElemType elem[100];
	int count;
	int sizeindex;
} HashTable;
void CreateHash(HashTable &H);
int Hash(int key);
void collision(int &p,int c);
int Search(HashTable H,int key);

int main(void)
{
	HashTable test;
	CreateHash(test);
	printf("%d\n",Search(test,29));
	return 0;
}

void CreateHash(HashTable &H)
{
	int num,count,p;
	H.count = 11;
	H.sizeindex = 13;
	for(int i=0;i<H.sizeindex;i++)
	{
		H.elem[i] = -1;
	}
	for(int i=0;i<H.count;i++)
	{
		scanf("%d",&num);
		p = Hash(num);
		while(H.elem[p]!=-1)
		{
			collision(p,1);
		}
		H.elem[p] = num;
	}
}

int Hash(int key)
{
	return key%13;
}
void collision(int &p,int c)
{
	p = (p+c)%13;
}
int Search(HashTable H,int key)
{
	int p;
	p = Hash(key);
	while(H.elem[p]!=-1&&H.elem[p]!=key)
		collision(p,1);
	if(H.elem[p]==key)
		return 1;
	else
		return 0;
}
