#include "Menu.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Menu::main()
{
	int choice;
	cout << "ϵͳ�����ɹ�!!" << endl;
	cin >> this;  //�ӱ���txt�ļ���ȡ����
	cout << "��enter������...." << endl;
	getchar();
	system("cls");
	do
	{
		cout
			<< "**��ӭʹ��ѧУ���¹���ϵͳ**" << endl
			<< "1.�����Ա��Ϣ" << endl
			<< "2.ɾ����Ա��Ϣ" << endl
			<< "3.��ѯ��Ա��Ϣ" << endl
			<< "4.�޸���Ա��Ϣ" << endl
			<< "5.ͳ����Ա��Ϣ" << endl
			<< "6.��ʼ����Ա��Ϣ" << endl
			<< "7.������Ա��Ϣ������" << endl
			<< "8.�˳�ϵͳ��������Ա��Ϣ������" << endl
			<< "9.�˳�ϵͳ��������Ա��Ϣ������" << endl
			<< "�����Ӧ�������ѡ��: ";
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
			cout << this;  //��������
			cout << "�˳�ϵͳ....";
		}
		else if (choice == 9)
		{
			cout << "�˳�ϵͳ....";
		}
		else
		{
			cout << "�������������! ����������...." << endl;
		}
	} while (choice!=9&&choice!=8);
	

}

void Menu::add()
{
	int choice;
	do
	{
		cout
			<< "1.��ʼ������Ա��Ϣ" << endl
			<< "2.������һ���˵�" << endl
			<< "�����Ӧ�������ѡ��: ";
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
			cout << "�������������! ����������...." << endl;
		}
	} while (choice!=2);
	
}

void Menu::del()
{
	int choice;
	
	do
	{
		cout 
			<< "1.�����ɾ��" << endl
			<< "2.���Ա�ɾ��" << endl
			<< "3.������ɾ��" << endl
			<< "4.������ɾ��" << endl
			<< "5.��ְ��ɾ��" << endl
			<< "6.��ְ��ɾ��" << endl
			<< "7.��������òɾ��" << endl
			<< "8.�����ѧ��ɾ��" << endl
			<< "9.����Ա����ɾ��" << endl
			<< "10.������һ���˵�" << endl
			<< "�����Ӧ�������ѡ��: ";
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
			cout << "�������������! ����������...." << endl;
		}
	} while (choice != 10);


}

void Menu::modi()
{
	int choice;

	do
	{
		cout
			<< "1.������������޸�" << endl
			<< "2.���Ա��������޸�" << endl
			<< "3.�������������޸�" << endl
			<< "4.�������������޸�" << endl
			<< "5.��ְ���������޸�" << endl
			<< "6.��ְ���������޸�" << endl
			<< "7.��������ò�������޸�" << endl
			<< "8.�����ѧ���������޸�" << endl
			<< "9.����Ա�����������޸�" << endl
			<< "10.������һ���˵�" << endl
			<< "�����Ӧ�������ѡ��: ";
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
			cout << "�������������! ����������...." << endl;
		}
	} while (choice != 10);
}

void Menu::search()
{
	int choice;
	do
	{
		cout
			<< "1.���������" << endl
			<< "2.���Ա�����" << endl
			<< "3.����������" << endl
			<< "4.����������" << endl
			<< "5.��ְ������" << endl
			<< "6.��ְ������" << endl
			<< "7.��������ò����" << endl
			<< "8.�����ѧ������" << endl
			<< "9.����Ա��������" << endl
			<< "10.���������Ա��Ϣ" << endl
			<< "11.������һ���˵�" << endl
			<< "�����Ӧ�������ѡ��: ";
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
			cout << "�������������! ����������...." << endl;
		}
	} while (choice != 11);
}

void Menu::statistic()
{
	int choice;
	do
	{
		cout
			<< "1.�����ͳ��" << endl
			<< "2.���Ա�ͳ��" << endl
			<< "3.������ͳ��" << endl
			<< "4.������ͳ��" << endl
			<< "5.��ְ��ͳ��" << endl
			<< "6.��ְ��ͳ��" << endl
			<< "7.��������òͳ��" << endl
			<< "8.�����ѧ��ͳ��" << endl
			<< "9.����Ա����ͳ��" << endl
			<< "10.������һ���˵�" << endl
			<< "�����Ӧ�������ѡ��: ";
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
			cout << "�������������! ����������...." << endl;
		}
	} while (choice != 10);
}

void Menu::init()
{
	int choice;
	cout
		<< "1.��ʼ����Ա��Ϣ" << endl
		<< "2.������һ���˵�" << endl
		<< "�����Ӧ�������ѡ��: ";

	cin >> choice;
	if (choice==1)
	{
		cout << "��ȷ���Ƿ�Ҫ��ʼ������?(�˲���������ڴ��е�����,������ձ�������)" << endl
			<< "(1ȷ�� 2ȡ��)" << endl
			<< "�����Ӧ�������ѡ��: ";
		cin >> choice;
		if (choice == 1)
		{
			initStaff();
		}
		else
		{
			cout << "��Ա��Ϣ��ȡ����ʼ��,��enter������....";
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
		<< "1.������Ա��Ϣ������" << endl
		<< "2.������һ���˵�" << endl
		<< "�����Ӧ�������ѡ��: ";
	cin >> choice;
	if (choice == 1)
	{
		cout << this;  //�洢�ڴ����ݵ�����
		cout << "��enter������...." << endl;
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
	cout << "**��Ա��Ϣ�Ѵ��ڴ�д�뱾��**" << endl;
	// TODO: �ڴ˴����� return ���
	return out;
}

istream& operator>>(istream& in, Menu* menu)
{
	menu->readStaffInfo();
	cout << "**��Ա��Ϣ�Ѵӱ��ض����ڴ�**" << endl;
	// TODO: �ڴ˴����� return ���
	return in;
}
