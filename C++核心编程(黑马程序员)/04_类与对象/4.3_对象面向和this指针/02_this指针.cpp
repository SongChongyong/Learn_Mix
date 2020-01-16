#include<iostream>
using namespace std;

class Person
{
public:

    Person(int age)
    {
        //1. 当形参和成员变量同名时，可用this指针来区分，解决名称冲突
        // this指针指向被调用的成员函数所属的对象
        this->age = age;  // 这里如果直接写"age = age", 命名冲突，也可以定义成员变量为m_age，用不同名字区分
    }

    Person& PersonAddPerson(Person p)
    {
        this->age += p.age;
        //2. 返回对象本身，用*this
        return *this;
    }

    int age;
};

void test01()
{
    Person p1(6);     // 创建p1类，构造函数Person中this->age = age表示：this指向p1,即p1->age
    cout << "p1.age = " << p1.age << endl;

    Person p2(10);
    // 调用PersonAddPerson函数中"this->age += p.age"表示this指向对象p2, p2->age += p1.age
    // "return *this"表示返回对象本身，即返回p2
    p2.PersonAddPerson(p1);   
    cout << "p2.age = " << p2.age << endl;
}

int main() {
    test01();

    return 0;
}
/*
p1.age = 6
p2.age = 16
*/