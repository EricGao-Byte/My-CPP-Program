#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>  //����ʽ�����

using namespace std;

class Form  //�������Form����
{
public:
	virtual void display() = 0;
};

class EmployeeForm:public Form  //ְ����Ϣ��������
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
	virtual void display();  //�����������
	friend class EmployeeBriefForm;
protected:
	string m_name[10];  //����
	int m_age[10];  //����
	int m_numbers;  //��Ϣ�������ְ��������
private:
	string m_sex[10];  //�Ա�
	int m_num[10];  //���

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
	virtual void display();  //�����������

};

void enterInfo(string* name, int* age, int* numbers, string* sex, int* num)
{
	int i;
	char c;
	for (i = 0; i < 10; i++)
	{
		cout << "ְ��" << i + 1 << ":" << endl
			<< "   ����: ";
		cin >> name[i];
		cout << "   ����: ";
		cin >> age[i];
		cout << "   �Ա�: ";
		cin >> sex[i];
		cout << "   ���: ";
		cin >> num[i];
		getchar();  //���ջس���
		cout << "�Ƿ��������?(���������ַ��ûس�ֹͣ���� ���� ֱ���ûس���������....)";
		c = getchar();
		system("cls");  //����
		if (c != '\n')  // ���ǻس���ֹͣ������Ϣ
		{
			*numbers = i + 1;  //������ְ������=ѭ������
			break;
		}
	}
}

void printer(Form* ptr)  //����ʵ�ʶ���������ǵ�����
{
	ptr->display();
}

int main()
{
	cout << "--�γ����_������_ְ����Ϣ�����--" << endl;
	string name[10];  //����
	int age[10];  //����
	int numbers;  //��Ϣ�������ְ��������
	string sex[10];  //�Ա�
	int num[10];  //���


	//--������---
	//string name[10] = { "С��","С��","С��","С��","С��","С��","С��","С��","С��","С��" };
	//int age[10] = { 13,14,15,16,17,18,19,20,21,22 };
	//int numbers = 10;
	//string sex[10] = { "��","Ů","��", "��", "��", "��", "��", "��", "��", "Ů" };
	//int num[10] = { 100001,100002,100003,100004,100005,100006,100007,100008,100009,100010 };


	string* p_name = name, * p_sex = sex;
	int* p_age = age, * p_numbers = &numbers, * p_num = num;
	enterInfo(p_name, p_age, p_numbers, p_sex, p_num);  //����ְ����Ϣ

	Form* f;  //�����������Formָ��,������������
	EmployeeForm ef(p_name, p_age, p_numbers, p_sex, p_num);  //�������������
	EmployeeBriefForm ebf(&ef);  //�������������
	
	f = &ef;
	printer(f);  //����ְ����Ϣ���ຯ����Ա
	f = &ebf;
	printer(f);  //����ְ����Ϣ����ຯ����Ա
	return 0;
}

void EmployeeForm::display()
{
	int i;
	cout << "------------------------------------" << endl;
	cout << "             ְ����Ϣ��" << endl;
	cout << "------------------------------------" << endl;
	cout << setiosflags(ios::left) << setw(9) << "����" << resetiosflags(ios::left)  //����� �����п��Ϊ9
		<< setiosflags(ios::right) << setw(9) << "����" << setw(9) << "�Ա�"
		<< setw(9) << "���" << resetiosflags(ios::right) << endl;  //�Ҷ��� �����п��Ϊ9
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
	cout << "   ְ����Ϣ���" << endl;
	cout << "------------------" << endl;
	cout << setiosflags(ios::left) << setw(9) << "����" << resetiosflags(ios::left)
		<< setiosflags(ios::right) << setw(9) << "����" << resetiosflags(ios::right) << endl;
	cout << "------------------" << endl;
	for (i = 0; i < m_numbers; i++)
	{
		cout << setiosflags(ios::left) << setw(9) << m_name[i] << resetiosflags(ios::left)
			<< setiosflags(ios::right) << setw(9) << m_age[i] << resetiosflags(ios::right) << endl;
	}
	cout << "------------------" << endl;
}
