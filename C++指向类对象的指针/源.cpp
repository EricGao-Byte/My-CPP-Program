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
	Point* ptr;//������һ��ָ��Point�����ָ��
	ptr = &A;
	int x;
	x = ptr->GetX();//ͨ����ָ����������
	cout << x << endl;
	return 0;
}