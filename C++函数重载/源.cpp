#include <iostream>

using namespace std;
void min(double x, double y)
{
	if (x <= y)
		cout << "这两个实数较小数为:" << x << endl;
	else
		cout << "这两个实数较小数为:" << y << endl;
}
void min(int x, int y)
{
	if (x <= y)
		cout << "这两个整数较小数为:" << x << endl;
	else
		cout << "这两个整数较小数为:" << y << endl;
}
int main()
{
	cout << "---------------比较数字大小------------------" << endl;
	double a, b;
	cout << "请输入两个实数：" << endl;
	cin >> a >> b;
	min(a, b);
	int c, d;
	cout << "请输入两个整数：" << endl;
	cin >> c >> d;
	min(c, d);
	/*cout << "这两个实数较小数为:" << min(c, d) << endl;*/
	cout << "---------------程序结束------------------" << endl;

	return 0;
}