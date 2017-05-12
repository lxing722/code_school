#include<stdio.h>
#define MaxSize 100
typedef struct {
	int Edge[MaxSize][MaxSize] = { 10000 };
	int n, e;
} Graph;
typedef struct {
	int head, tail;
	int cost;
} MST;
void CreateGraph(Graph &G,int n);
void Prim(Graph G, MST T[], int n);
int main(void)
{
	while (true)
	{
		int v;
		scanf_s("%d", &v);
		if (v == 0)
			break;
		Graph test;
		MST T[MaxSize];
		CreateGraph(test,v);
		Prim(test, T, 1);
	}
	return 0;
}
void CreateGraph(Graph &G,int v)
{
	int m,n,build,cost;
	G.n = v;
	G.e = G.n*(G.n - 1) / 2;
	for (int i = 1; i < G.e + 1; i++)
	{
		scanf_s("%d %d %d %d", &m, &n, &cost, &build);
		G.Edge[i][i] = 0;
		if (build == 1)
			cost = 0;
		G.Edge[m][n] = cost;
		G.Edge[n][m] = cost;
	}
}
void Prim(Graph G, MST T[], int n)
{
	int lowcost[MaxSize];
	int nearvex[MaxSize];
	for (int i = 1; i < G.n+1; i++)
	{
		lowcost[i] = G.Edge[n][i];
		nearvex[i] = n;
	}
	nearvex[n] = -1;
	int k = 0;
	for (int i = 1; i < G.n+1; i++)
	{
		if (i != n)
		{
			int min = 999, v = 0;
			for (int j = 1; j < G.n+1; j++)
			{
				if (nearvex[j] != -1 && lowcost[j] < min)
				{
					v = j;
					min = lowcost[j];
				}
			}
			if (v)
			{
				T[k].tail = v;
				T[k].head = nearvex[v];
				T[k++].cost = lowcost[v];
				nearvex[v] = -1;
				for (int j = 1; j < G.n+1; j++)
				{
					if (nearvex[j] != -1 && G.Edge[v][j] < lowcost[j])
					{
						nearvex[j] = v;
						lowcost[j] = G.Edge[v][j];
					}
				}
			}
		}
	}
	int totalcost = 0;
	for (int i = 0; i < G.n - 1; i++)
		totalcost += T[i].cost;
	printf("%d\n", totalcost);
}