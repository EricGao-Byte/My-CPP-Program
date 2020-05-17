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
		X += xOff;//����������ƶ��ľ���
		Y += yOff;
	}
	float GetX() { return X; }
	float GetY() { return Y; }
private:
	float X, Y;
};
//���м̳о���
class Rectangle_pub :public Point
{
public:
	void initR(float x, float y, float w, float h)
	{
		initP(x, y);//���û���Ĺ��г�Ա����
		W = w;
		H = h;
	}		
	float GetH() { return H; }
	float GetW() { return W; }
private:
	float W, H;
};
//˽�м̳о���
class Rectangle_pri :private Point
{
public:
	void initR(float x, float y, float w, float h)
	{
		initP(x, y);//˽�м̳п��Է��ʻ���Ĺ��г�Ա
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
	//���м̳�
	Rectangle_pub rect_pub;
	rect_pub.initR(2, 3, 20, 10);
	rect_pub.Move(3,2);//ͨ�������������ʻ���Ĺ��г�Ա
	cout << rect_pub.GetX() << "," << rect_pub.GetY() << ","
		<< rect_pub.GetH() << "," << rect_pub.GetW() << endl;
	//˽�м̳�
	Rectangle_pri rect_pri;
	rect_pri.initR(2, 3, 20, 10);
	rect_pri.Move(3, 2);

	return 0;
}