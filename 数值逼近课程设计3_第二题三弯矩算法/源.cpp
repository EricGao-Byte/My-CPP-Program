#include <iostream>
using namespace std;
const int N = 37;
int main()
{
	//�������벿��
	int i;
	double y[N + 1] = { 502.75,502.96,525,523.6,514.3,492,451,394.6,326.5,256.7,188.6,132.1,92.2,68.9,59.6,58.2,62.24,80.45 };
	double h = 52.36;  //���䳤��
	double x[N + 1];
	for ( i = 0; i < N+1; i++)
	{
		x[i] = i * h;
	}
	//���㲿��
	int choice=1;
	double X, Y=0;
	do
	{
		cout << "��������Ҫ��ĵ��ֵX: ";
		cin >> X;
		double m1, m2, m3, m4;
		int j;
		if (X >= 0 && X <= 890.12)  //AB���߶β���
		{
			for ( i = 0; i < N; i++)
			{
				if (X <= x[i])
				{
					j = i;
					break;
				}
			}
			m1 = x[i];
			m2 = x[i + 1];
			m3 = y[i];
			m4 = y[i + 1];
			Y = m3 * (X - m2) / (m1 - m2) + m4 * (X - m1) / (m2 - m1);
			cout << "Y= " << Y << endl;
		}
		else if (X >= 890.12 && X < 1884.96)  //BCֱ�߶β���
		{
			Y = (502.75 - 80.45) / (1884.96 - 890.12) * (X - 890.12) + 80.45;
			cout << "Y= " << Y << endl;
		}
		else
		{
			cout << "����!! ������Ĳ���㲻�ڷ�Χ��,����������!" << endl;
		}
		cout << "�Ƿ��������?(1�� 2��)" << endl
			<< "����������ѡ��: ";
		cin >> choice;
		cout << endl;
	} while (choice!=2);
}