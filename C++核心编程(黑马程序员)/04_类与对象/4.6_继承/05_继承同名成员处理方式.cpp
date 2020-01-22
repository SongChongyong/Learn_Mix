#include<iostream>
using namespace std;

class Base {
public:
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base - func()调用" << endl;
    }
    
    // 注意函数重载
    void func(int a)
    {
        cout << "Base - func(int a)调用" << endl;
    }

public:
    int m_A;
};


class Son : public Base {
public:
    Son()
    {
        m_A = 200;
    }

    //当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
    //如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
    void func()
    {
        cout << "Son - func()调用" << endl;
    }
public:
    int m_A;
};

void test01()
{
    Son s;

    cout << "Son下的m_A = " << s.m_A << endl;
    // 如果通过子类对象，访问到父类中同名成员，需要加作用域
    cout << "Base下的m_A = " << s.Base::m_A << endl;
    
    // 子类与父类拥有同名的成员函数测试
    s.func();
    s.Base::func();
    s.Base::func(10);

}
int main() {
    test01();
    
    return 0;
    // return EXIT_SUCCESS;
}
/*
Son下的m_A = 200
Base下的m_A = 100
Son - func()调用
Base - func()调用
Base - func(int a)调用
*/