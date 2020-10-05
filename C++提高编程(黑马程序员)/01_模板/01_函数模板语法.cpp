#include<iostream>
using namespace std;


//交换整型函数
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//交换浮点型函数
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

//利用模板提供通用的交换函数
template<typename T>     //声明一个模板，告诉编译器紧跟着的T是一个通用数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	
	//swapInt(a, b);             //测试交换整型函数

	//利用模板实现交换
	//1、自动类型推导
	mySwap(a, b);
    cout << "After 'mySwap(a, b)':" << endl;
    cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//2、显示指定类型
	mySwap<int>(a, b);

	cout << "Then, after 'mySwap<int>(a, b)':" << endl;
    cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}

int main() {
	test01();

	return 0;
}
/*
After 'mySwap(a, b)':
a = 20
b = 10
Then, after 'mySwap<int>(a, b)':
a = 10
b = 20
*/