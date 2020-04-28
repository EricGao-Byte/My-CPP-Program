#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
private:
	string num, name, faddr, email, tel;//ѧ�ţ����֣�סַ������,�绰
	string sex;//�Ա�f Ů  m ��
	int math, physics, eng, prog;//�ɼ�����ѧ����������������
public:
	void SetNum(string n);
	void SetName(string na);
	void SetSex(string s);
	void SetFaddr(string f);
	void SetTel(string t);
	void SetEmail(string e);
	void SetScore(char tag, int score);
	void PrintStudent();
};

int main()
{
	Student stu;
	stu.SetNum("3180811020");
	stu.SetName("����");
	stu.SetSex("f");
	stu.SetFaddr("Xi'an");
	stu.SetTel("10086");
	stu.SetEmail("10086@qq.com");
	stu.SetScore('m', 59);
	stu.SetScore('p', 59);
	stu.SetScore('e', 59);
	stu.SetScore('c', 59);
	stu.PrintStudent();
	return 0;	 
}

void Student::SetNum(string n)
{
	num = n;
}

void Student::SetName(string na)
{
	name = na;
}

void Student::SetSex(string s)
{
	sex = s;
}

void Student::SetFaddr(string f)
{
	faddr = f;
}

void Student::SetTel(string t)
{
	tel = t;
}

void Student::SetEmail(string e)
{
	email = e;
}

void Student::SetScore(char tag, int score)
{
	if (tag == 'm')
		math = score;
	else if (tag == 'p')
		physics = score;
	else if (tag == 'e')
		eng = score;
	else
		prog = score;
}

void Student::PrintStudent()
{
	cout << "����" <<setw(12) << name << endl;
	cout << "ѧ��" <<setw(12) <<num<<endl;
	cout << "�Ա�" <<setw(12) <<sex<<endl;
	cout << "סַ" <<setw(12) <<faddr<<endl;
	cout << "�绰" <<setw(12) <<tel<<endl;
	cout << "����" << setw(12) << email << endl << endl;
	cout << "��Ŀ" << setw(12) << "��ѧ" << setw(12) << "����" << setw(12) << "����" << setw(12) << "���" << endl;
	cout << "�ɼ�" << setw(12) << math << setw(12) << physics << setw(12) << eng << setw(12) << prog << endl;
}
