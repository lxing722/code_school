#include<stdio.h>
#include<locale.h>
#define MaxSize 5000
typedef struct {
	int id,score1,score2,score = score1+score2;
	char sex[5];
	char name[20];
}Student; 
typedef struct
{
	Student data[MaxSize];
	int num;
}StuData;
void Init(StuData &S);
int Search(StuData S, int n);
int Insert(StuData &S);
int Partition(StuData &S, int low, int high);
void QSort(StuData &S, int low, int high);

int main(void)
{
	setlocale(LC_ALL, "chs");
	//wchar_t test;
	//wscanf(L"%c", &test);
	//wprintf(L"%c\n", test);
	StuData test;
	Init(test);
	char ch;
	puts("1:��ѯ   2������   3������   4���˳�");
	printf("��ѡ����Ҫִ�еĲ�����");
	while ((ch = getchar()) != '4')
	{
		switch (ch)
		{
			case '1':
			{
				while (true)
				{
					int n;
					puts("������Ҫ��ѯ��ѧ��(����-1���˳���ѯ)��");
					scanf_s("%d", &n);
					if (n == -1)
						break;
					int k = Search(test, n);
					if (k >= 0)
					{
						puts("��ѯ������Ϣ���£�");
						printf("ѧ��: %d\n", test.data[k].id);
						printf("����: %s\n", test.data[k].name);
						printf("�Ա�: %s\n", test.data[k].sex);
						printf("�ɼ�1: %d\n", test.data[k].score1);
						printf("�ɼ�2: %d\n", test.data[k].score2);
						printf("�ܳɼ�: %d\n", test.data[k].score);
					}
					else
						puts("�޴�ѧ����Ϣ��");
				}
				break;
			}
			case '2':
			{
				int n;
				printf("��������Ҫ������Ϣ�Ĵ�����");
				scanf_s("%d", &n);
				int i = 0;
				while (i < n)
				{
					Insert(test);
					i++;
				}
				break;
			}
			case '3':
			{
				QSort(test, 0, test.num - 1);
				puts("��������Ϣ����:");
			}
		}
	}
	//Insert(test);
	//Insert(test);
	//QSort(test, 0, test.num - 1);
	//for (int i = 0; i < test.num; i++)
		//printf("%d\n", test.data[i].id);
	return 0;
}
void Init(StuData &S)
{
	S.num = 0;
}
int Search(StuData S, int n)
{
	int i;
	for (i = 0; i < S.num&&S.data[i].id != n; i++);
	if (S.data[i].id == n)
		return i;
	else
		return -1;
}
int Search_Bin(StuData S, int n)
{
	int low, mid, high;
	low = 0; high = S.num-1;
	while (low < high)
	{
		mid = (high - low) % 2;
		if (S.data[mid].id == n)
			return mid;
		else if (S.data[mid].id < n)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
int Insert(StuData &S)
{
	int id;
	printf(" ������ѧ�ţ�");
	scanf("%d", &id);
	if (Search(S, id)>=0)
	{
		puts("��ѧ���Ѵ���ϵͳ��");
		return 0;
	}
	S.data[S.num].id = id;
	printf(" ������������");
	scanf("%s", S.data[S.num].name);
	printf(" �������Ա�");
	scanf("%s", S.data[S.num].sex);
	printf(" ������ɼ�1��");
	scanf("%d", &S.data[S.num].score1);
	printf(" ������ɼ�2��");
	scanf("%d", &S.data[S.num].score2);
	S.num++;
	return 1;
}
int Partition(StuData &S,int low,int high)
{
	int key, k;
	low = 0, high = S.num - 1;
	key = S.data[low].id;
	while (low < high)
	{
		while (low<high&&S.data[high].id > key) --high;
		k = S.data[high].id;
		S.data[high].id = S.data[low].id;
		S.data[low].id = S.data[high].id;
		while (low<high&&S.data[low].id < key) ++low;
		S.data[high].id = S.data[low].id;
		S.data[low].id = k;
	}
	return low;
}
void QSort(StuData &S,int low,int high)
{
	if (low < high)
	{
		int pivotloc = Partition(S, low, high);
		QSort(S, low, pivotloc - 1);
		QSort(S, pivotloc + 1, high);
	}
}
void BubbleSort(StuData &S)
{
	int i = 0;
	int exchange = 1;
	while (i < S.num - 1 && exchange)
	{
		exchange = 0;
		for (int j = 0; j < S.num - i - 1; j++)
		{
			if (S.data[j].id > S.data[j + 1].id)
			{
				int temp = S.data[j + 1].id;
				S.data[j + 1].id = S.data[j].id;
				S.data[j].id = temp;
				exchange = 1;
			}
		}
		i++;
	}
}