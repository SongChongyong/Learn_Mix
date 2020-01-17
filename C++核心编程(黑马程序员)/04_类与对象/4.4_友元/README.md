
### 4.4 友元

生活中你的家有客厅(Public)，有你的卧室(Private)

客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去

但是呢，你也可以允许你的好闺蜜好基友进去。



在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

**友元的目的就是让一个函数或者类访问另一个类中私有成员**



友元的关键字为`friend`

友元的三种实现

* 全局函数做友元
* 类做友元
* 成员函数做友元



#### 4.4.1 全局函数做友元

```C++
#include<iostream>
#include<string>
using namespace std;

class Building
{
    //告诉编译器 goodGay全局函数 是Building类的好朋友，可以访问类中的私有内容
    friend void goodGay(Building * building);

public:

    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }


public:
    string m_SittingRoom; //客厅

private:
    string m_BedRoom; //卧室
};

// 全局函数
void goodGay(Building * building)
{
    cout << "好基友正在访问： " << building->m_SittingRoom << endl;
    cout << "好基友正在访问： " << building->m_BedRoom << endl;
}


void test01()
{
    Building b;
    goodGay(&b);
}

int main(){
    test01();

    return 0;
}

/*
好基友正在访问： 客厅
好基友正在访问： 卧室
*/
```

(代码见: [01_全局函数做友元.cpp](01_全局函数做友元.cpp))



#### 4.4.2 类做友元

```C++
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
```

(代码见: [02_类做友元 .cpp](02_类做友元 .cpp))



#### 4.4.3 成员函数做友元

```C++
#include<iostream>
#include<string>
using namespace std;


class Building;
class GoodGay
{
public:

    GoodGay();
    void visit(); //只让visit函数作为Building的好朋友，可以发访问Building中私有内容
    void visit2(); 

private:
    Building *building;
};


class Building
{
    //告诉编译器  GoodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
    friend void GoodGay::visit();

public:
    Building();

public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom;//卧室
};

Building::Building()
{
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
    building = new Building;
}

// GoodGay类中的成员函数visit()定义
// visit函数作为Building的好朋友，可以发访问Building中私有内容
void GoodGay::visit()
{
    cout << "好基友正在通过visit()访问" << building->m_SittingRoom << endl;
    cout << "好基友正在通过visit()访问" << building->m_BedRoom << endl;
}

// GoodGay类中的成员函数visit2()定义
void GoodGay::visit2()
{
    cout << "好基友正在通过visit2()访问" << building->m_SittingRoom << endl;
    //cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void test01()
{
    GoodGay  gg;
    gg.visit();
    gg.visit2();
}

int main(){ 
    test01();

    return 0;
}

/*
好基友正在通过visit()访问客厅
好基友正在通过visit()访问卧室
好基友正在通过visit2()访问客厅
*/
```

(代码见: [03_成员函数做友元 .cpp](03_成员函数做友元 .cpp))

