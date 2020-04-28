#include <stdio.h>

int main()
{
	double sqrt(double);
	double n;
	printf("please input a number to square root:\n");
	scanf_s("%lf", &n);
	printf("¡Ì%.2lf=%.8lf", n, sqrt(n));
	return 0;
}
double sqrt(double a)
{
	double x, x1, x2;
	x1 = a / 2;
	do
	{
		x2 = 0.5 * (x1 + a / x1);
		x = x1;
		x1 = x2;
	} while ((x2 - x) > 0.000000001 || (x2 - x) < -0.000000001);
	return (x2);
}