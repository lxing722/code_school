#include<stdio.h>

#define NUM 200     //最大顶点个数
#define EDGENUM 20000       //最大的边数
#define MAX 40000   //最大值

//定义邻接矩阵的结构
typedef struct
{
	int edges[NUM][NUM];    //邻接矩阵
	int n;      //顶点数
	int e;      //边数
}MGraph;

//定义边的结构
typedef struct
{
	int begin;      //边的起点
	int end;        //边的终点
	int weight;     //边的权值
}Edge;

//构造邻接矩阵，v表示顶点数
void CreatGraph(MGraph &G, int v)
{
	G.n = v;
	G.e = v * (v - 1) / 2;
	for (int i = 1; i <= G.n; i++) {      //初始化邻接矩阵
		for (int j = 1; j <= G.n; j++) {
			G.edges[i][j] = MAX;
		}
	}
	for (int i = 1; i <= G.e; i++) {      //构造邻接矩阵
										  //v1,v2一条路连接的两村庄，cost修路费用，build修建状态
		int v1, v2, cost, build;
		scanf("%d%d%d%d", &v1, &v2, &cost, &build);
		if (build == 1)
			cost = 0;
		G.edges[v1][v2] = cost;
		G.edges[v2][v1] = cost;
	}
}

//找顶点k的终点
int Find(int parent[], int k)
{
	while (parent[k] > 0) {
		k = parent[k];
	}
	return k;
}

//Kruskal算法实现
int Kruskal(MGraph G)
{
	Edge edge[EDGENUM];     //图对应的所有边
	int parent[EDGENUM];    //用于记录顶点的终点
	int k = 1;      //用于记录边的数量
	for (int i = 1; i <= G.n; i++) {      //构建边
		for (int j = i + 1; j <= G.n; j++) {
			edge[k].begin = i;
			edge[k].end = j;
			edge[k].weight = G.edges[i][j];
			k++;
		}
	}

	//根据边的权值大小对边数组进行从小到大排序
	for (int i = 1; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (edge[i].weight > edge[j].weight) {
				int temp;
				temp = edge[i].begin;
				edge[i].begin = edge[j].begin;
				edge[j].begin = temp;
				temp = edge[i].end;
				edge[i].end = edge[j].end;
				edge[j].end = temp;
				temp = edge[i].weight;
				edge[i].weight = edge[j].weight;
				edge[j].weight = temp;
			}
		}
	}
	//初始化parent数组
	for (int i = 1; i <= G.n; i++) {
		parent[i] = 0;
	}

	int m, n;
	int result = 0; //用于记录修路成本
	for (int i = 1; i <= G.e; i++) {
		//判断遍历的边是存在环
		m = Find(parent, edge[i].begin);
		n = Find(parent, edge[i].end);
		if (m != n) {
			parent[n] = m;
			result = result + edge[i].weight;
		}
	}
	return result;
}

int main()
{
	while (true) {
		int v;
		scanf("%d", &v);
		if (v == 0)break;
		MGraph G;
		CreatGraph(G, v);
		int cost = Kruskal(G);
		printf("%d\n", cost);
	}
	return 0;
}

