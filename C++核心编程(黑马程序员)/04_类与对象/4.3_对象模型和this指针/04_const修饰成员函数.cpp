#include<iostream>
using namespace std;

class Person {
public:
    Person() {
        m_A = 0;
        m_B = 0;
    }

    //this指针的本质是一个指针常量，指针的指向不可修改
    //如果想让指针指向的值也不可以修改，需要声明常函数，在成员函数后加const
    void ShowPerson() const {
        //const Type* const pointer;
        //this = NULL;       //不能修改指针的指向，this指针的本质是一个指针常量， Person* const this;
        //this->mA = 100;    //但是this指针指向的对象的数据是可以修改的，这里用ShowPerson() const让值也不能改

        //const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
        this->m_B = 100;
    }

    // 常函数
    void MyFunc() const {
        //mA = 10000;
        cout<<"调用常函数MyFunc()"<<endl;
    }
    
    // 普通函数
    void MyFunc2() {
        cout<<"调用普通函数MyFunc2()"<<endl;
    }

public:
    int m_A;
    mutable int m_B; //可修改 可变的
};


//const修饰对象  常对象
void test01() {

    const Person person;        //常量对象  
    cout << "person.m_A = " << person.m_A << endl;
    //person.mA = 100;          //常对象不能修改成员变量的值,但是可以访问
    person.m_B = 200;           //但是常对象可以修改mutable修饰成员变量
    cout << "修改mutable修饰成员变量,person.m_B = " << person.m_B << endl;


    //常对象只能调用常函数，不能调用普通函数
    person.MyFunc();             //常对象只能调用常函数
    // person.MyFunc2();         //常对象不能调用普通成员函数

}

int main() {
    test01();

    return 0;
}
/*
person.m_A = 0
修改mutable修饰成员变量,person.m_B = 200
调用常函数MyFunc()
*/