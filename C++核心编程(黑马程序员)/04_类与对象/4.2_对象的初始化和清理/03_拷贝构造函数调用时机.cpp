#include<iostream>
using namespace std;

class Person {
public:
    Person() {
        cout << "无参构造函数!" << endl;
        mAge = 0;
    }
    Person(int age) {
        cout << "有参构造函数!" << endl;
        mAge = age;
    }
    Person(const Person &p) {
        cout << "拷贝构造函数!" << endl;
        mAge = p.mAge;
    }
    //析构函数在释放内存之前调用
    ~Person() {
        cout << "析构函数!" << endl;
    }
public:
    int mAge;
};

//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test01() {

    Person man(20);         //p对象已经创建完毕
    Person newman(man);     //调用拷贝构造函数
    Person newman2 = man;   //拷贝构造

    //Person newman3;
    //newman3 = man;       //不是调用拷贝构造函数，赋值操作
}

//2. 值传递的方式给函数参数传值
//相当于Person p1 = p;
void doWork(Person p1) {}
void test02() {
    Person p;                //无参构造函数
    doWork(p);
}

//3. 以值方式返回局部对象
Person doWork2()
{
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
}

void test03()
{
    Person p = doWork2();
    cout << (int *)&p << endl;
}


int main() {

    //test01();
    //test02();
    test03();

    return 0;
}

/*
当main函数中调用test01()时，运行结果：
有参构造函数!
拷贝构造函数!
拷贝构造函数!
析构函数!
析构函数!
析构函数!

当main函数中调用test02()时，运行结果：
无参构造函数!
拷贝构造函数!
析构函数!
析构函数!

当main函数中调用test03()时，运行结果(这里编译器不同，结果可能不同，这是g++5.5编译结果)：
无参构造函数!
0x7ffd4091c4e4
0x7ffd4091c4e4
析构函数!

对于test03()，使用拷贝构造函数实现值方式返回局部对象，老师运行结果：
无参构造函数!
0x7ffd4091c4e4
拷贝构造函数!
析构函数!
0x7ffd4091c4...    -- 一个不同的地址
析构函数!
*/
