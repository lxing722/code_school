#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10000
typedef struct tri
{
	int i,j;
	int e;
} Triple; //此结构体不需要动态分配内存，不用设为指针类型
typedef struct
{
	Triple *data; //data要形成一个数组的形式，每一个单元又指向data结构体
	int mu,nu,tu;
} TSMatrix;
int Create(TSMatrix &T,int arry[][6]);
void ConvertTo(TSMatrix S,TSMatrix &T);
void FastConvert(TSMatrix S,TSMatrix &T);
int main(void)
{
	TSMatrix test1,test3;
	int test2[7][6] = {{0,0,0,0,91,0},
					   {0,11,0,0,0,0},
					   {0,0,0,0,0,28},
					   {22,0,-6,0,0,0},
					   {0,0,0,0,0,0},
					   {0,17,0,39,0,0},
					   {15,0,0,0,0,0}};
	test1.mu = 7,test1.nu = 6,test1.tu = 0;
	//for(int i=0;i<7;i++)
	//{
		//for(int j=0;j<6;j++)
			//printf("%d ",test2[i][j]);
		//printf("\n");
	//}
	Create(test1,test2);
	for(int i=0;i<test1.tu;i++)
		printf("%d\n",test1.data[i].e);
	FastConvert(test1,test3);
	for(int i=0;i<test3.tu;i++)
		printf("%d\n",test3.data[i].e);
	printf("%d\n",test1.tu);
	return 0;
}
int Create(TSMatrix &T,int arry[][6])
{
	T.data = (Triple *)malloc((MAXSIZE+1)*sizeof(struct tri));
	if(!T.data)
	{
		puts("ERROR!");
		exit(-1);
	}
	for(int i=0;i<T.mu;i++)
	{
		for(int j=0;j<6;j++)
		{
			//printf("%d ",arry[i][j]);
			if(arry[i][j]!=0)
			{
				T.data[T.tu].i = i;
				T.data[T.tu].j = j;
				T.data[T.tu].e = arry[i][j];
			    T.tu++;
			}
		}
		//printf("\n");
	}
	return 0;
}
void ConvertTo(TSMatrix S,TSMatrix &T)
{
	T.data = (Triple *)malloc((MAXSIZE+1)*sizeof(struct tri));
	T.tu = 0;
	for(int i=0;i<S.nu;i++)
	{
		for(int j=0;j<S.tu;j++)
		{
			if(S.data[j].j==i)
			{
				T.data[T.tu].e = S.data[j].e;
				T.data[T.tu].i = S.data[j].j;
				T.data[T.tu].j = S.data[j].i;
				T.tu++;
			}
		}
	}
}
void FastConvert(TSMatrix S,TSMatrix &T)
{
	int copt[100] = {0},num[100] = {0};
	T.data = (Triple *)malloc((MAXSIZE+1)*sizeof(struct tri));
	if(!T.data)
	{
		puts("ERROR!");
		exit(-1);
	}
	for(int i=0;i<S.tu;i++)
	{
		if(S.data[i].e!=0)
			num[S.data[i].j]++;
	}
	copt[0] = 0;
	for(int i=1;i<S.nu;i++)
		copt[i] = copt[i-1]+num[i-1];
	for(int i=0;i<S.tu;i++)
	{
		T.data[copt[S.data[i].j]].e = S.data[i].e;
		T.data[copt[S.data[i].j]].i = S.data[i].j;
		T.data[copt[S.data[i].j]].j = S.data[i].i;
		copt[S.data[i].j]++;
	}
	T.tu = S.tu;
}
