#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double real=0.0, double image=0.0)
	{
		real_ = real;
		image_ = image;
	}
	Complex operator + (Complex c2);  //+重载为成员函数
	Complex operator - (Complex c2);  //-重载为成员函数
	//Complex operator ++ ();  //重载前置++ 
	//Complex operator ++ (int);  //加int以区分前置和后置
	friend Complex operator * (Complex c1, Complex c2);
	friend Complex operator / (Complex c1, Complex c2);
	void printComplex();
private:
	double real_, image_;
};


int main()
{
	Complex c1(2.0, -3.0);
	Complex c2(1.0, 1.0);
	Complex c3;
	cout << "c1= "; c1.printComplex();
	cout << "c2= "; c2.printComplex();
	c3 = c1.operator-(c2);  //相当于c3=c1-c2;
	cout << "c1-c2= "; c3.printComplex();
	c3 = c1 + c2;  //编译器将运算符重载,表达式变为c3=c1.operator+(c2)
	cout << "c1+c2= "; c3.printComplex();
	c3 = c1 * c2;  //友元函数重载*
	cout << "c1*c2= "; c3.printComplex();
	c3 = c1 / c2;
	cout << "c1/c2= "; c3.printComplex();

}

Complex Complex::operator+(Complex c2)  //+重载函数
{
	Complex c;
	c.real_ = c2.real_ + real_;  //real_为c1的real
	c.image_ = c2.image_ + image_;
	return c;
}

Complex Complex::operator-(Complex c2)
{
	Complex c;
	c.real_ = c2.real_ - real_;  //real_为c1的real
	c.image_ = c2.image_ - image_;
	return c;
}

void Complex::printComplex()
{
	if (image_ >= 0)
	{
		cout << "(" << real_ << "+" << image_ << "i)" << endl;
	}
	else
	{
		cout << "(" << real_ << image_ << "i)" << endl;
	}
}

Complex operator*(Complex c1, Complex c2)
{
	Complex c3;
	c3.real_ = c1.real_ * c2.real_ - c1.image_ * c2.image_;
	c3.image_ = c1.real_ * c2.image_ + c1.image_ * c2.real_;
	return c3;
}

Complex operator/(Complex c1, Complex c2)
{
	Complex c3;
	c3.real_ = (c1.real_ * c2.real_ + c1.image_ * c2.image_) / (c2.real_ * c2.real_ + c2.image_ * c2.image_);
	c3.image_ = (c1.image_ * c2.real_ - c1.real_ * c2.image_) / (c2.real_ * c2.real_ + c2.image_ * c2.image_);
	return c3;
}
