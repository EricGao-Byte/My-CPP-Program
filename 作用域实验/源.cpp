#include <iostream>
using namespace std;

int abc = 100;//定义一个全局变量abc
int sum(int a,int b)
{
	static int sum1;//定义静态变量 以便下次调用函数还能使用 注意：其他函数依然无法引用与全局变量不同
	sum1 = a + b + sum1;
	return sum1;
}

int main()
{
	//静态变量作用域使用
	int n;
	n = sum(10, 20);
	cout << n << endl;
	n = sum(30, 40);
	cout << n << endl;





	/*int a = 10, b = 20;
	cout << a << b << endl;
	{
		int a = 0;
		int b = 30;
		cout << a << b << endl;
	}
	cout << a << b << endl;*/
	//for循环作用域
	/*int i = 10;
	for (int i = 0; i < 5; i++)
	{
		cout << i << endl;
	}
	cout << i << endl;*/
	//如何用：：访问全局变量
	//int abc = 50;
	//cout << abc << endl;
	//abc += 1;
	//cout << abc << endl;
	//cout << ::abc << endl;
	//::abc += ::abc;
	//cout << ::abc << endl;
	//cout << abc << endl;

	return 0;
}