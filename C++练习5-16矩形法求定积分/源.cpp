#include <iostream>
using namespace std;
//��(1+x)x��(a,b)�ϵĶ�����

class Integral
{
public:
	Integral(double A=0, double B=0)//���캯��
	{
		a = A;
		b = B;
		f = -13323;
	}
	void calc();
	void print_result();
private:
	double a, b, f;//fΪ�����ֵ�ֵ
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
	double accurac = 0.0000001;//����
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
	cout << "(1+x)x��("
		<< a << "," << b
		<< ")�ϵĻ���Ϊ:" << endl << f;
}
