#include<iostream>
using namespace std;

/* 函数重载的满足条件：
    1. 需要函数都在同一个作用域下
    2. 函数名称相同
    3. 函数参数类型不同，或者参数个数不同，或者顺序不同
*/

void func()
{
    cout << "func 的调用！" << endl;
}

void func(int a)
{
    cout << "func (int a) 的调用！" << endl;
}

void func(double a)
{
    cout << "func (double a)的调用！" << endl;
}

void func(int a , double b)
{
    cout << "func (int a ,double b) 的调用！" << endl;
}

void func(double a , int b)
{
    cout << "func (double a ,int b)的调用！" << endl;
}

//函数返回值不可以作为函数重载条件,如void fun()和int func()仅仅返回类型不同，不可作为函数重载
//int func(double a, int b)
//{
//	cout << "func (double a , int b)的调用！" << endl; 
//}

int main() {

    func();              // func 的调用！
    func(10);            // func (int a) 的调用！
    func(3.14);          // func (double a)的调用！
    func(10, 3.14);      // func (int a ,double b) 的调用！
    func(3.14 , 10);     // func (double a ,int b)的调用！

    return 0;
}

