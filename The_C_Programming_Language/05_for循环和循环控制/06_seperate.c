#include <stdio.h>

// 输入一个正整数，正序输入它的每一位数字。如输入"12345"，输出"1 2 3 4 5" 
int main()
{
	int x;
	scanf("%d", &x);

	int mask = 1;
	int t = x;
	while ( t>9 ) {
		t /= 10;
		mask *=10;
	} 
	printf("x=%d, mask=%d\n", x, mask);
	do {
		int d = x / mask;
		printf("%d", d);
		// 用判断来实现除最后一位数外其他数字间加空格 
		if ( mask >9 ) {
			printf(" ");
		}
		x %= mask;
		mask /= 10;
		// printf("现在的x=%d,mask=%d,d=%d\n", x, mask, d);
	} while ( mask > 0 );
	printf("\n");

	return 0;
}
/*
12342
x=12342, mask=10000
1 2 3 4 2
*/

