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

private:
	double x_, y_;
};

class Line :public Point
{
public:
	Line(Point A, Point B);
	Line();
	void PrintPoint();
	double LineLength();

private:
	Point A_, B_;
};

class Triangle :public Line
{
public:
	Triangle(Point A, Point B, Point C);
	void PrintPoint();
	double TrianglePerimeter();
	void PrintTrianglePerimeter();
	double TriangleArea();
	void PrintTriangleArea();
private:
	Point A_, B_, C_;
	Line AB_, AC_, BC_;
};

int main()
{
	Point A(0,0), B(0, 4), C(3, 0);
	//Line AB(A, B);
	//AB.PrintPoint();
	//cout << AB.LineLength() << endl;
	Triangle ABC(A, B, C);
	ABC.PrintPoint();
	ABC.PrintTrianglePerimeter();
	ABC.PrintTriangleArea();
	return 0;
}

inline Line::Line(Point A, Point B)
{
	A_ = A;
	B_ = B;
}

inline Line::Line() { A_.SetX(0), A_.SetY(0), B_.SetX(0), B_.SetY(0); }

inline void Line::PrintPoint()
{
	cout << "Line's point is:";
	A_.PrintPoint();
	B_.PrintPoint();
	cout << endl;
}

inline double Line::LineLength()
{
	return sqrt((A_.GetX() - B_.GetX()) * (A_.GetX() - B_.GetX()) + (A_.GetY() - B_.GetY()) * (A_.GetY() - B_.GetY()));
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

inline Triangle::Triangle(Point A, Point B, Point C)
{
	A_ = A, B_ = B, C_ = C;
	AC_ = Line(A_, C_);
	AB_ = Line(A_, B_);
	BC_ = Line(B_, C_);
}

inline void Triangle::PrintPoint()
{
	cout << "Triangle's point is:";
	A_.PrintPoint();
	B_.PrintPoint();
	C_.PrintPoint();
	cout << endl;
}

double Triangle::TrianglePerimeter()
{
	return AB_.LineLength() + AC_.LineLength() + BC_.LineLength();
}

inline void Triangle::PrintTrianglePerimeter()
{
	cout << "Triangle's perimeter is:"<< TrianglePerimeter() << endl;
}

//利用海伦公式计算面积

double Triangle::TriangleArea()
{
	double a = BC_.LineLength(), b = AC_.LineLength(), c = AB_.LineLength();
	return  0.25 * sqrt((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a));
}


inline void Triangle::PrintTriangleArea()
{
	cout << "Triangle's area is:" << TriangleArea() << endl;
}
