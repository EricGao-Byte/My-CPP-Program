//hex:16  oct:8   dec:10
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//int a = 10, b = 20, c = 30, d = 40;
	int a, b, c, d;
	cin >> hex >> a;//��ʮ�����ƶ�ȡ
	cin >> oct >> b;//���˽��ƶ�ȡ
	cin >> c;//��Ȼ���հ˽��ƶ�ȡ
	cin >> dec >> d;//��ʮ���ƶ�ȡ
	cout.setf(ios::scientific);
	cout << a <<" "<< b <<" "<< c <<" "<< d << endl;//���Ĭ����ʮ�������
	//cout << hex << d << endl;
	//cout << c;


	//cin.ignore(n) ����������ʼλ������n���ַ������
/*	string a, b;
	cin.ignore(3) >> a;
	cin.ignore(3) >> b;
	cout << a <<setw(10)<< b;*///������iomanip���У����Ƹ�ʽ�����Ĭ������ո�
	//int c;
	//cin.ignore(3) >> c;
	//cout << c;
	return 0;
}