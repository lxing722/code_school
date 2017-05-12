#include<stdio.h>
#define MaxSize 20
#define MaxValue 200
typedef int EdgeData;
typedef struct graph
{
	int n;
	EdgeData Edge[5][5];
} MTGraph;

int main(void)
{

}

void CreateGraph(MTGraph &G)
{
	G.n = 5;
	G.Edge = {{-1,10,-1,30,100},
					{-1,-1,50,-1,-1},
					{-1,-1,-1,20,10},
					{-1,-1,20,-1,60},
					{-1,-1,-1,-1,-1}};

