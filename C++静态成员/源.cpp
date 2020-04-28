#include<iostream>
using namespace std;

class Application
{
public:
	static void f();//定义静态成员函数
	static void g();
private:
	static int global;
};
int Application::global = 0;//定义了一个静态数据成员,而且一定要在类外定义
void Application::f()
{
	global = 5;
}
void Application::g()
{
	cout << global << endl;
}

int main()
{

	Application::f();//定义了静态函数成员之后,类外可以直接使用函数名来进行调用
	Application::g();//若不是静态函数,则只能定义一个对象,用对象来调用函数,例如Application a.f()
	return 0;
}
