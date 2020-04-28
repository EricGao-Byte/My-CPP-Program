#include <stdio.h>

void change(int n)
{
	printf("它的十进制数为:%d", n);
}

int main()
{
	void change(int n);
	int num;
	printf("请输入一个十六进制数:");
	scanf_s("%x", &num);
	change(num);
	return 0;
}
