#include<stdio.h>
void Fibonacci(int n);
int Fibonacci_2(int n);
int main(void)
{
	int n;
	printf("Please enter the length of the list(n):");
	scanf("%d",&n);
	puts("�ǵݹ���ʽ��");
	Fibonacci(n);
	puts("�ݹ���ʽ��");
	for(int i=0;i<n;i++)
		printf("%d\n",Fibonacci_2(i));
	return 0;
}

void Fibonacci(int n)				//�ǵݹ�
{
	int a,b,m,temp;
	a = 0,b = 1,m = 0;
	while(m<n)
	{
		temp = a;			//������ʱ�洢a��ֵ
		printf("%d\n",a);
		a = a+b;
		b = temp;
	    m++;
	}
}
int Fibonacci_2(int n)			//�ݹ�
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return Fibonacci_2(n-1)+Fibonacci_2(n-2);
}

	