#include <iostream>
using namespace std;

void min(int a,int b)
{
	if (a >= b)
	{
		cout << "min(a,b)=" << b << endl;
	}
	else
	{
		cout << "min(a,b)=" << a << endl;
	}
}
void min(double a,double b)
{
	if (a >= b)
	{
		cout << "min(a,b)=" << b << endl;
	}
	else
	{
		cout << "min(a,b)=" << a << endl;
	}
}

int main()
{
	int A, B;
	cout << "input two integers:" << endl;
	cin >> A >> B;
	min(A, B);
	double C, D;
	cout << "input two real number:" << endl;
	cin >> C >> D;
	min(C, D);
	return 0;
}