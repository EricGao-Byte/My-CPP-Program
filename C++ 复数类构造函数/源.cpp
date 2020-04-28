#include <iostream>
using namespace std;

template <typename T>
class Complex
{
private:
	T real, image;
public:
	Complex()//无参构造函数
	{
		cout << "调用无参构造函数" << endl;
		real = 1.5;
		image = 1.5;
	}
	Complex(T r, T i)//带参数构造函数
	{
		cout << "调用带参构造函数" << endl;
		real = r;
		image = i;
	}
	Complex(Complex& comp)
	{
		cout << "调用拷贝函数" << endl;
		real = comp.real;
		image = comp.image;
	}
	void SetReal(T r);
	void SetImage(T i);
	T GetReal();
	T GetImage();
	void PrintComplex();
};

int main()
{
	cout << "无参构造函数：" << endl;//调用无参函数
	Complex<double> complex_1;
	complex_1.PrintComplex();
	cout << endl;

	cout << "带参构造函数：" << endl;
	Complex<double> complex_2(3.5, 4.7);//调用有参函数
	complex_2.PrintComplex();
	cout << endl; 

	cout << "拷贝构造函数：" << endl;
	Complex<double> complex_A;//调用无参函数
	Complex<double> complex_B(complex_A);//调用拷贝函数
	complex_B.PrintComplex();
	cout << endl;
	return 0;
}

template<typename T>
void Complex<T>::SetReal(T r)
{
	real = r;
}

template<typename T>
void Complex<T>::SetImage(T i)
{
	image = i;
}

template<typename T>
T Complex<T>::GetReal()
{
	return real;
}

template<typename T>
T Complex<T>::GetImage()
{
	return image;
}

template<typename T>
void Complex<T>::PrintComplex()
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
