#include <iostream>
using namespace std;

void ReverseNum(int x)
{
	int remain = x % 10;//ȡ��Сλ����
	int division = x / 10;//ȡ��Сλ֮��ʣ�µ�����
	if(division!=0)//����СΪʣ�µ�����Ϊ0,��ݹ���ֹ
	{
		cout << remain;
		ReverseNum(division);
	}
	else
	{
		cout << remain << endl;
	}

}

int main()
{
	int a;
	cout << "input a integer:" << endl;
	cin >> a;
	ReverseNum(a);
	return 0;
}