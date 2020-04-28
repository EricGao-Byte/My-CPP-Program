#include <iostream>
#include <math.h>
using namespace std;

void display(const double& r);

class A
{
public:
	A(int i, int j)
	{
		x = i;
		y = j;
	}
	void modify(int i, int j)
	{
		x = i;
		y = j;
	}
	void print()
	{
		cout << x << "," << y << endl;
	}
private:
	int x, y;
};
int main()
{
	A const a(3, 4);
	/*a.modify(4,5);*///a是常对象,不能被更新


	double d(9.5);
	display(d);
	return 0;
}
void display(const double& r)
{
	//常引用做参数,在函数中不能更新r所引用的对象
	cout << r << endl;
	/*r++;*///r是常量,不能自加
	cout << r << endl;
}