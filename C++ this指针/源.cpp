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
    this->name = name;//this 只能用在类的内部，通过 this 可以访问类的所有成员，包括 private、protected、public 属性的。
}                       //this 是 const 指针，它的值是不能被修改的，一切企图修改该指针的操作，如赋值、递增、递减等都是不允许的。
void Student::setage(int age) {//this 实际上是成员函数的一个形参，在调用成员函数时将对象的地址作为实参传递给 this。不过 this 这个形参是隐式的，它并不出现在代码中，而是在编译阶段由编译器默默地将它添加到参数列表中。

    //this 作为隐式形参，本质上是成员函数的局部变量，所以只能用在成员函数的内部，并且只有在通过对象调用成员函数时才给 this 赋值。
    this->age = age;
}
void Student::setscore(float score) {
    this->score = score;
}
void Student::show() {
    cout << this->name << "的年龄是" << this->age << "，成绩是" << this->score << endl;
}

int main()
{
    Student* p_stu = new Student;
    p_stu->setage(21);
    p_stu->setname("李华");
    p_stu->setscore(99);
    p_stu->show();
    return 0;
}