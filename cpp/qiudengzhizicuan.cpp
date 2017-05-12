#include<stdio.h>
#include<string.h>
void substr(char s[])
{
	int T[2]={0};
	int i=0,j,k,len;
	for(len = 0;s[len] != NULL;len++);
	while(i < len)
	{
		if(s[i] != s[i+1])
			i++;
		else
		{			
			for(j = i;s[j] == s[j+1];j++);
			if(T[1] == 0)
			{
				T[0] = i;
				T[1] = j+1;
			}
			else
			{				
				if((j+1) > T[1])
				{
					T[0] = i;
					T[1] = j+1;
				}
			}
			i = j+1;
		}
	}
	if(T[1] == 0)
		printf("ÎÞµÈÖµ×Ö´®£¡\n");
	else
	{
		for(k = T[0];k<T[1];k++)
			printf("%c",s[k]);
		printf("\n");
	}
}

int main(void)
{
	substr("ababaaabbaaabbbb");
	return 0;
}