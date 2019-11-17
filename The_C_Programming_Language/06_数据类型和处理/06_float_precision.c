# include <stdio.h>
# include <math.h>

int main()
{
	float a, b, c;
	a = 1.345f;
	b = 1.123f;
	c = a + b;
	if (c==2.468)
		printf("相等\n");
	else 
		printf("不相等！a = %.10f, b = %.10f, c = %.10f\n", a, b, c);
		 
	if (fabs(c-2.468)<1e-3)
		printf("判断条件为fabs(c-2.468)<1e-3时，c与2.468相等\n");
} 
/*
不相等！a = 1.3450000286, b = 1.1230000257, c = 2.4679999352
判断条件为fabs(c-2.468)<1e-3时，c与2.468相等
*/
