#include <iostream>
using namespace std;

void ReverseNum(int x)
{
	int remain = x % 10;//取最小位数字
	int division = x / 10;//取最小位之外剩下的数字
	if(division!=0)//若最小为剩下的数字为0,则递归终止
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