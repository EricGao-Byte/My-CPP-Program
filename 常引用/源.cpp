#include <iostream>
#include <math.h>
using namespace std;

void display(const double& r);

class A
{
public:
	A(int i, int j)
	{
		x = i;
		y = j;
	}
	void modify(int i, int j)
	{
		x = i;
		y = j;
	}
	void print()
	{
		cout << x << "," << y << endl;
	}
private:
	int x, y;
};
int main()
{
	A const a(3, 4);
	/*a.modify(4,5);*///a�ǳ�����,���ܱ�����


	double d(9.5);
	display(d);
	return 0;
}
void display(const double& r)
{
	//������������,�ں����в��ܸ���r�����õĶ���
	cout << r << endl;
	/*r++;*///r�ǳ���,�����Լ�
	cout << r << endl;
}