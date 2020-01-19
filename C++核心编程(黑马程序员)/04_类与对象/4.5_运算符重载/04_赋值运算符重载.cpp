#include<iostream>
using namespace std;

class Person
{
public:

    Person(int age)
    {
        //将年龄数据开辟到堆区
        m_Age = new int(age);
    }

    //重载赋值运算符 
    Person& operator=(Person &p)
    {
        // 先判断是否有属性在堆区，如果有则先释放干净，然后再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        //编译器提供的代码是浅拷贝，发生重复释放堆区中m_Age的内存，程序崩溃
        //m_Age = p.m_Age;

        //提供深拷贝 解决浅拷贝的问题
        m_Age = new int(*p.m_Age);

        //返回自身
        return *this;
    }


    ~Person()
    {
        // 释放堆区内存，即前面new的m_Age的内存
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    //年龄的指针
    int *m_Age;
};


void test01()
{
    Person p1(18);

    Person p2(20);

    Person p3(30);

    p3 = p2 = p1; //赋值操作，可以实现连续赋值，则要求赋值运算符"="的返回值不能是void，而是*this

    cout << "p1的年龄为：" << *p1.m_Age << "  p1.m_Age的地址是："<< p1.m_Age<< endl;

    cout << "p2的年龄为：" << *p2.m_Age << "  p2.m_Age的地址是："<< p2.m_Age<< endl;

    cout << "p3的年龄为：" << *p3.m_Age << "  p3.m_Age的地址是："<< p3.m_Age<< endl;
}

int main() {
    test01();

    //int a = 10;
    //int b = 20;
    //int c = 30;

    //c = b = a;    // 可以实现连续赋值，则要求赋值运算符"="的返回值不应该是空
    //cout << "a = " << a << endl;    // 10
    //cout << "b = " << b << endl;    // 10
    //cout << "c = " << c << endl;    // 10


    return 0;
}
/*
p1的年龄为：18  p1.m_Age的地址是：0xaccc20
p2的年龄为：18  p2.m_Age的地址是：0xaccc40
p3的年龄为：18  p3.m_Age的地址是：0xaccc60
*/
