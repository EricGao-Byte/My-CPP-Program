//һ�����׵ļ���ʯͷ����Ϸ
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main()
{
	//void game();
	//int flag = 0;
	//cout << "--------------��Ϸ��ʼ---------------" << endl;
	//cout << "��ʼ��Ϸǰ����ȷ��������һλ��ҵ��Ⱥ����" << endl;
	//cout << "����0��ʼ��Ϸ   ��������������ֹͣ��Ϸ" << endl;
	//cin >> flag;//��Ϸ����״̬����
	//while (flag==0)
	//{
	//	game();
	//	cout << "����0������Ϸ   ��������������ֹͣ��Ϸ" << endl;
	//	cin >> flag;
	//	system("cls");
	//}
	//cout << "--------------��Ϸ����---------------";
	int i=0;
	srand((unsigned)time(NULL));

	while (i<5)
	{
		cout << rand()/double(RAND_MAX)<<endl;
		i++;
	}
	return 0;
}
//
//void game()
//{
//	int a, b;//a:�����һ���˵ĳ�ȭ����  b������ڶ����˵ĳ�ȭ���� 
//	int sign_a=0,sign_b=0;//��Ӯ״̬��������� +0��ƽ�ֺ��䣬+1��Ӯ
//	int n;
//	cout << "�����������";
//	cin >> n;//��Ϸ��������
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		cout << "�� " << i + 1 << " ��" << endl;
//		
//			a = 1 + rand() % 3;//�������1��2��3�е�һ������1������2��������3��ʯͷ
//			b = 1 + rand() % 3;
//			if (a == 1)
//			{
//				cout << "��һ���˳�---��" << endl;
//				if (b == 1)
//				{
//					sign_a += 0;
//					sign_b += 0;
//					cout << "�ڶ����˳�---��" << endl;
//					cout << "ƽ�֣�" << endl;
//				}
//				if (b == 2)
//				{
//					sign_a += 0;
//					sign_b += 1;
//					cout << "�ڶ����˳�---����" << endl;
//					cout << "�ڶ�����Ӯ��" << endl;
//				}
//				if (b == 3)
//				{
//					sign_a += 0;
//					sign_b += 1;
//					cout << "�ڶ����˳�---ʯͷ" << endl;
//					cout << "�ڶ�����Ӯ��" << endl;
//				}
//			}
//			if (a == 2)
//			{
//				cout << "��һ���˳�---����" << endl;
//				if (b == 1)
//				{
//					sign_a += 1;
//					sign_b += 0;
//					cout << "�ڶ����˳�---��" << endl;
//					cout << "��һ����Ӯ��" << endl;
//				}
//				if (b == 2)
//				{
//					sign_a += 0;
//					sign_b += 0;
//					cout << "�ڶ����˳�---����" << endl;
//					cout << "ƽ�֣�" << endl;
//				}
//				if (b == 3)
//				{
//					sign_a += 0;
//					sign_b += 1;
//					cout << "�ڶ����˳�---ʯͷ" << endl;
//					cout << "�ڶ�����Ӯ��" << endl;
//				}
//			}
//			if (a == 3)
//			{
//				cout << "��һ���˳�---ʯͷ" << endl;
//				if (b == 1)
//				{
//					sign_a += 1;
//					sign_b += 0;
//					cout << "�ڶ����˳�---��" << endl;
//					cout << "��һ����Ӯ��" << endl;
//				}
//				if (b == 2)
//				{
//					sign_a += 1;
//					sign_b += 0;
//					cout << "�ڶ����˳�---����" << endl;
//					cout << "��һ����Ӯ��" << endl;
//				}
//				if (b == 3)
//				{
//					sign_a += 0;
//					sign_b += 0;
//					cout << "�ڶ����˳�---ʯͷ" << endl;
//					cout << "ƽ�֣�" << endl;
//				}
//			}
//			cout << endl;
//	}
//	if (sign_a == sign_b)cout <<"��Ϸ������ " << n << " ��" << "   ƽ�֣�" << endl;
//	if (sign_a > sign_b)cout << "��Ϸ������ " << n << " ��" << "   ��һ����Ӯ��" << endl;
//	if (sign_a < sign_b)cout << "��Ϸ������ " << n << " ��" << "   �ڶ�����Ӯ��" << endl;
//	cout << endl;
//}