#include <iostream>

using namespace std;
void min(double x, double y)
{
	if (x <= y)
		cout << "������ʵ����С��Ϊ:" << x << endl;
	else
		cout << "������ʵ����С��Ϊ:" << y << endl;
}
void min(int x, int y)
{
	if (x <= y)
		cout << "������������С��Ϊ:" << x << endl;
	else
		cout << "������������С��Ϊ:" << y << endl;
}
int main()
{
	cout << "---------------�Ƚ����ִ�С------------------" << endl;
	double a, b;
	cout << "����������ʵ����" << endl;
	cin >> a >> b;
	min(a, b);
	int c, d;
	cout << "����������������" << endl;
	cin >> c >> d;
	min(c, d);
	/*cout << "������ʵ����С��Ϊ:" << min(c, d) << endl;*/
	cout << "---------------�������------------------" << endl;

	return 0;
}