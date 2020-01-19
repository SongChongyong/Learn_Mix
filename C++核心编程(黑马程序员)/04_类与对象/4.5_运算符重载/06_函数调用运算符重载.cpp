#include<iostream>
#include<string>
using namespace std;

// 函数调用重载(仿函数)

// 打印输出类
class MyPrint
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }

};

void test01()
{
    //重载的（）操作符,使用起来非常类似于函数调用，也称为仿函数
    MyPrint myFunc;
    myFunc("hello world");
}

// 仿函数非常灵活，没有固定写法
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

void test02()
{
    MyAdd add;
    int ret = add(10, 10);
    cout << "ret = " << ret << endl;

    //匿名对象调用，"Myadd()"表示创建匿名对象  
    cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main() {
    test01();
    test02();

    return 0;
}
/*
hello world
ret = 20
MyAdd()(100,100) = 200
*/