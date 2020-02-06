#include<iostream>
#include<fstream>
#include<string>
using namespace std;


// 文本文件--读文件
void test01()
{
	ifstream ifs;    // 创建流对象  
    // 打开文件并判断文件是否打开成功
	ifs.open("test.txt", ios::in);   // 打开文件：ifs.open("文件路径",打开方式);
    
    // 并判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

    // 读数据:四种方式

	// 第一种方式
	// char buf[1024] = { 0 };
	// while (ifs >> buf)
	// {
	// 	cout << buf << endl;
	// }

	// 第二种
	// char buf[1024] = { 0 };
	// while (ifs.getline(buf,sizeof(buf)))
	// {
	// 	cout << buf << endl;
	// }

	// 第三种
	// string buf;
	// while (getline(ifs, buf))
	// {
	// 	cout << buf << endl;
	// }

    // 第四种--不推荐
	char c;
	while ((c = ifs.get()) != EOF)    // EOF: end of file
	{
		cout << c;
	}

    // 关闭文件
	ifs.close();
}

int main() 
{
	test01();

	return 0;
}
/*
姓名：张三
性别：男
年龄：18
*/