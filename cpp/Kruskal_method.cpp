#include<stdio.h>

#define NUM 200     //��󶥵����
#define EDGENUM 20000       //���ı���
#define MAX 40000   //���ֵ

//�����ڽӾ���Ľṹ
typedef struct
{
	int edges[NUM][NUM];    //�ڽӾ���
	int n;      //������
	int e;      //����
}MGraph;

//����ߵĽṹ
typedef struct
{
	int begin;      //�ߵ����
	int end;        //�ߵ��յ�
	int weight;     //�ߵ�Ȩֵ
}Edge;

//�����ڽӾ���v��ʾ������
void CreatGraph(MGraph &G, int v)
{
	G.n = v;
	G.e = v * (v - 1) / 2;
	for (int i = 1; i <= G.n; i++) {      //��ʼ���ڽӾ���
		for (int j = 1; j <= G.n; j++) {
			G.edges[i][j] = MAX;
		}
	}
	for (int i = 1; i <= G.e; i++) {      //�����ڽӾ���
										  //v1,v2һ��·���ӵ�����ׯ��cost��·���ã�build�޽�״̬
		int v1, v2, cost, build;
		scanf("%d%d%d%d", &v1, &v2, &cost, &build);
		if (build == 1)
			cost = 0;
		G.edges[v1][v2] = cost;
		G.edges[v2][v1] = cost;
	}
}

//�Ҷ���k���յ�
int Find(int parent[], int k)
{
	while (parent[k] > 0) {
		k = parent[k];
	}
	return k;
}

//Kruskal�㷨ʵ��
int Kruskal(MGraph G)
{
	Edge edge[EDGENUM];     //ͼ��Ӧ�����б�
	int parent[EDGENUM];    //���ڼ�¼������յ�
	int k = 1;      //���ڼ�¼�ߵ�����
	for (int i = 1; i <= G.n; i++) {      //������
		for (int j = i + 1; j <= G.n; j++) {
			edge[k].begin = i;
			edge[k].end = j;
			edge[k].weight = G.edges[i][j];
			k++;
		}
	}

	//���ݱߵ�Ȩֵ��С�Ա�������д�С��������
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
	//��ʼ��parent����
	for (int i = 1; i <= G.n; i++) {
		parent[i] = 0;
	}

	int m, n;
	int result = 0; //���ڼ�¼��·�ɱ�
	for (int i = 1; i <= G.e; i++) {
		//�жϱ����ı��Ǵ��ڻ�
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

