#include<iostream>
using namespace std;

int *func()
{
    // 利用new，可以将数据开辟到堆区
    // 指针本质也是局部变流，放在栈区，但是指针保存的数据放在堆区
    int * a = new int(10);
    return a;

}

int main()
{
    // 在堆区开辟数据
    int *p = func();

	cout << *p << endl;    // 10
	cout << *p << endl;    // 10
    
	// system("pause");

	return 0;
}
