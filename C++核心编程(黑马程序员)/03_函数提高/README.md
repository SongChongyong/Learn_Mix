## 3 函数提高

### 3.1 函数默认参数

在C++中，函数的形参列表中的形参是可以有默认值的。

语法： ` 返回值类型  函数名 （参数= 默认值）{}` 

**如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值。**



**示例：**

```C++
// 1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
int func(int a, int b = 10, int c = 10) {
    return a + b + c;
}

int main() 
{
    cout << "ret = " << func(20, 20) << endl;    // ret = 50
    cout << "ret = " << func(100) << endl;       // ret = 120

    return 0;
}

```



**函数声明和函数定义时只能有一个有默认参数，如果函数声明有默认值，函数实现的时候就不能有默认参数。**

```c++
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数

int func2(int a = 10, int b = 10); 
int func2(int a, int b) {
    return a + b;
}
```





### 3.2 函数占位参数

C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置

**语法：** `返回值类型 函数名 (数据类型){}` 

在现阶段函数的占位参数存在意义不大，但是后面的课程中会用到该技术

**示例：**

```C++
//函数占位参数 ，占位参数也可以有默认参数
void func(int a, int) {
    cout << "this is func" << endl;
}

int main() {
    func(10,10); //占位参数必须填补

    return 0;
}
```



### 3.3 函数重载

#### 3.3.1 函数重载概述

**作用：**函数名可以相同，提高复用性

**函数重载满足条件：**

* 同一个作用域下
* 函数名称相同
* 函数参数**类型不同**  或者 **个数不同** 或者 **顺序不同**

**注意:**  函数的返回值不可以作为函数重载的条件

**示例：**

```C++
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

//函数返回值不可以作为函数重载条件, 如void fun()和int func()仅仅返回类型不同，不可作为函数重载
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
```

(代码见: [02_函数重载.cpp](./02_函数重载.cpp))



#### 3.3.2 函数重载注意事项

* 引用作为重载条件
* 函数重载碰到函数默认参数

**示例：**

```C++
#include<iostream>
using namespace std;

//函数重载注意事项
//1、引用作为重载条件

void func(int &a)
{
    cout << "func (int &a) 调用 " << endl;
}

void func(const int &a)
{
    cout << "func (const int &a) 调用 " << endl;
}

//2、函数重载碰到函数默认参数

void func2(int a, int b = 10)
{
    cout << "func2(int a, int b = 10) 调用" << endl;
}

void func2(int a)
{
    cout << "func2(int a) 调用" << endl;
}

int main() {
    
    int a = 10;
    func(a);       //调用无const
    func(10);      //调用有const

    //func2(10);     //碰到默认参数产生歧义，需要避免

    return 0;
}
/*
func (int &a) 调用 
func (const int &a) 调用 
*/
```

(代码见: [03_函数重载 注意事项.cpp](./03_函数重载 注意事项.cpp))