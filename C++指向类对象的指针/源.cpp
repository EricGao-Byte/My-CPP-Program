#include <iostream>
using namespace std;

class Point
{
public:	
	Point(int x, int y)
	{
		X = x;
		Y = y;
	}
	int GetX()
	{
		return X;
	}
	int GetY()
	{
		return Y;
	}
private:
	int X, Y;
};

int main()
{
	Point A(5, 10);
	Point* ptr;//定义了一个指向Point类的类指针
	ptr = &A;
	int x;
	x = ptr->GetX();//通过类指针访问类对象
	cout << x << endl;
	return 0;
}