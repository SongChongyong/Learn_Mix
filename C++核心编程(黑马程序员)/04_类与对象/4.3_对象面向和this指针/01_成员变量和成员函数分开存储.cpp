#include<iostream>
using namespace std;

// 在C++中，类内的成员变量和成员函数分开存储
// 只有非静态成员变量才属于类的对象上，占用空间
// C++编译器会给每个对象也分配一个字节空间，为了区分空对象占内存的位置，所以空对象的内存大小为1字节
// 每个空对象也有一个独一无二的内存地址

class Person {
public:
    Person() {
        mA = 0;
    }
    //非静态成员变量占对象空间
    int mA;
    //静态成员变量不占对象空间
    static int mB; 
    //函数也不占对象空间，所有函数共享一个函数实例
    void func() {
        cout << "mA:" << this->mA << endl;
    }
    //静态成员函数也不占对象空间
    static void sfunc() {
    }
};
class Book {
    // 空对象
};

int main() {
    cout << "空类Book占用内存为："<<sizeof(Book) << endl;
    cout << "有一个非静态变量，同时有静态成员、静态成员函数、普通函数的Person类占用内存为："<< sizeof(Person) << endl;

    return 0;
}
/*
空类Book占用内存为：1
有一个非静态变量，同时有静态成员、静态成员函数、普通函数的Person类占用内存为：4
*/
