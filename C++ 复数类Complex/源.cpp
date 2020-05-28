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

private:
	double real_, image_;
};

int main()
{
	Complex complex;
	complex.SetReal(3.45);
	complex.SetImage(384.5);
	cout << "real part:" << complex.GetReal() << endl;
	cout << "image part:" << complex.GetImage() << endl;
	complex.PrintComplex();
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
	if (image_ == 0)
	{
		cout << real_ << endl;
	}
	else if (image_ > 0)
	{
		cout << real_ << "+" << image_ << "i" << endl;
	}
	else
	{
		cout << real_ << image_ << "i" << endl;
	}
}




