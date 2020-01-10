

# C++语言程序设计

这是学习学堂在线郑莉老师的"C++语言程序设计"课程的学习笔记，才开始接触计算机，笔记仅仅是个人学习的记录。

- **01 绪论**

    这章简单介绍了面向对象的由来和主要的基本概念，没有特别笔记，可以参考[学堂在线讲义第1章.md](https://github.com/xuetangx-cpp/main/blob/master/handout/第1章.md)

- **02 C++简单程序设计**

    由于有C语言的基础，这部分笔记只记录C语言没有或者与C语言不同的地方，而且都是简单的程序设计，笔记直接记录在此README文件中。

- **03 函数**

    C++继承了C语言的全部语法，也包括函数的定义与使用，这部分与C语言差不多，不记特别笔记，笔记直接记录在此README文件中。。

- [04 类与对象](./04_类与对象)











-----

# 02 C++简单程序设计

由于有C语言的基础，这部分笔记只记录C语言没有或者与C语言不同的地方，而且都是简单的程序设计。



## 2.1 C++语言概述

C++是从C语言发展演变而来。C++中引入了类的机制，支持面向对象的程序设计。

### 2.1.3 C++程序实例

```c++
#include<iostream>   
using namespace std;   // 使用std命名空间

int main()
{
    cout<<"Hello!"<<endl;
    cout<<"Welcome to C++!"<<endl;
    
    return 0;
}

/*
Hello!
Welcome to C++!
*/
```

(详细代码见: [2_1_Hello.cpp](./2_1_Hello.cpp))

在Linux环境下编译链接使用`g++ 2_1_Hello.cpp -o 2_1_Hello`或`gcc 2_1_Hello.cpp -lstdc++ -o 2_1_Hello` (编译运行中出现错误可以参考[ubuntu下 GCC编译程序出现 undefined reference to`std::ios_base::Init::Init()'问题](https://www.cnblogs.com/chinazhangjie/archive/2011/05/23/2054598.html))



## 2.2 基础数据类型和表达式

这部分与C语言差不多，不记特别笔记。



## 2.3 数据的输入与输出

### 2.3.1 I/O流

在C++中，将数据从一个对象到另一个对象的流动抽象为"流"。流在使用前要被建立，使用后要被删除。

数据的输入与输出是通过I/O流来实现的：

- `cin`: 用来处理标准输入，即键盘输入。
- `cout`: 用来处理标准输出，即屏幕输出。



### 2.3.2 预定义的 插入符<< 和 提取符>>

- **"<<"是预定义的插入符**，作用在cout上实现一般的屏幕输出：

     `cout<<表达式1<<表达式2<<...`



- **">>"提取符**，最一般的键盘输入是将提取符作用在流类对象cin上:

    `cin>>表达式1>>表达式2>>...`

    

    如：

    ```c++
    int a, b;
    cin>>a>>b;    // 要求从键盘输入两个int型数，两数之间以空格分隔
    ```

    

### 2.3.3 简单的I/O控制

使用cin和cout进行数据的输入和输出时，经常需要设置特殊的格式，详细的见第11章。

这里只列出常见的I/O流类库操纵符(要使用操纵符，首先必须在源程序的开头包含iomanip头文件)：

|      操纵符名      |               含义               |
| :----------------: | :------------------------------: |
|        dec         |      数值数据采用十进制表示      |
|        hex         |     数值数据采用十六进制表示     |
|        oct         |      数值数据采用八进制表示      |
|         ws         |            提取空白符            |
|      **endl**      |     **插入换行符，并刷新流**     |
|        ends        |            插入空字符            |
| setsprecision(int) | 设置浮点数的小数位数(包括小数点) |
|     setw(int)      |             设置域宽             |



```c++
cout<<setw(5)<<setprecision(3)<<3.14157<<endl;   // 设置输出域宽为5个字符，小数点后保留两位
/* 3.14*/
```



## 2.4 算法的基本控制结构

**顺序结构、选择结构、循环结构**三种基本控制结构与C语言差不多，不记特别笔记。



## 2.5 自定义数据类型

**typedef声明、枚举类型enum**与C语言差不多，不记特别笔记。



# 03 函数

C++继承了C语言的全部语法，也包括函数的定义与使用，这部分与C语言差不多，不记特别笔记。

## 3.2 内联函数

对于一些功能简单、规模较小又频繁使用的函数，可以设计为**内联函数**。**内联函数不是在函数调用时发生控制转移，而是在编译时将函数体嵌入在每一个调用处。**这样节省了参数传递、控制转移等开销。

```c++
// 内联函数的定义使用关键字inline，其他跟函数定义一致
inline 类型说明符 函数名(含类型说明的形参表)
{
    语句序列;
}
```

注意：

- 内联函数体内不能有循环语句和switch语句

- 内联函数的定义必须出现在内联函数第一次调用之前

- 对内联函数不能进行异常接口声明

- 编译器可能自动定义简单函数为inline函数，同时也可能将定义的inline函数判断为不是inline函数，作普通函数处理

    

    ```c++
    #include<iostream>
    using namespace std;
    
    const double PI = 3.14159265358979;
    
    //内联函数，根据圆的半径计算其面积
    inline double calArea(double radius){
        return PI*radius*radius;
    }
    
    int main()
    {
        double r=3.0;    // r是圆的半径
        // 调用内联函数求圆的面积，编译时此处被替换为calArea()函数体语句
        double area = calArea(r);
        cout << area << endl;    
        return 0;
    }
    /*
    28.2743
    */
    ```

    (代码见: [3_14.cpp](./3_14.cpp))



## 3.4 函数重载

**函数重载：两个以上的函数，具有相同的函数名，但是形参的个数或者类型不同，编译器根据实参和形参的类型及个数的最佳匹配，自动确定调用哪一个函数。

```c++
#include<iostream>
using namespace std;

/* 函数重载实例 */

/* 求两个整数的平方和 */
int sumOfSquare(int a, int b){
    return a*a + b*b;
}

/* 求两个实数的平方和 */
double sumOfSquare(double a, double b){
    return a*a + b*b;
}

int main(){
    int m, n;
    cout << "Enter two integer: ";
    cin >> m >> n;
    // 读入的m,n类型是int，编译器自动定位sumOfSquare()函数为求两个整数的平方和的函数
    cout << "Their sum of square: " << sumOfSquare(m, n) <<endl;

    double x, y;
    cout << "Enter two real number: ";
    cin >> x >> y;
    // 读入的m,n类型是double，编译器自动定位sumOfSquare()函数为求两个实数的平方和的函数
   cout << "Their sum of square: " << sumOfSquare(x, y) << endl;

    return 0; 
}

/*
Enter two integer: 3 4
Their sum of square: 25
Enter two real number: 3.0 4.0
Their sum of square: 25

Enter two integer: 3 4
Their sum of square: 25
Enter two real number: 3.0 4.1
Their sum of square: 25.81
*/

```

(代码见: [3_16.cpp](./3_16.cpp))



## 3.5 C++系统函数

C++不仅允许用户自定义函数，同时C++的系统库中提供了几百个函数可以直接调用。在调用时，必须先用include指令嵌入相应的头文件。如要使用数学函数，先`#include<cmath>`，后面就可以调用"sin"等函数。

查阅各种常用的标准C++函数的原型、头文件、和用法网站：https://cppreference.com/







-----

## 参考资料

1.  学堂在线课程：[C++语言程序设计基础](https://next.xuetangx.com/course/THU08091000247/1075271)
2.  学堂在线课程：[C++语言程序设计进阶](https://next.xuetangx.com/course/THU08091000248/1075378)
3.  [ubuntu下 GCC编译程序出现 undefined reference to`std::ios_base::Init::Init()'问题](https://www.cnblogs.com/chinazhangjie/archive/2011/05/23/2054598.html)