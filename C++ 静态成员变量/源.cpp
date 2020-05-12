#include <iostream>
using namespace std;

class Student {
public:
    Student(string name, int age, float score);
    void show();
public:
    static int m_total;  //��̬��Ա����
private:                    //��C++�У����ǿ���ʹ�þ�̬��Ա������ʵ�ֶ�����������ݵ�Ŀ�ꡣ
    char* m_name;
    int m_age;
    float m_score;
};

int Student::m_total = 0;//��̬���������������ʼ��

//static ��Ա�����ȿ���ͨ�����������ʣ�Ҳ����ͨ���������ʡ�

int main()
{
    //ͨ��������� static ��Ա����
    Student::m_total = 10;
    //ͨ������������ static ��Ա����
    Student stu("С��", 15, 92.5f);
    stu.m_total = 20;
    //ͨ������ָ�������� static ��Ա����
    Student* pstu = new Student("�", 16, 96);
    pstu->m_total = 20;
    return 0;
}