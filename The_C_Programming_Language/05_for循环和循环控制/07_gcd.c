#include <stdio.h>

int main()
{
	int a,b;
	int t;
	
	scanf("%d %d", &a, &b);
	int origa = a;
	int origb = b;
	while ( b != 0 ) {
		t = a%b;
		a = b;
		b = t;
		printf("a=%d, b=%d, t=%d\n", a, b, t);
	}
	printf("%d和%d的最大公约数是%d.\n", origa, origb, a);
	
	return 0;
}
/*
12
18
a=18, b=12, t=12
a=12, b=6, t=6
a=6, b=0, t=0
12和18的最大公约数是6.
*/

