#include<stdio.h>
#include<stdlib.h>  // Ҫʹ��malloc������ͷ�ļ� 

int main()
{
	int number;
	int *a; 
	int i;
	scanf("%d", &number);
	a = (int*)malloc(number*sizeof(int));  // �������ܶ����С��number��int����a
	
	// ������Զ�����a(���߽�ָ��a�����ֲ���) 
	printf("Input items for a[number]:", number);
	for (i=0; i<number; i++){
		scanf("%d", &a[i]);
	}
	printf("a[%d] = ", number);
	for (i=number-1; i>=0; i--){
		printf("%d ", a[i]);
	}
	free(a);   //���ձ������������Ŀռ仹��ϵͳ 
	return 0;
}
/*
5
Input items for a[number]:2 5 7 2 9
a[5] = 9 2 7 5 2
*/

