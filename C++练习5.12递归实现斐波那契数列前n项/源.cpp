#include <iostream>
using namespace std;

int fib(int n)//返回n对应的数列的值
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return (fib(n - 1) + fib(n - 2));
	}
}
void PrintFibonacci(int n)//打印斐波那契数列
{
	for (int i = 1; i <= n; i++)
	{
		cout << " " << fib(i);
	}
	
}

int main()
{
	int n;
	cout << "to show Fibonacci array,input n(n>0):" << endl;
	cin >> n;
	PrintFibonacci(n);
	return 0;
}