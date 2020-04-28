#include <iostream>

//using namespace std;//不要在头文件使用命名空间。会造成关键字错乱
int sum(int x,int y)
{
	int z;
	z = x + y;
	return z;
}
int main()
{
	int sum(int, int);
	int a, b, c;
	std::cout << "a= b=" << std::endl;
	std::cin >> a >> b;
	//std::cout << "b=";
	//std::cin >> b;
	c = sum(a, b);
	std::cout << "a + b= " << c << std::endl;
	return 0;
}