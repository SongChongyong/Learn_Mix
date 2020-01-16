#include<iostream>
using namespace std;

//空指针访问成员函数
class Person {
public:

    void ShowClassName() {
        cout << "我是Person类!" << endl;
    }

    void ShowPerson() {
        // 判断函数预防传入的是空指针，加判断保证代码的健壮性
        if (this == NULL) {
            return;
        }
        cout << mAge << endl;    // mAge其实是"this->mAge",表示对象所指的mAge，用到了this指针
    }

public:
    int mAge;
};

void test01()
{
    Person * p = NULL;    // 空指针
    p->ShowClassName();   // 空指针，可以调用成员函数
    p->ShowPerson();      // 但是如果成员函数中用到了this指针，就不可以了，所以加了一个判断函数
}

int main() {
    test01();
    
    return 0;
}

/*
我是Person类!
*/