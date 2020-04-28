#include <iostream>

using namespace std;

template <typename T>//编译器根据调用abs()时实参的类型，推导出函数模板的类型参数。
//例如，对于调用表达式abs(n)，由于实参n为int型，所以推导出模板中类型参数T为int。
//模板进一步简化了重载函数的设计 使得同一种功能的重载函数不用写多个函数 现在写一个函数就搞定了
T abs(T x,T y)
{
	return x / y;
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << abs(a, b);
	return 0;
}