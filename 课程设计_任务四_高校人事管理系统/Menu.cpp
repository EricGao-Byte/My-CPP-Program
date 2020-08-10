#include "Menu.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Menu::main()
{
	int choice;
	cout << "系统启动成功!!" << endl;
	cin >> this;  //从本地txt文件读取数据
	cout << "按enter键继续...." << endl;
	getchar();
	system("cls");
	do
	{
		cout
			<< "**欢迎使用学校人事管理系统**" << endl
			<< "1.添加人员信息" << endl
			<< "2.删除人员信息" << endl
			<< "3.查询人员信息" << endl
			<< "4.修改人员信息" << endl
			<< "5.统计人员信息" << endl
			<< "6.初始化人员信息" << endl
			<< "7.保存人员信息到本地" << endl
			<< "8.退出系统并保存人员信息到本地" << endl
			<< "9.退出系统不保存人员信息到本地" << endl
			<< "输入对应号码进行选择: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			add();
		}
		else if (choice == 2)
		{
			del();
		}
		else if (choice == 3)
		{
			search();
		}
		else if (choice == 4)
		{
			modi();
		}
		else if (choice == 5)
		{
			statistic();
		}
		else if(choice == 6)
		{
			init();
		}
		else if (choice == 7)
		{
			save();
		}
		else if(choice == 8)
		{
			cout << this;  //保存数据
			cout << "退出系统....";
		}
		else if (choice == 9)
		{
			cout << "退出系统....";
		}
		else
		{
			cout << "输入的数字有误! 请重新输入...." << endl;
		}
	} while (choice!=9&&choice!=8);
	

}

void Menu::add()
{
	int choice;
	do
	{
		cout
			<< "1.开始输入人员信息" << endl
			<< "2.返回上一级菜单" << endl
			<< "输入对应号码进行选择: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			addStaff();
			system("cls");
		}
		else if (choice == 2)
		{

		}
		else
		{
			cout << "输入的数字有误! 请重新输入...." << endl;
		}
	} while (choice!=2);
	
}

void Menu::del()
{
	int choice;
	
	do
	{
		cout 
			<< "1.按编号删除" << endl
			<< "2.按性别删除" << endl
			<< "3.按姓名删除" << endl
			<< "4.按年龄删除" << endl
			<< "5.按职务删除" << endl
			<< "6.按职称删除" << endl
			<< "7.按政治面貌删除" << endl
			<< "8.按最高学历删除" << endl
			<< "9.按人员类型删除" << endl
			<< "10.返回上一级菜单" << endl
			<< "输入对应号码进行选择: ";
		cin >> choice;
		system("cls");
		if (choice != 10)
		{
			delStaff(choice);
			system("cls");
		}
		else if (choice == 10)
		{

		}
		else
		{
			cout << "输入的数字有误! 请重新输入...." << endl;
		}
	} while (choice != 10);


}

void Menu::modi()
{
	int choice;

	do
	{
		cout
			<< "1.按编号搜索并修改" << endl
			<< "2.按性别搜索并修改" << endl
			<< "3.按姓名搜索并修改" << endl
			<< "4.按年龄搜索并修改" << endl
			<< "5.按职务搜索并修改" << endl
			<< "6.按职称搜索并修改" << endl
			<< "7.按政治面貌搜索并修改" << endl
			<< "8.按最高学历搜索并修改" << endl
			<< "9.按人员类型搜索并修改" << endl
			<< "10.返回上一级菜单" << endl
			<< "输入对应号码进行选择: ";
		cin >> choice;
		system("cls");
		if (choice != 10)
		{
			modiStaff(choice);
			system("cls");
		}
		else if (choice == 10)
		{

		}
		else
		{
			cout << "输入的数字有误! 请重新输入...." << endl;
		}
	} while (choice != 10);
}

void Menu::search()
{
	int choice;
	do
	{
		cout
			<< "1.按编号搜索" << endl
			<< "2.按性别搜索" << endl
			<< "3.按姓名搜索" << endl
			<< "4.按年龄搜索" << endl
			<< "5.按职务搜索" << endl
			<< "6.按职称搜索" << endl
			<< "7.按政治面貌搜索" << endl
			<< "8.按最高学历搜索" << endl
			<< "9.按人员类型搜索" << endl
			<< "10.输出所有人员信息" << endl
			<< "11.返回上一级菜单" << endl
			<< "输入对应号码进行选择: ";
		cin >> choice;
		system("cls");
		if (choice != 11)
		{
			searchStaff(choice);
			getchar();
			system("cls");
		}
		else if (choice == 11)
		{

		}
		else
		{
			cout << "输入的数字有误! 请重新输入...." << endl;
		}
	} while (choice != 11);
}

void Menu::statistic()
{
	int choice;
	do
	{
		cout
			<< "1.按编号统计" << endl
			<< "2.按性别统计" << endl
			<< "3.按姓名统计" << endl
			<< "4.按年龄统计" << endl
			<< "5.按职务统计" << endl
			<< "6.按职称统计" << endl
			<< "7.按政治面貌统计" << endl
			<< "8.按最高学历统计" << endl
			<< "9.按人员类型统计" << endl
			<< "10.返回上一级菜单" << endl
			<< "输入对应号码进行选择: ";
		cin >> choice;
		system("cls");
		if (choice != 10)
		{
			searchStaff(choice);
			getchar();
			system("cls");
		}
		else if (choice == 10)
		{

		}
		else
		{
			cout << "输入的数字有误! 请重新输入...." << endl;
		}
	} while (choice != 10);
}

void Menu::init()
{
	int choice;
	cout
		<< "1.初始化人员信息" << endl
		<< "2.返回上一级菜单" << endl
		<< "输入对应号码进行选择: ";

	cin >> choice;
	if (choice==1)
	{
		cout << "请确认是否要初始化数据?(此操作将清空内存中的数据,不会清空本地数据)" << endl
			<< "(1确认 2取消)" << endl
			<< "输入对应号码进行选择: ";
		cin >> choice;
		if (choice == 1)
		{
			initStaff();
		}
		else
		{
			cout << "人员信息已取消初始化,按enter键继续....";
			getchar();
			getchar();
		}
		
	}
	else
	{
	}
	system("cls");
}

void Menu::save()
{
	int choice;
	cout
		<< "1.保存人员信息到本地" << endl
		<< "2.返回上一级菜单" << endl
		<< "输入对应号码进行选择: ";
	cin >> choice;
	if (choice == 1)
	{
		cout << this;  //存储内存数据到本地
		cout << "按enter键继续...." << endl;
		getchar();
		getchar();
	}
	else
	{
	}
	system("cls");
}

ostream& operator<<(ostream& out, Menu* menu)
{
	menu->writeStaffInfo();
	cout << "**人员信息已从内存写入本地**" << endl;
	// TODO: 在此处插入 return 语句
	return out;
}

istream& operator>>(istream& in, Menu* menu)
{
	menu->readStaffInfo();
	cout << "**人员信息已从本地读入内存**" << endl;
	// TODO: 在此处插入 return 语句
	return in;
}
