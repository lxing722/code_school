#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TSIZE 45
typedef struct film
{
	char title[TSIZE];
	int rating;
	struct film *next;
};
int main(void)
{
	struct film *head=NULL;
	struct film *current,*prev;
	char input[TSIZE];
	puts("Enter the title of the movie:");
	while(gets(input)!=NULL&&input[0]!='\0')
	{
		current=(struct film *)malloc(sizeof(struct film));
		if(head==NULL) 
			head=current;
		else 
			prev->next=current;
		current->next=NULL;
		strcpy(current->title,input);
		puts("Enter the rating of the movie:");
		scanf("%d",&current->rating);
		while(getchar()!='\n')
			 continue;
		puts("Now enter the next movie title:");
		prev=current;
	}
	if(head==NULL) 
		printf("No data entered!");
	else
		printf("Here is the movie list:\n");
	current=head;
	while(current!=NULL)
	{
		printf("The movie title is %s,your rating is %d;\n",current->title,current->rating);
		current=current->next;
	}
	printf("Bye!\n");
	return 0;
}

