#include<iostream>

#include<iostream>
using namespace std;

// #include "person.h"
// #include "person.cpp" //解决方式1，包含cpp源文件,很少这样实现

//解决方式2，将声明(.h)和实现(.cpp)写到一起，文件后缀名改为.hpp
#include "person.hpp"
void test01()
{
	Person<string, int> p("Tom", 10);
	p.showPerson();
}

int main() {
	test01();

	return 0;
}

/*
姓名: Tom 年龄:10
*/