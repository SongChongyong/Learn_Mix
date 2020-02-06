#include<iostream>
#include<fstream>          // 1.包含头文件
using namespace std;


void test01()
{
	ofstream ofs;        // 2.创建流对象
    // 3.打开文件:ofs.open("文件路径",打开方式);
    //   打开方式：'ios::out'--为写文件而打开文件, ios::app--追加方式写文件
    //   |操作符配合使用多个文件打开方式
	ofs.open("test.txt", ios::out|ios::app);   

	ofs << "姓名：张三" << endl;       // 4.写数据
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	ofs.close();         // 5.关闭文件
}

int main()
{
	test01();

	return 0;
}
/*
执行后，生成"test.txt"文件，文件中有写入数据
*/
