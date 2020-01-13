#include<iostream>
using namespace std;

// 1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
int func(int a, int b = 10, int c = 10) {
    return a + b + c;
}

int main() 
{
    cout << "ret = " << func(20, 20) << endl;    // ret = 50
    cout << "ret = " << func(100) << endl;

    return 0;
}


