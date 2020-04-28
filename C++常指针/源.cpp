#include <iostream>
using namespace std;

int main()
{
	//常量指针
	const int* pt_int;
	int a = 10;
	const int b = 20;
	pt_int = &a;//可以将const int 指针指向一个变量
	pt_int = &b;//也可以改变指针指向,让他指向一个常量
	//*pt_int = 20;错误:不可以改变const int指针所指向的值
	a = 30;//但是改变本身的值与指针无关

	//指针常量
	int* const constpt_int = &a;//指针常量定义时必须初始化
	*constpt_int = 30;//合法,通过指针给变量赋值
	//constpt_int = &b;错误:不能改变指针常量的指向

	//指向指针常量的指针常量
	const int* const constpt_int = &a;
	//不能改变指针指向的量,也不能改变指针的指向
	//只可以读取,不可以改变,也就是使变量只读

	
	return 0;
}