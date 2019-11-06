#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int a = rand();                  // 随机取一个数 
	printf("a = %d\n", a);
	printf("a%100 = %d\n", a%100);   // 取的随机数对100取余，获得100以内的整数 

	return 0;
}

/*
a = 18253
a = 53
*/
