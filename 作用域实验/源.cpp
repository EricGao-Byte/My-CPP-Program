#include <iostream>
using namespace std;

int abc = 100;//����һ��ȫ�ֱ���abc
int sum(int a,int b)
{
	static int sum1;//���徲̬���� �Ա��´ε��ú�������ʹ�� ע�⣺����������Ȼ�޷�������ȫ�ֱ�����ͬ
	sum1 = a + b + sum1;
	return sum1;
}

int main()
{
	//��̬����������ʹ��
	int n;
	n = sum(10, 20);
	cout << n << endl;
	n = sum(30, 40);
	cout << n << endl;





	/*int a = 10, b = 20;
	cout << a << b << endl;
	{
		int a = 0;
		int b = 30;
		cout << a << b << endl;
	}
	cout << a << b << endl;*/
	//forѭ��������
	/*int i = 10;
	for (int i = 0; i < 5; i++)
	{
		cout << i << endl;
	}
	cout << i << endl;*/
	//����ã�������ȫ�ֱ���
	//int abc = 50;
	//cout << abc << endl;
	//abc += 1;
	//cout << abc << endl;
	//cout << ::abc << endl;
	//::abc += ::abc;
	//cout << ::abc << endl;
	//cout << abc << endl;

	return 0;
}