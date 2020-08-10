#include "Staff.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

string Staff::getName(int i)
{
	return m_name[i];
}

string Staff::getWorkTime(int i)
{
	return m_worktime[i];
}

string Staff::getSchoolTime(int i)
{
	return m_schooltime[i];
}

int Staff::getNum(string name)
{
	int i;
	for ( i = 0; i < MAX; i++)
	{
		if (m_name[i] == name)
		{
			break;
		}
	}
	return m_num[i];
}

string Staff::getSex(int i)
{
	if (m_sex[i] == 0)
	{
		return "��";
	}
	else
	{
		return "Ů";
	}
}

int Staff::getAge(int i)
{
	return m_age[i];
}

string Staff::getJob(int i)
{
	if (m_job[i] == 0)
	{
		return "��ְ��";
	}
	else if (m_job[i] == 1)
	{
		return "��ʦ";
	}	
	else if (m_job[i] == 2)
	{
		return "�̵�����";

	}	
	else if (m_job[i] == 3)
	{
		return "ϵ����";

	}	
	else if (m_job[i] == 4)
	{
		return "ѧԺԺ��";

	}	
	else if (m_job[i] == 5)
	{
		return "У������";

	}
	else if (m_job[i] == 6)
	{
		return "��У��";

	}
	else if (m_job[i] == 7)
	{
		return "���";

	}
	else
	{
		return "У��";
	}
}

string Staff::getTitle(int i)
{
	if (m_title[i] == 0)
	{
		return "��ְ��";
	}
	else if (m_title[i] == 1)
	{
		return "����";
	}
	else if (m_title[i] == 2)
	{
		return "��ʦ";
	}
	else if (m_title[i] == 3)
	{
		return "������";
	}
	else
	{
		return "����";
	}
}

string Staff::getPolitics(int i)
{
	if (m_politics[i] == 0)
	{
		return "Ⱥ��";
	}
	else
	{
		return "�й���Ա";
	}
}

string Staff::getEdu(int i)
{
	if (m_edu[i] == 0)
	{
		return "��������";
	}
	else if (m_edu[i] == 1)
	{
		return "����";
	}
	else if (m_edu[i] == 2)
	{
		return "˶ʿ";
	}
	else
	{
		return "��ʿ";
	}
}

string Staff::getType(int i)
{
	if (m_type[i] == 0)
	{
		return "������Ա";
	}
	else if (m_type[i] == 1)
	{
		return "��ʦ";
	}
	else if (m_type[i] == 2)
	{
		return "˫������Ա";
	}
	else if (m_type[i] == 3)
	{
		return "������Ա";
	}
	else if (m_type[i] == 4)
	{
		return "��Ƹ��Ա";
	}
	else
	{
		return "��ʱ��";
	}
}

int Staff::getTypeNum(int i)
{
	return m_type[i];
}

void Staff::setName(int i, string name)
{
	m_name[i] == name;
}

void Staff::setWorkTime(int i, string worktime)
{
	m_worktime[i] = worktime;
}

void Staff::setSchoolTime(int i, string schooltime)
{
	m_schooltime[i] = schooltime;
}

void Staff::setNum(int i, int n)
{
	m_num[i] = n;
}

void Staff::setSex(int i, int n)
{
	m_sex[i]=n;
}

void Staff::setAge(int i, int n)
{
	m_age[i] = n;
}

void Staff::setJob(int i, int n)
{
	m_job[i]=n;
}

void Staff::setTitle(int i, int n)
{
	m_title[i]=n;
}

void Staff::setPolitics(int i, int n)
{
	m_politics[i]=n;
}

void Staff::setEdu(int i, int n)
{
	m_edu[i]=n;
}

void Staff::setType(int i, int n)
{
	m_type[i] = n;
}

