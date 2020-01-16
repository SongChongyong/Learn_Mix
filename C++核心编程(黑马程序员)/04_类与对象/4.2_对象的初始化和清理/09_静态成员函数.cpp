#include<iostream>
using namespace std;

class Person
{

public:

    //静态成员函数特点：
    //1 程序共享一个函数
    //2 静态成员函数只能访问静态成员变量
    
    static void func()
    {
        cout << "static func()调用" << endl;
        m_A = 100;
        //m_B = 100; //错误，不可以访问非静态成员变量，无法区分是哪个对象的m_B
    }

    static int m_A;    //静态成员变量
    int m_B;           //非静态成员变量
private:

    //静态成员函数也是有访问权限的
    static void func2()
    {
        cout << "static func2()调用" << endl;
    }
};

// 初始化静态成员变量m_A
int Person::m_A = 10;


void test01()
{
    //静态成员变量两种访问方式

    //1、通过对象
    Person p1;
    p1.func();

    //2、通过类名
    Person::func();

    //Person::func2(); //私有权限访问不到
}

int main() {
    test01();

    return 0;
}
/*
static func()调用
static func()调用
*/
