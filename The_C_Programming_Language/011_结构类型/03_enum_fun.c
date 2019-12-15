#include<stdio.h>

enum colour {red, yellow, green};

void fun(enum colour c); 
int main(void)
{
	//! showMemory(start=65520)
	enum colour t = red;
	scanf("%d", &t);
	fun(t);
	return 0;
}

void fun(enum colour c)
{
	printf("%d\n", c);
}
