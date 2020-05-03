#include <iostream>
using namespace std;

char* find(char* str, char ch)//指针函数,返回值为指针的函数
{
	return str;
}

void print_stuff(float data_to_ignore)
{
	cout << data_to_ignore << " to ignore." << endl;
}
void print_message(float list_this_data);
void print_float(float data_to_print);
void (*function_pointer)(float);//void型指针可以指向任何对象,也可以指向除成员函数外的函数对象


int main()
{
	const float pi = 3.14159;
	float two_pi = 2.0 * pi;
	function_pointer = print_stuff;//将void型指针指向函数
	function_pointer(3.0);
	function_pointer = print_float;//且指针可以重新指向另一个函数
	return 0;
}