#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000	//指定字符长度
int StringSplit(int num[],char chars[]);
int cmp(const void *a,const void *b);
typedef struct node		//创建节点，用于存储分割后的数字
{
	int data[MAXSIZE];
	int length;
	struct node *next;
} *ListNode;

int main(void)
{
	char chars[MAXSIZE];
	ListNode head = NULL,prev,current;		//声明头节点，前一个节点，当前结点
	puts("请输入数字（长度不大于1000）:");
	while(gets(chars)!=NULL&&chars[0]!='\0')		//读取输入的数字串存入chars数组中，当输入为空时，停止读取，继续执行后面的语句
	{
		current = (ListNode)malloc(sizeof(struct node));
		if(head == NULL)		//创建头节点
			head = current;
		else
			prev->next = current;		//将当前结点与前一个节点连接
		current->next = NULL;
		current->length = StringSplit(current->data,chars);		//将分割的数字存入当前结点的data数组中，将数组中数字的个数赋给length
		qsort(current->data,current->length,sizeof(current->data[0]),cmp);		//将data数组中的数字按升序排列
		prev = current;
	}
	puts("分割后的结果为:");
	if(head == NULL)
		puts("无数字输入！");
	current = head;		//输出分割后的结果
	while(current)
	{
		for(int i=0;i<current->length;i++)
			printf("%d ",current->data[i]);
		printf("\n");
		current = current->next;
	}
	ListNode next;
	current = head;
	while(current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return 0;
}
int StringSplit(int num[],char chars[])		//创建函数用于分割字符串，并将分割后的数字存入num数组中
{
	char *str = strtok(chars,"5");		//将chars字符串中的5作为分割符号，将分割的第一个字符串赋给str
	int i = 0;
	if(!str)		//如果str为空，说明组成字符串的数字都为5
	{
		puts("Data Error：数字不能全为5!");
		exit(-1);
	}
	while(str)
	{
		if(atol(str)>100000000)
		{
			puts("Data Error：所截取的数字不能大于100000000!");
			exit(-1);
		}
		num[i++] = atol(str);		//将str转成长整形整数并存入num数组
		str = strtok(NULL,"5");		//将分割后的下一个字符串赋给str，以此类推
	}
	
	return i;
}
int cmp(const void *a,const void *b)		//定义cmp函数，用于qsort函数按照指定方式排序
{
	return *(int*)a-*(int*)b;
}