#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int a = rand();                  // ���ȡһ���� 
	printf("a = %d\n", a);
	printf("a%100 = %d\n", a%100);   // ȡ���������100ȡ�࣬���100���ڵ����� 

	return 0;
}

/*
a = 18253
a = 53
*/
