#include<iostream>
#include<string>
using namespace std;

class Animal {
public:

    Animal()
    {
        cout << "Animal 构造函数调用！" << endl;
    }
    // 纯虚函数
    virtual void Speak() = 0;

    // // 方法一：析构函数加上virtual关键字，变成虚析构函数，解决父类指针释放子类对象时不干净的问题
    // virtual ~Animal()
    // {
    // 	cout << "Animal虚析构函数调用！" << endl;
    // }

    // 方法二：纯虚析构函数，需要申明也需要实现
    // 有了纯虚析构，该类属于抽象类，无法实例化对象
    virtual ~Animal() = 0;
};

// 方法二用纯虚析构函数，需要具体函数实现
Animal::~Animal()
{
    cout << "Animal 纯虚析构函数调用！" << endl;
}

//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。

class Cat : public Animal {
public:
    // 构造函数
    Cat(string name)
    {
        cout << "Cat构造函数调用！" << endl;
        m_Name = new string(name);
    }
    virtual void Speak()
    {
        cout << *m_Name <<  "小猫在说话!" << endl;
    }

    // 析构函数
    ~Cat()
    {
        cout << "Cat析构函数调用!" << endl;
        if (this->m_Name != NULL) {
            delete m_Name;
            m_Name = NULL;
        }
    }

public:
    string *m_Name;
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->Speak();

    //通过父类指针去释放，不会调用子类中析构函数，会导致子类对象可能清理不干净，造成内存泄漏
    //怎么解决？给基类增加一个虚析构函数
    //虚析构函数就是用来解决通过父类指针释放子类对象
    delete animal;
}

int main() {
    test01();

    return 0;
}

/*
Animal 构造函数调用！
Cat构造函数调用！
Tom小猫在说话!
Cat析构函数调用!
Animal 纯虚析构函数调用！
*/