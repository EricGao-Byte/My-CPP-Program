#include <iostream>
using namespace std;
class Student {
public:
    void setname(string name);
    void setage(int age);
    void setscore(float score);
    void show();
private:
    string name;
    int age;
    float score;
};

void Student::setname(string name) {
    this->name = name;//this ֻ����������ڲ���ͨ�� this ���Է���������г�Ա������ private��protected��public ���Եġ�
}                       //this �� const ָ�룬����ֵ�ǲ��ܱ��޸ĵģ�һ����ͼ�޸ĸ�ָ��Ĳ������縳ֵ���������ݼ��ȶ��ǲ�����ġ�
void Student::setage(int age) {//this ʵ�����ǳ�Ա������һ���βΣ��ڵ��ó�Ա����ʱ������ĵ�ַ��Ϊʵ�δ��ݸ� this������ this ����β�����ʽ�ģ������������ڴ����У������ڱ���׶��ɱ�����ĬĬ�ؽ�����ӵ������б��С�

    //this ��Ϊ��ʽ�βΣ��������ǳ�Ա�����ľֲ�����������ֻ�����ڳ�Ա�������ڲ�������ֻ����ͨ��������ó�Ա����ʱ�Ÿ� this ��ֵ��
    this->age = age;
}
void Student::setscore(float score) {
    this->score = score;
}
void Student::show() {
    cout << this->name << "��������" << this->age << "���ɼ���" << this->score << endl;
}

int main()
{
    Student* p_stu = new Student;
    p_stu->setage(21);
    p_stu->setname("�");
    p_stu->setscore(99);
    p_stu->show();
    return 0;
}