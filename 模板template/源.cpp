#include <iostream>

using namespace std;

template <typename T>//���������ݵ���abs()ʱʵ�ε����ͣ��Ƶ�������ģ������Ͳ�����
//���磬���ڵ��ñ��ʽabs(n)������ʵ��nΪint�ͣ������Ƶ���ģ�������Ͳ���TΪint��
//ģ���һ���������غ�������� ʹ��ͬһ�ֹ��ܵ����غ�������д������� ����дһ�������͸㶨��
T abs(T x,T y)
{
	return x / y;
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << abs(a, b);
	return 0;
}