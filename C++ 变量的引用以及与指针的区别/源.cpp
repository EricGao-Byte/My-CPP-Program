#include <stdlib.h>
#include <iostream>

using namespace  std;

int main()
{
	int a = 10;
	int& b = a;
	int* c = &a;
	const int x = 100;
	int& y = x;
	//b = 10;
	//cout << a << endl;
	/*cout << &b << endl;
	cout << &a << endl;
	cout << *c << endl;
	cout << *(c + 1) << endl;*///引用与指针的区别：低层实现基本相同，区别在于引用无法移动指向的地址，是死指针
	//(2)可以有const指针，但是没有const引用；

	//(3)指针可以有多级，但是引用只能是一级（int** p；合法 而 int&& a是不合法的）

	//(4)指针的值可以为空，但是引用的值不能为NULL，并且引用在定义的时候必须初始化；

	//(5)指针的值在初始化后可以改变，即指向其它的存储单元，而引用在进行初始化后就不会再改变了。

	//(6)"sizeof引用"得到的是所指向的变量(对象)的大小，而"sizeof指针"得到的是指针本身的大小；

	//(7)指针和引用的自增(++)运算意义不一样；
	return 0;
}