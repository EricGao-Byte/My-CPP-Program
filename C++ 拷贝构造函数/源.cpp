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
		*p = *(r.p);//定义拷贝构造函数另外申请空间,反正同一空间释放两次
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

int Rect::count = 0;//静态成员变量只能再类外定义

int main()
{
	Rect rect1;
	cout << "The count of Rect:" << Rect::getCount() << endl;
	Rect rect2(rect1);
	cout << "The count of Rect:" << Rect::getCount() << endl;
	return 0;
}