#include <iostream>
using namespace std;
int main()
{
	int* p = new int;//申请内存
	if (p == NULL)//有可能申请不到空间 需要检测指针是否为空
	{
		exit(1);//异常情况的处理
	}
	delete p;//释放内存
	p = NULL;//将释放后的指针置为空 防止重新调用指针后发生错误

	int* arr = new int[20];//申请快内存
	if (p == NULL)
	{
		exit(2);
	}
	delete[]arr;//释放块内存
	p = NULL;
	return 0;
}