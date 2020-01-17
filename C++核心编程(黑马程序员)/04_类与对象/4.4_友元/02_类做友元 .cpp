#include<iostream>
#include<string>
using namespace std;

class Building;
class GoodGay
{
public:

    GoodGay();
    void visit();

private:
    Building *building;
};


class Building
{
    //告诉编译器 GoodGay类是Building类的好朋友，可以访问到Building类中私有内容
    friend class GoodGay;

public:
    Building();

public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom;//卧室
};

// Buliding类的构造函数，在类外写
Building::Building()
{
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

// GoodGay类的构造函数，在类外写
GoodGay::GoodGay()
{
    building = new Building;
}

// GoodGay类的函数，在类外写
void GoodGay::visit()
{
    cout << "好基友正在访问" << building->m_SittingRoom << endl;
    cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();

}

int main(){
    test01();

    return 0;
}

/*
好基友正在访问客厅
好基友正在访问卧室
*/
