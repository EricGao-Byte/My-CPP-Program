#include <iostream>
using namespace std;

class Student {
public:
    Student(string name, int age, float score);
    void show();
public:  //������̬��Ա����
    static int getTotal();
    static float getPoints();
private:
    static int m_total;  //������
    static float m_points;  //�ܳɼ�
private:
    string m_name;
    int m_age;
    float m_score;
};

//��̬��Ա��������ͨ��Ա�����ĸ����������ڣ���ͨ��Ա������ this ָ�룬���Է������е������Ա��
//����̬��Ա����û�� this ָ�룬ֻ�ܷ��ʾ�̬��Ա��������̬��Ա�����;�̬��Ա��������

//����������̬��Ա����
int Student::m_total = 0;
float Student::m_points = 0.0;

//���徲̬��Ա����
int Student::getTotal() {
    return m_total;
}
float Student::getPoints() {
    return m_points;
}
Student::Student(string name, int age, float score) : m_name(name), m_age(age), m_score(score) {
    m_total++;
    m_points += score;
}
void Student::show() {
    cout << m_name << "��������" << m_age << "���ɼ���" << m_score << endl;
}

int main() {
    (new Student("С��", 15, 90.6))->show();
    (new Student("����", 16, 80.5))->show();
    (new Student("�Ż�", 16, 99.0))->show();
    (new Student("����", 14, 60.8))->show();
    int total = Student::getTotal();
    float points = Student::getPoints();
    cout << "��ǰ����" << total << "��ѧ�����ܳɼ���" << points << "��ƽ������" << points / total << endl;
    return 0;
}
