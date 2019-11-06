#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	int digit;
	int ret = 0;

	while ( x> 0 ) {
		digit = x%10;
		ret = ret*10 + digit;
		// 打印各个循环的结果 
		printf("x=%d,digit=%d,ret=%d\n", x, digit, ret);  
		x /= 10;
	}
	printf("%d", ret);
	
	return 0;
}
/*
1234
x=1234,digit=4,ret=4
x=123,digit=3,ret=43
x=12,digit=2,ret=432
x=1,digit=1,ret=4321
4321
*/
