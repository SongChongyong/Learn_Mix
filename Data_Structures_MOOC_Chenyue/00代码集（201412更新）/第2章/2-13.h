#include <malloc.h>

ElementType Median( ElementType S[], int N )
{   
	ElementType  *p, m;

	/* ������ʱ�����С����Ҫ�Ŀռ�*/
	P = (ElementType *)malloc(sizeof(ElementType)*N);
	m = FindKthLargest(S, (N+1)/2, 0, N-1, p);
	free(p);     /* �ͷ���ʱ����ռ� */
	return m;
}
