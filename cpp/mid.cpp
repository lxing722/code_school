#include<stdio.h>
#include<stdlib.h>
typedef int KeyType;
typedef struct
{
	int key;
}ElemType;
typedef struct
{
	ElemType *elem;
	int length;
} SSTable;
void Create(SSTable &T);
int Search(SSTable T,KeyType kval);
int Search_Bin(SSTable T,KeyType kval);

int main(void)
{
	SSTable test;
	Create(test);
	printf("%d\n",Search_Bin(test,21));
	return 0;
}

void Create(SSTable &T)
{
	T.length = 11;
	T.elem = (ElemType *)malloc(sizeof(ElemType));
	for(int i=0;i<11;i++)
	{
		scanf("%d",&T.elem[i].key);
	}
}

int Search(SSTable T,KeyType kval)
{
	int i;
	T.elem[0].key = kval;
	for(i=T.length;T.elem[i].key != kval;--i);
	return i;
}

int Search_Bin(SSTable T,KeyType kval)
{
	int low = 0,high = T.length-1,mid;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(T.elem[mid].key == kval)
			return mid;
		else if(kval < T.elem[mid].key)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}