#include <iostream>
using namespace std;

void swap(double& x, double& y)
{
	double i;
	i = x;
	x = y;
	y = i;
}

int main()
{
	double a, b;
	cout << "please input two numbers:" << endl;
	cin >> a >> b;
	swap(a, b);
	cout << "the swaped two numbers is:"<<endl << a <<" "<< b << endl;
	return 0;
}