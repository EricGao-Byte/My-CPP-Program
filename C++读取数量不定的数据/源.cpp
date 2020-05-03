#include <iostream>
#include<vector>
using namespace std;

int main()
{
//	int sum = 0, value = 0;
//	int i = 0;
//	while (cin>>value)//当碰到文件结束符(或输入错误)结束循环
//	{
//		sum += value;
//		i++;
//	}
	vector<int> a;
	int i = 0;
	do {
		cin >> i;
		a.push_back(i);
	} while (getchar() != '\n');
	for (i = 0; i < a.size(); i++)
	cout << a[i] << " ";
	return 0;
}