//hex:16  oct:8   dec:10
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//int a = 10, b = 20, c = 30, d = 40;
	int a, b, c, d;
	cin >> hex >> a;//按十六进制读取
	cin >> oct >> b;//按八进制读取
	cin >> c;//依然按照八进制读取
	cin >> dec >> d;//按十进制读取
	cout.setf(ios::scientific);
	cout << a <<" "<< b <<" "<< c <<" "<< d << endl;//输出默认是十进制输出
	//cout << hex << d << endl;
	//cout << c;


	//cin.ignore(n) ：由输入起始位置跳过n个字符后读入
/*	string a, b;
	cin.ignore(3) >> a;
	cin.ignore(3) >> b;
	cout << a <<setw(10)<< b;*///包含于iomanip库中，控制格式输出，默认输出空格
	//int c;
	//cin.ignore(3) >> c;
	//cout << c;
	return 0;
}