#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	Point(double x=0, double y=0);
	void MovePoint(double add_x, double add_y);
	void PrintPoint();
	double GetX();
	double GetY();
	void SetX(double x);
	void SetY(double y);
	void SetPoint(Point);
	void operator ++();  //前置++
	void operator ++(int);  //后置++
	friend void operator --(Point&); //前置--
	friend void operator --(Point&,int);  //后置--
private:
	double x_, y_;
};

int main()
{
	Point A(1, 1);
	cout << "A: ", A.PrintPoint();
	++A, A.PrintPoint();
	A++, A.PrintPoint();
	--A, A.PrintPoint();
	A--, A.PrintPoint();
	return 0;
}

inline Point::Point(double x, double y)
{
	x_ = x;
	y_ = y;
}

inline void Point::MovePoint(double add_x, double add_y)
{
	x_ += add_x;
	y_ += add_y;
}

inline void Point::PrintPoint()
{
	cout << "(" << x_ << ", " << y_ << ")" << endl;
}

inline double Point::GetX() { return x_; }

inline double Point::GetY() { return y_; }

inline void Point::SetX(double x) { x_ = x; }

inline void Point::SetY(double y) { y_ = y; }

void Point::SetPoint(Point point)
{
	SetX(point.GetX());
	SetY(point.GetY());
}

void Point::operator++()
{
	++x_;
	++y_;
	cout << "++Point: ";
}

void Point::operator++(int)
{
	x_++;
	y_++;
	cout << "Point++: ";
}

void operator--(Point &A)
{
	A.SetX(A.GetX() - 1);
	A.SetY(A.GetY() - 1);
	cout << "--Point: ";
}

void operator--(Point &A, int)
{
	A.SetX(A.GetX() - 1);
	A.SetY(A.GetY() - 1);
	cout << "Point--: ";
}
