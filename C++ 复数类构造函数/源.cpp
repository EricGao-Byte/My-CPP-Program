#include <iostream>
using namespace std;

template <typename T>
class Complex
{
private:
	T real, image;
public:
	Complex()//�޲ι��캯��
	{
		cout << "�����޲ι��캯��" << endl;
		real = 1.5;
		image = 1.5;
	}
	Complex(T r, T i)//���������캯��
	{
		cout << "���ô��ι��캯��" << endl;
		real = r;
		image = i;
	}
	Complex(Complex& comp)
	{
		cout << "���ÿ�������" << endl;
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
	cout << "�޲ι��캯����" << endl;//�����޲κ���
	Complex<double> complex_1;
	complex_1.PrintComplex();
	cout << endl;

	cout << "���ι��캯����" << endl;
	Complex<double> complex_2(3.5, 4.7);//�����вκ���
	complex_2.PrintComplex();
	cout << endl; 

	cout << "�������캯����" << endl;
	Complex<double> complex_A;//�����޲κ���
	Complex<double> complex_B(complex_A);//���ÿ�������
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
