#include <stdio.h>
struct time
{
	int hour;
	int minute;
	int second;
};
struct date
{
	int year;
	int month;
	int day;
	struct time* t;
};
void printc(struct date x)
{
	printf("%dÄê%dÔÂ%dÈÕ%d:%d:%d", x.year, x.month, x.day, x.t->hour, x.t->minute, x.t->second);
}
int main()
{
	void printc(struct date x);
	struct date a = {0};
	struct time b;
	a.t = &b;
	a.year = 2019;
	a.month = 12;
	a.day = 2;
	a.t->hour = 15;
	a.t->second = 45;
	a.t->minute = 43;
	printc(a);
	return 0;
}