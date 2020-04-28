#include <stdio.h>

int main()
{
	double fac(int n);
	int n;
	scanf_s("%d", &n);
	printf("%.8lf", fac(n));
	return 0;
}
double fac(int n)
{
	if (n < 0)
	{
		printf("Êý¾Ý´íÎó!\n");
		return (0);
	}
	else if (n == 0 || n == 1)
		return (1);
	else return (fac(n - 1) * n);
}