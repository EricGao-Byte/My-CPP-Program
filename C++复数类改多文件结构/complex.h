#include <iostream>
using namespace std;

class Complex
{

public:
	void SetReal(double r);
	void SetImage(double i);
	double GetReal();
	double GetImage();
	void PrintComplex();
	friend void Output(Complex& complex);//定义友元函数:输出复数类对象
private:
	double real, image;
}; 

void Complex::SetReal(double r)
{
	real = r;
}

void Complex::SetImage(double i)
{
	image = i;
}

double Complex::GetReal()
{
	return real;
}

double Complex::GetImage()
{
	return image;
}

void Complex::PrintComplex()
{
	if (image == 0)
	{
		cout << real << endl;
	}
	else if (image > 0)
	{
		cout << real << "+" << image << "i" << endl;
	}
	else
	{
		cout << real << image << "i" << endl;
	}
}

void Output(Complex& complex)
{
	if (complex.image >= 0)
	{
		cout << "complex is:"
			<< complex.real << "+"
			<< complex.image << endl;
	}
	else
	{
		cout << "complex is:"
			<< complex.real
			<< complex.image << endl;
	}
}
