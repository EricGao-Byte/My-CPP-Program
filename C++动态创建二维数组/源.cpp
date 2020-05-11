#include <iostream>
using namespace std;

int main()
{
	int** A;//定义一个指向int指针的指针
	int a1=3, a2=3, i,j;
	A = new int* [a1];//定义一个含有a1个元素的指针数组
	for (i = 0; i < a1; i++)
	{
		A[i] = new int[a2];
	}
	for (i = 0; i < a1; i++)
	{
		for (j = 0; j < a2; j++)
		{
			A[i][j] = 0;
		}
	}
	return 0;
}
