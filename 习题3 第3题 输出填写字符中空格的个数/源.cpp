#include <iostream>
//#include <istream>

using namespace std;
int main()
{
	char chars;
	int count = 0;//chars�������û�������ַ���count����¼�û�������ַ��пո�ĸ�����
	for ( int i = 0;  i < 5; i++)//ִ����� 01234
	{
		cout << "�������" << i+1 <<"���ַ�" << endl;
		
		chars = getchar();
		getchar();//���ܻس��ַ�����ֹ����һ�ֵ�chars��ȡ

		/*cin.get(chars);//ʹ��get�����ܹ���ȡ�ո񣬵���ʹ��cin�������ո�
		cin.get(a);
		cin.get(b);
		cin.get(c);*/
		if (chars == ' ')
			count++;
	}
	cout << "������ַ��пո�ĸ����У�" << count << "��" << endl;
	return 0;
}