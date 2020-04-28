#include <iostream>
using namespace std;

void PrintFacity(int n=10)
{
	int fac = 1;
	int i;
	for ( i = 1; i <= n; i++)
	{
		fac *= i;
	}
	cout << n << "!=" << fac << endl;
}

int main()
{
	int n;
	PrintFacity();//
	cout << "to calculate n!,input n=" << endl;
	cin >> n;
	PrintFacity(n);
	return 0;
}