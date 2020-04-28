#include <iostream>
using namespace std;

int main()
{
	void printNum();
	printNum();
	return 0;
}
void printNum()
{
	int i;
	int n = 0;
	cout << "1~1000 prime number:" << endl;
	//代码改进
	for (i = 1; i <= 1000; i++)
	{
		int flag = 0;
		int n = 2;
		while (n<i)
		{
			if (i % n == 0)
			{
				flag = 1;
				break;
			}
			n++;
		}
		if (flag == 0)
		{
			cout << " " << i;
		}
	}
	//落后代码
	/*for (i = 1; i <= 1000; i++)
	{
		int flag = 0;
		for (j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				if (j != 1 && j != i)
				{
					flag = 1;
				}
			}
			if (flag == 1)
				break;
		}
		if (flag == 0)
		{
			n++;
			if (n % 5 == 0)
				cout << endl;
			cout << " " << i;
		}
	}*/
}