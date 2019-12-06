# include <stdio.h>

void swap(int *pa, int *pb);

int main(void)
{
	int a = 5;
	int b = 6;
	swap(&a,&b);
	printf("After swap, a = %d, b = %d", a, b);
	return 0;
}

void swap(int *pa, int *pb)
{
	int t = *pa;
	*pa = *pb;
	*pb = t;
}
