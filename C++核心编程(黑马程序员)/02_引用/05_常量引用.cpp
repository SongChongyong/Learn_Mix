#include<iostream>
using namespace std;

//引用使用的场景，通常用来修饰形参
void showValue(const int& v) {      // 这里是const引用，不能修改v的值，防止误操作修改了v和a的值
    // v += 10;
    cout << v << endl;    // 100
}

int main() {

    //int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
    //加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
    const int& ref = 10;

    //ref = 100;  //加入const后不可以修改变量

    cout << ref << endl;      // 10

    //函数中利用常量引用防止误操作修改实参
    int a = 100;
    showValue(a);

    return 0;
}

