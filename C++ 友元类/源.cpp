#include <iostream>
using namespace std;
//�� B ����Ϊ�� A ����Ԫ�࣬��ô�� B �е����г�Ա���������� A ����Ԫ���������Է����� A �����г�Ա��
//���� public��protected��private ���Եġ�

//��Ԫ�Ĺ�ϵ�ǵ���Ķ�����˫��ġ������������ B ���� A ����Ԫ�࣬
//�������� A ���� B ����Ԫ�࣬�� A �еĳ�Ա�������ܷ����� B �е� private ��Ա��

//��Ԫ�Ĺ�ϵ���ܴ��ݡ������ B ���� A ����Ԫ�࣬�� C ���� B ����Ԫ�࣬�������� C ���� A ����Ԫ�ࡣ

class Address;  //��ǰ����Address��
//����Student��
class Student {
public:
    Student(string name, int age, float score);
public:
    void show(Address* addr);
private:
    string m_name;
    int m_age;
    float m_score;
};


//����Address��
class Address {
public:
    Address(string province, string city, string district);
public:
    //��Student������ΪAddress�����Ԫ��
    friend class Student;
private:
    string m_province;  //ʡ��
    string m_city;  //����
    string m_district;  //����������
};


//ʵ��Student��
Student::Student(string name, int age, float score) : m_name(name), m_age(age), m_score(score) { }
void Student::show(Address* addr) {
    cout << m_name << "�������� " << m_age << "���ɼ��� " << m_score << endl;
    cout << "��ͥסַ��" << addr->m_province << "ʡ" << addr->m_city << "��" << addr->m_district << "��" << endl;
}


//ʵ��Address��
Address::Address(string province, string city, string district) {
    m_province = province;
    m_city = city;
    m_district = district;
}


int main() {
    Student stu("С��", 16, 95.5f);
    Address addr("����", "����", "����");
    stu.show(&addr);

    Student* pstu = new Student("����", 16, 80.5);
    Address* paddr = new Address("�ӱ�", "��ˮ", "�ҳ�");
    pstu->show(paddr);
    return 0;
}