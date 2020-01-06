#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t  start, stop;  /* clock_t��clock()�������صı������� */
double  duration;      /* ��¼���⺯������ʱ�䣬����Ϊ��λ */
#define MAXN 10        /* ����ʽ���������������ʽ����+1 */
#define MAXK 1e7       /* ���⺯������ظ����ô��� */

double f( int n, double a[], double x );

int main ()
{	/* ���Զ���ʽ��ֵ����������ʱ�� */
	int i;
	double a[MAXN]; /* �洢����ʽ��ϵ�� */
	for ( i=0; i<MAXN; i++ ) a[i] = (double)i; 
	/* ��f(x)��ϵ��a[]��ֵ */

	start = clock(); /* ��ʼ��ʱ */
	for ( i=0; i<MAXK; i++ ) /* �ظ����ú����Ի�ó�ֶ��ʱ�Ӵ����*/
		f(MAXN-1, a, 1.1); 
	stop = clock();	/* ֹͣ��ʱ */
	duration = ((double)(stop - start))/CLK_TCK/MAXK; 
	/* ���㺯���������е�ʱ�� */

	printf("ticks = %f\n", (double)(stop - start));
	printf("duration= %6.2e\n", duration);

	return 0;
}

/* ����ʱ��ʹ����������*.h�ļ�֮һ */
/* #include "1-4.h" */
/* #include "1-5.h" */