bool Staff::isEmpty(int i)
{
	if (m_num[i] == 0)  //0��ʾ��
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Staff::addStaff()
{
	int i;
	char c;
	for ( i = 0; i < MAX; i++)
	{
		if (isEmpty(i))  //Ϊ�վͿ���������Ϣ
		{
			m_num[i] = m_max_num;
			m_max_num++;
			cout << "����ԱϵͳΪ�����ɵı��Ϊ: " << m_num[i] << endl
				<< "��������Ϣ" << endl;
			cout << "����: ";
			cout << endl;
			cin >> m_name[i];

			cout << "�Ա�(0���� 1Ů��): ";
			cout << endl;
			cin >> m_sex[i];

			cout << "����: ";
			cout << endl;
			cin >> m_age[i];

			cout << "ְ��(0��ְ�� 1��ʦ 2�̵�����3 ϵ���� 4ѧԺԺ�� 5У������6 ��У�� 7��� 8У��): ";
			cout << endl;
			cin >> m_job[i];

			cout << "ְ��(0��ְ�� 1���� 2��ʦ 3������ 4����): ";
			cout << endl;
			cin >> m_title[i];

			cout << "������ò(0Ⱥ�� 1�й���Ա): ";
			cout << endl;
			cin >> m_politics[i];

			cout << "���ѧ��(0�������� 1���� 2˶ʿ 3��ʿ): ";
			cout << endl;
			cin >> m_edu[i];

			cout << "��Ա����(0������Ա 1��ʦ 2˫���� 3���� 4��Ƹ 5��ʱ��): ";
			cout << endl;
			cin >> m_type[i];

			cout << "��ְʱ��(��ʽ:YYYY-MM-DD): ";
			cout << endl;
			cin >> m_worktime[i];

			cout << "��Уʱ��(��ʽ:YYYY-MM-DD): ";
			cout << endl;
			cin >> m_schooltime[i];
			getchar();
			cout << "�Ƿ����������Ա��Ϣ?(���������ַ���enter��ֹͣ ���� ֱ�Ӱ�enter����������...." << endl;
			c = getchar();
			if (c != '\n')
			{
				break;
			}
		}
		
		system("cls");
	}
}

void Staff::delStaff(int n)
{
	int choice;
	int i,j;
	searchStaff(n);
	cout
		<<endl
		<< "1.ȫ��ɾ��" << endl
		<< "2.������ѡ����ɾ��" << endl
		<< "3.���ص���һ���˵�" << endl
		<< "�����Ӧ�������ѡ��: ";
	cin >> choice;
	if (choice == 1)
	{
		for ( i = 0; i < m_searchNum; i++)
		{
			m_num[m_searchList[i]] = 0;  //ͨ��������б��ÿ�������ɾ����Ϣ
		}
		cout << "ȫ��ɾ����� ��enter������....";
		getchar();
		getchar();
	}
	else if(choice == 2)
	{
		int temp;
		char c;
		cout << "��������Ҫɾ������Ա�ı��(�������֮��ո����):" << endl;
		do
		{
			for ( i = 0; i < MAX; i++)
			{
				cin >> temp;
				c = getchar();
				for ( j = 0; j < m_searchNum; j++)
				{
					if (m_num[m_searchList[j]] == temp)
					{
						m_num[m_searchList[j]] = 0;
						break;
					}
					if (j == (m_searchNum - 1) && m_num[m_searchList[j]] != temp)
					{
						cout << "���Ϊ " << temp << " ����Ա�����б���,�����Ƿ��������!" << endl;
					}
				}
				if (c == '\n')
				{
					break;
				}
			}
			cout<<"ɾ�����! �Ƿ����ɾ��?"<<endl
				<<"1.����ɾ��"<<endl
				<<"2.����ɾ��"<<endl
				<< "�����Ӧ�������ѡ��: ";
			cin >> choice;
		} while (choice!=2);
		
	}
}

void Staff::modiStaff(int n)
{
	int choice;
	int i, j;
	searchStaff(n);
	cout
		<< endl
		<< "1.ȫ���޸�" << endl
		<< "2.������ѡ�����޸�" << endl
		<< "3.������һ���˵�" << endl
		<< "�����Ӧ�������ѡ��: ";
	cin >> choice;
	if (choice == 1)
	{
		for (i = 0; i < m_searchNum; i++)
		{
			modiStaffInfo(m_searchList[i]);
		}
		cout << "ȫ���޸���� ��enter������....";
		getchar();
		getchar();
	}
	else if(choice==2)
	{
		int temp;
		char c;
		do
		{
			cout << "��������Ҫɾ������Ա�ı��(�������֮��ո����):" << endl;
			for (i = 0; i < MAX; i++)
			{
				cin >> temp;
				c = getchar();
				for (j = 0; j < m_searchNum; j++)
				{
					if (m_num[m_searchList[j]] == temp)
					{
						modiStaffInfo(m_searchList[j]);
						break;
					}
					if (j == (m_searchNum - 1) && m_num[m_searchList[j]] != temp)
					{
						cout << "���Ϊ " << temp << " ����Ա�����б���,�����Ƿ��������!" << endl;
						choice = -1;
					}
				}
				if (c == '\n')
				{
					break;
				}
			}
			if (choice == -1)
			{
				cout << "��⵽�б�ſ����������,�Ƿ�����޸�?(1���� 2����)" << endl;
				cin >> choice;
			}
		} while (choice != 2);

	}
}

void Staff::modiStaffInfo(int i)  //i:����λ��
{
	int choice;
	do
	{
		cout
			<< endl
			<< "�����޸ı��Ϊ " << m_num[i] << " ��Ա����Ϣ" << endl
			<< "1.�޸�����" << endl
			<< "2.�޸��Ա�" << endl
			<< "3.�޸�����" << endl
			<< "4.�޸�ְ��" << endl
			<< "5.�޸�ְ��" << endl
			<< "6.�޸�������ò" << endl
			<< "7.�޸����ѧ��" << endl
			<< "8.�޸���Ա����" << endl
			<< "9.�޸���ְʱ��" << endl
			<< "10.�޸���Уʱ��" << endl
			<< "11.�����Ը���Ա���޸�" << endl;
		cin >> choice;

		if (choice == 1)
		{
			cout << "����: ";
			cout << endl;
			cin >> m_name[i];
		}
		else if(choice == 2)
		{
			cout << "�Ա�(0���� 1Ů��): ";
			cout << endl;
			cin >> m_sex[i];
		}
		else if (choice == 3)
		{
			cout << "����: ";
			cout << endl;
			cin >> m_age[i];
		}
		else if (choice == 4)
		{
			cout << "ְ��(0��ְ�� 1��ʦ 2�̵�����3 ϵ���� 4ѧԺԺ�� 5У������6 ��У�� 7��� 8У��): ";
			cout << endl;
			cin >> m_job[i];
		}
		else if (choice == 5)
		{
			cout << "ְ��(0��ְ�� 1���� 2��ʦ 3������ 4����): ";
			cout << endl;
			cin >> m_title[i];
		}
		else if (choice == 6)
		{
			cout << "������ò(0Ⱥ�� 1�й���Ա): ";
			cout << endl;
			cin >> m_politics[i];
		}
		else if (choice == 7)
		{
			cout << "���ѧ��(0�������� 1���� 2˶ʿ 3��ʿ): ";
			cout << endl;
			cin >> m_edu[i];
		}
		else if (choice == 8)
		{
			cout << "��Ա����(0������Ա 1��ʦ 2˫���� 3���� 4��Ƹ 5��ʱ��): ";
			cout << endl;
			cin >> m_type[i];
		}
		else if (choice == 9)
		{

			cout << "��ְʱ��(��ʽ:YYYY-MM-DD): ";
			cout << endl;
			cin >> m_worktime[i];
		}
		else if (choice == 10)
		{

			cout << "��Уʱ��(��ʽ:YYYY-MM-DD): ";
			cout << endl;
			cin >> m_schooltime[i];
		}

		if (choice != 11)
		{
			cout << "�Ƿ�����޸�?(1�� 2��)" << endl;
			cin >> choice;
			if (choice == 2)
			{
				choice = 11;
			}
		}
		
	} while (choice!=11);
}

void Staff::searchStaff(int n)
{
	int i;
	int num;
	string name;
	m_searchNum = 0;  //��ʼ����Ѱ�б���Ա����
	if (n == 1)
	{
		cout << "��������: ";
		cin >> num;
		printHead();
		for ( i = 0; i < MAX; i++)
		{
			if (m_num[i] == num)
			{
				printStaff(i);
				statisticStaff(i);
				break;  //��Ų����ظ� �������˳�ѭ��
			}
		}
	}
	else if (n == 2)
	{
		cout << "�Ա�(0���� 1Ů��)" << endl
			<< "�������: ";
		cin >> num;
		printHead();
		for ( i = 0; i < MAX; i++)
		{
			if (!isEmpty(i))
			{
				if (m_sex[i] == num)
				{
					printStaff(i);
					statisticStaff(i);
				}
			}
		}
	}
	else if (n == 3)
	{
		cout << "����������: ";
		cin >> name;
		printHead();
		for (i = 0; i < MAX; i++)
		{
			if (!isEmpty(i))
			{
				if (m_name[i] == name)
				{
					printStaff(i);
					statisticStaff(i);
				}
			}
		}
	}
	else if (n == 4)
	{
		cout << "����������: ";
		cin >> num;
		printHead();
		for (i = 0; i < MAX; i++)
		{
			if (!isEmpty(i))
			{
				if (m_age[i] == num)
				{
					printStaff(i);
					statisticStaff(i);
				}
			}
		}
	}
	else if (n == 5)
	{
		cout << "ְ��(0��ְ�� 1��ʦ 2�̵����� 3ϵ���� 4ѧԺԺ�� 5У������6 ��У�� 7��� 8У��)" << endl
			<< "�������: ";
		cin >> num;
		printHead();
		for (i = 0; i < MAX; i++)
		{
			if (!isEmpty(i))
			{
				if (m_job[i] == num)
				{
					printStaff(i);
					statisticStaff(i);
				}
			}
		}
	}
	else if (n == 6)
	{
		cout << "ְ��(0��ְ�� 1���� 2��ʦ 3������ 4����)" << endl
			<< "�������: ";
		cin >> num;
		printHead();
		for (i = 0; i < MAX; i++)
		{
			if (!isEmpty(i))
			{
				if (m_title[i] == num)
				{
					printStaff(i);
					statisticStaff(i);
				}
			}
		}
	}
	else if (n == 7)
	{
		cout << "������ò(0Ⱥ�� 1�й���Ա)" << endl
			<< "�������: ";
		cin >> num;
		printHead();
		for (i = 0; i < MAX; i++)
		{
			if (!isEmpty(i))
			{
				if (m_politics[i] == num)
				{
					printStaff(i);
					statisticStaff(i);
				}
			}
		}
	}
	else if (n == 8)
	{
		cout << "���ѧ��(0�������� 1���� 2˶ʿ 3��ʿ)" << endl
			<< "�������: ";
		cin >> num;
		printHead();
		for (i = 0; i < MAX; i++)
		{
			if (!isEmpty(i))
			{
				if (m_edu[i] == num)
				{
					printStaff(i);
					statisticStaff(i);
				}
			}
		}
	}
	else if( n == 9)
	{
		cout << "��Ա����(0������Ա 1��ʦ 2˫���� 3���� 4��Ƹ 5��ʱ��)" << endl
			<< "�������: ";
		cin >> num;
		printHead();
		for (i = 0; i < MAX; i++)
		{
			if (!isEmpty(i))
			{
				if (m_type[i] == num)
				{
					printStaff(i);
					statisticStaff(i);
				}
			}
		}
	}
	else
	{
		printHead();
		for (i = 0; i < MAX; i++)
		{
			if (!isEmpty(i))
			{
				printStaff(i);
				statisticStaff(i);
			}
		}
	}

	cout
		<< "----------------------------------------------------------------------------------------------------------------------------" << endl;
	cout 
		<< "�������,���ҵ� " << m_searchNum << " ����Ա����Ϣ" << endl
		<<"��enter������....(�����ֱ��������,����������)";
	getchar();
}

void Staff::statisticStaff(int i)
{
	m_searchList[m_searchNum] = i;
	m_searchNum++;
}

void Staff::initStaff()
{
	int i;
	for ( i = 0; i < MAX; i++)
	{
		if (!isEmpty(i))
		{
			m_num[i] = 0;  //ͨ������ų�ʼ��Ϊ0���ÿ�
		}
	}
	m_max_num = 1;  //��Ա���������Ϊ1
	cout << "��ʼ���������! ��enter������....";
	getchar();
	getchar();
	system("cls");
}

void Staff::printHead()
{
	cout
		<< "----------------------------------------------------------------------------------------------------------------------------" << endl
		<< setiosflags(ios::left) 
		<< setw(8) << "���" 
		<< resetiosflags(ios::left)

		<< setiosflags(ios::right) 
		<< setw(8) << "����"
		<< setw(8) << "�Ա�"
		<< setw(8) << "����" 
		<< setw(12) << "ְ��" 
		<< setw(12) << "ְ��" 
		<< setw(12) << "������ò" 
		<< setw(12) << "���ѧ��" 
		<< setw(12) << "��Ա����" 
		<< setw(16) << "��ְʱ��" 
		<< setw(16) << "��Уʱ��" 
		<< resetiosflags(ios::right) << endl
		<< "----------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Staff::printStaff(int i)
{
	string sex, job, title, politics, edu, type;
	if (m_sex[i] == 0)
	{
		sex = "��";
	}
	else
	{
		sex = "Ů";
	}

	if (m_job[i] == 0)
	{
		job = "��ְ��";
	}
	else if (m_job[i] == 1)
	{
		job = "��ʦ";
	}
	else if (m_job[i] == 2)
	{
		job = "�̵�����";
	}
	else if (m_job[i] == 3)
	{
		job = "ϵ����";
	}
	else if (m_job[i] == 4)
	{
		job = "ѧԺԺ��";
	}
	else if (m_job[i] == 5)
	{
		job = "У������";
	}
	else if (m_job[i] == 6)
	{
		job = "��У��";
	}
	else if (m_job[i] == 7)
	{
		job = "���";
	}
	else
	{
		job = "У��";
	}

	if (m_title[i] == 0)
	{
		title = "��ְ��";
	}
	else if (m_title[i] == 1)
	{
		title = "����";
	}
	else if (m_title[i] == 2)
	{
		title = "��ʦ";
	}
	else if (m_title[i] == 3)
	{
		title = "������";
	}
	else
	{
		title = "����";
	}

	if (m_politics[i] == 0)
	{
		politics = "Ⱥ��";
	}
	else
	{
		politics = "�й���Ա";
	}

	if (m_edu[i] == 0)
	{
		edu = "��������";
	}
	else if (m_edu[i] == 1)
	{
		edu = "����";
	}
	else if (m_edu[i] == 2)
	{
		edu = "˶ʿ";
	}
	else
	{
		edu = "��ʿ";
	}

	if (m_type[i] == 0)
	{
		type = "������Ա";
	}
	else if (m_type[i] == 1)
	{
		type = "��ʦ";
	}
	else if (m_type[i] == 2)
	{
		type = "˫����";
	}
	else if (m_type[i] == 3)
	{
		type = "����";
	}
	else if (m_type[i] == 4)
	{
		type = "��Ƹ��Ա";
	}
	else
	{
		type = "��ʱ��";
	}


	cout
		<< setiosflags(ios::left)
		<< setw(8) << m_num[i]
		<< resetiosflags(ios::left)

		<< setiosflags(ios::right)
		<< setw(8) << m_name[i]
		<< setw(8) << sex
		<< setw(8) << m_age[i]
		<< setw(12) << job
		<< setw(12) << title
		<< setw(12) << politics
		<< setw(12) << edu
		<< setw(12) << type
		<< setw(16) << m_worktime[i]
		<< setw(16) << m_schooltime[i]
		<< resetiosflags(ios::right) << endl;
}

void Staff::writeStaffInfo()
{
	int i;
	ofstream out_numfile, out_namefile, out_sexfile, out_agefile, out_jobfile, out_titlefile, out_politicsfile, out_edufile, out_typefile, out_worktimefile, out_schooltimefile, out_maxnumfile;
	out_numfile.open("num.txt", ios::out | ios::trunc);
	out_namefile.open("name.txt", ios::out | ios::trunc);
	out_sexfile.open("sex.txt", ios::out | ios::trunc);
	out_agefile.open("age.txt", ios::out | ios::trunc);
	out_jobfile.open("job.txt", ios::out | ios::trunc);
	out_titlefile.open("title.txt", ios::out | ios::trunc);
	out_politicsfile.open("politics.txt", ios::out | ios::trunc);
	out_edufile.open("edu.txt", ios::out | ios::trunc);
	out_typefile.open("type.txt", ios::out | ios::trunc);
	out_worktimefile.open("worktime.txt", ios::out | ios::trunc);
	out_schooltimefile.open("schooltime.txt", ios::out | ios::trunc);
	out_maxnumfile.open("maxnum.txt", ios::out | ios::trunc);
	
	for ( i = 0; i < MAX; i++)
	{
		if (!isEmpty(i))
		{
			out_numfile << m_num[i]<<endl;
			out_namefile << m_name[i]<<endl;
			out_sexfile << m_sex[i]<<endl;
			out_agefile << m_age[i]<<endl;
			out_jobfile << m_job[i]<<endl;
			out_titlefile<<m_title[i]<<endl;
			out_politicsfile<<m_politics[i]<<endl;
			out_edufile<<m_edu[i]<<endl;
			out_typefile << m_type[i] << endl;
			out_worktimefile<<m_worktime[i]<<endl;
			out_schooltimefile<<m_schooltime[i]<<endl;
			out_maxnumfile << m_max_num << endl;
		}
	}

	out_numfile.close();
	out_namefile.close();
	out_sexfile.close();
	out_agefile.close();
	out_jobfile.close();
	out_titlefile.close();
	out_politicsfile.close();
	out_edufile.close();
	out_typefile.close();
	out_worktimefile.close();
	out_schooltimefile.close();
	out_maxnumfile.close();
}

void Staff::readStaffInfo()
{
	int i;
	ifstream in_numfile, in_namefile, in_sexfile, in_agefile, in_jobfile, in_titlefile, in_politicsfile, in_edufile, in_typefile, in_worktimefile, in_schooltimefile, in_maxnumfile;
	in_numfile.open("num.txt", ios::in);
	in_namefile.open("name.txt", ios::in);
	in_sexfile.open("sex.txt", ios::in);
	in_agefile.open("age.txt", ios::in);
	in_jobfile.open("job.txt", ios::in);
	in_titlefile.open("title.txt", ios::in);
	in_politicsfile.open("politics.txt", ios::in);
	in_edufile.open("edu.txt", ios::out | ios::trunc);
	in_typefile.open("type.txt", ios::out | ios::trunc);
	in_worktimefile.open("worktime.txt", ios::in);
	in_schooltimefile.open("schooltime.txt", ios::in);
	in_maxnumfile.open("maxnum.txt", ios::in);


	for (i = 0; i < MAX; i++)
	{
		in_numfile >> m_num[i];
		in_namefile >> m_name[i];
		in_sexfile >> m_sex[i];
		in_agefile >> m_age[i];
		in_jobfile >> m_job[i];
		in_titlefile >> m_title[i];
		in_politicsfile >> m_politics[i];
		in_edufile >> m_edu[i];
		in_typefile >> m_type[i];
		in_worktimefile >> m_worktime[i];
		in_schooltimefile >> m_schooltime[i];
		in_maxnumfile >> m_max_num;
	}

	in_numfile.close();
	in_namefile.close();
	in_sexfile.close();
	in_agefile.close();
	in_jobfile.close();
	in_titlefile.close();
	in_politicsfile.close();
	in_edufile.close();
	in_typefile.close();
	in_worktimefile.close();
	in_schooltimefile.close();
	in_maxnumfile.close();
}


