#include <iostream>
//#include <istream>

using namespace std;
int main()
{
	char chars;
	int count = 0;//chars：接收用户输入的字符；count：记录用户输入的字符中空格的个数。
	for ( int i = 0;  i < 5; i++)//执行五次 01234
	{
		cout << "请输入第" << i+1 <<"个字符" << endl;
		
		chars = getchar();
		getchar();//接受回车字符，防止被下一轮的chars读取

		/*cin.get(chars);//使用get函数能够读取空格，单独使用cin会跳过空格
		cin.get(a);
		cin.get(b);
		cin.get(c);*/
		if (chars == ' ')
			count++;
	}
	cout << "输入的字符中空格的个数有：" << count << "个" << endl;
	return 0;
}