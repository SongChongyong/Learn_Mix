#include <iostream>
#include <vector>
#include <string>
using namespace std;

//自定义数据类型
class Person {
public:
	Person(string name, int age) {
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};
//存放对象
void test01() {

	vector<Person> v;

	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	// 迭代器it，我们将其当成指针   （*it）后是一个Person数据类型
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "Name:" << (*it).mName << " Age:" << (*it).mAge << endl;

	}
}

//放对象指针
void test02() {
	vector<Person*> v;

	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	// 这里(*it)就是 Person*，可以直接用->取出指针指向的值
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "Name:" << (*it)->mName << " Age:" << (*it)->mAge << endl;

        // // 也可以用 *p = (*it) 来指代，效果与上面是一样，重点是理解 (*it)就是 Person*
		// Person * p = (*it);
		// cout << "Name:" << p->mName << " Age:" << (*it)->mAge << endl;
	}
}


int main() {
	// test01();
   
	test02();

	return 0;
}
/*
Name:aaa Age:10
Name:bbb Age:20
Name:ccc Age:30
Name:ddd Age:40
Name:eee Age:50
*/