#include <iostream>
using namespace std;

int main()
{
	//����ָ��
	const int* pt_int;
	int a = 10;
	const int b = 20;
	pt_int = &a;//���Խ�const int ָ��ָ��һ������
	pt_int = &b;//Ҳ���Ըı�ָ��ָ��,����ָ��һ������
	//*pt_int = 20;����:�����Ըı�const intָ����ָ���ֵ
	a = 30;//���Ǹı䱾���ֵ��ָ���޹�

	//ָ�볣��
	int* const constpt_int = &a;//ָ�볣������ʱ�����ʼ��
	*constpt_int = 30;//�Ϸ�,ͨ��ָ���������ֵ
	//constpt_int = &b;����:���ܸı�ָ�볣����ָ��

	//ָ��ָ�볣����ָ�볣��
	const int* const constpt_int = &a;
	//���ܸı�ָ��ָ�����,Ҳ���ܸı�ָ���ָ��
	//ֻ���Զ�ȡ,�����Ըı�,Ҳ����ʹ����ֻ��

	
	return 0;
}