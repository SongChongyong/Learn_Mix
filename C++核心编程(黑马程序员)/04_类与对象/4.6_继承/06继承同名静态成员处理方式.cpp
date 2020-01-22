#include<iostream>
using namespace std;

class Base {
public:
    // 静态函数定义
    static void func()
    {
        cout << "Base - static void func()" << endl;
    }
    static void func(int a)
    {
        cout << "Base - static void func(int a)" << endl;
    }

    static int m_A; // 静态成员定义--类内
};

// 静态成员初始化--类外
int Base::m_A = 100;

class Son : public Base {
public:
    // 静态函数定义
    static void func()
    {
        cout << "Son - static void func()" << endl;
    }
    static int m_A;   // 静态成员定义，这个子类的成员与父类同名
};

int Son::m_A = 200;

//同名成员属性
void test01()
{
    // 1.通过对象访问
    cout << "通过对象访问： " << endl;
    Son s;
    cout << "Son  下 m_A = " << s.m_A << endl;
    cout << "Base 下 m_A = " << s.Base::m_A << endl;

    // 2.通过类名访问
    cout << "通过类名访问： " << endl;
    cout << "Son  下 m_A = " << Son::m_A << endl;
    // 第一个::代表通过类名方式访问，第二个::代表访问父类作用域下
    cout << "Base 下 m_A = " << Son::Base::m_A << endl;  
}

//同名成员函数
void test02()
{
    // 1.通过对象访问
    cout << "通过对象访问： " << endl;
    Son s;
    s.func();
    s.Base::func();
    
    // 2.通过类名访问
    cout << "通过类名访问： " << endl;
    Son::func();
    Son::Base::func();
    // 出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
    // 第一个::代表通过类名方式访问，第二个::代表访问父类作用域下
    Son::Base::func(100);
}
int main() {

    test01();
    test02();


    return 0;
}

/*
通过对象访问： 
Son  下 m_A = 200
Base 下 m_A = 100
通过类名访问： 
Son  下 m_A = 200
Base 下 m_A = 100
通过对象访问： 
Son - static void func()
Base - static void func()
通过类名访问： 
Son - static void func()
Base - static void func()
Base - static void func(int a)
*/
