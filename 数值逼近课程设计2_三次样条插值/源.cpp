#include <iostream>

using namespace std;
const int MAX_NUM = 20;  //���ڵ���
int main()
{
	//�������ݲ���
	int i;
	int n;
	double h[MAX_NUM], b[MAX_NUM], a[MAX_NUM], m[MAX_NUM], x1[MAX_NUM];
	double u[MAX_NUM], v[MAX_NUM], y[MAX_NUM];
	double p1[MAX_NUM], p2[MAX_NUM], p3[MAX_NUM], p4[MAX_NUM];
	double x, S, y1, y2;
	cout << "--����������ֵ--" << endl;
	cout << "�������ֵ�ڵ���Ŀ: ";
	cin >> n;

	for ( i = 0; i < n; i++)
	{
		cout << "������ڵ�x" << i << ",y" << i << "��ֵ: ";
		cin >> x1[i] >> y[i];
	}
	//���㲿��
	int choice;  //ѡ��
	do
	{
		cout << "����߽�y1��ֵ: ";
		cin >> y1;
		cout << "����߽�y2��ֵ: ";
		cin >> y2;
		cout << "����x��ֵ: ";
		cin >> x;
		a[0] = -0.5;
		b[0] = (3 * (y[2] - y[1]) / (2 * (x1[2] - x1[1]))) - (y1 * (x1[2] - x1[1]) / 4);
		h[0] = x1[1] - x1[0];

		for (i = 1; i <= n - 2; i++)
		{
			h[i] = x1[i + 1] - x1[i];
			u[i] = h[i - 1] / (h[i - 1] + h[i]);
			v[i] = 6 * (((h[i - 1] * (y[i + 1] - y[i])) - (h[i] * (y[i] - y[i - 1]))) / (h[i - 1] * h[i] * (h[i] + h[i - 1])));
			a[i] = -u[i] / (2 + ((1 - u[i]) * a[i - 1]));
			b[i] = (v[i] - ((1 - u[i]) * b[i - 1])) / (2 + ((1 - u[i]) * a[i - 1]));
		}
		m[n - 1] = ((3 * (y[n - 1] - y[n - 2]) / h[n - 2]) + y2 * h[n - 2] - b[n - 2]) / (2 + a[n - 2]);
		for (i = n - 2; i >= 0; i--)
		{
			m[i] = (a[i] * m[i + 1]) + b[i];
		} 
		for (i = 1; i <= n - 1; i++)
		{
			if (x <= x1[i])
			{
				p1[i] = ((x1[i] - x) * (x1[i] - x) * (x1[i] - x)) / (6 * h[i - 1]);
				p2[i] = ((x1[i - 1] - x) * (x1[i - 1] - x) * (x - x1[i - 1])) / (6 * h[i - 1]);
				p3[i] = (y[i - 1] - ((h[i - 1] * h[i - 1] * m[i - 1]) / 6)) * ((x1[i] - x) / h[i - 1]);
				p4[i] = (y[i] - ((h[i - 1] * h[i - 1] * m[i]) / 6)) * ((x - x1[i - 1]) / h[i - 1]);
				cout << p1[i] << p2[i] << p3[i] << p4[i] << endl;
				S = p1[i] * m[i - 1] + p2[i] * m[i] + p3[i] + p4[i];
				break;
			}
			else continue;
		}
		cout << "S(" << x << ")=" << S << endl;
		cout << "�Ƿ��������?(1�� 2��)" << endl
			<< "������������ѡ��: ";
		cin >> choice;
	} while (choice!=2);
	
	return 0;
}