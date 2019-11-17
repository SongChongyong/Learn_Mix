# include <stdio.h>

int main()
{
	char c = 255; // 1111 1111
	char d = 3; // 0000 0011
	int i = 255; // 00000000 00000000 00000000 11111111
	printf("c=%d, d=%d, i=%d\n",c,d,i);
} 
// c=-1, d=3, i=255 
