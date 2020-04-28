#include <stdio.h>

int main()
{
	double exp(double);
	double x;
	printf("please input a number-x to calculate e^x:\n");
	scanf_s("%lf", &x);
	printf("e^%.2lf=%lf\n", x, exp(x));
	return 0;
}
double exp(double n)
{
	double fac(int);
	double sum_x(double, int);
	double ex=1;
	double ex1 = 1, ex2;
	int i;
	for ( i = 1; i <= 100; i++)
	{
		ex2 = ex1;
		ex1 = sum_x(n, i) / fac(i);
		ex += ex1;
	}
	return (ex);
}
double fac(int n)
{
	double f = 0;
	if (n < 0)
		printf("Êý¾Ý´íÎó!\n");
	else if (n == 0 || n == 1)
		f = 1;
	else f = fac(n - 1) * n;
	return (f);
}
double sum_x(double x,int n)
{
	double sum = 1;
	int i;
	for ( i = 1; i <= n; i++)
	{
		sum *= x;
	}
	return (sum);
}