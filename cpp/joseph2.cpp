#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct num
{
	int data;
	struct num *next;
};
int main(void)
{
	struct num *head = NULL;
	struct num *prev,*current,*next;
	int n;
	printf("Enter the total number of the people:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		current = (struct num *)malloc(sizeof(struct num));
		if(head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		current->data = i;
		prev = current;
	}
	prev->next = head;
	int m;
	printf("Enter the number m:");
	scanf("%d",&m);
	current = head;
	for(int i=0;i<m-1;i++) current = current->next;
	prev = current;
	current = head;
	for(int i=0;i<m+1;i++) current = current->next;
	next = current;
	prev->next = next;
	

	int a=0;
	current = head;
	while(a<10)
	{
		printf("%d\n",current->data);
		current = current->next;
		a += 1;
	}
}
