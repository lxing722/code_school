#include<stdio.h>
#define Vertices 100
typedef struct {
	float Edge[7][7] = {
		{ 0,28,1000,1000,1000,10,1000 },
		{ 28,0,16,1000,1000,1000,14 },
		{ 1000,16,0,12,1000,1000,1000 },
		{ 1000,1000,12,0,22,1000,18 },
		{ 1000,1000,1000,22,0,25,24 },
		{ 10,1000,1000,1000,25,0,1000 },
		{ 1000,14,1000,18,24,1000,0 }
	};
	int n, e;
} Graph;
typedef struct {
	int tail, head;
	float cost;
} MST;
void InitGraph(Graph &G);
void Prim(Graph G, MST T[], int n);

int main(void)
{
	Graph test;
	MST T[9] = { 0 };
	InitGraph(test);
	Prim(test, T, 0);
	return 0;
}
void InitGraph(Graph &G)
{
	G.n = 7;
	G.e = 9;
}
void Prim(Graph G, MST T[], int n)
{
	float lowcost[7];
	int nearvex[7];
	for (int i = 0; i < G.n; i++)
	{
		lowcost[i] = G.Edge[n][i];
		nearvex[i] = n;
	}
	nearvex[n] = -1;
	int k = 0;
	for (int i = 0; i < G.n; i++)
	{
		if (i != n)
		{
			int min = 999, v = 0;
			for (int j = 0; j < G.n; j++)
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
				for (int j = 0; j < G.n; j++)
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
	for (int i = 0; i < G.n-1; i++)
		printf("(%d->%d,%f)\n", T[i].head, T[i].tail, T[i].cost);
}