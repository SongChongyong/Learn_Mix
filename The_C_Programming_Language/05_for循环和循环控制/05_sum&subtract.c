# include <stdio.h>

int main()
{
	int n;
	int i;
	double sum=0.0;
	int sign = 1;

	scanf("%d", &n);
	for ( i=1; i<=n; i++ ) {
		sum += 1.0*sign/i;
		sign = -sign;
	}
	printf("f(%d) = %f\n", n, sum);

	return 0;
}

/*
10
f(10) = 0.645635
*/
