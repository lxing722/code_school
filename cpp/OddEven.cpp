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
	printf("�������㽫Ҫ�������ֵĸ�����");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf_s("%d", &k);
		num[i] = k;
	}
	int exchange = 1;			//�����ж�����exchange
	while (exchange)			//���exchangeΪ0��˵��һ����ż�����û������ֵ������˵���Ѿ��ź�����˾��Ƴ�ѭ��
	{
		exchange = 0;
		for (int i = 1; i < n; i++)			//��������ɨ��
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
		for (int i = 1; i < n; i++)			//��ż����ɨ��
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