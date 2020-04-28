#include <iostream>
using namespace std;

template <typename T>
class Complex
{

public:
	void SetReal(T r);
	void SetImage(T i);
	T GetReal();
	T GetImage();
	void PrintComplex();
	friend void Output<Complex>(Complex& complex);
private:
	T real, image;
};

int main()
{
	Complex<double> complex;
	complex.SetReal(3.45);
	complex.SetImage(384.5);
	cout << "real part:" << complex.GetReal() << endl;
	cout << "image part:" << complex.GetImage() << endl;
	complex.PrintComplex();
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


