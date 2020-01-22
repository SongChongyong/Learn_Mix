#include<iostream>
using namespace std;

class Base1
{
public: 
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

// ------ 公共继承 ------
class Son1 :public Base1
{
public:
    void func()
    {
        m_A = 10; //可访问 public权限--父类中的共有权限，到子类中依然是公开权限
        m_B = 10; //可访问 protected权限--父类中的保护权限，到子类中依然是保护权限
        //m_C = 10; //不可访问  -- 父类中的私有权限，子类访问不到
    }
};

void test01()
{
    Son1 s1;
    s1.m_A = 100; //其他类只能访问到公共权限
    // s1._m_B = 100;  // 保护权限，类外访问不到
}

//------ 保护继承 ------
class Base2
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class Son2:protected Base2
{
public:
    void func()
    {
        m_A; //可访问 protected权限  --父类中的共有权限，到子类中变为保护权限
        m_B; //可访问 protected权限  --父类中的保护权限，到子类中还是保护权限
        //m_C; //不可访问  -- 父类中的私有权限，子类访问不到
    }
};
void test02()
{
    Son2 s;
    //s.m_A = 100; //不可访问，保护权限，类外访问不到
}

//------ 私有继承 ------
class Base3
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class Son3:private Base3
{
public:
    void func()
    {
        m_A; //可访问 private权限  --父类中的共有权限，到子类中变为私有权限
        m_B; //可访问 private权限  --父类中的保护权限，到子类中变为私有权限
        //m_C; //不可访问  -- 父类中的私有权限，子类访问不到
    }
};

void test03()
{
    Son3 s1;
    // s1.m_A = 100;      // 到Son3中，m_A变成私有权限，类外访问不到
    // s1._m_B = 100;  // 保护权限，类外访问不到
}

// 这里再建一个类GrandSon3继承Son3，发现由于Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
class GrandSon3 :public Son3
{
public:
    void func()
    {
        //Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
        //m_A;
        //m_B;
        //m_C;
    }
};
