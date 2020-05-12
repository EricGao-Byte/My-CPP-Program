#include <iostream>
using namespace std;

class Student {
public:
    Student(string name, int age, float score);
    void show();
public:
    static int m_total;  //静态成员变量
private:                    //在C++中，我们可以使用静态成员变量来实现多个对象共享数据的目标。
    char* m_name;
    int m_age;
    float m_score;
};

int Student::m_total = 0;//静态变量必须在类外初始化

//static 成员变量既可以通过对象来访问，也可以通过类来访问。

int main()
{
    //通过类类访问 static 成员变量
    Student::m_total = 10;
    //通过对象来访问 static 成员变量
    Student stu("小明", 15, 92.5f);
    stu.m_total = 20;
    //通过对象指针来访问 static 成员变量
    Student* pstu = new Student("李华", 16, 96);
    pstu->m_total = 20;
    return 0;
}