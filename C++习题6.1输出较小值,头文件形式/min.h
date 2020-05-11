#pragma once
#include <iostream>
using namespace std;

void min(double a, double b, double c)
{
	double min;
	if (a < b)
	{
		if (a < c)
		{
			min = a;
		}
		else
		{
			min = c;
		}
	}
	else
	{
		if (b < c)
		{
			min = b;
		}
		else
		{
			min = c;
		}
	}
	cout << "min number:" << min << endl;
}
