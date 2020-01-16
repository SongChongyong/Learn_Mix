#include<iostream>
using namespace std;

class Person {
public:
    ////传统方式初始化
    //Person(int a, int b, int c) {
    //	m_A = a;
    //	m_B = b;
    //	m_C = c;
    //}

    //初始化列表方式初始化
    // 语法： 构造函数()：属性1(值1),属性2（值2）... {}
    Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}

    void PrintPerson() {
        cout << "mA:" << m_A << endl;
        cout << "mB:" << m_B << endl;
        cout << "mC:" << m_C << endl;
    }
private:
    int m_A;
    int m_B;
    int m_C;
};

int main() {
    Person p(10, 20, 30);
    p.PrintPerson();

    return 0;
}
/*
mA:10
mB:20
mC:30
*/
