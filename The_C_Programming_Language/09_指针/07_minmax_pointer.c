# include<stdio.h>
void minmax (int a[], int len, int *min, int *max);
int main(void)
{
	int a[] = {1,2,3,4,5,6,7,8,9,12,16,17,21,23,55,};
	int min,max;
	printf("��main���������a�Ĵ�С: %lu\n", sizeof(a)); 
	printf("��main���������a�ĵ�ַ��%p\n", a); 
	minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
	printf("��������minmax��������ʱa[0]��ֵ��%d\n", a[0]);
	
	return 0;
	
}

void minmax (int a[], int len, int *min, int *max)
{
	int i;
	printf("��minmax���������a�Ĵ�С: %lu\n", sizeof(a)); 
	printf("��main���������a�ĵ�ַ��%p\n", a);
	a[0] = 1000;
	*min = *max = a[0];
	for (i=1; i<len; i++) {
		if (a[i] < *min){
			*min = a[i];
		}
		if (a[i] > *max) {
			*max = a[i];
		}
	}
}
/*
��main���������a�Ĵ�С: 60
��main���������a�ĵ�ַ��0061FE74
��minmax���������a�Ĵ�С: 4
��main���������a�ĵ�ַ��0061FE74
��������minmax��������ʱa[0]��ֵ��1000
*/
