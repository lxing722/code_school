#include<stdio.h>
#define MaxSize 1000
void OddEvenSort(void);
int main(void)
{
	OddEvenSort();
	return 0;
}
void OddEvenSort(void)
{
	int n, num[MaxSize] = { 65535 };
	printf("请输入你将要输入数字的个数：");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf_s("%d", &k);
		num[i] = k;
	}
	int exchange = 1;			//设置判断数字exchange
	while (exchange)			//如果exchange为0，说明一趟奇偶排序后没有做数值交换，说明已经排好序，如此就推出循环
	{
		exchange = 0;
		for (int i = 1; i < n; i++)			//第奇数次扫描
		{
			if (i % 2)
			{
				if (num[i] > num[i + 1])
				{
					int temp1 = num[i];
					num[i] = num[i + 1];
					num[i + 1] = temp1;
					exchange = 1;
				}
			}
		}
		for (int i = 1; i < n; i++)			//第偶数次扫描
		{
			if (!(i % 2))
			{
				if (num[i] > num[i + 1])
				{
					int temp2 = num[i];
					num[i] = num[i + 1];
					num[i + 1] = temp2;
					exchange = 1;
				}
			}
		}		
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", num[i]);
	printf("\n");
}