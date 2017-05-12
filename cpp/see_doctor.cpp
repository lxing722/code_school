#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} *QueuePtr;		//定义队列的节点
typedef struct queue
{
	QueuePtr front;
	QueuePtr rear;
} Queue;		//定义一个队列，这个队列带一个头指针和一个尾指针
void InitQueue(Queue &Q);
void EnQueue(Queue &Q,int x);
int OutQueue(Queue &Q);
void Check(Queue Q);

int main(void)
{
	Queue test;
	char order;
	InitQueue(test);
	puts("1:排队  2：就诊  3：查看排队  4：不再排队，余下依次就诊  5：下班");		//程序功能
	printf("请输入操作序号（1-5）：");
	while((order = getchar()) != '#')
	{
		if('\n' == order)
			continue;
		else
		{
			switch(order)
			{
			case '1':			//输入为1时则输入病历号直到输入为-1
				int num;
				puts("请输入病历号（“-1”表示退出输入）");
				printf("请输入病历号：");
				scanf("%d",&num);
				while(num!=-1)
				{
					EnQueue(test,num);
					printf("请输入病历号：");
				    scanf("%d",&num);
				}
				break;
			case '2':			//取出队列首元素
				OutQueue(test);
				break;
			case '3':			//遍历所有节点，读取数据
				Check(test);
				break;
			case '4':			//遍历所有节点，读取数据并退出程序
				Check(test);
				exit(0);
			case '5':			//退出程序
				exit(0);
			}
		}
		while(getchar() != '\n')
			continue;
		printf("请输入操作序号（1-5）：");
	}
	return 0;
}

void InitQueue(Queue &Q)		//定义一个函数用于初始化队列
{
	Q.front  = Q.rear = (QueuePtr)malloc(sizeof(struct node));		//刚开始，队列为空，头指针和尾指针都指向同一个节点
	Q.front->next = NULL;
}
void EnQueue(Queue &Q,int x)		//定义一个函数用于将x插入队列
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(struct node));
	p->data = x;
	p->next = NULL;
	Q.rear->next = p;			//插到队尾
	Q.rear = p;
}
int OutQueue(Queue &Q)			//定义一个函数用于去处队列中的节点元素
{
	QueuePtr current;
	current = Q.front->next;
	if(!current)
	{
		puts("Empty queue!");
	    exit(-1);
	}
	printf("%d\n",current->data);
	Q.front->next = current->next;			//取出头指针后面那个节点
	free(current);
	return 0;
}
void Check(Queue Q)			//定义一个函数用于从头到尾遍历所有节点，并输出节点携带的数据
{
	QueuePtr current;
	current = Q.front->next;
	while(current)
	{
		printf("%d\n",current->data);
		current = current->next;
	}
}