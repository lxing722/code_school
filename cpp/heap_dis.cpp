#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct str
{
	char *ch;
	int length;
} *HString;
enum Status{OK,ERROR};
Status StrInsert(HString S,HString T,int pos);
Status StrAssign(HString T,char *chars);
Status Contact(HString T,HString S1,HString S2);
Status SubString(HString Sub,HString S,int pos,int len);
int Search(HString S,HString T,int pos);
int main(void)
{
	HString test1,test2,test3,substr;
	test1 = (HString)malloc(sizeof(struct str));
	test2 = (HString)malloc(sizeof(struct str));
	test3 = (HString)malloc(sizeof(struct str));
	substr = (HString)malloc(sizeof(struct str));
	StrAssign(test1,"shenmedongxi");
	StrAssign(test2,"me");
	printf("%d\n",Search(test1,test2,0));
	return 0;
}

Status StrInsert(HString S,HString T,int pos)
{
	if(pos<0||pos>S->length-1) 
		return ERROR;
	if(T->length)
	{
		S->ch = (char *)realloc(S->ch,(S->length+T->length)*sizeof(char));
		if(!S->ch)
			return ERROR;
		for(int i = S->length-1;i>pos-1;i--)
			S->ch[i+T->length] = S->ch[i];
		for(int j = pos;j<pos+T->length;j++)
			S->ch[j] = T->ch[j-pos];
		S->length += T->length; 
	}
	return OK;
}
Status StrAssign(HString T,char *chars)
{
	int i;
	//if(T->ch) free(T->ch);
	i = strlen(chars);
	if(!i) 
	{
		T->ch = NULL;
		T->length = 0;
	}
	else
	{
		T->ch = (char*)malloc(i*sizeof(char));
		if(!T->ch)
			return ERROR;
		for(int j=0;j<i;j++)
			T->ch[j] = chars[j];
		T->length = i;
	}
	return OK;
}
Status Contact(HString T,HString S1,HString S2)
{
	if(!T->ch) free(T->ch);
	T->ch = (char*)malloc((S1->length+S2->length)*sizeof(char));
	if(!T->ch)
		return ERROR;
	for(int i=0;i<S1->length;i++)
		T->ch[i] = S1->ch[i];
	T->length = S1->length+S2->length;
	for(int j=S1->length;j<T->length;j++)
		T->ch[j] = S2->ch[j-S1->length];
	return OK;
}
Status SubString(HString Sub,HString S,int pos,int len)
{
	if(!Sub->ch) return ERROR;
	Sub->ch = (char *)malloc(len*sizeof(char));
	for(int i=0;i<len;i++)
		Sub->ch[i] = S->ch[pos+i];
	Sub->length =len;
	return OK;
}
int Search(HString S,HString T,int pos)
{
	int i,j;
	i = pos,j = 0;
	while(i<S->length&&j<T->length)
	{
		if(S->ch[i] == T->ch[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i-j+2;
			j = 0;
		}
	}
	if(j>=T->length) return i-T->length;
	else return -1;
}
