#include <stdio.h>
#define	N 5
int main()
{
	void input_array(int(*a)[N], int n);
	void printf_array(int(*a)[N], int n);
	void select(int(*a)[N], int n);
	int a[N][N];
	printf("请输入一个5X5矩阵（每输入一行回车一次）：\n");
	input_array(a, N);
	select(a, N);
	printf("调整顺序后的矩阵为：\n");
	printf_array(a, N);
	return 0;
}
void input_array(int(*a)[N], int n)
{
	int i, j;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			scanf_s("%d", *((a + i)) + j);
		}
	}
}
void select(int(*a)[N], int n)
{
	int i, t;
	int* p;
	p = *a;
	for (i = 0; i < n * n; i++)
	{
		if (*(p + i) <= *p)
			t = *(p), * (p) = *(p + i), * (p + i) = t;
		else if (*(p + i) <= *(p + 4))
			t = *(p + 4), * (p + 4) = *(p + i), * (p + i) = t;
		else if (*(p + i) <= *(p + 20))
			t = *(p + 20), * (p + 20) = *(p + i), * (p + i) = t;
		else if (*(p + i) <= *(p + 24))
			t = *(p + 24), * (p + 24) = *(p + i), * (p + i) = t;
		if (*(p + i) >= *(p + 12))
			t = *(p + 12), * (p + 12) = *(p + i), * (p + i) = t;
	}
}
void printf_array(int(*a)[N], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", *(*(a + i) + j));
		}
		printf("\n");
	}
}