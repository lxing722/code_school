#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ch
{
	char keyword[16];
	struct ch *next;
} *keyptr;			//创建链表节点，用于暂时存储关键字符串
int Find(char *keywords,char *source,int next[]);
void GetNext(char *keywords,int next[]);
int SafeStrcpy2KeyWord(char* pDestBuffer,char* pSourceString,int nDestBufferSize,char* szKeyWord);

int main(void)
{
	char source[256],key[16];
	keyptr head = NULL;		//头指针默认设为空
	keyptr prev,current;		//设置前指针，现在指针
	puts("请输入源字符串（长度小于256）：");
	gets(source);
	puts("请输入关键字串（输入END以结束输入）：");		//存储关键字符串
	while(strcmp(gets(key),"END")!=0)		//错误点，判断输入的字符串为END是难点，利用strcmp字符串比较函数，如果两者相同则返回0，不同则返回两者首个不同字符的ASCII码差值
	{
		if(key[0] == '\0')		//如果输入为空，则进行下一轮循环
			continue;
		current = (keyptr)malloc(sizeof(struct ch));
		if(head == NULL)			
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		if(strcmp(key,"NULL") == 0)		//判断NULL
			strcpy(current->keyword,"");
		else
			strcpy(current->keyword,key);		//将key数组中存储的字符串拷贝到current指针的keyword里面，以备后面使用
		//while(getchar()!='\n')
			//continue; 画蛇添足，没有真正搞清楚这行代码的意义，书中是配合scanf使用
		prev = current;			
	}
	puts("拷贝的长度和拷贝后的目的字符串为：");
	current = head;				//输出拷贝的长度和拷贝后的目的字符串
	while(current)
	{
		SafeStrcpy2KeyWord("",source,256,current->keyword);
		current = current->next;
	}
	keyptr next;
	current = head;
	while(current)			//输出后释放内存
	{
		next = current->next;
		free(current);
		current = next;
	}
	return 0;
}
int Find(char *keywords,char *source,int next[])   //模式匹配，找到源地址中关键字开始的位置
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
void GetNext(char *keywords,int next[])   //KMP算法得到next数组
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
int SafeStrcpy2KeyWord(char* pDestBuffer,char* pSourceString,int nDestBufferSize,char* szKeyWord)  //主功能函数
{
	char text[256];
	for(int i=0;i<strlen(pDestBuffer);i++)
		text[i] = pDestBuffer[i];
	if(!szKeyWord)			//首先判断有无设置关键字
	{
		printf("0 ");		//没有则输出0和原样的目的字符串
		if(!pDestBuffer)
			puts("NULL");
		else
			puts(pDestBuffer);
	}
	else
	{
		int m,length;
		int next[256];
		GetNext(szKeyWord,next); //忘记调用函数生成next数组，内存冲突
		m = Find(szKeyWord,pSourceString,next);			//在源字符串中找到关键字符串开始位置数字，而这个数字刚好等于拷贝字符串的长度
		for(int i=0;i<m;i++)
			text[strlen(pDestBuffer)+i] = pSourceString[i];			//将要拷贝的字符串拷贝到目的字符串中
		length = strlen(pDestBuffer)+m;
		printf("%d ",m);
		if(length == 0)
			printf("NULL");
		if(nDestBufferSize<length)			//判断拷贝后目的字符串长度是否超出缓存区长度，如果超出，则只输出缓存区内的字符
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