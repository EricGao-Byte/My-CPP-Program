#include <iostream>
using namespace std;

int main()
{
	void PrintNum();
	PrintNum();
	return 0;
}

void PrintNum()
{
	int isNum(int);//判断完数 是1 不是0
	void PrintFac(int);//打印因子
	int i;
	for (i = 1; i <= 1000; i++)
	{
		if (isNum(i) == 1)
		{
			cout << i << "   " << "its factors are:";
			PrintFac(i);
			cout << endl;
		}
	}
}

int isNum(int i)
{
	int fac_sum = 0;
	int n;
	for ( n = 1; n < i; n++)
	{
		if (i % n == 0)
		{
			fac_sum += n;
		}
	}
	if (i == fac_sum)
		return 1;
	else
		return 0;
}
void PrintFac(int i)
{
	int n;
	for ( n = 1; n < i; n++)
	{
		if (i % n == 0)
		{
			cout << "   " << n;
		}
	}
}
