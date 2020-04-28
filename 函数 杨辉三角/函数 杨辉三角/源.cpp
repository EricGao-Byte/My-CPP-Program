#include <stdio.h>

int h;
double fac(int n)
{
	double f = 0;
	if (n < 0)
		printf("数据错误!\n");
	else if (n == 0 || n == 1)
		f = 1;
	else f = fac(n - 1) * n;
	return (f);
}
void space(int n)
{
	int i;
	for (i = 1; i <= h - n; i++)
		printf(" ");
}
void calculator(int n)
{
	int i;
	double s;
	for (i = 1; i <= n; i++)
	{
		if (i == 1 || i == n)
			printf("1 ");
		else
		{
			s = fac(n - 1) / (fac(i - 1) * fac(n - i));
			printf("%.lf ", s);
		}
	}
	printf("\n");
}

int main()
{
	double fac(int n);
	void space(int n);
	void calculator(int n);
	int i;
	printf("请输入杨辉三角的行数:");
	scanf_s("%d", &h);
	for (i = 1; i <= h; i++)
	{
		space(i);
		calculator(i);
	}
	return 0;
}