#include<iostream>
using namespace std;

class Application
{
public:
	static void f();//���徲̬��Ա����
	static void g();
private:
	static int global;
};
int Application::global = 0;//������һ����̬���ݳ�Ա,����һ��Ҫ�����ⶨ��
void Application::f()
{
	global = 5;
}
void Application::g()
{
	cout << global << endl;
}

int main()
{

	Application::f();//�����˾�̬������Ա֮��,�������ֱ��ʹ�ú����������е���
	Application::g();//�����Ǿ�̬����,��ֻ�ܶ���һ������,�ö��������ú���,����Application a.f()
	return 0;
}
