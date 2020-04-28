//一个简易的剪刀石头布游戏
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main()
{
	//void game();
	//int flag = 0;
	//cout << "--------------游戏开始---------------" << endl;
	//cout << "开始游戏前，请确定您与另一位玩家的先后次序。" << endl;
	//cout << "输入0开始游戏   输入其他任意数停止游戏" << endl;
	//cin >> flag;//游戏进行状态变量
	//while (flag==0)
	//{
	//	game();
	//	cout << "输入0继续游戏   输入其他任意数停止游戏" << endl;
	//	cin >> flag;
	//	system("cls");
	//}
	//cout << "--------------游戏结束---------------";
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
//	int a, b;//a:储存第一个人的出拳代号  b：储存第二个人的出拳代号 
//	int sign_a=0,sign_b=0;//输赢状态储存变量； +0：平局和输，+1：赢
//	int n;
//	cout << "请输入局数：";
//	cin >> n;//游戏局数变量
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		cout << "第 " << i + 1 << " 局" << endl;
//		
//			a = 1 + rand() % 3;//随机产生1，2，3中的一个数；1：布，2：剪刀，3：石头
//			b = 1 + rand() % 3;
//			if (a == 1)
//			{
//				cout << "第一个人出---布" << endl;
//				if (b == 1)
//				{
//					sign_a += 0;
//					sign_b += 0;
//					cout << "第二个人出---布" << endl;
//					cout << "平局！" << endl;
//				}
//				if (b == 2)
//				{
//					sign_a += 0;
//					sign_b += 1;
//					cout << "第二个人出---剪刀" << endl;
//					cout << "第二个人赢！" << endl;
//				}
//				if (b == 3)
//				{
//					sign_a += 0;
//					sign_b += 1;
//					cout << "第二个人出---石头" << endl;
//					cout << "第二个人赢！" << endl;
//				}
//			}
//			if (a == 2)
//			{
//				cout << "第一个人出---剪刀" << endl;
//				if (b == 1)
//				{
//					sign_a += 1;
//					sign_b += 0;
//					cout << "第二个人出---布" << endl;
//					cout << "第一个人赢！" << endl;
//				}
//				if (b == 2)
//				{
//					sign_a += 0;
//					sign_b += 0;
//					cout << "第二个人出---剪刀" << endl;
//					cout << "平局！" << endl;
//				}
//				if (b == 3)
//				{
//					sign_a += 0;
//					sign_b += 1;
//					cout << "第二个人出---石头" << endl;
//					cout << "第二个人赢！" << endl;
//				}
//			}
//			if (a == 3)
//			{
//				cout << "第一个人出---石头" << endl;
//				if (b == 1)
//				{
//					sign_a += 1;
//					sign_b += 0;
//					cout << "第二个人出---布" << endl;
//					cout << "第一个人赢！" << endl;
//				}
//				if (b == 2)
//				{
//					sign_a += 1;
//					sign_b += 0;
//					cout << "第二个人出---剪刀" << endl;
//					cout << "第一个人赢！" << endl;
//				}
//				if (b == 3)
//				{
//					sign_a += 0;
//					sign_b += 0;
//					cout << "第二个人出---石头" << endl;
//					cout << "平局！" << endl;
//				}
//			}
//			cout << endl;
//	}
//	if (sign_a == sign_b)cout <<"游戏进行了 " << n << " 局" << "   平局！" << endl;
//	if (sign_a > sign_b)cout << "游戏进行了 " << n << " 局" << "   第一个人赢！" << endl;
//	if (sign_a < sign_b)cout << "游戏进行了 " << n << " 局" << "   第二个人赢！" << endl;
//	cout << endl;
//}