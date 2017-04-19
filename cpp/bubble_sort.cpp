#include<stdio.h>
void selectSort(int a[],int n);
void BubbleSort(int a[], int n);
int main(void)
{
	int test[10] = {3,5,2,7,23,12,7,4,6,17};
	BubbleSort(test,10);
	for(int i=0;i<10;i++)
	{
		printf("%d\n",test[i]);
	}
	return 0;
}

void selectSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int k = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[k]) k = j;
		}
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
}
void BubbleSort(int a[], int n)
{
	int i = 0;
	int exchange = 1;
	while (i < n-1&&exchange)
	{
		exchange = 0;
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j+1];
				a[j + 1] = a[j];
				a[j] = temp;
				exchange = 1;
			}
		}
		i++;
	}
}