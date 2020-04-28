#include <iostream>
using namespace std;

inline void max(double x, double y, double z)
{
	double max;
	if (x >= y)
	{
		max = x;
		if (z >= x)
		{
			max = z;
		}
	}
	else
	{
		max = y;
		if (z >= y)
		{
			max = z;
		}
	}
	cout << "max number:" << max << endl;
}

int main()
{
	void max(double, double, double);
	double a, b, c;
	cout << "input three numbers:" << endl;
	cin >> a >> b >> c;
	max(a, b, c);
	return 0;
}