#include <iostream>
using namespace std;
int main()
{
	int i, n;
	double m, x[20], y[20], s;
	cout << "输入节点数目: " << endl;
	cin >> n;
	cout << "输入节点数值: " << endl;
	for ( i = 0; i <= n; i++)
	{
		cout << "x[" << i << "],y[" << i << "]: ";
		cin >> x[i] >> y[i];
	}
	cout << "输入要求的值: ";
	cin >> m;
	for ( i = 0; i <= n; i++)
	{
		if (m < x[i])
		{
			s = y[i - 1] * (m - x[i]) / (x[i - 1] - x[i]) + y[i] * (m - x[i - 1]) / (x[i] - x[i - 1]);
			break;
		}
	}
	cout << "Linear Interpolation(" << m << ")=" << s << endl;
}