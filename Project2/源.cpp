#include <iostream>

using namespace std;
inline double max(double x, double y, double z)
{
	double i;
	if (x >= y)
		i = x;
	else
		i = y;
	if (i >= z)
		return i;
	return z;
}
int main()
{
	double a, b, c;
	double max1;
	cout << "�������������Ƚϴ�С��" << endl;
	cin >> a >> b >> c;
	max1 = max(a, b, c);
	cout << "�����Ϊ��" << max1 << endl;
	return 0;
}