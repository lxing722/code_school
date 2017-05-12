#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ch
{
	char keyword[16];
	struct ch *next;
} *keyptr;			//��������ڵ㣬������ʱ�洢�ؼ��ַ���
int Find(char *keywords,char *source,int next[]);
void GetNext(char *keywords,int next[]);
int SafeStrcpy2KeyWord(char* pDestBuffer,char* pSourceString,int nDestBufferSize,char* szKeyWord);

int main(void)
{
	char source[256],key[16];
	keyptr head = NULL;		//ͷָ��Ĭ����Ϊ��
	keyptr prev,current;		//����ǰָ�룬����ָ��
	puts("������Դ�ַ���������С��256����");
	gets(source);
	puts("������ؼ��ִ�������END�Խ������룩��");		//�洢�ؼ��ַ���
	while(strcmp(gets(key),"END")!=0)		//����㣬�ж�������ַ���ΪEND���ѵ㣬����strcmp�ַ����ȽϺ��������������ͬ�򷵻�0����ͬ�򷵻������׸���ͬ�ַ���ASCII���ֵ
	{
		if(key[0] == '\0')		//�������Ϊ�գ��������һ��ѭ��
			continue;
		current = (keyptr)malloc(sizeof(struct ch));
		if(head == NULL)			
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		if(strcmp(key,"NULL") == 0)		//�ж�NULL
			strcpy(current->keyword,"");
		else
			strcpy(current->keyword,key);		//��key�����д洢���ַ���������currentָ���keyword���棬�Ա�����ʹ��
		//while(getchar()!='\n')
			//continue; �������㣬û��������������д�������壬���������scanfʹ��
		prev = current;			
	}
	puts("�����ĳ��ȺͿ������Ŀ���ַ���Ϊ��");
	current = head;				//��������ĳ��ȺͿ������Ŀ���ַ���
	while(current)
	{
		SafeStrcpy2KeyWord("",source,256,current->keyword);
		current = current->next;
	}
	keyptr next;
	current = head;
	while(current)			//������ͷ��ڴ�
	{
		next = current->next;
		free(current);
		current = next;
	}
	return 0;
}
int Find(char *keywords,char *source,int next[])   //ģʽƥ�䣬�ҵ�Դ��ַ�йؼ��ֿ�ʼ��λ��
{
	int i,j,m,n;
	i = -1,j = -1,m = strlen(source),n = strlen(keywords);
	while(i<m && j<n)
	{
		if(j == -1||source[i] == keywords[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if(j>=n)
		return i-n;
	else
		return -1;
}
void GetNext(char *keywords,int next[])   //KMP�㷨�õ�next����
{
	int i,j,m;
	i = 0,next[0] = -1,j = -1,m = strlen(keywords);
	while(i<m)
	{
		if(j == -1||keywords[i] == keywords[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
int SafeStrcpy2KeyWord(char* pDestBuffer,char* pSourceString,int nDestBufferSize,char* szKeyWord)  //�����ܺ���
{
	char text[256];
	for(int i=0;i<strlen(pDestBuffer);i++)
		text[i] = pDestBuffer[i];
	if(!szKeyWord)			//�����ж��������ùؼ���
	{
		printf("0 ");		//û�������0��ԭ����Ŀ���ַ���
		if(!pDestBuffer)
			puts("NULL");
		else
			puts(pDestBuffer);
	}
	else
	{
		int m,length;
		int next[256];
		GetNext(szKeyWord,next); //���ǵ��ú�������next���飬�ڴ��ͻ
		m = Find(szKeyWord,pSourceString,next);			//��Դ�ַ������ҵ��ؼ��ַ�����ʼλ�����֣���������ָպõ��ڿ����ַ����ĳ���
		for(int i=0;i<m;i++)
			text[strlen(pDestBuffer)+i] = pSourceString[i];			//��Ҫ�������ַ���������Ŀ���ַ�����
		length = strlen(pDestBuffer)+m;
		printf("%d ",m);
		if(length == 0)
			printf("NULL");
		if(nDestBufferSize<length)			//�жϿ�����Ŀ���ַ��������Ƿ񳬳����������ȣ������������ֻ����������ڵ��ַ�
		{
			for(int i=0;i<nDestBufferSize;i++)				
				printf("%c",text[i]);
		}
		else
		{
			for(int i=0;i<length;i++)
				printf("%c",text[i]);
		}
		printf("\n");
		
	}
	return 0;
}