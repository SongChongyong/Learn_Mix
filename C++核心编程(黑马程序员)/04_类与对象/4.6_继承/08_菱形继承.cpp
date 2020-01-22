#include<iostream>
using namespace std;

class Animal
{
public:
    int m_Age;
};

// 数据一份就可以，菱形继承导致数据两份，资源浪费,
// 继承前加virtual关键字后，变为虚继承，解决菱形继承的问题
// 此时公共的父类Animal称为虚基类
// 虚继承后，每个虚继承父类对应一个"vbtpt"(virtual base ptr，虚基类指针，指向一个虚基类表)
class Sheep : virtual public Animal {};
class Tuo   : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 100;
    st.Tuo::m_Age = 200;

    // 当菱形继承，两个父类用于相同数据，需要加以作用预区分
    // 这是虚继承，数据只有一份，m_Age对这三个类都一样
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;  
    cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;

    cout << "st.m_Age = " << st.m_Age << endl;
}


int main() {
    test01();

    return 0;
}

/*
st.Sheep::m_Age = 200
st.Tuo::m_Age = 200
st.m_Age = 200
*/