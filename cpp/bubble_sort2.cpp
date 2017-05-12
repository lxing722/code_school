#include<stdio.h>
void BubbleSort(int S[], int n)
{
	int i = 1;
	int exchange = 1;
	while (i < n&&exchange)
	{
		exchange = 0;
		for (int j = 1; j <= n - i; j++)
		{
			if (S[j] > S[j + 1])
			{
				int k = S[j];
				S[j] = S[j + 1];
				S[j + 1] = k;
				exchange = 1;
			}
		}
		i++;
	}
}
int main(void)
{
	int S[7] = { 0,21,25,49,25,16,8 };
	BubbleSort(S, 6);
	for (int i = 1; i < 7; i++)
		printf("%d\n", S[i]);
	return 0;
}