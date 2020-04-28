#include <iostream>

using namespace std;
template <typename T>
class Clock
{
public:
	void SetTime(T NewH, T NewM, T NewS)
	{
		if (NewH >= 24)
		{
			cout << "error! hour is not correct."<<endl;
			exit(1);
		}
		else if (NewM >= 60)
		{
			cout << "error! minute is not correct."<<endl;
			exit(1);
		}
		else if(NewS >= 60)
		{
			cout << "error! second is not correct."<<endl;
			exit(1);
		}
		Hour = NewH;
		Minute = NewM;
		Second = NewS;
	}
	void ShowTime()
	{
		cout << Hour << ":" << Minute << ":" << Second;
	}
private:
	T Hour, Minute, Second;
};


int main()
{
	Clock<int> clock;
	clock.SetTime(12, 34, 32);
	clock.ShowTime();
	return 0;
}


