#include<stdio.h>
#define MaxSize 20
typedef struct {
	int Key;
}Redtype;
typedef struct {
	Redtype r[MaxSize + 1];
	int length;
}Sqlist;
void InitSqlist(Sqlist &L, int n);
void InsertSort(Sqlist &L);
int main(void)
{
	Sqlist test;
	int n;
	scanf_s("%d", &n);
	InitSqlist(test, n);
	InsertSort(test);
	for (int i = 1; i <= test.length; i++)
		printf("%d\n", test.r[i].Key);
	return 0;
}
void InitSqlist(Sqlist &L,int n)
{
	L.length = n;
	L.r[0].Key = -1000;
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &L.r[i].Key);
	}
}
void InsertSort(Sqlist &L)
{
	int i, j;
	for (i = 2; i <= L.length; i++)
	{
		if (L.r[i].Key < L.r[i - 1].Key)
		{
			L.r[0].Key = L.r[i].Key;
			for (j = i - 1; L.r[j].Key > L.r[0].Key; j--)
				L.r[j + 1].Key = L.r[j].Key;
			L.r[j + 1].Key = L.r[0].Key;
		}
	}
}