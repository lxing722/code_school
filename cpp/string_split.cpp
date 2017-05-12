#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000	//ָ���ַ�����
int StringSplit(int num[],char chars[]);
int cmp(const void *a,const void *b);
typedef struct node		//�����ڵ㣬���ڴ洢�ָ�������
{
	int data[MAXSIZE];
	int length;
	struct node *next;
} *ListNode;

int main(void)
{
	char chars[MAXSIZE];
	ListNode head = NULL,prev,current;		//����ͷ�ڵ㣬ǰһ���ڵ㣬��ǰ���
	puts("���������֣����Ȳ�����1000��:");
	while(gets(chars)!=NULL&&chars[0]!='\0')		//��ȡ��������ִ�����chars�����У�������Ϊ��ʱ��ֹͣ��ȡ������ִ�к�������
	{
		current = (ListNode)malloc(sizeof(struct node));
		if(head == NULL)		//����ͷ�ڵ�
			head = current;
		else
			prev->next = current;		//����ǰ�����ǰһ���ڵ�����
		current->next = NULL;
		current->length = StringSplit(current->data,chars);		//���ָ�����ִ��뵱ǰ����data�����У������������ֵĸ�������length
		qsort(current->data,current->length,sizeof(current->data[0]),cmp);		//��data�����е����ְ���������
		prev = current;
	}
	puts("�ָ��Ľ��Ϊ:");
	if(head == NULL)
		puts("���������룡");
	current = head;		//����ָ��Ľ��
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
int StringSplit(int num[],char chars[])		//�����������ڷָ��ַ����������ָ������ִ���num������
{
	char *str = strtok(chars,"5");		//��chars�ַ����е�5��Ϊ�ָ���ţ����ָ�ĵ�һ���ַ�������str
	int i = 0;
	if(!str)		//���strΪ�գ�˵������ַ��������ֶ�Ϊ5
	{
		puts("Data Error�����ֲ���ȫΪ5!");
		exit(-1);
	}
	while(str)
	{
		if(atol(str)>100000000)
		{
			puts("Data Error������ȡ�����ֲ��ܴ���100000000!");
			exit(-1);
		}
		num[i++] = atol(str);		//��strת�ɳ���������������num����
		str = strtok(NULL,"5");		//���ָ�����һ���ַ�������str���Դ�����
	}
	
	return i;
}
int cmp(const void *a,const void *b)		//����cmp����������qsort��������ָ����ʽ����
{
	return *(int*)a-*(int*)b;
}