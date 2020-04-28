#include <iostream>

using namespace std;

//当函数传递的参数缺失时 会使用默认定义的函数参数值 这就叫缺省形参
//缺省形参值必须从右向左顺序定义，并且在缺省形参值的右面不能有非缺省形参值定义。
//调用时实参取代形参是从左向右的顺序

int main()
{
	int add(int x = 5, int y = 6);//函数声明中如果带缺省形参，且此时缺省形参以函数声明为准，函数中定义的缺省形参作废
	int a = 10, b = 20;
	cout << add(a, b) << endl;//参数不缺失 不使用缺省形参
	cout << add(a) << endl;//第二个参数缺失 使用第二个缺省形参 
	cout << add() << endl;
	return 0;
}
int add(int x = 1000, int y = 100000)
{
	return x + y;
}
