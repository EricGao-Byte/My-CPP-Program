#include <iostream>
using namespace std;
const int MAX_NUM = 20;  //�ڵ������Ŀ
int main()
{
	//�������ݲ���
	int i, j, n;
	double m, x[MAX_NUM] = { 0 }, y[MAX_NUM] = { 0 }, diff[MAX_NUM] = { 0 }, sum, tmp;
	cout << "--Newton��ֵ--" << endl;
	cout << "������ڵ���Ŀ: " << endl;
	cin >> n;  //�ڵ���Ŀ
	n = n - 1;
	cout << "������ڵ����ֵ(x,y֮��ո����): " << endl;
	for (i = 0; i <= n; i++)
	{
		cout << "x[" << i << "],y[" << i << "]:";
		cin >> x[i] >> y[i];
	}
	//���㲿��
	int choice;  //ѡ��
	do
	{
		cout << "����Ҫ���ֵ: " << endl;
		cin >> m;
		for (i = 0; i <= n; i++)
		{
			diff[i] = y[i];
		}
		//�����
		for (i = 0; i <= n; i++)
		{
			for (j = n; j > i; j--)
			{
				diff[j] = (diff[j] - diff[j - 1]) / (x[j] - x[j - 1 - i]);
			}
		}
		//�����ֵ
		sum = y[0];
		for (tmp = 1, i = 0; i < n; i++)
		{
			tmp *= m - x[i];
			sum += tmp * diff[i + 1];
		}
		cout << "Newton(" << m << ")=" << sum << endl;
		cout << "�Ƿ��������?(1�� 2��)" << endl
			<< "���������ѡ��: ";
		cin >> choice;
	} while (choice!= 2);  //ѡ���ʱ�ų�ѭ��
	return 0;
}