#include <iostream>
using namespace std;
//求(1+x)x在(a,b)上的定积分

class Integral
{
public:
	Integral(double A=0, double B=0)//构造函数
	{
		a = A;
		b = B;
		f = -13323;
	}
	void calc();
	void print_result();
private:
	double a, b, f;//f为定积分的值
};

int main()
{
	Integral integral(1, 3);
	integral.calc();
	integral.print_result();
	return 0;
}



void Integral::calc()
{
	double accurac = 0.0000001;//精度
	double n = (b - a) / accurac;
	int i;
	double sum = 0;
	double a1 = a;
	for ( i = 1; i < n; i++)
	{
		sum += (a1 + 1) * a1 * accurac;
		a1 += accurac;
	}
	f = sum;
}

void Integral::print_result()
{
	cout << "(1+x)x在("
		<< a << "," << b
		<< ")上的积分为:" << endl << f;
}
