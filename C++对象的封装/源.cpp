#include <iostream>

using namespace std;
//����ʵ�������ӱ���
class Clock
{
public:
	void SetTime(int NewH, int NewM, int NewS);
	void ShowTime();
private:
	int Hour, Minute, Second;
};
int main()
{
	Clock myClock;
	myClock.SetTime(8, 30, 30);
	myClock.ShowTime();
	
	return 0;
}

void Clock::SetTime(int NewH, int NewM, int NewS)
{
	Hour = NewH;
	Minute = NewM;
	Second = NewS;
}

void Clock::ShowTime()
{
	cout << Hour << "ʱ" << Minute << "��" << Second << "��" << endl;
}
