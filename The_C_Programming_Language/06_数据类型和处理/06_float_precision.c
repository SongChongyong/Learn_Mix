# include <stdio.h>
# include <math.h>

int main()
{
	float a, b, c;
	a = 1.345f;
	b = 1.123f;
	c = a + b;
	if (c==2.468)
		printf("���\n");
	else 
		printf("����ȣ�a = %.10f, b = %.10f, c = %.10f\n", a, b, c);
		 
	if (fabs(c-2.468)<1e-3)
		printf("�ж�����Ϊfabs(c-2.468)<1e-3ʱ��c��2.468���\n");
} 
/*
����ȣ�a = 1.3450000286, b = 1.1230000257, c = 2.4679999352
�ж�����Ϊfabs(c-2.468)<1e-3ʱ��c��2.468���
*/
