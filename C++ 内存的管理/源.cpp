#include <iostream>
using namespace std;
int main()
{
	int* p = new int;//�����ڴ�
	if (p == NULL)//�п������벻���ռ� ��Ҫ���ָ���Ƿ�Ϊ��
	{
		exit(1);//�쳣����Ĵ���
	}
	delete p;//�ͷ��ڴ�
	p = NULL;//���ͷź��ָ����Ϊ�� ��ֹ���µ���ָ���������

	int* arr = new int[20];//������ڴ�
	if (p == NULL)
	{
		exit(2);
	}
	delete[]arr;//�ͷſ��ڴ�
	p = NULL;
	return 0;
}