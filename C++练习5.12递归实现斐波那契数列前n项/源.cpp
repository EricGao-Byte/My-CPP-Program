#include <iostream>
using namespace std;

int fib(int n)//����n��Ӧ�����е�ֵ
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
void PrintFibonacci(int n)//��ӡ쳲���������
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