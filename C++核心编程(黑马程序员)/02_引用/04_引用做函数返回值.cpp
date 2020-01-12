#include<iostream>
using namespace std;

// 返回局部变量引用----不要这么做
// 编译产生warning: reference to local variable ‘a’ returned [-Wreturn-local-addr]
int& test01() {
    int a = 10; //局部变量,存放在栈区，栈区的数据在函数执行后自动释放
    return a;
}

//返回静态变量引用
int& test02() {
    static int a = 20;   // 静态变量存放在全局区，该区域的数据在程序结束后由操作系统释放
    return a;
}

int main() {

    //不能返回局部变量的引用，因为局部变量在函数执行后内存已经释放
    // int& ref = test01();
    // cout << "ref = " << ref << endl;
    // cout << "ref = " << ref << endl;



    //如果函数的返回值是引用，这个函数调用可以作为左值
    int& ref2 = test02();
    cout << "ref2 = " << ref2 << endl;    // ref2 = 20
    cout << "ref2 = " << ref2 << endl;    // ref2 = 20

    test02() = 1000;

    cout << "ref2 = " << ref2 << endl;     // ref2 = 1000
    cout << "ref2 = " << ref2 << endl;     // ref2 = 1000


    return 0;
}