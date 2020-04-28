#include <stdlib.h>
#include <iostream>

using namespace  std;

namespace A
{
	int x = 10;
	void fun()
	{
		cout << "A" << endl;
	}
}

namespace B
{
	int x = 10000;
	void fun()
	{
		cout << "B" << endl;
		//A::x;
		//B::fun();//一个命名空间里可以支持其他命名空间的函数和变量
	}
	void fun2()
	{
		cout << "fun2B" << endl;
	}
}
using namespace A;//也可手动引入命名空间 这样fun2（）函数可以不指明命名空间也可使用
					//同理 也可以不引入namespace std，使用std：：也可以使用cout和cin
using namespace B;//但是若引入的两个命名空间中含有相同的元素，则还是需要声明命名空间
int main()
{
	fun2();
	cout << A::x << endl;
	cout << B::x << endl;
	B::fun();//利用namespace可以调用不同命名空间里的相同的函数或者变量
	//A::fun();
	system("pause");
	return 0;
}