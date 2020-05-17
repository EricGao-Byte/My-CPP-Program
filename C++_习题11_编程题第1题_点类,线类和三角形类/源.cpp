#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	Point(double x, double y);
	Point();
	void MovePoint(double add_x, double add_y);
	void PrintPoint();
	double GetX();
	double GetY();
	void SetX(double x);
	void SetY(double y);
	void SetPoint(Point);

private:
	double x_, y_;
};

class Line :public Point
{
public:
	Line(Point A, Point B);
	Line(){}
	Point GetLinePoint1();
	void GetLinePoint2(Point*);
	void PrintLine();
	double LineLength();
	void SetLine(Point, Point);
private:
	Point A_;  //已经有一个点,再加一个点组成一条边
};

class Triangle :public Line
{
public:
	Triangle(Point A, Point B, Point C);
	void PrintTrianglePoint();
	double TrianglePerimeter();
	void PrintTrianglePerimeter();
	double TriangleArea();
	void PrintTriangleArea();
private:
	Point A_;  //已经有一条边,再加一个点就可以组成一个三角形
};

int main()
{
	Point A(0,0), B(0, 5), C(12, 0);
	//Line AB(A, B);
	//AB.PrintLine();
	//cout << AB.LineLength() << endl;
	Triangle ABC(A, B, C);
	ABC.PrintTrianglePoint();
	ABC.PrintTrianglePerimeter();
	ABC.PrintTriangleArea();
	return 0;
}

inline Line::Line(Point A, Point B)
{
	SetPoint(A);
	A_ = B;
}

Point Line::GetLinePoint1()
{
	return A_;
}

void Line::GetLinePoint2(Point* p_B)
{
	p_B->SetX(GetX());
	p_B->SetY(GetY());
}
	

inline void Line::PrintLine()
{
	cout << "Line's point is:";
	PrintPoint();
	A_.PrintPoint();
}

inline double Line::LineLength()
{
	return sqrt((A_.GetX() - GetX()) * (A_.GetX() - GetX()) + (A_.GetY() - GetY()) * (A_.GetY() - GetY()));
}

void Line::SetLine(Point A ,Point B)
{
	SetPoint(A);
	A_ = B;
}

inline Point::Point(double x, double y)
{
	x_ = x;
	y_ = y;
}

inline Point::Point() { x_ = 0, y_ = 0; }

inline void Point::MovePoint(double add_x, double add_y)
{
	x_ += add_x;
	y_ += add_y;
}

inline void Point::PrintPoint()
{
	cout << "(" << x_ << ", " << y_ << ")";
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





inline Triangle::Triangle(Point A, Point B, Point C)
{
	SetLine(A, B);
	A_ = C;
}

inline void Triangle::PrintTrianglePoint()
{
	cout << "Triangle's point is:";
	PrintLine();
	A_.PrintPoint();
	cout << endl;
}

double Triangle::TrianglePerimeter()
{
	Point B, C;
	B = GetLinePoint1();
	GetLinePoint2(&C);
	Line AB(A_, B);
	Line AC(A_, C);
	return LineLength() + AB.LineLength() + AC.LineLength();
}

inline void Triangle::PrintTrianglePerimeter()
{
	cout << "Triangle's perimeter is:"<< TrianglePerimeter() << endl;
}

//利用海伦公式计算面积

double Triangle::TriangleArea()
{
	Point B, C;
	B = GetLinePoint1();
	GetLinePoint2(&C);
	Line AB(A_, B);
	Line AC(A_, C);
	double a = LineLength(), b = AB.LineLength(), c = AC.LineLength();
	return  0.25 * sqrt((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a));
}


inline void Triangle::PrintTriangleArea()
{
	cout << "Triangle's area is:" << TriangleArea() << endl;
}
