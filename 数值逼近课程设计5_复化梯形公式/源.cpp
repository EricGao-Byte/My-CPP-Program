#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int i, n;
	double a, b, h, sum = 0;
	double y[20];
	double x[20] = {-4.267,-3.556,-2.845,-2.134,-1.422,-0.711,0,0.711,1.422,2.134,2.845,3.556,4.267};
	for ( i = 0; i < 13; i++)
	{
		y[i] = -0.0033 * (pow(x[i], 5)) - 0.0052 * pow(x[i], 4) + 0.0552 * pow(x[i], 3) - 0.4666 * pow(x[i], 2) + 0.0572 * x[i] + 9.6819;
	}
	cout << "输入所求多项式区间(a,b)和等分的份数: ";
	cin >> a >> b >> n;
	h = (b - a) / n;
	for ( i = 0; i < n; i++)
	{
		sum += y[i];
	}
	sum = (h / 2) * (y[0] + y[n] + 2 * sum);
	cout << "sum=" << sum << endl;
	return 0;
}