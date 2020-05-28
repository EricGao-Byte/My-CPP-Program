#include <iostream>
using namespace std;

class Complex
{

public:
	Complex(double real = 0.0, double image = 0.0)
	{
		real_ = real;
		image_ = image;
	}
	void SetReal(double r);
	void SetImage(double i);
	double GetReal();
	double GetImage();
	void PrintComplex();
	void operator = (Complex c2);
	void operator += (Complex c2);
	friend Complex operator + (Complex c1, Complex c2);
	friend Complex operator - (Complex c1, Complex c2);
private:
	double real_, image_;
};

int main()
{
	Complex c1,c2(2,4);
	cout << "c1: "; c1.PrintComplex();
	cout << " c2: "; c2.PrintComplex(); cout << endl;
	c1 = c2;
	cout << "c1=c2 ";	
	cout << "c1: "; c1.PrintComplex();
	cout << " c2: "; c2.PrintComplex(); cout << endl;
	c1 += c2;
	cout << "c1+=c2 ";
	cout << "c1: "; c1.PrintComplex();
	cout << " c2: "; c2.PrintComplex(); cout << endl;

	Complex c3;
	c3 = c1 + c2;
	cout << "c3=c1+c2 ";
	cout << "c1: "; c1.PrintComplex();
	cout << " c2: "; c2.PrintComplex();
	cout << " c3: "; c3.PrintComplex(); cout << endl;	
	c3 = c1 - c2;
	cout << "c3=c1-c2 ";
	cout << "c1: "; c1.PrintComplex();
	cout << " c2: "; c2.PrintComplex();
	cout << " c3: "; c3.PrintComplex(); cout << endl;
	return 0;
}

void Complex::SetReal(double r)
{
	real_ = r;
}

void Complex::SetImage(double i)
{
	image_ = i;
}

double Complex::GetReal()
{
	return real_;
}

double Complex::GetImage()
{
	return image_;
}

void Complex::PrintComplex()
{

	if (image_ >= 0)
	{
		cout << "(" << real_ << "+" << image_ << "i" << ")";
	}
	else
	{
		cout << "(" << real_ << image_ << "i" << ")";
	}
}

void Complex::operator=(Complex c2)
{
	real_ = c2.GetReal();
	image_ = c2.GetImage();
}



void Complex::operator+=(Complex c2)
{
	real_ += c2.GetReal();
	image_ += c2.GetImage();
}

Complex operator+(Complex c1, Complex c2)
{
	Complex c;
	c.real_ = c2.real_ + c1.real_;  
	c.image_ = c2.image_ + c1.image_;
	return c;
}

Complex operator-(Complex c1, Complex c2)
{
	Complex c;
	c.real_ = c1.real_ - c2.real_;
	c.image_ = c1.image_ - c2.image_;
	return c;
}
