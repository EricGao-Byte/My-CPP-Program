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
	Point* ptr = new Point;//newһ��Point��Ŀռ䲢��ptrָ����
	cout << ptr->GetX() << endl;
	delete ptr;//�ͷ�ptr��ָ��Ŀռ�
	return 0;
}