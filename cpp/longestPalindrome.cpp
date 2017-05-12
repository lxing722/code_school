#include<stdio.h>
#include<string.h>
int longestPalindrome(char* s);
int main(void)
{
	char* str = "abcdaadcddsfs";
	//for (int i = 0; i < strlen(str); i++)
		//*(substr+i) = str[i];
	//printf("%s\n", substr);
	longestPalindrome(str);
	return 0;
}
int longestPalindrome(char* s) {
	int length = strlen(s);
	int head, tail, num = length;
	while (length >= 2)
	{
		//const int len = length;
		//char substr[len];
		head = 0, tail = length - 1;
		while (tail<num)
		{
			int i = head, j = tail;
			while (i<j&&s[i] == s[j])
			{
				i++;
				j--;
			}
			if (i >= j)
			{
				for (int k = head; k <= tail; k++)
					printf("%c",s[k]);
				printf("\n");
				return 0;;
			}
			head++;
			tail++;
		}
		length--;
	}
	//char substr[length];
	printf("%c\n",s[0]);
	return 0;
}