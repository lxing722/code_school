#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MinStackSize 5
typedef char ElementType;
typedef struct StackNode		//定义栈结构体
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
} *stack;
struct Graph
{
	int nodes = 9;
	char V[9] = { 'A','B','C','D','E','F','G','H','I' }; //保存图中顶点的值
	int E[9][9] = { { 0,40,120,130,140,0,0,100,0 },
	{ 40,0,150,0,45,0,0,0,0 },
	{ 120,150,0,60,0,70,75,80,160 },
	{ 130,0,60,0,50,0,75,0,0 },
	{ 140,45,0,50,0,0,65,0,0 },
	{ 0,0,70,0,0,0,120,120,130 } ,
	{ 0,0,75,75,65,120,0,0,100 } ,
	{ 100,0,80,0,0,120,0,0,0 } ,
	{ 0,0,160,0,0,130,100,0,0 } }; //图的邻接矩阵
};
struct paths {		//用于保存路径节点，路径节点个数，路径总权值
	int num;
	int cost;
	char vex[100];
};
paths all_paths[1000];
int length = 0;
stack CreateStack(int max)	//创建最大容量为max的栈
{
	stack S;
	if (max < MinStackSize)
	{
		puts("The stack size is too small!");			//c语言不是python，两行及以上要用大括号括起来，不然只执行条件中的第一个语句
		exit(-1);
	}
	S = (struct StackNode *)malloc(sizeof(struct StackNode));
	if (S == NULL)
	{
		puts("Out of space!!");
		exit(-1);
	}
	S->Array = (ElementType *)malloc(max * sizeof(ElementType));
	if (S->Array == NULL)
	{
		puts("Out of space!!");
		exit(-1);
	}
	S->Capacity = max;
	S->TopOfStack = -1;
	return S;
}
int IsEmpty(stack S)	//判断栈是否空
{
	return S->TopOfStack == -1;
}
int IsFull(stack S)		//判断栈是否满
{
	return S->TopOfStack == S->Capacity - 1;
}
int IsIn(ElementType p, stack S) //判断元素p是否在栈S中
{
	for (int k = 0; k <= S->TopOfStack; k++)
	{
		if (S->Array[k] == p)
			return 1;
	}
	return 0;
}
void Push(stack S, ElementType x)	//入栈
{
	if (S == NULL)
	{
		puts("You have to cteate a stack first!");
		exit(-1);
	}
	if (!IsFull(S))
		S->Array[++S->TopOfStack] = x;
}
void Pop(stack S)	//出栈
{
	if (IsEmpty(S))
	{
		puts("Empty stack!");
		exit(-1);
	}
	S->TopOfStack--;
}
using namespace std;
Graph G;
stack path = CreateStack(10);; //用于保存遍历过程中所走过的节点点值
void DFS(char B, char E) //深度遍历图，B为起点，E为终点
{
	Push(path,B); //保存顶点值到栈中
	if (E == B) //如果找到了终点，则保存路径
	{
		int i;
		for (i = 0; i <= path->TopOfStack; i++)
		{
			all_paths[length].vex[i] = path->Array[i];
			if (i < path->TopOfStack)
			{
				int index1,index2;
				for (index1 = 0; G.V[index1] != path->Array[i]; index1++);
				for (index2 = 0; G.V[index2] != path->Array[i+1]; index2++);
				all_paths[length].cost += G.E[index1][index2];
			}
		}
		all_paths[length].num = i + 1;
		length++;
		Pop(path); //返回上一层时删除栈顶值
		return;
	}
	//如果未找到终点，继续深度遍历
	int index;
	for (index = 0; G.V[index] != B; index++);
	for (int j = 0; j < G.nodes; j++)
	{
		if (IsIn(G.V[j],path))
			continue; //如果 j 所对应的节点在栈中，就不遍历该节点，否则遍历
		if (G.E[index][j] != 0)
			DFS(G.V[j], E);
	}
	Pop(path); //返回上一层时删除栈顶值
}
void Swap(int i, int j)		//交换下标为i，j之间的路径
{
	int temp_num = all_paths[i].num, temp_cost = all_paths[i].cost;
	char temp_vex[10];
	for (int k = 0; k < all_paths[i].num; k++)
		temp_vex[k] = all_paths[i].vex[k];
	all_paths[i].num = all_paths[j].num, all_paths[i].cost = all_paths[j].cost;
	for (int k = 0; k < all_paths[j].num; k++)
		all_paths[i].vex[k] = all_paths[j].vex[k];
	all_paths[j].num = temp_num, all_paths[j].cost = temp_cost;
	for (int k = 0; k < temp_num; k++)
		all_paths[j].vex[k] = temp_vex[k];
}
void BubbleSort_Cost()		//根据总权值进行冒泡排序
{
	int i = 0;
	int exchange = 1;
	while (i < length && exchange)
	{
		exchange = 0;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (all_paths[j].cost > all_paths[j+1].cost)
			{
				Swap(j,j + 1);
				exchange = 1;
			}
		}
		i++;
	}
}
void BubbleSort_num()	//根据节点个数进行冒泡排序
{
	int i = 0;
	int exchange = 1;
	while (i < length && exchange)
	{
		exchange = 0;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (all_paths[j].num > all_paths[j + 1].num)
			{
				Swap(j, j + 1);
				exchange = 1;
			}
		}
		i++;
	}
}
int main(void)
{
	char start, end;
	cout << "请输入您的的起始站点：" << endl;
	cin >> start;
	cout << "请输入您的的目的站点：" << endl;
	cin >> end;
	DFS(start, end);
	BubbleSort_Cost();
	cout << "路程最短：" << endl;
	for (int m = 0; m < length; m++)
	{
		if (all_paths[m].num <= 5 && all_paths[m].cost <= 2 * all_paths[0].cost)//选择输出换乘次数不多于两次，总路程不大于起始点和终点最短路程的两倍的路线
		{
			for (int n = 0; n < all_paths[m].num; n++)
				printf(" %c ", all_paths[m].vex[n]);
			printf("总路程%d公里  换乘%d次。\n", all_paths[m].cost, all_paths[m].num - 3);
		}
	}
	BubbleSort_num();
	cout << "换乘最少：" << endl;
	for (int m = 0; m < length; m++)
	{
		if (all_paths[m].num <= 5 && all_paths[m].cost <= 2 * all_paths[0].cost)
		{
			for (int n = 0; n < all_paths[m].num; n++)
				printf(" %c ", all_paths[m].vex[n]);
			printf("换乘%d次  总路程%d公里。\n", all_paths[m].num - 3, all_paths[m].cost);
		}
	}
	return 0;
}