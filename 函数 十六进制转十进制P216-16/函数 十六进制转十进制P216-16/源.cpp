#include <stdio.h>

void change(int n)
{
	printf("����ʮ������Ϊ:%d", n);
}

int main()
{
	void change(int n);
	int num;
	printf("������һ��ʮ��������:");
	scanf_s("%x", &num);
	change(num);
	return 0;
}
