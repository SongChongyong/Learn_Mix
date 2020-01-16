#include<iostream>
using namespace std;

//学生类
class Student {
public:
    // 类中的属性和行为，统一成为成员
    // 属性：成员属性 or 成员变量
    // 行为：成员函数 or 成员方法
    
    //行为
    // 给姓名赋值
    void setName(string name) {
        m_name = name;
    }
    // 给学号赋值
    void setID(int id) {
        m_id = id;
    }
    // 显示姓名和学号
    void showStudent() {
        cout << "name:" << m_name << " ID:" << m_id << endl;
    }
public:   //公共权限
    //属性：姓名，学号
    string m_name;
    int m_id;
};

int main() {

    Student stu;
    stu.setName("Tom");
    stu.setID(250);
    stu.showStudent();

    return 0;
}


/*
name:Tom ID:250
*/
