#include <iostream>
using namespace std;

int main()
{
	int** A;//����һ��ָ��intָ���ָ��
	int a1=3, a2=3, i,j;
	A = new int* [a1];//����һ������a1��Ԫ�ص�ָ������
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
