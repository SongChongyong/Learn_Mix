#include<iostream>
using namespace std;

// 栈区的数据由编译器管理开辟和释放
// ！！不要返回局部变量的地址

int * func(int b)     // 形参数据也会放在栈区，如这里的b
{
	b = 100;
    int a = 10;  // 局部变量,存放在栈区，栈区的数据在函数执行后自动释放
	return &a;   // 返回局部变量的地址
}

int main() {

	int *p = func(1);

	cout << *p << endl;   // 第一次有时可以打印出"10"的结果，因为编译器做了保留
	cout << *p << endl;   // 第二次数据不再保留，打印出无效结果

	// system("pause");

	return 0;
}

/*
编译有warnning:
02_栈区.cpp:9:6: warning: address of local variable ‘a’ returned [-Wreturn-local-addr]
  int a = 10;  // 局部变量

执行文件：
$ ./02_栈区 
Segmentation fault (core dumped)

*/
