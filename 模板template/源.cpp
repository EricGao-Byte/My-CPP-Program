#include <iostream>

using namespace std;

//���������ݵ���abs()ʱʵ�ε����ͣ��Ƶ�������ģ������Ͳ�����
//���磬���ڵ��ñ��ʽabs(n)������ʵ��nΪint�ͣ������Ƶ���ģ�������Ͳ���TΪint��
//ģ���һ���������غ�������� ʹ��ͬһ�ֹ��ܵ����غ�������д������� ����дһ�������͸㶨��
template <typename T>
T abs(T x,T y)
{
	return x / y;
}
template <typename T>  //ģ�庯��������
T abs(T x, char y)
{
	return x / y;
}
template <typename T1,typename T2>  //���ģ������,����T1,T2������ͬ
T1 abs(T1 x, T2 y)
{
	return x / y;
}

template <typename T>
void Swap(T& a, T& b) 
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	//int a, b;
	//cin >> a >> b;
	//cout << abs(a, b)<<endl;  //ϵͳ����ʵ�ε�����,�������غ���
	//Swap(a, b);
	//cout << "a:" << a <<" "<< "b:" << b << endl;

	/*double c, d;
	cin >> c >> d;
	cout << abs(c, d) << endl;
	char e;
	cin >> e;
	cout << abs(c, e);*/

	double A;
	int B;
	cin >> A >> B;
	cout << abs(A, B);
	return 0;
}