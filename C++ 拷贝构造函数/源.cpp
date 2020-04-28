#include <iostream>
#include <stdlib.h>
using namespace std;

class Rect
{
public:
	Rect()
	{
		count++;
		p = new int[10];
	}
	Rect(const Rect& r)
	{
		width = r.width;
		height = r.height;
		count++;
		p = new int[10];
		*p = *(r.p);//���忽�����캯����������ռ�,����ͬһ�ռ��ͷ�����
	}
	~Rect()
	{
		count--;
		delete p;
	}
	static int getCount()
	{
		return count;
	}
private:
	int width;
	int height;
	static int count;
	int* p;
};

int Rect::count = 0;//��̬��Ա����ֻ�������ⶨ��

int main()
{
	Rect rect1;
	cout << "The count of Rect:" << Rect::getCount() << endl;
	Rect rect2(rect1);
	cout << "The count of Rect:" << Rect::getCount() << endl;
	return 0;
}