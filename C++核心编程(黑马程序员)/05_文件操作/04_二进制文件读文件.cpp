#include<iostream>
#include <fstream>
#include <string>
using namespace std;

// 二进制文件--读文件
class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test01()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	Person p;
	ifs.read((char *)&p, sizeof(p));

	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}

int main() {
	test01();

	return 0;
}
/*
姓名： 张三 年龄： 18
*/