#include <iostream>

using namespace std;

class Date
{
private:
	int year, month, day;
public:
	int isleap(int y);//�ж����꣺�� 1  ���� 0
	int check();//�ж����ںϷ����Ϸ� 1  ���Ϸ� 0
	void SetDate(int y, int m, int d);//�趨���ڣ�������Ч��
	void PrintDate();//��yyyy/mm/dd��ʽ������ڣ��������껹Ҫ����Ƿ�Ϊ������Ϣ
};

int main()
{
	Date date;
	int year, month, day;
	cout << "�ܹ���������Լ�����С�¼�����ڿ����ԡ�" << endl;
	cout << "���磬����2020 2 29��" << endl;
	cout << "�������� �� �գ�" << endl;
	cin >> year >> month >> day;
	date.SetDate(year, month, day);
	date.PrintDate();
	return 0;
}

int Date::isleap(int y)
{
	if (y % 4 == 0)
	{
		if (y % 100 == 0 && y % 400 != 0)//�ܱ�100�����Ҳ��ܱ�400�����Ĳ�������
			return 0;
		else return 1;
	}
	return 0;
}

int Date::check()
{
		if (year < 0)
		{
			cout << "��ݲ��Ϸ���" << endl;
			return 0;
		}
		if (month < 0 || month > 12)
		{
			cout << "�·ݲ��Ϸ���" << endl;
			return 0;
		}

		int i, sum = 0;
		int month1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
		if (isleap(year) == 1)
			month1[1] = 29;//����2����29��
		if (day<0 || day>month1[month-1])
		{
			cout << "�������Ϸ���" << endl;
			return 0;
		}
		return 1;
}

void Date::SetDate(int y, int m, int d)
{

	year = y;
	month = m;
	day = d;
	if (check() == 0)
		exit(1);
}

void Date::PrintDate()
{
	cout << year << "/" << month << "/" << day << endl;
	if (isleap(year) == 1)
		cout << "����������." << endl;
}