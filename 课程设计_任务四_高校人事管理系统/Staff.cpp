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
		return "男";
	}
	else
	{
		return "女";
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
		return "无职务";
	}
	else if (m_job[i] == 1)
	{
		return "教师";
	}	
	else if (m_job[i] == 2)
	{
		return "教导主任";

	}	
	else if (m_job[i] == 3)
	{
		return "系主任";

	}	
	else if (m_job[i] == 4)
	{
		return "学院院长";

	}	
	else if (m_job[i] == 5)
	{
		return "校长助理";

	}
	else if (m_job[i] == 6)
	{
		return "副校长";

	}
	else if (m_job[i] == 7)
	{
		return "书记";

	}
	else
	{
		return "校长";
	}
}

string Staff::getTitle(int i)
{
	if (m_title[i] == 0)
	{
		return "无职称";
	}
	else if (m_title[i] == 1)
	{
		return "助教";
	}
	else if (m_title[i] == 2)
	{
		return "讲师";
	}
	else if (m_title[i] == 3)
	{
		return "副教授";
	}
	else
	{
		return "教授";
	}
}

string Staff::getPolitics(int i)
{
	if (m_politics[i] == 0)
	{
		return "群众";
	}
	else
	{
		return "中共党员";
	}
}

string Staff::getEdu(int i)
{
	if (m_edu[i] == 0)
	{
		return "本科以下";
	}
	else if (m_edu[i] == 1)
	{
		return "本科";
	}
	else if (m_edu[i] == 2)
	{
		return "硕士";
	}
	else
	{
		return "博士";
	}
}

string Staff::getType(int i)
{
	if (m_type[i] == 0)
	{
		return "行政人员";
	}
	else if (m_type[i] == 1)
	{
		return "教师";
	}
	else if (m_type[i] == 2)
	{
		return "双肩挑人员";
	}
	else if (m_type[i] == 3)
	{
		return "退休人员";
	}
	else if (m_type[i] == 4)
	{
		return "返聘人员";
	}
	else
	{
		return "临时工";
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
	if (m_num[i] == 0)  //0表示空
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
		if (isEmpty(i))  //为空就可以输入信息
		{
			m_num[i] = m_max_num;
			m_max_num++;
			cout << "该人员系统为其生成的编号为: " << m_num[i] << endl
				<< "请输入信息" << endl;
			cout << "姓名: ";
			cout << endl;
			cin >> m_name[i];

			cout << "性别(0男性 1女性): ";
			cout << endl;
			cin >> m_sex[i];

			cout << "年龄: ";
			cout << endl;
			cin >> m_age[i];

			cout << "职务(0无职务 1教师 2教导主任3 系主任 4学院院长 5校长助理6 副校长 7书记 8校长): ";
			cout << endl;
			cin >> m_job[i];

			cout << "职称(0无职称 1助教 2讲师 3副教授 4教授): ";
			cout << endl;
			cin >> m_title[i];

			cout << "政治面貌(0群众 1中共党员): ";
			cout << endl;
			cin >> m_politics[i];

			cout << "最高学历(0本科以下 1本科 2硕士 3博士): ";
			cout << endl;
			cin >> m_edu[i];

			cout << "人员类型(0行政人员 1教师 2双肩挑 3退休 4返聘 5临时工): ";
			cout << endl;
			cin >> m_type[i];

			cout << "任职时间(格式:YYYY-MM-DD): ";
			cout << endl;
			cin >> m_worktime[i];

			cout << "来校时间(格式:YYYY-MM-DD): ";
			cout << endl;
			cin >> m_schooltime[i];
			getchar();
			cout << "是否继续输入人员信息?(输入任意字符按enter键停止 或者 直接按enter键继续输入...." << endl;
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
		<< "1.全部删除" << endl
		<< "2.输入编号选择性删除" << endl
		<< "3.返回到上一级菜单" << endl
		<< "输入对应号码进行选择: ";
	cin >> choice;
	if (choice == 1)
	{
		for ( i = 0; i < m_searchNum; i++)
		{
			m_num[m_searchList[i]] = 0;  //通过将编号列表置空来快速删除信息
		}
		cout << "全部删除完成 按enter键继续....";
		getchar();
		getchar();
	}
	else if(choice == 2)
	{
		int temp;
		char c;
		cout << "请输入需要删除的人员的编号(编号与编号之间空格隔开):" << endl;
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
						cout << "编号为 " << temp << " 的人员不在列表里,请检查是否输入错误!" << endl;
					}
				}
				if (c == '\n')
				{
					break;
				}
			}
			cout<<"删除完成! 是否继续删除?"<<endl
				<<"1.继续删除"<<endl
				<<"2.结束删除"<<endl
				<< "输入对应号码进行选择: ";
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
		<< "1.全部修改" << endl
		<< "2.输入编号选择性修改" << endl
		<< "3.返回上一级菜单" << endl
		<< "输入对应号码进行选择: ";
	cin >> choice;
	if (choice == 1)
	{
		for (i = 0; i < m_searchNum; i++)
		{
			modiStaffInfo(m_searchList[i]);
		}
		cout << "全部修改完成 按enter键继续....";
		getchar();
		getchar();
	}
	else if(choice==2)
	{
		int temp;
		char c;
		do
		{
			cout << "请输入需要删除的人员的编号(编号与编号之间空格隔开):" << endl;
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
						cout << "编号为 " << temp << " 的人员不在列表里,请检查是否输入错误!" << endl;
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
				cout << "检测到有编号可能输入错误,是否继续修改?(1继续 2结束)" << endl;
				cin >> choice;
			}
		} while (choice != 2);

	}
}

