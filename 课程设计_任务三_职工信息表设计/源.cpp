#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>  //表格格式化输出

using namespace std;

class Form  //抽象基类Form声明
{
public:
	virtual void display() = 0;
};

class EmployeeForm:public Form  //职工信息表类声明
{
public:
	EmployeeForm(string* name, int* age, int* numbers, string* sex, int* num)
	{
		int i;
		m_numbers = *numbers;
		for ( i = 0; i < m_numbers; i++)
		{
			m_name[i] = name[i];
			m_age[i] = age[i];
			m_sex[i] = sex[i];
			m_num[i] = num[i];
		}
	}
	EmployeeForm()
	{
		int i;
		m_numbers = 0;
		for (i = 0; i < 10; i++)
		{
			m_name[i] = { 0 };
			m_age[i] = { 0 };
			m_sex[i] = { 0 };
			m_num[i] = { 0 };
		}
	}
	virtual void display();  //输出数组内容
	friend class EmployeeBriefForm;
protected:
	string m_name[10];  //姓名
	int m_age[10];  //年龄
	int m_numbers;  //信息表包含的职工的人数
private:
	string m_sex[10];  //性别
	int m_num[10];  //编号

};

class EmployeeBriefForm : public EmployeeForm
{
public:
	EmployeeBriefForm(EmployeeForm* f)
	{
		int i;
		m_numbers = f->m_numbers;
		for ( i = 0; i < m_numbers; i++)
		{
			m_name[i] = f->m_name[i];
			m_age[i] = f->m_age[i];
		}
	}
	EmployeeBriefForm()
	{
		int i;
		m_numbers = 0;
		for (i = 0; i < m_numbers; i++)
		{
			m_name[i] = { 0 };
			m_age[i] = { 0 };
		}
	}
	virtual void display();  //输出数组内容

};

void enterInfo(string* name, int* age, int* numbers, string* sex, int* num)
{
	int i;
	char c;
	for (i = 0; i < 10; i++)
	{
		cout << "职工" << i + 1 << ":" << endl
			<< "   姓名: ";
		cin >> name[i];
		cout << "   年龄: ";
		cin >> age[i];
		cout << "   性别: ";
		cin >> sex[i];
		cout << "   编号: ";
		cin >> num[i];
		getchar();  //吸收回车符
		cout << "是否继续输入?(输入任意字符敲回车停止输入 或者 直接敲回车继续输入....)";
		c = getchar();
		system("cls");  //清屏
		if (c != '\n')  // 不是回车则停止输入信息
		{
			*numbers = i + 1;  //包含的职工人数=循环次数
			break;
		}
	}
}

void printer(Form* ptr)  //根据实际对象输出他们的内容
{
	ptr->display();
}

int main()
{
	cout << "--课程设计_任务三_职工信息表设计--" << endl;
	string name[10];  //姓名
	int age[10];  //年龄
	int numbers;  //信息表包含的职工的人数
	string sex[10];  //性别
	int num[10];  //编号


	//--调试用---
	//string name[10] = { "小明","小红","小王","小高","小李","小白","小黑","小绿","小赵","小吴" };
	//int age[10] = { 13,14,15,16,17,18,19,20,21,22 };
	//int numbers = 10;
	//string sex[10] = { "男","女","男", "男", "男", "男", "男", "男", "男", "女" };
	//int num[10] = { 100001,100002,100003,100004,100005,100006,100007,100008,100009,100010 };


	string* p_name = name, * p_sex = sex;
	int* p_age = age, * p_numbers = &numbers, * p_num = num;
	enterInfo(p_name, p_age, p_numbers, p_sex, p_num);  //输入职工信息

	Form* f;  //声明抽象基类Form指针,不能声明对象
	EmployeeForm ef(p_name, p_age, p_numbers, p_sex, p_num);  //声明派生类对象
	EmployeeBriefForm ebf(&ef);  //声明派生类对象
	
	f = &ef;
	printer(f);  //调用职工信息表类函数成员
	f = &ebf;
	printer(f);  //调用职工信息简表类函数成员
	return 0;
}

void EmployeeForm::display()
{
	int i;
	cout << "------------------------------------" << endl;
	cout << "             职工信息表" << endl;
	cout << "------------------------------------" << endl;
	cout << setiosflags(ios::left) << setw(9) << "姓名" << resetiosflags(ios::left)  //左对齐 设置列宽度为9
		<< setiosflags(ios::right) << setw(9) << "年龄" << setw(9) << "性别"
		<< setw(9) << "编号" << resetiosflags(ios::right) << endl;  //右对齐 设置列宽度为9
	cout << "------------------------------------" << endl;
	for ( i = 0; i < m_numbers; i++)
	{
		cout << setiosflags(ios::left) << setw(9) << m_name[i] << resetiosflags(ios::left)
			<< setiosflags(ios::right) << setw(9) << m_age[i] << setw(9) << m_sex[i]
			<< setw(9) << m_num[i] << resetiosflags(ios::right) << endl;
	}
	cout << "------------------------------------" << endl;
}

void EmployeeBriefForm::display()
{
	int i;
	cout << "------------------" << endl;
	cout << "   职工信息简表" << endl;
	cout << "------------------" << endl;
	cout << setiosflags(ios::left) << setw(9) << "姓名" << resetiosflags(ios::left)
		<< setiosflags(ios::right) << setw(9) << "年龄" << resetiosflags(ios::right) << endl;
	cout << "------------------" << endl;
	for (i = 0; i < m_numbers; i++)
	{
		cout << setiosflags(ios::left) << setw(9) << m_name[i] << resetiosflags(ios::left)
			<< setiosflags(ios::right) << setw(9) << m_age[i] << resetiosflags(ios::right) << endl;
	}
	cout << "------------------" << endl;
}
