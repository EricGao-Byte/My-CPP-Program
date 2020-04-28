#include <iostream>
using namespace std;

int main()
{
	void cal_ex(double*,int);
	double ex=0;
	int x;
	cout << "to calculate e^x,input times x:" << endl;
	cin >> x;
	cal_ex(&ex, x);
	cout << "e^" << x << "=" << ex << endl;
	return 0;
}

void cal_ex(double* ex, int x)
{
	double pow(int x, int i);
	double fac(int i);
	int i=0;
	double ex1;
	do
	{
		ex1 = pow(x, i) / fac(i);
		*ex += ex1;
		i++;
	} while (ex1>0.000001||ex1<-0.000001);
}
double pow(int x, int i)
{
	double pow=1;
	if (x == 0)
	{
		return pow;
	}
	else
	{
		int n;
		for (n = 1; n <= i; n++)
		{
			pow *= x;
		}
	}
	return pow;
}
double fac(int i)
{
	double fac = 1;
	int n;
	for (n = 1; n <= i; n++)
	{
		fac *= n;
	}
	return fac;
}
