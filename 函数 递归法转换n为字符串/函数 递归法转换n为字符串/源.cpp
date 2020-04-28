#include <stdio.h>

int i,j;
void reverse(int n)
{
	if ((i = n / 10) != 0)
		reverse(i);
	putchar(n % 10 + 48);
}
int main()
{
	void reverse(int n);
	int n;
	printf("请输入一个整数:");
	scanf_s("%d", &n);
	if (n < 0)
	{
		printf("-");
		n = -n;
	}
	reverse(n);
	return 0;
}