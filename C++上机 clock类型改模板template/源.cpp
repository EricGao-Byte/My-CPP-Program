#include <iostream>
using namespace std;

template <typename T> 
class Clock
{
public:
	void SetTime(T NewH, T NewM, T NewS);
	void ShowTime();
private:
	T Hour, Minute, Second;
};


int main()
{
	Clock<int> clock;  //类模板必须要程序设计者手动指明数据类型
	clock.SetTime(12, 34, 32);
	clock.ShowTime();
	return 0;
}

template<typename T>
inline void Clock<T>::SetTime(T NewH, T NewM, T NewS)
{
	if (NewH >= 24)
	{
		cout << "error! hour is not correct." << endl;
		exit(1);
	}
	else if (NewM >= 60)
	{
		cout << "error! minute is not correct." << endl;
		exit(1);
	}
	else if (NewS >= 60)
	{
		cout << "error! second is not correct." << endl;
		exit(1);
	}
	Hour = NewH;
	Minute = NewM;
	Second = NewS;
}

template<typename T>
inline void Clock<T>::ShowTime()
{
	cout << Hour << ":" << Minute << ":" << Second;
}
