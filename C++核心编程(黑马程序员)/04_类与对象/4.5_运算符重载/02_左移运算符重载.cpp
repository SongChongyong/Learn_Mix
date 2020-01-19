#include<iostream>
using namespace std;


class Person {
    // 友元让一个全局函数访问类中私有成员
    friend ostream& operator<<(ostream& out, Person& p);

public:

    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

    // 成员函数实现不了左移运算符重载,  p.operator<<(cout) 或者 p << cout 不是我们想要的效果
    // 通常不会利用成元函数重载<<，因为无法实现cout在左侧
    // void operator<<(Person& p){
    // }

private:
    int m_A;
    int m_B;
};

// 只能利用全局函数实现左移运算符重载
// cout是"ostream"类型，标准输出流
// ostream对象只能有一个
ostream& operator<<(ostream& out, Person& p) {
    out << "m_A = " << p.m_A << " m_B = " << p.m_B;
    return out;
}

void test() {

    Person p1(10, 20);
    // 对"cout << p1"，开始编译器无法实现，这里通过左移运算符重载实现了
    // 本质上是 "operator << (cout, p1)"
    cout << p1 << endl << "hello world" << endl;       //链式编程
}

int main() {
    test();

    return 0;
}
/*
m_A = 10 m_B = 20
hello world
*/