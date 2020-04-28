#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
private:
	string num, name, faddr, email, tel;//学号，名字，住址，邮箱,电话
	string sex;//性别：f 女  m 男
	int math, physics, eng, prog;//成绩：数学，物理，外语，程序设计
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
	stu.SetName("张三");
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
	cout << "姓名" <<setw(12) << name << endl;
	cout << "学号" <<setw(12) <<num<<endl;
	cout << "性别" <<setw(12) <<sex<<endl;
	cout << "住址" <<setw(12) <<faddr<<endl;
	cout << "电话" <<setw(12) <<tel<<endl;
	cout << "邮箱" << setw(12) << email << endl << endl;
	cout << "科目" << setw(12) << "数学" << setw(12) << "物理" << setw(12) << "外语" << setw(12) << "编程" << endl;
	cout << "成绩" << setw(12) << math << setw(12) << physics << setw(12) << eng << setw(12) << prog << endl;
}
