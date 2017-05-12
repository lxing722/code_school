#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 255
typedef unsigned char SString[MAXSIZE+1];
void Assign(SString S,char *chars);
void Contact(SString S1,SString S2);
int Search(SString S,SString T,int next[]);
void get_next(SString T,int next[]);

int main(void)
{
	SString test1,test2;
	int next[MAXSIZE];
	Assign(test1,"shenmedongxi");
	Assign(test2,"me");
	for(int i=1;i<=test1[0];i++)
		printf("%c",test1[i]);
	printf("\n");
	for(int i=1;i<=test2[0];i++)
		printf("%c",test2[i]);
	printf("\n");
	Contact(test1,test2);
	for(int i=1;i<=test1[0];i++)
		printf("%c",test1[i]);
	printf("\n"); 
	get_next(test2,next);
	printf("%d\n",Search(test1,test2,next)); 
	return 0;
}

void Assign(SString S,char *chars)
{
	int m = strlen(chars);
	S[0] = m;
	for(int i=0;i<m;i++)
		S[i+1] = chars[i];
}
void Contact(SString S1,SString S2)
{
	int len1 = S1[0],len2 = S2[0];
	int m = MAXSIZE-len1;
	if(len1+len2<=MAXSIZE)
	{
		for(int i=1;i<=len2;i++)
			S1[len1+i] = S2[i];
		S1[0] += S2[0];
	}
	else
	{
		for(int j=0;j<=m;j++)
			S1[len1+j] = S2[j];
		S1[0] += m;
	}
}
int Search(SString S,SString T,int next[])
{
	int i,j;
	i = 0,j = 0;
	while(i<=S[0]&&j<=T[0])
	{
		if(j == 0||S[i] == T[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if(j>T[0]) return i-T[0];
	else return 0;
}
void get_next(SString T,int next[])
{
	int i,j;
	i = 1,next[0] = -1,next[1] = 0,j = 0;
	while(i<T[0])
	{
		if(j == 0||T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}