void Staff::modiStaffInfo(int i)  //i:数组位置
{
	int choice;
	do
	{
		cout
			<< endl
			<< "正在修改编号为 " << m_num[i] << " 人员的信息" << endl
			<< "1.修改姓名" << endl
			<< "2.修改性别" << endl
			<< "3.修改年龄" << endl
			<< "4.修改职务" << endl
			<< "5.修改职称" << endl
			<< "6.修改政治面貌" << endl
			<< "7.修改最高学历" << endl
			<< "8.修改人员类型" << endl
			<< "9.修改任职时间" << endl
			<< "10.修改来校时间" << endl
			<< "11.放弃对改人员的修改" << endl;
		cin >> choice;

		if (choice == 1)
		{
			cout << "姓名: ";
			cout << endl;
			cin >> m_name[i];
		}
		else if(choice == 2)
		{
			cout << "性别(0男性 1女性): ";
			cout << endl;
			cin >> m_sex[i];
		}
		else if (choice == 3)
		{
			cout << "年龄: ";
			cout << endl;
			cin >> m_age[i];
		}
		else if (choice == 4)
		{
			cout << "职务(0无职务 1教师 2教导主任3 系主任 4学院院长 5校长助理6 副校长 7书记 8校长): ";
			cout << endl;
			cin >> m_job[i];
		}
		else if (choice == 5)
		{
			cout << "职称(0无职称 1助教 2讲师 3副教授 4教授): ";
			cout << endl;
			cin >> m_title[i];
		}
		else if (choice == 6)
		{
			cout << "政治面貌(0群众 1中共党员): ";
			cout << endl;
			cin >> m_politics[i];
		}
		else if (choice == 7)
		{
			cout << "最高学历(0本科以下 1本科 2硕士 3博士): ";
			cout << endl;
			cin >> m_edu[i];
		}
		else if (choice == 8)
		{
			cout << "人员类型(0行政人员 1教师 2双肩挑 3退休 4返聘 5临时工): ";
			cout << endl;
			cin >> m_type[i];
		}
		else if (choice == 9)
		{

			cout << "任职时间(格式:YYYY-MM-DD): ";
			cout << endl;
			cin >> m_worktime[i];
		}
		else if (choice == 10)
		{

			cout << "来校时间(格式:YYYY-MM-DD): ";
			cout << endl;
			cin >> m_schooltime[i];
		}

		if (choice != 11)
		{
			cout << "是否继续修改?(1是 2否)" << endl;
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
	m_searchNum = 0;  //初始化搜寻列表人员数量
	if (n == 1)
	{
		cout << "请输入编号: ";
		cin >> num;
		printHead();
		for ( i = 0; i < MAX; i++)
		{
			if (m_num[i] == num)
			{
				printStaff(i);
				statisticStaff(i);
				break;  //编号不会重复 到即可退出循环
			}
		}
	}
	else if (n == 2)
	{
		cout << "性别(0男性 1女性)" << endl
			<< "输入号码: ";
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
		cout << "请输入姓名: ";
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
		cout << "请输入年龄: ";
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
		cout << "职务(0无职务 1教师 2教导主任 3系主任 4学院院长 5校长助理6 副校长 7书记 8校长)" << endl
			<< "输入号码: ";
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
		cout << "职称(0无职称 1助教 2讲师 3副教授 4教授)" << endl
			<< "输入号码: ";
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
		cout << "政治面貌(0群众 1中共党员)" << endl
			<< "输入号码: ";
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
		cout << "最高学历(0本科以下 1本科 2硕士 3博士)" << endl
			<< "输入号码: ";
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
		cout << "人员类型(0行政人员 1教师 2双肩挑 3退休 4返聘 5临时工)" << endl
			<< "输入号码: ";
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
		<< "搜索完成,共找到 " << m_searchNum << " 个人员的信息" << endl
		<<"按enter键继续....(若出现表格换行现象,请拉长窗口)";
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
			m_num[i] = 0;  //通过将编号初始化为0来置空
		}
	}
	m_max_num = 1;  //人员最大编号重置为1
	cout << "初始化数据完成! 按enter键继续....";
	getchar();
	getchar();
	system("cls");
}

void Staff::printHead()
{
	cout
		<< "----------------------------------------------------------------------------------------------------------------------------" << endl
		<< setiosflags(ios::left) 
		<< setw(8) << "编号" 
		<< resetiosflags(ios::left)

		<< setiosflags(ios::right) 
		<< setw(8) << "姓名"
		<< setw(8) << "性别"
		<< setw(8) << "年龄" 
		<< setw(12) << "职务" 
		<< setw(12) << "职称" 
		<< setw(12) << "政治面貌" 
		<< setw(12) << "最高学历" 
		<< setw(12) << "人员类型" 
		<< setw(16) << "任职时间" 
		<< setw(16) << "来校时间" 
		<< resetiosflags(ios::right) << endl
		<< "----------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Staff::printStaff(int i)
{
	string sex, job, title, politics, edu, type;
	if (m_sex[i] == 0)
	{
		sex = "男";
	}
	else
	{
		sex = "女";
	}

	if (m_job[i] == 0)
	{
		job = "无职务";
	}
	else if (m_job[i] == 1)
	{
		job = "教师";
	}
	else if (m_job[i] == 2)
	{
		job = "教导主任";
	}
	else if (m_job[i] == 3)
	{
		job = "系主任";
	}
	else if (m_job[i] == 4)
	{
		job = "学院院长";
	}
	else if (m_job[i] == 5)
	{
		job = "校长助理";
	}
	else if (m_job[i] == 6)
	{
		job = "副校长";
	}
	else if (m_job[i] == 7)
	{
		job = "书记";
	}
	else
	{
		job = "校长";
	}

	if (m_title[i] == 0)
	{
		title = "无职称";
	}
	else if (m_title[i] == 1)
	{
		title = "助教";
	}
	else if (m_title[i] == 2)
	{
		title = "讲师";
	}
	else if (m_title[i] == 3)
	{
		title = "副教授";
	}
	else
	{
		title = "教授";
	}

	if (m_politics[i] == 0)
	{
		politics = "群众";
	}
	else
	{
		politics = "中共党员";
	}

	if (m_edu[i] == 0)
	{
		edu = "本科以下";
	}
	else if (m_edu[i] == 1)
	{
		edu = "本科";
	}
	else if (m_edu[i] == 2)
	{
		edu = "硕士";
	}
	else
	{
		edu = "博士";
	}

	if (m_type[i] == 0)
	{
		type = "行政人员";
	}
	else if (m_type[i] == 1)
	{
		type = "教师";
	}
	else if (m_type[i] == 2)
	{
		type = "双肩挑";
	}
	else if (m_type[i] == 3)
	{
		type = "退休";
	}
	else if (m_type[i] == 4)
	{
		type = "返聘人员";
	}
	else
	{
		type = "临时工";
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


