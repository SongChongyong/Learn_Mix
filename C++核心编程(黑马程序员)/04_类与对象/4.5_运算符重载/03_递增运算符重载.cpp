#include<iostream>
using namespace std;

// 重载递增运算符
// 作用： 通过重载递增运算符，实现自己的整型数据的递增运算

class MyInteger {

    friend ostream& operator<<(ostream& out, MyInteger myint);

public:
    MyInteger() {
        m_Num = 0;
    }
    //前置++，返回引用是为了一直对一个数据递增操作
    MyInteger& operator++() {
        //先++
        m_Num++;
        //再返回自身
        return *this;    // 这里返回的是引用
    }

    //后置++，int代表占位参数位，可以用于区分前置递增和后置底层
    MyInteger operator++(int) {
        // 先记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++
        MyInteger temp = *this; 
        // 后递增
        m_Num++;
        // 返回记录的结果
        return temp;    // 这里返回的是值
    }

private:
    int m_Num;
};

// 重载左移运算符，实现输出自定义数据类型，如"cout << myInt"
ostream& operator<<(ostream& out, MyInteger myint) {
    out << myint.m_Num;
    return out;
}


//前置++ 先++ 再返回
void test01() {
    MyInteger myInt;
    cout << ++myInt << endl;
    cout << myInt << endl;
}

//后置++ 先返回 再++
void test02() {

    MyInteger myInt;
    cout << myInt++ << endl;
    cout << myInt << endl;
}

int main() {
    // test01();
    test02();

    return 0;
}

/*
main()中调用test01()时运行结果：
1
1

main()中调用test01()时运行结果：
0
1
*/
