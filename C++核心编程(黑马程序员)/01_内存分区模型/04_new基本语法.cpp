#include<iostream>
using namespace std;

int *func()
{
    // 利用new，可以将数据开辟到堆区
    int *a = new int(10);
    return a;
}

int main()
{
    // 在堆区开辟数据
    int *p = func();
    cout << *p << endl;    // 10
    cout << *p << endl;    // 10
    // 堆区的数据 由程序员管理开辟，也由程序员管理释放
    // 如果想释放堆区的数据，利用关键字 delete

    delete p;

    cout << *p << endl; // 报错，释放的空间不可访问 (Linux输出0)

    return 0;
}

