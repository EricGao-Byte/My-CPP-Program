#include <stdio.h>

struct date
{
	int year;
	int month;
	int day;
};
int main()
{
	int judge(struct date b);
	struct date a;
	printf("please input year month day:");
	scanf_s("%d%d%d", &a.year, &a.month, &a.day);
	printf("Year:%d of Month:%d of Day:%d\nthe %d day of the year.", a.year, a.month, a.day, judge(a));
	return 0;
}
int judge(struct date b)
{
	int i, sum = 0;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sign = 0;//判断是否是闰年的标识符
	sign = b.year % (b.year % 100 ? 4 : 400) ? 0 : 1;
	if (sign == 1)
		month[1] = 29;
	for (i = 0; i < b.month - 1; i++)
		sum += month[i];
	return (sum += b.day);
}