# include <stdio.h>

int main()
{
	// ����a��b����������ֵ
	int a = 5;
	int b = 6;
	printf("a = %d, b = %d\n", a, b);
	int t;
	t = a;
	a = b;
	b = t;
	printf("a = %d, b = %d", a, b);
}
/*
a = 5, b = 6
a = 6, b = 5
*/
