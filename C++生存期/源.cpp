#include<iostream>

using namespace std;
void fun();
void main()
{
    fun();
    fun();
}
void fun()
{
    static int a;
    int i = 5;
    a++;
    i++;
    cout << "i=" << i << ",a=" << a << endl;
}
