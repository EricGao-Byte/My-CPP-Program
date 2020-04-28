#include <iostream>

using namespace std;

class Date
{
private:
	int year, month, day;
public:
	int isleap(int y);//判断闰年：是 1  不是 0
	int check();//判断日期合法：合法 1  不合法 0
	void SetDate(int y, int m, int d);//设定日期，需检测有效性
	void PrintDate();//按yyyy/mm/dd格式输出日期，若是闰年还要输出是否为闰年信息
};

int main()
{
	Date date;
	int year, month, day;
	cout << "能够检测闰年以及按大小月检测日期可行性。" << endl;
	cout << "例如，输入2020 2 29。" << endl;
	cout << "请输入年 月 日：" << endl;
	cin >> year >> month >> day;
	date.SetDate(year, month, day);
	date.PrintDate();
	return 0;
}

int Date::isleap(int y)
{
	if (y % 4 == 0)
	{
		if (y % 100 == 0 && y % 400 != 0)//能被100整除且不能被400整除的不是闰年
			return 0;
		else return 1;
	}
	return 0;
}

int Date::check()
{
		if (year < 0)
		{
			cout << "年份不合法！" << endl;
			return 0;
		}
		if (month < 0 || month > 12)
		{
			cout << "月份不合法！" << endl;
			return 0;
		}

		int i, sum = 0;
		int month1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
		if (isleap(year) == 1)
			month1[1] = 29;//闰月2月是29天
		if (day<0 || day>month1[month-1])
		{
			cout << "天数不合法！" << endl;
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
		cout << "今年是闰年." << endl;
}