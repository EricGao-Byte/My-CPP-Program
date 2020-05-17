#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

class Person
{
private:
	char sex_;
	char num_[20], name_[20], addr_[50], tel_[20], email_[20];
public:
	void SetNum(const char*);
	void SetName(const char*);
	void SetSex(char);
	void SetAddr(const char*);
	void SetTel(const char*);
	void SetEmail(const char*);
	void PrintPerson();
};

class Student :public Person
{
private:
	int math_, physic_, eng_, prog_;
public:
	void SetScore(char, int);
	void PrintStudent();
};

class Teacher :public Person
{
private:
	char headship_[20], post_[20];
	int salary_;
public:
	void SetHeadship(const char*);
	void SetPost(const char*);
	void SetSalary(int);
	void PrintTeacher();
};

int main()
{
	Student student;
	student.SetNum("3180811020");
	student.SetName("Gaochuanjin");
	student.SetSex('m');
	student.SetAddr("Shanxi,Xi'an");
	student.SetTel("10086");
	student.SetEmail("2265351510@qq.com");
	student.SetScore('m', 90);
	student.SetScore('p', 90);
	student.SetScore('e', 90);
	student.SetScore('c', 90);
	student.PrintStudent();

	Teacher teacher;
	teacher.SetNum("1234567");
	teacher.SetName("Teacher");
	teacher.SetSex('m');
	teacher.SetAddr("Shanxi,Xi'an");
	teacher.SetTel("10086");
	teacher.SetEmail("teacher@qq.com");
	teacher.SetHeadship("headmaster");
	teacher.SetPost("good teacher");
	teacher.SetSalary(10000);
	teacher.PrintTeacher();
	return 0;
}

void Person::SetNum(const char* num)
{
	strcpy(num_, num);
}

void Person::SetName(const char* name)
{
	strcpy(name_, name);
}

void Person::SetSex(char sex)
{
	sex_ = sex;
}

void Person::SetAddr(const char* addr)
{
	strcpy(addr_, addr);
}

void Person::SetTel(const char* tel)
{
	strcpy(tel_, tel);
}

void Person::SetEmail(const char* email)
{
	strcpy(email_, email);
}

void Person::PrintPerson()
{
	cout << "Num: " << num_ << endl
		<< "Name: " << name_ << endl
		<< "Sex: " << sex_ << endl
		<< "Addr: " << addr_ << endl
		<< "Tel: " << tel_ << endl
		<< "Email: " << email_ << endl;
}


void Student::SetScore(char tag, int score)
{
	if (tag == 'm')
	{
		math_ = score;
	}
	else if (tag == 'p')
	{
		physic_ = score;
	}
	else if (tag == 'e')
	{
		eng_ = score;
	}
	else if(tag == 'c')
	{
		prog_ = score;
	}
	else
	{
		cout << "error input!" << endl;
	}
}

void Student::PrintStudent()
{
	cout << "   class Student:" << endl;
	PrintPerson();
	cout << "Math score: " << math_ << endl
		<< "Physic score: " << physic_ << endl
		<< "Eng score: " << eng_ << endl
		<< "Prog score: " << prog_ << endl;
}



void Teacher::SetHeadship(const char* headship)
{
	strcpy(headship_, headship);
}

void Teacher::SetPost(const char* post)
{
	strcpy(post_, post);
}

void Teacher::SetSalary(int salary)
{
	salary_ = salary;
}

void Teacher::PrintTeacher()
{
	cout << "   class Teacher:" << endl;
	PrintPerson();
	cout << "Headship: " << headship_ << endl
		<< "Post: " << post_ << endl
		<< "Salary: " << salary_ << endl;
}
