#include <iostream>
using namespace std;

/* 函数重载实例 */


/* 求两个整数的平方和 */
int sumOfSquare(int a, int b) {
	return a * a + b * b;
}

/* 求两个实数的平方和 */
double sumOfSquare(double a, double b) {
	return a * a + b * b;
}

int main() {
	int m, n;
	cout << "Enter two integer: ";
	cin >> m >> n;
	// 读入的m,n类型是int，编译器自动定位sumOfSquare()函数为求两个整数的平方和的函数
	cout << "Their sum of square: " << sumOfSquare(m, n) << endl;

	double x, y;
	cout << "Enter two real number: ";
	cin >> x >> y;
	// 读入的m,n类型是double，编译器自动定位sumOfSquare()函数为求两个实数的平方和的函数
	cout << "Their sum of square: " << sumOfSquare(x, y) << endl;

	return 0;
}

/*
Enter two integer: 3 4
Their sum of square: 25
Enter two real number: 3.0 4.0
Their sum of square: 25

Enter two integer: 3 4
Their sum of square: 25
Enter two real number: 3.0 4.1
Their sum of square: 25.81
*/

