#include<iostream>
using namespace std;

/*
设计立方体类(Cube)
求出立方体的面积和体积
分别用全局函数和成员函数判断两个立方体是否相等。
*/

// 立方体类
class Cube
{
public:

    // 设置长度
    void setL(double L){
        m_L = L;
    }
    // 获取长度
    double getL(){
        return m_L;
    }

    // 设置宽度
    void setW(double W){
        m_W = W;
    }
    // 获取长度
    double getW(){
        return m_W;
    }

    // 设置高度
    void setH(double H){
        m_H = H;
    }
    // 获取高度
    double getH(){
        return m_H;
    }

    // 输入立方体的长宽高
    void cin_LWH(){
        cout << "请输入立方体的长宽高：" << endl;
        double L, W, H;
        cin >> L >> W >> H ;
        setL(L);
        setW(W);
        setH(H);
    }

    // 求面积方法
    double cubeArea(){
        return 2*(m_L*m_W+m_W*m_H+m_H*m_L);
    }
    // 求体积方法
    double cubeVolume(){
        return m_L*m_W*m_H;
    }

    // 类中，成员函数：判断两个立方体是否相等
    bool ifEqual_class (Cube &c2){
        if (m_L - c2.getL() == 0 && m_W - c2.getW() == 0 && m_H - c2.getH() == 0) {
        return true;
    }
    return false;
    }

private:
    // 属性：长宽高，都设置为私有，然后在public中编写函数进行读取操作
    double m_L;
    double m_W;
    double m_H;
};

// 全局函数：判断两个立方体是否相等
bool ifEqual(Cube &c1, Cube &c2)
{
    if (c1.getL() - c2.getL() == 0 && c1.getW() - c2.getW() == 0 && c1.getH() - c2.getH() == 0) {
        return true;
    }
    return false;
}


int main()
{
    // 定义cube1
    Cube cube1;
    cube1.cin_LWH();
    double cube1_area = cube1.cubeArea();
    double cube1_volume = cube1.cubeVolume();
    cout << "cube1的表面积是: " << cube1_area << endl;
    cout << "cube1的体积是： " << cube1_volume << endl;

    // 定义cube2
    Cube cube2;
    cube2.cin_LWH();

    // 利用全局函数判断cube1和cube2是否相等
    bool cnt = ifEqual (cube1, cube2);
    if (cnt) {
        cout << "cube1 = cube2" << endl;
    } else {
        cout << "cube1 != cube2" << endl;
    }

    // 利用成员函数判断cube1和cube2是否相等
    bool cnt2 = cube1.ifEqual_class(cube2);
    if (cnt2) {
        cout << "cube1 = cube2" << endl;
    } else {
        cout << "cube1 != cube2" << endl;
    }

    return 0;
}

/*
请输入立方体的长宽高：
1.1 1.1 1.1
cube1的表面积是: 7.26
cube1的体积是： 1.331
请输入立方体的长宽高：
1.111 1.11 1.111
cube1 != cube2
cube1 != cube2
*/
