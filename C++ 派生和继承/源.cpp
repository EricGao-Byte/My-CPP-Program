#include <iostream>
using namespace std;


class Point
{
public:
	void initP(float xx = 0, float yy = 0)
	{
		X = xx;
		Y = yy;
	}
	void Move(float xOff, float yOff)
	{
		X += xOff;//点坐标加上移动的距离
		Y += yOff;
	}
	float GetX() { return X; }
	float GetY() { return Y; }
private:
	float X, Y;
};
//公有继承举例
class Rectangle_pub :public Point
{
public:
	void initR(float x, float y, float w, float h)
	{
		initP(x, y);//调用基类的公有成员函数
		W = w;
		H = h;
	}		
	float GetH() { return H; }
	float GetW() { return W; }
private:
	float W, H;
};
//私有继承举例
class Rectangle_pri :private Point
{
public:
	void initR(float x, float y, float w, float h)
	{
		initP(x, y);//私有继承可以访问基类的公有成员
		W = w;
		H = h;
	}
	void Move(float xOff,float yOff)//
	{
		Point::Move(xOff, yOff);
	}
	float GetX() { return Point::GetX(); }
	float GetY() { return Point::GetY(); }
	float GetH() { return H; }
	float GetW() { return W; }
private:
	float W, H;
};

int main()
{
	//公有继承
	Rectangle_pub rect_pub;
	rect_pub.initR(2, 3, 20, 10);
	rect_pub.Move(3,2);//通过派生类对象访问基类的公有成员
	cout << rect_pub.GetX() << "," << rect_pub.GetY() << ","
		<< rect_pub.GetH() << "," << rect_pub.GetW() << endl;
	//私有继承
	Rectangle_pri rect_pri;
	rect_pri.initR(2, 3, 20, 10);
	rect_pri.Move(3, 2);

	return 0;
}