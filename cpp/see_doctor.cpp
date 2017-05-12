#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} *QueuePtr;		//������еĽڵ�
typedef struct queue
{
	QueuePtr front;
	QueuePtr rear;
} Queue;		//����һ�����У�������д�һ��ͷָ���һ��βָ��
void InitQueue(Queue &Q);
void EnQueue(Queue &Q,int x);
int OutQueue(Queue &Q);
void Check(Queue Q);

int main(void)
{
	Queue test;
	char order;
	InitQueue(test);
	puts("1:�Ŷ�  2������  3���鿴�Ŷ�  4�������Ŷӣ��������ξ���  5���°�");		//������
	printf("�����������ţ�1-5����");
	while((order = getchar()) != '#')
	{
		if('\n' == order)
			continue;
		else
		{
			switch(order)
			{
			case '1':			//����Ϊ1ʱ�����벡����ֱ������Ϊ-1
				int num;
				puts("�����벡���ţ���-1����ʾ�˳����룩");
				printf("�����벡���ţ�");
				scanf("%d",&num);
				while(num!=-1)
				{
					EnQueue(test,num);
					printf("�����벡���ţ�");
				    scanf("%d",&num);
				}
				break;
			case '2':			//ȡ��������Ԫ��
				OutQueue(test);
				break;
			case '3':			//�������нڵ㣬��ȡ����
				Check(test);
				break;
			case '4':			//�������нڵ㣬��ȡ���ݲ��˳�����
				Check(test);
				exit(0);
			case '5':			//�˳�����
				exit(0);
			}
		}
		while(getchar() != '\n')
			continue;
		printf("�����������ţ�1-5����");
	}
	return 0;
}

void InitQueue(Queue &Q)		//����һ���������ڳ�ʼ������
{
	Q.front  = Q.rear = (QueuePtr)malloc(sizeof(struct node));		//�տ�ʼ������Ϊ�գ�ͷָ���βָ�붼ָ��ͬһ���ڵ�
	Q.front->next = NULL;
}
void EnQueue(Queue &Q,int x)		//����һ���������ڽ�x�������
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(struct node));
	p->data = x;
	p->next = NULL;
	Q.rear->next = p;			//�嵽��β
	Q.rear = p;
}
int OutQueue(Queue &Q)			//����һ����������ȥ�������еĽڵ�Ԫ��
{
	QueuePtr current;
	current = Q.front->next;
	if(!current)
	{
		puts("Empty queue!");
	    exit(-1);
	}
	printf("%d\n",current->data);
	Q.front->next = current->next;			//ȡ��ͷָ������Ǹ��ڵ�
	free(current);
	return 0;
}
void Check(Queue Q)			//����һ���������ڴ�ͷ��β�������нڵ㣬������ڵ�Я��������
{
	QueuePtr current;
	current = Q.front->next;
	while(current)
	{
		printf("%d\n",current->data);
		current = current->next;
	}
}