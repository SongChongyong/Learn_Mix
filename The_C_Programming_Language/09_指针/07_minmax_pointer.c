# include<stdio.h>
void minmax (int a[], int len, int *min, int *max);
int main(void)
{
	int a[] = {1,2,3,4,5,6,7,8,9,12,16,17,21,23,55,};
	int min,max;
	printf("在main函数里，数组a的大小: %lu\n", sizeof(a)); 
	printf("在main函数里，数组a的地址：%p\n", a); 
	minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
	printf("经过调用minmax函数，此时a[0]的值：%d\n", a[0]);
	
	return 0;
	
}

void minmax (int a[], int len, int *min, int *max)
{
	int i;
	printf("在minmax函数里，数组a的大小: %lu\n", sizeof(a)); 
	printf("在main函数里，数组a的地址：%p\n", a);
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
在main函数里，数组a的大小: 60
在main函数里，数组a的地址：0061FE74
在minmax函数里，数组a的大小: 4
在main函数里，数组a的地址：0061FE74
经过调用minmax函数，此时a[0]的值：1000
*/
