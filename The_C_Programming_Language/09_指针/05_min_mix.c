# include<stdio.h>

// 打印数组中最大和最小元素 
void minmax(int a[], int len, int *max, int *min);

int main()
{
	int a[] = {1,2,3,4,5,6,7,87,45,23,55};
	int min,max;
	minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
	printf("min=%d, max=%d", min, max);   // min=87, max=1
	return 0;
}
void minmax(int a[], int len, int *max, int *min)
{
	int i;
	*min = *max = a[0];
	for (i=1; i<len; i++){
		if (a[i] < *min){
			*min = a[i];
		}
		if (a[i] > *max){
			*max = a[i];
		}
	}

}
