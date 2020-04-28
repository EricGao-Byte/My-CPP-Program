#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
class Clock
{
public:
	Clock(T NewH, T NewM, T NewS);//¹¹Ôìº¯Êý
	//void SetTime(int NewH, int NewM, int NewS);
	void ShowTime()
	{
		cout << Hour << ":" << Minute << ":" << Second << endl;
	}
private:
	T Hour, Minute, Second;
};

//Clock<T>::Clock(T NewH=0, T NewM=0, T NewS=0)
//{
//	Hour = NewH;
//	Minute = NewM;
//	Second = NewS;
//}
//
//void Clock::ShowTime()
//{
//	cout << Hour << ":" << Minute << ":" << Second << endl;
//}
//void Clock::SetTime(int NewH, int NewM, int NewS)
//{
//
//}


int main()
{
	Clock<double> clock(23.5, 34.3,34.1332);
	clock.ShowTime();
	return 0;
}

template<typename T>
Clock<T>::Clock(T NewH, T NewM, T NewS)
{
		Hour = NewH;
		Minute = NewM;
		Second = NewS;
}
