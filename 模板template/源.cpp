#include <iostream>

using namespace std;

//编译器根据调用abs()时实参的类型，推导出函数模板的类型参数。
//例如，对于调用表达式abs(n)，由于实参n为int型，所以推导出模板中类型参数T为int。
//模板进一步简化了重载函数的设计 使得同一种功能的重载函数不用写多个函数 现在写一个函数就搞定了
template <typename T>
T abs(T x,T y)
{
	return x / y;
}
template <typename T>  //模板函数的重载
T abs(T x, char y)
{
	return x / y;
}
template <typename T1,typename T2>  //多个模板类型,允许T1,T2类型相同
T1 abs(T1 x, T2 y)
{
	return x / y;
}

template <typename T>
void Swap(T& a, T& b) 
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	//int a, b;
	//cin >> a >> b;
	//cout << abs(a, b)<<endl;  //系统根据实参的类型,生成重载函数
	//Swap(a, b);
	//cout << "a:" << a <<" "<< "b:" << b << endl;

	/*double c, d;
	cin >> c >> d;
	cout << abs(c, d) << endl;
	char e;
	cin >> e;
	cout << abs(c, e);*/

	double A;
	int B;
	cin >> A >> B;
	cout << abs(A, B);
	return 0;
}