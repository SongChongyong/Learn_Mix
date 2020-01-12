#include <iostream>
using namespace std;

//1. 值传递
void mySwap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

//2. 地址传递
void mySwap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//3. 引用传递
void mySwap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{

    int a = 10;
    int b = 20;

    mySwap01(a, b);    // 值传递
    cout << "a:" << a << " b:" << b << endl;

    mySwap02(&a, &b);   // 地址传递
    cout << "a:" << a << " b:" << b << endl;

    mySwap03(a, b);     // 引用传递
    cout << "a:" << a << " b:" << b << endl;

    return 0;
}
/*
a:10 b:20
a:20 b:10
a:10 b:20
*/