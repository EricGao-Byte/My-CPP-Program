#include <stdio.h>

int judge(int y, int m, int d)
{
	int i,sum=0;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sign = 0;//判断是否是闰年的标识符
	sign = y % (y % 100 ? 4 : 400) ? 0 : 1;
	if (sign == 1)
		month[1] = 29;
	for (i = 0; i < m - 1; i++)
		sum += month[i];
	return (sum += d);
}
int main()
{
	int judge(int y, int m, int d);
	int y, m, d;//年 月 日
	printf("请输入年,月,日:");
	scanf_s("%d%d%d", &y, &m, &d);
	printf("%d月,%d日是%d年的第%d天", m, d, y, judge(y, m, d));
	return 0;
}