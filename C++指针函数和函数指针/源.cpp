#include <iostream>
using namespace std;

char* find(char* str, char ch)//ָ�뺯��,����ֵΪָ��ĺ���
{
	return str;
}

void print_stuff(float data_to_ignore)
{
	cout << data_to_ignore << " to ignore." << endl;
}
void print_message(float list_this_data);
void print_float(float data_to_print);
void (*function_pointer)(float);//void��ָ�����ָ���κζ���,Ҳ����ָ�����Ա������ĺ�������


int main()
{
	const float pi = 3.14159;
	float two_pi = 2.0 * pi;
	function_pointer = print_stuff;//��void��ָ��ָ����
	function_pointer(3.0);
	function_pointer = print_float;//��ָ���������ָ����һ������
	return 0;
}