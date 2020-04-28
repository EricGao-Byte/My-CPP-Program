#include <iostream>
#include <stdlib.h>

using namespace std;
//C++ 中 using namespace std 到底是什么意思？
//
//声明一个命名空间的意思。命名空间在多人合作的时候很有用，因为你定义了变量 a，别人也定义了变量 a，这样就重复定义了。如果你在自己的命名空间中定义了 a，别人在别人的命名空间中定义了 a，这样就不重复了，比如：
//
//using namespace xx;
//using namespace yy;
//xx::a 和 yy::a 虽然都叫 a，但是不是同一个变量。

int main()
{
	int a, b;
	/*cout << "Hello world!"
		<< endl
		<< "Hello Eric!"
		<< endl
		<< "Welcome to my world!\n";
	system("pause");*/
	cout << "Please input a number:"
		<<endl;
	cin >> a;
	cout << "You input number is:" << a << '\n';
	return 0;
}
