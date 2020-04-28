#include <iostream>
#include <math.h>
using namespace std;

class Point
{
	friend class Slope;

private:
	double X, Y;

public:
	Point(double xi, double yi)
	{
		X = xi;
		Y = yi;
	}
	double GetX()
	{
		return X;
	}
	double GetY()
	{
		return Y;
	}
	/*friend */static double Distance(Point& a, Point& b);
	//������һ��Point�����Ԫ����,����ֱ�ӷ���private��protected�����ݶ���
};
class Slope
{
private:
	Point a, b;

public:
	void InputPoint(Point A, Point B)
	{
		a.X = A.X;
		a.Y = A.Y;
		b.X = B.X;
		b.Y = B.Y;
	}
	void PrintSlope()
	{
		double slope;
		slope = (a.X = b.X) / (a.Y - b.Y);
		cout << slope;
	}
};


int main()
{
	Point A(1, 1), B(4, 5);
	cout <<"A(1, 1), B(4, 5)����Ϊ:"<< Point::Distance(A, B) << endl;

	return 0;
}

double Point::Distance(Point& a, Point& b)
{
	double dx = a.X - b.X;
	double dy = a.Y - b.Y;
	return sqrt(dx * dx + dy * dy);
}
