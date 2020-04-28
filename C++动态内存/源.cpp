#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x=0, int y=0)
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
	Point* ptr = new Point;//new一个Point类的空间并将ptr指向他
	cout << ptr->GetX() << endl;
	delete ptr;//释放ptr所指向的空间
	return 0;
}