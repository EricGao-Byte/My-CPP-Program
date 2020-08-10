#include <iostream>
using namespace std;
const int MAX_NUM = 20;  //节点最大数目
int main()
{
	//输入数据部分
	int i, j, n;
	double m, x[MAX_NUM] = { 0 }, y[MAX_NUM] = { 0 }, diff[MAX_NUM] = { 0 }, sum, tmp;
	cout << "--Newton插值--" << endl;
	cout << "请输入节点数目: " << endl;
	cin >> n;  //节点数目
	n = n - 1;
	cout << "请输入节点的数值(x,y之间空格隔开): " << endl;
	for (i = 0; i <= n; i++)
	{
		cout << "x[" << i << "],y[" << i << "]:";
		cin >> x[i] >> y[i];
	}
	//计算部分
	int choice;  //选项
	do
	{
		cout << "输入要求的值: " << endl;
		cin >> m;
		for (i = 0; i <= n; i++)
		{
			diff[i] = y[i];
		}
		//求差商
		for (i = 0; i <= n; i++)
		{
			for (j = n; j > i; j--)
			{
				diff[j] = (diff[j] - diff[j - 1]) / (x[j] - x[j - 1 - i]);
			}
		}
		//求近似值
		sum = y[0];
		for (tmp = 1, i = 0; i < n; i++)
		{
			tmp *= m - x[i];
			sum += tmp * diff[i + 1];
		}
		cout << "Newton(" << m << ")=" << sum << endl;
		cout << "是否继续输入?(1是 2否)" << endl
			<< "请输入号码选择: ";
		cin >> choice;
	} while (choice!= 2);  //选择否时才出循环
	return 0;
}