#include <stdlib.h>
#include <iostream>

using namespace  std;

namespace A
{
	int x = 10;
	void fun()
	{
		cout << "A" << endl;
	}
}

namespace B
{
	int x = 10000;
	void fun()
	{
		cout << "B" << endl;
		//A::x;
		//B::fun();//һ�������ռ������֧�����������ռ�ĺ����ͱ���
	}
	void fun2()
	{
		cout << "fun2B" << endl;
	}
}
using namespace A;//Ҳ���ֶ����������ռ� ����fun2�����������Բ�ָ�������ռ�Ҳ��ʹ��
					//ͬ�� Ҳ���Բ�����namespace std��ʹ��std����Ҳ����ʹ��cout��cin
using namespace B;//��������������������ռ��к�����ͬ��Ԫ�أ�������Ҫ���������ռ�
int main()
{
	fun2();
	cout << A::x << endl;
	cout << B::x << endl;
	B::fun();//����namespace���Ե��ò�ͬ�����ռ������ͬ�ĺ������߱���
	//A::fun();
	system("pause");
	return 0;
}