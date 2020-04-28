#include <iostream>

using namespace std;
int add(int x, int y)
{
	return x - y;
}
int add(int x, int y, int z)
{
	return x + y + z;
}
double add(double x, double y)
{
	return x * y;
}
int main()
{
	int a = 10, b = 20, c = 30;
	cout << add(a, b, c) << endl;//函数重载：函数的个数不同
	cout << add(a, b) << endl;
	double d = 40, e = 50;
	cout << add(d, e) << endl;//函数重载：函数的类型不同
	return 0;
}