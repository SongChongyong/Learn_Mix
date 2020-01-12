#include<iostream>
using namespace std;

// 堆区开辟数组
void test()
{
    // 创建有10个整型数据的数组，在堆区
    int *arr = new int[10];

    // 给数组赋值 100-109
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i+100;
    }
    
    // 遍历打印数组元素
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    // 释放堆区数组
    // 释放数组时，需要加入[]
    delete[] arr;

}

int main()
{
    test();
    return 0;
}

