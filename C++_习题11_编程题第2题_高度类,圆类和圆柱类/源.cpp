#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.1415926;

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
	void SetPoint(double x, double y);

private:
	double x_, y_;
};

class Height
{
private:
	double height_;
public:
	Height(double height);
	Height();
};

class Circle
{
private:
	double radius_;
	Point circle_center_;
public:
	Circle(Point circle_center, double radius);
	Circle();
	Point GetCircleCenter();
	double CirclePerimeter();
	double CircleArea();
};

class Cylinder :public Height, public Circle
{
private:
	double height_;
	Circle circle_;
public:
	Cylinder(Circle circle, double height);
	Cylinder();
	double CylinderVolume();
	void PrintCylinderVolume();
	double CylinderSurfaceArea();
	void PrintCylinderSurfaceArea();
};



int main()
{
	Point O(0, 0);
	Circle A(O, 2);  //定义一个以(0,0)为圆心,2为半径的圆A
	Cylinder cyl(A,2);  //定义以圆A为底,2为高的圆柱
	cyl.PrintCylinderVolume();
	cyl.PrintCylinderSurfaceArea();
	return 0;
}



inline Point::Point(double x, double y)
{
	x_ = x;
	y_ = y;
}

inline Point::Point() { SetX(0), SetY(0); }

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

inline void Point::SetPoint(double x, double y) { x_ = x, y_ = y; }

inline Circle::Circle(Point circle_center, double radius)
{
	circle_center_ = circle_center;
	radius_ = radius;
}

inline Circle::Circle()
{
	Point O(0, 0);
	circle_center_ = O;
	radius_ = 1;
}

inline Point Circle::GetCircleCenter() { return circle_center_; }

inline double Circle::CirclePerimeter()
{
	return 2 * pi * radius_;
}

inline double Circle::CircleArea()
{
	return pi * radius_ * radius_;
}

inline Cylinder::Cylinder(Circle circle, double height)
{
	circle_ = circle;
	height_ = height;
}

inline Cylinder::Cylinder()
{
	Point O(0, 0);
	Circle A(O, 1);
	circle_ = A;
	height_ = 1;
}

inline double Cylinder::CylinderVolume()
{
	return circle_.CircleArea() * height_;
}

inline void Cylinder::PrintCylinderVolume()
{
	cout << "Cylinder's volume is:" << CylinderVolume() << endl;
}

inline double Cylinder::CylinderSurfaceArea()
{
	return 2 * circle_.CircleArea() + height_ * circle_.CirclePerimeter();
}

inline void Cylinder::PrintCylinderSurfaceArea()
{
	cout << "Cylinder's surface area is:" << CylinderSurfaceArea() << endl;
}

inline Height::Height(double height) { height_ = height; }

inline Height::Height() { height_ = 0; }
